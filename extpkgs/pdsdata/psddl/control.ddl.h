#ifndef PDS_CONTROL_DDL_H
#define PDS_CONTROL_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <iosfwd>
#include <cstddef>
#include <cstring>
#include "pdsdata/xtc/TypeId.hh"
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/ClockTime.hh"
namespace Pds {
namespace ControlData {

/** @class PVControl

  
*/

#pragma pack(push,4)

class PVControl {
public:
  enum { NameSize = 32 /**< Length of the name array. */ };
  enum { NoArray = 0xFFFFFFFF /**< Special value used for _index when PV is not an array */ };
  PVControl(const char* arg__name, uint32_t arg__index, double arg__value)
    : _index(arg__index), _value(arg__value)
  {
    if (arg__name) std::copy(arg__name, arg__name+(32), &_name[0]);
  }
  PVControl() {}
  /** Name of the control. */
  const char* name() const { return _name; }
  /** Index of the control PV (for arrays) or NoArray. */
  uint32_t index() const { return _index; }
  /** Value for this control. */
  double value() const { return _value; }
  /** Returns true if the control is an array. */
  uint8_t array() const;
  static uint32_t _sizeof() { return ((((((0+(1*(NameSize)))+4)+8)+4)-1)/4)*4; }
private:
  char	_name[NameSize];	/**< Name of the control. */
  uint32_t	_index;	/**< Index of the control PV (for arrays) or NoArray. */
  double	_value;	/**< Value for this control. */
};
#pragma pack(pop)

/** @class PVControlV1

  
*/

#pragma pack(push,4)

class PVControlV1 {
public:
  enum { NameSize = 128 /**< Length of the name array. */ };
  enum { NoArray = 0xFFFFFFFF /**< Special value used for _index when PV is not an array */ };
  PVControlV1(const char* arg__name, uint32_t arg__index, double arg__value)
    : _index(arg__index), _value(arg__value)
  {
    if (arg__name) std::copy(arg__name, arg__name+(128), &_name[0]);
  }
  PVControlV1() {}
  /** Name of the control. */
  const char* name() const { return _name; }
  /** Index of the control PV (for arrays) or NoArray. */
  uint32_t index() const { return _index; }
  /** Value for this control. */
  double value() const { return _value; }
  /** Returns true if the control is an array. */
  uint8_t array() const;
  static uint32_t _sizeof() { return ((((((0+(1*(NameSize)))+4)+8)+4)-1)/4)*4; }
private:
  char	_name[NameSize];	/**< Name of the control. */
  uint32_t	_index;	/**< Index of the control PV (for arrays) or NoArray. */
  double	_value;	/**< Value for this control. */
};
#pragma pack(pop)

/** @class PVMonitor

  
*/

#pragma pack(push,4)

class PVMonitor {
public:
  enum { NameSize = 32 /**< Length of the name array. */ };
  enum { NoArray = 0xFFFFFFFF /**< Special value used for _index when PV is not an array */ };
  PVMonitor(const char* arg__name, uint32_t arg__index, double arg__loValue, double arg__hiValue)
    : _index(arg__index), _loValue(arg__loValue), _hiValue(arg__hiValue)
  {
    if (arg__name) std::copy(arg__name, arg__name+(32), &_name[0]);
  }
  PVMonitor() {}
  /** Name of the control. */
  const char* name() const { return _name; }
  /** Index of the control PV (for arrays) or NoArray. */
  uint32_t index() const { return _index; }
  /** Lowest value for this monitor. */
  double loValue() const { return _loValue; }
  /** Highest value for this monitor. */
  double hiValue() const { return _hiValue; }
  /** Returns true if the monitor is an array. */
  uint8_t array() const;
  static uint32_t _sizeof() { return (((((((0+(1*(NameSize)))+4)+8)+8)+4)-1)/4)*4; }
private:
  char	_name[NameSize];	/**< Name of the control. */
  uint32_t	_index;	/**< Index of the control PV (for arrays) or NoArray. */
  double	_loValue;	/**< Lowest value for this monitor. */
  double	_hiValue;	/**< Highest value for this monitor. */
};
#pragma pack(pop)

/** @class PVMonitorV1

  
*/

#pragma pack(push,4)

class PVMonitorV1 {
public:
  enum { NameSize = 128 /**< Length of the name array. */ };
  enum { NoArray = 0xFFFFFFFF /**< Special value used for _index when PV is not an array */ };
  PVMonitorV1(const char* arg__name, uint32_t arg__index, double arg__loValue, double arg__hiValue)
    : _index(arg__index), _loValue(arg__loValue), _hiValue(arg__hiValue)
  {
    if (arg__name) std::copy(arg__name, arg__name+(128), &_name[0]);
  }
  PVMonitorV1() {}
  /** Name of the control. */
  const char* name() const { return _name; }
  /** Index of the control PV (for arrays) or NoArray. */
  uint32_t index() const { return _index; }
  /** Lowest value for this monitor. */
  double loValue() const { return _loValue; }
  /** Highest value for this monitor. */
  double hiValue() const { return _hiValue; }
  /** Returns true if the monitor is an array. */
  uint8_t array() const;
  static uint32_t _sizeof() { return (((((((0+(1*(NameSize)))+4)+8)+8)+4)-1)/4)*4; }
private:
  char	_name[NameSize];	/**< Name of the control. */
  uint32_t	_index;	/**< Index of the control PV (for arrays) or NoArray. */
  double	_loValue;	/**< Lowest value for this monitor. */
  double	_hiValue;	/**< Highest value for this monitor. */
};
#pragma pack(pop)

/** @class PVLabel

  
*/

#pragma pack(push,4)

class PVLabel {
public:
  enum { NameSize = 32 /**< Length of the PV name array. */ };
  enum { ValueSize = 64 /**< Length of the value array. */ };
  PVLabel(const char* arg__name, const char* arg__value)
  {
    if (arg__name) std::copy(arg__name, arg__name+(32), &_name[0]);
    if (arg__value) std::copy(arg__value, arg__value+(64), &_value[0]);
  }
  PVLabel() {}
  /** PV name. */
  const char* name() const { return _name; }
  /** Label value. */
  const char* value() const { return _value; }
  static uint32_t _sizeof() { return (((((0+(1*(NameSize)))+(1*(ValueSize)))+1)-1)/1)*1; }
private:
  char	_name[NameSize];	/**< PV name. */
  char	_value[ValueSize];	/**< Label value. */
};
#pragma pack(pop)

/** @class PVLabelV1

  
*/

#pragma pack(push,4)

class PVLabelV1 {
public:
  enum { NameSize = 128 /**< Length of the PV name array. */ };
  enum { ValueSize = 256 /**< Length of the value array. */ };
  PVLabelV1(const char* arg__name, const char* arg__value)
  {
    if (arg__name) std::copy(arg__name, arg__name+(128), &_name[0]);
    if (arg__value) std::copy(arg__value, arg__value+(256), &_value[0]);
  }
  PVLabelV1() {}
  /** PV name. */
  const char* name() const { return _name; }
  /** Label value. */
  const char* value() const { return _value; }
  static uint32_t _sizeof() { return (((((0+(1*(NameSize)))+(1*(ValueSize)))+1)-1)/1)*1; }
private:
  char	_name[NameSize];	/**< PV name. */
  char	_value[ValueSize];	/**< Label value. */
};
#pragma pack(pop)

/** @class ConfigV1

  
*/


class ConfigV1 {
public:
  enum { TypeId = Pds::TypeId::Id_ControlConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  ConfigV1(uint32_t arg__bf_events, uint8_t arg__bf_uses_duration, uint8_t arg__bf_uses_events, const Pds::ClockTime& arg__duration, uint32_t arg__npvControls, uint32_t arg__npvMonitors, const ControlData::PVControl* arg__pvControls, const ControlData::PVMonitor* arg__pvMonitors);
  ConfigV1() {}
  ConfigV1(const ConfigV1& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
  }
  ConfigV1& operator=(const ConfigV1& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
    return *this;
  }
  /** Maximum number of events per scan. */
  uint32_t events() const { return uint32_t(this->_control & 0x3fffffff); }
  /** returns true if the configuration uses duration control. */
  uint8_t uses_duration() const { return uint8_t((this->_control>>30) & 0x1); }
  /** returns true if the configuration uses events limit. */
  uint8_t uses_events() const { return uint8_t((this->_control>>31) & 0x1); }
  /** Maximum duration of the scan. */
  const Pds::ClockTime& duration() const { return _duration; }
  /** Number of PVControl objects in this configuration. */
  uint32_t npvControls() const { return _npvControls; }
  /** Number of PVMonitor objects in this configuration. */
  uint32_t npvMonitors() const { return _npvMonitors; }
  /** PVControl configuration objects

    Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const ControlData::PVControl, 1> pvControls(const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=24;
    const ControlData::PVControl* data = (const ControlData::PVControl*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const ControlData::PVControl>(owner, data), this->npvControls());
  }
  /** PVControl configuration objects

    Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const ControlData::PVControl, 1> pvControls() const { ptrdiff_t offset=24;
  const ControlData::PVControl* data = (const ControlData::PVControl*)(((char*)this)+offset);
  return make_ndarray(data, this->npvControls()); }
  /** PVMonitor configuration objects

    Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const ControlData::PVMonitor, 1> pvMonitors(const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=24+(44*(this->npvControls()));
    const ControlData::PVMonitor* data = (const ControlData::PVMonitor*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const ControlData::PVMonitor>(owner, data), this->npvMonitors());
  }
  /** PVMonitor configuration objects

    Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const ControlData::PVMonitor, 1> pvMonitors() const { ptrdiff_t offset=24+(44*(this->npvControls()));
  const ControlData::PVMonitor* data = (const ControlData::PVMonitor*)(((char*)this)+offset);
  return make_ndarray(data, this->npvMonitors()); }
  uint32_t _sizeof() const { return (((((24+(ControlData::PVControl::_sizeof()*(this->npvControls())))+(ControlData::PVMonitor::_sizeof()*(this->npvMonitors())))+4)-1)/4)*4; }
private:
  uint32_t	_control;
  uint32_t	_reserved;
  Pds::ClockTime	_duration;	/**< Maximum duration of the scan. */
  uint32_t	_npvControls;	/**< Number of PVControl objects in this configuration. */
  uint32_t	_npvMonitors;	/**< Number of PVMonitor objects in this configuration. */
  //ControlData::PVControl	_pvControls[this->npvControls()];
  //ControlData::PVMonitor	_pvMonitors[this->npvMonitors()];
};

/** @class ConfigV2

  
*/


class ConfigV2 {
public:
  enum { TypeId = Pds::TypeId::Id_ControlConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  ConfigV2(uint32_t arg__bf_events, uint8_t arg__bf_uses_duration, uint8_t arg__bf_uses_events, const Pds::ClockTime& arg__duration, uint32_t arg__npvControls, uint32_t arg__npvMonitors, uint32_t arg__npvLabels, const ControlData::PVControl* arg__pvControls, const ControlData::PVMonitor* arg__pvMonitors, const ControlData::PVLabel* arg__pvLabels);
  ConfigV2() {}
  ConfigV2(const ConfigV2& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
  }
  ConfigV2& operator=(const ConfigV2& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
    return *this;
  }
  /** Maximum number of events per scan. */
  uint32_t events() const { return uint32_t(this->_control & 0x3fffffff); }
  /** returns true if the configuration uses duration control. */
  uint8_t uses_duration() const { return uint8_t((this->_control>>30) & 0x1); }
  /** returns true if the configuration uses events limit. */
  uint8_t uses_events() const { return uint8_t((this->_control>>31) & 0x1); }
  /** Maximum duration of the scan. */
  const Pds::ClockTime& duration() const { return _duration; }
  /** Number of PVControl objects in this configuration. */
  uint32_t npvControls() const { return _npvControls; }
  /** Number of PVMonitor objects in this configuration. */
  uint32_t npvMonitors() const { return _npvMonitors; }
  /** Number of PVLabel objects in this configuration. */
  uint32_t npvLabels() const { return _npvLabels; }
  /** PVControl configuration objects

    Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const ControlData::PVControl, 1> pvControls(const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=28;
    const ControlData::PVControl* data = (const ControlData::PVControl*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const ControlData::PVControl>(owner, data), this->npvControls());
  }
  /** PVControl configuration objects

    Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const ControlData::PVControl, 1> pvControls() const { ptrdiff_t offset=28;
  const ControlData::PVControl* data = (const ControlData::PVControl*)(((char*)this)+offset);
  return make_ndarray(data, this->npvControls()); }
  /** PVMonitor configuration objects

    Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const ControlData::PVMonitor, 1> pvMonitors(const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=28+(44*(this->npvControls()));
    const ControlData::PVMonitor* data = (const ControlData::PVMonitor*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const ControlData::PVMonitor>(owner, data), this->npvMonitors());
  }
  /** PVMonitor configuration objects

    Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const ControlData::PVMonitor, 1> pvMonitors() const { ptrdiff_t offset=28+(44*(this->npvControls()));
  const ControlData::PVMonitor* data = (const ControlData::PVMonitor*)(((char*)this)+offset);
  return make_ndarray(data, this->npvMonitors()); }
  /** PVLabel configuration objects

    Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const ControlData::PVLabel, 1> pvLabels(const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=(28+(44*(this->npvControls())))+(52*(this->npvMonitors()));
    const ControlData::PVLabel* data = (const ControlData::PVLabel*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const ControlData::PVLabel>(owner, data), this->npvLabels());
  }
  /** PVLabel configuration objects

    Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const ControlData::PVLabel, 1> pvLabels() const { ptrdiff_t offset=(28+(44*(this->npvControls())))+(52*(this->npvMonitors()));
  const ControlData::PVLabel* data = (const ControlData::PVLabel*)(((char*)this)+offset);
  return make_ndarray(data, this->npvLabels()); }
  uint32_t _sizeof() const { return ((((((28+(ControlData::PVControl::_sizeof()*(this->npvControls())))+(ControlData::PVMonitor::_sizeof()*(this->npvMonitors())))+(ControlData::PVLabel::_sizeof()*(this->npvLabels())))+4)-1)/4)*4; }
private:
  uint32_t	_control;
  uint32_t	_reserved;
  Pds::ClockTime	_duration;	/**< Maximum duration of the scan. */
  uint32_t	_npvControls;	/**< Number of PVControl objects in this configuration. */
  uint32_t	_npvMonitors;	/**< Number of PVMonitor objects in this configuration. */
  uint32_t	_npvLabels;	/**< Number of PVLabel objects in this configuration. */
  //ControlData::PVControl	_pvControls[this->npvControls()];
  //ControlData::PVMonitor	_pvMonitors[this->npvMonitors()];
  //ControlData::PVLabel	_pvLabels[this->npvLabels()];
};

/** @class ConfigV3

  
*/


class ConfigV3 {
public:
  enum { TypeId = Pds::TypeId::Id_ControlConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 3 /**< XTC type version number */ };
  ConfigV3(uint32_t arg__bf_events, uint8_t arg__bf_uses_l3t_events, uint8_t arg__bf_uses_duration, uint8_t arg__bf_uses_events, const Pds::ClockTime& arg__duration, uint32_t arg__npvControls, uint32_t arg__npvMonitors, uint32_t arg__npvLabels, const ControlData::PVControl* arg__pvControls, const ControlData::PVMonitor* arg__pvMonitors, const ControlData::PVLabel* arg__pvLabels);
  ConfigV3() {}
  ConfigV3(const ConfigV3& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
  }
  ConfigV3& operator=(const ConfigV3& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
    return *this;
  }
  /** Maximum number of events per scan. */
  uint32_t events() const { return uint32_t(this->_control & 0x1fffffff); }
  /** returns true if the configuration uses l3trigger events limit. */
  uint8_t uses_l3t_events() const { return uint8_t((this->_control>>29) & 0x1); }
  /** returns true if the configuration uses duration control. */
  uint8_t uses_duration() const { return uint8_t((this->_control>>30) & 0x1); }
  /** returns true if the configuration uses events limit. */
  uint8_t uses_events() const { return uint8_t((this->_control>>31) & 0x1); }
  /** Maximum duration of the scan. */
  const Pds::ClockTime& duration() const { return _duration; }
  /** Number of PVControl objects in this configuration. */
  uint32_t npvControls() const { return _npvControls; }
  /** Number of PVMonitor objects in this configuration. */
  uint32_t npvMonitors() const { return _npvMonitors; }
  /** Number of PVLabel objects in this configuration. */
  uint32_t npvLabels() const { return _npvLabels; }
  /** PVControl configuration objects

    Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const ControlData::PVControl, 1> pvControls(const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=28;
    const ControlData::PVControl* data = (const ControlData::PVControl*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const ControlData::PVControl>(owner, data), this->npvControls());
  }
  /** PVControl configuration objects

    Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const ControlData::PVControl, 1> pvControls() const { ptrdiff_t offset=28;
  const ControlData::PVControl* data = (const ControlData::PVControl*)(((char*)this)+offset);
  return make_ndarray(data, this->npvControls()); }
  /** PVMonitor configuration objects

    Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const ControlData::PVMonitor, 1> pvMonitors(const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=28+(44*(this->npvControls()));
    const ControlData::PVMonitor* data = (const ControlData::PVMonitor*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const ControlData::PVMonitor>(owner, data), this->npvMonitors());
  }
  /** PVMonitor configuration objects

    Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const ControlData::PVMonitor, 1> pvMonitors() const { ptrdiff_t offset=28+(44*(this->npvControls()));
  const ControlData::PVMonitor* data = (const ControlData::PVMonitor*)(((char*)this)+offset);
  return make_ndarray(data, this->npvMonitors()); }
  /** PVLabel configuration objects

    Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const ControlData::PVLabel, 1> pvLabels(const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=(28+(44*(this->npvControls())))+(52*(this->npvMonitors()));
    const ControlData::PVLabel* data = (const ControlData::PVLabel*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const ControlData::PVLabel>(owner, data), this->npvLabels());
  }
  /** PVLabel configuration objects

    Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const ControlData::PVLabel, 1> pvLabels() const { ptrdiff_t offset=(28+(44*(this->npvControls())))+(52*(this->npvMonitors()));
  const ControlData::PVLabel* data = (const ControlData::PVLabel*)(((char*)this)+offset);
  return make_ndarray(data, this->npvLabels()); }
  uint32_t _sizeof() const { return ((((((28+(ControlData::PVControl::_sizeof()*(this->npvControls())))+(ControlData::PVMonitor::_sizeof()*(this->npvMonitors())))+(ControlData::PVLabel::_sizeof()*(this->npvLabels())))+4)-1)/4)*4; }
private:
  uint32_t	_control;
  uint32_t	_reserved;
  Pds::ClockTime	_duration;	/**< Maximum duration of the scan. */
  uint32_t	_npvControls;	/**< Number of PVControl objects in this configuration. */
  uint32_t	_npvMonitors;	/**< Number of PVMonitor objects in this configuration. */
  uint32_t	_npvLabels;	/**< Number of PVLabel objects in this configuration. */
  //ControlData::PVControl	_pvControls[this->npvControls()];
  //ControlData::PVMonitor	_pvMonitors[this->npvMonitors()];
  //ControlData::PVLabel	_pvLabels[this->npvLabels()];
};

/** @class ConfigV4

  
*/


class ConfigV4 {
public:
  enum { TypeId = Pds::TypeId::Id_ControlConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 4 /**< XTC type version number */ };
  ConfigV4(uint32_t arg__bf_events, uint8_t arg__bf_uses_l3t_events, uint8_t arg__bf_uses_duration, uint8_t arg__bf_uses_events, const Pds::ClockTime& arg__duration, uint32_t arg__npvControls, uint32_t arg__npvMonitors, uint32_t arg__npvLabels, const ControlData::PVControlV1* arg__pvControls, const ControlData::PVMonitorV1* arg__pvMonitors, const ControlData::PVLabelV1* arg__pvLabels);
  ConfigV4() {}
  ConfigV4(const ConfigV4& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
  }
  ConfigV4& operator=(const ConfigV4& other) {
    const char* src = reinterpret_cast<const char*>(&other);
    std::copy(src, src+other._sizeof(), reinterpret_cast<char*>(this));
    return *this;
  }
  /** Maximum number of events per scan. */
  uint32_t events() const { return uint32_t(this->_control & 0x1fffffff); }
  /** returns true if the configuration uses l3trigger events limit. */
  uint8_t uses_l3t_events() const { return uint8_t((this->_control>>29) & 0x1); }
  /** returns true if the configuration uses duration control. */
  uint8_t uses_duration() const { return uint8_t((this->_control>>30) & 0x1); }
  /** returns true if the configuration uses events limit. */
  uint8_t uses_events() const { return uint8_t((this->_control>>31) & 0x1); }
  /** Maximum duration of the scan. */
  const Pds::ClockTime& duration() const { return _duration; }
  /** Number of PVControl objects in this configuration. */
  uint32_t npvControls() const { return _npvControls; }
  /** Number of PVMonitor objects in this configuration. */
  uint32_t npvMonitors() const { return _npvMonitors; }
  /** Number of PVLabel objects in this configuration. */
  uint32_t npvLabels() const { return _npvLabels; }
  /** PVControl configuration objects

    Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const ControlData::PVControlV1, 1> pvControls(const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=28;
    const ControlData::PVControlV1* data = (const ControlData::PVControlV1*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const ControlData::PVControlV1>(owner, data), this->npvControls());
  }
  /** PVControl configuration objects

    Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const ControlData::PVControlV1, 1> pvControls() const { ptrdiff_t offset=28;
  const ControlData::PVControlV1* data = (const ControlData::PVControlV1*)(((char*)this)+offset);
  return make_ndarray(data, this->npvControls()); }
  /** PVMonitor configuration objects

    Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const ControlData::PVMonitorV1, 1> pvMonitors(const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=28+(140*(this->npvControls()));
    const ControlData::PVMonitorV1* data = (const ControlData::PVMonitorV1*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const ControlData::PVMonitorV1>(owner, data), this->npvMonitors());
  }
  /** PVMonitor configuration objects

    Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const ControlData::PVMonitorV1, 1> pvMonitors() const { ptrdiff_t offset=28+(140*(this->npvControls()));
  const ControlData::PVMonitorV1* data = (const ControlData::PVMonitorV1*)(((char*)this)+offset);
  return make_ndarray(data, this->npvMonitors()); }
  /** PVLabel configuration objects

    Note: this overloaded method accepts shared pointer argument which must point to an object containing
    this instance, the returned ndarray object can be used even after this instance disappears. */
  template <typename T>
  ndarray<const ControlData::PVLabelV1, 1> pvLabels(const boost::shared_ptr<T>& owner) const { 
    ptrdiff_t offset=(28+(140*(this->npvControls())))+(148*(this->npvMonitors()));
    const ControlData::PVLabelV1* data = (const ControlData::PVLabelV1*)(((char*)this)+offset);
    return make_ndarray(boost::shared_ptr<const ControlData::PVLabelV1>(owner, data), this->npvLabels());
  }
  /** PVLabel configuration objects

    Note: this method returns ndarray instance which does not control lifetime
    of the data, do not use returned ndarray after this instance disappears. */
  ndarray<const ControlData::PVLabelV1, 1> pvLabels() const { ptrdiff_t offset=(28+(140*(this->npvControls())))+(148*(this->npvMonitors()));
  const ControlData::PVLabelV1* data = (const ControlData::PVLabelV1*)(((char*)this)+offset);
  return make_ndarray(data, this->npvLabels()); }
  uint32_t _sizeof() const { return ((((((28+(ControlData::PVControlV1::_sizeof()*(this->npvControls())))+(ControlData::PVMonitorV1::_sizeof()*(this->npvMonitors())))+(ControlData::PVLabelV1::_sizeof()*(this->npvLabels())))+4)-1)/4)*4; }
private:
  uint32_t	_control;
  uint32_t	_reserved;
  Pds::ClockTime	_duration;	/**< Maximum duration of the scan. */
  uint32_t	_npvControls;	/**< Number of PVControl objects in this configuration. */
  uint32_t	_npvMonitors;	/**< Number of PVMonitor objects in this configuration. */
  uint32_t	_npvLabels;	/**< Number of PVLabel objects in this configuration. */
  //ControlData::PVControlV1	_pvControls[this->npvControls()];
  //ControlData::PVMonitorV1	_pvMonitors[this->npvMonitors()];
  //ControlData::PVLabelV1	_pvLabels[this->npvLabels()];
};
} // namespace ControlData
} // namespace Pds
#endif // PDS_CONTROL_DDL_H
