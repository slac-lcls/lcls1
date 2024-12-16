@package Archon {

//------------------ ArchonConfigV1 ------------------
/* Class containing configuration data for CCDs using the Archon controller. */
@type ConfigV1
  [[type_id(Id_ArchonConfig, 1)]]
  [[config_type]]
{
  @const uint16_t FILENAME_CHAR_MAX = 256;
  
  @enum ReadoutMode (uint16_t) {
    Single     = 0,
    Continuous = 1,
    Triggered  = 2,
  }

  ReadoutMode _readoutMode -> readoutMode;
  uint16_t _sweepCount -> sweepCount;
  uint32_t _integrationTime -> integrationTime;
  uint32_t _nonIntegrationTime -> nonIntegrationTime;
  //-------- Image Formatting parameters --------
  uint32_t _preSkipPixels -> preSkipPixels;
  uint32_t _pixels -> pixels;
  uint32_t _postSkipPixels -> postSkipPixels;
  uint32_t _overscanPixels -> overscanPixels;
  uint16_t _preSkipLines -> preSkipLines;
  uint16_t _lines -> lines;
  uint16_t _postSkipLines -> postSkipLines;
  uint16_t _overScanLines -> overScanLines;
  uint16_t _horizontalBinning -> horizontalBinning;
  uint16_t _verticalBinning -> verticalBinning;
  //-------- Timing Parameters --------
  uint16_t _rgh     ->  rgh;
  uint16_t _rgl     ->  rgl;
  uint16_t _shp     ->  shp;
  uint16_t _shd     ->  shd;
  uint16_t _st      ->  st;
  uint16_t _stm1    ->  stm1;
  uint16_t _at      ->  at;
  uint16_t _dwell1  -> dwell1;
  uint16_t _dwell2  -> dwell2;
  //-------- Constants - Clock Level --------
  int16_t _rgHigh -> rgHigh;
  int16_t _rgLow  -> rgLow;
  int16_t _sHigh  -> sHigh;
  int16_t _sLow   -> sLow;
  int16_t _aHigh  -> aHigh;
  int16_t _aLow   -> aLow;
  //-------- Constants - Slew Rates --------
  int16_t _rgSlew -> rgSlew;
  int16_t _sSlew  -> sSlew;
  int16_t _aSlew  -> aSlew;

  char _config[FILENAME_CHAR_MAX] -> config [[shape_method(None)]]; /* The path to an acf file to use with the camera. */

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

//------------------ ArchonConfigV2 ------------------
/* Class containing configuration data for CCDs using the Archon controller. */
@type ConfigV2
  [[type_id(Id_ArchonConfig, 2)]]
  [[config_type]]
{
  @const uint16_t MaxConfigLines = 1<<14;
  @const uint16_t MaxConfigLineLength = 2048;

  @enum ReadoutMode (uint16_t) {
    Single     = 0,
    Continuous = 1,
    Triggered  = 2,
  }

  /* Readout mode of the camera, a.k.a. software vs hardware triggered. */
  ReadoutMode _readoutMode      ->  readoutMode;
  /* The event code to use for exposure when software triggering the camera. */
  uint16_t _exposureEventCode   ->  exposureEventCode;
  /* The size of the acf file portion of the configuration. */
  uint32_t _configSize          ->  configSize;
  /* The count of lines to sweep before beginning a frame. */
  uint32_t _preFrameSweepCount  ->  preFrameSweepCount;
  /* The number of lines to sweep per cycle when waiting for triggers. */
  uint32_t _idleSweepCount      ->  idleSweepCount;
  /* The time (ms) to expose the sensor. */
  uint32_t _integrationTime     ->  integrationTime;
  /* The time (ms) to wait after exposing the sensor before reading it out. */
  uint32_t _nonIntegrationTime  ->  nonIntegrationTime;
  //-------- Image Formatting parameters --------
  /* The number of frames to batch together for readout. */
  uint32_t _batches             ->  batches;
  /* The number of pixels to readout from each tap. */
  uint32_t _pixels              ->  pixels;
  /* The number of lines to readout from each tap. */
  uint32_t _lines               ->  lines;
  /* The horizontal binning setting. */
  uint32_t _horizontalBinning   ->  horizontalBinning;
  /* The vertical binning setting. */
  uint32_t _verticalBinning     ->  verticalBinning;
  //-------- Sensor Info Parameters --------
  /* Number of actual pixels per tap. */
  uint32_t _sensorPixels        -> sensorPixels;
  /* Number of actual lines per tap. */
  uint32_t _sensorLines         -> sensorLines;
  /* Number of taps for the sensor. */
  uint32_t _sensorTaps          -> sensorTaps;
  //-------- Timing Parameters --------
  uint32_t _st    ->  st;
  uint32_t _stm1  ->  stm1;
  uint32_t _at    ->  at;

  char _config[@self.configSize()] -> config; /* The contents of the acf file to use with the camera. */

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];

  /* Constructor which takes values necessary for size calculations */
  @init(configSize -> _configSize) [[inline]];
}

//------------------ ArchonConfigV3 ------------------
@type ConfigV3
  [[type_id(Id_ArchonConfig, 3)]]
  [[config_type]]
{
  @const uint16_t MaxConfigLines = 1<<14;
  @const uint16_t MaxConfigLineLength = 2048;

  @enum ReadoutMode (uint16_t) {
    FreeRun   = 0,
    Triggered = 1,
  }

  @enum Switch (uint16_t) {
    Off  = 0,
    On   = 1,
  }

  @enum BiasChannelId (int16_t) {
    NV4     = -4,
    NV3     = -3,
    NV2     = -2,
    NV1     = -1,
    PV1     = 1,
    PV2     = 2,
    PV3     = 3,
    PV4     = 4,
  }

  /* Readout mode of the camera, a.k.a. software vs hardware triggered. */
  ReadoutMode _readoutMode      ->  readoutMode;
  /* The state of the ccd power, a.k.a off vs on. */
  Switch _power                 -> power;
  /* The event code to use for exposure when software triggering the camera. */
  uint16_t _exposureEventCode   ->  exposureEventCode;
  uint16_t _pad0;
  /* The size of the acf file portion of the configuration. */
  uint32_t _configSize          ->  configSize;
  /* The count of lines to sweep before beginning a frame. */
  uint32_t _preFrameSweepCount  ->  preFrameSweepCount;
  /* The number of lines to sweep per cycle when waiting for triggers. */
  uint32_t _idleSweepCount      ->  idleSweepCount;
  /* The time (ms) to expose the sensor. */
  uint32_t _integrationTime     ->  integrationTime;
  /* The time (ms) to wait after exposing the sensor before reading it out. */
  uint32_t _nonIntegrationTime  ->  nonIntegrationTime;
  //-------- Image Formatting parameters --------
  /* The number of frames to batch together for readout. */
  uint32_t _batches             ->  batches;
  /* The number of pixels to readout from each tap. */
  uint32_t _pixels              ->  pixels;
  /* The number of lines to readout from each tap. */
  uint32_t _lines               ->  lines;
  /* The horizontal binning setting. */
  uint32_t _horizontalBinning   ->  horizontalBinning;
  /* The vertical binning setting. */
  uint32_t _verticalBinning     ->  verticalBinning;
  //-------- Sensor Info Parameters --------
  /* Number of actual pixels per tap. */
  uint32_t _sensorPixels        -> sensorPixels;
  /* Number of actual lines per tap. */
  uint32_t _sensorLines         -> sensorLines;
  /* Number of taps for the sensor. */
  uint32_t _sensorTaps          -> sensorTaps;
  //-------- Timing Parameters --------
  uint32_t _st    ->  st;
  uint32_t _stm1  ->  stm1;
  uint32_t _at    ->  at;
  //-------- Sensor Bias Parameters --------
  /* The state of the ccd bias voltage, a.k.a off vs on. */
  Switch _bias            -> bias;
  /* The channel ID of the bias voltage. */
  BiasChannelId _biasChan -> biasChan;
  /* The bias voltage setpoint. */
  float _biasVoltage     -> biasVoltage;

  /* Version tag for the attached acf file. */
  uint32_t _configVersion -> configVersion;

  char _config[@self.configSize()] -> config; /* The contents of the acf file to use with the camera. */

  /* Calculate the frame X size in pixels based on the number of pixels per tap and the number of taps. */
  uint32_t numPixelsX() [[inline]]
  [[language("C++")]] @{ return @self.pixels() * @self.sensorTaps(); @}

  /* calculate frame Y size in pixels based on the number of lines per tap. */
  uint32_t numPixelsY()  [[inline]]
  [[language("C++")]] @{ return @self.lines(); @}

  /* calculate total frame size in pixels. */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{ return @self.numPixelsX() * @self.numPixelsY(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];

  /* Constructor which takes values necessary for size calculations */
  @init(configSize -> _configSize) [[inline]];
}

//------------------ ArchonConfigV4 ------------------
@type ConfigV4
  [[type_id(Id_ArchonConfig, 4)]]
  [[config_type]]
{
  @const uint16_t MaxConfigLines = 1<<14;
  @const uint16_t MaxConfigLineLength = 2048;

  @enum ReadoutMode (uint16_t) {
    FreeRun   = 0,
    Triggered = 1,
  }

  @enum Switch (uint16_t) {
    Off  = 0,
    On   = 1,
  }

  @enum BiasChannelId (int16_t) {
    NV4     = -4,
    NV3     = -3,
    NV2     = -2,
    NV1     = -1,
    PV1     = 1,
    PV2     = 2,
    PV3     = 3,
    PV4     = 4,
  }

  /* Readout mode of the camera, a.k.a. software vs hardware triggered. */
  ReadoutMode _readoutMode      ->  readoutMode;
  /* The state of the ccd power, a.k.a off vs on. */
  Switch _power                 -> power;
  /* The event code to use for exposure when software triggering the camera. */
  uint16_t _exposureEventCode   ->  exposureEventCode;
  uint16_t _pad0;
  /* The size of the acf file portion of the configuration. */
  uint32_t _configSize          ->  configSize;
  /* The count of lines to sweep before beginning a frame. */
  uint32_t _preFrameSweepCount  ->  preFrameSweepCount;
  /* The number of lines to sweep per cycle when waiting for triggers. */
  uint32_t _idleSweepCount      ->  idleSweepCount;
  /* The number of lines to skip before beginning a frame. */
  uint32_t _preSkipLines        ->  preSkipLines;
  /* The time (ms) to expose the sensor. */
  uint32_t _integrationTime     ->  integrationTime;
  /* The time (ms) to wait after exposing the sensor before reading it out. */
  uint32_t _nonIntegrationTime  ->  nonIntegrationTime;
  //-------- Image Formatting parameters --------
  /* The number of frames to batch together for readout. */
  uint32_t _batches             ->  batches;
  /* The number of pixels to readout from each tap. */
  uint32_t _pixels              ->  pixels;
  /* The number of lines to readout from each tap. */
  uint32_t _lines               ->  lines;
  /* The horizontal binning setting. */
  uint32_t _horizontalBinning   ->  horizontalBinning;
  /* The vertical binning setting. */
  uint32_t _verticalBinning     ->  verticalBinning;
  //-------- Sensor Info Parameters --------
  /* Number of actual pixels per tap. */
  uint32_t _sensorPixels        -> sensorPixels;
  /* Number of actual lines per tap. */
  uint32_t _sensorLines         -> sensorLines;
  /* Number of taps for the sensor. */
  uint32_t _sensorTaps          -> sensorTaps;
  //-------- Timing Parameters --------
  uint32_t _st    ->  st;
  uint32_t _stm1  ->  stm1;
  uint32_t _at    ->  at;
  //-------- Sensor Bias Parameters --------
  /* The state of the ccd bias voltage, a.k.a off vs on. */
  Switch _bias            -> bias;
  /* The channel ID of the bias voltage. */
  BiasChannelId _biasChan -> biasChan;
  /* The bias voltage setpoint. */
  float _biasVoltage     -> biasVoltage;

  /* Version tag for the attached acf file. */
  uint32_t _configVersion -> configVersion;

  char _config[@self.configSize()] -> config; /* The contents of the acf file to use with the camera. */

  /* Calculate the frame X size in pixels based on the number of pixels per tap and the number of taps. */
  uint32_t numPixelsX() [[inline]]
  [[language("C++")]] @{ return @self.pixels() * @self.sensorTaps(); @}

  /* calculate frame Y size in pixels based on the number of lines per tap. */
  uint32_t numPixelsY()  [[inline]]
  [[language("C++")]] @{ return @self.lines(); @}

  /* calculate total frame size in pixels. */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{ return @self.numPixelsX() * @self.numPixelsY(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];

  /* Constructor which takes values necessary for size calculations */
  @init(configSize -> _configSize) [[inline]];
}


} //- @package Archon
