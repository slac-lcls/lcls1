#ifndef PSANA_L3T_DDL_H
#define PSANA_L3T_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <iosfwd>
#include <cstring>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
namespace Psana {
namespace L3T {

/** @class ConfigV1

  
*/


class ConfigV1 {
public:
  enum { TypeId = Pds::TypeId::Id_L3TConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  virtual ~ConfigV1();
  /** Length of the module identification string */
  virtual uint32_t module_id_len() const = 0;
  /** Length of the description string */
  virtual uint32_t desc_len() const = 0;
  /** The module identification string */
  virtual const char* module_id() const = 0;
  /** The description string */
  virtual const char* desc() const = 0;
  /** Method which returns the shape (dimensions) of the data returned by module_id() method. */
  virtual std::vector<int> module_id_shape() const = 0;
  /** Method which returns the shape (dimensions) of the data returned by desc() method. */
  virtual std::vector<int> desc_shape() const = 0;
};

/** @class DataV1

  
*/


class DataV1 {
public:
  enum { TypeId = Pds::TypeId::Id_L3TData /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  virtual ~DataV1();
  /** Module trigger decision */
  virtual uint32_t accept() const = 0;
};

/** @class DataV2

  
*/


class DataV2 {
public:
  enum { TypeId = Pds::TypeId::Id_L3TData /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  enum Result {
    Fail,
    Pass,
    None,
  };
  enum Bias {
    Unbiased,
    Biased,
  };
  virtual ~DataV2();
  virtual uint32_t accept() const = 0;
  /** Returns L3T Decision : None = insufficient information/resources */
  virtual L3T::DataV2::Result result() const = 0;
  /** Returns L3T Bias : Unbiased = recorded independent of decision */
  virtual L3T::DataV2::Bias bias() const = 0;
};
std::ostream& operator<<(std::ostream& str, L3T::DataV2::Result enval);
std::ostream& operator<<(std::ostream& str, L3T::DataV2::Bias enval);
} // namespace L3T
} // namespace Psana
#endif // PSANA_L3T_DDL_H