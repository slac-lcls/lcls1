
// *** Do not edit this file, it is auto-generated ***

#include <cstddef>
#include "psddl_psana/l3t.ddl.h"
#include <iostream>
namespace Psana {
namespace L3T {

ConfigV1::~ConfigV1() {}


DataV1::~DataV1() {}


DataV2::~DataV2() {}

std::ostream& operator<<(std::ostream& str, L3T::DataV2::Result enval) {
  const char* val;
  switch (enval) {
  case L3T::DataV2::Fail:
    val = "Fail";
    break;
  case L3T::DataV2::Pass:
    val = "Pass";
    break;
  case L3T::DataV2::None:
    val = "None";
    break;
  default:
    return str << "Result(" << int(enval) << ")";
  }
  return str << val;
}
std::ostream& operator<<(std::ostream& str, L3T::DataV2::Bias enval) {
  const char* val;
  switch (enval) {
  case L3T::DataV2::Unbiased:
    val = "Unbiased";
    break;
  case L3T::DataV2::Biased:
    val = "Biased";
    break;
  default:
    return str << "Bias(" << int(enval) << ")";
  }
  return str << val;
}
} // namespace L3T
} // namespace Psana
