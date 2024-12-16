@package Rayonix  {


//------------------ ConfigV1 ------------------
@type ConfigV1
  [[type_id(Id_RayonixConfig, 1)]]
  [[config_type]]
  [[pack(4)]]
{
  @const int32_t Row_Pixels = 3840;
  @const int32_t Column_Pixels = 3840;
  @const int32_t BasePixelSize = 44;
  @const int32_t DeviceIDMax = 40;

  @enum ReadoutMode (uint32_t) {
    Standard = 0,
    HighGain = 1,
    LowNoise = 2,
    EDR = 3,
  }

  uint8_t _binning_f -> binning_f;
  uint8_t _binning_s -> binning_s;
  int16_t _pad;
  uint32_t _exposure -> exposure;
  uint32_t _trigger -> trigger;
  uint16_t _rawMode -> rawMode;
  uint16_t _darkFlag -> darkFlag;
  ReadoutMode _readoutMode -> readoutMode;
  char _deviceID[DeviceIDMax] -> deviceID  [[shape_method(None)]];

  /* The width of the pixels in um. */
  uint32_t pixelWidth() [[inline]]
  [[language("C++")]] @{ return BasePixelSize * @self.binning_f(); @}

  /* The height of the pixels in um. */
  uint32_t pixelHeight() [[inline]]
  [[language("C++")]] @{ return BasePixelSize * @self.binning_s(); @}

  /* Returns the maximum possible width in pixels (a.k.a unbinned). */
  uint32_t maxWidth() [[inline]]
  [[language("C++")]] @{ return Column_Pixels; @}

  /* Returns the maximum possible height in pixels (a.k.a unbinned). */
  uint32_t maxHeight() [[inline]]
  [[language("C++")]] @{ return Row_Pixels; @}

  /* Calculate the frame width in pixels based on the max number of pixels and the binning. */
  uint32_t width() [[inline]]
  [[language("C++")]] @{ return @self.maxWidth() / @self.binning_f(); @}

  /* Calculate the frame height in pixels based on the max number of pixels and the binning. */
  uint32_t height() [[inline]]
  [[language("C++")]] @{ return @self.maxHeight() / @self.binning_s(); @}

  /* calculate total frame size in pixels. */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{ return @self.width() * @self.height(); @}

  /* Constructor with a value for each argument */
  @init()  [[auto, inline]];

}


//------------------ ConfigV2 ------------------
@type ConfigV2
  [[type_id(Id_RayonixConfig, 2)]]
  [[config_type]]
  [[pack(4)]]
{
  @const int32_t MX340HS_Row_Pixels = 7680;
  @const int32_t MX340HS_Column_Pixels = 7680;
  @const int32_t MX170HS_Row_Pixels = 3840;
  @const int32_t MX170HS_Column_Pixels = 3840;
  @const int32_t BasePixelSize = 44;
  @const int32_t DeviceIDMax = 40;

  @enum ReadoutMode (uint32_t) {
    Unknown = 0,
    Standard = 1,
    HighGain = 2,
    LowNoise = 3,
    HDR = 4,
  }

  uint8_t _binning_f -> binning_f;
  uint8_t _binning_s -> binning_s;
  int16_t _testPattern -> testPattern;
  uint32_t _exposure -> exposure;
  uint32_t _trigger -> trigger;
  uint16_t _rawMode -> rawMode;
  uint16_t _darkFlag -> darkFlag;
  ReadoutMode _readoutMode -> readoutMode;
  char _deviceID[DeviceIDMax] -> deviceID  [[shape_method(None)]];

  /* The width of the pixels in um. */
  uint32_t pixelWidth() [[inline]]
  [[language("C++")]] @{ return BasePixelSize * @self.binning_f(); @}

  /* The height of the pixels in um. */
  uint32_t pixelHeight() [[inline]]
  [[language("C++")]] @{ return BasePixelSize * @self.binning_s(); @}

  /* Returns the maximum possible width in pixels (a.k.a unbinned). */
  uint32_t maxWidth()
  [[language("C++")]] @{
    if (!strncmp(@self.deviceID(), "MX340-HS", 8)) {
      return MX340HS_Column_Pixels;
    } else if (!strncmp(@self.deviceID(), "MX170-HS", 8)) {
      return MX170HS_Column_Pixels;
    } else {
      return MX170HS_Column_Pixels;
    }
  @}

  /* Returns the maximum possible height in pixels (a.k.a unbinned). */
  uint32_t maxHeight()
  [[language("C++")]] @{
    if (!strncmp(@self.deviceID(), "MX340-HS", 8)) {
      return MX340HS_Row_Pixels;
    } else if (!strncmp(@self.deviceID(), "MX170-HS", 8)) {
      return MX170HS_Row_Pixels;
    } else {
      return MX170HS_Row_Pixels;
    }
  @}

  /* Calculate the frame width in pixels based on the max number of pixels and the binning. */
  uint32_t width() [[inline]]
  [[language("C++")]] @{ return @self.maxWidth() / @self.binning_f(); @}

  /* Calculate the frame height in pixels based on the max number of pixels and the binning. */
  uint32_t height() [[inline]]
  [[language("C++")]] @{ return @self.maxHeight() / @self.binning_s(); @}

  /* calculate total frame size in pixels. */
  uint32_t numPixels()  [[inline]]
  [[language("C++")]] @{ return @self.width() * @self.height(); @}

  /* Constructor with a value for each argument */
  @init()  [[auto, inline]];

}
} //- @package Rayonix
