#include <cstdio>
#include "psddl_hdf2psana/generic1d.h"
#include "hdf5pp/ArrayType.h"
#include "hdf5pp/CompoundType.h"
#include "hdf5pp/Utils.h"
#include "psddl_hdf2psana/Exceptions.h"

namespace {
  using namespace psddl_hdf2psana;
// local namespace for helper functions to make and store datasets
  
typedef enum Psana::Generic1D::ConfigV0::Sample_Type Sample_Type;

std::vector<Sample_Type> getChannelTypeList(const Psana::Generic1D::DataV0 & obj) {

  std::vector<Sample_Type> channelTypeList;

  int32_t channel = -1;
  while (true)  {
    channel += 1;

    ndarray<const uint8_t, 1> arr_u8 = obj.data_u8((uint32_t)channel);
    if (not arr_u8.empty()) {
      channelTypeList.push_back(Psana::Generic1D::ConfigV0::UINT8);
      continue;
    } 
    ndarray<const uint16_t, 1> arr_u16 = obj.data_u16((uint32_t)channel);
    if (not arr_u16.empty()) {
      channelTypeList.push_back(Psana::Generic1D::ConfigV0::UINT16);
      continue;
    } 
    ndarray<const uint32_t, 1> arr_u32 = obj.data_u32((uint32_t)channel);
    if (not arr_u32.empty()) {
      channelTypeList.push_back(Psana::Generic1D::ConfigV0::UINT32);
      continue;
    } 
    ndarray<const float, 1> arr_float = obj.data_f32((uint32_t)channel);
    if (not arr_float.empty()) {
      channelTypeList.push_back(Psana::Generic1D::ConfigV0::FLOAT32);
      continue;
    } 
    ndarray<const double, 1> arr_double = obj.data_f64((uint32_t)channel);
    if (not arr_double.empty()) {
      channelTypeList.push_back(Psana::Generic1D::ConfigV0::FLOAT64);
      continue;
    } 
    break;
  };
  return channelTypeList;
}

std::string channelDatasetName(uint32_t channel) {
  static char datasetName[128];
  sprintf(datasetName, "channel:%2.2u", channel);
  return std::string(datasetName);
}

template<class T>
void createChannelDataset(ndarray<const T, 1> arr, uint32_t channel, 
                          hdf5pp::Group group, const ChunkPolicy &chunkPolicy, 
                          int deflate, bool shuffle) 
{  
  hdf5pp::Type dstype = hdf5pp::ArrayType::arrayType(hdf5pp::TypeTraits<T>::stored_type(), arr.shape()[0]);
  hdf5pp::Utils::createDataset(group, channelDatasetName(channel), dstype, chunkPolicy.chunkSize(dstype), chunkPolicy.chunkCacheSize(dstype), deflate, shuffle);
}

void storeChannelsDatasetsAt(hdf5pp::Group group, 
                             const Psana::Generic1D::DataV0 & obj, 
                             long index) {
  std::vector<Sample_Type> channelTypeList = getChannelTypeList(obj);
  for (uint32_t channel = 0; channel < channelTypeList.size(); ++channel) {
    switch (channelTypeList[channel]) {
    case Psana::Generic1D::ConfigV0::UINT8:
      hdf5pp::Utils::storeNDArrayAt(group, channelDatasetName(channel), obj.data_u8(channel), index);
      break;
    case Psana::Generic1D::ConfigV0::UINT16:
      hdf5pp::Utils::storeNDArrayAt(group, channelDatasetName(channel), obj.data_u16(channel), index);
      break;
    case Psana::Generic1D::ConfigV0::UINT32:
      hdf5pp::Utils::storeNDArrayAt(group, channelDatasetName(channel), obj.data_u32(channel), index);
      break;
    case Psana::Generic1D::ConfigV0::FLOAT32:
      hdf5pp::Utils::storeNDArrayAt(group, channelDatasetName(channel), obj.data_f32(channel), index);
      break;
    case Psana::Generic1D::ConfigV0::FLOAT64:
      hdf5pp::Utils::storeNDArrayAt(group, channelDatasetName(channel), obj.data_f64(channel), index);
      break;
    }
  }
}

void resizeChannelsDatasets(hdf5pp::Group group, 
                             long index) {
  uint32_t channel = 0;
  while (group.hasChild(channelDatasetName(channel))) {
    hdf5pp::Utils::resizeDataset(group, channelDatasetName(channel), index < 0 ? index : index + 1);
  }
}

void storeChannelsDatasets(hdf5pp::Group group, 
                           const Psana::Generic1D::DataV0 & obj) {
  std::vector<Sample_Type> channelTypeList = getChannelTypeList(obj);
  for (uint32_t channel = 0; channel < channelTypeList.size(); ++channel) {
    switch (channelTypeList[channel]) {
    case Psana::Generic1D::ConfigV0::UINT8:
      hdf5pp::Utils::storeNDArray(group, channelDatasetName(channel), obj.data_u8(channel));
      break;
    case Psana::Generic1D::ConfigV0::UINT16:
      hdf5pp::Utils::storeNDArray(group, channelDatasetName(channel), obj.data_u16(channel));
      break;
    case Psana::Generic1D::ConfigV0::UINT32:
      hdf5pp::Utils::storeNDArray(group, channelDatasetName(channel), obj.data_u32(channel));
      break;
    case Psana::Generic1D::ConfigV0::FLOAT32:
      hdf5pp::Utils::storeNDArray(group, channelDatasetName(channel), obj.data_f32(channel));
      break;
    case Psana::Generic1D::ConfigV0::FLOAT64:
      hdf5pp::Utils::storeNDArray(group, channelDatasetName(channel), obj.data_f64(channel));
      break;
    }
  }
}

} // local namespace


namespace psddl_hdf2psana {
namespace Generic1D {

template <typename Config>
bool DataV0_v0<Config>::doesnt_store_type(uint32_t channel, enum Config::Sample_Type sample_type) const {
  if (channel > m_cfg->NChannels()) return true;
  if (m_cfg->SampleType()[channel] != sample_type) return true;
  return false;
}

template <typename Config>
ndarray<const uint8_t, 1> DataV0_v0<Config>::data_u8(uint32_t channel) const {
  if (doesnt_store_type(channel, Config::UINT8)) return ndarray<const uint8_t, 1>();
  if (m_data_u8.find(channel) == m_data_u8.end()) read_data_u8(channel);
  return m_data_u8[channel];
}

template <typename Config>
ndarray<const uint16_t, 1> DataV0_v0<Config>::data_u16(uint32_t channel) const {
  if (doesnt_store_type(channel, Config::UINT16)) return ndarray<const uint16_t, 1>();
  if (m_data_u16.find(channel) == m_data_u16.end()) read_data_u16(channel);
  return m_data_u16[channel];
}

template <typename Config>
ndarray<const uint32_t, 1> DataV0_v0<Config>::data_u32(uint32_t channel) const {
  if (doesnt_store_type(channel, Config::UINT32)) return ndarray<const uint32_t, 1>();
  if (m_data_u32.find(channel) == m_data_u32.end()) read_data_u32(channel);
  return m_data_u32[channel];
}

template <typename Config>
ndarray<const float, 1> DataV0_v0<Config>::data_f32(uint32_t channel) const {
  if (doesnt_store_type(channel, Config::FLOAT32)) return ndarray<const float, 1>();
  if (m_data_f32.find(channel) == m_data_f32.end()) read_data_f32(channel);
  return m_data_f32[channel];
}

template <typename Config>
ndarray<const double, 1> DataV0_v0<Config>::data_f64(uint32_t channel) const {
  if (doesnt_store_type(channel, Config::FLOAT64)) return ndarray<const double, 1>();
  if (m_data_f64.find(channel) == m_data_f64.end()) read_data_f64(channel);
  return m_data_f64[channel];
}

template <typename Config>
void DataV0_v0<Config>::read_data_u8(uint32_t channel) const {
  m_data_u8[channel] = hdf5pp::Utils::readNdarray<uint8_t, 1>(m_group, channelDatasetName(channel), m_idx);
}

template <typename Config>
void DataV0_v0<Config>::read_data_u16(uint32_t channel) const {
  m_data_u16[channel] = hdf5pp::Utils::readNdarray<uint16_t, 1>(m_group, channelDatasetName(channel), m_idx);
}

template <typename Config>
void DataV0_v0<Config>::read_data_u32(uint32_t channel) const {
  m_data_u32[channel] = hdf5pp::Utils::readNdarray<uint32_t, 1>(m_group, channelDatasetName(channel), m_idx);
}

template <typename Config>
void DataV0_v0<Config>::read_data_f32(uint32_t channel) const {
  m_data_f32[channel] = hdf5pp::Utils::readNdarray<float, 1>(m_group, channelDatasetName(channel), m_idx);
}

template <typename Config>
void DataV0_v0<Config>::read_data_f64(uint32_t channel) const {
  m_data_f64[channel] = hdf5pp::Utils::readNdarray<double, 1>(m_group, channelDatasetName(channel), m_idx);
}


// instantiate
template class DataV0_v0<Psana::Generic1D::ConfigV0>;


void make_datasets_DataV0_v0(const Psana::Generic1D::DataV0& obj,
                             hdf5pp::Group group, 
                             const ChunkPolicy& chunkPolicy, int deflate, bool shuffle) 
{
  std::vector<Sample_Type> channelTypeList = getChannelTypeList(obj);
  for (uint32_t channel = 0; channel < channelTypeList.size(); ++channel) {
    switch (channelTypeList[channel]) {
    case Psana::Generic1D::ConfigV0::UINT8:
      createChannelDataset<uint8_t>(obj.data_u8(channel), (uint32_t)channel, group, chunkPolicy, deflate, shuffle);
      break;
    case Psana::Generic1D::ConfigV0::UINT16:
      createChannelDataset<uint16_t>(obj.data_u16(channel), (uint32_t)channel, group, chunkPolicy, deflate, shuffle);
      break;
    case Psana::Generic1D::ConfigV0::UINT32:
      createChannelDataset<uint32_t>(obj.data_u32(channel), (uint32_t)channel, group, chunkPolicy, deflate, shuffle);
      break;
    case Psana::Generic1D::ConfigV0::FLOAT32:
      createChannelDataset<float>(obj.data_f32(channel), (uint32_t)channel, group, chunkPolicy, deflate, shuffle);
      break;
    case Psana::Generic1D::ConfigV0::FLOAT64:
      createChannelDataset<double>(obj.data_f64(channel), (uint32_t)channel, group, chunkPolicy, deflate, shuffle);
      break;
    }
  }
}


void store_DataV0_v0(const Psana::Generic1D::DataV0* obj, hdf5pp::Group group, long index, bool append) 
{
  if (append) {
    if (obj) {
      storeChannelsDatasetsAt(group, *obj, index);
    } else {
      resizeChannelsDatasets(group, index);
    }
  } else {
    storeChannelsDatasets(group, *obj);
  }
}

} // namespace Generic1D
} // namespace psddl_hdf2psana
