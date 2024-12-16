#ifndef PDS_JUNGFRAU_DDL_H
#define PDS_JUNGFRAU_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <iosfwd>
#include <cstddef>
#include <cstring>
#include "pdsdata/xtc/TypeId.hh"
#include "ndarray/ndarray.h"
namespace Pds {
namespace Jungfrau {

/** @class ModuleConfigV1

  
*/

#pragma pack(push,2)

class ModuleConfigV1 {
public:
  ModuleConfigV1(uint64_t arg__serialNumber, uint64_t arg__moduleVerion, uint64_t arg__firmwareVersion);
  ModuleConfigV1() {}
  ModuleConfigV1(const ModuleConfigV1& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
  }
  ModuleConfigV1& operator=(const ModuleConfigV1& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
    return *this;
  }
  /** The module serial number. */
  uint64_t serialNumber() const { return _serialNumber; }
  /** The version number of the module. */
  uint64_t moduleVersion() const { return _moduleVerion; }
  /** The firmware version of the module. */
  uint64_t firmwareVersion() const { return _firmwareVersion; }
  static uint32_t _sizeof() { return 24; }
private:
  uint64_t	_serialNumber;	/**< The module serial number. */
  uint64_t	_moduleVerion;	/**< The version number of the module. */
  uint64_t	_firmwareVersion;	/**< The firmware version of the module. */
};
#pragma pack(pop)

/** @class ConfigV1

  
*/

#pragma pack(push,4)

class ConfigV1 {
public:
  enum { TypeId = Pds::TypeId::Id_JungfrauConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  enum GainMode {
    Normal = 0,
    FixedGain1 = 1,
    FixedGain2 = 2,
    ForcedGain1 = 3,
    ForcedGain2 = 4,
    HighGain0 = 5,
  };
  enum SpeedMode {
    Quarter = 0,
    Half = 1,
  };
  ConfigV1(uint32_t arg__numberOfModules, uint32_t arg__numberOfRowsPerModule, uint32_t arg__numberOfColumnsPerModule, uint32_t arg__biasVoltage, Jungfrau::ConfigV1::GainMode arg__gainMode, Jungfrau::ConfigV1::SpeedMode arg__speedMode, double arg__triggerDelay, double arg__exposureTime);
  ConfigV1() {}
  ConfigV1(const ConfigV1& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
  }
  ConfigV1& operator=(const ConfigV1& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
    return *this;
  }
  /** The number of modules in a physical camera. */
  uint32_t numberOfModules() const { return _numberOfModules; }
  /** The number of rows per module. */
  uint32_t numberOfRowsPerModule() const { return _numberOfRowsPerModule; }
  /** The number of columns per module. */
  uint32_t numberOfColumnsPerModule() const { return _numberOfColumnsPerModule; }
  /** The bias applied to the sensor in volts. */
  uint32_t biasVoltage() const { return _biasVoltage; }
  /** The gain mode set for the camera. */
  Jungfrau::ConfigV1::GainMode gainMode() const { return Jungfrau::ConfigV1::GainMode(_gainMode); }
  /** The camera clock speed setting. */
  Jungfrau::ConfigV1::SpeedMode speedMode() const { return Jungfrau::ConfigV1::SpeedMode(_speedMode); }
  /** Internal delay from receiving a trigger input until the start of an acquisiton in seconds. */
  double triggerDelay() const { return _triggerDelay; }
  /** The exposure time in seconds. */
  double exposureTime() const { return _exposureTime; }
  /** Total size in bytes of the Frame object */
  uint32_t frameSize() const;
  /** calculate total frame size in pixels based on the current ROI and binning settings */
  uint32_t numPixels() const { return numberOfModules()*numberOfRowsPerModule()*numberOfColumnsPerModule(); }
  static uint32_t _sizeof() { return 36; }
private:
  uint32_t	_numberOfModules;	/**< The number of modules in a physical camera. */
  uint32_t	_numberOfRowsPerModule;	/**< The number of rows per module. */
  uint32_t	_numberOfColumnsPerModule;	/**< The number of columns per module. */
  uint32_t	_biasVoltage;	/**< The bias applied to the sensor in volts. */
  uint16_t	_gainMode;	/**< The gain mode set for the camera. */
  uint16_t	_speedMode;	/**< The camera clock speed setting. */
  double	_triggerDelay;	/**< Internal delay from receiving a trigger input until the start of an acquisiton in seconds. */
  double	_exposureTime;	/**< The exposure time in seconds. */
};
std::ostream& operator<<(std::ostream& str, Jungfrau::ConfigV1::GainMode enval);
std::ostream& operator<<(std::ostream& str, Jungfrau::ConfigV1::SpeedMode enval);
#pragma pack(pop)

/** @class ConfigV2

  
*/

#pragma pack(push,4)

class ConfigV2 {
public:
  enum { TypeId = Pds::TypeId::Id_JungfrauConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  enum GainMode {
    Normal = 0,
    FixedGain1 = 1,
    FixedGain2 = 2,
    ForcedGain1 = 3,
    ForcedGain2 = 4,
    HighGain0 = 5,
  };
  enum SpeedMode {
    Quarter = 0,
    Half = 1,
  };
  ConfigV2(uint32_t arg__numberOfModules, uint32_t arg__numberOfRowsPerModule, uint32_t arg__numberOfColumnsPerModule, uint32_t arg__biasVoltage, Jungfrau::ConfigV2::GainMode arg__gainMode, Jungfrau::ConfigV2::SpeedMode arg__speedMode, double arg__triggerDelay, double arg__exposureTime, double arg__exposurePeriod, uint16_t arg__vb_ds, uint16_t arg__vb_comp, uint16_t arg__vb_pixbuf, uint16_t arg__vref_ds, uint16_t arg__vref_comp, uint16_t arg__vref_prech, uint16_t arg__vin_com, uint16_t arg__vdd_prot);
  ConfigV2() {}
  ConfigV2(const ConfigV2& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
  }
  ConfigV2& operator=(const ConfigV2& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
    return *this;
  }
  /** The number of modules in a physical camera. */
  uint32_t numberOfModules() const { return _numberOfModules; }
  /** The number of rows per module. */
  uint32_t numberOfRowsPerModule() const { return _numberOfRowsPerModule; }
  /** The number of columns per module. */
  uint32_t numberOfColumnsPerModule() const { return _numberOfColumnsPerModule; }
  /** The bias applied to the sensor in volts. */
  uint32_t biasVoltage() const { return _biasVoltage; }
  /** The gain mode set for the camera. */
  Jungfrau::ConfigV2::GainMode gainMode() const { return Jungfrau::ConfigV2::GainMode(_gainMode); }
  /** The camera clock speed setting. */
  Jungfrau::ConfigV2::SpeedMode speedMode() const { return Jungfrau::ConfigV2::SpeedMode(_speedMode); }
  /** Internal delay from receiving a trigger input until the start of an acquisiton in seconds. */
  double triggerDelay() const { return _triggerDelay; }
  /** The exposure time in seconds. */
  double exposureTime() const { return _exposureTime; }
  /** The period between exposures of the camera. In triggered mode this should be smaller than the trigger period. */
  double exposurePeriod() const { return _exposurePeriod; }
  /** Value of vb_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vb_ds() const { return _vb_ds; }
  /** Value of vb_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vb_comp() const { return _vb_comp; }
  /** Value of vb_pixbuf in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vb_pixbuf() const { return _vb_pixbuf; }
  /** Value of vref_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vref_ds() const { return _vref_ds; }
  /** Value of vref_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vref_comp() const { return _vref_comp; }
  /** Value of vref_prech in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vref_prech() const { return _vref_prech; }
  /** Value of vin_com in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vin_com() const { return _vin_com; }
  /** Value of vdd_prot in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vdd_prot() const { return _vdd_prot; }
  /** Total size in bytes of the Frame object */
  uint32_t frameSize() const;
  /** calculate total frame size in pixels based on the current ROI and binning settings */
  uint32_t numPixels() const { return numberOfModules()*numberOfRowsPerModule()*numberOfColumnsPerModule(); }
  static uint32_t _sizeof() { return 60; }
private:
  uint32_t	_numberOfModules;	/**< The number of modules in a physical camera. */
  uint32_t	_numberOfRowsPerModule;	/**< The number of rows per module. */
  uint32_t	_numberOfColumnsPerModule;	/**< The number of columns per module. */
  uint32_t	_biasVoltage;	/**< The bias applied to the sensor in volts. */
  uint16_t	_gainMode;	/**< The gain mode set for the camera. */
  uint16_t	_speedMode;	/**< The camera clock speed setting. */
  double	_triggerDelay;	/**< Internal delay from receiving a trigger input until the start of an acquisiton in seconds. */
  double	_exposureTime;	/**< The exposure time in seconds. */
  double	_exposurePeriod;	/**< The period between exposures of the camera. In triggered mode this should be smaller than the trigger period. */
  uint16_t	_vb_ds;	/**< Value of vb_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vb_comp;	/**< Value of vb_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vb_pixbuf;	/**< Value of vb_pixbuf in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vref_ds;	/**< Value of vref_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vref_comp;	/**< Value of vref_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vref_prech;	/**< Value of vref_prech in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vin_com;	/**< Value of vin_com in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vdd_prot;	/**< Value of vdd_prot in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
};
std::ostream& operator<<(std::ostream& str, Jungfrau::ConfigV2::GainMode enval);
std::ostream& operator<<(std::ostream& str, Jungfrau::ConfigV2::SpeedMode enval);
#pragma pack(pop)

/** @class ConfigV3

  
*/

#pragma pack(push,4)

class ConfigV3 {
public:
  enum { TypeId = Pds::TypeId::Id_JungfrauConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 3 /**< XTC type version number */ };
  enum { MaxModulesPerDetector = 8 /**< Defines the maximum number of modules in a Jungfrau detector. */ };
  enum { MaxRowsPerModule = 512 /**< Defines the maximum number of rows in a Jungfrau module. */ };
  enum { MaxColumnsPerModule = 1024 /**< Defines the maximum number of columns in a Jungfrau module. */ };
  enum GainMode {
    Normal = 0,
    FixedGain1 = 1,
    FixedGain2 = 2,
    ForcedGain1 = 3,
    ForcedGain2 = 4,
    HighGain0 = 5,
  };
  enum SpeedMode {
    Quarter = 0,
    Half = 1,
  };
  ConfigV3(uint32_t arg__numberOfModules, uint32_t arg__numberOfRowsPerModule, uint32_t arg__numberOfColumnsPerModule, uint32_t arg__biasVoltage, Jungfrau::ConfigV3::GainMode arg__gainMode, Jungfrau::ConfigV3::SpeedMode arg__speedMode, double arg__triggerDelay, double arg__exposureTime, double arg__exposurePeriod, uint16_t arg__vb_ds, uint16_t arg__vb_comp, uint16_t arg__vb_pixbuf, uint16_t arg__vref_ds, uint16_t arg__vref_comp, uint16_t arg__vref_prech, uint16_t arg__vin_com, uint16_t arg__vdd_prot, const Jungfrau::ModuleConfigV1* arg__moduleConfig);
  ConfigV3() {}
  ConfigV3(const ConfigV3& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
  }
  ConfigV3& operator=(const ConfigV3& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
    return *this;
  }
  /** The number of modules in a physical camera. */
  uint32_t numberOfModules() const { return _numberOfModules; }
  /** The number of rows per module. */
  uint32_t numberOfRowsPerModule() const { return _numberOfRowsPerModule; }
  /** The number of columns per module. */
  uint32_t numberOfColumnsPerModule() const { return _numberOfColumnsPerModule; }
  /** The bias applied to the sensor in volts. */
  uint32_t biasVoltage() const { return _biasVoltage; }
  /** The gain mode set for the camera. */
  Jungfrau::ConfigV3::GainMode gainMode() const { return Jungfrau::ConfigV3::GainMode(_gainMode); }
  /** The camera clock speed setting. */
  Jungfrau::ConfigV3::SpeedMode speedMode() const { return Jungfrau::ConfigV3::SpeedMode(_speedMode); }
  /** Internal delay from receiving a trigger input until the start of an acquisiton in seconds. */
  double triggerDelay() const { return _triggerDelay; }
  /** The exposure time in seconds. */
  double exposureTime() const { return _exposureTime; }
  /** The period between exposures of the camera. In triggered mode this should be smaller than the trigger period. */
  double exposurePeriod() const { return _exposurePeriod; }
  /** Value of vb_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vb_ds() const { return _vb_ds; }
  /** Value of vb_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vb_comp() const { return _vb_comp; }
  /** Value of vb_pixbuf in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vb_pixbuf() const { return _vb_pixbuf; }
  /** Value of vref_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vref_ds() const { return _vref_ds; }
  /** Value of vref_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vref_comp() const { return _vref_comp; }
  /** Value of vref_prech in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vref_prech() const { return _vref_prech; }
  /** Value of vin_com in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vin_com() const { return _vin_com; }
  /** Value of vdd_prot in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vdd_prot() const { return _vdd_prot; }
  /** Module specific configuration information for each of the modules in the detector system. */
  const Jungfrau::ModuleConfigV1& moduleConfig(uint32_t i0) const { return _moduleConfig[i0]; }
  /** Total size in bytes of the Frame object */
  uint32_t frameSize() const;
  /** calculate total frame size in pixels based on the current ROI and binning settings */
  uint32_t numPixels() const { return numberOfModules()*numberOfRowsPerModule()*numberOfColumnsPerModule(); }
  static uint32_t _sizeof() { return ((((60+(Jungfrau::ModuleConfigV1::_sizeof()*(MaxModulesPerDetector)))+4)-1)/4)*4; }
  /** Method which returns the shape (dimensions) of the data returned by moduleConfig() method. */
  std::vector<int> moduleConfig_shape() const;
private:
  uint32_t	_numberOfModules;	/**< The number of modules in a physical camera. */
  uint32_t	_numberOfRowsPerModule;	/**< The number of rows per module. */
  uint32_t	_numberOfColumnsPerModule;	/**< The number of columns per module. */
  uint32_t	_biasVoltage;	/**< The bias applied to the sensor in volts. */
  uint16_t	_gainMode;	/**< The gain mode set for the camera. */
  uint16_t	_speedMode;	/**< The camera clock speed setting. */
  double	_triggerDelay;	/**< Internal delay from receiving a trigger input until the start of an acquisiton in seconds. */
  double	_exposureTime;	/**< The exposure time in seconds. */
  double	_exposurePeriod;	/**< The period between exposures of the camera. In triggered mode this should be smaller than the trigger period. */
  uint16_t	_vb_ds;	/**< Value of vb_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vb_comp;	/**< Value of vb_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vb_pixbuf;	/**< Value of vb_pixbuf in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vref_ds;	/**< Value of vref_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vref_comp;	/**< Value of vref_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vref_prech;	/**< Value of vref_prech in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vin_com;	/**< Value of vin_com in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vdd_prot;	/**< Value of vdd_prot in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  Jungfrau::ModuleConfigV1	_moduleConfig[MaxModulesPerDetector];	/**< Module specific configuration information for each of the modules in the detector system. */
};
std::ostream& operator<<(std::ostream& str, Jungfrau::ConfigV3::GainMode enval);
std::ostream& operator<<(std::ostream& str, Jungfrau::ConfigV3::SpeedMode enval);
#pragma pack(pop)

/** @class ConfigV4

  
*/

#pragma pack(push,4)

class ConfigV4 {
public:
  enum { TypeId = Pds::TypeId::Id_JungfrauConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 4 /**< XTC type version number */ };
  enum { MaxModulesPerDetector = 32 /**< Defines the maximum number of modules in a Jungfrau detector. */ };
  enum { MaxRowsPerModule = 512 /**< Defines the maximum number of rows in a Jungfrau module. */ };
  enum { MaxColumnsPerModule = 1024 /**< Defines the maximum number of columns in a Jungfrau module. */ };
  enum GainMode {
    Normal = 0,
    FixedGain1 = 1,
    FixedGain2 = 2,
    ForcedGain1 = 3,
    ForcedGain2 = 4,
    HighGain0 = 5,
  };
  enum SpeedMode {
    Quarter = 0,
    Half = 1,
  };
  ConfigV4(uint32_t arg__numberOfModules, uint32_t arg__numberOfRowsPerModule, uint32_t arg__numberOfColumnsPerModule, uint32_t arg__biasVoltage, Jungfrau::ConfigV4::GainMode arg__gainMode, Jungfrau::ConfigV4::SpeedMode arg__speedMode, double arg__triggerDelay, double arg__exposureTime, double arg__exposurePeriod, uint16_t arg__vb_ds, uint16_t arg__vb_comp, uint16_t arg__vb_pixbuf, uint16_t arg__vref_ds, uint16_t arg__vref_comp, uint16_t arg__vref_prech, uint16_t arg__vin_com, uint16_t arg__vdd_prot, const Jungfrau::ModuleConfigV1* arg__moduleConfig);
  ConfigV4() {}
  ConfigV4(const ConfigV4& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
  }
  ConfigV4& operator=(const ConfigV4& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
    return *this;
  }
  /** The number of modules in a physical camera. */
  uint32_t numberOfModules() const { return _numberOfModules; }
  /** The number of rows per module. */
  uint32_t numberOfRowsPerModule() const { return _numberOfRowsPerModule; }
  /** The number of columns per module. */
  uint32_t numberOfColumnsPerModule() const { return _numberOfColumnsPerModule; }
  /** The bias applied to the sensor in volts. */
  uint32_t biasVoltage() const { return _biasVoltage; }
  /** The gain mode set for the camera. */
  Jungfrau::ConfigV4::GainMode gainMode() const { return Jungfrau::ConfigV4::GainMode(_gainMode); }
  /** The camera clock speed setting. */
  Jungfrau::ConfigV4::SpeedMode speedMode() const { return Jungfrau::ConfigV4::SpeedMode(_speedMode); }
  /** Internal delay from receiving a trigger input until the start of an acquisiton in seconds. */
  double triggerDelay() const { return _triggerDelay; }
  /** The exposure time in seconds. */
  double exposureTime() const { return _exposureTime; }
  /** The period between exposures of the camera. In triggered mode this should be smaller than the trigger period. */
  double exposurePeriod() const { return _exposurePeriod; }
  /** Value of vb_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vb_ds() const { return _vb_ds; }
  /** Value of vb_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vb_comp() const { return _vb_comp; }
  /** Value of vb_pixbuf in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vb_pixbuf() const { return _vb_pixbuf; }
  /** Value of vref_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vref_ds() const { return _vref_ds; }
  /** Value of vref_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vref_comp() const { return _vref_comp; }
  /** Value of vref_prech in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vref_prech() const { return _vref_prech; }
  /** Value of vin_com in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vin_com() const { return _vin_com; }
  /** Value of vdd_prot in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t vdd_prot() const { return _vdd_prot; }
  /** Module specific configuration information for each of the modules in the detector system. */
  const Jungfrau::ModuleConfigV1& moduleConfig(uint32_t i0) const { return _moduleConfig[i0]; }
  /** Total size in bytes of the Frame object */
  uint32_t frameSize() const;
  /** calculate total frame size in pixels based on the current ROI and binning settings */
  uint32_t numPixels() const { return numberOfModules()*numberOfRowsPerModule()*numberOfColumnsPerModule(); }
  static uint32_t _sizeof() { return ((((60+(Jungfrau::ModuleConfigV1::_sizeof()*(MaxModulesPerDetector)))+4)-1)/4)*4; }
  /** Method which returns the shape (dimensions) of the data returned by moduleConfig() method. */
  std::vector<int> moduleConfig_shape() const;
private:
  uint32_t	_numberOfModules;	/**< The number of modules in a physical camera. */
  uint32_t	_numberOfRowsPerModule;	/**< The number of rows per module. */
  uint32_t	_numberOfColumnsPerModule;	/**< The number of columns per module. */
  uint32_t	_biasVoltage;	/**< The bias applied to the sensor in volts. */
  uint16_t	_gainMode;	/**< The gain mode set for the camera. */
  uint16_t	_speedMode;	/**< The camera clock speed setting. */
  double	_triggerDelay;	/**< Internal delay from receiving a trigger input until the start of an acquisiton in seconds. */
  double	_exposureTime;	/**< The exposure time in seconds. */
  double	_exposurePeriod;	/**< The period between exposures of the camera. In triggered mode this should be smaller than the trigger period. */
  uint16_t	_vb_ds;	/**< Value of vb_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vb_comp;	/**< Value of vb_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vb_pixbuf;	/**< Value of vb_pixbuf in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vref_ds;	/**< Value of vref_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vref_comp;	/**< Value of vref_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vref_prech;	/**< Value of vref_prech in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vin_com;	/**< Value of vin_com in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t	_vdd_prot;	/**< Value of vdd_prot in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  Jungfrau::ModuleConfigV1	_moduleConfig[MaxModulesPerDetector];	/**< Module specific configuration information for each of the modules in the detector system. */
};
std::ostream& operator<<(std::ostream& str, Jungfrau::ConfigV4::GainMode enval);
std::ostream& operator<<(std::ostream& str, Jungfrau::ConfigV4::SpeedMode enval);
#pragma pack(pop)

/** @class ModuleInfoV1

  
*/

#pragma pack(push,2)

class ModuleInfoV1 {
public:
  ModuleInfoV1(uint64_t arg__timestamp, uint32_t arg__exposureTime, uint16_t arg__moduleID, uint16_t arg__xCoord, uint16_t arg__yCoord, uint16_t arg__zCoord);
  ModuleInfoV1() {}
  ModuleInfoV1(const ModuleInfoV1& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
  }
  ModuleInfoV1& operator=(const ModuleInfoV1& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
    return *this;
  }
  /** The camera timestamp associated with the detector frame in 100 ns ticks. */
  uint64_t timestamp() const { return _timestamp; }
  /** The actual exposure time of the image in 100 ns ticks. */
  uint32_t exposureTime() const { return _exposureTime; }
  /** The unique module ID number. */
  uint16_t moduleID() const { return _moduleID; }
  /** The X coordinate in the complete detector system. */
  uint16_t xCoord() const { return _xCoord; }
  /** The Y coordinate in the complete detector system. */
  uint16_t yCoord() const { return _yCoord; }
  /** The Z coordinate in the complete detector system. */
  uint16_t zCoord() const { return _zCoord; }
  static uint32_t _sizeof() { return 20; }
private:
  uint64_t	_timestamp;	/**< The camera timestamp associated with the detector frame in 100 ns ticks. */
  uint32_t	_exposureTime;	/**< The actual exposure time of the image in 100 ns ticks. */
  uint16_t	_moduleID;	/**< The unique module ID number. */
  uint16_t	_xCoord;	/**< The X coordinate in the complete detector system. */
  uint16_t	_yCoord;	/**< The Y coordinate in the complete detector system. */
  uint16_t	_zCoord;	/**< The Z coordinate in the complete detector system. */
};
#pragma pack(pop)

/** @class ElementV1

  
*/

class ConfigV1;
class ConfigV2;
class ConfigV3;
class ConfigV4;
#pragma pack(push,2)

class ElementV1 {
public:
  enum { TypeId = Pds::TypeId::Id_JungfrauElement /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  ElementV1() {}
private:
  ElementV1(const ElementV1&);
  ElementV1& operator=(const ElementV1&);
public:
  /** The internal frame counter number of the detector. */
  uint32_t frameNumber() const { return _frameNumber; }
  /** The LCLS timing tick associated with the detector frame. */
  uint32_t ticks() const { return _ticks; }
  /** The LCLS timing fiducial associated with the detector frame. */
  uint32_t fiducials() const { return _fiducials; }
  /**     Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV1& cfg, const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=12;
    const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const uint16_t>(owner, data), cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule());
  }
  /**     Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV2& cfg, const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=12;
    const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const uint16_t>(owner, data), cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule());
  }
  /**     Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV3& cfg, const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=12;
    const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const uint16_t>(owner, data), cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule());
  }
  /**     Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV4& cfg, const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=12;
    const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const uint16_t>(owner, data), cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule());
  }
  /**     Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV1& cfg) const { ptrdiff_t offset=12;
  const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
  return make_ndarray(data, cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule()); }
  /**     Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV2& cfg) const { ptrdiff_t offset=12;
  const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
  return make_ndarray(data, cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule()); }
  /**     Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV3& cfg) const { ptrdiff_t offset=12;
  const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
  return make_ndarray(data, cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule()); }
  /**     Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV4& cfg) const { ptrdiff_t offset=12;
  const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
  return make_ndarray(data, cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule()); }
  static uint32_t _sizeof(const Jungfrau::ConfigV1& cfg) { return ((((12+(2*(cfg.numberOfModules())*(cfg.numberOfRowsPerModule())*(cfg.numberOfColumnsPerModule())))+2)-1)/2)*2; }
  static uint32_t _sizeof(const Jungfrau::ConfigV2& cfg) { return ((((12+(2*(cfg.numberOfModules())*(cfg.numberOfRowsPerModule())*(cfg.numberOfColumnsPerModule())))+2)-1)/2)*2; }
  static uint32_t _sizeof(const Jungfrau::ConfigV3& cfg) { return ((((12+(2*(cfg.numberOfModules())*(cfg.numberOfRowsPerModule())*(cfg.numberOfColumnsPerModule())))+2)-1)/2)*2; }
  static uint32_t _sizeof(const Jungfrau::ConfigV4& cfg) { return ((((12+(2*(cfg.numberOfModules())*(cfg.numberOfRowsPerModule())*(cfg.numberOfColumnsPerModule())))+2)-1)/2)*2; }
private:
  uint32_t	_frameNumber;	/**< The internal frame counter number of the detector. */
  uint32_t	_ticks;	/**< The LCLS timing tick associated with the detector frame. */
  uint32_t	_fiducials;	/**< The LCLS timing fiducial associated with the detector frame. */
  //uint16_t	_frame[cfg.numberOfModules()][cfg.numberOfRowsPerModule()][cfg.numberOfColumnsPerModule()];
};
#pragma pack(pop)

/** @class ElementV2

  
*/

class ConfigV1;
class ConfigV2;
class ConfigV3;
class ConfigV4;
#pragma pack(push,2)

class ElementV2 {
public:
  enum { TypeId = Pds::TypeId::Id_JungfrauElement /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  ElementV2(uint64_t frameNumber, uint32_t ticks, uint32_t fiducials)
    : _frameNumber(frameNumber), _ticks(ticks), _fiducials(fiducials)
  {
  }
  ElementV2() {}
private:
  ElementV2(const ElementV2&);
  ElementV2& operator=(const ElementV2&);
public:
  /** The internal frame counter number of the detector. */
  uint64_t frameNumber() const { return _frameNumber; }
  /** The LCLS timing tick associated with the detector frame. */
  uint32_t ticks() const { return _ticks; }
  /** The LCLS timing fiducial associated with the detector frame. */
  uint32_t fiducials() const { return _fiducials; }
  /** Information about each of the modules in the detector system. */
  const Jungfrau::ModuleInfoV1& moduleInfo(uint32_t i0) const { ptrdiff_t offset=16;
  const Jungfrau::ModuleInfoV1* memptr = (const Jungfrau::ModuleInfoV1*)(((const char*)this)+offset);
  size_t memsize = memptr->_sizeof();
  return *(const Jungfrau::ModuleInfoV1*)((const char*)memptr + (i0)*memsize); }
  /**     Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV1& cfg, const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=16+(20*(cfg.numberOfModules()));
    const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const uint16_t>(owner, data), cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule());
  }
  /**     Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV2& cfg, const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=16+(20*(cfg.numberOfModules()));
    const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const uint16_t>(owner, data), cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule());
  }
  /**     Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV3& cfg, const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=16+(20*(cfg.numberOfModules()));
    const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const uint16_t>(owner, data), cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule());
  }
  /**     Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV4& cfg, const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=16+(20*(cfg.numberOfModules()));
    const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const uint16_t>(owner, data), cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule());
  }
  /**     Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV1& cfg) const { ptrdiff_t offset=16+(20*(cfg.numberOfModules()));
  const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
  return make_ndarray(data, cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule()); }
  /**     Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV2& cfg) const { ptrdiff_t offset=16+(20*(cfg.numberOfModules()));
  const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
  return make_ndarray(data, cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule()); }
  /**     Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV3& cfg) const { ptrdiff_t offset=16+(20*(cfg.numberOfModules()));
  const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
  return make_ndarray(data, cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule()); }
  /**     Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const uint16_t, 3> frame(const Jungfrau::ConfigV4& cfg) const { ptrdiff_t offset=16+(20*(cfg.numberOfModules()));
  const uint16_t* data = (const uint16_t*)(((char*)this)+offset);
  return make_ndarray(data, cfg.numberOfModules(), cfg.numberOfRowsPerModule(), cfg.numberOfColumnsPerModule()); }
  static uint32_t _sizeof(const Jungfrau::ConfigV1& cfg) { return (((((16+(Jungfrau::ModuleInfoV1::_sizeof()*(cfg.numberOfModules())))+(2*(cfg.numberOfModules())*(cfg.numberOfRowsPerModule())*(cfg.numberOfColumnsPerModule())))+2)-1)/2)*2; }
  static uint32_t _sizeof(const Jungfrau::ConfigV2& cfg) { return (((((16+(Jungfrau::ModuleInfoV1::_sizeof()*(cfg.numberOfModules())))+(2*(cfg.numberOfModules())*(cfg.numberOfRowsPerModule())*(cfg.numberOfColumnsPerModule())))+2)-1)/2)*2; }
  static uint32_t _sizeof(const Jungfrau::ConfigV3& cfg) { return (((((16+(Jungfrau::ModuleInfoV1::_sizeof()*(cfg.numberOfModules())))+(2*(cfg.numberOfModules())*(cfg.numberOfRowsPerModule())*(cfg.numberOfColumnsPerModule())))+2)-1)/2)*2; }
  static uint32_t _sizeof(const Jungfrau::ConfigV4& cfg) { return (((((16+(Jungfrau::ModuleInfoV1::_sizeof()*(cfg.numberOfModules())))+(2*(cfg.numberOfModules())*(cfg.numberOfRowsPerModule())*(cfg.numberOfColumnsPerModule())))+2)-1)/2)*2; }
  /** Method which returns the shape (dimensions) of the data returned by moduleInfo() method. */
  std::vector<int> moduleInfo_shape(const Jungfrau::ConfigV1& cfg) const;
  /** Method which returns the shape (dimensions) of the data returned by moduleInfo() method. */
  std::vector<int> moduleInfo_shape(const Jungfrau::ConfigV2& cfg) const;
  /** Method which returns the shape (dimensions) of the data returned by moduleInfo() method. */
  std::vector<int> moduleInfo_shape(const Jungfrau::ConfigV3& cfg) const;
  /** Method which returns the shape (dimensions) of the data returned by moduleInfo() method. */
  std::vector<int> moduleInfo_shape(const Jungfrau::ConfigV4& cfg) const;
private:
  uint64_t	_frameNumber;	/**< The internal frame counter number of the detector. */
  uint32_t	_ticks;	/**< The LCLS timing tick associated with the detector frame. */
  uint32_t	_fiducials;	/**< The LCLS timing fiducial associated with the detector frame. */
  //Jungfrau::ModuleInfoV1	_moduleInfo[cfg.numberOfModules()];
  //uint16_t	_frame[cfg.numberOfModules()][cfg.numberOfRowsPerModule()][cfg.numberOfColumnsPerModule()];
};
#pragma pack(pop)
} // namespace Jungfrau
} // namespace Pds
#endif // PDS_JUNGFRAU_DDL_H
