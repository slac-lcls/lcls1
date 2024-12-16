@package Pixis  {

//------------------ ConfigV1 ------------------
@type ConfigV1
  [[type_id(Id_PixisConfig, 1)]]
  [[config_type]]
  [[pack(4)]]
{
  @enum GainMode (uint16_t) {
    Low     = 1,
    Medium  = 2,
    High    = 3,
  }

  @enum AdcMode (uint16_t) {
    LowNoise      = 1,
    HighCapacity  = 2,
  }

  @enum TriggerMode (uint16_t) {
    Software              = 0,
    External              = 1,
    ExternalWithCleaning  = 2,
  }

  uint32_t _width                   -> width;
  uint32_t _height                  -> height;
  uint32_t _orgX                    -> orgX;
  uint32_t _orgY                    -> orgY;
  uint32_t _binX                    -> binX;
  uint32_t _binY                    -> binY;

  /* Detector exposure time in seconds. */
  float    _exposureTime            -> exposureTime;
  /* Detector cooler setpoint temperature in degrees Celsius. */
  float    _coolingTemp             -> coolingTemp;
  /* Detector ADC digitization speed in MHz. */
  float    _readoutSpeed            -> readoutSpeed;
  /* Enum of the available gain settings of the detector. */
  GainMode _gainMode                -> gainMode;
  /* Enum of the available ADC Quality settings of the detector. */
  AdcMode  _adcMode                 -> adcMode;
  /* Trigger setting for the detector. */
  TriggerMode _triggerMode          -> triggerMode;
  uint16_t _pad0;

  /* Detector active width in columns. */
  uint32_t _activeWidth             -> activeWidth;
  /* Detector active height in rows. */
  uint32_t _activeHeight            -> activeHeight;
  /* Number of inactive rows at the top of the sensor. */ 
  uint32_t _activeTopMargin         -> activeTopMargin;
  /* Number of inactive rows at the top of the sensor. */
  uint32_t _activeBottomMargin      -> activeBottomMargin;
  /* Number of inactive columns at the left of the sensor. */
  uint32_t _activeLeftMargin        -> activeLeftMargin;
  /* Number of inactive columns at the right of the sensor. */
  uint32_t _activeRightMargin       -> activeRightMargin;

  /* The number of clean cycles to run before acquisition begins. */
  uint32_t _cleanCycleCount         -> cleanCycleCount;
  /* The number of rows in a clean cycle. */
  uint32_t _cleanCycleHeight        -> cleanCycleHeight;
  /* The final height rows for exponential decomposition cleaning. */
  uint32_t _cleanFinalHeight        -> cleanFinalHeight;
  /* The final height iterations for exponential decomposition cleaning. */
  uint32_t _cleanFinalHeightCount   -> cleanFinalHeightCount;

  uint32_t _maskedHeight            -> maskedHeight;
  uint32_t _kineticHeight           -> kineticHeight;
  /* Detector vertical shift speed. */
  float    _vsSpeed                 -> vsSpeed;

  int16_t  _infoReportInterval      -> infoReportInterval;
  uint16_t _exposureEventCode       -> exposureEventCode;
  uint32_t _numIntegrationShots     -> numIntegrationShots;

  /* Total size in bytes of the Frame object */
  uint32_t frameSize()
  [[language("C++")]] @{ return 12 + @self.numPixels()*2; @}

  /* calculate frame X size in pixels based on the current ROI and binning settings */
  uint32_t numPixelsX()  [[inline]]
  [[language("C++")]] @{ return (@self.width() + @self.binX() - 1) / @self.binX(); @}

  /* calculate frame Y size in pixels based on the current ROI and binning settings */
  uint32_t numPixelsY()  [[inline]]
  [[language("C++")]] @{ return (@self.height()+ @self.binY() - 1) / @self.binY(); @}

  /* calculate total frame size in pixels based on the current ROI and binning settings */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{
    return ((@self.width() + @self.binX()-1)/ @self.binX() )*((@self.height()+ @self.binY()-1)/ @self.binY() );
  @}

  /* Constructor which takes values for each attribute */
  @init()  [[auto, inline]];

  /* Constructor which takes values for each attribute */
  @init(width -> _width, height -> _height)  [[inline]];

}

//------------------ FrameV1 ------------------
@type FrameV1
  [[type_id(Id_PixisFrame, 1)]]
  [[pack(4)]]
  [[config(ConfigV1)]]
{
  uint32_t  _iShotIdStart -> shotIdStart;
  float     _fReadoutTime -> readoutTime;
  float     _fTemperature -> temperature;
  uint16_t _data[@config.numPixelsY()][@config.numPixelsX()] -> data;

  /* Constructor with values for scalar attributes */
  @init(iShotIdStart -> _iShotIdStart, fReadoutTime -> _fReadoutTime, fTemperature -> _fTemperature)  [[inline]];

}

} //- @package Pixis
