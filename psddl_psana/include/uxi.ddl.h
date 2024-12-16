#ifndef PSANA_UXI_DDL_H
#define PSANA_UXI_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <iosfwd>
#include <cstring>
#include "ndarray/ndarray.h"
#include "pdsdata/xtc/TypeId.hh"
namespace Psana {
namespace Uxi {

/** @class ConfigV1

  
*/


class ConfigV1 {
public:
  enum { TypeId = Pds::TypeId::Id_UxiConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  enum { NumberOfPots = 13 /**< Defines the number of potentiometers in the Icarus detector. */ };
  enum { NumberOfSides = 2 };
  virtual ~ConfigV1();
  /** The width in pixels of each frame of the detector. */
  virtual uint32_t width() const = 0;
  /** The height in pixels of each frame of the detector. */
  virtual uint32_t height() const = 0;
  /** The number of frames produced by the detector. */
  virtual uint32_t numberOfFrames() const = 0;
  /** The number of bytes for each pixel. */
  virtual uint32_t numberOFBytesPerPixel() const = 0;
  /** The sensor type ID. */
  virtual uint32_t sensorType() const = 0;
  /** High speed timing on parameter in ns for each side. */
  virtual ndarray<const uint32_t, 1> timeOn() const = 0;
  /** High speed timing off parameter in ns for each side. */
  virtual ndarray<const uint32_t, 1> timeOff() const = 0;
  /** High speed timing initial delay in ns for each side. */
  virtual ndarray<const uint32_t, 1> delay() const = 0;
  /** Bitmask to designate which pots should only be read and not written. */
  virtual uint32_t readOnlyPots() const = 0;
  /** The values of the each of the pots in volts. */
  virtual ndarray<const double, 1> pots() const = 0;
  /** Check if a pot is readonly. */
  virtual uint8_t potIsReadOnly(uint8_t i) const = 0;
  /** Check if a pot was tuned. */
  virtual uint8_t potIsTuned(uint8_t i) const = 0;
  /** calculate total number of pixels per frame. */
  virtual uint32_t numPixelsPerFrame() const = 0;
  /** calculate total number of pixels across all frames. */
  virtual uint32_t numPixels() const = 0;
  /** Total size in bytes of the frame */
  virtual uint32_t frameSize() const = 0;
};

/** @class RoiCoord

  
*/


class RoiCoord {
public:
  RoiCoord(uint16_t arg__first, uint16_t arg__last)
    : _first(arg__first), _last(arg__last)
  {
  }
  RoiCoord() {}
  /** The first row/frame of ROI. */
  uint16_t first() const { return _first; }
  /** The last row/frame of ROI. */
  uint16_t last() const { return _last; }
  static uint32_t _sizeof() { return 4; }
private:
  uint16_t	_first;	/**< The first row/frame of ROI. */
  uint16_t	_last;	/**< The last row/frame of ROI. */
};

/** @class ConfigV2

  
*/


class ConfigV2 {
public:
  enum { TypeId = Pds::TypeId::Id_UxiConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 2 /**< XTC type version number */ };
  enum { NumberOfPots = 13 /**< Defines the number of potentiometers in the Icarus detector. */ };
  enum { NumberOfSides = 2 };
  enum RoiMode {
    Off = 0,
    On = 1,
  };
  virtual ~ConfigV2();
  /** Enable frame/row roi. */
  virtual Uxi::ConfigV2::RoiMode roiEnable() const = 0;
  /** The first/last rows of the roi. */
  virtual const Uxi::RoiCoord& roiRows() const = 0;
  /** The first/last frames of the roi. */
  virtual const Uxi::RoiCoord& roiFrames() const = 0;
  /** The width in pixels of each frame of the detector. */
  virtual uint32_t width() const = 0;
  /** The height in pixels of each frame of the detector. */
  virtual uint32_t height() const = 0;
  /** The number of frames produced by the detector. */
  virtual uint32_t numberOfFrames() const = 0;
  /** The number of bytes for each pixel. */
  virtual uint32_t numberOFBytesPerPixel() const = 0;
  /** The sensor type ID. */
  virtual uint32_t sensorType() const = 0;
  /** High speed timing on parameter in ns for each side. */
  virtual ndarray<const uint32_t, 1> timeOn() const = 0;
  /** High speed timing off parameter in ns for each side. */
  virtual ndarray<const uint32_t, 1> timeOff() const = 0;
  /** High speed timing initial delay in ns for each side. */
  virtual ndarray<const uint32_t, 1> delay() const = 0;
  /** Bitmask to designate which pots should only be read and not written. */
  virtual uint32_t readOnlyPots() const = 0;
  /** The values of the each of the pots in volts. */
  virtual ndarray<const double, 1> pots() const = 0;
  /** Check if a pot is readonly. */
  virtual uint8_t potIsReadOnly(uint8_t i) const = 0;
  /** Check if a pot was tuned. */
  virtual uint8_t potIsTuned(uint8_t i) const = 0;
  /** calculate total number of pixels per frame. */
  virtual uint32_t numPixelsPerFrame() const = 0;
  /** calculate total number of pixels across all frames. */
  virtual uint32_t numPixels() const = 0;
  /** Total size in bytes of the frame */
  virtual uint32_t frameSize() const = 0;
};
std::ostream& operator<<(std::ostream& str, Uxi::ConfigV2::RoiMode enval);

/** @class ConfigV3

  
*/


class ConfigV3 {
public:
  enum { TypeId = Pds::TypeId::Id_UxiConfig /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 3 /**< XTC type version number */ };
  enum { NumberOfPots = 13 /**< Defines the number of potentiometers in the Icarus detector. */ };
  enum { NumberOfSides = 2 };
  enum RoiMode {
    Off = 0,
    On = 1,
  };
  enum OscMode {
    RelaxationOsc = 0,
    RingOscWithCaps = 1,
    RingOscNoCaps = 2,
    ExternalClock = 3,
  };
  virtual ~ConfigV3();
  /** Enable frame/row roi. */
  virtual Uxi::ConfigV3::RoiMode roiEnable() const = 0;
  /** The first/last rows of the roi. */
  virtual const Uxi::RoiCoord& roiRows() const = 0;
  /** The first/last frames of the roi. */
  virtual const Uxi::RoiCoord& roiFrames() const = 0;
  /** The oscillator to that the detector should use. */
  virtual Uxi::ConfigV3::OscMode oscillator() const = 0;
  /** The width in pixels of each frame of the detector. */
  virtual uint32_t width() const = 0;
  /** The height in pixels of each frame of the detector. */
  virtual uint32_t height() const = 0;
  /** The number of frames produced by the detector. */
  virtual uint32_t numberOfFrames() const = 0;
  /** The number of bytes for each pixel. */
  virtual uint32_t numberOFBytesPerPixel() const = 0;
  /** The sensor type ID. */
  virtual uint32_t sensorType() const = 0;
  /** High speed timing on parameter in ns for each side. */
  virtual ndarray<const uint32_t, 1> timeOn() const = 0;
  /** High speed timing off parameter in ns for each side. */
  virtual ndarray<const uint32_t, 1> timeOff() const = 0;
  /** High speed timing initial delay in ns for each side. */
  virtual ndarray<const uint32_t, 1> delay() const = 0;
  /** Bitmask to designate which pots should only be read and not written. */
  virtual uint32_t readOnlyPots() const = 0;
  /** The values of the each of the pots in volts. */
  virtual ndarray<const double, 1> pots() const = 0;
  /** Check if a pot is readonly. */
  virtual uint8_t potIsReadOnly(uint8_t i) const = 0;
  /** Check if a pot was tuned. */
  virtual uint8_t potIsTuned(uint8_t i) const = 0;
  /** calculate total number of pixels per frame. */
  virtual uint32_t numPixelsPerFrame() const = 0;
  /** calculate total number of pixels across all frames. */
  virtual uint32_t numPixels() const = 0;
  /** Total size in bytes of the frame */
  virtual uint32_t frameSize() const = 0;
};
std::ostream& operator<<(std::ostream& str, Uxi::ConfigV3::RoiMode enval);
std::ostream& operator<<(std::ostream& str, Uxi::ConfigV3::OscMode enval);

/** @class FrameV1

  
*/

class ConfigV1;
class ConfigV2;
class ConfigV3;

class FrameV1 {
public:
  enum { TypeId = Pds::TypeId::Id_UxiFrame /**< XTC type ID value (from Pds::TypeId class) */ };
  enum { Version = 1 /**< XTC type version number */ };
  virtual ~FrameV1();
  /** The internal acquisition counter number of the detector. */
  virtual uint32_t acquisitionCount() const = 0;
  /** The internal detector timestamp associated with the frames. */
  virtual uint32_t timestamp() const = 0;
  /** The temperature of the detector associated with the frames. */
  virtual double temperature() const = 0;
  virtual ndarray<const uint16_t, 3> frames() const = 0;
};
} // namespace Uxi
} // namespace Psana
#endif // PSANA_UXI_DDL_H