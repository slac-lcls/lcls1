#ifndef PDS_IPIMB_DDL_H
#define PDS_IPIMB_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <iosfwd>
#include <cstddef>
#include <cstring>
#include "pdsdata/xtc/TypeId.hh"
#include "ndarray/ndarray.h"
namespace Pds {
namespace Ipimb {

/** @class ConfigV1

  
*/

#pragma pack(push,4)

class ConfigV1 {
public:
  enum { TypeId = Pds::TypeId::Id_IpimbConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  enum CapacitorValue {
    c_1pF,
    c_100pF,
    c_10nF,
  };
  ConfigV1(uint64_t arg__triggerCounter, uint64_t arg__serialID, uint16_t arg__chargeAmpRange, uint16_t arg__calibrationRange, uint32_t arg__resetLength, uint32_t arg__resetDelay, float arg__chargeAmpRefVoltage, float arg__calibrationVoltage, float arg__diodeBias, uint16_t arg__status, uint16_t arg__errors, uint16_t arg__calStrobeLength, uint32_t arg__trigDelay)
    : _triggerCounter(arg__triggerCounter), _serialID(arg__serialID), _chargeAmpRange(arg__chargeAmpRange), _calibrationRange(arg__calibrationRange), _resetLength(arg__resetLength), _resetDelay(arg__resetDelay), _chargeAmpRefVoltage(arg__chargeAmpRefVoltage), _calibrationVoltage(arg__calibrationVoltage), _diodeBias(arg__diodeBias), _status(arg__status), _errors(arg__errors), _calStrobeLength(arg__calStrobeLength), _trigDelay(arg__trigDelay)
  {
  }
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
  uint64_t triggerCounter() const { return _triggerCounter; }
  uint64_t serialID() const { return _serialID; }
  uint16_t chargeAmpRange() const { return _chargeAmpRange; }
  uint16_t calibrationRange() const { return _calibrationRange; }
  uint32_t resetLength() const { return _resetLength; }
  uint32_t resetDelay() const { return _resetDelay; }
  float chargeAmpRefVoltage() const { return _chargeAmpRefVoltage; }
  float calibrationVoltage() const { return _calibrationVoltage; }
  float diodeBias() const { return _diodeBias; }
  uint16_t status() const { return _status; }
  uint16_t errors() const { return _errors; }
  uint16_t calStrobeLength() const { return _calStrobeLength; }
  uint32_t trigDelay() const { return _trigDelay; }
  /** Returns CapacitorValue enum for given channel number (0..3). */
  Ipimb::ConfigV1::CapacitorValue capacitorValue(uint32_t ch) const { return CapacitorValue((this->chargeAmpRange() >> (ch*2)) & 0x3); }
  /** Returns array of CapacitorValue enums. */
  ndarray<const uint8_t, 1> capacitorValues() const;
  static uint32_t _sizeof() { return 52; }
private:
  uint64_t	_triggerCounter;
  uint64_t	_serialID;
  uint16_t	_chargeAmpRange;
  uint16_t	_calibrationRange;
  uint32_t	_resetLength;
  uint32_t	_resetDelay;
  float	_chargeAmpRefVoltage;
  float	_calibrationVoltage;
  float	_diodeBias;
  uint16_t	_status;
  uint16_t	_errors;
  uint16_t	_calStrobeLength;
  uint16_t	_pad0;
  uint32_t	_trigDelay;
};
std::ostream& operator<<(std::ostream& str, Ipimb::ConfigV1::CapacitorValue enval);
#pragma pack(pop)

/** @class ConfigV2

  
*/

#pragma pack(push,4)

class ConfigV2 {
public:
  enum { TypeId = Pds::TypeId::Id_IpimbConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  enum CapacitorValue {
    c_1pF,
    c_4p7pF,
    c_24pF,
    c_120pF,
    c_620pF,
    c_3p3nF,
    c_10nF,
    expert,
  };
  ConfigV2(uint64_t arg__triggerCounter, uint64_t arg__serialID, uint16_t arg__chargeAmpRange, uint16_t arg__calibrationRange, uint32_t arg__resetLength, uint32_t arg__resetDelay, float arg__chargeAmpRefVoltage, float arg__calibrationVoltage, float arg__diodeBias, uint16_t arg__status, uint16_t arg__errors, uint16_t arg__calStrobeLength, uint32_t arg__trigDelay, uint32_t arg__trigPsDelay, uint32_t arg__adcDelay)
    : _triggerCounter(arg__triggerCounter), _serialID(arg__serialID), _chargeAmpRange(arg__chargeAmpRange), _calibrationRange(arg__calibrationRange), _resetLength(arg__resetLength), _resetDelay(arg__resetDelay), _chargeAmpRefVoltage(arg__chargeAmpRefVoltage), _calibrationVoltage(arg__calibrationVoltage), _diodeBias(arg__diodeBias), _status(arg__status), _errors(arg__errors), _calStrobeLength(arg__calStrobeLength), _trigDelay(arg__trigDelay), _trigPsDelay(arg__trigPsDelay), _adcDelay(arg__adcDelay)
  {
  }
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
  uint64_t triggerCounter() const { return _triggerCounter; }
  uint64_t serialID() const { return _serialID; }
  uint16_t chargeAmpRange() const { return _chargeAmpRange; }
  uint16_t calibrationRange() const { return _calibrationRange; }
  uint32_t resetLength() const { return _resetLength; }
  uint32_t resetDelay() const { return _resetDelay; }
  float chargeAmpRefVoltage() const { return _chargeAmpRefVoltage; }
  float calibrationVoltage() const { return _calibrationVoltage; }
  float diodeBias() const { return _diodeBias; }
  uint16_t status() const { return _status; }
  uint16_t errors() const { return _errors; }
  uint16_t calStrobeLength() const { return _calStrobeLength; }
  uint32_t trigDelay() const { return _trigDelay; }
  uint32_t trigPsDelay() const { return _trigPsDelay; }
  uint32_t adcDelay() const { return _adcDelay; }
  /** Returns CapacitorValue enum for given channel number (0..3). */
  Ipimb::ConfigV2::CapacitorValue capacitorValue(uint32_t ch) const { return CapacitorValue((this->chargeAmpRange() >> (ch*4)) & 0xf); }
  /** Returns array of CapacitorValue enums. */
  ndarray<const uint8_t, 1> capacitorValues() const;
  static uint32_t _sizeof() { return 60; }
private:
  uint64_t	_triggerCounter;
  uint64_t	_serialID;
  uint16_t	_chargeAmpRange;
  uint16_t	_calibrationRange;
  uint32_t	_resetLength;
  uint32_t	_resetDelay;
  float	_chargeAmpRefVoltage;
  float	_calibrationVoltage;
  float	_diodeBias;
  uint16_t	_status;
  uint16_t	_errors;
  uint16_t	_calStrobeLength;
  uint16_t	_pad0;
  uint32_t	_trigDelay;
  uint32_t	_trigPsDelay;
  uint32_t	_adcDelay;
};
std::ostream& operator<<(std::ostream& str, Ipimb::ConfigV2::CapacitorValue enval);
#pragma pack(pop)

/** @class DataV1

  
*/

#pragma pack(push,4)

class DataV1 {
public:
  enum { TypeId = Pds::TypeId::Id_IpimbData /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  DataV1() {}
  DataV1(const DataV1& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
  }
  DataV1& operator=(const DataV1& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
    return *this;
  }
  uint64_t triggerCounter() const { return _triggerCounter; }
  uint16_t config0() const { return _config0; }
  uint16_t config1() const { return _config1; }
  uint16_t config2() const { return _config2; }
  /** Raw counts value returned from channel 0. */
  uint16_t channel0() const { return _channel0; }
  /** Raw counts value returned from channel 1. */
  uint16_t channel1() const { return _channel1; }
  /** Raw counts value returned from channel 2. */
  uint16_t channel2() const { return _channel2; }
  /** Raw counts value returned from channel 3. */
  uint16_t channel3() const { return _channel3; }
  uint16_t checksum() const { return _checksum; }
  /** Value of of channel0() converted to Volts. */
  float channel0Volts() const;
  /** Value of of channel1() converted to Volts. */
  float channel1Volts() const;
  /** Value of of channel2() converted to Volts. */
  float channel2Volts() const;
  /** Value of of channel3() converted to Volts. */
  float channel3Volts() const;
  static uint32_t _sizeof() { return 24; }
private:
  uint64_t	_triggerCounter;
  uint16_t	_config0;
  uint16_t	_config1;
  uint16_t	_config2;
  uint16_t	_channel0;	/**< Raw counts value returned from channel 0. */
  uint16_t	_channel1;	/**< Raw counts value returned from channel 1. */
  uint16_t	_channel2;	/**< Raw counts value returned from channel 2. */
  uint16_t	_channel3;	/**< Raw counts value returned from channel 3. */
  uint16_t	_checksum;
};
#pragma pack(pop)

/** @class DataV2

  
*/

#pragma pack(push,4)

class DataV2 {
public:
  enum { TypeId = Pds::TypeId::Id_IpimbData /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  enum { ipimbAdcRange = 5 };
  enum { ipimbAdcSteps = 65536 };
  DataV2() {}
  DataV2(const DataV2& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
  }
  DataV2& operator=(const DataV2& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
    return *this;
  }
  uint16_t config0() const { return _config0; }
  uint16_t config1() const { return _config1; }
  uint16_t config2() const { return _config2; }
  /** Raw counts value returned from channel 0. */
  uint16_t channel0() const { return _channel0; }
  /** Raw counts value returned from channel 1. */
  uint16_t channel1() const { return _channel1; }
  /** Raw counts value returned from channel 2. */
  uint16_t channel2() const { return _channel2; }
  /** Raw counts value returned from channel 3. */
  uint16_t channel3() const { return _channel3; }
  /** Raw counts value returned from channel 0. */
  uint16_t channel0ps() const { return _channel0ps; }
  /** Raw counts value returned from channel 1. */
  uint16_t channel1ps() const { return _channel1ps; }
  /** Raw counts value returned from channel 2. */
  uint16_t channel2ps() const { return _channel2ps; }
  /** Raw counts value returned from channel 3. */
  uint16_t channel3ps() const { return _channel3ps; }
  uint16_t checksum() const { return _checksum; }
  /** Value of of channel0() converted to Volts. */
  float channel0Volts() const;
  /** Value of of channel1() converted to Volts. */
  float channel1Volts() const;
  /** Value of of channel2() converted to Volts. */
  float channel2Volts() const;
  /** Value of of channel3() converted to Volts. */
  float channel3Volts() const;
  /** Value of of channel0ps() converted to Volts. */
  float channel0psVolts() const;
  /** Value of of channel1ps() converted to Volts. */
  float channel1psVolts() const;
  /** Value of of channel2ps() converted to Volts. */
  float channel2psVolts() const;
  /** Value of of channel3ps() converted to Volts. */
  float channel3psVolts() const;
  /** Trigger counter value. */
  uint64_t triggerCounter() const { 
    return (((_triggerCounter >> 48) & 0x000000000000ffffLL) |
	((_triggerCounter >> 16) & 0x00000000ffff0000LL) |
	((_triggerCounter << 16) & 0x0000ffff00000000LL) |
	((_triggerCounter << 48) & 0xffff000000000000LL)); 
 }
  static uint32_t _sizeof() { return 32; }
private:
  uint64_t	_triggerCounter;
  uint16_t	_config0;
  uint16_t	_config1;
  uint16_t	_config2;
  uint16_t	_channel0;	/**< Raw counts value returned from channel 0. */
  uint16_t	_channel1;	/**< Raw counts value returned from channel 1. */
  uint16_t	_channel2;	/**< Raw counts value returned from channel 2. */
  uint16_t	_channel3;	/**< Raw counts value returned from channel 3. */
  uint16_t	_channel0ps;	/**< Raw counts value returned from channel 0. */
  uint16_t	_channel1ps;	/**< Raw counts value returned from channel 1. */
  uint16_t	_channel2ps;	/**< Raw counts value returned from channel 2. */
  uint16_t	_channel3ps;	/**< Raw counts value returned from channel 3. */
  uint16_t	_checksum;
};
#pragma pack(pop)
} // namespace Ipimb
} // namespace Pds
#endif // PDS_IPIMB_DDL_H