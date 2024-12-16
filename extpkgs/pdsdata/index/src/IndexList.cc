#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "pdsdata/psddl/evr.ddl.h"
#include "pdsdata/xtc/BldInfo.hh"
#include "pdsdata/index/IndexList.hh"

namespace Pds
{  
namespace Index
{
/*
 * class IndexList
 */ 

int IndexList::startNewNode(const Dgram& dg, int64_t i64Offset, bool& bInvalidData)
{
  bInvalidData = false;
  
  int iError = 0;    
  if ( _bNewNode )  
  {
    printf( "IndexList::startNewNode():: *** Previous new node hasn't been finished\n" );
    finishNode(false);    
    iError = 1;
  }

  uint32_t uFiducial = dg.seq.stamp().fiducials();  
  
  if ( uFiducial == L1AcceptNode::uInvalidFiducial )
  {
    bInvalidData = true;
    return 2;
  }
    
  L1AcceptNode  nodeNew(dg.seq.clock().seconds(), dg.seq.clock().nanoseconds(), uFiducial, i64Offset);
  L1AcceptNode& nodeCur = checkInNode(nodeNew);
  
  _pCurNode = &nodeCur;
  
  nodeCur.damage = dg.xtc.damage;
    
  _bNewNode = true;  
  _itCurSeg = _mapSegToId.end();
  
  return iError;
}

int IndexList::updateSegment(const Xtc& xtc)
{
  if ( ! _bNewNode )  
  {
    printf( "IndexList::updateSegment():: *** new node hasn't been initialized\n" );
    return 1;
  }

  finishPrevSegmentId();
  
  const ProcInfo& info          = (const ProcInfo &) (xtc.src);  
  int             iSegmentIndex = -1;  
  
  if ( _iNumSegments < 0 )
  {    
    iSegmentIndex = _mapSegToId.size();
            
    std::pair<TSegmentToIdMap::iterator,bool> 
      rInsert = _mapSegToId.insert( 
        TSegmentToIdMap::value_type( info, L1SegmentId(iSegmentIndex) ) );
      
    if ( !rInsert.second )
    {
      printf( "IndexList::updateSegment():: Found duplicated segment for "
        "ip 0x%x pid 0x%x\n", info.ipAddr(), info.processId() );
      return 2;
    }
    
    _itCurSeg = rInsert.first;
  }
  else
  {
    TSegmentToIdMap::iterator itFind = 
      _mapSegToId.find( info );
      
    if ( itFind == _mapSegToId.end() )
    {
      iSegmentIndex = _mapSegToId.size();
              
      std::pair<TSegmentToIdMap::iterator,bool> 
        rInsert = _mapSegToId.insert( 
          TSegmentToIdMap::value_type( info, L1SegmentId(iSegmentIndex) ) );
              
      _itCurSeg     = rInsert.first;      
      _iNumSegments = _mapSegToId.size();
    }     
    else
    {
      iSegmentIndex = itFind->second.iIndex;
      if ( iSegmentIndex >= (int) _iNumSegments )
      {
        printf( "IndexList::updateSegment():: *** invalid segment index %d (max value %d)\n", 
          iSegmentIndex, _iNumSegments );
        return 4;
      }
      _itCurSeg = itFind;
    }
  }

  L1AcceptNode& node  =   *_pCurNode;  
  if ( xtc.damage.value() != 0 ) {
    if ( iSegmentIndex < (int) sizeof(node.uMaskDetDmgs) * 8 )
      node.uMaskDetDmgs   |=  (1 << iSegmentIndex);  
    else
      node.uMaskDetDmgs   = -1;
  }

  if ( xtc.contains.id() != TypeId::Id_Xtc ) // not a normal segment level
    return 5;

  if ( xtc.sizeofPayload() == 0 ) {
    if ( iSegmentIndex < (int) sizeof(node.uMaskDetData) * 8 )
      node.uMaskDetData   |=  (1 << iSegmentIndex);
    else
      node.uMaskDetData   = -1;
  }
    
  return 0;
}

int IndexList::updateSource(const Xtc& xtc, bool& bStopUpdate)
{
  bStopUpdate = false;
  
  if ( ! _bNewNode )  
  {
    printf( "IndexList::updateSource():: *** new node hasn't been initialized\n" );
    return 1;
  }
  
  if ( _itCurSeg == _mapSegToId.end() )
  {
    printf( "IndexList::updateSource():: Invalid segment\n" );
    return 2;
  }

  L1SegmentId&  segId = _itCurSeg->second;
  if (segId.bSrcUpdated)
    bStopUpdate = true;
  else
  {
    segId.srcList .push_back(xtc.src);
    segId.typeList.push_back(xtc.contains);
    
    if (xtc.contains.id() == TypeId::Id_Epics)
      bStopUpdate = true;
  }
    
  if ( xtc.contains.id() == TypeId::Id_EvrData )
    updateEvr( xtc );

  return 0;
}

int IndexList::updateReporter(const Xtc& xtc, bool& bStopUpdate)
{
  bStopUpdate = false;
  
  if ( ! _bNewNode )  
  {
    printf( "IndexList::updateReporter():: *** new node hasn't been initialized\n" );
    return 1;
  }
  
  if ( _itCurSeg == _mapSegToId.end() )
  {
    printf( "IndexList::updateReporter():: Invalid segment\n" );
    return 2;
  }

  L1SegmentId&  segId = _itCurSeg->second;
  if (segId.bSrcUpdated)
    bStopUpdate = true;
  else
  {
    segId.srcList .push_back(xtc.src);
    segId.typeList.push_back(xtc.contains);
  }
  
  return 0;
}

int IndexList::updateEvr(const Xtc& xtc)
{
  // assume xtc.contains.id() == TypeId::Id_EvrData
  
  const EvrData::DataV4& evrData = * reinterpret_cast<const EvrData::DataV4*>(xtc.payload());
  
  for ( unsigned int uEvent = 0; uEvent < evrData.numFifoEvents(); uEvent++ )
  {
    const EvrData::FIFOEvent& fifoEvent = 
      evrData.fifoEvents()[uEvent];
      
    TEvrEvtToIdMap::iterator itFind = 
      _mapEvrToId.find(fifoEvent.eventCode());
      
    if ( itFind == _mapEvrToId.end() )
    {
      std::pair<TEvrEvtToIdMap::iterator,bool> 
        rInsert = _mapEvrToId.insert(TEvrEvtToIdMap::value_type( fifoEvent.eventCode(), 
                                                                 _mapEvrToId.size() ) );
      itFind = rInsert.first;
    }

    if ( itFind->second < (int) sizeof(_pCurNode->uMaskEvrEvents) * 8)
      _pCurNode->uMaskEvrEvents |= ( 1 << itFind->second );
    else
      _pCurNode->uMaskEvrEvents = -1;
  }  
  
  return 0;
}

int IndexList::finishNode(bool bPrint)
{
  if ( ! _bNewNode )  
  {
    printf( "IndexList::finishNode():: *** new node hasn't been initialized\n" );
    return 1;
  }

  finishPrevSegmentId();
  
  //L1AcceptNode& node  =   *_pCurNode;  
  if ( _iNumSegments < 0 )
    _iNumSegments = _mapSegToId.size();      
  
  if (bPrint)
    printNode(*_pCurNode, _iCurSerial);
      
  _bNewNode = false;   
  _pCurNode = NULL;  
  return 0;
}

int IndexList::finishList()
{    
  if ( _lNode.size() > 0 )
    _l1NodeLast = _lNode.back();
    
  if ( _mapSegToId.size() > sizeof(_l1NodeLast.uMaskDetDmgs) * 8 )
    printf( "Warning: segment # %d > %d! Detector damage bits may not be recorded precisely in index file\n",
      (int) _mapSegToId.size(), (int) sizeof(_l1NodeLast.uMaskDetDmgs) * 8 );

  if ( _mapSegToId.size() > sizeof(_l1NodeLast.uMaskDetData) * 8 )
    printf( "Warning: segment # %d > %d! Detector data bits may not be recorded precisely in index file\n",
      (int) _mapSegToId.size(), (int) sizeof(_l1NodeLast.uMaskDetData) * 8 );
      
  if ( _mapEvrToId.size() > sizeof(_l1NodeLast.uMaskEvrEvents) * 8 )
    printf( "Warning: evr event # %d > %d! Evr event bits may not be recorded precisely in index file\n",
      (int) _mapEvrToId.size(), (int) sizeof(_l1NodeLast.uMaskEvrEvents) * 8 );
        
  return 0;
}

int IndexList::addCalibCycle(int64_t i64Offset, uint32_t uSeconds, uint32_t uNanoseconds)
{  
  _lCalib.push_back(CalibNode(i64Offset,_lNode.size(), uSeconds, uNanoseconds));
  return 0;
}

void IndexList::printList(int iVerbose) const
{ 
  printf( "XtcFn %s List index# 0x%x (%u) Calib# %d EvrEvt# %d Segment# %u\n",
    _sXtcFilename, (int) _lNode.size(), (int) _lNode.size(), (int) _lCalib.size(), 
    (int) _mapEvrToId.size(), (int) _mapSegToId.size()
    );

  printf("  Out-of-Order# %u Overlapped with prev %u\n", _iNumOutOrder, _iNumOverlapPrev);
  if ( iVerbose > 0 )
  {
    /*
     * Print BeginCalibCycle list
     */    
    int iCalib = 0;
    for ( TCalibList::const_iterator
      iterCalib =  _lCalib.begin();
      iterCalib != _lCalib.end();
      iterCalib++, iCalib++ )
    {      
      const CalibNode& calibNode = *iterCalib;
      
      char sTimeBuff[128];
      time_t t = calibNode.uSeconds;
      strftime(sTimeBuff,128,"%Z %a %F %T",localtime(&t));  
      
      printf( "Calib %d Off 0x%Lx L1 %d %s.%03u\n", iCalib, (long long unsigned) calibNode.i64Offset, calibNode.iL1Index,
        sTimeBuff, (int)(calibNode.uNanoseconds/1e6));
    }
    
    /*
     * Print Event Code list
     */    
    for ( TEvrEvtToIdMap::const_iterator 
      iterMap =  _mapEvrToId.begin();
      iterMap != _mapEvrToId.end();
      iterMap++ )
    {
      printf( "Evr Event %d Code %d\n", 
        iterMap->second, iterMap->first );
    }
    
    /*
     * Print segment list
     */    
    for ( TSegmentToIdMap::const_iterator 
      iterMap =  _mapSegToId.begin();
      iterMap != _mapSegToId.end();
      iterMap++ )
    {
      const ProcInfo& info    = iterMap->first.procNode;
      printf( "Segment %d ip 0x%x pid 0x%x\n", 
        iterMap->second.iIndex, info.ipAddr(), info.processId());
        
      /*
       * Print typeId and src list for each segment
       */        
      const L1SegmentId& segId = iterMap->second;
      for ( int iSource = 0; iSource < (int) segId.srcList.size(); iSource++ )
      {         
        const Src& src = (Src&) segId.srcList[iSource];
        if (src.level() == Level::Source)
        {        
          const DetInfo& info = (const DetInfo&) src;
          printf("  src %s,%d %s,%d ",
           DetInfo::name(info.detector()), info.detId(),
           DetInfo::name(info.device()), info.devId());           
        }
        else if ( src.level() == Level::Reporter )
        {
          const BldInfo& info = (const BldInfo&) src;
          printf("  bldType %s ", BldInfo::name(info));          
        }
          
        const TypeId& typeId = segId.typeList[iSource];
        printf("contains %s V%d\n",
         TypeId::name(typeId.id()), typeId.version()
         );          
      }
    }
  } // if ( iVerbose > 0 )
  
  if ( iVerbose > 1 )
  {
    int iSerial = 0;
    for ( TNodeList::const_iterator 
      iterNode = _lNode.begin(); 
      iterNode != _lNode.end(); 
      ++iterNode, iSerial++ )
    {
      printNode(*iterNode, iSerial);
    }
  }
}

void IndexList::printNode(const L1AcceptNode& node, int iSerial) const
{
  char sTimeBuff[128];
  time_t t = node.uSeconds;
  strftime(sTimeBuff,128,"%T",localtime(&t));  
  
  printf( "[%d] %s.%03u Fid 0x%05x Off 0x%Lx Dmg 0x%x ", 
    iSerial, sTimeBuff, (int)(node.uNanoseconds/1e6), 
    node.uFiducial, (long long) node.i64OffsetXtc, node.damage.value() );

  if ( (int) node.uMaskDetDmgs == -1 && _mapSegToId.size() >= sizeof(node.uMaskDetDmgs) * 8)
    printf( "DetDmg [Undetermined]");
  else
    printf( "DetDmg 0x%x ", node.uMaskDetDmgs);

  if ( (int) node.uMaskDetData == -1 && _mapSegToId.size() >= sizeof(node.uMaskDetData) * 8)
    printf( "DetData [Undetermined]");
  else
    printf( "DetData 0x%x ", node.uMaskDetData);    
    
  /*
   * print events     
   */
  if ( node.uMaskEvrEvents != 0 )
  {
    if ( (int) node.uMaskEvrEvents == -1 && _mapEvrToId.size() >= sizeof(node.uMaskEvrEvents) * 8)
      printf("Evn [Undetermined]"); // some event index is larger than the representation length
    else
    {
      printf("Evn ");
      uint32_t uEventBit = 0x1;
      for ( int iBit = 0; iBit < (int) sizeof(node.uMaskEvrEvents)*8; iBit++, uEventBit <<= 1 )
        if ( (node.uMaskEvrEvents & uEventBit) != 0 )
          for ( TEvrEvtToIdMap::const_iterator 
            iterMap =  _mapEvrToId.begin();
            iterMap != _mapEvrToId.end();
            iterMap++ )
          {
            if ( iterMap->second == iBit )
              printf( "[%d] ", iterMap->first );
          }    
    }
  }
  
  printf("\n");
}

int IndexList::writeToFile(int fdFile) const
{  
  int iError = writeFileHeader(fdFile);
  if ( iError != 0 )
    return 1;    
    
  iError = writeFileL1AcceptList(fdFile);
  if ( iError != 0 )
    return 2;    

  iError = writeFileSupplement(fdFile);
  if ( iError != 0 )
    return 3;    
    
  return 0;
}

int IndexList::finishPrevSegmentId()
{
  if ( _itCurSeg == _mapSegToId.end() )
    return 0;

  L1SegmentId&  segId = _itCurSeg->second;
  
  if (segId.srcList.size() != 0 )
    segId.bSrcUpdated   = true;
  
  return 0;
}

int IndexList::readFromFile(int fdFile)
{  
  IndexFileHeaderType fileHeader;
  int iError = readFileHeader  (fdFile, fileHeader);
  if ( iError != 0 )
    return 1;    
  
  iError = readFileL1AcceptList (fdFile, fileHeader.iNumIndex);
  if ( iError != 0 )
    return 2;    

  iError = readFileSupplement (fdFile, fileHeader);
  if ( iError != 0 )
    return 3;    
    
  return 0;
}

IndexList::IndexList()
{
  reset();
  memset( _sXtcFilename, 0, sizeof(_sXtcFilename) );
}

IndexList::IndexList(const char* sXtcFilename)
{
  reset();
  setXtcFilename(sXtcFilename);
}

int IndexList::reset(bool bClearL1NodeLast)
{
  memset( _sXtcFilename, 0, sizeof(_sXtcFilename) );
  _iNumSegments   = -1;
  _bNewNode       = false;
  _pCurNode       = NULL;
  _iCurSerial     = -1;

  _lCalib     .clear();
  _lNode      .clear();
  _mapSegToId .clear();  
  _mapEvrToId .clear();
  
  if (bClearL1NodeLast)
  {
    _bOverlapChecked  = true; // We don't perform overlap checking for the first chunk
    new (&_l1NodeLast) L1AcceptNode();
  }
  else
    _bOverlapChecked  = false;
    
  _iNumOutOrder     = 0;
  _iNumOverlapPrev  = 0;
  _iNumOverlapNext  = 0;
  
  return 0;
}

int IndexList::setXtcFilename(const char* sXtcFilename)
{
  char* sFnCopy = strdup(sXtcFilename);
  char* sBaseFn = basename(sFnCopy);
  
  int iError = 0;
  
  if ( (int) strlen( sBaseFn) >= iMaxFilenameLen)
  {
    printf( "IndexList::setXtcFilename(): xtc filename %s is too long (max=%d), "
      "filename will be truncated.\n", 
      sBaseFn, iMaxFilenameLen-1 );
    iError = 1;
  }
  
  strncpy( _sXtcFilename,  sBaseFn, iMaxFilenameLen-1);     
  _sXtcFilename[iMaxFilenameLen-1] = 0;
  free(sFnCopy);  
  
  return iError;
}

int IndexList::getNumNode() const
{
  return _lNode.size();
}

int IndexList::getNode(int iNode, L1AcceptNode*& pNode)
{
  if ( iNode < 0 || iNode >= (int) _lNode.size() )
    return 1;
    
  pNode = &_lNode[iNode];
  return 0;
}

L1AcceptNode& IndexList::checkInNode( L1AcceptNode& nodeNew )
{
  if ( _lNode.size() == 0 )
  {      
    _lNode.push_back( nodeNew );
    _iCurSerial = 0;
    return _lNode.back();
  }
    
  L1AcceptNode& nodeLast = _lNode.back();
    
  int iCmpTime = nodeNew.laterThan(nodeLast);
  
  if ( iCmpTime <= 0 )  
    ++_iNumOutOrder;

  if ( iCmpTime >= 0 )
  {
    if ( !_bOverlapChecked )
    {
      if ( nodeNew.laterThan(_l1NodeLast) <= 0 )
        ++_iNumOverlapPrev;
      else
        _bOverlapChecked = true;
    }
    
    _lNode.push_back( nodeNew );
    _iCurSerial = _lNode.size() - 1;
    return _lNode.back();
  }

  if ( nodeNew.laterThan(_l1NodeLast) <= 0)
    ++_iNumOverlapPrev;
  
  int iSerial = _lNode.size() - 2;
  for ( TNodeList::iterator 
    itNodeIns =  _lNode.end() - 2;
    itNodeIns >= _lNode.begin();
    itNodeIns--, iSerial-- )
  {
    int iCmpTime = nodeNew.laterThan(*itNodeIns);
    
    if ( iCmpTime <= 0 )  
      ++_iNumOutOrder;
      
    if ( iCmpTime >= 0 )
    {      
      TNodeList::iterator iterNew = _lNode.insert( itNodeIns+1, nodeNew );
      _iCurSerial = iSerial+1;
      return *iterNew;
    }          
  }  

  /*
   * Remaining case:
   *   The new node should be inserted at the front of the list
   */
  printf( "IndexList::checkInNode(): *** event 0x%x need to be inserted at front (total %d elements)\n", 
    nodeNew.uFiducial, (int) _lNode.size() ); // !! debug
   
  _lNode.insert( _lNode.begin(), nodeNew );
  _iCurSerial = 0;
  return _lNode.front();  
}

int IndexList::writeFileHeader(int fdFile) const
{  
  /*
   * Write main header
   */
  IndexFileHeaderType fileHeader(*this);
  int iError = ::write(fdFile, &fileHeader, sizeof(fileHeader) );
  if ( iError == -1 )
  {
    printf( "IndexList::writeFileHeader(): write file info header failed (%s)\n", strerror(errno) );
    return 1;
  }
      
  return 0;
}

int IndexList::writeFileL1AcceptList(int fdFile) const 
{
  int iNode = 0;
  
  for (TNodeList::const_iterator 
    iterNode =  _lNode.begin();
    iterNode != _lNode.end();
    iterNode++, iNode++)
  {
    IndexFileL1NodeType node(*iterNode);

    int iError = ::write(fdFile, &node, sizeof(node) );
    if ( iError == -1 )
    {
      printf( "IndexList::writeFileL1AcceptList(): write node %d failed (%s)\n", iNode, strerror(errno) );              
      return 1;
    }
  }

  return 0;
}

int IndexList::writeFileSupplement(int fdFile) const
{
  /*
   * Write BeginCalibCycle
   */
  int iError = ::write(fdFile, &_lCalib[0], _lCalib.size() * sizeof(_lCalib[0]) );  
  if ( iError == -1 )
  {
    printf( "IndexList::writeFileHeader(): write calib node failed (%s)\n", strerror(errno) );    
    return 1;
  }
    
  /*
   * Write event codes
   */
  uint8_t lEventCodes[_mapEvrToId.size()];  
  memset(lEventCodes, 0, sizeof(lEventCodes));
  for ( TEvrEvtToIdMap::const_iterator 
    itMap =  _mapEvrToId.begin();
    itMap != _mapEvrToId.end();
    itMap++ )
  {    
    if ( itMap->second >= (int) _mapEvrToId.size() )
      printf("IndexList::writeFileHeader(): Found invalid evr index %d for code %d\n",
        itMap->second, itMap->first);
    else
      lEventCodes[itMap->second] = itMap->first;
  }
    
  iError = ::write(fdFile, &lEventCodes, sizeof(lEventCodes) );
  if ( iError == -1 )
  {
    printf( "IndexList::writeFileHeader(): write event code failed (%s)\n", strerror(errno) );    
    return 2;
  }
    

  /*
   * Write segments
   */    
  const L1SegmentIndex* lSegmentIndex[_mapSegToId.size()];
  const L1SegmentId*    lSegmentId[_mapSegToId.size()];
  memset(lSegmentIndex, 0, sizeof(lSegmentIndex));
  memset(lSegmentId   , 0, sizeof(lSegmentId));
  for ( TSegmentToIdMap::const_iterator 
    itMap =  _mapSegToId.begin();
    itMap != _mapSegToId.end();
    itMap++ )
  {    
    int iIndex = itMap->second.iIndex;
    if ( iIndex >= (int) _mapSegToId.size() )
    {
      printf("IndexList::writeFileHeader(): Found invalid segment index %d\n", iIndex);
      continue;
    }
    
    lSegmentIndex[iIndex] = &itMap->first;
    lSegmentId   [iIndex] = &itMap->second;
  }
  
  for ( int iSeg = 0; iSeg < (int) _mapSegToId.size(); ++iSeg )
  {
    if (lSegmentIndex[iSeg] == NULL)
    {
      printf( "IndexList::writeFileHeader(): No ProcInfo assigned for segment %d\n",  iSeg);    
      return 3;
    }    
    const L1SegmentIndex& segIndex = *lSegmentIndex[iSeg];
    const ProcInfo& info  = segIndex.procNode;
    iError = ::write(fdFile, &info, sizeof(info) );
    if ( iError == -1 )
    {
      printf( "IndexList::writeFileHeader(): write proc info failed (%s)\n", strerror(errno) );    
      return 4;
    }

    /*
     * Write source and typeId list for each segment
     */    
    if (lSegmentId[iSeg] == NULL)
    {
      printf( "IndexList::writeFileHeader(): No src/type data found for segment %d\n",  iSeg);    
      return 5;
    }     
    const L1SegmentId& segId = *lSegmentId[iSeg];
    uint8_t uNumSrc = segId.srcList.size();
    iError = ::write(fdFile, &uNumSrc, sizeof(uNumSrc) );
    if ( iError == -1 )
    {
      printf( "IndexList::writeFileHeader(): write NumSrc failed (%s)\n", strerror(errno) );    
      return 6;
    }      
      
    iError = ::write(fdFile, &segId.srcList[0], segId.srcList.size() * sizeof(segId.srcList[0]) );  
    if ( iError == -1 )
    {
      printf( "IndexList::writeFileHeader(): write src list failed (%s)\n", strerror(errno) );    
      return 7;
    }      

    iError = ::write(fdFile, &segId.typeList[0], segId.typeList.size() * sizeof(segId.typeList[0]) );  
    if ( iError == -1 )
    {
      printf( "IndexList::writeFileHeader(): write type list failed (%s)\n", strerror(errno) );               
      return 8;
    }      
  }    
  
  return 0;
}

int IndexList::readFileHeader(int fdFile, IndexFileHeaderType& fileHeader)
{
  /*
   * Read main header
   */
  TypeId typeId;
  int iError = ::read(fdFile, &typeId, sizeof(typeId) );
  if ( iError == -1 )
  {
    printf( "IndexList::readFileHeader(): read file header version failed (%s)\n", strerror(errno) );
    return 1;
  }
  
  if ( typeId.id() != TypeId::Id_Index  )
  {
    printf( "IndexList::readFileHeader(): Unsupported xtc type: %s V%d\n",
      TypeId::name(typeId.id()), typeId.version() );
    return 2;
  }

  // printf( "Xtc index header type: %s V%d\n", TypeId::name(typeId.id()), typeId.version() );
  
  /*
   * Provide back-compatibility with the previous header version
   */
  if ( (int) typeId.version() != IndexFileHeaderType::iXtcIndexVersion )
  {
    if ( (int) typeId.version() == 1 )
    {
      IndexFileHeaderV1 fileHeaderV1;
      lseek64(fdFile, 0, SEEK_SET);
      int iError = ::read(fdFile, &fileHeaderV1, sizeof(IndexFileHeaderV1) );
      if ( iError == -1 )
      {
        printf( "IndexList::readFileHeader(): read file header failed (%s)\n", strerror(errno) );
        return 1;
      }    
      
      new (&fileHeader) IndexFileHeaderType(fileHeaderV1);
    }
    else
    {
      printf( "IndexList::readFileHeader(): Unsupported xtc type: %s V%d\n",
        TypeId::name(typeId.id()),
        typeId.version() );
      return 2;
    }
  }
  else
  {
    lseek64(fdFile, 0, SEEK_SET);
    int iError = ::read(fdFile, &fileHeader, sizeof(fileHeader) );
    if ( iError == -1 )
    {
      printf( "IndexList::readFileHeader(): read file header failed (%s)\n", strerror(errno) );
      return 1;
    }    
  }
  
  strncpy( _sXtcFilename, fileHeader.sXtcFilename, iMaxFilenameLen-1);    
  _sXtcFilename[iMaxFilenameLen-1] = 0;
  
  return 0;
}

int IndexList::readFileL1AcceptList(int fdFile, int iNumIndex)
{  
  _lNode.clear();  
  for ( int iNode = 0; iNode < iNumIndex; iNode++ )
  {
    IndexFileL1NodeType fileNode;

    int iError = ::read(fdFile, &fileNode, sizeof(fileNode) );
    if ( iError == -1 )
    {
      printf( "IndexList::readFileL1AcceptList(): read node %d failed (%s)\n", iNode, strerror(errno) );              
      return 1;
    }

    L1AcceptNode l1Node(fileNode);
    _lNode.push_back(l1Node);
  }
  
  return 0;  
}

int IndexList::readFileSupplement(int fdFile, const IndexFileHeaderType& fileHeader)
{  
  int iError = -1;
  
  /*
   * Read BeginCalibCycle
   */
  int iNumCalib = fileHeader.iNumCalib;  
  _lCalib.resize(iNumCalib);
  if (iNumCalib > 0)
  {
    iError = ::read(fdFile, &_lCalib[0], _lCalib.size() * sizeof(_lCalib[0]) );
    if ( iError == -1 )
    {
      printf( "IndexList::readFileHeader(): read calib failed (%s)\n", strerror(errno) );
      return 1;
    }
  }

  /*
   * Read event codes
   */
  int iNumEvrEvents = fileHeader.iNumEvrEvents;
  if ( iNumEvrEvents < 0 )
  {
    printf("IndexList::readFileHeader(): Invalid Evr event # %d\n", iNumEvrEvents);
    iNumEvrEvents = 0;
  }
  else if ( iNumEvrEvents > 0 )
  {
    uint8_t lEventCodes[iNumEvrEvents];  
    iError = ::read(fdFile, lEventCodes, sizeof(lEventCodes) );
    if ( iError == -1 )
    {
      printf( "IndexList::readFileHeader(): read Evr events failed (%s)\n", strerror(errno) );
      return 2;
    }
        
    for (int iEvrEvent = 0; iEvrEvent < iNumEvrEvents; ++iEvrEvent )
      _mapEvrToId.insert( 
        TEvrEvtToIdMap::value_type( (int) lEventCodes[iEvrEvent], iEvrEvent ) );
  }
  
  /*
   * Read segments
   */    
  _iNumSegments = fileHeader.iNumDetector;  
  _mapSegToId.clear();
  for ( int iSeg = 0; iSeg < _iNumSegments; iSeg++ )
  {
    ProcInfo info(Level::Segment,0,0);
    iError = ::read(fdFile, &info, sizeof(info) );
    if ( iError == -1 )
      printf( "IndexList::readFileHeader(): read proc info failed (%s)\n", strerror(errno) );
    
    std::pair<TSegmentToIdMap::iterator,bool> 
      rInsert = _mapSegToId.insert( 
        TSegmentToIdMap::value_type( info, L1SegmentId(iSeg) ) );
      
    if ( !rInsert.second )
    {
      printf( "IndexList::readFileHeader(): read duplicated segment for "
        "ip 0x%x pid 0x%x\n", info.ipAddr(), info.processId() );
    }
    
    uint8_t uNumSrc;
    iError = ::read(fdFile, &uNumSrc, sizeof(uNumSrc) );
    if ( iError == -1 )
      printf( "IndexList::readFileHeader(): read NumSrc failed (%s)\n", strerror(errno) );        
    
    L1SegmentId& segId = rInsert.first->second;
    segId.srcList .resize(uNumSrc);
    segId.typeList.resize(uNumSrc);
    if (uNumSrc > 0)
    {
      iError = ::read(fdFile, &segId.srcList[0], segId.srcList.size() * sizeof(segId.srcList[0]) );
      if ( iError == -1 )
      {
        printf( "IndexList::readFileHeader(): read src list failed (%s)\n", strerror(errno) );
        return 3;
      }
      
      iError = ::read(fdFile, &segId.typeList[0], segId.typeList.size() * sizeof(segId.typeList[0]) );
      if ( iError == -1 )
      {
        printf( "IndexList::readFileHeader(): read type list failed (%s)\n", strerror(errno) );
        return 4;
      }
    }        
    segId.bSrcUpdated = true;
  }    
  
  return 0;
}

/*
 * class L1SegmentIndex
 */ 
L1SegmentIndex::L1SegmentIndex(const ProcInfo& procNode1) :
  procNode(procNode1)
{
}

bool L1SegmentIndex::operator<(const L1SegmentIndex& right) const
{
  if ( procNode.ipAddr() == right.procNode.ipAddr() )
    return ( procNode.processId() < right.procNode.processId() );
  else 
    return ( procNode.ipAddr() < right.procNode.ipAddr() );
}

/*
 * class L1SegmentId
 */ 
L1SegmentId::L1SegmentId(int iIndex1) : 
  iIndex(iIndex1), bSrcUpdated(false)
{
}
 
/*
 * class L1AcceptNode
 */ 
L1AcceptNode::L1AcceptNode() :
  uSeconds(0), uNanoseconds(0), uFiducial(0), i64OffsetXtc(0), 
  damage(0), uMaskDetDmgs(0), uMaskDetData(0), uMaskEvrEvents(0)
{
}
 
L1AcceptNode::L1AcceptNode(uint32_t uSeconds1, uint32_t uNanoseconds1, uint32_t uFiducial1, int64_t i64Offset1) :
  uSeconds(uSeconds1), uNanoseconds(uNanoseconds1), uFiducial(uFiducial1), i64OffsetXtc(i64Offset1), 
  damage(0), uMaskDetDmgs(0), uMaskDetData(0), uMaskEvrEvents(0)
{
}

L1AcceptNode::L1AcceptNode(IndexFileL1NodeType& fileNode) :
  uSeconds      (fileNode.uSeconds),
  uNanoseconds  (fileNode.uNanoseconds),
  uFiducial     (fileNode.uFiducial), 
  i64OffsetXtc  (fileNode.i64OffsetXtc), 
  damage        (fileNode.damage),
  uMaskDetDmgs  (fileNode.uMaskDetDmgs),
  uMaskDetData  (fileNode.uMaskDetData),
  uMaskEvrEvents(fileNode.uMaskEvrEvents)
{
}

int L1AcceptNode::laterThan(const L1AcceptNode& node)
{
  if ( uSeconds > node.uSeconds )           return 1;
  if ( uSeconds < node.uSeconds )           return -1;
  if ( uNanoseconds > node.uNanoseconds )   return 1;
  if ( uNanoseconds < node.uNanoseconds )   return -1;  
  
  return 0;
}

} // namespace Index
} // namespace Pds

