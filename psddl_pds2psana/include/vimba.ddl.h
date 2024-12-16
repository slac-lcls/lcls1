#ifndef PSDDL_PDS2PSANA_VIMBA_DDL_H
#define PSDDL_PDS2PSANA_VIMBA_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <boost/shared_ptr.hpp>
#include "psddl_psana/vimba.ddl.h"
#include "pdsdata/psddl/vimba.ddl.h"
namespace psddl_pds2psana {
namespace Vimba {

class AlviumConfigV1 : public Psana::Vimba::AlviumConfigV1 {
public:
  typedef Pds::Vimba::AlviumConfigV1 XtcType;
  typedef Psana::Vimba::AlviumConfigV1 PsanaType;
  AlviumConfigV1(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~AlviumConfigV1();
  virtual Psana::Vimba::AlviumConfigV1::VmbBool reverseX() const;
  virtual Psana::Vimba::AlviumConfigV1::VmbBool reverseY() const;
  virtual Psana::Vimba::AlviumConfigV1::VmbBool contrastEnable() const;
  virtual Psana::Vimba::AlviumConfigV1::VmbBool correctionEnable() const;
  virtual Psana::Vimba::AlviumConfigV1::RoiMode roiEnable() const;
  virtual Psana::Vimba::AlviumConfigV1::ImgCorrectionType correctionType() const;
  virtual Psana::Vimba::AlviumConfigV1::ImgCorrectionSet correctionSet() const;
  virtual Psana::Vimba::AlviumConfigV1::PixelMode pixelMode() const;
  virtual Psana::Vimba::AlviumConfigV1::TriggerMode triggerMode() const;
  virtual uint32_t width() const;
  virtual uint32_t height() const;
  virtual uint32_t offsetX() const;
  virtual uint32_t offsetY() const;
  virtual uint32_t sensorWidth() const;
  virtual uint32_t sensorHeight() const;
  virtual uint32_t contrastDarkLimit() const;
  virtual uint32_t contrastBrightLimit() const;
  virtual uint32_t contrastShape() const;
  virtual double exposureTime() const;
  virtual double blackLevel() const;
  virtual double gain() const;
  virtual double gamma() const;
  virtual const char* manufacturer() const;
  virtual const char* family() const;
  virtual const char* model() const;
  virtual const char* manufacturerId() const;
  virtual const char* version() const;
  virtual const char* serialNumber() const;
  virtual const char* firmwareId() const;
  virtual const char* firmwareVersion() const;
  virtual uint32_t depth() const;
  virtual uint32_t frameSize() const;
  virtual uint32_t numPixelsX() const;
  virtual uint32_t numPixelsY() const;
  virtual uint32_t numPixels() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
};


template <typename Config>
class FrameV1 : public Psana::Vimba::FrameV1 {
public:
  typedef Pds::Vimba::FrameV1 XtcType;
  typedef Psana::Vimba::FrameV1 PsanaType;
  FrameV1(const boost::shared_ptr<const XtcType>& xtcPtr, const boost::shared_ptr<const Config>& cfgPtr);
  virtual ~FrameV1();
  virtual uint64_t frameid() const;
  virtual uint64_t timestamp() const;
  virtual ndarray<const uint16_t, 2> data() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  boost::shared_ptr<const Config> m_cfgPtr;
};

} // namespace Vimba
} // namespace psddl_pds2psana
#endif // PSDDL_PDS2PSANA_VIMBA_DDL_H
