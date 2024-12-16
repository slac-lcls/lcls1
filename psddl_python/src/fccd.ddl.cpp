/* Do not edit this file, as it is auto-generated */

#include <boost/python.hpp>
#include <boost/make_shared.hpp>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
#include "psddl_psana/fccd.ddl.h" // inc_psana
#include "psddl_python/Converter.h"
#include "psddl_python/DdlWrapper.h"
#include "psddl_python/ConverterMap.h"
#include "psddl_python/ConverterBoostDef.h"
#include "psddl_python/ConverterBoostDefSharedPtr.h"

namespace psddl_python {
namespace FCCD {

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
  DDL_CREATE_MODULE( "psana.FCCD", 0, "The Python wrapper module for FCCD types");
  Py_INCREF(submodule);
  PyModule_AddObject(module, "FCCD", submodule);
  scope mod = object(handle<>(borrowed(submodule)));
  {
  scope outer = 
  class_<Psana::FCCD::FccdConfigV1, boost::shared_ptr<Psana::FCCD::FccdConfigV1>, boost::noncopyable >("FccdConfigV1", no_init)
    .def("outputMode", &Psana::FCCD::FccdConfigV1::outputMode)
    .def("width", &Psana::FCCD::FccdConfigV1::width)
    .def("height", &Psana::FCCD::FccdConfigV1::height)
    .def("trimmedWidth", &Psana::FCCD::FccdConfigV1::trimmedWidth)
    .def("trimmedHeight", &Psana::FCCD::FccdConfigV1::trimmedHeight)
  ;

  enum_<Psana::FCCD::FccdConfigV1::Depth>("Depth")
    .value("Sixteen_bit",Psana::FCCD::FccdConfigV1::Sixteen_bit)
  ;

  enum_<Psana::FCCD::FccdConfigV1::Output_Source>("Output_Source")
    .value("Output_FIFO",Psana::FCCD::FccdConfigV1::Output_FIFO)
    .value("Output_Pattern4",Psana::FCCD::FccdConfigV1::Output_Pattern4)
  ;
  scope().attr("Version")=1;
  scope().attr("TypeId")=int(Pds::TypeId::Id_FccdConfig);
  scope().attr("Row_Pixels")=500;
  scope().attr("Column_Pixels")=576;
  scope().attr("Trimmed_Row_Pixels")=480;
  scope().attr("Trimmed_Column_Pixels")=480;
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::FCCD::FccdConfigV1> >(Pds::TypeId::Id_FccdConfig));

  {
  scope outer = 
  class_<Psana::FCCD::FccdConfigV2, boost::shared_ptr<Psana::FCCD::FccdConfigV2>, boost::noncopyable >("FccdConfigV2", no_init)
    .def("outputMode", &Psana::FCCD::FccdConfigV2::outputMode)
    .def("ccdEnable", &Psana::FCCD::FccdConfigV2::ccdEnable)
    .def("focusMode", &Psana::FCCD::FccdConfigV2::focusMode)
    .def("exposureTime", &Psana::FCCD::FccdConfigV2::exposureTime)
    .def("dacVoltages", &Psana::FCCD::FccdConfigV2::dacVoltages)
    .def("waveforms", &Psana::FCCD::FccdConfigV2::waveforms)
    .def("width", &Psana::FCCD::FccdConfigV2::width)
    .def("height", &Psana::FCCD::FccdConfigV2::height)
    .def("trimmedWidth", &Psana::FCCD::FccdConfigV2::trimmedWidth)
    .def("trimmedHeight", &Psana::FCCD::FccdConfigV2::trimmedHeight)
  ;

  enum_<Psana::FCCD::FccdConfigV2::Depth>("Depth")
    .value("Eight_bit",Psana::FCCD::FccdConfigV2::Eight_bit)
    .value("Sixteen_bit",Psana::FCCD::FccdConfigV2::Sixteen_bit)
  ;

  enum_<Psana::FCCD::FccdConfigV2::Output_Source>("Output_Source")
    .value("Output_FIFO",Psana::FCCD::FccdConfigV2::Output_FIFO)
    .value("Test_Pattern1",Psana::FCCD::FccdConfigV2::Test_Pattern1)
    .value("Test_Pattern2",Psana::FCCD::FccdConfigV2::Test_Pattern2)
    .value("Test_Pattern3",Psana::FCCD::FccdConfigV2::Test_Pattern3)
    .value("Test_Pattern4",Psana::FCCD::FccdConfigV2::Test_Pattern4)
  ;
  scope().attr("Version")=2;
  scope().attr("TypeId")=int(Pds::TypeId::Id_FccdConfig);
  scope().attr("Row_Pixels")=500;
  scope().attr("Column_Pixels")=576 * 2;
  scope().attr("Trimmed_Row_Pixels")=480;
  scope().attr("Trimmed_Column_Pixels")=480;
  scope().attr("NVoltages")=17;
  scope().attr("NWaveforms")=15;
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::FCCD::FccdConfigV2> >(Pds::TypeId::Id_FccdConfig));

  {
    PyObject* unvlist = PyList_New(2);
    PyList_SET_ITEM(unvlist, 0, PyObject_GetAttrString(submodule, "FccdConfigV1"));
    PyList_SET_ITEM(unvlist, 1, PyObject_GetAttrString(submodule, "FccdConfigV2"));
    PyObject_SetAttrString(submodule, "FccdConfig", unvlist);
    Py_CLEAR(unvlist);
  }
  detail::register_ndarray_to_numpy_cvt<const float, 1>();
  detail::register_ndarray_to_numpy_cvt<const uint16_t, 1>();

} // createWrappers()
} // namespace FCCD
} // namespace psddl_python
