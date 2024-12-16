/* Do not edit this file, as it is auto-generated */

#include <boost/python.hpp>
#include <boost/make_shared.hpp>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
#include "psddl_psana/genericpgp.ddl.h" // inc_psana
#include "psddl_python/Converter.h"
#include "psddl_python/DdlWrapper.h"
#include "psddl_python/ConverterMap.h"
#include "psddl_python/ConverterBoostDef.h"
#include "psddl_python/ConverterBoostDefSharedPtr.h"

namespace psddl_python {
namespace GenericPgp {

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
  DDL_CREATE_MODULE( "psana.GenericPgp", 0, "The Python wrapper module for GenericPgp types");
  Py_INCREF(submodule);
  PyModule_AddObject(module, "GenericPgp", submodule);
  scope mod = object(handle<>(borrowed(submodule)));
  class_<Psana::GenericPgp::CDimension, boost::shared_ptr<Psana::GenericPgp::CDimension>, boost::noncopyable >("CDimension", no_init)
    .def("rows", &Psana::GenericPgp::CDimension::rows)
    .def("columns", &Psana::GenericPgp::CDimension::columns)
  ;
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::GenericPgp::CDimension> >(-1));

  {
  scope outer = 
  class_<Psana::GenericPgp::CRegister >("CRegister", no_init)
    .def("action", &Psana::GenericPgp::CRegister::action,"Configuration action")
    .def("datasize", &Psana::GenericPgp::CRegister::datasize,"Size of register access (in uint32_t's)")
    .def("address", &Psana::GenericPgp::CRegister::address,"Register access address")
    .def("offset", &Psana::GenericPgp::CRegister::offset,"Payload offset")
    .def("mask", &Psana::GenericPgp::CRegister::mask,"Register value mask")
  ;

  enum_<Psana::GenericPgp::CRegister::Action>("Action")
    .value("RegisterRead",Psana::GenericPgp::CRegister::RegisterRead)
    .value("RegisterWrite",Psana::GenericPgp::CRegister::RegisterWrite)
    .value("RegisterWriteA",Psana::GenericPgp::CRegister::RegisterWriteA)
    .value("RegisterVerify",Psana::GenericPgp::CRegister::RegisterVerify)
    .value("Spin",Psana::GenericPgp::CRegister::Spin)
    .value("Usleep",Psana::GenericPgp::CRegister::Usleep)
    .value("Flush",Psana::GenericPgp::CRegister::Flush)
  ;
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDef<Psana::GenericPgp::CRegister> >(-1));

  class_<Psana::GenericPgp::CStream >("CStream", no_init)
    .def("pgp_channel", &Psana::GenericPgp::CStream::pgp_channel,"PGP virtual channel ID")
    .def("data_type", &Psana::GenericPgp::CStream::data_type,"Event data type ID")
    .def("config_type", &Psana::GenericPgp::CStream::config_type,"Configuration data type ID")
    .def("config_offset", &Psana::GenericPgp::CStream::config_offset,"Location of configuration data")
  ;
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDef<Psana::GenericPgp::CStream> >(-1));

  {
  scope outer = 
  class_<Psana::GenericPgp::ConfigV1, boost::shared_ptr<Psana::GenericPgp::ConfigV1>, boost::noncopyable >("ConfigV1", no_init)
    .def("id", &Psana::GenericPgp::ConfigV1::id,"Serial number identifying the array")
    .def("frame_dim", &Psana::GenericPgp::ConfigV1::frame_dim, return_internal_reference<1>(),"Dimensions of the frame data from the array")
    .def("aux_dim", &Psana::GenericPgp::ConfigV1::aux_dim, return_internal_reference<1>(),"Dimensions of the auxillary data from the array")
    .def("env_dim", &Psana::GenericPgp::ConfigV1::env_dim, return_internal_reference<1>(),"Dimensions of the environmental data from the array")
    .def("number_of_registers", &Psana::GenericPgp::ConfigV1::number_of_registers,"Number of registers in the sequence array")
    .def("number_of_sequences", &Psana::GenericPgp::ConfigV1::number_of_sequences,"Number of (sub)sequences of register operations in the array")
    .def("number_of_streams", &Psana::GenericPgp::ConfigV1::number_of_streams)
    .def("payload_size", &Psana::GenericPgp::ConfigV1::payload_size)
    .def("pixel_settings", &Psana::GenericPgp::ConfigV1::pixel_settings)
    .def("sequence_length", &Psana::GenericPgp::ConfigV1::sequence_length,"Lengths of (sub)sequence register operations in the array")
    .def("sequence", &Psana::GenericPgp::ConfigV1::sequence,"Register Operations")
    .def("stream", &Psana::GenericPgp::ConfigV1::stream,"Stream readout configuration")
    .def("payload", &Psana::GenericPgp::ConfigV1::payload,"Stream and Register Data")
    .def("numberOfRows", &Psana::GenericPgp::ConfigV1::numberOfRows,"Number of rows in a readout unit")
    .def("numberOfColumns", &Psana::GenericPgp::ConfigV1::numberOfColumns,"Number of columns in a readout unit")
    .def("lastRowExclusions", &Psana::GenericPgp::ConfigV1::lastRowExclusions,"Number of rows in the auxillary data")
    .def("numberOfAsics", &Psana::GenericPgp::ConfigV1::numberOfAsics,"Number of elements in environmental data")
  ;
  scope().attr("Version")=1;
  scope().attr("TypeId")=int(Pds::TypeId::Id_GenericPgpConfig);
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::GenericPgp::ConfigV1> >(Pds::TypeId::Id_GenericPgpConfig));

  {
    PyObject* unvlist = PyList_New(1);
    PyList_SET_ITEM(unvlist, 0, PyObject_GetAttrString(submodule, "ConfigV1"));
    PyObject_SetAttrString(submodule, "Config", unvlist);
    Py_CLEAR(unvlist);
  }
  detail::register_ndarray_to_list_cvt<const Psana::GenericPgp::CRegister>();
  detail::register_ndarray_to_numpy_cvt<const uint32_t, 1>();
  detail::register_ndarray_to_numpy_cvt<const uint32_t, 2>();
  detail::register_ndarray_to_list_cvt<const Psana::GenericPgp::CStream>();

} // createWrappers()
} // namespace GenericPgp
} // namespace psddl_python
