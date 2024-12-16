#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <map>
#include <string>

#include "pdsdata/xtc/DetInfo.hh"
#include "pdsdata/xtc/ProcInfo.hh"
#include "pdsdata/xtc/XtcIterator.hh"
#include "pdsdata/xtc/XtcFileIterator.hh"
#include "pdsdata/psddl/acqiris.ddl.h"
#include "pdsdata/psddl/ipimb.ddl.h"
#include "pdsdata/psddl/encoder.ddl.h"
#include "pdsdata/psddl/camera.ddl.h"
#include "pdsdata/psddl/fccd.ddl.h"
#include "pdsdata/psddl/timepix.ddl.h"
#include "pdsdata/psddl/opal1k.ddl.h"
#include "pdsdata/psddl/pulnix.ddl.h"
#include "pdsdata/psddl/pnccd.ddl.h"
#include "pdsdata/psddl/evr.ddl.h"
#include "pdsdata/psddl/control.ddl.h"
#include "pdsdata/psddl/epics.ddl.h"
#include "pdsdata/psddl/bld.ddl.h"
#include "pdsdata/psddl/princeton.ddl.h"
#include "pdsdata/psddl/cspad.ddl.h"
#include "pdsdata/psddl/cspad2x2.ddl.h"
#include "pdsdata/psddl/lusi.ddl.h"
#include "pdsdata/psddl/alias.ddl.h"
#include "pdsdata/psddl/rayonix.ddl.h"
#include "pdsdata/psddl/smldata.ddl.h"
#include "pdsdata/psddl/partition.ddl.h"
#include "pdsdata/psddl/timetool.ddl.h"
#include "pdsdata/psddl/jungfrau.ddl.h"
#include "pdsdata/psddl/epix.ddl.h"
#include "pdsdata/psddl/zyla.ddl.h"
#include "pdsdata/psddl/istar.ddl.h"
#include "pdsdata/psddl/vimba.ddl.h"
#include "pdsdata/psddl/uxi.ddl.h"

static unsigned eventCount = 0;

using namespace Pds;
using std::map;
using std::string;
using Pds::Alias::SrcAlias;

static map<Src,string> aliasMap;

class myLevelIter : public XtcIterator {
public:
  enum {Stop, Continue};
  myLevelIter(Xtc* xtc, unsigned depth, long long int lliOffset) : XtcIterator(xtc), _depth(depth), _lliOffset(lliOffset) {}

  void process(const DetInfo& d, const Camera::FrameV1& f) {
    printf("*** Processing frame object\n");
  }
  void process(const DetInfo&, const Acqiris::DataDescV1&) {
    printf("*** Processing acqiris data object\n");
  }
  void process(const DetInfo&, const Acqiris::ConfigV1&) {
    printf("*** Processing Acqiris config object\n");
  }
  void process(const DetInfo& i, const Acqiris::TdcDataV1& d, uint32_t payloadSize) {
    printf("*** Processing acqiris TDC data object for %s\n",
     DetInfo::name(i));
    unsigned nItems = payloadSize / sizeof(Acqiris::TdcDataV1_Item);
    ndarray<const Acqiris::TdcDataV1_Item,1> a = d.data(nItems);
    for(unsigned j=0; j<a.shape()[0]; j++) {
      if (a[j].source() == Acqiris::TdcDataV1_Item::AuxIO &&
          static_cast<const Acqiris::TdcDataV1Marker&>(a[j]).type() < Acqiris::TdcDataV1Marker::AuxIOMarker) 
        break;
      switch(a[j].source()) {
      case Acqiris::TdcDataV1_Item::Comm:
        printf("common start %d\n",
               static_cast<const Acqiris::TdcDataV1Common&>(a[j]).nhits());
        break;
      case Acqiris::TdcDataV1_Item::AuxIO:
        break;
      default:
        { 
          const Acqiris::TdcDataV1Channel& c = 
            static_cast<const Acqiris::TdcDataV1Channel&>(a[j]);
          if (!c.overflow())
            printf("ch %d : %g ns\n",
                   a[j].source()-1, c.time());
          break;
        }
      }
    }
  }
  void process(const DetInfo& i, const Acqiris::TdcConfigV1& c) {
    printf("*** Processing Acqiris TDC config object for %s\n",
     DetInfo::name(i));
    for(unsigned j=0; j<Acqiris::TdcConfigV1::NChannels; j++) {
      const Acqiris::TdcChannel& ch = c.channels()[j];
      printf("chan %d : %s, slope %c, level %gv\n",
             ch.channel(),
             ch.mode ()==Acqiris::TdcChannel::Inactive?"inactive":"active",
             ch.slope()==Acqiris::TdcChannel::Positive?'+':'-',
             ch.level());
    }
  }
  void process(const DetInfo&, const Ipimb::DataV1&) {
    printf("*** Processing ipimb data object\n");
  }
  void process(const DetInfo&, const Ipimb::ConfigV1&) {
    printf("*** Processing Ipimb config object\n");
  }
  void process(const DetInfo&, const Ipimb::DataV2&) {
    printf("*** Processing ipimb data object\n");
  }
  void process(const DetInfo&, const Ipimb::ConfigV2&) {
    printf("*** Processing Ipimb config object\n");
  }
  void process(const DetInfo&, const Encoder::DataV1&) {
    printf("*** Processing encoder DataV1 object\n");
  }
  void process(const DetInfo&, const Encoder::DataV2&) {
    printf("*** Processing encoder DataV2 object\n");
  }
  void process(const DetInfo&, const Encoder::ConfigV1&) {
    printf("*** Processing Encoder config object\n");
  }
  void process(const DetInfo&, const Opal1k::ConfigV1&) {
    printf("*** Processing Opal1000 config object\n");
  }
  void process(const DetInfo&, const Camera::FrameFexConfigV1&) {
    printf("*** Processing frame feature extraction config object\n");
  }
  void process(const DetInfo&, const FCCD::FccdConfigV1&) {
    printf("*** Processing FCCD ConfigV1 object\n");
  }
  void process(const DetInfo&, const FCCD::FccdConfigV2&) {
    printf("*** Processing FCCD ConfigV2 object\n");
  }
  void process(const DetInfo&, const Timepix::ConfigV1&) {
    printf("*** Processing Timepix ConfigV1 object\n");
  }
  void process(const DetInfo&, const Timepix::ConfigV2&) {
    printf("*** Processing Timepix ConfigV2 object\n");
  }
  void process(const DetInfo&, const Timepix::ConfigV3&) {
    printf("*** Processing Timepix ConfigV3 object\n");
  }
  void process(const DetInfo&, const Timepix::DataV1&) {
    printf("*** Processing Timepix DataV1 object\n");
  }
  void process(const DetInfo&, const Timepix::DataV2&) {
    printf("*** Processing Timepix DataV2 object\n");
  }
  void process(const DetInfo&, const Camera::TwoDGaussianV1& o) {
    printf("*** Processing 2DGauss object\n");
  }
  void process(const DetInfo& det, const PNCCD::ConfigV1& config) {
    if ( det.detId() != 0 )
    {
      printf( "myLevelIter::process(...,PNCCD::ConfigV1&): pnCCD detector Id (%d) is not 0\n", det.detId() );
      return;
    }
    if ( det.devId() < 0 || det.devId() > 1)
    {
      printf( "myLevelIter::process(...,PNCCD::ConfigV1&): pnCCD device Id (%d) is out of range (0..1)\n", det.devId() );
      return;
    }
    
    _pnCcdCfgListV1[det.devId()] = config;
    printf("*** Processing pnCCD config.  Number of Links: %d, PayloadSize per Link: %d\n",
           config.numLinks(),config.payloadSizePerLink());
  }  
  void process(const DetInfo& det, const PNCCD::ConfigV2& config) {
    if ( det.detId() != 0 )
    {
      printf( "myLevelIter::process(...,PNCCD::ConfigV2&): pnCCD detector Id (%d) is not 0\n", det.detId() );
      return;
    }
    if ( det.devId() < 0 || det.devId() > 1)
    {
      printf( "myLevelIter::process(...,PNCCD::ConfigV2&): pnCCD device Id (%d) is out of range (0..1)\n", det.devId() );
      return;
    }

    _pnCcdCfgListV2[det.devId()] = config;
    printf("*** Processing pnCCD config.  Number of Links: %u, PayloadSize per Link: %u\n",
           config.numLinks(),config.payloadSizePerLink());
    printf("\tNumber of Channels %u, Number of Rows %u, Number of SubModule Channels %u\n\tNumber of SubModule Rows %u, Number of SubModules, %u\n",
        config.numChannels(),config.numRows(), config.numSubmoduleChannels(),config.numSubmoduleRows(),config.numSubmodules());
    printf("\tCamex Magic 0x%x, info %s, Timing File Name %s\n", config.camexMagic(),config.info(),config.timingFName());
  }
  void process(const DetInfo& det, const PNCCD::FrameV1* f) {
    if ( det.detId() != 0 )
    {
      printf( "myLevelIter::process(...,PNCCD::FrameV1*): pnCCD detector Id (%d) is not 0\n", det.detId() );
      return;
    }
    if ( det.devId() < 0 || det.devId() > 1)
    {
      printf( "myLevelIter::process(...,PNCCD::FrameV1*): pnCCD device Id (%d) is out of range (0..1)\n", det.devId() );
      return;
    }
    
    printf("*** Processing pnCCD Frame\n");
  }  
  void process(const DetInfo&, const ControlData::ConfigV1& config) {
    printf("*** Processing Control config object\n");    
    
    printf( "Control PV Number = %d, Monitor PV Number = %d\n", config.npvControls(), config.npvMonitors() );
    for(unsigned int iPvControl=0; iPvControl < config.npvControls(); iPvControl++) {      
      const Pds::ControlData::PVControl& pvControlCur = config.pvControls()[iPvControl];
      if (pvControlCur.array())
        printf( "%s[%d] = ", pvControlCur.name(), pvControlCur.index() );
      else
        printf( "%s = ", pvControlCur.name() );
      printf( "%lf\n", pvControlCur.value() );
    }
    
    for(unsigned int iPvMonitor=0; iPvMonitor < config.npvMonitors(); iPvMonitor++) {      
      const Pds::ControlData::PVMonitor& pvMonitorCur = config.pvMonitors()[iPvMonitor];
      if (pvMonitorCur.array())
        printf( "%s[%d]  ", pvMonitorCur.name(), pvMonitorCur.index() );
      else
        printf( "%s  ", pvMonitorCur.name() );
      printf( "Low %lf  High %lf\n", pvMonitorCur.loValue(), pvMonitorCur.hiValue() );
    }
          
  }  
  void process(const DetInfo&, const ControlData::ConfigV2& config) {
    printf("*** Processing Control config object\n");    
    
    printf( "Control PV Number = %d, Monitor PV Number = %d, Label PV Number = %d\n", config.npvControls(), config.npvMonitors(), config.npvLabels() );
    for(unsigned int iPvControl=0; iPvControl < config.npvControls(); iPvControl++) {      
      const Pds::ControlData::PVControl& pvControlCur = config.pvControls()[iPvControl];
      if (pvControlCur.array())
        printf( "%s[%d] = ", pvControlCur.name(), pvControlCur.index() );
      else
        printf( "%s = ", pvControlCur.name() );
      printf( "%lf\n", pvControlCur.value() );
    }
    
    for(unsigned int iPvMonitor=0; iPvMonitor < config.npvMonitors(); iPvMonitor++) {      
      const Pds::ControlData::PVMonitor& pvMonitorCur = config.pvMonitors()[iPvMonitor];
      if (pvMonitorCur.array())
        printf( "%s[%d]  ", pvMonitorCur.name(), pvMonitorCur.index() );
      else
        printf( "%s  ", pvMonitorCur.name() );
      printf( "Low %lf  High %lf\n", pvMonitorCur.loValue(), pvMonitorCur.hiValue() );
    }
          
    for(unsigned int iPvLabel=0; iPvLabel < config.npvLabels(); iPvLabel++) {      
      const Pds::ControlData::PVLabel& pvLabelCur = config.pvLabels()[iPvLabel];
      printf( "%s = %s\n", pvLabelCur.name(), pvLabelCur.value() );
    }
          
  } 
  void process(const DetInfo&, const ControlData::ConfigV3& config) {
    printf("*** Processing Control config object\n");    
    
    printf( "Control PV Number = %d, Monitor PV Number = %d, Label PV Number = %d\n", config.npvControls(), config.npvMonitors(), config.npvLabels() );
    for(unsigned int iPvControl=0; iPvControl < config.npvControls(); iPvControl++) {      
      const Pds::ControlData::PVControl& pvControlCur = config.pvControls()[iPvControl];
      if (pvControlCur.array())
        printf( "%s[%d] = ", pvControlCur.name(), pvControlCur.index() );
      else
        printf( "%s = ", pvControlCur.name() );
      printf( "%lf\n", pvControlCur.value() );
    }
    
    for(unsigned int iPvMonitor=0; iPvMonitor < config.npvMonitors(); iPvMonitor++) {      
      const Pds::ControlData::PVMonitor& pvMonitorCur = config.pvMonitors()[iPvMonitor];
      if (pvMonitorCur.array())
        printf( "%s[%d]  ", pvMonitorCur.name(), pvMonitorCur.index() );
      else
        printf( "%s  ", pvMonitorCur.name() );
      printf( "Low %lf  High %lf\n", pvMonitorCur.loValue(), pvMonitorCur.hiValue() );
    }
          
    for(unsigned int iPvLabel=0; iPvLabel < config.npvLabels(); iPvLabel++) {      
      const Pds::ControlData::PVLabel& pvLabelCur = config.pvLabels()[iPvLabel];
      printf( "%s = %s\n", pvLabelCur.name(), pvLabelCur.value() );
    }
          
  }
  void process(const DetInfo&, const ControlData::ConfigV4& config) {
    printf("*** Processing Control config object\n");    
    
    printf( "Control PV Number = %d, Monitor PV Number = %d, Label PV Number = %d\n", config.npvControls(), config.npvMonitors(), config.npvLabels() );
    for(unsigned int iPvControl=0; iPvControl < config.npvControls(); iPvControl++) {      
      const Pds::ControlData::PVControlV1& pvControlCur = config.pvControls()[iPvControl];
      if (pvControlCur.array())
        printf( "%s[%d] = ", pvControlCur.name(), pvControlCur.index() );
      else
        printf( "%s = ", pvControlCur.name() );
      printf( "%lf\n", pvControlCur.value() );
    }
    
    for(unsigned int iPvMonitor=0; iPvMonitor < config.npvMonitors(); iPvMonitor++) {      
      const Pds::ControlData::PVMonitorV1& pvMonitorCur = config.pvMonitors()[iPvMonitor];
      if (pvMonitorCur.array())
        printf( "%s[%d]  ", pvMonitorCur.name(), pvMonitorCur.index() );
      else
        printf( "%s  ", pvMonitorCur.name() );
      printf( "Low %lf  High %lf\n", pvMonitorCur.loValue(), pvMonitorCur.hiValue() );
    }
          
    for(unsigned int iPvLabel=0; iPvLabel < config.npvLabels(); iPvLabel++) {      
      const Pds::ControlData::PVLabelV1& pvLabelCur = config.pvLabels()[iPvLabel];
      printf( "%s = %s\n", pvLabelCur.name(), pvLabelCur.value() );
    }
          
  } 

  void process(const DetInfo&, const Epics::EpicsPvHeader& epicsPv)
  {    
    printf("*** Processing Epics object\n");
    //    epicsPv.printPv();
    printf( "\n" );
  }
  void process(const DetInfo&, const Bld::BldDataFEEGasDetEnergy& bldData) {
    printf("*** Processing FEEGasDetEnergy object\n");
//     bldData.print();
//     printf( "\n" );    
  }  
  void process(const DetInfo&, const Bld::BldDataFEEGasDetEnergyV1& bldData) {
    printf("*** Processing FEEGasDetEnergyV1 object\n");
//     bldData.print();
//     printf( "\n" );    
  }  
  void process(const DetInfo&, const Bld::BldDataEBeamV0& bldData) {
    printf("*** Processing EBeamV0 object\n");
//     bldData.print();
//     printf( "\n" );    
  }  
  void process(const DetInfo&, const Bld::BldDataEBeamV1& bldData) {
    printf("*** Processing EBeamV1 object\n");
//     bldData.print();
//     printf( "\n" );    
  }  
  void process(const DetInfo&, const Bld::BldDataEBeamV2& bldData) {
    printf("*** Processing EBeamV2 object\n");
//     bldData.print();
//     printf( "\n" );    
  }  
  void process(const DetInfo&, const Bld::BldDataEBeamV3& bldData) {
    printf("*** Processing EBeamV3 object\n");
//     bldData.print();
//     printf( "\n" ); 
  }   
  void process(const DetInfo&, const Bld::BldDataEBeamV4& bldData) {
    printf("*** Processing EBeamV4 object\n");
//     bldData.print();
//     printf( "\n" );    
  }
  void process(const DetInfo&, const Bld::BldDataEBeamV5& bldData) {
    printf("*** Processing EBeamV5 object\n");
//     bldData.print();
//     printf( "\n" );    
  }
  void process(const DetInfo&, const Bld::BldDataEBeamV6& bldData) {
    printf("*** Processing EBeamV6 object\n");
//     bldData.print();
//     printf( "\n" );    
  }  
  void process(const DetInfo&, const Bld::BldDataPhaseCavity& bldData) {
    printf("*** Processing PhaseCavity object\n");
//     bldData.print();
//     printf( "\n" );    
  } 
  void process(const DetInfo&, const Bld::BldDataIpimbV0& bldData) {
    printf("*** Processing Bld-Ipimb V0 object\n");
//     bldData.print();
//     printf( "\n" );    
  } 
  void process(const DetInfo&, const Bld::BldDataIpimbV1& bldData) {
    printf("*** Processing Bld-Ipimb V1 object\n");
//     bldData.print();
//     printf( "\n" );    
  } 
  
  void process(const DetInfo&, const Bld::BldDataGMDV0& bldData) {
    printf("*** Processing Bld-GMD V0 object\n");
//     bldData.print();
//     printf( "\n" );    
  } 

  void process(const DetInfo&, const Bld::BldDataGMDV1& bldData) {
    printf("*** Processing Bld-GMD V1 object\n");
    printf("\tmJ per pulse: %g\n",              bldData.milliJoulesPerPulse());
    printf("\tmJ average: %g\n",                bldData.milliJoulesAverage());
    printf("\tCorrected sum per pulse: %g\n",   bldData.correctedSumPerPulse());
    printf("\tbg value per sample: %g\n",       bldData.bgValuePerSample());
    printf("\trelative energy per pulse: %g\n", bldData.relativeEnergyPerPulse());
  }

  void process(const DetInfo&, const Bld::BldDataGMDV2& bldData) {
    printf("*** Processing Bld-GMD V2 object\n");
//     bldData.print();
//     printf( "\n" );
  }
  
  void process(const DetInfo&, const EvrData::IOConfigV1&) {
    printf("*** Processing EVR IOconfig V1 object\n");
  }
  void process(const DetInfo&, const EvrData::ConfigV1&) {
    printf("*** Processing EVR config V1 object\n");
  }
  void process(const DetInfo&, const EvrData::ConfigV2&) {
    printf("*** Processing EVR config V2 object\n");
  }
  void process(const DetInfo&, const EvrData::ConfigV3&) {
    printf("*** Processing EVR config V3 object\n");
  }
  void process(const DetInfo&, const EvrData::ConfigV4&) {
    printf("*** Processing EVR config V4 object\n");
  }
  void process(const DetInfo&, const EvrData::ConfigV5&) {
    printf("*** Processing EVR config V5 object\n");
  }
  void process(const DetInfo&, const EvrData::ConfigV6&) {
    printf("*** Processing EVR config V6 object\n");
  }
  void process(const DetInfo&, const EvrData::ConfigV7&) {
    printf("*** Processing EVR config V7 object\n");
  }
  void process(const DetInfo&, const EvrData::DataV3& data) {
    printf("*** Processing Evr Data object\n");
    eventCount++;    

    printf( "# of Fifo Events: %u\n", data.numFifoEvents() );
    for ( unsigned int iEventIndex=0; iEventIndex< data.numFifoEvents(); iEventIndex++ ) {
      const EvrData::FIFOEvent& event = data.fifoEvents()[iEventIndex];
      printf( "[%02u] Event Code %u  TimeStampHigh 0x%x  TimeStampLow 0x%x\n",
              iEventIndex, event.eventCode(), event.timestampHigh(), event.timestampLow() );
      if (event.eventCode() == 162)
        printf ("Blank shot eventcode 162 found at eventNo: %u \n",eventCount); 
      if (event.eventCode() == 163)
        printf ("Blank shot eventcode 163 found at eventNo: %u \n",eventCount); 
    }    
    printf( "\n" );    
  }  
  void process(const DetInfo&, const Princeton::ConfigV1&) {
    printf("*** Processing Princeton ConfigV1 object\n");
  }
  void process(const DetInfo&, const Princeton::FrameV1&) {
    printf("*** Processing Princeton FrameV1 object\n");
  }
  void process(const DetInfo&, const Princeton::InfoV1&) {
    printf("*** Processing Princeton InfoV1 object\n");
  }
  void process(const DetInfo&, const CsPad2x2::ElementV1&) {
    printf("*** Processing CsPad2x2 ElementV1 object\n");
  }
  void process(const DetInfo&, const CsPad::ElementV1&) {
    printf("*** Processing CsPad ElementV1 object\n");
  }
  void process(const DetInfo&, const CsPad::ConfigV1&) {
    printf("*** Processing CsPad ElementV1 object\n");
  }
  void process(const DetInfo&, const Lusi::IpmFexConfigV1&) {
    printf("*** Processing LUSI IpmFexConfigV1 object\n");
  }
  void process(const DetInfo&, const Lusi::IpmFexConfigV2&) {
    printf("*** Processing LUSI IpmFexConfigV2 object\n");
  }
  void process(const DetInfo&, const Lusi::IpmFexV1&) {
    printf("*** Processing LUSI IpmFexV1 object\n");
  }
  void process(const DetInfo&, const Lusi::DiodeFexConfigV1&) {
    printf("*** Processing LUSI DiodeFexConfigV1 object\n");
  }
  void process(const DetInfo&, const Lusi::DiodeFexConfigV2&) {
    printf("*** Processing LUSI DiodeFexConfigV2 object\n");
  }
  void process(const DetInfo&, const Lusi::DiodeFexV1&) {
    printf("*** Processing LUSI DiodeFexV1 object\n");
  }
  void process(const DetInfo &, const Lusi::PimImageConfigV1 &)
  {
    printf("*** Processing LUSI PimImageConfigV1 object\n");
  }  
  void process(const DetInfo &, const Pulnix::TM6740ConfigV1 &)
  {
    printf("*** Processing Pulnix TM6740ConfigV1 object\n");
  }
  void process(const DetInfo &, const Pulnix::TM6740ConfigV2 &)
  {
    printf("*** Processing Pulnix::TM6740ConfigV2 object\n");
  }  
  void process(const DetInfo &, const Alias::ConfigV1 &aliasConfig)
  {
    printf("*** Processing Alias ConfigV1 object\n");
    ndarray<const SrcAlias,1> a = aliasConfig.srcAlias();
    for(const SrcAlias* p = a.begin(); p!=a.end(); p++) {
      printf("\t%08x.%08x\t%s\n",p->src().log(),p->src().phy(),p->aliasName());
      aliasMap[p->src()] = string(p->aliasName(), SrcAlias::AliasNameMax);
    }      
  }
  void process(const DetInfo &, const Rayonix::ConfigV2 &rayonixConfig)
  {
    char lilbuf[Rayonix::ConfigV2::DeviceIDMax+20];
    printf("*** Processing Rayonix ConfigV2 object\n");
    snprintf(lilbuf, sizeof(lilbuf), "deviceID: '%s'", rayonixConfig.deviceID());
    printf("\t%s\n\treadoutMode: ", lilbuf);
    switch (rayonixConfig.readoutMode()) {
      case Rayonix::ConfigV2::Unknown:  printf("Unknown"); break;
      case Rayonix::ConfigV2::Standard: printf("Standard"); break;
      case Rayonix::ConfigV2::HighGain: printf("HighGain"); break;
      case Rayonix::ConfigV2::LowNoise: printf("LowNoise"); break;
      case Rayonix::ConfigV2::HDR: printf("HDR"); break;
      default: printf("Unrecognized (%d)", (int)rayonixConfig.readoutMode()); break;
    }
    printf("\n");
    printf("\tbinning_f: %d\n", rayonixConfig.binning_f());
    printf("\tbinning_s: %d\n", rayonixConfig.binning_s());
    printf("\ttestPattern: %d\n", rayonixConfig.testPattern());
    printf("\texposure: %d ms\n", rayonixConfig.exposure());
    printf("\ttrigger: 0x%08x\n", rayonixConfig.trigger());
    printf("\trawMode: %d\n", rayonixConfig.rawMode());
    printf("\tdarkFlag: %d\n", rayonixConfig.darkFlag());
  }
  void process(const DetInfo &, const Rayonix::ConfigV1 &rayonixConfig)
  {
    char lilbuf[Rayonix::ConfigV1::DeviceIDMax+20];
    printf("*** Processing Rayonix ConfigV1 object\n");
    snprintf(lilbuf, sizeof(lilbuf), "deviceID: '%s'", rayonixConfig.deviceID());
    printf("\t%s\n\treadoutMode: ", lilbuf);
    switch (rayonixConfig.readoutMode()) {
      case Rayonix::ConfigV1::Standard: printf("Standard"); break;
      case Rayonix::ConfigV1::HighGain: printf("HighGain"); break;
      case Rayonix::ConfigV1::LowNoise: printf("LowNoise"); break;
      case Rayonix::ConfigV1::EDR: printf("EDR"); break;
      default: printf("Unrecognized (%d)", (int)rayonixConfig.readoutMode()); break;
    }
    printf("\n");
    printf("\tbinning_f: %d\n", rayonixConfig.binning_f());
    printf("\tbinning_s: %d\n", rayonixConfig.binning_s());
    printf("\texposure: %d ms\n", rayonixConfig.exposure());
    printf("\ttrigger: 0x%08x\n", rayonixConfig.trigger());
    printf("\trawMode: %d\n", rayonixConfig.rawMode());
    printf("\tdarkFlag: %d\n", rayonixConfig.darkFlag());
  }
  void process(const DetInfo &, const SmlData::ConfigV1 &)
  {
    printf("*** Processing SmlData::ConfigV1 object\n");
  }
  void process(const DetInfo &, const SmlData::ProxyV1 &)
  {
    printf("*** Processing SmlData::ProxyV1 object\n");
  }
  void process(const DetInfo &, const SmlData::OrigDgramOffsetV1 &)
  {
    printf("*** Processing SmlData::OrigDgramOffsetV1 object\n");
  }
  void process(const DetInfo &, const Partition::ConfigV1 &)
  {
    printf("*** Processing Partition::ConfigV1 object\n");
  }
  void process(const DetInfo &, const Partition::ConfigV2 &)
  {
    printf("*** Processing Partition::ConfigV2 object\n");
  }
  void process(const DetInfo &, const TimeTool::ConfigV1 &ttConfig)
  {
    printf("*** Processing TimeTool::ConfigV1 object\n");
    const char* project_axis;
    switch (ttConfig.project_axis()) {
    case TimeTool::ConfigV1::X:
      project_axis = "X";
      break;
    case TimeTool::ConfigV1::Y:
      project_axis = "Y";
      break;
    default:
      project_axis = "Unknown";
      break;
    }
    printf("\tproject_axis: %s\n", project_axis);
    printf("\twrite_image: %u\n", ttConfig.write_image());
    printf("\twrite_projections: %u\n", ttConfig.write_projections());
    printf("\tsubtract_sideband: %u\n", ttConfig.subtract_sideband());
    printf("\tnumber_of_weights: %u\n", ttConfig.number_of_weights());
    printf("\tcalib_poly_dim: %u\n", ttConfig.calib_poly_dim());
    printf("\tbase_name_length: %u\n", ttConfig.base_name_length());
    printf("\tnumber_of_beam_event_codes: %u\n", ttConfig.number_of_beam_event_codes());
    printf("\tnumber_of_laser_event_codes: %u\n", ttConfig.number_of_laser_event_codes());
    printf("\tsignal_cut: %u\n", ttConfig.signal_cut());
    printf("\tsignal roi (x,y): (%u,%u), (%u,%u)\n",
           ttConfig.sig_roi_lo().column(),
           ttConfig.sig_roi_hi().column(),
           ttConfig.sig_roi_lo().row(),
           ttConfig.sig_roi_hi().row());
    printf("\tsb roi (x,y): (%u,%u), (%u,%u)\n",
           ttConfig.sb_roi_lo().column(),
           ttConfig.sb_roi_hi().column(),
           ttConfig.sb_roi_lo().row(),
           ttConfig.sb_roi_hi().row());
    printf("\tsb_convergence: %g\n", ttConfig.sb_convergence());
    printf("\tref_convergence: %g\n", ttConfig.ref_convergence());
    ndarray<const TimeTool::EventLogic, 1> beam_logic = ttConfig.beam_logic();
    printf("\tbeam_logic:\n");
    for (unsigned i=0; i<ttConfig.number_of_beam_event_codes(); i++) {
      const char* logic_op;
      switch (beam_logic[i].logic_op()) {
        case TimeTool::EventLogic::L_OR:
          logic_op = "OR";
          break;
        case TimeTool::EventLogic::L_AND:
          logic_op = "AND";
          break;
        case TimeTool::EventLogic::L_OR_NOT:
          logic_op = "OR NOT";
          break;
        case TimeTool::EventLogic::L_AND_NOT:
          logic_op = "L_AND_NOT";
          break;
        default:
          logic_op = "Unknown";
          break;
      }
      printf("\t\t%s %u\n", logic_op, beam_logic[i].event_code());
    }
    ndarray<const TimeTool::EventLogic, 1> laser_logic = ttConfig.laser_logic();
    printf("\tlaser_logic:\n");
    for (unsigned i=0; i<ttConfig.number_of_laser_event_codes(); i++) {
      const char* logic_op;
      switch (laser_logic[i].logic_op()) {
        case TimeTool::EventLogic::L_OR:
          logic_op = "OR";
          break;
        case TimeTool::EventLogic::L_AND:
          logic_op = "AND";
          break;
        case TimeTool::EventLogic::L_OR_NOT:
          logic_op = "OR NOT";
          break;
        case TimeTool::EventLogic::L_AND_NOT:
          logic_op = "L_AND_NOT";
          break;
        default:
          logic_op = "Unknown";
          break;
      }
      printf("\t\t%s %u\n", logic_op, laser_logic[i].event_code());
    }
    ndarray<const double, 1> weights = ttConfig.weights();
    printf("\tweights:");
    for (unsigned i=0; i<ttConfig.number_of_weights(); i++) {
      if (i%5 == 0)
        printf("\n\t\t%g", weights[i]);
      else
        printf(", %g", weights[i]);
    }
    printf("\n");
    ndarray<const double, 1> calib_poly = ttConfig.calib_poly();
    printf("\tcalib_poly:");
    for (unsigned i=0; i<ttConfig.calib_poly_dim(); i++) {
      if (i%5 == 0)
        printf("\n\t\t%g", calib_poly[i]);
      else
        printf(", %g", calib_poly[i]);
    }
    printf("\n");
    printf("\tbase_name: %s\n", ttConfig.base_name());
    printf("\tsignal_projection_size: %u\n", ttConfig.signal_projection_size());
    printf("\tsideband_projection_size: %u\n", ttConfig.sideband_projection_size());
  }
  void process(const DetInfo &, const TimeTool::ConfigV2 &ttConfig)
  {
    printf("*** Processing TimeTool::ConfigV2 object\n");
    const char* project_axis;
    switch (ttConfig.project_axis()) {
    case TimeTool::ConfigV2::X:
      project_axis = "X";
      break;
    case TimeTool::ConfigV2::Y:
      project_axis = "Y";
      break;
    default:
      project_axis = "Unknown";
      break;
    }
    printf("\tproject_axis: %s\n", project_axis);
    printf("\twrite_image: %u\n", ttConfig.write_image());
    printf("\twrite_projections: %u\n", ttConfig.write_projections());
    printf("\tsubtract_sideband: %u\n", ttConfig.subtract_sideband());
    printf("\tuse_reference_roi: %u\n", ttConfig.use_reference_roi());
    printf("\tnumber_of_weights: %u\n", ttConfig.number_of_weights());
    printf("\tcalib_poly_dim: %u\n", ttConfig.calib_poly_dim());
    printf("\tbase_name_length: %u\n", ttConfig.base_name_length());
    printf("\tnumber_of_beam_event_codes: %u\n", ttConfig.number_of_beam_event_codes());
    printf("\tnumber_of_laser_event_codes: %u\n", ttConfig.number_of_laser_event_codes());
    printf("\tsignal_cut: %u\n", ttConfig.signal_cut());
    printf("\tsignal roi (x,y): (%u,%u), (%u,%u)\n",
           ttConfig.sig_roi_lo().column(),
           ttConfig.sig_roi_hi().column(),
           ttConfig.sig_roi_lo().row(),
           ttConfig.sig_roi_hi().row());
    printf("\tsb roi (x,y): (%u,%u), (%u,%u)\n",
           ttConfig.sb_roi_lo().column(),
           ttConfig.sb_roi_hi().column(),
           ttConfig.sb_roi_lo().row(),
           ttConfig.sb_roi_hi().row());
    printf("\tsb_convergence: %g\n", ttConfig.sb_convergence());
    printf("\tref roi (x,y): (%u,%u), (%u,%u)\n",
           ttConfig.ref_roi_lo().column(),
           ttConfig.ref_roi_hi().column(),
           ttConfig.ref_roi_lo().row(),  
           ttConfig.ref_roi_hi().row());
    printf("\tref_convergence: %g\n", ttConfig.ref_convergence());
    ndarray<const TimeTool::EventLogic, 1> beam_logic = ttConfig.beam_logic();
    printf("\tbeam_logic:\n");
    for (unsigned i=0; i<ttConfig.number_of_beam_event_codes(); i++) {
      const char* logic_op;
      switch (beam_logic[i].logic_op()) {
        case TimeTool::EventLogic::L_OR:
          logic_op = "OR";
          break;
        case TimeTool::EventLogic::L_AND:
          logic_op = "AND";
          break;
        case TimeTool::EventLogic::L_OR_NOT:
          logic_op = "OR NOT";
          break;
        case TimeTool::EventLogic::L_AND_NOT:
          logic_op = "L_AND_NOT";
          break;
        default:
          logic_op = "Unknown";
          break;
      }
      printf("\t\t%s %u\n", logic_op, beam_logic[i].event_code());
    }
    ndarray<const TimeTool::EventLogic, 1> laser_logic = ttConfig.laser_logic();
    printf("\tlaser_logic:\n");
    for (unsigned i=0; i<ttConfig.number_of_laser_event_codes(); i++) {
      const char* logic_op;
      switch (laser_logic[i].logic_op()) {
        case TimeTool::EventLogic::L_OR:
          logic_op = "OR";
          break;
        case TimeTool::EventLogic::L_AND:
          logic_op = "AND";
          break;
        case TimeTool::EventLogic::L_OR_NOT:
          logic_op = "OR NOT";
          break;
        case TimeTool::EventLogic::L_AND_NOT:
          logic_op = "L_AND_NOT";
          break;
        default:
          logic_op = "Unknown";
          break;
      }
      printf("\t\t%s %u\n", logic_op, laser_logic[i].event_code());
    }
    ndarray<const double, 1> weights = ttConfig.weights();
    printf("\tweights:");
    for (unsigned i=0; i<ttConfig.number_of_weights(); i++) {
      if (i%5 == 0)
        printf("\n\t\t%g", weights[i]);
      else
        printf(", %g", weights[i]);
    }
    printf("\n");
    ndarray<const double, 1> calib_poly = ttConfig.calib_poly();
    printf("\tcalib_poly:");
    for (unsigned i=0; i<ttConfig.calib_poly_dim(); i++) {
      if (i%5 == 0)
        printf("\n\t\t%g", calib_poly[i]);
      else
        printf(", %g", calib_poly[i]);
    }
    printf("\n");
    printf("\tbase_name: %s\n", ttConfig.base_name());
    printf("\tsignal_projection_size: %u\n", ttConfig.signal_projection_size());
    printf("\tsideband_projection_size: %u\n", ttConfig.sideband_projection_size());
    printf("\treference_projection_size: %u\n", ttConfig.reference_projection_size());
  }
  void process(const DetInfo &, const TimeTool::ConfigV3 &ttConfig)
  {
    printf("*** Processing TimeTool::ConfigV3 object\n");
    const char* project_axis;
    switch (ttConfig.project_axis()) {
    case TimeTool::ConfigV3::X:
      project_axis = "X";
      break;
    case TimeTool::ConfigV3::Y:
      project_axis = "Y";
      break;
    default:
      project_axis = "Unknown";
      break;
    }
    printf("\tproject_axis: %s\n", project_axis);
    printf("\tuse_full_roi: %u\n", ttConfig.use_full_roi());
    printf("\tuse_fit: %u\n", ttConfig.use_fit());
    printf("\twrite_image: %u\n", ttConfig.write_image());
    printf("\twrite_projections: %u\n", ttConfig.write_projections());
    printf("\tsubtract_sideband: %u\n", ttConfig.subtract_sideband());
    printf("\tuse_reference_roi: %u\n", ttConfig.use_reference_roi());
    printf("\tnumber_of_weights: %u\n", ttConfig.number_of_weights());
    printf("\tcalib_poly_dim: %u\n", ttConfig.calib_poly_dim());
    printf("\tfit_params_dim: %u\n", ttConfig.fit_params_dim());
    printf("\tbase_name_length: %u\n", ttConfig.base_name_length());
    printf("\tnumber_of_beam_event_codes: %u\n", ttConfig.number_of_beam_event_codes());
    printf("\tnumber_of_laser_event_codes: %u\n", ttConfig.number_of_laser_event_codes());
    printf("\tsignal_cut: %u\n", ttConfig.signal_cut());
    printf("\tfit_max_iterations: %u\n", ttConfig.fit_max_iterations());
    printf("\tfit_weights_factor: %g\n", ttConfig.fit_weights_factor());
    printf("\tsignal roi (x,y): (%u,%u), (%u,%u)\n",
           ttConfig.sig_roi_lo().column(),
           ttConfig.sig_roi_hi().column(),
           ttConfig.sig_roi_lo().row(),
           ttConfig.sig_roi_hi().row());
    printf("\tsb roi (x,y): (%u,%u), (%u,%u)\n",
           ttConfig.sb_roi_lo().column(),
           ttConfig.sb_roi_hi().column(),
           ttConfig.sb_roi_lo().row(),
           ttConfig.sb_roi_hi().row());
    printf("\tsb_convergence: %g\n", ttConfig.sb_convergence());
    printf("\tref roi (x,y): (%u,%u), (%u,%u)\n",
           ttConfig.ref_roi_lo().column(),
           ttConfig.ref_roi_hi().column(),
           ttConfig.ref_roi_lo().row(),  
           ttConfig.ref_roi_hi().row());
    printf("\tref_convergence: %g\n", ttConfig.ref_convergence());
    ndarray<const TimeTool::EventLogic, 1> beam_logic = ttConfig.beam_logic();
    printf("\tbeam_logic:\n");
    for (unsigned i=0; i<ttConfig.number_of_beam_event_codes(); i++) {
      const char* logic_op;
      switch (beam_logic[i].logic_op()) {
        case TimeTool::EventLogic::L_OR:
          logic_op = "OR";
          break;
        case TimeTool::EventLogic::L_AND:
          logic_op = "AND";
          break;
        case TimeTool::EventLogic::L_OR_NOT:
          logic_op = "OR NOT";
          break;
        case TimeTool::EventLogic::L_AND_NOT:
          logic_op = "L_AND_NOT";
          break;
        default:
          logic_op = "Unknown";
          break;
      }
      printf("\t\t%s %u\n", logic_op, beam_logic[i].event_code());
    }
    ndarray<const TimeTool::EventLogic, 1> laser_logic = ttConfig.laser_logic();
    printf("\tlaser_logic:\n");
    for (unsigned i=0; i<ttConfig.number_of_laser_event_codes(); i++) {
      const char* logic_op;
      switch (laser_logic[i].logic_op()) {
        case TimeTool::EventLogic::L_OR:
          logic_op = "OR";
          break;
        case TimeTool::EventLogic::L_AND:
          logic_op = "AND";
          break;
        case TimeTool::EventLogic::L_OR_NOT:
          logic_op = "OR NOT";
          break;
        case TimeTool::EventLogic::L_AND_NOT:
          logic_op = "L_AND_NOT";
          break;
        default:
          logic_op = "Unknown";
          break;
      }
      printf("\t\t%s %u\n", logic_op, laser_logic[i].event_code());
    }
    ndarray<const double, 1> weights = ttConfig.weights();
    printf("\tweights:");
    for (unsigned i=0; i<ttConfig.number_of_weights(); i++) {
      if (i%5 == 0)
        printf("\n\t\t%g", weights[i]);
      else
        printf(", %g", weights[i]);
    }
    printf("\n");
    ndarray<const double, 1> calib_poly = ttConfig.calib_poly();
    printf("\tcalib_poly:");
    for (unsigned i=0; i<ttConfig.calib_poly_dim(); i++) {
      if (i%5 == 0)
        printf("\n\t\t%g", calib_poly[i]);
      else
        printf(", %g", calib_poly[i]);
    }
    printf("\n");
    ndarray<const double, 1> fit_params = ttConfig.fit_params();
    printf("\tfit_params:");
    for (unsigned i=0; i<ttConfig.fit_params_dim(); i++) {
      if (i%5 == 0)
        printf("\n\t\t%g", fit_params[i]);
      else
        printf(", %g", fit_params[i]);
    }
    printf("\n");
    printf("\tbase_name: %s\n", ttConfig.base_name());
    printf("\tsignal_projection_size: %u\n", ttConfig.signal_projection_size());
    printf("\tsideband_projection_size: %u\n", ttConfig.sideband_projection_size());
    printf("\treference_projection_size: %u\n", ttConfig.reference_projection_size());
    printf("\tsignal_x_size: %u\n", ttConfig.signal_x_size());
    printf("\tsignal_y_size: %u\n", ttConfig.signal_y_size());
    printf("\tsignal_size: %u\n", ttConfig.signal_size());
    printf("\tsideband_x_size: %u\n", ttConfig.sideband_x_size());
    printf("\tsideband_y_size: %u\n", ttConfig.sideband_y_size());
    printf("\tsideband_size: %u\n", ttConfig.sideband_size());
    printf("\treference_x_size: %u\n", ttConfig.reference_x_size());
    printf("\treference_y_size: %u\n", ttConfig.reference_y_size());
    printf("\treference_size: %u\n", ttConfig.reference_size());
  }
  void process(const DetInfo &, const TimeTool::DataV1 &ttData)
  {
    printf("*** Processing TimeTool::DataV1 object\n");
    const char* event_type;
    switch (ttData.event_type()) {
      case TimeTool::DataV1::Dark:
        event_type = "Dark";
        break;
      case TimeTool::DataV1::Reference:
        event_type = "Reference";
        break;
      case TimeTool::DataV1::Signal:
        event_type = "Reference";
        break;
      default:
        event_type = "Unknown";
        break;
    }
    printf("\tevent type: %s\n", event_type);

  }
  void process(const DetInfo &, const TimeTool::DataV2 &ttData)
  {
    printf("*** Processing TimeTool::DataV2 object\n");
    const char* event_type;
    switch (ttData.event_type()) {
      case TimeTool::DataV2::Dark:
        event_type = "Dark";
        break;
      case TimeTool::DataV2::Reference:
        event_type = "Reference";
        break;
      case TimeTool::DataV2::Signal:
        event_type = "Reference";
        break;
      default:
        event_type = "Unknown";
        break;
    }
    printf("\tevent type: %s\n", event_type);
  }
  void process(const DetInfo &, const TimeTool::DataV3 &ttData)
  {
    printf("*** Processing TimeTool::DataV3 object\n");
    const char* event_type;
    switch (ttData.event_type()) {
      case TimeTool::DataV3::Dark:
        event_type = "Dark";
        break;
      case TimeTool::DataV3::Reference:
        event_type = "Reference";
        break;
      case TimeTool::DataV3::Signal:
        event_type = "Reference";
        break;
      default:
        event_type = "Unknown";
        break;
    }
    printf("\tevent type: %s\n", event_type);
  }
  void process(const DetInfo &, const Jungfrau::ConfigV1 &jungfrauConfig)
  {
    printf("*** Processing Jungfrau::ConfigV1 object\n");
    printf("\tnumber of modules: %d\n", jungfrauConfig.numberOfModules());
    printf("\tspeedMode: ");
    switch (jungfrauConfig.speedMode()) {
      case Jungfrau::ConfigV1::Quarter: printf("Quarter"); break;
      case Jungfrau::ConfigV1::Half: printf("Half"); break;
      default: printf("Unrecognized (%d)", (int)jungfrauConfig.speedMode()); break;
    }
    printf("\n");
    printf("\tgainMode: ");
    switch (jungfrauConfig.gainMode()) {
      case Jungfrau::ConfigV1::Normal: printf("Normal"); break;
      case Jungfrau::ConfigV1::FixedGain1: printf("FixedGain1"); break;
      case Jungfrau::ConfigV1::FixedGain2: printf("FixedGain2"); break;
      case Jungfrau::ConfigV1::ForcedGain1: printf("ForcedGain1"); break;
      case Jungfrau::ConfigV1::ForcedGain2: printf("ForcedGain2"); break;
      case Jungfrau::ConfigV1::HighGain0: printf("HighGain0"); break;
      default: printf("Unrecognized (%d)", (int)jungfrauConfig.gainMode()); break;
    }
    printf("\n");
    printf("\tframe size: %d\n", jungfrauConfig.frameSize());
  }
  void process(const DetInfo &, const Jungfrau::ConfigV2 &jungfrauConfig)
  {
    printf("*** Processing Jungfrau::ConfigV2 object\n");
    printf("\tnumber of modules: %d\n", jungfrauConfig.numberOfModules());
    printf("\tspeedMode: ");
    switch (jungfrauConfig.speedMode()) {
      case Jungfrau::ConfigV2::Quarter: printf("Quarter"); break;
      case Jungfrau::ConfigV2::Half: printf("Half"); break;
      default: printf("Unrecognized (%d)", (int)jungfrauConfig.speedMode()); break;
    }
    printf("\n");
    printf("\tgainMode: ");
    switch (jungfrauConfig.gainMode()) {
      case Jungfrau::ConfigV2::Normal: printf("Normal"); break;
      case Jungfrau::ConfigV2::FixedGain1: printf("FixedGain1"); break;
      case Jungfrau::ConfigV2::FixedGain2: printf("FixedGain2"); break;
      case Jungfrau::ConfigV2::ForcedGain1: printf("ForcedGain1"); break;
      case Jungfrau::ConfigV2::ForcedGain2: printf("ForcedGain2"); break;
      case Jungfrau::ConfigV2::HighGain0: printf("HighGain0"); break;
      default: printf("Unrecognized (%d)", (int)jungfrauConfig.gainMode()); break;
    }
    printf("\n");
    printf("\tframe size: %d\n", jungfrauConfig.frameSize());
  }
  void process(const DetInfo &, const Jungfrau::ConfigV3 &jungfrauConfig)
  {
    printf("*** Processing Jungfrau::ConfigV3 object\n");
    printf("\tnumber of modules: %d\n", jungfrauConfig.numberOfModules());
    for (unsigned n=0; n<jungfrauConfig.numberOfModules(); n++) {
      printf("\tmodule %u:\n", n);
      const Jungfrau::ModuleConfigV1& modConfig = jungfrauConfig.moduleConfig(n);
      printf("\t\tserial number: %#" PRIx64 "\n", modConfig.serialNumber());
      printf("\t\tsoftware version: %#" PRIx64 "\n", modConfig.moduleVersion());
      printf("\t\tfirmware version: %#" PRIx64 "\n", modConfig.firmwareVersion());
    }
    printf("\tspeedMode: ");
    switch (jungfrauConfig.speedMode()) {
      case Jungfrau::ConfigV3::Quarter: printf("Quarter"); break;
      case Jungfrau::ConfigV3::Half: printf("Half"); break;
      default: printf("Unrecognized (%d)", (int)jungfrauConfig.speedMode()); break;
    }
    printf("\n");
    printf("\tgainMode: ");
    switch (jungfrauConfig.gainMode()) {
      case Jungfrau::ConfigV3::Normal: printf("Normal"); break;
      case Jungfrau::ConfigV3::FixedGain1: printf("FixedGain1"); break;
      case Jungfrau::ConfigV3::FixedGain2: printf("FixedGain2"); break;
      case Jungfrau::ConfigV3::ForcedGain1: printf("ForcedGain1"); break;
      case Jungfrau::ConfigV3::ForcedGain2: printf("ForcedGain2"); break;
      case Jungfrau::ConfigV3::HighGain0: printf("HighGain0"); break;
      default: printf("Unrecognized (%d)", (int)jungfrauConfig.gainMode()); break;
    }
    printf("\n");
    printf("\tframe size: %d\n", jungfrauConfig.frameSize());
  }
  void process(const DetInfo &, const Jungfrau::ConfigV4 &jungfrauConfig)
  {
    printf("*** Processing Jungfrau::ConfigV4 object\n");
    printf("\tnumber of modules: %d\n", jungfrauConfig.numberOfModules());
    for (unsigned n=0; n<jungfrauConfig.numberOfModules(); n++) {
      printf("\tmodule %u:\n", n);
      const Jungfrau::ModuleConfigV1& modConfig = jungfrauConfig.moduleConfig(n);
      printf("\t\tserial number: %#" PRIx64 "\n", modConfig.serialNumber());
      printf("\t\tsoftware version: %#" PRIx64 "\n", modConfig.moduleVersion());
      printf("\t\tfirmware version: %#" PRIx64 "\n", modConfig.firmwareVersion());
    }
    printf("\tspeedMode: ");
    switch (jungfrauConfig.speedMode()) {
      case Jungfrau::ConfigV4::Quarter: printf("Quarter"); break;
      case Jungfrau::ConfigV4::Half: printf("Half"); break;
      default: printf("Unrecognized (%d)", (int)jungfrauConfig.speedMode()); break;
    }
    printf("\n");
    printf("\tgainMode: ");
    switch (jungfrauConfig.gainMode()) {
      case Jungfrau::ConfigV4::Normal: printf("Normal"); break;
      case Jungfrau::ConfigV4::FixedGain1: printf("FixedGain1"); break;
      case Jungfrau::ConfigV4::FixedGain2: printf("FixedGain2"); break;
      case Jungfrau::ConfigV4::ForcedGain1: printf("ForcedGain1"); break;
      case Jungfrau::ConfigV4::ForcedGain2: printf("ForcedGain2"); break;
      case Jungfrau::ConfigV4::HighGain0: printf("HighGain0"); break;
      default: printf("Unrecognized (%d)", (int)jungfrauConfig.gainMode()); break;
    }
    printf("\n");
    printf("\tframe size: %d\n", jungfrauConfig.frameSize());
  }
  void process(const DetInfo &, const Jungfrau::ElementV1 &)
  {
    printf("*** Processing Jungfrau::ElementV1 object\n");
  }
  void process(const DetInfo &, const Jungfrau::ElementV2 &)
  {
    printf("*** Processing Jungfrau::ElementV2 object\n");
  }
  void process(const DetInfo &, const Epix::Config100aV1 &epixConfig)
  {
    printf("*** Processing Epix::Config100aV1 object\n");
    printf("\tversion: %#x\n", epixConfig.version());
    printf("\tdigitalCardId0: 0x%x\n", epixConfig.digitalCardId0());
    printf("\tdigitalCardId1: 0x%x\n", epixConfig.digitalCardId1());
    printf("\tanalogCardId0: 0x%x\n", epixConfig.analogCardId0());
    printf("\tanalogCardId1: 0x%x\n", epixConfig.analogCardId1());
    //printf("\tcarrierId0: 0x%x\n", epixConfig.carrierId0());
    //printf("\tcarrierId1: 0x%x\n", epixConfig.carrierId1());
    printf("\tnumber of asics: %u\n", epixConfig.numberOfAsics());
    ndarray<const uint16_t, 2> apc = epixConfig.asicPixelConfigArray();
    unsigned count = 0;
    unsigned apc_avg = 0;
    uint16_t apc_min=0, apc_max=0;
    for (unsigned r=0; r<apc.shape()[0]; r++) {
      for (unsigned c=0; c<apc.shape()[1]; c++) {
        uint16_t val = apc(r,c);
        if (count == 0) {
          apc_min = apc_max = val;
        } else if (val < apc_min) {
          apc_min = val;
        } else if (val > apc_max) {
          apc_max = val;
        }
        apc_avg += val;
        count++;
      }
    }
    printf("\t\tnumber of rows: %u\n", epixConfig.numberOfRows());
    printf("\t\tnumber of columns: %u\n", epixConfig.numberOfColumns());
    printf("\t\tasicPixelConfigArray (avg, min, max): %g, %u, %u\n",
           (double) apc_avg / count, apc_min, apc_max);
  }
  void process(const DetInfo &, const Epix::Config100aV2 &epixConfig)
  {
    printf("*** Processing Epix::Config100aV2 object\n");
    printf("\tversion: %#x\n", epixConfig.version());
    printf("\tdigitalCardId0: 0x%x\n", epixConfig.digitalCardId0());
    printf("\tdigitalCardId1: 0x%x\n", epixConfig.digitalCardId1());
    printf("\tanalogCardId0: 0x%x\n", epixConfig.analogCardId0());
    printf("\tanalogCardId1: 0x%x\n", epixConfig.analogCardId1());
    printf("\tcarrierId0: 0x%x\n", epixConfig.carrierId0());
    printf("\tcarrierId1: 0x%x\n", epixConfig.carrierId1());
    printf("\tnumber of asics: %u\n", epixConfig.numberOfAsics());
    ndarray<const uint16_t, 2> apc = epixConfig.asicPixelConfigArray();
    unsigned count = 0;
    unsigned apc_avg = 0;
    uint16_t apc_min=0, apc_max=0;
    for (unsigned r=0; r<apc.shape()[0]; r++) {
      for (unsigned c=0; c<apc.shape()[1]; c++) {
        uint16_t val = apc(r,c);
        if (count == 0) {
          apc_min = apc_max = val;
        } else if (val < apc_min) {
          apc_min = val;
        } else if (val > apc_max) {
          apc_max = val;
        }
        apc_avg += val;
        count++;
      }
    }
    printf("\t\tnumber of rows: %u\n", epixConfig.numberOfRows());
    printf("\t\tnumber of columns: %u\n", epixConfig.numberOfColumns());
    printf("\t\tasicPixelConfigArray (avg, min, max): %g, %u, %u\n",
           (double) apc_avg / count, apc_min, apc_max);
  }
  void process(const DetInfo &, const Epix::Config10kaV1 &epixConfig)
  {
    printf("*** Processing Epix::Config10kaV1 object\n");
    printf("\tversion: %#x\n", epixConfig.version());
    printf("\tdigitalCardId0: 0x%x\n", epixConfig.digitalCardId0());
    printf("\tdigitalCardId1: 0x%x\n", epixConfig.digitalCardId1());
    printf("\tanalogCardId0: 0x%x\n", epixConfig.analogCardId0());
    printf("\tanalogCardId1: 0x%x\n", epixConfig.analogCardId1());
    printf("\tcarrierId0: 0x%x\n", epixConfig.carrierId0());
    printf("\tcarrierId1: 0x%x\n", epixConfig.carrierId1());
    printf("\tnumber of asics: %u\n", epixConfig.numberOfAsics());
    ndarray<const uint16_t, 2> apc = epixConfig.asicPixelConfigArray();
    unsigned count = 0;
    unsigned apc_avg = 0;
    uint16_t apc_min=0, apc_max=0;
    for (unsigned r=0; r<apc.shape()[0]; r++) {
      for (unsigned c=0; c<apc.shape()[1]; c++) {
        uint16_t val = apc(r,c);
        if (count == 0) {
          apc_min = apc_max = val;
        } else if (val < apc_min) {
          apc_min = val;
        } else if (val > apc_max) {
          apc_max = val;
        }
        apc_avg += val;
        count++;
      }
    }
    printf("\t\tnumber of rows: %u\n", epixConfig.numberOfRows());
    printf("\t\tnumber of columns: %u\n", epixConfig.numberOfColumns());
    printf("\t\tasicPixelConfigArray (avg, min, max): %g, %u, %u\n",
           (double) apc_avg / count, apc_min, apc_max);
    printf("\t\tnumber of asics: %u\n", epixConfig.numberOfAsics());
    for (unsigned a=0; a<epixConfig.numberOfAsics(); a++) {
      printf("\t\tasic %u trbit: %u\n", a, epixConfig.asics(a).trbit());
    }
  }
  void process(const DetInfo &, const Epix::Config10kaV2 &epixConfig)
  {
    printf("*** Processing Epix::Config10kaV2 object\n");
    printf("\tversion: %#x\n", epixConfig.version());
    printf("\tfirmwareHash: %s\n", epixConfig.firmwareHash());
    printf("\tfirmwareDesc: %s\n", epixConfig.firmwareDesc());
    printf("\tdigitalCardId0: 0x%x\n", epixConfig.digitalCardId0());
    printf("\tdigitalCardId1: 0x%x\n", epixConfig.digitalCardId1());
    printf("\tanalogCardId0: 0x%x\n", epixConfig.analogCardId0());
    printf("\tanalogCardId1: 0x%x\n", epixConfig.analogCardId1());
    printf("\tcarrierId0: 0x%x\n", epixConfig.carrierId0());
    printf("\tcarrierId1: 0x%x\n", epixConfig.carrierId1());
    printf("\tnumber of asics: %u\n", epixConfig.numberOfAsics());
    ndarray<const uint16_t, 2> apc = epixConfig.asicPixelConfigArray();
    unsigned count = 0;
    unsigned apc_avg = 0;
    uint16_t apc_min=0, apc_max=0;
    for (unsigned r=0; r<apc.shape()[0]; r++) {
      for (unsigned c=0; c<apc.shape()[1]; c++) {
        uint16_t val = apc(r,c);
        if (count == 0) {
          apc_min = apc_max = val;
        } else if (val < apc_min) {
          apc_min = val;
        } else if (val > apc_max) {
          apc_max = val;
        }
        apc_avg += val;
        count++;
      }
    }
    printf("\t\tnumber of rows: %u\n", epixConfig.numberOfRows());
    printf("\t\tnumber of columns: %u\n", epixConfig.numberOfColumns());
    printf("\t\tasicPixelConfigArray (avg, min, max): %g, %u, %u\n",
           (double) apc_avg / count, apc_min, apc_max);
    printf("\t\tnumber of asics: %u\n", epixConfig.numberOfAsics());
    for (unsigned a=0; a<epixConfig.numberOfAsics(); a++) {
      printf("\t\tasic %u trbit: %u\n", a, epixConfig.asics(a).trbit());
    }
  }
  void process(const DetInfo &, const Epix::Config10ka2MV1 &epixConfig)
  {
    printf("*** Processing Epix::Config10ka2MV1 object\n");
    printf("\tnumber of elements: %u\n", epixConfig.numberOfElements());
    printf("\tnumber of asics: %u\n", epixConfig.numberOfAsics());
    for (unsigned n=0; n<epixConfig.numberOfElements(); n++) {
      const Epix::Elem10kaConfigV1& elem = epixConfig.elemCfg(n);
      ndarray<const uint16_t, 2> apc = elem.asicPixelConfigArray();
      unsigned count = 0;
      unsigned apc_avg = 0;
      uint16_t apc_min=0, apc_max=0;
      for (unsigned r=0; r<apc.shape()[0]; r++) {
        for (unsigned c=0; c<apc.shape()[1]; c++) {
          uint16_t val = apc(r,c);
          if (count == 0) {
            apc_min = apc_max = val;
          } else if (val < apc_min) {
            apc_min = val;
          } else if (val > apc_max) {
            apc_max = val;
          }
          apc_avg += val;
          count++;
        }
      }
      printf("\telement %u:\n", n);
      printf("\t\tnumber of rows: %u\n", elem.numberOfRows());
      printf("\t\tnumber of columns: %u\n", elem.numberOfColumns());
      printf("\t\tasicPixelConfigArray (avg, min, max): %g, %u, %u\n",
             (double) apc_avg / count, apc_min, apc_max);
      printf("\t\tnumber of asics: %u\n", elem.numberOfAsics());
      for (unsigned a=0; a<elem.numberOfAsics(); a++) {
        printf("\t\tasic %u trbit: %u\n", a, elem.asics(a).trbit());
      }
    }
  }
  void process(const DetInfo &, const Epix::Config10ka2MV2 &epixConfig)
  {
    printf("*** Processing Epix::Config10ka2MV2 object\n");
    printf("\tnumber of elements: %u\n", epixConfig.numberOfElements());
    printf("\tnumber of asics: %u\n", epixConfig.numberOfAsics());
    for (unsigned n=0; n<epixConfig.numberOfElements(); n++) {
      const Epix::Elem10kaConfigV1& elem = epixConfig.elemCfg(n);
      ndarray<const uint16_t, 2> apc = elem.asicPixelConfigArray();
      unsigned count = 0;
      unsigned apc_avg = 0;
      uint16_t apc_min=0, apc_max=0;
      for (unsigned r=0; r<apc.shape()[0]; r++) {
        for (unsigned c=0; c<apc.shape()[1]; c++) {
          uint16_t val = apc(r,c);
          if (count == 0) {
            apc_min = apc_max = val;
          } else if (val < apc_min) {
            apc_min = val;
          } else if (val > apc_max) {
            apc_max = val;
          }
          apc_avg += val;
          count++;
        }
      }
      printf("\telement %u:\n", n);
      printf("\t\tnumber of rows: %u\n", elem.numberOfRows());
      printf("\t\tnumber of columns: %u\n", elem.numberOfColumns());
      printf("\t\tasicPixelConfigArray (avg, min, max): %g, %u, %u\n",
             (double) apc_avg / count, apc_min, apc_max);
      printf("\t\tnumber of asics: %u\n", elem.numberOfAsics());
      for (unsigned a=0; a<elem.numberOfAsics(); a++) {
        printf("\t\tasic %u trbit: %u\n", a, elem.asics(a).trbit());
      }
    }
  }
  void process(const DetInfo &, const Epix::ArrayV1 &)
  {
    printf("*** Processing Epix::ArrayV1 object\n");
  }
  void process(const DetInfo &, const Epix::Config10kaQuadV1 &epixConfig)
  {
    printf("*** Processing Epix::Config10kaQuadV1 object\n");
    printf("\tnumber of elements: %u\n", epixConfig.numberOfElements());
    printf("\tnumber of asics: %u\n", epixConfig.numberOfAsics());
    for (unsigned n=0; n<epixConfig.numberOfElements(); n++) {
      const Epix::Elem10kaConfigV1& elem = epixConfig.elemCfg(n);
      ndarray<const uint16_t, 2> apc = elem.asicPixelConfigArray();
      unsigned count = 0;
      unsigned apc_avg = 0;
      uint16_t apc_min=0, apc_max=0;
      for (unsigned r=0; r<apc.shape()[0]; r++) {
        for (unsigned c=0; c<apc.shape()[1]; c++) {
          uint16_t val = apc(r,c);
          if (count == 0) {
            apc_min = apc_max = val;
          } else if (val < apc_min) {
            apc_min = val;
          } else if (val > apc_max) {
            apc_max = val;
          }
          apc_avg += val;
          count++;
        }
      }
      printf("\telement %u:\n", n);
      printf("\t\tnumber of rows: %u\n", elem.numberOfRows());
      printf("\t\tnumber of columns: %u\n", elem.numberOfColumns());
      printf("\t\tasicPixelConfigArray (avg, min, max): %g, %u, %u\n",
             (double) apc_avg / count, apc_min, apc_max);
      printf("\t\tnumber of asics: %u\n", elem.numberOfAsics());
      for (unsigned a=0; a<elem.numberOfAsics(); a++) {
        printf("\t\tasic %u trbit: %u\n", a, elem.asics(a).trbit());
      }
    }
  }
  void process(const DetInfo &, const Epix::Config10kaQuadV2 &epixConfig)
  {
    printf("*** Processing Epix::Config10kaQuadV2 object\n");
    printf("\tnumber of elements: %u\n", epixConfig.numberOfElements());
    printf("\tnumber of asics: %u\n", epixConfig.numberOfAsics());
    for (unsigned n=0; n<epixConfig.numberOfElements(); n++) {
      const Epix::Elem10kaConfigV1& elem = epixConfig.elemCfg(n);
      ndarray<const uint16_t, 2> apc = elem.asicPixelConfigArray();
      unsigned count = 0;
      unsigned apc_avg = 0;
      uint16_t apc_min=0, apc_max=0;
      for (unsigned r=0; r<apc.shape()[0]; r++) {
        for (unsigned c=0; c<apc.shape()[1]; c++) {
          uint16_t val = apc(r,c);
          if (count == 0) {
            apc_min = apc_max = val;
          } else if (val < apc_min) {
            apc_min = val;
          } else if (val > apc_max) {
            apc_max = val;
          }
          apc_avg += val;
          count++;
        }
      }
      printf("\telement %u:\n", n);
      printf("\t\tnumber of rows: %u\n", elem.numberOfRows());
      printf("\t\tnumber of columns: %u\n", elem.numberOfColumns());
      printf("\t\tasicPixelConfigArray (avg, min, max): %g, %u, %u\n",
             (double) apc_avg / count, apc_min, apc_max);
      printf("\t\tnumber of asics: %u\n", elem.numberOfAsics());
      for (unsigned a=0; a<elem.numberOfAsics(); a++) {
        printf("\t\tasic %u trbit: %u\n", a, elem.asics(a).trbit());
      }
    }
  }
  void process(const DetInfo &, const Zyla::ConfigV1 &zylaConfig)
  {
    printf("*** Processing Zyla::ConfigV1 object\n");
    printf("\twidth: %u\n", zylaConfig.width());
    printf("\theight: %u\n", zylaConfig.height());
    printf("\torg x: %u\n", zylaConfig.orgX());
    printf("\torg y: %u\n", zylaConfig.orgY());
    printf("\texposure time: %g\n", zylaConfig.exposureTime());
    printf("\ttrigger delay: %g\n", zylaConfig.triggerDelay());
    printf("\tcooling on: %s\n", zylaConfig.cooling() == Zyla::ConfigV1::True ? "true" : "false");
    const char* cooling_setpoint;
    switch (zylaConfig.setpoint()) {
      case Zyla::ConfigV1::Temp_0C:
        cooling_setpoint = "0 C";
        break;
      case Zyla::ConfigV1::Temp_Neg5C:
        cooling_setpoint = "5 C";
        break;
      case Zyla::ConfigV1::Temp_Neg10C:
        cooling_setpoint = "10 C";
        break;
      case Zyla::ConfigV1::Temp_Neg15C:
        cooling_setpoint = "15 C";
        break;
      case Zyla::ConfigV1::Temp_Neg20C:
        cooling_setpoint = "20 C";
        break;
      case Zyla::ConfigV1::Temp_Neg25C:
        cooling_setpoint = "25 C";
        break;
      case Zyla::ConfigV1::Temp_Neg30C:
        cooling_setpoint = "30 C";
        break;
      case Zyla::ConfigV1::Temp_Neg35C:
        cooling_setpoint = "35 C";
        break;
      case Zyla::ConfigV1::Temp_Neg40C:
        cooling_setpoint = "40 C";
        break;
      default:
        cooling_setpoint = "Unknown";
        break;
    }
    printf("\tcooling setpoint: %s\n", cooling_setpoint);
    printf("\toverlap mode: %s\n", zylaConfig.overlap() == Zyla::ConfigV1::True ? "true" : "false");
    printf("\tnoise filter: %s\n", zylaConfig.noiseFilter() == Zyla::ConfigV1::True ? "true" : "false");
    printf("\tblemish correction: %s\n", zylaConfig.blemishCorrection() == Zyla::ConfigV1::True ? "true" : "false");
    const char* shutter;
    switch (zylaConfig.shutter()) {
      case Zyla::ConfigV1::Rolling:
        shutter = "Rolling";
        break;
      case Zyla::ConfigV1::Global:
        shutter = "Global";
        break;
      default:
        shutter = "Unknown";
        break;
    }
    printf("\tshutter mode: %s\n", shutter);
    const char* readout;
    switch (zylaConfig.readoutRate()) {
      case Zyla::ConfigV1::Rate280MHz:
        readout = "280 MHz";
        break;
      case Zyla::ConfigV1::Rate200MHz:
        readout = "200 MHz";
        break;
      case Zyla::ConfigV1::Rate100MHz:
        readout = "100 MHz";
        break;
      case Zyla::ConfigV1::Rate10MHz:
        readout = "10 MHz";
        break;
      default:
        readout = "Unknown";
        break;
    }
    printf("\treadout mode: %s\n", readout);
    const char* fanspeed;
    switch (zylaConfig.fanSpeed()) {
      case Zyla::ConfigV1::Off:
        fanspeed = "Off";
        break;
      case Zyla::ConfigV1::Low:
        fanspeed = "Low";
        break;
      case Zyla::ConfigV1::On:
        fanspeed = "On";
        break;
      default:
        fanspeed = "Unknown";
        break;
    }
    printf("\tfan speed: %s\n", fanspeed);
    const char* trigger;
    switch (zylaConfig.triggerMode()) {
      case Zyla::ConfigV1::Internal:
        trigger = "Internal";
        break;
      case Zyla::ConfigV1::ExternalLevelTransition:
        trigger = "ExternalLevelTransition";
        break;
      case Zyla::ConfigV1::ExternalStart:
        trigger = "ExternalStart";
        break;
      case Zyla::ConfigV1::ExternalExposure:
        trigger = "ExternalExposure";
        break;
      case Zyla::ConfigV1::Software:
        trigger = "Software";
        break;
      case Zyla::ConfigV1::Advanced:
        trigger = "Advanced";
        break;
      case Zyla::ConfigV1::External:
        trigger = "External";
        break;
      default:
        trigger = "Unknown";
        break;
    }
    printf("\ttrigger mode: %s\n", trigger);
    const char* gain;
    switch (zylaConfig.gainMode()) {
      case Zyla::ConfigV1::HighWellCap12Bit:
        gain = "HighWellCap12Bit";
        break;
      case Zyla::ConfigV1::LowNoise12Bit:
        gain = "LowNoise12Bit";
        break;
      case Zyla::ConfigV1::LowNoiseHighWellCap16Bit:
        gain = "LowNoiseHighWellCap16Bit";
        break;
      default:
        gain = "Unknown";
        break;
    }
    printf("\tgain mode: %s\n", gain);
    printf("\tnum pixels: %u\n", zylaConfig.numPixels());
    printf("\tframe size: %u\n", zylaConfig.frameSize());
  }
  void process(const DetInfo &, const iStar::ConfigV1 &istarConfig)
  {
    printf("*** Processing iStar::ConfigV1 object\n");
    printf("\twidth: %u\n", istarConfig.width());
    printf("\theight: %u\n", istarConfig.height());
    printf("\torg x: %u\n", istarConfig.orgX());
    printf("\torg y: %u\n", istarConfig.orgY());
    printf("\texposure time: %g\n", istarConfig.exposureTime());
    printf("\ttrigger delay: %g\n", istarConfig.triggerDelay());
    printf("\tcooling on: %s\n", istarConfig.cooling() == iStar::ConfigV1::True ? "true" : "false");
    printf("\toverlap mode: %s\n", istarConfig.overlap() == iStar::ConfigV1::True ? "true" : "false");
    printf("\tnoise filter: %s\n", istarConfig.noiseFilter() == iStar::ConfigV1::True ? "true" : "false");
    printf("\tblemish correction: %s\n", istarConfig.blemishCorrection() == iStar::ConfigV1::True ? "true" : "false");
    printf("\tmcp intelligate: %s\n", istarConfig.mcpIntelligate() == iStar::ConfigV1::True ? "true" : "false");
    const char* fanspeed;
    switch (istarConfig.fanSpeed()) {
      case iStar::ConfigV1::Off:
        fanspeed = "Off";
        break;
      case iStar::ConfigV1::On:
        fanspeed = "On";
        break;
      default:
        fanspeed = "Unknown";
        break;
    }
    printf("\tfan speed: %s\n", fanspeed);
    const char* readout;
    switch (istarConfig.readoutRate()) {
      case iStar::ConfigV1::Rate280MHz:
        readout = "280 MHz";
        break;
      case iStar::ConfigV1::Rate100MHz:
        readout = "100 MHz";
        break;
      default:
        readout = "Unknown";
        break;
    }
    printf("\treadout mode: %s\n", readout);
    const char* trigger;
    switch (istarConfig.triggerMode()) {
      case iStar::ConfigV1::Internal:
        trigger = "Internal";
        break;
      case iStar::ConfigV1::ExternalLevelTransition:
        trigger = "ExternalLevelTransition";
        break;
      case iStar::ConfigV1::ExternalStart:
        trigger = "ExternalStart";
        break;
      case iStar::ConfigV1::ExternalExposure:
        trigger = "ExternalExposure";
        break;
      case iStar::ConfigV1::Software:
        trigger = "Software";
        break;
      case iStar::ConfigV1::Advanced:
        trigger = "Advanced";
        break;
      case iStar::ConfigV1::External:
        trigger = "External";
        break;
      default:
        trigger = "Unknown";
        break;
    }
    printf("\ttrigger mode: %s\n", trigger);
    const char* gain;
    switch (istarConfig.gainMode()) {
      case iStar::ConfigV1::HighWellCap12Bit:
        gain = "HighWellCap12Bit";
        break;
      case iStar::ConfigV1::LowNoise12Bit:
        gain = "LowNoise12Bit";
        break;
      case iStar::ConfigV1::LowNoiseHighWellCap16Bit:
        gain = "LowNoiseHighWellCap16Bit";
        break;
      default:
        gain = "Unknown";
        break;
    }
    printf("\tgain mode: %s\n", gain);
    const char* gate;
    switch (istarConfig.gateMode()) {
      case iStar::ConfigV1::CWOn:
        gate = "CWOn";
        break;
      case iStar::ConfigV1::CWOff:
        gate = "CWOff";
        break;
      case iStar::ConfigV1::FireOnly:
        gate = "FireOnly";
        break;
      case iStar::ConfigV1::GateOnly:
        gate = "GateOnly";
        break;
      case iStar::ConfigV1::FireAndGate:
        gate = "FireAndGate";
        break;
      case iStar::ConfigV1::DDG:
        gate = "DDG";
        break;
      default:
        gate = "Unknown";
        break;
    }
    printf("\tgate mode: %s\n", gate);
    const char* insert;
    switch (istarConfig.insertionDelay()) {
      case iStar::ConfigV1::Normal:
        insert = "Normal";
        break;
      case iStar::ConfigV1::Fast:
        insert = "Fast";
        break;
      default:
        insert = "Unknown";
        break;
    }
    printf("\tinsertion delay: %s\n", insert);
    printf("\tmcp gain: %u\n", istarConfig.mcpGain());
    printf("\tnum pixels: %u\n", istarConfig.numPixels());
    printf("\tframe size: %u\n", istarConfig.frameSize());
  }
  void process(const DetInfo &, const Zyla::FrameV1 &zylaFrame)
  {
    printf("*** Processing Zyla::FrameV1 object\n");
    printf("\ttimestamp %" PRIu64 "\n", zylaFrame.timestamp());
  }
  void process(const DetInfo &, const Vimba::AlviumConfigV1 &alviumConfig)
  {
    printf("*** Processing Vimba::AlviumConfigV1 object\n");
    printf("\tmanufacturer: %s\n", alviumConfig.manufacturer());
    printf("\tfamily: %s\n", alviumConfig.family());
    printf("\tmodel: %s\n", alviumConfig.model());
    printf("\tmanufacturer id: %s\n", alviumConfig.manufacturerId());
    printf("\tversion: %s\n", alviumConfig.version());
    printf("\tserial number: %s\n", alviumConfig.serialNumber());
    printf("\tfirmware id: %s\n", alviumConfig.firmwareId());
    printf("\tfirmware version: %s\n", alviumConfig.firmwareVersion());
    printf("\tsensor width: %u\n", alviumConfig.sensorWidth());
    printf("\tsensor height: %u\n", alviumConfig.sensorHeight());
    printf("\troi settings:\n");
    const char* roi_mode;
    switch(alviumConfig.roiEnable()) {
      case Vimba::AlviumConfigV1::Off:
        roi_mode = "Off";
        break;
      case Vimba::AlviumConfigV1::On:
        roi_mode = "On";
        break;
      case Vimba::AlviumConfigV1::Centered:
        roi_mode = "Centered";
        break;
      default:
        roi_mode = "Uknown";
        break;
    }
    printf("\t\tmode: %s\n", roi_mode);
    printf("\t\twidth: %u\n", alviumConfig.width());
    printf("\t\theight: %u\n", alviumConfig.height());
    printf("\t\toffset x: %u\n", alviumConfig.offsetX());
    printf("\t\toffset y: %u\n", alviumConfig.offsetY());
    printf("\treverse x: %s\n", alviumConfig.reverseX() == Vimba::AlviumConfigV1::True ? "true" : "false");
    printf("\treverse y: %s\n", alviumConfig.reverseY() == Vimba::AlviumConfigV1::True ? "true" : "false");
    const char* pixel_mode;
    switch(alviumConfig.pixelMode()) {
      case Vimba::AlviumConfigV1::Mono8:
        pixel_mode = "Mono8";
        break;
      case Vimba::AlviumConfigV1::Mono10:
        pixel_mode = "Mono10";
        break;
      case Vimba::AlviumConfigV1::Mono10p:
        pixel_mode = "Mono10p";
        break;
      case Vimba::AlviumConfigV1::Mono12:
        pixel_mode = "Mono12";
        break;
      case Vimba::AlviumConfigV1::Mono12p:
        pixel_mode = "Mono12p";
        break;
      default:
        pixel_mode = "Uknown";
        break;
    }
    printf("\tpixel mode: %s\n", pixel_mode);
    const char* trig_mode;
    switch(alviumConfig.triggerMode()) {
      case Vimba::AlviumConfigV1::FreeRun:
        trig_mode = "FreeRun";
        break;
      case Vimba::AlviumConfigV1::External:
        trig_mode = "External";
        break;
      case Vimba::AlviumConfigV1::Software:
        trig_mode = "Software";
        break;
      default:
        trig_mode = "Uknown";
        break;
    }
    printf("\ttrigger mode: %s\n", trig_mode);
    printf("\texposure time: %g\n", alviumConfig.exposureTime());
    printf("\tblack level: %g\n", alviumConfig.blackLevel());
    printf("\tgain: %g\n", alviumConfig.gain());
    printf("\tgamma: %g\n", alviumConfig.gamma());
    printf("\tcontrast settings:\n");
    printf("\t\tenabled: %s\n", alviumConfig.contrastEnable() == Vimba::AlviumConfigV1::True ? "true" : "false");
    printf("\t\tdark limit: %u\n", alviumConfig.contrastDarkLimit());
    printf("\t\tbright limit: %u\n", alviumConfig.contrastBrightLimit());
    printf("\t\tshape: %u\n",  alviumConfig.contrastShape());
    printf("\tcorrection settings:\n");
    printf("\t\tenabled: %s\n", alviumConfig.correctionEnable() == Vimba::AlviumConfigV1::True ? "true" : "false");
    const char* corr_type;
    const char* corr_set;
    switch(alviumConfig.correctionType()) {
      case Vimba::AlviumConfigV1::DefectPixelCorrection:
        corr_type = "DefectPixelCorrection";
        break;
      case Vimba::AlviumConfigV1::FixedPatternNoiseCorrection:
        corr_type = "FixedPatternNoiseCorrection";
        break;
      default:
        corr_type = "Uknown";
        break;
    }
    switch(alviumConfig.correctionSet()) {
      case Vimba::AlviumConfigV1::Preset:
        corr_set = "Preset";
        break;
      case Vimba::AlviumConfigV1::User:
        corr_set = "User";
        break;
      default:
        corr_set = "Uknown";
        break;
    }
    printf("\t\ttype: %s\n", corr_type);
    printf("\t\tset: %s\n", corr_set); 
    printf("\tbit depth: %u\n", alviumConfig.depth());
    printf("\tnum pixels: %u\n", alviumConfig.numPixels());
    printf("\tframe size: %u\n", alviumConfig.frameSize());
  }
  void process(const DetInfo &, const Vimba::FrameV1 &vimbaFrame)
  {
    printf("*** Processing Vimba::FrameV1 object\n");
    printf("\tframeid: %" PRIu64 "\n", vimbaFrame.frameid());
    printf("\ttimestamp: %" PRIu64 "\n", vimbaFrame.timestamp());
  }
  void process(const DetInfo &, const Uxi::ConfigV1 &uxiConfig)
  {
    printf("*** Processing Uxi::ConfigV1 object\n");
    printf("\twidth: %u\n", uxiConfig.width());
    printf("\theight: %u\n", uxiConfig.height());
    printf("\tnframes: %u\n", uxiConfig.numberOfFrames());
    printf("\tbytes: %u\n", uxiConfig.numberOFBytesPerPixel());
    printf("\tsensor: %u\n", uxiConfig.sensorType());
    printf("\ttime on:\n");
    ndarray<const uint32_t, 1> timeOn = uxiConfig.timeOn();
    for (unsigned i=0; i<Uxi::ConfigV1::NumberOfSides; i++) {
      printf("\t\tside %u: %u ns\n", i, timeOn[i]);
    }
    printf("\ttime off:\n");
    ndarray<const uint32_t, 1> timeOff = uxiConfig.timeOff();
    for (unsigned i=0; i<Uxi::ConfigV1::NumberOfSides; i++) {
      printf("\t\tside %u: %u ns\n", i, timeOff[i]);
    }
    printf("\tdelay:\n");
    ndarray<const uint32_t, 1> delay = uxiConfig.delay();
    for (unsigned i=0; i<Uxi::ConfigV1::NumberOfSides; i++) {
      printf("\t\tside %u: %u ns\n", i, delay[i]);
    }
    printf("\tpots:\n");
    ndarray<const double, 1> pots = uxiConfig.pots();
    for (unsigned i=0; i<Uxi::ConfigV1::NumberOfPots; i++) {
      printf("\t\tpot %u (readonly, tuned, value): %s, %s, %g\n",
             i,
             uxiConfig.potIsReadOnly((uint8_t) i) ? "true" : "false",
             uxiConfig.potIsTuned((uint8_t) i) ? "true" : "false",
             pots[i]);
    }
    printf("\tnpixels per frame: %u\n", uxiConfig.numPixelsPerFrame());
    printf("\tnpixels total: %u\n", uxiConfig.numPixels());
    printf("\tframe size: %u\n", uxiConfig.frameSize());
  }
  void process(const DetInfo &, const Uxi::ConfigV2 &uxiConfig)
  {
    printf("*** Processing Uxi::ConfigV2 object\n");
    printf("\troi: %s\n", uxiConfig.roiEnable() ? "on" : "off");
    if (uxiConfig.roiEnable()) {
      const Uxi::RoiCoord& roirows = uxiConfig.roiRows();
      printf("\t\trows (first last): %u, %u\n", roirows.first(), roirows.last());
      const Uxi::RoiCoord& roiframes = uxiConfig.roiFrames();
      printf("\t\tframe (first last): %u, %u\n", roiframes.first(), roiframes.last());
    }
    printf("\twidth: %u\n", uxiConfig.width());
    printf("\theight: %u\n", uxiConfig.height());
    printf("\tnframes: %u\n", uxiConfig.numberOfFrames());
    printf("\tbytes: %u\n", uxiConfig.numberOFBytesPerPixel());
    printf("\tsensor: %u\n", uxiConfig.sensorType());
    printf("\ttime on:\n");
    ndarray<const uint32_t, 1> timeOn = uxiConfig.timeOn();
    for (unsigned i=0; i<Uxi::ConfigV2::NumberOfSides; i++) {
      printf("\t\tside %u: %u ns\n", i, timeOn[i]);
    }
    printf("\ttime off:\n");
    ndarray<const uint32_t, 1> timeOff = uxiConfig.timeOff();
    for (unsigned i=0; i<Uxi::ConfigV2::NumberOfSides; i++) {
      printf("\t\tside %u: %u ns\n", i, timeOff[i]);
    }
    printf("\tdelay:\n");
    ndarray<const uint32_t, 1> delay = uxiConfig.delay();
    for (unsigned i=0; i<Uxi::ConfigV2::NumberOfSides; i++) {
      printf("\t\tside %u: %u ns\n", i, delay[i]);
    }
    printf("\tpots:\n");
    ndarray<const double, 1> pots = uxiConfig.pots();
    for (unsigned i=0; i<Uxi::ConfigV2::NumberOfPots; i++) {
      printf("\t\tpot %u (readonly, tuned, value): %s, %s, %g\n",
             i,
             uxiConfig.potIsReadOnly((uint8_t) i) ? "true" : "false",
             uxiConfig.potIsTuned((uint8_t) i) ? "true" : "false",
             pots[i]);
    }
    printf("\tnpixels per frame: %u\n", uxiConfig.numPixelsPerFrame());
    printf("\tnpixels total: %u\n", uxiConfig.numPixels());
    printf("\tframe size: %u\n", uxiConfig.frameSize());

  }
  void process(const DetInfo &, const Uxi::ConfigV3 &uxiConfig)
  {
    printf("*** Processing Uxi::ConfigV3 object\n");
    printf("\troi: %s\n", uxiConfig.roiEnable() ? "on" : "off");
    if (uxiConfig.roiEnable()) {
      const Uxi::RoiCoord& roirows = uxiConfig.roiRows();
      printf("\t\trows (first last): %u, %u\n", roirows.first(), roirows.last());
      const Uxi::RoiCoord& roiframes = uxiConfig.roiFrames();
      printf("\t\tframe (first last): %u, %u\n", roiframes.first(), roiframes.last());
    }
    printf("\toscillator mode: ");
    switch (uxiConfig.oscillator()) {
      case Uxi::ConfigV3::RelaxationOsc:
        printf("RelaxationOsc");
        break;
      case Uxi::ConfigV3::RingOscWithCaps:
        printf("RingOscWithCaps");
        break;
      case Uxi::ConfigV3::RingOscNoCaps:
        printf("RingOscNoCaps");
        break;
      case Uxi::ConfigV3::ExternalClock:
        printf("ExternalClock");
        break;
      default:
        printf("Unrecognized (%d)", (int)uxiConfig.oscillator());
        break;
    }
    printf("\n");
    printf("\twidth: %u\n", uxiConfig.width());
    printf("\theight: %u\n", uxiConfig.height());
    printf("\tnframes: %u\n", uxiConfig.numberOfFrames());
    printf("\tbytes: %u\n", uxiConfig.numberOFBytesPerPixel());
    printf("\tsensor: %u\n", uxiConfig.sensorType());
    printf("\ttime on:\n");
    ndarray<const uint32_t, 1> timeOn = uxiConfig.timeOn();
    for (unsigned i=0; i<Uxi::ConfigV3::NumberOfSides; i++) {
      printf("\t\tside %u: %u ns\n", i, timeOn[i]);
    }
    printf("\ttime off:\n");
    ndarray<const uint32_t, 1> timeOff = uxiConfig.timeOff();
    for (unsigned i=0; i<Uxi::ConfigV3::NumberOfSides; i++) {
      printf("\t\tside %u: %u ns\n", i, timeOff[i]);
    }
    printf("\tdelay:\n");
    ndarray<const uint32_t, 1> delay = uxiConfig.delay();
    for (unsigned i=0; i<Uxi::ConfigV3::NumberOfSides; i++) {
      printf("\t\tside %u: %u ns\n", i, delay[i]);
    }
    printf("\tpots:\n");
    ndarray<const double, 1> pots = uxiConfig.pots();
    for (unsigned i=0; i<Uxi::ConfigV3::NumberOfPots; i++) {
      printf("\t\tpot %u (readonly, tuned, value): %s, %s, %g\n",
             i,
             uxiConfig.potIsReadOnly((uint8_t) i) ? "true" : "false",
             uxiConfig.potIsTuned((uint8_t) i) ? "true" : "false",
             pots[i]);
    }
    printf("\tnpixels per frame: %u\n", uxiConfig.numPixelsPerFrame());
    printf("\tnpixels total: %u\n", uxiConfig.numPixels());
    printf("\tframe size: %u\n", uxiConfig.frameSize());

  }
  void process(const DetInfo &, const Uxi::FrameV1 &uxiFrame)
  {
    printf("*** Processing Uxi::FrameV1 object\n");
    printf("\tframeid: %u\n", uxiFrame.acquisitionCount());
    printf("\ttimestamp: %u\n", uxiFrame.timestamp());
    printf("\ttemperature: %g\n", uxiFrame.temperature());
  }
  int process(Xtc* xtc) {
    unsigned      i         =_depth; while (i--) printf("  ");
    Level::Type   level     = xtc->src.level();
    printf("%s level  offset %Ld (0x%Lx), payload size %d contains %s damage 0x%x: ",
           Level::name(level), _lliOffset, _lliOffset, xtc->sizeofPayload(), TypeId::name(xtc->contains.id()),
           xtc->damage.value());
    long long lliOffsetPayload = _lliOffset + sizeof(Xtc);
    _lliOffset += sizeof(Xtc) + xtc->sizeofPayload();
     
    const DetInfo& info = *(DetInfo*)(&xtc->src);
    if (level==Level::Source) {
      map<Src,string>::iterator it = aliasMap.find(xtc->src);
      if (it != aliasMap.end()) {
        printf("%s (%s,%d  %s,%d)\n", it->second.c_str(),
               DetInfo::name(info.detector()),info.detId(),
               DetInfo::name(info.device()),info.devId());
      } else {
        printf("%s,%d  %s,%d\n",
               DetInfo::name(info.detector()),info.detId(),
               DetInfo::name(info.device()),info.devId());
      }
    } else {
      ProcInfo& info = *(ProcInfo*)(&xtc->src);
      printf("IpAddress 0x%x ProcessId 0x%x\n",info.ipAddr(),info.processId());
    }
    if (level < 0 || level >= Level::NumberOfLevels )
    {
        printf("Unsupported Level %d\n", (int) level);
        return Continue;
    }    
    switch (xtc->contains.id()) {
    case (TypeId::Id_Xtc) : {
      myLevelIter iter(xtc,_depth+1, lliOffsetPayload);
      iter.iterate();
      break;
    }
    case (TypeId::Id_Frame) :
      process(info, *(const Camera::FrameV1*)(xtc->payload()));
      break;
    case (TypeId::Id_AcqWaveform) :
      process(info, *(const Acqiris::DataDescV1*)(xtc->payload()));
      break;
    case (TypeId::Id_AcqConfig) :
    {      
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info,*(const Acqiris::ConfigV1*)(xtc->payload()));
        break;
      default:
        printf("Unsupported acqiris configuration version %d\n",version);
        break;
      }
      break;      
    }
    case (TypeId::Id_AcqTdcConfig) :
      process(info, *(const Acqiris::TdcConfigV1*)(xtc->payload()));
      break;
    case (TypeId::Id_AcqTdcData) :
      // TdcDataV1 need extra info (XTC size) to get the number of items in it
      process(info, *(const Acqiris::TdcDataV1*)(xtc->payload()), xtc->sizeofPayload());
      break;
    case (TypeId::Id_IpimbData) :
      {
	unsigned version = xtc->contains.version();
	switch (version) {
	case 1:
	  process(info, *(const Ipimb::DataV1*)(xtc->payload()));
	  break;
	case 2:
	  process(info, *(const Ipimb::DataV2*)(xtc->payload()));
	  break;
	default:
	  printf("Unsupported ipimb configuration version %d\n",version);
	  break;
	}
      }
      break;
    case (TypeId::Id_IpimbConfig) :
    {      
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info,*(const Ipimb::ConfigV1*)(xtc->payload()));
        break;
      case 2:
        process(info,*(const Ipimb::ConfigV2*)(xtc->payload()));
        break;
      default:
        printf("Unsupported ipimb configuration version %d\n",version);
        break;
      }
      break;      
    }
    case (TypeId::Id_EncoderData) :
    {      
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info,*(const Encoder::DataV1*)(xtc->payload()));
        break;
      case 2:
        process(info,*(const Encoder::DataV2*)(xtc->payload()));
        break;
      default:
        printf("Unsupported encoder data version %d\n",version);
        break;
      }
      break;      
    }
    case (TypeId::Id_EncoderConfig) :
    {      
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info,*(const Encoder::ConfigV1*)(xtc->payload()));
        break;
      default:
        printf("Unsupported encoder configuration version %d\n",version);
        break;
      }
      break;      
    }
    case (TypeId::Id_TwoDGaussian) :
      process(info, *(const Camera::TwoDGaussianV1*)(xtc->payload()));
      break;
    case (TypeId::Id_Opal1kConfig) :
      process(info, *(const Opal1k::ConfigV1*)(xtc->payload()));
      break;
    case (TypeId::Id_FrameFexConfig) :
      process(info, *(const Camera::FrameFexConfigV1*)(xtc->payload()));
      break;
    case (TypeId::Id_pnCCDconfig) :
      {
      unsigned version = xtc->contains.version();
      switch (version) {
        case 1:
          process(info, *(const PNCCD::ConfigV1*)(xtc->payload()));
          break;
        case 2:
          process(info, *(const PNCCD::ConfigV2*)(xtc->payload()));
          break;
        default:
          printf("Unsupported pnCCD configuration version %d\n",version);
      }
      break;
      }
    case (TypeId::Id_pnCCDframe) :
      {
      process(info, (const PNCCD::FrameV1*)(xtc->payload()));
      break;
      }
    case (TypeId::Id_EvrIOConfig) :
      {      
      process(info, *(const EvrData::IOConfigV1*)(xtc->payload()));
      break;
      }
    case (TypeId::Id_EvrConfig) :
    {      
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const EvrData::ConfigV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const EvrData::ConfigV2*)(xtc->payload()));
        break;
      case 3:
        process(info, *(const EvrData::ConfigV3*)(xtc->payload()));
        break;
      case 4:
        process(info, *(const EvrData::ConfigV4*)(xtc->payload()));
        break;
      case 5:
        process(info, *(const EvrData::ConfigV5*)(xtc->payload()));
        break;
      case 6:
        process(info, *(const EvrData::ConfigV6*)(xtc->payload()));
        break;
      case 7:
        process(info, *(const EvrData::ConfigV7*)(xtc->payload()));
        break;
      default:
        printf("Unsupported evr configuration version %d\n",version);
        break;
      }
      break;      
    }
    case (TypeId::Id_EvrData) :
    {
      process(info, *(const EvrData::DataV3*) xtc->payload() );
      break;        
    }
    case (TypeId::Id_ControlConfig) :
      switch(xtc->contains.version()) {
      case 1:
        process(info, *(const ControlData::ConfigV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const ControlData::ConfigV2*)(xtc->payload()));
        break;
      case 3:
        process(info, *(const ControlData::ConfigV3*)(xtc->payload()));
        break;
      case 4:
        process(info, *(const ControlData::ConfigV4*)(xtc->payload()));
        break;
      default:
        printf("Unsupported ControlData::Config version %d\n",xtc->contains.version());
        break;
      }
      break;
    case (TypeId::Id_Epics) :      
    {
//       int iVersion = xtc->contains.version();
//       if ( iVersion != EpicsXtcSettings::iXtcVersion ) 
//       {
//           printf( "Xtc Epics version (%d) is not compatible with reader supported version (%d)", iVersion, EpicsXtcSettings::iXtcVersion );
//           break;
//       }
      process(info, *(const Epics::EpicsPvHeader*)(xtc->payload()));
      break;
    }
    case (TypeId::Id_TimepixConfig) :
      {
      unsigned version = xtc->contains.version();
      switch (version) {
        case 1:
          process(info, *(const Timepix::ConfigV1*)(xtc->payload()));
          break;
        case 2:
          process(info, *(const Timepix::ConfigV2*)(xtc->payload()));
          break;
        case 3:
          process(info, *(const Timepix::ConfigV3*)(xtc->payload()));
          break;
        default:
          printf("Unsupported timepix configuration version %u\n", version);
          break;
      }
      break;
      }
    case (TypeId::Id_TimepixData) :
      {
      unsigned version = xtc->contains.version();
      switch (version) {
        case 1:
          process(info, *(const Timepix::DataV1*)(xtc->payload()));
          break;
        case 2:
          process(info, *(const Timepix::DataV2*)(xtc->payload()));
          break;
        default:
          printf("Unsupported timepix data version %u\n", version);
          break;
      }
      break;
      }
    /*
     * BLD data
     */
    case (TypeId::Id_FEEGasDetEnergy) :
    {
      switch(xtc->contains.version()) {
      case 0:
        process(info, *(const Bld::BldDataFEEGasDetEnergy*) xtc->payload() );
        break; 
      case 1:
        process(info, *(const Bld::BldDataFEEGasDetEnergyV1*) xtc->payload() );
        break; 
      default:
        break;
      }
    }
    case (TypeId::Id_EBeam) :
    {
      switch(xtc->contains.version()) {
      case 0:
        process(info, *(const Bld::BldDataEBeamV0*) xtc->payload() );
        break; 
      case 1:
        process(info, *(const Bld::BldDataEBeamV1*) xtc->payload() );
        break; 
      case 2:
        process(info, *(const Bld::BldDataEBeamV2*) xtc->payload() );
        break; 
      case 3:
        process(info, *(const Bld::BldDataEBeamV3*) xtc->payload() );
        break; 
      case 4:
        process(info, *(const Bld::BldDataEBeamV4*) xtc->payload() );
        break; 
      case 5:
        process(info, *(const Bld::BldDataEBeamV5*) xtc->payload() );
        break; 
      case 6:
        process(info, *(const Bld::BldDataEBeamV6*) xtc->payload() );
        break; 
      default:
        break;
      }       
      break;
    }    
    case (TypeId::Id_PhaseCavity) :
    {
      process(info, *(const Bld::BldDataPhaseCavity*) xtc->payload() );
      break;        
    }
    case (TypeId::Id_GMD) :
    {
      switch(xtc->contains.version()) {
        case 0:
          process(info, *(const Bld::BldDataGMDV0*) xtc->payload() );
          break;
        case 1:
          process(info, *(const Bld::BldDataGMDV1*) xtc->payload() );
          break;
        case 2:
          process(info, *(const Bld::BldDataGMDV1*) xtc->payload() );
          break;
        default:
          break;
      }
      break;        
    }
    case (TypeId::Id_SharedIpimb) :
    {
     switch(xtc->contains.version()) {
      case 0:
        process(info, *(const Bld::BldDataIpimbV0*) xtc->payload() );
        break; 
      case 1:
        process(info, *(const Bld::BldDataIpimbV1*) xtc->payload() );
        break; 
      default:
        break;
      }       
      break;       
    } 
    case (TypeId::Id_PrincetonConfig) :
    {
      process(info, *(const Princeton::ConfigV1*)(xtc->payload()));
      break;
    }
    case (TypeId::Id_PrincetonFrame) :
    {
      process(info, *(const Princeton::FrameV1*)(xtc->payload()));
      break;
    }    
    case (TypeId::Id_PrincetonInfo) :
    {
      process(info, *(const Princeton::InfoV1*)(xtc->payload()));
      break;
    }    
    case (TypeId::Id_Cspad2x2Element) :
    {
      process(info, *(const CsPad2x2::ElementV1*)(xtc->payload()));
      break;
    }    
    case (TypeId::Id_CspadElement) :
    {
      process(info, *(const CsPad::ElementV1*)(xtc->payload()));
      break;
    }    
    case (TypeId::Id_CspadConfig) :
    {
      process(info, *(const CsPad::ConfigV1*)(xtc->payload()));
      break;
    }    
    case (TypeId::Id_IpmFexConfig) :
    {
      switch(xtc->contains.version()) {
      case 1:
        process(info, *(const Lusi::IpmFexConfigV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const Lusi::IpmFexConfigV2*)(xtc->payload()));
        break;
      default:
        printf("Unsupported IpmFexConfig version %d\n",xtc->contains.version());
        break;
      }
    }    
    case (TypeId::Id_IpmFex) :
    {
      process(info, *(const Lusi::IpmFexV1*)(xtc->payload()));
      break;
    }    
    case (TypeId::Id_DiodeFexConfig) :
    {
      switch(xtc->contains.version()) {
      case 1:
        process(info, *(const Lusi::DiodeFexConfigV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const Lusi::DiodeFexConfigV2*)(xtc->payload()));
        break;
      default:
        printf("Unsupported DiodeFexConfig version %d\n",xtc->contains.version());
        break;
      }
    }    
    case (TypeId::Id_DiodeFex) :
    {
      process(info, *(const Lusi::DiodeFexV1*)(xtc->payload()));
      break;
    }    
    case (TypeId::Id_TM6740Config):
    {
      switch (xtc->contains.version())
      {
      case 1:
        process(info, *(const Pulnix::TM6740ConfigV1 *) xtc->payload());
        break;
      case 2:
        process(info, *(const Pulnix::TM6740ConfigV2 *) xtc->payload());
        break;
      default:
        printf("Unsupported TM6740Config version %d\n", xtc->contains.version());            
        break;
      }        
      break;
    }
    case (TypeId::Id_PimImageConfig):
    {
      process(info, *(const Lusi::PimImageConfigV1 *) (xtc->payload()));
      break;
    }          
    case (TypeId::Id_AliasConfig):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Alias::ConfigV1 *) (xtc->payload()));
        break;
      default:
        printf("Unsupported alias configuration version %d\n", version);
        break;
      }
      break;
    }          
    case (TypeId::Id_RayonixConfig):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Rayonix::ConfigV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const Rayonix::ConfigV2*)(xtc->payload()));
        break;
      default:
        printf("Unsupported Rayonix configuration version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_SmlDataConfig):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const SmlData::ConfigV1*)(xtc->payload()));
        break;
      default:
        printf("Unsupported SmlData Config version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_SmlDataProxy):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const SmlData::ProxyV1*)(xtc->payload()));
        break;
      default:
        printf("Unsupported SmlData Proxy version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_SmlDataOrigDgramOffset):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const SmlData::OrigDgramOffsetV1*)(xtc->payload()));
        break;
      default:
        printf("Unsupported SmlData OrigDgramOffset version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_PartitionConfig):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Partition::ConfigV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const Partition::ConfigV2*)(xtc->payload()));
        break;
      default:
        printf("Unsupported Partition Config  version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_TimeToolConfig):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const TimeTool::ConfigV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const TimeTool::ConfigV2*)(xtc->payload()));
        break;
      case 3:
        process(info, *(const TimeTool::ConfigV3*)(xtc->payload()));
        break;
      default:
        printf("Unsupported TimeTool Config version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_TimeToolData):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const TimeTool::DataV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const TimeTool::DataV2*)(xtc->payload()));
        break;
      case 3:
        process(info, *(const TimeTool::DataV3*)(xtc->payload()));
        break;
      default:
        printf("Unsupported TimeTool Data version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_JungfrauConfig):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Jungfrau::ConfigV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const Jungfrau::ConfigV2*)(xtc->payload()));
        break;
      case 3:
        process(info, *(const Jungfrau::ConfigV3*)(xtc->payload()));
        break;
      case 4:
        process(info, *(const Jungfrau::ConfigV4*)(xtc->payload()));
        break;
      default:
        printf("Unsupported Jungfrau Config version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_JungfrauElement):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Jungfrau::ElementV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const Jungfrau::ElementV2*)(xtc->payload()));
        break;
      default:
        printf("Unsupported Jungfrau Data version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_Epix100aConfig):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Epix::Config100aV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const Epix::Config100aV2*)(xtc->payload()));
        break;
      default:
        printf("Unsupported Epix100a Config version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_Epix10kaConfig):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Epix::Config10kaV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const Epix::Config10kaV2*)(xtc->payload()));
        break;
      default:
        printf("Unsupported Epix10ka Config version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_Epix10ka2MConfig):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Epix::Config10ka2MV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const Epix::Config10ka2MV2*)(xtc->payload()));
        break;
      default:
        printf("Unsupported Epix10ka2M Config version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_Epix10kaArray):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Epix::ArrayV1*)(xtc->payload()));
        break;
      default:
        printf("Unsupported Epix10kaArray version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_Epix10kaQuadConfig):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Epix::Config10kaQuadV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const Epix::Config10kaQuadV2*)(xtc->payload()));
        break;
      default:
        printf("Unsupported Epix10kaQuad Config version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_ZylaConfig):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Zyla::ConfigV1*)(xtc->payload()));
        break;
      default:
        printf("Unsupported Zyla Config version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_iStarConfig):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const iStar::ConfigV1*)(xtc->payload()));
        break;
      default:
        printf("Unsupported iStar Config version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_ZylaFrame):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
        case 1:
          process(info, *(const Zyla::FrameV1*)(xtc->payload()));
          break;
        default:
          printf("Unsupported ZylaFrame version %d\n", version);
          break;
      }
      break;
    }
    case (TypeId::Id_AlviumConfig):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Vimba::AlviumConfigV1*)(xtc->payload()));
        break;
      default:
        printf("Unsupported Alvium Config version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_VimbaFrame):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Vimba::FrameV1*)(xtc->payload()));
        break;
      default:
        printf("Unsupported VimbaFrame version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_UxiConfig):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Uxi::ConfigV1*)(xtc->payload()));
        break;
      case 2:
        process(info, *(const Uxi::ConfigV2*)(xtc->payload()));
        break;
      case 3:
        process(info, *(const Uxi::ConfigV3*)(xtc->payload()));
        break;
      default:
        printf("Unsupported Uxi Config version %d\n", version);
        break;
      }
      break;
    }
    case (TypeId::Id_UxiFrame):
    {
      unsigned version = xtc->contains.version();
      switch (version) {
      case 1:
        process(info, *(const Uxi::FrameV1*)(xtc->payload()));
        break;
      default:
        printf("Unsupported UxiFrame version %d\n", version);
        break;
      }
      break;
    }
    default :
      printf("Unsupported TypeId %s (value = %d)\n", TypeId::name(xtc->contains.id()), (int) xtc->contains.id());
      break;
    }
    return Continue;
  }
private:
  unsigned       _depth;
  long long int  _lliOffset;

  /* static private data */
  static PNCCD::ConfigV1 _pnCcdCfgListV1[2];
  static PNCCD::ConfigV2 _pnCcdCfgListV2[2];
};

PNCCD::ConfigV1 myLevelIter::_pnCcdCfgListV1[2] = { PNCCD::ConfigV1(), PNCCD::ConfigV1() };
PNCCD::ConfigV2 myLevelIter::_pnCcdCfgListV2[2] = { PNCCD::ConfigV2(), PNCCD::ConfigV2() };

void usage(char* progname) {
  fprintf(stderr,"Usage: %s -f <filename> [-h]\n", progname);
}

int main(int argc, char* argv[]) {
  int c;
  char* xtcname=0;
  int parseErr = 0;

  while ((c = getopt(argc, argv, "hf:")) != -1) {
    switch (c) {
    case 'h':
      usage(argv[0]);
      exit(0);
    case 'f':
      xtcname = optarg;
      break;
    default:
      parseErr++;
    }
  }
  
  if (!xtcname) {
    usage(argv[0]);
    exit(2);
  }

  int fd = open(xtcname, O_RDONLY | O_LARGEFILE);
  if (fd < 0) {
    fprintf(stderr, "Unable to open file '%s'\n", xtcname);
    exit(2);
  }

  XtcFileIterator iter(fd,0x4000000);
  Dgram* dg;
  long long int lliOffset = lseek64( fd, 0, SEEK_CUR );  
  while ((dg = iter.next())) {
    printf("%s transition: time %d.%09d, fid/ticks 0x%0x/0x%x, env 0x%x, offset %Ld (0x%Lx), payloadSize %d\n",
           TransitionId::name(dg->seq.service()),
           dg->seq.clock().seconds(),dg->seq.clock().nanoseconds(),
           dg->seq.stamp().fiducials(),dg->seq.stamp().ticks(), 
           dg->env.value(),
           lliOffset, lliOffset, dg->xtc.sizeofPayload());
    myLevelIter iter(&(dg->xtc),0, lliOffset + sizeof(Xtc) + sizeof(*dg) - sizeof(dg->xtc));
    iter.iterate();
    lliOffset = lseek64( fd, 0, SEEK_CUR ); // get the file offset for the next iteration
  }

  ::close(fd);
  return 0;
}
