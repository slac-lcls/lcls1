
// *** Do not edit this file, it is auto-generated ***

#include <cstddef>
#include "psddl_psana/orca.ddl.h"
#include <iostream>
namespace Psana {
namespace Orca {

ConfigV1::~ConfigV1() {}

std::ostream& operator<<(std::ostream& str, Orca::ConfigV1::ReadoutMode enval) {
  const char* val;
  switch (enval) {
  case Orca::ConfigV1::x1:
    val = "x1";
    break;
  case Orca::ConfigV1::x2:
    val = "x2";
    break;
  case Orca::ConfigV1::x4:
    val = "x4";
    break;
  case Orca::ConfigV1::Subarray:
    val = "Subarray";
    break;
  default:
    return str << "ReadoutMode(" << int(enval) << ")";
  }
  return str << val;
}
std::ostream& operator<<(std::ostream& str, Orca::ConfigV1::Cooling enval) {
  const char* val;
  switch (enval) {
  case Orca::ConfigV1::Off:
    val = "Off";
    break;
  case Orca::ConfigV1::On:
    val = "On";
    break;
  case Orca::ConfigV1::Max:
    val = "Max";
    break;
  default:
    return str << "Cooling(" << int(enval) << ")";
  }
  return str << val;
}
} // namespace Orca
} // namespace Psana
