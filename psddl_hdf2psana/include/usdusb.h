#ifndef PSDDL_HDF2PSANA_USDUSB_H
#define PSDDL_HDF2PSANA_USDUSB_H 1

//--------------------------------------------------------------------------
// File and Version Information:
//      $Id$
//
// Description:
//      Hand-written supporting types for DDL-HDF5 mapping.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------

//----------------------
// Base Class Headers --
//----------------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "hdf5pp/Group.h"
#include "hdf5pp/Type.h"
#include "psddl_hdf2psana/ChunkPolicy.h"
#include "psddl_psana/usdusb.ddl.h"
#include "PSEvt/Proxy.h"

namespace psddl_hdf2psana {
namespace UsdUsb {

// ===============================================================
//      UsbUsd::FexConfigV1 schema version 0
// ===============================================================
class FexConfigV1_v0 : public Psana::UsdUsb::FexConfigV1 {
public:
  typedef Psana::UsdUsb::FexConfigV1 PsanaType;
  FexConfigV1_v0() {}
  FexConfigV1_v0(hdf5pp::Group group, hsize_t idx)
    : m_group(group), m_idx(idx) {}
  virtual ~FexConfigV1_v0() {}
  virtual ndarray<const int32_t, 1> offset() const;
  virtual ndarray<const double, 1> scale() const;
  virtual const char* name(uint32_t i0) const;
  virtual std::vector<int> name_shape() const;

private:
  mutable hdf5pp::Group m_group;
  hsize_t m_idx;
  mutable ndarray<const int32_t, 1> m_ds_offset;
  void read_ds_offset() const;
  mutable ndarray<const double, 1> m_ds_scale;
  void read_ds_scale() const;
  mutable std::vector<std::string> m_ds_name;
  void read_ds_name() const;
};

void make_datasets_FexConfigV1_v0(const Psana::UsdUsb::FexConfigV1& obj, 
                                  hdf5pp::Group group, const ChunkPolicy& chunkPolicy, int deflate, bool shuffle);

void store_FexConfigV1_v0(const Psana::UsdUsb::FexConfigV1* obj, hdf5pp::Group group, long index, bool append);

//boost::shared_ptr<PSEvt::Proxy<Psana::UsdUsb::FexConfigV1> > make_FexConfigV1(int version, hdf5pp::Group group, hsize_t idx);

/// Store object as a single instance (scalar dataset) inside specified group.
//void store(const Psana::UsdUsb::FexConfigV1& obj, hdf5pp::Group group, int version = -1);

/// Create container (rank=1) datasets for storing objects of specified type.
//void make_datasets(const Psana::UsdUsb::FexConfigV1& obj, hdf5pp::Group group, const ChunkPolicy& chunkPolicy,
//                   int deflate, bool shuffle, int version = -1);

/// Add one more object to the containers created by previous method at the specified index,
/// negative index means append to the end of dataset. If pointer to object is zero then
/// datsets are extended with zero-filled of default-initialized data.
//void store_at(const Psana::UsdUsb::FexConfigV1* obj, hdf5pp::Group group, long index = -1, int version = -1);

// ===============================================================
//      UsbUsd::DataV1 schema version 0
// ===============================================================
namespace ns_DataV1_v0 {
struct dataset_data {
  static hdf5pp::Type native_type();
  static hdf5pp::Type stored_type();

  dataset_data();
  dataset_data(const Psana::UsdUsb::DataV1& psanaobj);
  ~dataset_data();

  int32_t e_count[4];    // data in v0 are stored as uint32_t but interface requires int32_t
  uint16_t analog_in[4];
  uint32_t timestamp;
  uint8_t status[4];
  uint8_t digital_in;

};
}


class DataV1_v0 : public Psana::UsdUsb::DataV1 {
public:
  typedef Psana::UsdUsb::DataV1 PsanaType;
  DataV1_v0() {}
  DataV1_v0(hdf5pp::Group group, hsize_t idx)
    : m_group(group), m_idx(idx) {}
  DataV1_v0(const boost::shared_ptr<UsdUsb::ns_DataV1_v0::dataset_data>& ds) : m_ds_data(ds) {}
  virtual ~DataV1_v0() {}
  virtual uint8_t digital_in() const;
  virtual uint32_t timestamp() const;
  virtual ndarray<const uint8_t, 1> status() const;

  virtual ndarray<const uint16_t, 1> analog_in() const;
  /** Return lower 24 bits of _count array as signed integer values. */
  ndarray<const int32_t, 1> encoder_count() const;

private:
  mutable hdf5pp::Group m_group;
  hsize_t m_idx;
  mutable boost::shared_ptr<UsdUsb::ns_DataV1_v0::dataset_data> m_ds_data;
  void read_ds_data() const;
};

void make_datasets_DataV1_v0(const Psana::UsdUsb::DataV1& obj,
      hdf5pp::Group group, const ChunkPolicy& chunkPolicy, int deflate, bool shuffle);
void store_DataV1_v0(const Psana::UsdUsb::DataV1* obj, hdf5pp::Group group, long index, bool append);

} // namespace UsdUsb
} // namespace psddl_hdf2psana

#endif // PSDDL_HDF2PSANA_USDUSB_H
