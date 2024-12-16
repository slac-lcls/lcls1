
// *** Do not edit this file, it is auto-generated ***

#include <cstddef>
#include "psddl_psana/camera.ddl.h"
#include <iostream>
namespace Psana {
namespace Camera {

FrameFccdConfigV1::~FrameFccdConfigV1() {}


FrameFexConfigV1::~FrameFexConfigV1() {}

std::ostream& operator<<(std::ostream& str, Camera::FrameFexConfigV1::Forwarding enval) {
  const char* val;
  switch (enval) {
  case Camera::FrameFexConfigV1::NoFrame:
    val = "NoFrame";
    break;
  case Camera::FrameFexConfigV1::FullFrame:
    val = "FullFrame";
    break;
  case Camera::FrameFexConfigV1::RegionOfInterest:
    val = "RegionOfInterest";
    break;
  default:
    return str << "Forwarding(" << int(enval) << ")";
  }
  return str << val;
}
std::ostream& operator<<(std::ostream& str, Camera::FrameFexConfigV1::Processing enval) {
  const char* val;
  switch (enval) {
  case Camera::FrameFexConfigV1::NoProcessing:
    val = "NoProcessing";
    break;
  case Camera::FrameFexConfigV1::GssFullFrame:
    val = "GssFullFrame";
    break;
  case Camera::FrameFexConfigV1::GssRegionOfInterest:
    val = "GssRegionOfInterest";
    break;
  case Camera::FrameFexConfigV1::GssThreshold:
    val = "GssThreshold";
    break;
  default:
    return str << "Processing(" << int(enval) << ")";
  }
  return str << val;
}

FrameV1::~FrameV1() {}


TwoDGaussianV1::~TwoDGaussianV1() {}


ControlsCameraConfigV1::~ControlsCameraConfigV1() {}

std::ostream& operator<<(std::ostream& str, Camera::ControlsCameraConfigV1::ColorMode enval) {
  const char* val;
  switch (enval) {
  case Camera::ControlsCameraConfigV1::Mono:
    val = "Mono";
    break;
  case Camera::ControlsCameraConfigV1::Bayer:
    val = "Bayer";
    break;
  case Camera::ControlsCameraConfigV1::RGB1:
    val = "RGB1";
    break;
  default:
    return str << "ColorMode(" << int(enval) << ")";
  }
  return str << val;
}
} // namespace Camera
} // namespace Psana
