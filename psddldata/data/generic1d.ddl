@package Generic1D {

//------------------ Generic1D ------------------
@type ConfigV0
  [[type_id(Id_Generic1DConfig, 0)]]
  [[config_type]]
  [[pack(4)]]
{

  @enum Sample_Type (uint32_t) {
  UINT8,
  UINT16,
  UINT32, 
  FLOAT32,
  FLOAT64,
  }

  uint32_t _NChannels -> NChannels;  // Number of channels

  uint32_t    _Length     [@self._NChannels]   -> Length  ; /*   Waveform Length */
  uint32_t    _SampleType [@self._NChannels]   -> SampleType  ;  /*   Waveform Sample Type */
  int32_t     _Offset     [@self._NChannels]   -> Offset  ; /*   Waveform Delay Samples */
  double      _Period     [@self._NChannels]   -> Period  ; /*   Waveform Sampling Period */

  int32_t data_offset(uint32_t channel)
  [[language("C++")]] @{
    int32_t offset=0;
    if (channel>@self._NChannels) channel=@self._NChannels;
    for(uint32_t k=0; k<channel; k++)
      offset += (@self.Length()[k]*@self.Depth(k));
    return offset;
  @}

  uint32_t Depth(uint32_t channel)
  [[language("C++")]] @{
    switch (Sample_Type(@self.SampleType()[channel])) {
    case UINT8: return 1;
    case UINT16: return 2;
    case UINT32: return 4;
    case FLOAT32: return 4;
    case FLOAT64: return 8;
    } 
   return 0;
  @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto, inline]];
}

@type DataV0
  [[type_id(Id_Generic1DData, 0)]]
  [[pack(4)]]
  [[config(ConfigV0)]]
{
  uint32_t _data_size -> data_size ;
  uint8_t  _data[@self._data_size] -> _int_data;

  uint8_t[]  data_u8 (uint32_t channel)
  [[language("C++")]] @{
    if (@config.SampleType()[channel] != ConfigV0::UINT8) return ndarray<const uint8_t, 1>();
    return make_ndarray(_int_data().data()+@config.data_offset(channel), @config.Length()[channel]);
  @}

  uint16_t[] data_u16(uint32_t channel)
  [[language("C++")]] @{
    if (@config.SampleType()[channel] != ConfigV0::UINT16) return ndarray<const uint16_t, 1>();
    return make_ndarray((const uint16_t*)(_int_data().data()+@config.data_offset(channel)), @config.Length()[channel]);
  @}

  uint32_t[] data_u32(uint32_t channel)
  [[language("C++")]] @{
    if (@config.SampleType()[channel] != ConfigV0::UINT32) return ndarray<const uint32_t, 1>();
    return make_ndarray((const uint32_t*)(_int_data().data()+@config.data_offset(channel)), @config.Length()[channel]);
  @}

  float[] data_f32(uint32_t channel)
  [[language("C++")]] @{
    if (@config.SampleType()[channel] != ConfigV0::FLOAT32) return ndarray<const float, 1>();
    return make_ndarray((const float*)(_int_data().data()+@config.data_offset(channel)), @config.Length()[channel]);
  @}

  double[] data_f64(uint32_t channel)
  [[language("C++")]] @{
    if (@config.SampleType()[channel] != ConfigV0::FLOAT64) return ndarray<const double, 1>();
    return make_ndarray((const double*)(_int_data().data()+@config.data_offset(channel)), @config.Length()[channel]);
  @}

  /* Constructor with values for each attribute */
  @init()  [[auto, inline]];

}

}
