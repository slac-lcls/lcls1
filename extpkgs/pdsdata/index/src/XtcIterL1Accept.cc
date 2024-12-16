#include "pdsdata/xtc/DetInfo.hh"
#include "pdsdata/xtc/ProcInfo.hh"
#include "pdsdata/xtc/BldInfo.hh"

#include "pdsdata/index/XtcIterL1Accept.hh"

#include <stdio.h>

namespace Pds
{  
namespace Index 
{

int XtcIterL1Accept::process(Xtc * xtc)
{
  Level::Type     level             = xtc->src.level();
  int64_t         i64OffsetPayload  = _i64Offset + sizeof(Xtc);
  bool            bStopUpdate       = false;

  if (xtc->damage.value() & (1<<Damage::IncompleteContribution))
    return XtcIterL1Accept::Stop;
    
  if (xtc->extent < sizeof(Xtc) ||
      (xtc->extent&3) ||
      (xtc->contains.id() >= TypeId::NumberOf) ||
      (xtc->damage.value()==0 && xtc->contains.id() == TypeId::Any) ||
      (xtc->src.level() >= Level::NumberOfLevels)) {
    printf( "XtcIterL1Accept::process(): *** Skipping corrupt xtc: src %08x.%08x ctns %08x extent %08x\n",
            xtc->src.log(), xtc->src.phy(), xtc->contains.value(), xtc->extent);
    return XtcIterL1Accept::Stop;
  }
      
  if (level == Level::Segment)
  {
    if ( _depth != 0 )
      printf( "XtcIterL1Accept::process(): *** Error depth: Expect 0, but get %d, level %s\n", 
        _depth, Level::name(level) );
    
    _pIndexList->updateSegment( *xtc );    
  }  
  else if (level == Level::Source)
  {
    // Source level normally appear at level 1 only, except for Fccd (which shows at level 2)
    if ( _depth != 1 && _depth != 2 )
      printf( "XtcIterL1Accept::process(): *** Error depth: Expect level 1 or 2, but get %d, level %s\n", 
        _depth, Level::name(level) );
    
    _pIndexList->updateSource( *xtc, bStopUpdate );    
  }  
  else if (level == Level::Reporter)
  {
    if ( _depth != 1 ) {
      if ((_lquiet&1)==0) {
        printf( "XtcIterL1Accept::process(): *** Error depth: Expect 1, but get %d, level %s\n", 
                _depth, Level::name(level) );
        printf("\tSuppressing further identical messages\n");
        _lquiet |= 1;
      }
    }
    else
      _pIndexList->updateReporter( *xtc, bStopUpdate );    
  }
  else if (level == Level::Event)
  {
  }
  else
  {         
    printf( "XtcIterL1Accept::process(): *** Error level %s depth = %d", Level::name(level), _depth );     
  }  

  _i64Offset += sizeof(Xtc) + xtc->sizeofPayload();
    
  // depth > 0 : Will stop after current node
  
  if ( bStopUpdate )
    return XtcIterL1Accept::Stop;
    
  // Remaining case: depth == 0 : Will process more segment nodes
  
  if (xtc->contains.id() == TypeId::Id_Xtc)
  {
    XtcIterL1Accept iter(xtc, _depth + 1, i64OffsetPayload, *_pIndexList, _lquiet);
    iter.iterate();
  }
    
  return XtcIterL1Accept::Continue;     
}
 
} // namespace Index 
} // namespace Pds
