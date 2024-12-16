@package Jungfrau {

//------------------ ModuleConfigV1 ------------------
@type ModuleConfigV1
  [[pack(2)]]
{
  uint64_t _serialNumber -> serialNumber; /* The module serial number. */
  uint64_t _moduleVerion -> moduleVersion; /* The version number of the module. */
  uint64_t _firmwareVersion -> firmwareVersion; /* The firmware version of the module. */

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

//------------------ ConfigV1 ------------------
@type ConfigV1
  [[type_id(Id_JungfrauConfig, 1)]]
  [[config_type]]
  [[pack(4)]]
{
  @enum GainMode (uint16_t) {
    Normal      = 0,
    FixedGain1  = 1,
    FixedGain2  = 2,
    ForcedGain1 = 3,
    ForcedGain2 = 4,
    HighGain0   = 5,
  }

  @enum SpeedMode (uint16_t) {
    Quarter = 0,
    Half    = 1,
  }

  uint32_t  _numberOfModules -> numberOfModules; /* The number of modules in a physical camera. */
  uint32_t  _numberOfRowsPerModule -> numberOfRowsPerModule; /* The number of rows per module. */
  uint32_t  _numberOfColumnsPerModule -> numberOfColumnsPerModule; /* The number of columns per module. */
  uint32_t  _biasVoltage -> biasVoltage; /* The bias applied to the sensor in volts. */
  GainMode  _gainMode -> gainMode; /* The gain mode set for the camera. */
  SpeedMode _speedMode -> speedMode; /* The camera clock speed setting. */
  double    _triggerDelay -> triggerDelay; /* Internal delay from receiving a trigger input until the start of an acquisiton in seconds. */
  double    _exposureTime -> exposureTime; /* The exposure time in seconds. */

  /* Total size in bytes of the Frame object */
  uint32_t frameSize()
  [[language("C++")]] @{ return @self.numPixels()*2; @}

  /* calculate total frame size in pixels based on the current ROI and binning settings */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{ return numberOfModules()*numberOfRowsPerModule()*numberOfColumnsPerModule(); @}
  
  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

//------------------ ConfigV2 ------------------
@type ConfigV2
  [[type_id(Id_JungfrauConfig, 2)]]
  [[config_type]]
  [[pack(4)]]
{
  @enum GainMode (uint16_t) {
    Normal      = 0,
    FixedGain1  = 1,
    FixedGain2  = 2,
    ForcedGain1 = 3,
    ForcedGain2 = 4,
    HighGain0   = 5,
  }

  @enum SpeedMode (uint16_t) {
    Quarter = 0,
    Half    = 1,
  }

  uint32_t  _numberOfModules -> numberOfModules; /* The number of modules in a physical camera. */
  uint32_t  _numberOfRowsPerModule -> numberOfRowsPerModule; /* The number of rows per module. */
  uint32_t  _numberOfColumnsPerModule -> numberOfColumnsPerModule; /* The number of columns per module. */
  uint32_t  _biasVoltage -> biasVoltage; /* The bias applied to the sensor in volts. */
  GainMode  _gainMode -> gainMode; /* The gain mode set for the camera. */
  SpeedMode _speedMode -> speedMode; /* The camera clock speed setting. */
  double    _triggerDelay -> triggerDelay; /* Internal delay from receiving a trigger input until the start of an acquisiton in seconds. */
  double    _exposureTime -> exposureTime; /* The exposure time in seconds. */
  double    _exposurePeriod -> exposurePeriod; /* The period between exposures of the camera. In triggered mode this should be smaller than the trigger period. */
  uint16_t  _vb_ds -> vb_ds;            /* Value of vb_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vb_comp -> vb_comp;        /* Value of vb_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vb_pixbuf -> vb_pixbuf;    /* Value of vb_pixbuf in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vref_ds -> vref_ds;        /* Value of vref_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vref_comp -> vref_comp;    /* Value of vref_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vref_prech -> vref_prech;  /* Value of vref_prech in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vin_com -> vin_com;        /* Value of vin_com in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vdd_prot -> vdd_prot;      /* Value of vdd_prot in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */

  /* Total size in bytes of the Frame object */
  uint32_t frameSize()
  [[language("C++")]] @{ return @self.numPixels()*2; @}

  /* calculate total frame size in pixels based on the current ROI and binning settings */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{ return numberOfModules()*numberOfRowsPerModule()*numberOfColumnsPerModule(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

//------------------ ConfigV3 ------------------
@type ConfigV3 
  [[type_id(Id_JungfrauConfig, 3)]]
  [[config_type]]
  [[pack(4)]]
{
  /* Defines the maximum number of modules in a Jungfrau detector. */
  @const uint32_t MaxModulesPerDetector = 8;
  /* Defines the maximum number of rows in a Jungfrau module. */
  @const uint32_t MaxRowsPerModule = 512;
  /* Defines the maximum number of columns in a Jungfrau module. */
  @const uint32_t MaxColumnsPerModule = 1024;
 
  @enum GainMode (uint16_t) {
    Normal      = 0,
    FixedGain1  = 1,
    FixedGain2  = 2, 
    ForcedGain1 = 3,
    ForcedGain2 = 4,
    HighGain0   = 5,
  }

  @enum SpeedMode (uint16_t) {
    Quarter = 0,
    Half    = 1,
  } 
    
  uint32_t  _numberOfModules -> numberOfModules; /* The number of modules in a physical camera. */
  uint32_t  _numberOfRowsPerModule -> numberOfRowsPerModule; /* The number of rows per module. */
  uint32_t  _numberOfColumnsPerModule -> numberOfColumnsPerModule; /* The number of columns per module. */
  uint32_t  _biasVoltage -> biasVoltage; /* The bias applied to the sensor in volts. */
  GainMode  _gainMode -> gainMode; /* The gain mode set for the camera. */
  SpeedMode _speedMode -> speedMode; /* The camera clock speed setting. */
  double    _triggerDelay -> triggerDelay; /* Internal delay from receiving a trigger input until the start of an acquisiton in seconds. */
  double    _exposureTime -> exposureTime; /* The exposure time in seconds. */
  double    _exposurePeriod -> exposurePeriod; /* The period between exposures of the camera. In triggered mode this should be smaller than the trigger period. */
  uint16_t  _vb_ds -> vb_ds;            /* Value of vb_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vb_comp -> vb_comp;        /* Value of vb_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vb_pixbuf -> vb_pixbuf;    /* Value of vb_pixbuf in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vref_ds -> vref_ds;        /* Value of vref_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vref_comp -> vref_comp;    /* Value of vref_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vref_prech -> vref_prech;  /* Value of vref_prech in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vin_com -> vin_com;        /* Value of vin_com in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */ 
  uint16_t  _vdd_prot -> vdd_prot;      /* Value of vdd_prot in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  ModuleConfigV1 _moduleConfig[MaxModulesPerDetector] -> moduleConfig; /* Module specific configuration information for each of the modules in the detector system. */

  /* Total size in bytes of the Frame object */
  uint32_t frameSize()
  [[language("C++")]] @{ return @self.numPixels()*2; @}

  /* calculate total frame size in pixels based on the current ROI and binning settings */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{ return numberOfModules()*numberOfRowsPerModule()*numberOfColumnsPerModule(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

//------------------ ConfigV4 ------------------
@type ConfigV4
  [[type_id(Id_JungfrauConfig, 4)]]
  [[config_type]]
  [[pack(4)]]
{
  /* Defines the maximum number of modules in a Jungfrau detector. */
  @const uint32_t MaxModulesPerDetector = 32;
  /* Defines the maximum number of rows in a Jungfrau module. */
  @const uint32_t MaxRowsPerModule = 512;
  /* Defines the maximum number of columns in a Jungfrau module. */
  @const uint32_t MaxColumnsPerModule = 1024;

  @enum GainMode (uint16_t) {
    Normal      = 0,
    FixedGain1  = 1,
    FixedGain2  = 2,
    ForcedGain1 = 3,
    ForcedGain2 = 4,
    HighGain0   = 5,
  }

  @enum SpeedMode (uint16_t) {
    Quarter = 0,
    Half    = 1,
  }

  uint32_t  _numberOfModules -> numberOfModules; /* The number of modules in a physical camera. */
  uint32_t  _numberOfRowsPerModule -> numberOfRowsPerModule; /* The number of rows per module. */
  uint32_t  _numberOfColumnsPerModule -> numberOfColumnsPerModule; /* The number of columns per module. */
  uint32_t  _biasVoltage -> biasVoltage; /* The bias applied to the sensor in volts. */
  GainMode  _gainMode -> gainMode; /* The gain mode set for the camera. */
  SpeedMode _speedMode -> speedMode; /* The camera clock speed setting. */
  double    _triggerDelay -> triggerDelay; /* Internal delay from receiving a trigger input until the start of an acquisiton in seconds. */
  double    _exposureTime -> exposureTime; /* The exposure time in seconds. */
  double    _exposurePeriod -> exposurePeriod; /* The period between exposures of the camera. In triggered mode this should be smaller than the trigger period. */
  uint16_t  _vb_ds -> vb_ds;            /* Value of vb_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vb_comp -> vb_comp;        /* Value of vb_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vb_pixbuf -> vb_pixbuf;    /* Value of vb_pixbuf in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vref_ds -> vref_ds;        /* Value of vref_ds in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vref_comp -> vref_comp;    /* Value of vref_comp in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vref_prech -> vref_prech;  /* Value of vref_prech in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vin_com -> vin_com;        /* Value of vin_com in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  uint16_t  _vdd_prot -> vdd_prot;      /* Value of vdd_prot in bits. 12bit on 0 to 2.5V (i.e. 2.5V = 4096). */
  ModuleConfigV1 _moduleConfig[MaxModulesPerDetector] -> moduleConfig; /* Module specific configuration information for each of the modules in the detector system. */

  /* Total size in bytes of the Frame object */
  uint32_t frameSize()
  [[language("C++")]] @{ return @self.numPixels()*2; @}

  /* calculate total frame size in pixels based on the current ROI and binning settings */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{ return numberOfModules()*numberOfRowsPerModule()*numberOfColumnsPerModule(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

//------------------ ModuleInfoV1 ------------------
@type ModuleInfoV1
  [[pack(2)]]
{
  uint64_t _timestamp -> timestamp; /* The camera timestamp associated with the detector frame in 100 ns ticks. */
  uint32_t _exposureTime -> exposureTime; /* The actual exposure time of the image in 100 ns ticks. */
  uint16_t _moduleID -> moduleID; /* The unique module ID number. */
  uint16_t _xCoord -> xCoord; /* The X coordinate in the complete detector system. */
  uint16_t _yCoord -> yCoord; /* The Y coordinate in the complete detector system. */
  uint16_t _zCoord -> zCoord; /* The Z coordinate in the complete detector system. */

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

//------------------ ElementV1 ------------------
@type ElementV1
  [[type_id(Id_JungfrauElement, 1)]]
  [[pack(2)]]
  [[config(ConfigV1, ConfigV2, ConfigV3, ConfigV4)]]
{
  uint32_t _frameNumber -> frameNumber; /* The internal frame counter number of the detector. */
  uint32_t _ticks -> ticks; /* The LCLS timing tick associated with the detector frame. */
  uint32_t _fiducials -> fiducials; /* The LCLS timing fiducial associated with the detector frame. */
  uint16_t _frame[@config.numberOfModules()][@config.numberOfRowsPerModule()][@config.numberOfColumnsPerModule()] -> frame;
}

//------------------ ElementV2 ------------------
@type ElementV2
  [[type_id(Id_JungfrauElement, 2)]]
  [[pack(2)]]
  [[config(ConfigV1, ConfigV2, ConfigV3, ConfigV4)]]
{
  uint64_t _frameNumber -> frameNumber; /* The internal frame counter number of the detector. */
  uint32_t _ticks -> ticks; /* The LCLS timing tick associated with the detector frame. */
  uint32_t _fiducials -> fiducials; /* The LCLS timing fiducial associated with the detector frame. */
  ModuleInfoV1 _moduleInfo[@config.numberOfModules()] -> moduleInfo; /* Information about each of the modules in the detector system. */
  uint16_t _frame[@config.numberOfModules()][@config.numberOfRowsPerModule()][@config.numberOfColumnsPerModule()] -> frame;

  /* Constructor which takes values for scalar attributes */
  @init(frameNumber -> _frameNumber, ticks -> _ticks, fiducials -> _fiducials) [[inline]];
}

} //- @package Jungfrau
