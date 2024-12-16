@package Streak {
//------------------ ConfigV1 ------------------
@type ConfigV1
  [[type_id(Id_StreakConfig, 1)]]
  [[config_type]]
  [[pack(4)]]
{
  @const int32_t Row_Pixels = 1024;
  @const int32_t Column_Pixels = 1344;
  @const int32_t NumCalibConstants = 3;

  @enum DeviceMode (uint32_t) {
    Focus   = 0,
    Operate = 1,  
  }

  @enum ShutterMode (uint32_t) {
    Closed  = 0,
    Open    = 1,
  }

  @enum GateMode (uint32_t) {
    Normal    = 0,
    Gate      = 1,
    OpenFixed = 2,
  }

  @enum TriggerMode (uint32_t) {
    Single      = 0,
    Continuous  = 1,
  }

  @enum CalibScale (uint32_t) {
    Nanoseconds   = 0,
    Microseconds  = 1,
    Milliseconds  = 2,
    Seconds       = 3,
  }

  /* The time range of the camera (in ps). */
  uint64_t _timeRange -> timeRange;
  /* The trigger mode of the camera. */
  DeviceMode _mode -> mode;
  /* The gate mode of the camera. */
  GateMode _gate -> gate;
  /* Camera II-gain value. */
  uint32_t _gain -> gain;
  /* The shutter configuration of the camera. */
  ShutterMode _shutter -> shutter;
  /* The trigger mode of the camera. */
  TriggerMode _triggerMode -> triggerMode;
  /* The focus mode time out in minutes. */
  uint32_t _focusTimeOver -> focusTimeOver;
  /* The configured exposure time of the camera in seconds. */
  double _exposureTime -> exposureTime;
  /* Time calibration scale (ns, us, ms, or s). */
  CalibScale _calibScale -> calibScale;
  /* Time calibration constants (c0 + c1 * n + c2 * n * n). */
  double _calib[NumCalibConstants] -> calib;

  /* Factor for converting the time calibration value to seconds. */
  double calibScaleFactor()
  [[language("C++")]] @{
    double factor = 1.0;
    switch(@self.calibScale()) {
      case Nanoseconds:
        factor = 1e-9;
        break;
      case Microseconds:
        factor = 1e-6;
        break;
      case Milliseconds:
        factor = 1e-3;
        break;
      case Seconds:
        factor = 1.0;
        break;
    }
    return factor;
  @}

  /* The X-axis pixel to time mapping in units set in calibScale. */
  double[] calibTimes()
  [[language("C++")]] @{
    unsigned shape[1] = {Column_Pixels};
    ndarray<double,1> times(shape);
    times[0] = 0;
    for (unsigned n=1; n<Column_Pixels; ++n) {
      times[n] = times[n - 1] + (@self._calib[0] + @self._calib[1] * n + @self._calib[2] * n * n);
    }
    return times;
  @}

  /* The X-axis pixel to time mapping in seconds. */
  double[] calibTimesInSeconds()
  [[language("C++")]] @{
    double factor = @self.calibScaleFactor();
    unsigned shape[1] = {Column_Pixels};
    ndarray<double,1> times(shape);
    times[0] = 0;
    for (unsigned n=1; n<Column_Pixels; ++n) {
      times[n] = times[n - 1] + (@self._calib[0] + @self._calib[1] * n + @self._calib[2] * n * n) * factor;
    }
    return times;
  @}

  /* Constructor with values for each attribute */
  @init()  [[auto, inline]];
}

} //- @package Streak
