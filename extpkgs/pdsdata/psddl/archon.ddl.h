#ifndef PDS_ARCHON_DDL_H
#define PDS_ARCHON_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <iosfwd>
#include <cstddef>
#include <cstring>
#include "pdsdata/xtc/TypeId.hh"
#include "ndarray/ndarray.h"
namespace Pds {
namespace Archon {

/** @class ConfigV1

  Class containing configuration data for CCDs using the Archon controller.
*/


class ConfigV1 {
public:
  enum { TypeId = Pds::TypeId::Id_ArchonConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  enum { FILENAME_CHAR_MAX = 256 };
  enum ReadoutMode {
    Single = 0,
    Continuous = 1,
    Triggered = 2,
  };
  ConfigV1(Archon::ConfigV1::ReadoutMode arg__readoutMode, uint16_t arg__sweepCount, uint32_t arg__integrationTime, uint32_t arg__nonIntegrationTime, uint32_t arg__preSkipPixels, uint32_t arg__pixels, uint32_t arg__postSkipPixels, uint32_t arg__overscanPixels, uint16_t arg__preSkipLines, uint16_t arg__lines, uint16_t arg__postSkipLines, uint16_t arg__overScanLines, uint16_t arg__horizontalBinning, uint16_t arg__verticalBinning, uint16_t arg__rgh, uint16_t arg__rgl, uint16_t arg__shp, uint16_t arg__shd, uint16_t arg__st, uint16_t arg__stm1, uint16_t arg__at, uint16_t arg__dwell1, uint16_t arg__dwell2, int16_t arg__rgHigh, int16_t arg__rgLow, int16_t arg__sHigh, int16_t arg__sLow, int16_t arg__aHigh, int16_t arg__aLow, int16_t arg__rgSlew, int16_t arg__sSlew, int16_t arg__aSlew, const char* arg__config);
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
  Archon::ConfigV1::ReadoutMode readoutMode() const { return Archon::ConfigV1::ReadoutMode(_readoutMode); }
  uint16_t sweepCount() const { return _sweepCount; }
  uint32_t integrationTime() const { return _integrationTime; }
  uint32_t nonIntegrationTime() const { return _nonIntegrationTime; }
  uint32_t preSkipPixels() const { return _preSkipPixels; }
  uint32_t pixels() const { return _pixels; }
  uint32_t postSkipPixels() const { return _postSkipPixels; }
  uint32_t overscanPixels() const { return _overscanPixels; }
  uint16_t preSkipLines() const { return _preSkipLines; }
  uint16_t lines() const { return _lines; }
  uint16_t postSkipLines() const { return _postSkipLines; }
  uint16_t overScanLines() const { return _overScanLines; }
  uint16_t horizontalBinning() const { return _horizontalBinning; }
  uint16_t verticalBinning() const { return _verticalBinning; }
  uint16_t rgh() const { return _rgh; }
  uint16_t rgl() const { return _rgl; }
  uint16_t shp() const { return _shp; }
  uint16_t shd() const { return _shd; }
  uint16_t st() const { return _st; }
  uint16_t stm1() const { return _stm1; }
  uint16_t at() const { return _at; }
  uint16_t dwell1() const { return _dwell1; }
  uint16_t dwell2() const { return _dwell2; }
  int16_t rgHigh() const { return _rgHigh; }
  int16_t rgLow() const { return _rgLow; }
  int16_t sHigh() const { return _sHigh; }
  int16_t sLow() const { return _sLow; }
  int16_t aHigh() const { return _aHigh; }
  int16_t aLow() const { return _aLow; }
  int16_t rgSlew() const { return _rgSlew; }
  int16_t sSlew() const { return _sSlew; }
  int16_t aSlew() const { return _aSlew; }
  /** The path to an acf file to use with the camera. */
  const char* config() const { return _config; }
  static uint32_t _sizeof() { return ((((76+(1*(FILENAME_CHAR_MAX)))+4)-1)/4)*4; }
private:
  uint16_t	_readoutMode;
  uint16_t	_sweepCount;
  uint32_t	_integrationTime;
  uint32_t	_nonIntegrationTime;
  uint32_t	_preSkipPixels;
  uint32_t	_pixels;
  uint32_t	_postSkipPixels;
  uint32_t	_overscanPixels;
  uint16_t	_preSkipLines;
  uint16_t	_lines;
  uint16_t	_postSkipLines;
  uint16_t	_overScanLines;
  uint16_t	_horizontalBinning;
  uint16_t	_verticalBinning;
  uint16_t	_rgh;
  uint16_t	_rgl;
  uint16_t	_shp;
  uint16_t	_shd;
  uint16_t	_st;
  uint16_t	_stm1;
  uint16_t	_at;
  uint16_t	_dwell1;
  uint16_t	_dwell2;
  int16_t	_rgHigh;
  int16_t	_rgLow;
  int16_t	_sHigh;
  int16_t	_sLow;
  int16_t	_aHigh;
  int16_t	_aLow;
  int16_t	_rgSlew;
  int16_t	_sSlew;
  int16_t	_aSlew;
  char	_config[FILENAME_CHAR_MAX];	/**< The path to an acf file to use with the camera. */
};
std::ostream& operator<<(std::ostream& str, Archon::ConfigV1::ReadoutMode enval);

/** @class ConfigV2

  Class containing configuration data for CCDs using the Archon controller.
*/


class ConfigV2 {
public:
  enum { TypeId = Pds::TypeId::Id_ArchonConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  enum { MaxConfigLines = 1<<14 };
  enum { MaxConfigLineLength = 2048 };
  enum ReadoutMode {
    Single = 0,
    Continuous = 1,
    Triggered = 2,
  };
  ConfigV2(Archon::ConfigV2::ReadoutMode arg__readoutMode, uint16_t arg__exposureEventCode, uint32_t arg__configSize, uint32_t arg__preFrameSweepCount, uint32_t arg__idleSweepCount, uint32_t arg__integrationTime, uint32_t arg__nonIntegrationTime, uint32_t arg__batches, uint32_t arg__pixels, uint32_t arg__lines, uint32_t arg__horizontalBinning, uint32_t arg__verticalBinning, uint32_t arg__sensorPixels, uint32_t arg__sensorLines, uint32_t arg__sensorTaps, uint32_t arg__st, uint32_t arg__stm1, uint32_t arg__at, const char* arg__config);
  ConfigV2(uint32_t configSize)
    : _configSize(configSize)
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
  /** Readout mode of the camera, a.k.a. software vs hardware triggered. */
  Archon::ConfigV2::ReadoutMode readoutMode() const { return Archon::ConfigV2::ReadoutMode(_readoutMode); }
  /** The event code to use for exposure when software triggering the camera. */
  uint16_t exposureEventCode() const { return _exposureEventCode; }
  /** The size of the acf file portion of the configuration. */
  uint32_t configSize() const { return _configSize; }
  /** The count of lines to sweep before beginning a frame. */
  uint32_t preFrameSweepCount() const { return _preFrameSweepCount; }
  /** The number of lines to sweep per cycle when waiting for triggers. */
  uint32_t idleSweepCount() const { return _idleSweepCount; }
  /** The time (ms) to expose the sensor. */
  uint32_t integrationTime() const { return _integrationTime; }
  /** The time (ms) to wait after exposing the sensor before reading it out. */
  uint32_t nonIntegrationTime() const { return _nonIntegrationTime; }
  /** The number of frames to batch together for readout. */
  uint32_t batches() const { return _batches; }
  /** The number of pixels to readout from each tap. */
  uint32_t pixels() const { return _pixels; }
  /** The number of lines to readout from each tap. */
  uint32_t lines() const { return _lines; }
  /** The horizontal binning setting. */
  uint32_t horizontalBinning() const { return _horizontalBinning; }
  /** The vertical binning setting. */
  uint32_t verticalBinning() const { return _verticalBinning; }
  /** Number of actual pixels per tap. */
  uint32_t sensorPixels() const { return _sensorPixels; }
  /** Number of actual lines per tap. */
  uint32_t sensorLines() const { return _sensorLines; }
  /** Number of taps for the sensor. */
  uint32_t sensorTaps() const { return _sensorTaps; }
  uint32_t st() const { return _st; }
  uint32_t stm1() const { return _stm1; }
  uint32_t at() const { return _at; }
  /** The contents of the acf file to use with the camera. */
  const char* config() const { typedef char atype;
  ptrdiff_t offset=68;
  const atype* pchar = (const atype*)(((const char*)this)+offset);
  return pchar; }
  uint32_t _sizeof() const { return ((((68+(1*(this->configSize())))+4)-1)/4)*4; }
  /** Method which returns the shape (dimensions) of the data returned by config() method. */
  std::vector<int> config_shape() const;
private:
  uint16_t	_readoutMode;	/**< Readout mode of the camera, a.k.a. software vs hardware triggered. */
  uint16_t	_exposureEventCode;	/**< The event code to use for exposure when software triggering the camera. */
  uint32_t	_configSize;	/**< The size of the acf file portion of the configuration. */
  uint32_t	_preFrameSweepCount;	/**< The count of lines to sweep before beginning a frame. */
  uint32_t	_idleSweepCount;	/**< The number of lines to sweep per cycle when waiting for triggers. */
  uint32_t	_integrationTime;	/**< The time (ms) to expose the sensor. */
  uint32_t	_nonIntegrationTime;	/**< The time (ms) to wait after exposing the sensor before reading it out. */
  uint32_t	_batches;	/**< The number of frames to batch together for readout. */
  uint32_t	_pixels;	/**< The number of pixels to readout from each tap. */
  uint32_t	_lines;	/**< The number of lines to readout from each tap. */
  uint32_t	_horizontalBinning;	/**< The horizontal binning setting. */
  uint32_t	_verticalBinning;	/**< The vertical binning setting. */
  uint32_t	_sensorPixels;	/**< Number of actual pixels per tap. */
  uint32_t	_sensorLines;	/**< Number of actual lines per tap. */
  uint32_t	_sensorTaps;	/**< Number of taps for the sensor. */
  uint32_t	_st;
  uint32_t	_stm1;
  uint32_t	_at;
  //char	_config[this->configSize()];
};
std::ostream& operator<<(std::ostream& str, Archon::ConfigV2::ReadoutMode enval);

/** @class ConfigV3

  
*/


class ConfigV3 {
public:
  enum { TypeId = Pds::TypeId::Id_ArchonConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 3 /**< XTC type version number */ };
  enum { MaxConfigLines = 1<<14 };
  enum { MaxConfigLineLength = 2048 };
  enum ReadoutMode {
    FreeRun = 0,
    Triggered = 1,
  };
  enum Switch {
    Off = 0,
    On = 1,
  };
  enum BiasChannelId {
    NV4 = -4,
    NV3 = -3,
    NV2 = -2,
    NV1 = -1,
    PV1 = 1,
    PV2 = 2,
    PV3 = 3,
    PV4 = 4,
  };
  ConfigV3(Archon::ConfigV3::ReadoutMode arg__readoutMode, Archon::ConfigV3::Switch arg__power, uint16_t arg__exposureEventCode, uint32_t arg__configSize, uint32_t arg__preFrameSweepCount, uint32_t arg__idleSweepCount, uint32_t arg__integrationTime, uint32_t arg__nonIntegrationTime, uint32_t arg__batches, uint32_t arg__pixels, uint32_t arg__lines, uint32_t arg__horizontalBinning, uint32_t arg__verticalBinning, uint32_t arg__sensorPixels, uint32_t arg__sensorLines, uint32_t arg__sensorTaps, uint32_t arg__st, uint32_t arg__stm1, uint32_t arg__at, Archon::ConfigV3::Switch arg__bias, Archon::ConfigV3::BiasChannelId arg__biasChan, float arg__biasVoltage, uint32_t arg__configVersion, const char* arg__config);
  ConfigV3(uint32_t configSize)
    : _configSize(configSize)
  {
  }
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
  /** Readout mode of the camera, a.k.a. software vs hardware triggered. */
  Archon::ConfigV3::ReadoutMode readoutMode() const { return Archon::ConfigV3::ReadoutMode(_readoutMode); }
  /** The state of the ccd power, a.k.a off vs on. */
  Archon::ConfigV3::Switch power() const { return Archon::ConfigV3::Switch(_power); }
  /** The event code to use for exposure when software triggering the camera. */
  uint16_t exposureEventCode() const { return _exposureEventCode; }
  /** The size of the acf file portion of the configuration. */
  uint32_t configSize() const { return _configSize; }
  /** The count of lines to sweep before beginning a frame. */
  uint32_t preFrameSweepCount() const { return _preFrameSweepCount; }
  /** The number of lines to sweep per cycle when waiting for triggers. */
  uint32_t idleSweepCount() const { return _idleSweepCount; }
  /** The time (ms) to expose the sensor. */
  uint32_t integrationTime() const { return _integrationTime; }
  /** The time (ms) to wait after exposing the sensor before reading it out. */
  uint32_t nonIntegrationTime() const { return _nonIntegrationTime; }
  /** The number of frames to batch together for readout. */
  uint32_t batches() const { return _batches; }
  /** The number of pixels to readout from each tap. */
  uint32_t pixels() const { return _pixels; }
  /** The number of lines to readout from each tap. */
  uint32_t lines() const { return _lines; }
  /** The horizontal binning setting. */
  uint32_t horizontalBinning() const { return _horizontalBinning; }
  /** The vertical binning setting. */
  uint32_t verticalBinning() const { return _verticalBinning; }
  /** Number of actual pixels per tap. */
  uint32_t sensorPixels() const { return _sensorPixels; }
  /** Number of actual lines per tap. */
  uint32_t sensorLines() const { return _sensorLines; }
  /** Number of taps for the sensor. */
  uint32_t sensorTaps() const { return _sensorTaps; }
  uint32_t st() const { return _st; }
  uint32_t stm1() const { return _stm1; }
  uint32_t at() const { return _at; }
  /** The state of the ccd bias voltage, a.k.a off vs on. */
  Archon::ConfigV3::Switch bias() const { return Archon::ConfigV3::Switch(_bias); }
  /** The channel ID of the bias voltage. */
  Archon::ConfigV3::BiasChannelId biasChan() const { return Archon::ConfigV3::BiasChannelId(_biasChan); }
  /** The bias voltage setpoint. */
  float biasVoltage() const { return _biasVoltage; }
  /** Version tag for the attached acf file. */
  uint32_t configVersion() const { return _configVersion; }
  /** The contents of the acf file to use with the camera. */
  const char* config() const { typedef char atype;
  ptrdiff_t offset=84;
  const atype* pchar = (const atype*)(((const char*)this)+offset);
  return pchar; }
  /** Calculate the frame X size in pixels based on the number of pixels per tap and the number of taps. */
  uint32_t numPixelsX() const { return this->pixels() * this->sensorTaps(); }
  /** calculate frame Y size in pixels based on the number of lines per tap. */
  uint32_t numPixelsY() const { return this->lines(); }
  /** calculate total frame size in pixels. */
  uint32_t numPixels() const { return this->numPixelsX() * this->numPixelsY(); }
  uint32_t _sizeof() const { return ((((84+(1*(this->configSize())))+4)-1)/4)*4; }
  /** Method which returns the shape (dimensions) of the data returned by config() method. */
  std::vector<int> config_shape() const;
private:
  uint16_t	_readoutMode;	/**< Readout mode of the camera, a.k.a. software vs hardware triggered. */
  uint16_t	_power;	/**< The state of the ccd power, a.k.a off vs on. */
  uint16_t	_exposureEventCode;	/**< The event code to use for exposure when software triggering the camera. */
  uint16_t	_pad0;
  uint32_t	_configSize;	/**< The size of the acf file portion of the configuration. */
  uint32_t	_preFrameSweepCount;	/**< The count of lines to sweep before beginning a frame. */
  uint32_t	_idleSweepCount;	/**< The number of lines to sweep per cycle when waiting for triggers. */
  uint32_t	_integrationTime;	/**< The time (ms) to expose the sensor. */
  uint32_t	_nonIntegrationTime;	/**< The time (ms) to wait after exposing the sensor before reading it out. */
  uint32_t	_batches;	/**< The number of frames to batch together for readout. */
  uint32_t	_pixels;	/**< The number of pixels to readout from each tap. */
  uint32_t	_lines;	/**< The number of lines to readout from each tap. */
  uint32_t	_horizontalBinning;	/**< The horizontal binning setting. */
  uint32_t	_verticalBinning;	/**< The vertical binning setting. */
  uint32_t	_sensorPixels;	/**< Number of actual pixels per tap. */
  uint32_t	_sensorLines;	/**< Number of actual lines per tap. */
  uint32_t	_sensorTaps;	/**< Number of taps for the sensor. */
  uint32_t	_st;
  uint32_t	_stm1;
  uint32_t	_at;
  uint16_t	_bias;	/**< The state of the ccd bias voltage, a.k.a off vs on. */
  int16_t	_biasChan;	/**< The channel ID of the bias voltage. */
  float	_biasVoltage;	/**< The bias voltage setpoint. */
  uint32_t	_configVersion;	/**< Version tag for the attached acf file. */
  //char	_config[this->configSize()];
};
std::ostream& operator<<(std::ostream& str, Archon::ConfigV3::ReadoutMode enval);
std::ostream& operator<<(std::ostream& str, Archon::ConfigV3::Switch enval);
std::ostream& operator<<(std::ostream& str, Archon::ConfigV3::BiasChannelId enval);

/** @class ConfigV4

  
*/


class ConfigV4 {
public:
  enum { TypeId = Pds::TypeId::Id_ArchonConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 4 /**< XTC type version number */ };
  enum { MaxConfigLines = 1<<14 };
  enum { MaxConfigLineLength = 2048 };
  enum ReadoutMode {
    FreeRun = 0,
    Triggered = 1,
  };
  enum Switch {
    Off = 0,
    On = 1,
  };
  enum BiasChannelId {
    NV4 = -4,
    NV3 = -3,
    NV2 = -2,
    NV1 = -1,
    PV1 = 1,
    PV2 = 2,
    PV3 = 3,
    PV4 = 4,
  };
  ConfigV4(Archon::ConfigV4::ReadoutMode arg__readoutMode, Archon::ConfigV4::Switch arg__power, uint16_t arg__exposureEventCode, uint32_t arg__configSize, uint32_t arg__preFrameSweepCount, uint32_t arg__idleSweepCount, uint32_t arg__preSkipLines, uint32_t arg__integrationTime, uint32_t arg__nonIntegrationTime, uint32_t arg__batches, uint32_t arg__pixels, uint32_t arg__lines, uint32_t arg__horizontalBinning, uint32_t arg__verticalBinning, uint32_t arg__sensorPixels, uint32_t arg__sensorLines, uint32_t arg__sensorTaps, uint32_t arg__st, uint32_t arg__stm1, uint32_t arg__at, Archon::ConfigV4::Switch arg__bias, Archon::ConfigV4::BiasChannelId arg__biasChan, float arg__biasVoltage, uint32_t arg__configVersion, const char* arg__config);
  ConfigV4(uint32_t configSize)
    : _configSize(configSize)
  {
  }
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
  /** Readout mode of the camera, a.k.a. software vs hardware triggered. */
  Archon::ConfigV4::ReadoutMode readoutMode() const { return Archon::ConfigV4::ReadoutMode(_readoutMode); }
  /** The state of the ccd power, a.k.a off vs on. */
  Archon::ConfigV4::Switch power() const { return Archon::ConfigV4::Switch(_power); }
  /** The event code to use for exposure when software triggering the camera. */
  uint16_t exposureEventCode() const { return _exposureEventCode; }
  /** The size of the acf file portion of the configuration. */
  uint32_t configSize() const { return _configSize; }
  /** The count of lines to sweep before beginning a frame. */
  uint32_t preFrameSweepCount() const { return _preFrameSweepCount; }
  /** The number of lines to sweep per cycle when waiting for triggers. */
  uint32_t idleSweepCount() const { return _idleSweepCount; }
  /** The number of lines to skip before beginning a frame. */
  uint32_t preSkipLines() const { return _preSkipLines; }
  /** The time (ms) to expose the sensor. */
  uint32_t integrationTime() const { return _integrationTime; }
  /** The time (ms) to wait after exposing the sensor before reading it out. */
  uint32_t nonIntegrationTime() const { return _nonIntegrationTime; }
  /** The number of frames to batch together for readout. */
  uint32_t batches() const { return _batches; }
  /** The number of pixels to readout from each tap. */
  uint32_t pixels() const { return _pixels; }
  /** The number of lines to readout from each tap. */
  uint32_t lines() const { return _lines; }
  /** The horizontal binning setting. */
  uint32_t horizontalBinning() const { return _horizontalBinning; }
  /** The vertical binning setting. */
  uint32_t verticalBinning() const { return _verticalBinning; }
  /** Number of actual pixels per tap. */
  uint32_t sensorPixels() const { return _sensorPixels; }
  /** Number of actual lines per tap. */
  uint32_t sensorLines() const { return _sensorLines; }
  /** Number of taps for the sensor. */
  uint32_t sensorTaps() const { return _sensorTaps; }
  uint32_t st() const { return _st; }
  uint32_t stm1() const { return _stm1; }
  uint32_t at() const { return _at; }
  /** The state of the ccd bias voltage, a.k.a off vs on. */
  Archon::ConfigV4::Switch bias() const { return Archon::ConfigV4::Switch(_bias); }
  /** The channel ID of the bias voltage. */
  Archon::ConfigV4::BiasChannelId biasChan() const { return Archon::ConfigV4::BiasChannelId(_biasChan); }
  /** The bias voltage setpoint. */
  float biasVoltage() const { return _biasVoltage; }
  /** Version tag for the attached acf file. */
  uint32_t configVersion() const { return _configVersion; }
  /** The contents of the acf file to use with the camera. */
  const char* config() const { typedef char atype;
  ptrdiff_t offset=88;
  const atype* pchar = (const atype*)(((const char*)this)+offset);
  return pchar; }
  /** Calculate the frame X size in pixels based on the number of pixels per tap and the number of taps. */
  uint32_t numPixelsX() const { return this->pixels() * this->sensorTaps(); }
  /** calculate frame Y size in pixels based on the number of lines per tap. */
  uint32_t numPixelsY() const { return this->lines(); }
  /** calculate total frame size in pixels. */
  uint32_t numPixels() const { return this->numPixelsX() * this->numPixelsY(); }
  uint32_t _sizeof() const { return ((((88+(1*(this->configSize())))+4)-1)/4)*4; }
  /** Method which returns the shape (dimensions) of the data returned by config() method. */
  std::vector<int> config_shape() const;
private:
  uint16_t	_readoutMode;	/**< Readout mode of the camera, a.k.a. software vs hardware triggered. */
  uint16_t	_power;	/**< The state of the ccd power, a.k.a off vs on. */
  uint16_t	_exposureEventCode;	/**< The event code to use for exposure when software triggering the camera. */
  uint16_t	_pad0;
  uint32_t	_configSize;	/**< The size of the acf file portion of the configuration. */
  uint32_t	_preFrameSweepCount;	/**< The count of lines to sweep before beginning a frame. */
  uint32_t	_idleSweepCount;	/**< The number of lines to sweep per cycle when waiting for triggers. */
  uint32_t	_preSkipLines;	/**< The number of lines to skip before beginning a frame. */
  uint32_t	_integrationTime;	/**< The time (ms) to expose the sensor. */
  uint32_t	_nonIntegrationTime;	/**< The time (ms) to wait after exposing the sensor before reading it out. */
  uint32_t	_batches;	/**< The number of frames to batch together for readout. */
  uint32_t	_pixels;	/**< The number of pixels to readout from each tap. */
  uint32_t	_lines;	/**< The number of lines to readout from each tap. */
  uint32_t	_horizontalBinning;	/**< The horizontal binning setting. */
  uint32_t	_verticalBinning;	/**< The vertical binning setting. */
  uint32_t	_sensorPixels;	/**< Number of actual pixels per tap. */
  uint32_t	_sensorLines;	/**< Number of actual lines per tap. */
  uint32_t	_sensorTaps;	/**< Number of taps for the sensor. */
  uint32_t	_st;
  uint32_t	_stm1;
  uint32_t	_at;
  uint16_t	_bias;	/**< The state of the ccd bias voltage, a.k.a off vs on. */
  int16_t	_biasChan;	/**< The channel ID of the bias voltage. */
  float	_biasVoltage;	/**< The bias voltage setpoint. */
  uint32_t	_configVersion;	/**< Version tag for the attached acf file. */
  //char	_config[this->configSize()];
};
std::ostream& operator<<(std::ostream& str, Archon::ConfigV4::ReadoutMode enval);
std::ostream& operator<<(std::ostream& str, Archon::ConfigV4::Switch enval);
std::ostream& operator<<(std::ostream& str, Archon::ConfigV4::BiasChannelId enval);
} // namespace Archon
} // namespace Pds
#endif // PDS_ARCHON_DDL_H
