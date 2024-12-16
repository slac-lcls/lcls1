#ifndef PSDDL_HDF2PSANA_GENERIC1D_H
#define PSDDL_HDF2PSANA_GENERIC1D_H 1

#include <map>

#include "psddl_psana/generic1d.ddl.h"
#include "hdf5pp/Group.h"
#include "hdf5pp/Type.h"
#include "PSEvt/Proxy.h"
#include "psddl_hdf2psana/ChunkPolicy.h"
#include "psddl_hdf2psana/generic1d.ddl.h"


namespace psddl_hdf2psana {
namespace Generic1D {

namespace ns_DataV0_v0 {
}

/*
 * The generic1D data 
 */
template <typename Config>
class DataV0_v0 : public Psana::Generic1D::DataV0 {
public:
  typedef Psana::Generic1D::DataV0 PsanaType;
  DataV0_v0() {}
  DataV0_v0(hdf5pp::Group group, hsize_t idx, const boost::shared_ptr<Config>& cfg)
    : m_group(group), m_idx(idx), m_cfg(cfg) {}
  virtual ~DataV0_v0() {}

  // we don't implement data_size and _int_data on the Hdf5 side, just return 0/None:
  virtual uint32_t data_size() const { return 0; }
  virtual ndarray<const uint8_t, 1> _int_data() const { return ndarray<const uint8_t, 1>(); }

  virtual ndarray<const uint8_t, 1> data_u8(uint32_t channel) const;
  virtual ndarray<const uint16_t, 1> data_u16(uint32_t channel) const;
  virtual ndarray<const uint32_t, 1> data_u32(uint32_t channel) const;
  virtual ndarray<const float, 1> data_f32(uint32_t channel) const;
  virtual ndarray<const double, 1> data_f64(uint32_t channel) const;

private:
  mutable hdf5pp::Group m_group;
  hsize_t m_idx;
  boost::shared_ptr<Config> m_cfg;
  
  bool doesnt_store_type(uint32_t channel, enum Config::Sample_Type sample_type) const;

  mutable std::map<uint32_t, ndarray<const uint8_t, 1> > m_data_u8;
  mutable std::map<uint32_t, ndarray<const uint16_t, 1> > m_data_u16;
  mutable std::map<uint32_t, ndarray<const uint32_t, 1> > m_data_u32;
  mutable std::map<uint32_t, ndarray<const float, 1> > m_data_f32;
  mutable std::map<uint32_t, ndarray<const double, 1> > m_data_f64;

  void read_data_u8(uint32_t channel) const;
  void read_data_u16(uint32_t channel) const;
  void read_data_u32(uint32_t channel) const;
  void read_data_f32(uint32_t channel) const;
  void read_data_f64(uint32_t channel) const;

};

void make_datasets_DataV0_v0(const Psana::Generic1D::DataV0& obj,
                             hdf5pp::Group group, 
                             const ChunkPolicy& chunkPolicy, int deflate, bool shuffle);
 
void store_DataV0_v0(const Psana::Generic1D::DataV0* obj, hdf5pp::Group group, long index, bool append);



} // namespace Generic1D
} // namespace psddl_hdf2psana
#endif // PSDDL_HDF2PSANA_GENERIC1D_DDL_H
