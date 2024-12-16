@package Uxi {

//------------------ ConfigV1 ------------------
@type ConfigV1
  [[type_id(Id_UxiConfig, 1)]]
  [[config_type]]
  [[pack(4)]]
{
  /* Defines the number of potentiometers in the Icarus detector. */
  @const uint32_t NumberOfPots = 13;
  @const uint32_t NumberOfSides = 2;

  uint32_t  _width -> width; /* The width in pixels of each frame of the detector. */
  uint32_t  _height -> height; /* The height in pixels of each frame of the detector. */
  uint32_t  _numberOfFrames -> numberOfFrames; /* The number of frames produced by the detector. */
  uint32_t  _numberOfBytesPerPixel -> numberOFBytesPerPixel; /* The number of bytes for each pixel. */
  uint32_t  _sensorType -> sensorType; /* The sensor type ID. */
  uint32_t  _timeOn[NumberOfSides] -> timeOn; /* High speed timing on parameter in ns for each side. */
  uint32_t  _timeOff[NumberOfSides] -> timeOff; /* High speed timing off parameter in ns for each side. */
  uint32_t  _delay[NumberOfSides] -> delay; /* High speed timing initial delay in ns for each side. */
  uint32_t  _readOnlyPots -> readOnlyPots; /* Bitmask to designate which pots should only be read and not written. */
  double    _pots[NumberOfPots] -> pots; /* The values of the each of the pots in volts. */

  /* Check if a pot is readonly. */
  uint8_t potIsReadOnly(uint8_t i)  [[inline]]
  [[language("C++")]] @{ return ((i<NumberOfPots) && (_readOnlyPots & (1<<i))) ? 1 : 0; @}

  /* Check if a pot was tuned. */
  uint8_t potIsTuned(uint8_t i) [[inline]]
  [[language("C++")]] @{ return ((i<NumberOfPots) && (_readOnlyPots & (1<<(i+NumberOfPots)))) ? 1 : 0; @}

  /* calculate total number of pixels per frame. */
  uint32_t numPixelsPerFrame()  [[inline]]
  [[language("C++")]] @{ return @self.width()*@self.height(); @}

  /* calculate total number of pixels across all frames. */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{ return @self.width()*@self.height()*@self.numberOfFrames(); @}

  /* Total size in bytes of the frame */
  uint32_t frameSize()
  [[language("C++")]] @{ return @self.numPixels()*@self.numberOFBytesPerPixel(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

//------------------ RoiCoord ------------------
@type RoiCoord
  [[value_type]]
{
  uint16_t _first -> first; /* The first row/frame of ROI. */
  uint16_t _last -> last;   /* The last row/frame of ROI. */

  /* Constructor which takes values for every attribute */
  @init()  [[auto, inline]];
}

//------------------ ConfigV2 ------------------
@type ConfigV2
  [[type_id(Id_UxiConfig, 2)]]
  [[config_type]]
  [[pack(4)]]
{
  /* Defines the number of potentiometers in the Icarus detector. */
  @const uint32_t NumberOfPots = 13;
  @const uint32_t NumberOfSides = 2;

  @enum RoiMode (uint32_t) {
    Off = 0,
    On  = 1,
  }

  RoiMode   _roiEnable -> roiEnable; /* Enable frame/row roi. */
  RoiCoord  _roiRows -> roiRows; /* The first/last rows of the roi. */
  RoiCoord  _roiFrames -> roiFrames; /* The first/last frames of the roi. */
  uint32_t  _width -> width; /* The width in pixels of each frame of the detector. */
  uint32_t  _height -> height; /* The height in pixels of each frame of the detector. */
  uint32_t  _numberOfFrames -> numberOfFrames; /* The number of frames produced by the detector. */
  uint32_t  _numberOfBytesPerPixel -> numberOFBytesPerPixel; /* The number of bytes for each pixel. */
  uint32_t  _sensorType -> sensorType; /* The sensor type ID. */
  uint32_t  _timeOn[NumberOfSides] -> timeOn; /* High speed timing on parameter in ns for each side. */
  uint32_t  _timeOff[NumberOfSides] -> timeOff; /* High speed timing off parameter in ns for each side. */
  uint32_t  _delay[NumberOfSides] -> delay; /* High speed timing initial delay in ns for each side. */
  uint32_t  _readOnlyPots -> readOnlyPots; /* Bitmask to designate which pots should only be read and not written. */
  double    _pots[NumberOfPots] -> pots; /* The values of the each of the pots in volts. */

  /* Check if a pot is readonly. */
  uint8_t potIsReadOnly(uint8_t i)  [[inline]]
  [[language("C++")]] @{ return ((i<NumberOfPots) && (_readOnlyPots & (1<<i))) ? 1 : 0; @}

  /* Check if a pot was tuned. */
  uint8_t potIsTuned(uint8_t i) [[inline]]
  [[language("C++")]] @{ return ((i<NumberOfPots) && (_readOnlyPots & (1<<(i+NumberOfPots)))) ? 1 : 0; @}

  /* calculate total number of pixels per frame. */
  uint32_t numPixelsPerFrame()  [[inline]]
  [[language("C++")]] @{ return @self.width()*@self.height(); @}

  /* calculate total number of pixels across all frames. */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{ return @self.width()*@self.height()*@self.numberOfFrames(); @}

  /* Total size in bytes of the frame */
  uint32_t frameSize()
  [[language("C++")]] @{ return @self.numPixels()*@self.numberOFBytesPerPixel(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

//------------------ ConfigV3 ------------------
@type ConfigV3
  [[type_id(Id_UxiConfig, 3)]]
  [[config_type]]
  [[pack(4)]]
{
  /* Defines the number of potentiometers in the Icarus detector. */
  @const uint32_t NumberOfPots = 13;
  @const uint32_t NumberOfSides = 2;

  @enum RoiMode (uint32_t) {
    Off = 0,
    On  = 1,
  }

  @enum OscMode (uint32_t) {
    RelaxationOsc   = 0,
    RingOscWithCaps = 1,
    RingOscNoCaps   = 2,
    ExternalClock   = 3,
  }

  RoiMode   _roiEnable -> roiEnable; /* Enable frame/row roi. */
  RoiCoord  _roiRows -> roiRows; /* The first/last rows of the roi. */
  RoiCoord  _roiFrames -> roiFrames; /* The first/last frames of the roi. */
  OscMode   _oscillator -> oscillator; /* The oscillator to that the detector should use. */
  uint32_t  _width -> width; /* The width in pixels of each frame of the detector. */
  uint32_t  _height -> height; /* The height in pixels of each frame of the detector. */
  uint32_t  _numberOfFrames -> numberOfFrames; /* The number of frames produced by the detector. */
  uint32_t  _numberOfBytesPerPixel -> numberOFBytesPerPixel; /* The number of bytes for each pixel. */
  uint32_t  _sensorType -> sensorType; /* The sensor type ID. */
  uint32_t  _timeOn[NumberOfSides] -> timeOn; /* High speed timing on parameter in ns for each side. */
  uint32_t  _timeOff[NumberOfSides] -> timeOff; /* High speed timing off parameter in ns for each side. */
  uint32_t  _delay[NumberOfSides] -> delay; /* High speed timing initial delay in ns for each side. */
  uint32_t  _readOnlyPots -> readOnlyPots; /* Bitmask to designate which pots should only be read and not written. */
  double    _pots[NumberOfPots] -> pots; /* The values of the each of the pots in volts. */

  /* Check if a pot is readonly. */
  uint8_t potIsReadOnly(uint8_t i)  [[inline]]
  [[language("C++")]] @{ return ((i<NumberOfPots) && (_readOnlyPots & (1<<i))) ? 1 : 0; @}

  /* Check if a pot was tuned. */
  uint8_t potIsTuned(uint8_t i) [[inline]]
  [[language("C++")]] @{ return ((i<NumberOfPots) && (_readOnlyPots & (1<<(i+NumberOfPots)))) ? 1 : 0; @}

  /* calculate total number of pixels per frame. */
  uint32_t numPixelsPerFrame()  [[inline]]
  [[language("C++")]] @{ return @self.width()*@self.height(); @}

  /* calculate total number of pixels across all frames. */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{ return @self.width()*@self.height()*@self.numberOfFrames(); @}

  /* Total size in bytes of the frame */
  uint32_t frameSize()
  [[language("C++")]] @{ return @self.numPixels()*@self.numberOFBytesPerPixel(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

//------------------ FrameV1 ------------------
@type FrameV1
  [[type_id(Id_UxiFrame, 1)]]
  [[pack(2)]]
  [[config(ConfigV1, ConfigV2, ConfigV3)]]
{
  uint32_t _acquisitionCount -> acquisitionCount; /* The internal acquisition counter number of the detector. */
  uint32_t _timestamp -> timestamp; /* The internal detector timestamp associated with the frames. */
  double   _temperature -> temperature; /* The temperature of the detector associated with the frames. */
  uint16_t _frames[@config.numberOfFrames()][@config.height()][@config.width()] -> frames;

  /* Constructor with values for scalar attributes */
  @init(acquisitionCount -> _acquisitionCount, timestamp -> _timestamp, temperature -> _temperature)  [[inline]];
}

} //- @package Uxi
