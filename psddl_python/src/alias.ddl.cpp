/* Do not edit this file, as it is auto-generated */

#include <boost/python.hpp>
#include <boost/make_shared.hpp>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
#include "psddl_psana/alias.ddl.h" // inc_psana
#include "psddl_python/Converter.h"
#include "psddl_python/DdlWrapper.h"
#include "psddl_python/ConverterMap.h"
#include "psddl_python/ConverterBoostDef.h"
#include "psddl_python/ConverterBoostDefSharedPtr.h"

namespace psddl_python {
namespace Alias {

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
  DDL_CREATE_MODULE( "psana.Alias", 0, "The Python wrapper module for Alias types");
  Py_INCREF(submodule);
  PyModule_AddObject(module, "Alias", submodule);
  scope mod = object(handle<>(borrowed(submodule)));
  {
  scope outer = 
  class_<Psana::Alias::SrcAlias >("SrcAlias", no_init)
    .def("src", &Psana::Alias::SrcAlias::src, return_value_policy<copy_const_reference>(),"The src identifier")
    .def("aliasName", &Psana::Alias::SrcAlias::aliasName,"Alias name for src identifier")
    .def("operator<", &Psana::Alias::SrcAlias::operator<)
    .def("operator==", &Psana::Alias::SrcAlias::operator==)
    .def("aliasName_shape", &method_shape<Psana::Alias::SrcAlias, &Psana::Alias::SrcAlias::aliasName_shape>)
  ;
  scope().attr("AliasNameMax")=31;
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDef<Psana::Alias::SrcAlias> >(-1));

  {
  scope outer = 
  class_<Psana::Alias::ConfigV1, boost::shared_ptr<Psana::Alias::ConfigV1>, boost::noncopyable >("ConfigV1", no_init)
    .def("numSrcAlias", &Psana::Alias::ConfigV1::numSrcAlias,"Number of alias definitions")
    .def("srcAlias", &Psana::Alias::ConfigV1::srcAlias,"SrcAlias configuration objects")
  ;
  scope().attr("Version")=1;
  scope().attr("TypeId")=int(Pds::TypeId::Id_AliasConfig);
  }
  ConverterMap::instance().addConverter(boost::make_shared<ConverterBoostDefSharedPtr<Psana::Alias::ConfigV1> >(Pds::TypeId::Id_AliasConfig));

  {
    PyObject* unvlist = PyList_New(1);
    PyList_SET_ITEM(unvlist, 0, PyObject_GetAttrString(submodule, "ConfigV1"));
    PyObject_SetAttrString(submodule, "Config", unvlist);
    Py_CLEAR(unvlist);
  }
  detail::register_ndarray_to_list_cvt<const Psana::Alias::SrcAlias>();

} // createWrappers()
} // namespace Alias
} // namespace psddl_python
