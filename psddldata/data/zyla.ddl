@include "psddldata/istar.ddl";
@package Zyla {

//------------------ ConfigV1 ------------------
@type ConfigV1
  [[type_id(Id_ZylaConfig, 1)]]
  [[config_type]]
  [[pack(4)]]
{
  @const uint16_t STR_LEN_MAX = 64;

  @enum ATBool (uint8_t) {
    False = 0,
    True  = 1,
  }

  @enum ShutteringMode (uint8_t) {
    Rolling = 0,
    Global  = 1,
  }

  @enum FanSpeed (uint8_t) {
    Off = 0,
    Low = 1,
    On  = 2,
  }

  @enum ReadoutRate (uint8_t) {
    Rate280MHz = 0,
    Rate200MHz = 1,
    Rate100MHz = 2,
    Rate10MHz  = 3,
  }

  @enum TriggerMode (uint8_t) {
    Internal = 0,
    ExternalLevelTransition = 1,
    ExternalStart = 2,
    ExternalExposure = 3,
    Software = 4,
    Advanced = 5,
    External = 6,
  }

  @enum GainMode (uint8_t) {
    HighWellCap12Bit          = 0,
    LowNoise12Bit             = 1,
    LowNoiseHighWellCap16Bit  = 2,
  }

  @enum CoolingSetpoint (uint8_t) {
    Temp_0C = 0,
    Temp_Neg5C = 1,
    Temp_Neg10C = 2,
    Temp_Neg15C = 3,
    Temp_Neg20C = 4,
    Temp_Neg25C = 5,
    Temp_Neg30C = 6,
    Temp_Neg35C = 7,
    Temp_Neg40C = 8,
  }

  ATBool _cooling           -> cooling;
  ATBool _overlap           -> overlap;
  ATBool _noiseFilter       -> noiseFilter;
  ATBool _blemishCorrection -> blemishCorrection;

  ShutteringMode _shutter   -> shutter;
  FanSpeed _fanSpeed        -> fanSpeed;
  ReadoutRate _readoutRate  -> readoutRate;
  TriggerMode _triggerMode  -> triggerMode;
  GainMode _gainMode        -> gainMode;
  CoolingSetpoint _setpoint -> setpoint;
  uint16_t _pad0;

  uint32_t _width   -> width;
  uint32_t _height  -> height;
  uint32_t _orgX    -> orgX;
  uint32_t _orgY    -> orgY;
  uint32_t _binX    -> binX;
  uint32_t _binY    -> binY;

  double _exposureTime    -> exposureTime;
  double _triggerDelay    -> triggerDelay;

  /* Total size in bytes of the Frame object */
  uint32_t frameSize()
  [[language("C++")]] @{ return 12 + @self.numPixels()*2; @}

  /* calculate frame X size in pixels based on the current ROI and binning settings */
  uint32_t numPixelsX()  [[inline]]
  [[language("C++")]] @{ return (width() + binX() - 1) / binX(); @}

  /* calculate frame Y size in pixels based on the current ROI and binning settings */
  uint32_t numPixelsY()  [[inline]]
  [[language("C++")]] @{ return (height() + binY() - 1) / binY(); @}

  /* calculate total frame size in pixels based on the current ROI and binning settings */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{ return numPixelsX()*numPixelsY(); @}

  /* Constructor with values for each attribute */
  @init()  [[auto, inline]];

}

//------------------ FrameV1 ------------------
@type FrameV1
  [[type_id(Id_ZylaFrame, 1)]]
  [[pack(2)]]
  [[config(ConfigV1, iStar.ConfigV1)]]
{
  uint64_t _timestamp -> timestamp; /* The internal camera FPGA clock timestamp for the frame. */
  uint16_t _data[@config.numPixelsY()][@config.numPixelsX()] -> data;

  /* Constructor with values for scalar attributes */
  @init(timestamp -> _timestamp)  [[inline]];
}


} //- @package Zyla
