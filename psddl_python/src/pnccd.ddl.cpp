/* Do not edit this file, as it is auto-generated */

#include <boost/python.hpp>
#include <boost/make_shared.hpp>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
#include "psddl_psana/pnccd.ddl.h" // inc_psana
#include "psddl_python/Converter.h"
#include "psddl_python/DdlWrapper.h"
#include "psddl_python/ConverterMap.h"
#include "psddl_python/ConverterBoostDef.h"
#include "psddl_python/ConverterBoostDefSharedPtr.h"

namespace psddl_python {
namespace PNCCD {

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
  DDL_CREATE_MODULE( "psana.PNCCD", 0, "The Python wrapper module for PNCCD types");
  Py_INCREF(submodule);
  PyModule_AddObject(module, "PNCCD", submodule);
  scope mod = object(handle<>(borrowed(submodule)));
  {
  scope outer = 
  class_<Psana::PNCCD::ConfigV1, boost::shared_ptr<Psana::PNCCD::ConfigV1>, boost::noncopyable >("ConfigV1", "pnCCD configuration class ConfigV1", no_init)
    .def("numLinks", &Psana::PNCCD::ConfigV1::numLinks,"Number of links in the pnCCD.")
    .def("payloadSizePerLink", &Psana::PNCCD::ConfigV1::payloadSizePerLink,"Size of the payload in bytes for single link")
  ;
  scope().attr("Version")=1;
  scope().attr("TypeId")=int(Pds::TypeId::Id_pnCCDconfig);
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::PNCCD::ConfigV1> >(Pds::TypeId::Id_pnCCDconfig));

  {
  scope outer = 
  class_<Psana::PNCCD::ConfigV2, boost::shared_ptr<Psana::PNCCD::ConfigV2>, boost::noncopyable >("ConfigV2", "pnCCD configuration class ConfigV2", no_init)
    .def("numLinks", &Psana::PNCCD::ConfigV2::numLinks,"Number of links in the pnCCD.")
    .def("payloadSizePerLink", &Psana::PNCCD::ConfigV2::payloadSizePerLink,"Size of the payload in bytes for single link")
    .def("numChannels", &Psana::PNCCD::ConfigV2::numChannels,"Number of channels")
    .def("numRows", &Psana::PNCCD::ConfigV2::numRows,"Number of rows")
    .def("numSubmoduleChannels", &Psana::PNCCD::ConfigV2::numSubmoduleChannels,"Number of submodule channels")
    .def("numSubmoduleRows", &Psana::PNCCD::ConfigV2::numSubmoduleRows,"Number of submodule rows")
    .def("numSubmodules", &Psana::PNCCD::ConfigV2::numSubmodules,"Number of submodules")
    .def("camexMagic", &Psana::PNCCD::ConfigV2::camexMagic,"Magic word from CAMEX")
    .def("info", &Psana::PNCCD::ConfigV2::info,"Information data string")
    .def("timingFName", &Psana::PNCCD::ConfigV2::timingFName,"Timing file name string")
    .def("info_shape", &method_shape<Psana::PNCCD::ConfigV2, &Psana::PNCCD::ConfigV2::info_shape>)
    .def("timingFName_shape", &method_shape<Psana::PNCCD::ConfigV2, &Psana::PNCCD::ConfigV2::timingFName_shape>)
  ;
  scope().attr("Version")=2;
  scope().attr("TypeId")=int(Pds::TypeId::Id_pnCCDconfig);
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::PNCCD::ConfigV2> >(Pds::TypeId::Id_pnCCDconfig));

  class_<Psana::PNCCD::FrameV1, boost::shared_ptr<Psana::PNCCD::FrameV1>, boost::noncopyable >("FrameV1", "pnCCD class FrameV1, this is a class which is defined by origianl pdsdata package.", no_init)
    .def("specialWord", &Psana::PNCCD::FrameV1::specialWord,"Special values")
    .def("frameNumber", &Psana::PNCCD::FrameV1::frameNumber,"Frame number")
    .def("timeStampHi", &Psana::PNCCD::FrameV1::timeStampHi,"Most significant part of timestamp")
    .def("timeStampLo", &Psana::PNCCD::FrameV1::timeStampLo,"Least significant part of timestamp")
    .def("_data", &Psana::PNCCD::FrameV1::_data,"Frame data")
    .def("data", &Psana::PNCCD::FrameV1::data)
  ;
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::PNCCD::FrameV1> >(-1));

  {
  scope outer = 
  class_<Psana::PNCCD::FullFrameV1, boost::shared_ptr<Psana::PNCCD::FullFrameV1>, boost::noncopyable >("FullFrameV1", "This is a \"synthetic\" pnCCD frame which is four original 512x512 frames\n            glued together. This class does not exist in original pdsdata, it has been \n            introduced to psana to simplify access to full frame data in the user code.", no_init)
    .def("specialWord", &Psana::PNCCD::FullFrameV1::specialWord,"Special values")
    .def("frameNumber", &Psana::PNCCD::FullFrameV1::frameNumber,"Frame number")
    .def("timeStampHi", &Psana::PNCCD::FullFrameV1::timeStampHi,"Most significant part of timestamp")
    .def("timeStampLo", &Psana::PNCCD::FullFrameV1::timeStampLo,"Least significant part of timestamp")
    .def("data", &Psana::PNCCD::FullFrameV1::data,"Full frame data, image size is 1024x1024.")
  ;
  scope().attr("Version")=1;
  scope().attr("TypeId")=int(Pds::TypeId::Id_pnCCDframe);
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::PNCCD::FullFrameV1> >(Pds::TypeId::Id_pnCCDframe));

  {
  scope outer = 
  class_<Psana::PNCCD::FramesV1, boost::shared_ptr<Psana::PNCCD::FramesV1>, boost::noncopyable >("FramesV1", "pnCCD class FramesV1 which is a collection of FrameV1 objects, number of \n            frames in collection is determined by numLinks() method (which should return 4 \n            in most cases). This class does not exist in original pdsdata, has been \n            introduced to psana to help in organizing 4 small pnCCD frames together.", no_init)
    .def("frame", &Psana::PNCCD::FramesV1::frame, return_internal_reference<>(),"Number of frames is determined by numLinks() method.")
    .def("numLinks", &Psana::PNCCD::FramesV1::numLinks)
    .def("frame_shape", &method_shape<Psana::PNCCD::FramesV1, &Psana::PNCCD::FramesV1::frame_shape>)
  ;
  scope().attr("Version")=1;
  scope().attr("TypeId")=int(Pds::TypeId::Id_pnCCDframe);
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::PNCCD::FramesV1> >(Pds::TypeId::Id_pnCCDframe));

  {
    PyObject* unvlist = PyList_New(1);
    PyList_SET_ITEM(unvlist, 0, PyObject_GetAttrString(submodule, "FramesV1"));
    PyObject_SetAttrString(submodule, "Frames", unvlist);
    Py_CLEAR(unvlist);
  }
  {
    PyObject* unvlist = PyList_New(1);
    PyList_SET_ITEM(unvlist, 0, PyObject_GetAttrString(submodule, "FullFrameV1"));
    PyObject_SetAttrString(submodule, "FullFrame", unvlist);
    Py_CLEAR(unvlist);
  }
  {
    PyObject* unvlist = PyList_New(2);
    PyList_SET_ITEM(unvlist, 0, PyObject_GetAttrString(submodule, "ConfigV1"));
    PyList_SET_ITEM(unvlist, 1, PyObject_GetAttrString(submodule, "ConfigV2"));
    PyObject_SetAttrString(submodule, "Config", unvlist);
    Py_CLEAR(unvlist);
  }
  detail::register_ndarray_to_numpy_cvt<const uint16_t, 2>();
  detail::register_ndarray_to_numpy_cvt<const uint16_t, 1>();

} // createWrappers()
} // namespace PNCCD
} // namespace psddl_python
