#ifndef PSDDL_PDS2PSANA_QUADADC_DDL_H
#define PSDDL_PDS2PSANA_QUADADC_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <boost/shared_ptr.hpp>
#include "psddl_psana/quadadc.ddl.h"
#include "pdsdata/psddl/quadadc.ddl.h"
namespace psddl_pds2psana {
namespace QuadAdc {

class ConfigV1 : public Psana::QuadAdc::ConfigV1 {
public:
  typedef Pds::QuadAdc::ConfigV1 XtcType;
  typedef Psana::QuadAdc::ConfigV1 PsanaType;
  ConfigV1(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~ConfigV1();
  virtual uint32_t chanMask() const;
  virtual double delayTime() const;
  virtual uint32_t interleaveMode() const;
  virtual uint32_t nbrSamples() const;
  virtual uint32_t evtCode() const;
  virtual double sampleRate() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
};

} // namespace QuadAdc
} // namespace psddl_pds2psana
#endif // PSDDL_PDS2PSANA_QUADADC_DDL_H
