@package Vimba {

//------------------ AlviumConfigV1 ------------------
@type AlviumConfigV1
  [[type_id(Id_AlviumConfig, 1)]]
  [[config_type]]
  [[pack(4)]]
{
  @const uint16_t DESC_CHAR_MAX = 48;

  @enum VmbBool (uint8_t) {
    False = 0,
    True  = 1,
  }

  @enum RoiMode (uint8_t) {
    Off      = 0,
    On       = 1,
    Centered = 2,
  }

  @enum TriggerMode (uint8_t) {
    FreeRun  = 0,
    External = 1,
    Software = 2,
  }

  @enum PixelMode (uint8_t) {
    Mono8   = 0,
    Mono10  = 1,
    Mono10p = 2,
    Mono12  = 3,
    Mono12p = 4,
  }

  @enum ImgCorrectionType (uint8_t) {
    DefectPixelCorrection = 0,
    FixedPatternNoiseCorrection = 1,
  }

  @enum ImgCorrectionSet (uint8_t) {
    Preset = 0,
    User = 1,
  }

  /* Reverse the image along the x-axis of the image. */
  VmbBool _reverseX -> reverseX;
  /* Reverse the image along the y-axis of the image. */
  VmbBool _reverseY -> reverseY;
  /* Enable contrast enhancement features. */
  VmbBool _contrastEnable -> contrastEnable;
  /* Enable image correction feature. */
  VmbBool _correctionEnable -> correctionEnable;
  /* Enable image roi. */
  RoiMode _roiEnable -> roiEnable;
  uint8_t _pad0[3];
  
  /* Sets the type of image correction to use. */
  ImgCorrectionType _correctionType -> correctionType;
  /* Sets which image correction date to use. */
  ImgCorrectionSet _correctionSet -> correctionSet;

  /* Sets the pixel bit depth. */
  PixelMode _pixelMode -> pixelMode;
  /* Sets the trigger mode. */
  TriggerMode _triggerMode -> triggerMode;

  uint32_t _width   -> width;
  uint32_t _height  -> height;
  uint32_t _offsetX -> offsetX;
  uint32_t _offsetY -> offsetY;

  uint32_t _sensorWidth  -> sensorWidth;
  uint32_t _sensorHeight -> sensorHeight;

  uint32_t _contrastDarkLimit   -> contrastDarkLimit;
  uint32_t _contrastBrightLimit -> contrastBrightLimit;
  uint32_t _contrastShape       -> contrastShape;

  double _exposureTime  -> exposureTime;
  double _blackLevel    -> blackLevel;
  double _gain          -> gain;
  double _gamma         -> gamma;

  /* The name of the manufacturer of the camera. */
  char _manufacturer[DESC_CHAR_MAX] -> manufacturer [[shape_method(None)]];
  /* The model family of the camera. */
  char _family[DESC_CHAR_MAX] -> family [[shape_method(None)]];
  /* The model name of the camera. */
  char _model[DESC_CHAR_MAX] -> model [[shape_method(None)]];
  /* The manufacturer id of the camera. */
  char _manufacturerId[DESC_CHAR_MAX] -> manufacturerId [[shape_method(None)]];
  /* The hardware version number of the camera. */
  char _version[DESC_CHAR_MAX] -> version [[shape_method(None)]];
  /* The serial number of the camera. */
  char _serialNumber[DESC_CHAR_MAX] -> serialNumber [[shape_method(None)]];
  /* The firmware id of the camera. */
  char _firmwareId[DESC_CHAR_MAX] -> firmwareId [[shape_method(None)]];
  /* The firmware version of the camera. */
  char _firmwareVersion[DESC_CHAR_MAX] -> firmwareVersion [[shape_method(None)]];

  /* Number of bits per pixel. */
  uint32_t depth()
  [[language("C++")]] @{
    uint32_t bits = 0;
    switch(@self.pixelMode()) {
        case Mono8:
            bits = 8;
            break;
        case Mono10:
        case Mono10p:
            bits = 10;
            break;
        case Mono12:
        case Mono12p:
            bits = 12;
            break;
    }
    return bits;
  @}

  /* Total size in bytes of the Frame object */
  uint32_t frameSize()
  [[language("C++")]] @{ return numPixels() * 2; @}

  /* calculate frame X size in pixels based on the current ROI */
  uint32_t numPixelsX()  [[inline]]
  [[language("C++")]] @{ return width(); @}

  /* calculate frame Y size in pixels based on the current ROI */
  uint32_t numPixelsY()  [[inline]]
  [[language("C++")]] @{ return height(); @}

  /* calculate total frame size in pixels based on the current ROI and binning settings */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{ return numPixelsX()*numPixelsY(); @}

  /* Constructor with values for each attribute */
  @init()  [[auto, inline]];

}

//------------------ FrameV1 ------------------
@type FrameV1
  [[type_id(Id_VimbaFrame, 1)]]
  [[pack(2)]]
  [[config(AlviumConfigV1)]]
{
  uint64_t _frameid -> frameid; /* The internal frame id from the camera. */
  uint64_t _timestamp -> timestamp; /* The internal camera FPGA clock timestamp for the frame. */
  uint16_t _data[@config.numPixelsY()][@config.numPixelsX()] -> data;

  /* Constructor with values for scalar attributes */
  @init(frameid -> _frameid, timestamp -> _timestamp)  [[inline]];
}


} //- @package Vimba
