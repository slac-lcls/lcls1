// *** Do not edit this file, it is auto-generated ***

#include "MsgLogger/MsgLogger.h"
#include "PSEvt/Exceptions.h"

#include "psddl_hdf2psana/dispatch.h"
#include "psddl_hdf2psana/alias.ddl.h"
#include "psddl_hdf2psana/cspad.ddl.h"
#include "psddl_hdf2psana/l3t.ddl.h"
#include "psddl_hdf2psana/evr.ddl.h"
#include "psddl_hdf2psana/encoder.ddl.h"
#include "psddl_hdf2psana/usdusb.ddl.h"
#include "psddl_hdf2psana/timepix.ddl.h"
#include "psddl_hdf2psana/epixsampler.ddl.h"
#include "psddl_hdf2psana/camera.ddl.h"
#include "psddl_hdf2psana/partition.ddl.h"
#include "psddl_hdf2psana/quartz.ddl.h"
#include "psddl_hdf2psana/gsc16ai.ddl.h"
#include "psddl_hdf2psana/bld.ddl.h"
#include "psddl_hdf2psana/genericpgp.ddl.h"
#include "psddl_hdf2psana/fccd.ddl.h"
#include "psddl_hdf2psana/imp.ddl.h"
#include "psddl_hdf2psana/arraychar.ddl.h"
#include "psddl_hdf2psana/pnccd.ddl.h"
#include "psddl_hdf2psana/epics.ddl.h"
#include "psddl_hdf2psana/orca.ddl.h"
#include "psddl_hdf2psana/ipimb.ddl.h"
#include "psddl_hdf2psana/princeton.ddl.h"
#include "psddl_hdf2psana/control.ddl.h"
#include "psddl_hdf2psana/cspad2x2.ddl.h"
#include "psddl_hdf2psana/opal1k.ddl.h"
#include "psddl_hdf2psana/pimax.ddl.h"
#include "psddl_hdf2psana/andor.ddl.h"
#include "psddl_hdf2psana/fli.ddl.h"
#include "psddl_hdf2psana/oceanoptics.ddl.h"
#include "psddl_hdf2psana/timetool.ddl.h"
#include "psddl_hdf2psana/lusi.ddl.h"
#include "psddl_hdf2psana/andor3d.ddl.h"
#include "psddl_hdf2psana/acqiris.ddl.h"
#include "psddl_hdf2psana/jungfrau.ddl.h"
#include "psddl_hdf2psana/generic1d.ddl.h"
#include "psddl_hdf2psana/rayonix.ddl.h"
#include "psddl_hdf2psana/epix.ddl.h"
#include "psddl_hdf2psana/pulnix.ddl.h"


namespace {
    uint32_t str_hash(const std::string& str)
    {
        uint32_t hash = 5381;
        for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
            hash = ((hash << 5) + hash) ^ uint32_t(*it); /* hash * 33 + c */
        }
        return hash;
    }
}

namespace psddl_hdf2psana {
void hdfConvert(const hdf5pp::Group& group, int64_t idx, const std::string& typeName, int schema_version, 
                const Pds::Src& src, PSEvt::Event& evt, PSEnv::EnvObjectStore& cfgStore)
try {

  uint32_t hash = str_hash(typeName);
  switch(hash) {
  case 77859337:
    // Princeton::FrameV1
    if (boost::shared_ptr<Psana::Princeton::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Princeton::make_FrameV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::Princeton::ConfigV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Princeton::make_FrameV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::Princeton::ConfigV3> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Princeton::make_FrameV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::Princeton::ConfigV4> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Princeton::make_FrameV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::Princeton::ConfigV5> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Princeton::make_FrameV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 77859338:
    // Princeton::FrameV2
    if (boost::shared_ptr<Psana::Princeton::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Princeton::make_FrameV2(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::Princeton::ConfigV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Princeton::make_FrameV2(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::Princeton::ConfigV3> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Princeton::make_FrameV2(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::Princeton::ConfigV4> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Princeton::make_FrameV2(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::Princeton::ConfigV5> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Princeton::make_FrameV2(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 78353934:
    // Bld::BldDataAnalogInputV1
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataAnalogInputV1(schema_version, group, idx), src);
    break;
  case 115545194:
    // Bld::BldDataPhaseCavity
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataPhaseCavity(schema_version, group, idx), src);
    break;
  case 169144489:
    // Acqiris::TdcConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Acqiris::make_TdcConfigV1(schema_version, group, idx), src);
    break;
  case 171641950:
    // Jungfrau::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Jungfrau::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 245364150:
    // PNCCD::FullFrameV1
    evt.putProxy(psddl_hdf2psana::PNCCD::make_FullFrameV1(schema_version, group, idx), src);
    break;
  case 435810708:
    // Bld::BldDataUsdUsbV1
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataUsdUsbV1(schema_version, group, idx), src);
    break;
  case 477483284:
    // UsdUsb::DataV1
    evt.putProxy(psddl_hdf2psana::UsdUsb::make_DataV1(schema_version, group, idx), src);
    break;
  case 512147952:
    // Lusi::DiodeFexConfigV2
    cfgStore.putProxy(psddl_hdf2psana::Lusi::make_DiodeFexConfigV2(schema_version, group, idx), src);
    break;
  case 512147955:
    // Lusi::DiodeFexConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Lusi::make_DiodeFexConfigV1(schema_version, group, idx), src);
    break;
  case 619316661:
    // Bld::BldDataBeamMonitorV1
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataBeamMonitorV1(schema_version, group, idx), src);
    break;
  case 647095708:
    // TimeTool::DataV2
    if (boost::shared_ptr<Psana::TimeTool::ConfigV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::TimeTool::make_DataV2(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 647095711:
    // TimeTool::DataV1
    if (boost::shared_ptr<Psana::TimeTool::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::TimeTool::make_DataV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 670963505:
    // Quartz::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Quartz::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 670963506:
    // Quartz::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::Quartz::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 738044564:
    // Bld::BldDataSpectrometerV0
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataSpectrometerV0(schema_version, group, idx), src);
    break;
  case 738044565:
    // Bld::BldDataSpectrometerV1
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataSpectrometerV1(schema_version, group, idx), src);
    break;
  case 756401870:
    // Lusi::IpmFexV1
    evt.putProxy(psddl_hdf2psana::Lusi::make_IpmFexV1(schema_version, group, idx), src);
    break;
  case 912501018:
    // Princeton::InfoV1
    evt.putProxy(psddl_hdf2psana::Princeton::make_InfoV1(schema_version, group, idx), src);
    break;
  case 913738682:
    // Princeton::ConfigV5
    cfgStore.putProxy(psddl_hdf2psana::Princeton::make_ConfigV5(schema_version, group, idx), src);
    break;
  case 913738683:
    // Princeton::ConfigV4
    cfgStore.putProxy(psddl_hdf2psana::Princeton::make_ConfigV4(schema_version, group, idx), src);
    break;
  case 913738684:
    // Princeton::ConfigV3
    cfgStore.putProxy(psddl_hdf2psana::Princeton::make_ConfigV3(schema_version, group, idx), src);
    break;
  case 913738685:
    // Princeton::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::Princeton::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 913738686:
    // Princeton::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Princeton::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 1022640349:
    // Andor::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::Andor::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 1022640350:
    // Andor::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Andor::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 1048460753:
    // Bld::BldDataFEEGasDetEnergy
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataFEEGasDetEnergy(schema_version, group, idx), src);
    break;
  case 1054612892:
    // Epix::Config100aV1
    cfgStore.putProxy(psddl_hdf2psana::Epix::make_Config100aV1(schema_version, group, idx), src);
    break;
  case 1054612895:
    // Epix::Config100aV2
    cfgStore.putProxy(psddl_hdf2psana::Epix::make_Config100aV2(schema_version, group, idx), src);
    break;
  case 1078464760:
    // Bld::BldDataEBeamV5
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataEBeamV5(schema_version, group, idx), src);
    break;
  case 1078464761:
    // Bld::BldDataEBeamV4
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataEBeamV4(schema_version, group, idx), src);
    break;
  case 1078464762:
    // Bld::BldDataEBeamV7
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataEBeamV7(schema_version, group, idx), src);
    break;
  case 1078464763:
    // Bld::BldDataEBeamV6
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataEBeamV6(schema_version, group, idx), src);
    break;
  case 1078464764:
    // Bld::BldDataEBeamV1
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataEBeamV1(schema_version, group, idx), src);
    break;
  case 1078464765:
    // Bld::BldDataEBeamV0
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataEBeamV0(schema_version, group, idx), src);
    break;
  case 1078464766:
    // Bld::BldDataEBeamV3
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataEBeamV3(schema_version, group, idx), src);
    break;
  case 1078464767:
    // Bld::BldDataEBeamV2
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataEBeamV2(schema_version, group, idx), src);
    break;
  case 1083296677:
    // Encoder::DataV2
    evt.putProxy(psddl_hdf2psana::Encoder::make_DataV2(schema_version, group, idx), src);
    break;
  case 1083296678:
    // Encoder::DataV1
    evt.putProxy(psddl_hdf2psana::Encoder::make_DataV1(schema_version, group, idx), src);
    break;
  case 1101528269:
    // Generic1D::ConfigV0
    cfgStore.putProxy(psddl_hdf2psana::Generic1D::make_ConfigV0(schema_version, group, idx), src);
    break;
  case 1151720060:
    // Fli::FrameV1
    if (boost::shared_ptr<Psana::Fli::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Fli::make_FrameV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 1170742428:
    // Timepix::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Timepix::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 1170742430:
    // Timepix::ConfigV3
    cfgStore.putProxy(psddl_hdf2psana::Timepix::make_ConfigV3(schema_version, group, idx), src);
    break;
  case 1170742431:
    // Timepix::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::Timepix::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 1242681297:
    // PNCCD::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::PNCCD::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 1242681298:
    // PNCCD::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::PNCCD::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 1254115734:
    // PNCCD::FramesV1
    if (boost::shared_ptr<Psana::PNCCD::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::PNCCD::make_FramesV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::PNCCD::ConfigV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::PNCCD::make_FramesV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 1361748889:
    // EvrData::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::EvrData::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 1361748890:
    // EvrData::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::EvrData::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 1361748891:
    // EvrData::ConfigV3
    cfgStore.putProxy(psddl_hdf2psana::EvrData::make_ConfigV3(schema_version, group, idx), src);
    break;
  case 1361748892:
    // EvrData::ConfigV4
    cfgStore.putProxy(psddl_hdf2psana::EvrData::make_ConfigV4(schema_version, group, idx), src);
    break;
  case 1361748893:
    // EvrData::ConfigV5
    cfgStore.putProxy(psddl_hdf2psana::EvrData::make_ConfigV5(schema_version, group, idx), src);
    break;
  case 1361748894:
    // EvrData::ConfigV6
    cfgStore.putProxy(psddl_hdf2psana::EvrData::make_ConfigV6(schema_version, group, idx), src);
    break;
  case 1361748895:
    // EvrData::ConfigV7
    cfgStore.putProxy(psddl_hdf2psana::EvrData::make_ConfigV7(schema_version, group, idx), src);
    break;
  case 1378175084:
    // Epix::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Epix::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 1387299804:
    // OceanOptics::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::OceanOptics::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 1387299807:
    // OceanOptics::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::OceanOptics::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 1422110804:
    // Camera::FrameCoord
    evt.putProxy(psddl_hdf2psana::Camera::make_FrameCoord(schema_version, group, idx), src);
    break;
  case 1461968857:
    // CsPad::ElementV1
    if (boost::shared_ptr<Psana::CsPad::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::CsPad::ConfigV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::CsPad::ConfigV3> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::CsPad::ConfigV4> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::CsPad::ConfigV5> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 1461968858:
    // CsPad::ElementV2
    if (boost::shared_ptr<Psana::CsPad::ConfigV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV2(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::CsPad::ConfigV3> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV2(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::CsPad::ConfigV4> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV2(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::CsPad::ConfigV5> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV2(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 1551708791:
    // Orca::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Orca::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 1575949158:
    // Camera::FrameV1
    evt.putProxy(psddl_hdf2psana::Camera::make_FrameV1(schema_version, group, idx), src);
    break;
  case 1614614470:
    // Camera::TwoDGaussianV1
    evt.putProxy(psddl_hdf2psana::Camera::make_TwoDGaussianV1(schema_version, group, idx), src);
    break;
  case 1624433404:
    // Encoder::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Encoder::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 1624433407:
    // Encoder::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::Encoder::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 1698299089:
    // Rayonix::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::Rayonix::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 1698299090:
    // Rayonix::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Rayonix::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 1705456020:
    // Ipimb::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::Ipimb::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 1705456023:
    // Ipimb::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Ipimb::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 1751123230:
    // Alias::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Alias::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 1777917796:
    // Lusi::IpmFexConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Lusi::make_IpmFexConfigV1(schema_version, group, idx), src);
    break;
  case 1777917799:
    // Lusi::IpmFexConfigV2
    cfgStore.putProxy(psddl_hdf2psana::Lusi::make_IpmFexConfigV2(schema_version, group, idx), src);
    break;
  case 1852352324:
    // Epics::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Epics::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 1869558588:
    // EvrData::IOConfigV2
    cfgStore.putProxy(psddl_hdf2psana::EvrData::make_IOConfigV2(schema_version, group, idx), src);
    break;
  case 1869558591:
    // EvrData::IOConfigV1
    cfgStore.putProxy(psddl_hdf2psana::EvrData::make_IOConfigV1(schema_version, group, idx), src);
    break;
  case 2001219479:
    // EvrData::SrcEventCode
    evt.putProxy(psddl_hdf2psana::EvrData::make_SrcEventCode(schema_version, group, idx), src);
    break;
  case 2058892252:
    // Imp::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Imp::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 2103238272:
    // Opal1k::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Opal1k::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 2115881232:
    // Gsc16ai::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Gsc16ai::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 2125326828:
    // EpixSampler::ElementV1
    if (boost::shared_ptr<Psana::EpixSampler::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::EpixSampler::make_ElementV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 2143487294:
    // Andor3d::FrameV1
    if (boost::shared_ptr<Psana::Andor3d::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Andor3d::make_FrameV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 2160030172:
    // ControlData::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::ControlData::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 2160030173:
    // ControlData::ConfigV3
    cfgStore.putProxy(psddl_hdf2psana::ControlData::make_ConfigV3(schema_version, group, idx), src);
    break;
  case 2160030175:
    // ControlData::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::ControlData::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 2196756248:
    // EpixSampler::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::EpixSampler::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 2215517545:
    // Andor3d::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Andor3d::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 2244450246:
    // Epix::Config10KV1
    cfgStore.putProxy(psddl_hdf2psana::Epix::make_Config10KV1(schema_version, group, idx), src);
    break;
  case 2263071815:
    // Bld::BldDataAcqADCV1
    if (boost::shared_ptr<Psana::Acqiris::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Bld::make_BldDataAcqADCV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 2275609067:
    // Fli::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Fli::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 2301568325:
    // Timepix::DataV2
    evt.putProxy(psddl_hdf2psana::Timepix::make_DataV2(schema_version, group, idx), src);
    break;
  case 2301568326:
    // Timepix::DataV1
    evt.putProxy(psddl_hdf2psana::Timepix::make_DataV1(schema_version, group, idx), src);
    break;
  case 2393145943:
    // Camera::FrameFexConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Camera::make_FrameFexConfigV1(schema_version, group, idx), src);
    break;
  case 2519955859:
    // Arraychar::DataV1
    evt.putProxy(psddl_hdf2psana::Arraychar::make_DataV1(schema_version, group, idx), src);
    break;
  case 2708910361:
    // Lusi::DiodeFexV1
    evt.putProxy(psddl_hdf2psana::Lusi::make_DiodeFexV1(schema_version, group, idx), src);
    break;
  case 2814362281:
    // Partition::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::Partition::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 2814362282:
    // Partition::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Partition::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 2869143498:
    // Gsc16ai::DataV1
    if (boost::shared_ptr<Psana::Gsc16ai::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Gsc16ai::make_DataV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 2901814733:
    // Ipimb::DataV1
    evt.putProxy(psddl_hdf2psana::Ipimb::make_DataV1(schema_version, group, idx), src);
    break;
  case 2901814734:
    // Ipimb::DataV2
    evt.putProxy(psddl_hdf2psana::Ipimb::make_DataV2(schema_version, group, idx), src);
    break;
  case 2913417125:
    // Pimax::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Pimax::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 2914045208:
    // Epix::ElementV1
    if (boost::shared_ptr<Psana::Epix::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Epix::make_ElementV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::Epix::Config10KV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Epix::make_ElementV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::GenericPgp::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Epix::make_ElementV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 2914045210:
    // Epix::ElementV3
    if (boost::shared_ptr<Psana::Epix::Config100aV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Epix::make_ElementV3(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::Epix::Config100aV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Epix::make_ElementV3(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 2914045211:
    // Epix::ElementV2
    if (boost::shared_ptr<Psana::Epix::Config100aV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Epix::make_ElementV2(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::Epix::Config100aV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Epix::make_ElementV2(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 2929134980:
    // OceanOptics::DataV3
    if (boost::shared_ptr<Psana::OceanOptics::ConfigV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::OceanOptics::make_DataV3(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 2929134981:
    // OceanOptics::DataV2
    if (boost::shared_ptr<Psana::OceanOptics::ConfigV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::OceanOptics::make_DataV2(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 2929134982:
    // OceanOptics::DataV1
    if (boost::shared_ptr<Psana::OceanOptics::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::OceanOptics::make_DataV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::OceanOptics::ConfigV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::OceanOptics::make_DataV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 2940448584:
    // CsPad::ConfigV4
    cfgStore.putProxy(psddl_hdf2psana::CsPad::make_ConfigV4(schema_version, group, idx), src);
    break;
  case 2940448585:
    // CsPad::ConfigV5
    cfgStore.putProxy(psddl_hdf2psana::CsPad::make_ConfigV5(schema_version, group, idx), src);
    break;
  case 2940448589:
    // CsPad::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::CsPad::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 2940448590:
    // CsPad::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::CsPad::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 2940448591:
    // CsPad::ConfigV3
    cfgStore.putProxy(psddl_hdf2psana::CsPad::make_ConfigV3(schema_version, group, idx), src);
    break;
  case 2947916881:
    // Acqiris::DataDescV1
    if (boost::shared_ptr<Psana::Acqiris::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Acqiris::make_DataDescV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 2962565746:
    // Pimax::FrameV1
    if (boost::shared_ptr<Psana::Pimax::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Pimax::make_FrameV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 2968036851:
    // Acqiris::TdcDataV1
    evt.putProxy(psddl_hdf2psana::Acqiris::make_TdcDataV1(schema_version, group, idx), src);
    break;
  case 3055861455:
    // UsdUsb::FexDataV1
    evt.putProxy(psddl_hdf2psana::UsdUsb::make_FexDataV1(schema_version, group, idx), src);
    break;
  case 3110430406:
    // Bld::BldDataPimV1
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataPimV1(schema_version, group, idx), src);
    break;
  case 3115488487:
    // Bld::BldDataEOrbitsV0
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataEOrbitsV0(schema_version, group, idx), src);
    break;
  case 3122588892:
    // Bld::BldDataGMDV1
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataGMDV1(schema_version, group, idx), src);
    break;
  case 3122588893:
    // Bld::BldDataGMDV0
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataGMDV0(schema_version, group, idx), src);
    break;
  case 3122588895:
    // Bld::BldDataGMDV2
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataGMDV2(schema_version, group, idx), src);
    break;
  case 3124602907:
    // Bld::BldDataEBeam
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataEBeamV1(schema_version, group, idx), src);
    break;
  case 3139117226:
    // Bld::BldDataIpimb
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataIpimbV0(schema_version, group, idx), src);
    break;
  case 3291453148:
    // Camera::ControlsCameraConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Camera::make_ControlsCameraConfigV1(schema_version, group, idx), src);
    break;
  case 3346701347:
    // L3T::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::L3T::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 3467424660:
    // CsPad::DataV2
    if (boost::shared_ptr<Psana::CsPad::ConfigV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV2(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::CsPad::ConfigV3> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV2(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::CsPad::ConfigV4> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV2(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::CsPad::ConfigV5> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV2(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 3467424663:
    // CsPad::DataV1
    if (boost::shared_ptr<Psana::CsPad::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::CsPad::ConfigV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::CsPad::ConfigV3> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::CsPad::ConfigV4> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::CsPad::ConfigV5> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::CsPad::make_DataV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 3486939573:
    // CsPad2x2::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::CsPad2x2::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 3486939574:
    // CsPad2x2::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::CsPad2x2::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 3515749019:
    // EvrData::SrcConfigV1
    cfgStore.putProxy(psddl_hdf2psana::EvrData::make_SrcConfigV1(schema_version, group, idx), src);
    break;
  case 3538416190:
    // GenericPgp::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::GenericPgp::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 3565044250:
    // Acqiris::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Acqiris::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 3580200696:
    // Lusi::PimImageConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Lusi::make_PimImageConfigV1(schema_version, group, idx), src);
    break;
  case 3607424182:
    // Bld::BldDataFEEGasDetEnergyV1
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataFEEGasDetEnergyV1(schema_version, group, idx), src);
    break;
  case 3647400170:
    // Jungfrau::ElementV1
    if (boost::shared_ptr<Psana::Jungfrau::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Jungfrau::make_ElementV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 3654144449:
    // EvrData::DataV3
    evt.putProxy(psddl_hdf2psana::EvrData::make_DataV3(schema_version, group, idx), src);
    break;
  case 3654144454:
    // EvrData::DataV4
    evt.putProxy(psddl_hdf2psana::EvrData::make_DataV4(schema_version, group, idx), src);
    break;
  case 3663597207:
    // Generic1D::DataV0
    if (boost::shared_ptr<Psana::Generic1D::ConfigV0> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Generic1D::make_DataV0(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 3682217189:
    // PNCCD::FrameV1
    evt.putProxy(psddl_hdf2psana::PNCCD::make_FullFrameV1(schema_version, group, idx), src);
    if (boost::shared_ptr<Psana::PNCCD::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::PNCCD::make_FramesV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::PNCCD::ConfigV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::PNCCD::make_FramesV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 3781484641:
    // CsPad2x2::ElementV1
    evt.putProxy(psddl_hdf2psana::CsPad2x2::make_ElementV1(schema_version, group, idx), src);
    break;
  case 3801204302:
    // UsdUsb::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::UsdUsb::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 3930091641:
    // L3T::DataV1
    evt.putProxy(psddl_hdf2psana::L3T::make_DataV1(schema_version, group, idx), src);
    break;
  case 3930091642:
    // L3T::DataV2
    evt.putProxy(psddl_hdf2psana::L3T::make_DataV2(schema_version, group, idx), src);
    break;
  case 3940776773:
    // TimeTool::ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::TimeTool::make_ConfigV1(schema_version, group, idx), src);
    break;
  case 3940776774:
    // TimeTool::ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::TimeTool::make_ConfigV2(schema_version, group, idx), src);
    break;
  case 3985960297:
    // Andor::FrameV1
    if (boost::shared_ptr<Psana::Andor::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Andor::make_FrameV1(schema_version, group, idx, cfgPtr), src);
    } else if (boost::shared_ptr<Psana::Andor::ConfigV2> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Andor::make_FrameV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 3999657228:
    // Bld::BldDataIpimbV0
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataIpimbV0(schema_version, group, idx), src);
    break;
  case 3999657229:
    // Bld::BldDataIpimbV1
    evt.putProxy(psddl_hdf2psana::Bld::make_BldDataIpimbV1(schema_version, group, idx), src);
    break;
  case 4055296315:
    // Acqiris::AcqirisTdcConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Acqiris::make_TdcConfigV1(schema_version, group, idx), src);
    break;
  case 4103916008:
    // FCCD::FccdConfigV1
    cfgStore.putProxy(psddl_hdf2psana::FCCD::make_FccdConfigV1(schema_version, group, idx), src);
    break;
  case 4103916011:
    // FCCD::FccdConfigV2
    cfgStore.putProxy(psddl_hdf2psana::FCCD::make_FccdConfigV2(schema_version, group, idx), src);
    break;
  case 4130246568:
    // Imp::ElementV1
    if (boost::shared_ptr<Psana::Imp::ConfigV1> cfgPtr = cfgStore.get(src)) {
      evt.putProxy(psddl_hdf2psana::Imp::make_ElementV1(schema_version, group, idx, cfgPtr), src);
    }
    break;
  case 4207593793:
    // Pulnix::TM6740ConfigV2
    cfgStore.putProxy(psddl_hdf2psana::Pulnix::make_TM6740ConfigV2(schema_version, group, idx), src);
    break;
  case 4207593794:
    // Pulnix::TM6740ConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Pulnix::make_TM6740ConfigV1(schema_version, group, idx), src);
    break;
  case 4209408661:
    // UsdUsb::FexConfigV1
    cfgStore.putProxy(psddl_hdf2psana::UsdUsb::make_FexConfigV1(schema_version, group, idx), src);
    break;
  case 4219576590:
    // Camera::FrameFccdConfigV1
    cfgStore.putProxy(psddl_hdf2psana::Camera::make_FrameFccdConfigV1(schema_version, group, idx), src);
    break;
  } // end switch

} catch (const PSEvt::ExceptionDuplicateKey& ex) {
  // catch exception for duplicated objects, issue warning
  MsgLog("hdfConvert", warning, ex.what());
} // end hdfConvert(...)

} // namespace psddl_hdf2psana
