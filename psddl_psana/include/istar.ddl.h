#ifndef PSANA_ISTAR_DDL_H
#define PSANA_ISTAR_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <iosfwd>
#include <cstring>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
namespace Psana {
namespace iStar {

/** @class ConfigV1

  
*/


class ConfigV1 {
public:
  enum { TypeId = Pds::TypeId::Id_iStarConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  enum { STR_LEN_MAX = 64 };
  enum ATBool {
    False = 0,
    True = 1,
  };
  enum FanSpeed {
    Off = 0,
    On = 1,
  };
  enum ReadoutRate {
    Rate280MHz = 0,
    Rate100MHz = 1,
  };
  enum TriggerMode {
    Internal = 0,
    ExternalLevelTransition = 1,
    ExternalStart = 2,
    ExternalExposure = 3,
    Software = 4,
    Advanced = 5,
    External = 6,
  };
  enum GainMode {
    HighWellCap12Bit = 0,
    LowNoise12Bit = 1,
    LowNoiseHighWellCap16Bit = 2,
  };
  enum GateMode {
    CWOn = 0,
    CWOff = 1,
    FireOnly = 2,
    GateOnly = 3,
    FireAndGate = 4,
    DDG = 5,
  };
  enum InsertionDelay {
    Normal = 0,
    Fast = 1,
  };
  virtual ~ConfigV1();
  virtual iStar::ConfigV1::ATBool cooling() const = 0;
  virtual iStar::ConfigV1::ATBool overlap() const = 0;
  virtual iStar::ConfigV1::ATBool noiseFilter() const = 0;
  virtual iStar::ConfigV1::ATBool blemishCorrection() const = 0;
  virtual iStar::ConfigV1::ATBool mcpIntelligate() const = 0;
  virtual iStar::ConfigV1::FanSpeed fanSpeed() const = 0;
  virtual iStar::ConfigV1::ReadoutRate readoutRate() const = 0;
  virtual iStar::ConfigV1::TriggerMode triggerMode() const = 0;
  virtual iStar::ConfigV1::GainMode gainMode() const = 0;
  virtual iStar::ConfigV1::GateMode gateMode() const = 0;
  virtual iStar::ConfigV1::InsertionDelay insertionDelay() const = 0;
  virtual uint16_t mcpGain() const = 0;
  virtual uint32_t width() const = 0;
  virtual uint32_t height() const = 0;
  virtual uint32_t orgX() const = 0;
  virtual uint32_t orgY() const = 0;
  virtual uint32_t binX() const = 0;
  virtual uint32_t binY() const = 0;
  virtual double exposureTime() const = 0;
  virtual double triggerDelay() const = 0;
  /** Total size in bytes of the Frame object */
  virtual uint32_t frameSize() const = 0;
  /** calculate frame X size in pixels based on the current ROI and binning settings */
  virtual uint32_t numPixelsX() const = 0;
  /** calculate frame Y size in pixels based on the current ROI and binning settings */
  virtual uint32_t numPixelsY() const = 0;
  /** calculate total frame size in pixels based on the current ROI and binning settings */
  virtual uint32_t numPixels() const = 0;
};
std::ostream& operator<<(std::ostream& str, iStar::ConfigV1::ATBool enval);
std::ostream& operator<<(std::ostream& str, iStar::ConfigV1::FanSpeed enval);
std::ostream& operator<<(std::ostream& str, iStar::ConfigV1::ReadoutRate enval);
std::ostream& operator<<(std::ostream& str, iStar::ConfigV1::TriggerMode enval);
std::ostream& operator<<(std::ostream& str, iStar::ConfigV1::GainMode enval);
std::ostream& operator<<(std::ostream& str, iStar::ConfigV1::GateMode enval);
std::ostream& operator<<(std::ostream& str, iStar::ConfigV1::InsertionDelay enval);
} // namespace iStar
} // namespace Psana
#endif // PSANA_ISTAR_DDL_H
