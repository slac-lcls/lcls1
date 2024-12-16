#ifndef PSDDL_PDS2PSANA_LUSI_DDL_H
#define PSDDL_PDS2PSANA_LUSI_DDL_H 1

// *** Do not edit this file, it is auto-generated ***

#include <vector>
#include <boost/shared_ptr.hpp>
#include "psddl_psana/lusi.ddl.h"
#include "pdsdata/psddl/lusi.ddl.h"
namespace psddl_pds2psana {
namespace Lusi {
Psana::Lusi::DiodeFexConfigV1 pds_to_psana(Pds::Lusi::DiodeFexConfigV1 pds);

Psana::Lusi::DiodeFexConfigV2 pds_to_psana(Pds::Lusi::DiodeFexConfigV2 pds);

Psana::Lusi::DiodeFexV1 pds_to_psana(Pds::Lusi::DiodeFexV1 pds);


class IpmFexConfigV1 : public Psana::Lusi::IpmFexConfigV1 {
public:
  typedef Pds::Lusi::IpmFexConfigV1 XtcType;
  typedef Psana::Lusi::IpmFexConfigV1 PsanaType;
  IpmFexConfigV1(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~IpmFexConfigV1();
  virtual ndarray<const Psana::Lusi::DiodeFexConfigV1, 1> diode() const;
  virtual float xscale() const;
  virtual float yscale() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  ndarray<Psana::Lusi::DiodeFexConfigV1, 1> _diode_ndarray_storage_;
};


class IpmFexConfigV2 : public Psana::Lusi::IpmFexConfigV2 {
public:
  typedef Pds::Lusi::IpmFexConfigV2 XtcType;
  typedef Psana::Lusi::IpmFexConfigV2 PsanaType;
  IpmFexConfigV2(const boost::shared_ptr<const XtcType>& xtcPtr);
  virtual ~IpmFexConfigV2();
  virtual ndarray<const Psana::Lusi::DiodeFexConfigV2, 1> diode() const;
  virtual float xscale() const;
  virtual float yscale() const;
  const XtcType& _xtcObj() const { return *m_xtcObj; }
private:
  boost::shared_ptr<const XtcType> m_xtcObj;
  ndarray<Psana::Lusi::DiodeFexConfigV2, 1> _diode_ndarray_storage_;
};

Psana::Lusi::IpmFexV1 pds_to_psana(Pds::Lusi::IpmFexV1 pds);

Psana::Lusi::PimImageConfigV1 pds_to_psana(Pds::Lusi::PimImageConfigV1 pds);

} // namespace Lusi
} // namespace psddl_pds2psana
#endif // PSDDL_PDS2PSANA_LUSI_DDL_H