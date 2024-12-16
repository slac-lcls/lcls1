@package Andor3d  {


//------------------ ConfigV1 ------------------
@type ConfigV1
  [[type_id(Id_Andor3dConfig, 1)]]
  [[config_type]]
  [[pack(4)]]
{
  @enum EnumFanMode (uint8_t) {
    ENUM_FAN_FULL = 0,
    ENUM_FAN_LOW = 1,
    ENUM_FAN_OFF = 2,
    ENUM_FAN_ACQOFF = 3,
    ENUM_FAN_NUM = 4,
  }

  uint32_t _uWidth -> width;
  uint32_t _uHeight -> height;
  uint32_t _uNumSensors -> numSensors;
  uint32_t _uOrgX -> orgX;
  uint32_t _uOrgY -> orgY;
  uint32_t _uBinX -> binX;
  uint32_t _uBinY -> binY;
  float _f32ExposureTime -> exposureTime;
  float _f32CoolingTemp -> coolingTemp;
  EnumFanMode _u8FanMode -> fanMode;
  uint8_t _u8BaselineClamp -> baselineClamp;
  uint8_t _u8HighCapacity -> highCapacity;
  uint8_t _u8GainIndex -> gainIndex;
  uint16_t _u16ReadoutSpeedIndex -> readoutSpeedIndex;
  uint16_t _u16ExposureEventCode -> exposureEventCode;
  uint32_t _u32ExposureStartDelay -> exposureStartDelay;
  uint32_t _u32NumDelayShots -> numDelayShots;

  /* Total size in bytes of the Frame object */
  uint32_t frameSize()
  [[language("C++")]] @{ return 8 + @self.numSensors()*4 + @self.numPixels()*2; @}

  /* calculate frame X size in pixels per sensor based on the current ROI and binning settings */
  uint32_t numPixelsX()  [[inline]]
  [[language("C++")]] @{ return (width() + binX() - 1) / binX(); @}

  /* calculate frame Y size in pixels per sensor based on the current ROI and binning settings */
  uint32_t numPixelsY()  [[inline]]
  [[language("C++")]] @{ return (height() + binY() - 1) / binY(); @}

  /* calculate total frame size in pixels per sensor based on the current ROI and binning settings */
  uint32_t numPixelsPerSensor()  [[inline]]
  [[language("C++")]] @{ return numPixelsX()*numPixelsY(); @}

  /* calculate total frame size in pixels based on the current ROI and binning settings */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{ return numPixelsX()*numPixelsY()*numSensors(); @}

  /* Constructor with values for each attribute */
  @init()  [[auto, inline]];

}


//------------------ FrameV1 ------------------
@type FrameV1
  [[type_id(Id_Andor3dFrame, 1)]]
  [[pack(4)]]
  [[config(ConfigV1)]]
{
  uint32_t _iShotIdStart -> shotIdStart;
  float _fReadoutTime -> readoutTime;
  float _fTemperature[@config.numSensors()] -> temperature;
  uint16_t _data[@config.numSensors()][@config.numPixelsY()][@config.numPixelsX()] -> data;

  /* Constructor with values for scalar attributes */
  @init(iShotIdStart -> _iShotIdStart, fReadoutTime -> _fReadoutTime)  [[inline]];

}
} //- @package Andor3d
