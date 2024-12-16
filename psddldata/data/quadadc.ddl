@package QuadAdc  {


//------------------QuadAdc ------------------
/* QuadAdc Class */
@type ConfigV1
  [[type_id(Id_QuadAdcConfig, 0)]]
  [[config_type]]
  [[pack(4)]]
{
  uint32_t _chanMask -> chanMask;	/* Channel Mask. */
  double   _delayTime -> delayTime;	/* Delay time. */
  uint32_t _interleaveMode -> interleaveMode; /* Interleave Mode. */
  uint32_t _nbrSamples -> nbrSamples;	/* Number of samples. */
  uint32_t _evtCode -> evtCode;	/* Event Code. */
  double _sampRate -> sampleRate; /* Sample Rate. */

  /* Constructor which takes values for every attribute */
  @init()  [[auto, inline]];

}
}

























