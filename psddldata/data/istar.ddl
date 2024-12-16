@package iStar {

//------------------ ConfigV1 ------------------
@type ConfigV1
  [[type_id(Id_iStarConfig, 1)]]
  [[config_type]]
  [[pack(4)]]
{
  @const uint16_t STR_LEN_MAX = 64;

  @enum ATBool (uint8_t) {
    False = 0,
    True  = 1,
  }

  @enum FanSpeed (uint8_t) {
    Off = 0,
    On  = 1,
  }

  @enum ReadoutRate (uint8_t) {
    Rate280MHz = 0,
    Rate100MHz = 1,
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

  @enum GateMode (uint8_t) {
    CWOn        = 0,
    CWOff       = 1,
    FireOnly    = 2,
    GateOnly    = 3,
    FireAndGate = 4,
    DDG         = 5,
  }

  @enum InsertionDelay (uint8_t) {
    Normal = 0,
    Fast   = 1,
  }

  ATBool _cooling           -> cooling;
  ATBool _overlap           -> overlap;
  ATBool _noiseFilter       -> noiseFilter;
  ATBool _blemishCorrection -> blemishCorrection;
  ATBool _mcpIntelligate    -> mcpIntelligate;

  FanSpeed       _fanSpeed       -> fanSpeed;
  ReadoutRate    _readoutRate    -> readoutRate;
  TriggerMode    _triggerMode    -> triggerMode;
  GainMode       _gainMode       -> gainMode;
  GateMode       _gateMode       -> gateMode;
  InsertionDelay _insertionDelay -> insertionDelay;
  uint8_t _pad0;

  uint16_t _mcpGain         -> mcpGain;
  uint16_t _pad1;

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

} //- @package iStar
