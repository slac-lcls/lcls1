/* Do not edit this file, as it is auto-generated */

#include <boost/python.hpp>
#include <boost/make_shared.hpp>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
#include "psddl_psana/acqiris.ddl.h" // inc_psana
#include "psddl_python/Converter.h"
#include "psddl_python/DdlWrapper.h"
#include "psddl_python/ConverterMap.h"
#include "psddl_python/ConverterBoostDef.h"
#include "psddl_python/ConverterBoostDefSharedPtr.h"

namespace psddl_python {
namespace Acqiris {

using namespace boost::python;
using boost::python::object;
using boost::shared_ptr;
using std::vector;

namespace {
template<typename T, std::vector<int> (T::*MF)() const>
PyObject* method_shape(const T *x) {
  return detail::vintToList((x->*MF)());
}
} // namespace

void createWrappers(PyObject* module) {
  DDL_CREATE_MODULE( "psana.Acqiris", 0, "The Python wrapper module for Acqiris types");
  Py_INCREF(submodule);
  PyModule_AddObject(module, "Acqiris", submodule);
  scope mod = object(handle<>(borrowed(submodule)));
  {
  scope outer = 
  class_<Psana::Acqiris::VertV1 >("VertV1", "Class containing Acqiris configuration data for vertical axis.", no_init)
    .def("fullScale", &Psana::Acqiris::VertV1::fullScale,"Full vertical scale.")
    .def("offset", &Psana::Acqiris::VertV1::offset,"Offset value.")
    .def("coupling", &Psana::Acqiris::VertV1::coupling,"Coupling mode.")
    .def("bandwidth", &Psana::Acqiris::VertV1::bandwidth,"Bandwidth enumeration.")
    .def("slope", &Psana::Acqiris::VertV1::slope,"Calculated slope.")
  ;

  enum_<Psana::Acqiris::VertV1::Coupling>("Coupling")
    .value("GND",Psana::Acqiris::VertV1::GND)
    .value("DC",Psana::Acqiris::VertV1::DC)
    .value("AC",Psana::Acqiris::VertV1::AC)
    .value("DC50ohm",Psana::Acqiris::VertV1::DC50ohm)
    .value("AC50ohm",Psana::Acqiris::VertV1::AC50ohm)
  ;

  enum_<Psana::Acqiris::VertV1::Bandwidth>("Bandwidth")
    .value("None",Psana::Acqiris::VertV1::None)
    .value("MHz25",Psana::Acqiris::VertV1::MHz25)
    .value("MHz700",Psana::Acqiris::VertV1::MHz700)
    .value("MHz200",Psana::Acqiris::VertV1::MHz200)
    .value("MHz20",Psana::Acqiris::VertV1::MHz20)
    .value("MHz35",Psana::Acqiris::VertV1::MHz35)
  ;
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDef<Psana::Acqiris::VertV1> >(-1));

  class_<Psana::Acqiris::HorizV1 >("HorizV1", "Class containing Acqiris configuration data for horizontal axis.", no_init)
    .def("sampInterval", &Psana::Acqiris::HorizV1::sampInterval,"Interval for single sample.")
    .def("delayTime", &Psana::Acqiris::HorizV1::delayTime,"Delay time.")
    .def("nbrSamples", &Psana::Acqiris::HorizV1::nbrSamples,"Number of samples.")
    .def("nbrSegments", &Psana::Acqiris::HorizV1::nbrSegments,"Number of segments.")
  ;
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDef<Psana::Acqiris::HorizV1> >(-1));

  {
  scope outer = 
  class_<Psana::Acqiris::TrigV1 >("TrigV1", "Class containing Acqiris configuration data for triggering.", no_init)
    .def("coupling", &Psana::Acqiris::TrigV1::coupling)
    .def("input", &Psana::Acqiris::TrigV1::input,"Trigger source")
    .def("slope", &Psana::Acqiris::TrigV1::slope,"Triggering slope.")
    .def("level", &Psana::Acqiris::TrigV1::level,"Trigger level.")
  ;

  enum_<Psana::Acqiris::TrigV1::Source>("Source")
    .value("Internal",Psana::Acqiris::TrigV1::Internal)
    .value("External",Psana::Acqiris::TrigV1::External)
  ;

  enum_<Psana::Acqiris::TrigV1::Coupling>("Coupling")
    .value("DC",Psana::Acqiris::TrigV1::DC)
    .value("AC",Psana::Acqiris::TrigV1::AC)
    .value("HFreject",Psana::Acqiris::TrigV1::HFreject)
    .value("DC50ohm",Psana::Acqiris::TrigV1::DC50ohm)
    .value("AC50ohm",Psana::Acqiris::TrigV1::AC50ohm)
  ;

  enum_<Psana::Acqiris::TrigV1::Slope>("Slope")
    .value("Positive",Psana::Acqiris::TrigV1::Positive)
    .value("Negative",Psana::Acqiris::TrigV1::Negative)
    .value("OutOfWindow",Psana::Acqiris::TrigV1::OutOfWindow)
    .value("IntoWindow",Psana::Acqiris::TrigV1::IntoWindow)
    .value("HFDivide",Psana::Acqiris::TrigV1::HFDivide)
    .value("SpikeStretcher",Psana::Acqiris::TrigV1::SpikeStretcher)
  ;
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDef<Psana::Acqiris::TrigV1> >(-1));

  {
  scope outer = 
  class_<Psana::Acqiris::ConfigV1, boost::shared_ptr<Psana::Acqiris::ConfigV1>, boost::noncopyable >("ConfigV1", "Class containing all Acqiris configuration data.", no_init)
    .def("nbrConvertersPerChannel", &Psana::Acqiris::ConfigV1::nbrConvertersPerChannel,"Number of ADCs per channel.")
    .def("channelMask", &Psana::Acqiris::ConfigV1::channelMask,"Bit mask for channels.")
    .def("nbrBanks", &Psana::Acqiris::ConfigV1::nbrBanks,"Total number of banks.")
    .def("trig", &Psana::Acqiris::ConfigV1::trig, return_value_policy<copy_const_reference>(),"Trigger configuration.")
    .def("horiz", &Psana::Acqiris::ConfigV1::horiz, return_value_policy<copy_const_reference>(),"Configuration for horizontal axis")
    .def("vert", &Psana::Acqiris::ConfigV1::vert,"Configuration for vertical axis (one per channel).")
    .def("nbrChannels", &Psana::Acqiris::ConfigV1::nbrChannels,"Number of channels calculated from channel bit mask.")
  ;
  scope().attr("Version")=1;
  scope().attr("TypeId")=int(Pds::TypeId::Id_AcqConfig);
  scope().attr("MaxChan")=20;
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::Acqiris::ConfigV1> >(Pds::TypeId::Id_AcqConfig));

  class_<Psana::Acqiris::TimestampV1 >("TimestampV1", "Class representing Acqiris timestamp value.", no_init)
    .def("pos", &Psana::Acqiris::TimestampV1::pos,"Horizontal position, for the segment, of the first (nominal) data point with respect \n            to the origin of the nominal trigger delay in seconds.")
    .def("timeStampLo", &Psana::Acqiris::TimestampV1::timeStampLo)
    .def("timeStampHi", &Psana::Acqiris::TimestampV1::timeStampHi)
    .def("value", &Psana::Acqiris::TimestampV1::value,"64-bit trigger timestamp, in units of picoseconds. The timestamp is the trigger time \n                with respect to an arbitrary time origin.")
  ;
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDef<Psana::Acqiris::TimestampV1> >(-1));

  {
  scope outer = 
  class_<Psana::Acqiris::DataDescV1Elem, boost::shared_ptr<Psana::Acqiris::DataDescV1Elem>, boost::noncopyable >("DataDescV1Elem", "Class representing Acqiris waveforms from single channel.", no_init)
    .def("nbrSamplesInSeg", &Psana::Acqiris::DataDescV1Elem::nbrSamplesInSeg,"Number of samples in one segment.")
    .def("indexFirstPoint", &Psana::Acqiris::DataDescV1Elem::indexFirstPoint)
    .def("nbrSegments", &Psana::Acqiris::DataDescV1Elem::nbrSegments,"Number of segments.")
    .def("timestamp", &Psana::Acqiris::DataDescV1Elem::timestamp,"Timestamps, one timestamp per segment.")
    .def("waveforms", &Psana::Acqiris::DataDescV1Elem::waveforms,"Waveforms data, two-dimensional array [nbrSegments()]*[nbrSamplesInSeg()]. Note that \n            unlike in pdsdata this already takes into account value of the indexFirstPoint so\n            that client code does not need to correct for this offset.")
  ;
  scope().attr("NumberOfBits")=10;
  scope().attr("BitShift")=6;
  scope().attr("_extraSize")=32;
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::Acqiris::DataDescV1Elem> >(-1));

  {
  scope outer = 
  class_<Psana::Acqiris::DataDescV1, boost::shared_ptr<Psana::Acqiris::DataDescV1>, boost::noncopyable >("DataDescV1", "Class containing waveform data (DataDescV1Elem) for all channels.", no_init)
    .def("data", &Psana::Acqiris::DataDescV1::data, return_internal_reference<>(),"Waveform data, one object per channel.")
    .def("data_shape", &method_shape<Psana::Acqiris::DataDescV1, &Psana::Acqiris::DataDescV1::data_shape>)
  ;
  scope().attr("Version")=1;
  scope().attr("TypeId")=int(Pds::TypeId::Id_AcqWaveform);
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::Acqiris::DataDescV1> >(Pds::TypeId::Id_AcqWaveform));

  {
  scope outer = 
  class_<Psana::Acqiris::TdcChannel >("TdcChannel", "Configuration for Acqiris TDC channel.", no_init)
    .def("channel", &Psana::Acqiris::TdcChannel::channel,"Channel type as integer number, clients should use channel() method instead.")
    .def("_mode_int", &Psana::Acqiris::TdcChannel::_mode_int,"Bitfield value, should not be used directly. Use mode() and slope()\n                in the client code.")
    .def("slope", &Psana::Acqiris::TdcChannel::slope)
    .def("mode", &Psana::Acqiris::TdcChannel::mode)
    .def("level", &Psana::Acqiris::TdcChannel::level)
  ;

  enum_<Psana::Acqiris::TdcChannel::Channel>("Channel")
    .value("Veto",Psana::Acqiris::TdcChannel::Veto)
    .value("Common",Psana::Acqiris::TdcChannel::Common)
    .value("Input1",Psana::Acqiris::TdcChannel::Input1)
    .value("Input2",Psana::Acqiris::TdcChannel::Input2)
    .value("Input3",Psana::Acqiris::TdcChannel::Input3)
    .value("Input4",Psana::Acqiris::TdcChannel::Input4)
    .value("Input5",Psana::Acqiris::TdcChannel::Input5)
    .value("Input6",Psana::Acqiris::TdcChannel::Input6)
  ;

  enum_<Psana::Acqiris::TdcChannel::Mode>("Mode")
    .value("Active",Psana::Acqiris::TdcChannel::Active)
    .value("Inactive",Psana::Acqiris::TdcChannel::Inactive)
  ;

  enum_<Psana::Acqiris::TdcChannel::Slope>("Slope")
    .value("Positive",Psana::Acqiris::TdcChannel::Positive)
    .value("Negative",Psana::Acqiris::TdcChannel::Negative)
  ;
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDef<Psana::Acqiris::TdcChannel> >(-1));

  {
  scope outer = 
  class_<Psana::Acqiris::TdcAuxIO >("TdcAuxIO", "configuration for auxiliary IO channel.", no_init)
    .def("channel", &Psana::Acqiris::TdcAuxIO::channel)
    .def("mode", &Psana::Acqiris::TdcAuxIO::mode)
    .def("term", &Psana::Acqiris::TdcAuxIO::term)
  ;

  enum_<Psana::Acqiris::TdcAuxIO::Channel>("Channel")
    .value("IOAux1",Psana::Acqiris::TdcAuxIO::IOAux1)
    .value("IOAux2",Psana::Acqiris::TdcAuxIO::IOAux2)
  ;

  enum_<Psana::Acqiris::TdcAuxIO::Mode>("Mode")
    .value("BankSwitch",Psana::Acqiris::TdcAuxIO::BankSwitch)
    .value("Marker",Psana::Acqiris::TdcAuxIO::Marker)
    .value("OutputLo",Psana::Acqiris::TdcAuxIO::OutputLo)
    .value("OutputHi",Psana::Acqiris::TdcAuxIO::OutputHi)
  ;

  enum_<Psana::Acqiris::TdcAuxIO::Termination>("Termination")
    .value("ZHigh",Psana::Acqiris::TdcAuxIO::ZHigh)
    .value("Z50",Psana::Acqiris::TdcAuxIO::Z50)
  ;
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDef<Psana::Acqiris::TdcAuxIO> >(-1));

  {
  scope outer = 
  class_<Psana::Acqiris::TdcVetoIO >("TdcVetoIO", "Class with configuration data for Veto IO channel.", no_init)
    .def("channel", &Psana::Acqiris::TdcVetoIO::channel)
    .def("mode", &Psana::Acqiris::TdcVetoIO::mode)
    .def("term", &Psana::Acqiris::TdcVetoIO::term)
  ;

  enum_<Psana::Acqiris::TdcVetoIO::Channel>("Channel")
    .value("ChVeto",Psana::Acqiris::TdcVetoIO::ChVeto)
  ;

  enum_<Psana::Acqiris::TdcVetoIO::Mode>("Mode")
    .value("Veto",Psana::Acqiris::TdcVetoIO::Veto)
    .value("SwitchVeto",Psana::Acqiris::TdcVetoIO::SwitchVeto)
    .value("InvertedVeto",Psana::Acqiris::TdcVetoIO::InvertedVeto)
    .value("InvertedSwitchVeto",Psana::Acqiris::TdcVetoIO::InvertedSwitchVeto)
  ;

  enum_<Psana::Acqiris::TdcVetoIO::Termination>("Termination")
    .value("ZHigh",Psana::Acqiris::TdcVetoIO::ZHigh)
    .value("Z50",Psana::Acqiris::TdcVetoIO::Z50)
  ;
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDef<Psana::Acqiris::TdcVetoIO> >(-1));

  {
  scope outer = 
  class_<Psana::Acqiris::TdcConfigV1, boost::shared_ptr<Psana::Acqiris::TdcConfigV1>, boost::noncopyable >("TdcConfigV1", "Class with complete Acqiris TDC configuration.", no_init)
    .def("channels", &Psana::Acqiris::TdcConfigV1::channels,"Channel configurations, one object per channel.")
    .def("auxio", &Psana::Acqiris::TdcConfigV1::auxio,"Axiliary configurations, one object per channel.")
    .def("veto", &Psana::Acqiris::TdcConfigV1::veto, return_value_policy<copy_const_reference>())
  ;
  scope().attr("Version")=1;
  scope().attr("TypeId")=int(Pds::TypeId::Id_AcqTdcConfig);
  scope().attr("NChannels")=8;
  scope().attr("NAuxIO")=2;
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::Acqiris::TdcConfigV1> >(Pds::TypeId::Id_AcqTdcConfig));

  {
  scope outer = 
  class_<Psana::Acqiris::TdcDataV1_Item >("TdcDataV1_Item", "Base class for all Acqiris TDC data objects.", no_init)
    .def("value", &Psana::Acqiris::TdcDataV1_Item::value,"Value as integer number whiis composed of several bit fields. Do not use value directly,\n                instead cast this object to one of the actual types and use corresponding methods.")
    .def("bf_val_", &Psana::Acqiris::TdcDataV1_Item::bf_val_)
    .def("source", &Psana::Acqiris::TdcDataV1_Item::source,"Source of this data object, use returned enum to distinguish between actual \n                types of data objecs and cast appropriately.")
    .def("bf_ofv_", &Psana::Acqiris::TdcDataV1_Item::bf_ofv_)
  ;

  enum_<Psana::Acqiris::TdcDataV1_Item::Source>("Source")
    .value("Comm",Psana::Acqiris::TdcDataV1_Item::Comm)
    .value("Chan1",Psana::Acqiris::TdcDataV1_Item::Chan1)
    .value("Chan2",Psana::Acqiris::TdcDataV1_Item::Chan2)
    .value("Chan3",Psana::Acqiris::TdcDataV1_Item::Chan3)
    .value("Chan4",Psana::Acqiris::TdcDataV1_Item::Chan4)
    .value("Chan5",Psana::Acqiris::TdcDataV1_Item::Chan5)
    .value("Chan6",Psana::Acqiris::TdcDataV1_Item::Chan6)
    .value("AuxIO",Psana::Acqiris::TdcDataV1_Item::AuxIO)
  ;
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDef<Psana::Acqiris::TdcDataV1_Item> >(-1));

  class_<Psana::Acqiris::TdcDataV1Common, boost::python::bases<Psana::Acqiris::TdcDataV1_Item> >("TdcDataV1Common", "Class for the \"common\" TDC data object.", no_init)
    .def("nhits", &Psana::Acqiris::TdcDataV1Common::nhits,"Returns number of hits.")
    .def("overflow", &Psana::Acqiris::TdcDataV1Common::overflow,"Returns overflow status.")
  ;
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDef<Psana::Acqiris::TdcDataV1Common> >(-1));

  class_<Psana::Acqiris::TdcDataV1Channel, boost::python::bases<Psana::Acqiris::TdcDataV1_Item> >("TdcDataV1Channel", "Class for the \"channel\" TDC data object.", no_init)
    .def("ticks", &Psana::Acqiris::TdcDataV1Channel::ticks,"Returns number of ticks.")
    .def("overflow", &Psana::Acqiris::TdcDataV1Channel::overflow,"Returns overflow status.")
    .def("time", &Psana::Acqiris::TdcDataV1Channel::time,"Ticks converted to time, tick resolution is 50 picosecond.")
  ;
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDef<Psana::Acqiris::TdcDataV1Channel> >(-1));

  {
  scope outer = 
  class_<Psana::Acqiris::TdcDataV1Marker, boost::python::bases<Psana::Acqiris::TdcDataV1_Item> >("TdcDataV1Marker", "Class for the \"marker\" TDC data object.", no_init)
    .def("type", &Psana::Acqiris::TdcDataV1Marker::type,"Returns type of the marker.")
  ;

  enum_<Psana::Acqiris::TdcDataV1Marker::Type>("Type")
    .value("AuxIOSwitch",Psana::Acqiris::TdcDataV1Marker::AuxIOSwitch)
    .value("EventCntSwitch",Psana::Acqiris::TdcDataV1Marker::EventCntSwitch)
    .value("MemFullSwitch",Psana::Acqiris::TdcDataV1Marker::MemFullSwitch)
    .value("AuxIOMarker",Psana::Acqiris::TdcDataV1Marker::AuxIOMarker)
  ;
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDef<Psana::Acqiris::TdcDataV1Marker> >(-1));

  {
  scope outer = 
  class_<Psana::Acqiris::TdcDataV1, boost::shared_ptr<Psana::Acqiris::TdcDataV1>, boost::noncopyable >("TdcDataV1", "Acqiris TDS data object is a container for TdcDataV1_Item object (or their\n            sub-types).", no_init)
    .def("data", &Psana::Acqiris::TdcDataV1::data,"Access TDC data items.")
  ;
  scope().attr("Version")=1;
  scope().attr("TypeId")=int(Pds::TypeId::Id_AcqTdcData);
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::Acqiris::TdcDataV1> >(Pds::TypeId::Id_AcqTdcData));

  {
    PyObject* unvlist = PyList_New(1);
    PyList_SET_ITEM(unvlist, 0, PyObject_GetAttrString(submodule, "TdcConfigV1"));
    PyObject_SetAttrString(submodule, "TdcConfig", unvlist);
    Py_CLEAR(unvlist);
  }
  {
    PyObject* unvlist = PyList_New(1);
    PyList_SET_ITEM(unvlist, 0, PyObject_GetAttrString(submodule, "TdcDataV1"));
    PyObject_SetAttrString(submodule, "TdcData", unvlist);
    Py_CLEAR(unvlist);
  }
  {
    PyObject* unvlist = PyList_New(1);
    PyList_SET_ITEM(unvlist, 0, PyObject_GetAttrString(submodule, "DataDescV1"));
    PyObject_SetAttrString(submodule, "DataDesc", unvlist);
    Py_CLEAR(unvlist);
  }
  {
    PyObject* unvlist = PyList_New(1);
    PyList_SET_ITEM(unvlist, 0, PyObject_GetAttrString(submodule, "ConfigV1"));
    PyObject_SetAttrString(submodule, "Config", unvlist);
    Py_CLEAR(unvlist);
  }
  detail::register_ndarray_to_list_cvt<const Psana::Acqiris::TdcChannel>();
  detail::register_ndarray_to_list_cvt<const Psana::Acqiris::TimestampV1>();
  detail::register_ndarray_to_numpy_cvt<const int16_t, 2>();
  detail::register_ndarray_to_list_cvt<const Psana::Acqiris::TdcAuxIO>();
  detail::register_ndarray_to_list_cvt<const Psana::Acqiris::TdcDataV1_Item>();
  detail::register_ndarray_to_list_cvt<const Psana::Acqiris::VertV1>();

} // createWrappers()
} // namespace Acqiris
} // namespace psddl_python