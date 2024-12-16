//--------------------------------------------------------------------------
// File and Version Information:
//      $Id$
//
// Description:
//      Hand-written supporting types for DDL-HDF5 mapping.
//
//------------------------------------------------------------------------

//-----------------------
// This Class's Header --
//-----------------------
#include "psddl_hdf2psana/usdusb.h"

//-----------------
// C/C++ Headers --
//-----------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "hdf5pp/CompoundType.h"
#include "hdf5pp/EnumType.h"
#include "hdf5pp/Utils.h"
#include "PSEvt/DataProxy.h"
#include "psddl_hdf2psana/Exceptions.h"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

namespace {

  template <typename T, typename U>
  void ndarray2array(const ndarray<T, 1>& src, U* dst, size_t size) {
    size_t i;
    for (i = 0; i < src.shape()[0]; ++ i) dst[i] = src[i];
    for (; i < size; ++ i) dst[i] = U(0);
  }

}

//              ----------------------------------------
//              -- Public Function Member Definitions --
//              ----------------------------------------

namespace psddl_hdf2psana {
namespace UsdUsb {

// ===============================================================
//      UsbUsd::FexConfigV1 schema version 0
// ===============================================================

ndarray<const int32_t, 1> FexConfigV1_v0::offset() const {
  if (m_ds_offset.empty()) read_ds_offset();
  return m_ds_offset;
}

ndarray<const double, 1> FexConfigV1_v0::scale() const {
  if (m_ds_scale.empty()) read_ds_scale();
  return m_ds_scale;
}

const char* FexConfigV1_v0::name(uint32_t i0) const {
  if (m_ds_name.empty()) read_ds_name();
  return m_ds_name.at(i0).c_str();
}

std::vector<int>  FexConfigV1_v0::name_shape() const {
  if (m_ds_name.empty()) read_ds_name();
  std::vector<int> shape(1);
  shape.at(0) = m_ds_name.size();
  return shape;
}

void FexConfigV1_v0::read_ds_offset() const {
  m_ds_offset = hdf5pp::Utils::readNdarray<int32_t, 1>(m_group, "offset", m_idx);
}

void FexConfigV1_v0::read_ds_scale() const {
  m_ds_scale = hdf5pp::Utils::readNdarray<double, 1>(m_group, "scale", m_idx);
}

void FexConfigV1_v0::read_ds_name() const {
  m_ds_name = hdf5pp::Utils::readListStrings(m_group, "name", m_idx);
}

void make_datasets_FexConfigV1_v0(const Psana::UsdUsb::FexConfigV1& obj, 
      hdf5pp::Group group, const ChunkPolicy& chunkPolicy, int deflate, bool shuffle)
{
  {
    typedef __typeof__(obj.offset()) PsanaArray;
    const PsanaArray& psana_array = obj.offset();
    hdf5pp::Type dstype = hdf5pp::ArrayType::arrayType(hdf5pp::TypeTraits<int32_t>::stored_type(), psana_array.shape()[0]);
    hdf5pp::Utils::createDataset(group, "offset", dstype, chunkPolicy.chunkSize(dstype), chunkPolicy.chunkCacheSize(dstype), deflate, shuffle);    
  }
  {
    typedef __typeof__(obj.scale()) PsanaArray;
    const PsanaArray& psana_array = obj.scale();
    hdf5pp::Type dstype = hdf5pp::ArrayType::arrayType(hdf5pp::TypeTraits<double>::stored_type(), psana_array.shape()[0]);
    hdf5pp::Utils::createDataset(group, "scale", dstype, chunkPolicy.chunkSize(dstype), chunkPolicy.chunkCacheSize(dstype), deflate, shuffle);    
  }
  {
    hsize_t dims[1] = { Psana::UsdUsb::FexConfigV1::NCHANNELS };
    static hdf5pp::Type nameString = hdf5pp::TypeTraitsHelper::string_h5type(Psana::UsdUsb::FexConfigV1::NAME_CHAR_MAX);
    hdf5pp::Type dstype = hdf5pp::ArrayType::arrayType(nameString, 1, dims);
    hdf5pp::Utils::createDataset(group, "name", dstype, chunkPolicy.chunkSize(dstype), chunkPolicy.chunkCacheSize(dstype), deflate, shuffle);    
  }
}

void store_FexConfigV1_v0(const Psana::UsdUsb::FexConfigV1* obj, hdf5pp::Group group, long index, bool append)
{
  std::vector<std::string> channelNames;
  if (obj) {
    for (unsigned ch = 0; ch < Psana::UsdUsb::FexConfigV1::NCHANNELS; ++ch) {
      if (int(ch) < obj->name_shape().at(0)) {
        channelNames.push_back(obj->name(ch));
      } else {
        channelNames.push_back("");
      }
    }
  }
  
  if (append) {
    if (obj) {
      hdf5pp::Utils::storeNDArrayAt(group, "offset", obj->offset(), index);
      hdf5pp::Utils::storeNDArrayAt(group, "scale", obj->scale(), index);
      hdf5pp::Utils::storeListStringsAt(group, "name", 
                                        channelNames, 
                                        long(Psana::UsdUsb::FexConfigV1::NAME_CHAR_MAX),
                                        index);
    } else {
      hdf5pp::Utils::resizeDataset(group, "offset", index < 0 ? index : index + 1);
      hdf5pp::Utils::resizeDataset(group, "scale", index < 0 ? index : index + 1);
      hdf5pp::Utils::resizeDataset(group, "name", index < 0 ? index : index + 1);
    }
  } else {
    hdf5pp::Utils::storeNDArray(group, "offset", obj->offset());
    hdf5pp::Utils::storeNDArray(group, "scale", obj->scale());
    hdf5pp::Utils::storeListStrings(group, "name", 
                                    channelNames,
                                    long(Psana::UsdUsb::FexConfigV1::NAME_CHAR_MAX));
  }  
}


// ===============================================================
//      UsbUsd::DataV1 schema version 0
// ===============================================================

hdf5pp::Type ns_DataV1_v0_dataset_data_stored_type()
{
  typedef ns_DataV1_v0::dataset_data DsType;
  hdf5pp::CompoundType type = hdf5pp::CompoundType::compoundType<DsType>();
  type.insert("encoder_count", offsetof(DsType, e_count), hdf5pp::TypeTraits<uint32_t>::stored_type());
  type.insert("analog_in", offsetof(DsType, analog_in), hdf5pp::TypeTraits<uint16_t>::stored_type());
  type.insert("timestamp", offsetof(DsType, timestamp), hdf5pp::TypeTraits<uint32_t>::stored_type());
  type.insert("digital_in", offsetof(DsType, digital_in), hdf5pp::TypeTraits<uint8_t>::stored_type());
  return type;
}

hdf5pp::Type ns_DataV1_v0::dataset_data::stored_type()
{
  static hdf5pp::Type type = ns_DataV1_v0_dataset_data_stored_type();
  return type;
}

hdf5pp::Type ns_DataV1_v0_dataset_data_native_type()
{
  typedef ns_DataV1_v0::dataset_data DsType;
  hdf5pp::CompoundType type = hdf5pp::CompoundType::compoundType<DsType>();
  type.insert("encoder_count", offsetof(DsType, e_count), hdf5pp::TypeTraits<uint32_t>::native_type(), 4);
  type.insert("analog_in", offsetof(DsType, analog_in), hdf5pp::TypeTraits<uint16_t>::native_type(), 4);
  type.insert("timestamp", offsetof(DsType, timestamp), hdf5pp::TypeTraits<uint32_t>::native_type());
  type.insert("status", offsetof(DsType, status), hdf5pp::TypeTraits<uint8_t>::native_type(), 4) ;
  type.insert("digital_in", offsetof(DsType, digital_in), hdf5pp::TypeTraits<uint8_t>::native_type());
  return type;
}

hdf5pp::Type
ns_DataV1_v0::dataset_data::native_type()
{
  static hdf5pp::Type type = ns_DataV1_v0_dataset_data_native_type();
  return type;
}

ns_DataV1_v0::dataset_data::dataset_data()
{
}

ns_DataV1_v0::dataset_data::dataset_data(const Psana::UsdUsb::DataV1& psanaobj)
  : timestamp(psanaobj.timestamp())
  , digital_in(psanaobj.digital_in())
{
  ::ndarray2array(psanaobj.encoder_count(), e_count, 4);
  ::ndarray2array(psanaobj.analog_in(), analog_in, 4);
  ::ndarray2array(psanaobj.status(), status, 4);
}

ns_DataV1_v0::dataset_data::~dataset_data()
{
}

uint8_t
DataV1_v0::digital_in() const
{
  if (not m_ds_data.get()) read_ds_data();
  return uint8_t(m_ds_data->digital_in);
}

uint32_t
DataV1_v0::timestamp() const
{
  if (not m_ds_data.get()) read_ds_data();
  return uint32_t(m_ds_data->timestamp);
}

ndarray<const uint8_t, 1>
DataV1_v0::status() const
{
  ndarray<uint8_t, 1> arr = make_ndarray<uint8_t>(4);
  std::fill_n(arr.begin(), 4, uint8_t(0));
  return arr;
}

ndarray<const uint16_t, 1>
DataV1_v0::analog_in() const
{
  if (not m_ds_data.get()) read_ds_data();
  boost::shared_ptr<uint16_t> ptr(m_ds_data, m_ds_data->analog_in);
  return make_ndarray(ptr, Analog_Inputs);
}

ndarray<const int32_t, 1>
DataV1_v0::encoder_count() const
{
  if (not m_ds_data.get()) read_ds_data();
  boost::shared_ptr<int32_t> ptr(m_ds_data, m_ds_data->e_count);
  return make_ndarray(ptr, Encoder_Inputs);
}

void
DataV1_v0::read_ds_data() const
{
  m_ds_data = hdf5pp::Utils::readGroup<UsdUsb::ns_DataV1_v0::dataset_data>(m_group, "data", m_idx);
}

void make_datasets_DataV1_v0(const Psana::UsdUsb::DataV1& obj,
      hdf5pp::Group group, const ChunkPolicy& chunkPolicy, int deflate, bool shuffle)
{
  {
    hdf5pp::Type dstype = ns_DataV1_v0::dataset_data::stored_type();
    hdf5pp::Utils::createDataset(group, "data", dstype, chunkPolicy.chunkSize(dstype), chunkPolicy.chunkCacheSize(dstype), deflate, shuffle);
  }
}

void store_DataV1_v0(const Psana::UsdUsb::DataV1* obj, hdf5pp::Group group, long index, bool append)
{
  if (append) {
    if (obj) {
      hdf5pp::Utils::storeAt(group, "data", ns_DataV1_v0::dataset_data(*obj), index);
    } else {
      hdf5pp::Utils::resizeDataset(group, "data", index < 0 ? index : index + 1);
    }
  } else {
    hdf5pp::Utils::storeScalar(group, "data", ns_DataV1_v0::dataset_data(*obj));
  }
}

} // namespace UsdUsb
} // namespace psddl_hdf2psana
