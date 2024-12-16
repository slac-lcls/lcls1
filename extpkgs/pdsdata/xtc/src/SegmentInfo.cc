#include "pdsdata/xtc/SegmentInfo.hh"

using namespace Pds;

static const int CHILD_BITS = 4;
static const int CHILD_MASK = (1<<CHILD_BITS) - 1;
static const DetInfo::Device INVALID = DetInfo::NoDevice;

SegmentInfo::SegmentInfo(const DetInfo& child, bool preserve) :
  DetInfo(preserve ? child.processId() : 0,
          child.detector(),
          child.detId()>>CHILD_BITS,
          get_parent_device(child),
          child.devId()>>CHILD_BITS)
{}

SegmentInfo::SegmentInfo(const DetInfo& parent, uint32_t index, uint32_t number,
                         uint32_t total, bool preserve) :
  DetInfo(preserve ? parent.processId() : 0,
          parent.detector(),
          (parent.detId()<<CHILD_BITS) | (CHILD_MASK & total),
          get_child_device(parent, number),
          (parent.devId()<<CHILD_BITS) | (CHILD_MASK & index))
{}

bool SegmentInfo::isParent() const
{
  return get_child_device(*this) != INVALID;
}

bool SegmentInfo::isChild() const
{
  return get_parent_device(*this) != INVALID;
}

bool SegmentInfo::isValid() const
{
  return this->device() != INVALID;
}

uint32_t SegmentInfo::index() const
{
  if (this->isChild()) {
    return (this->devId() & CHILD_MASK);
  } else {
    return 0;
  }
}

uint32_t SegmentInfo::number() const
{
  switch (this->device()) {
  case DetInfo::JungfrauSegment:
    return 1;
  case DetInfo::JungfrauSegmentM2:
    return 2;
  case DetInfo::JungfrauSegmentM3:
    return 3;
  case DetInfo::JungfrauSegmentM4:
    return 4;
  default:
    return 1;
  }
}

uint32_t SegmentInfo::total() const
{
  if (this->isChild()) {
    return (this->detId() & CHILD_MASK);
  } else {
    return 1;
  }
}

bool SegmentInfo::is_valid(const DetInfo& child)
{
  const SegmentInfo& seg_info = reinterpret_cast<const SegmentInfo&>(child);
  return seg_info.isValid();
}

uint32_t SegmentInfo::get_device_index(const DetInfo& child)
{
  const SegmentInfo& seg_info = reinterpret_cast<const SegmentInfo&>(child);
  return seg_info.index();
}

uint32_t SegmentInfo::get_device_number(const DetInfo& child)
{
  const SegmentInfo& seg_info = reinterpret_cast<const SegmentInfo&>(child);
  return seg_info.number();
}

uint32_t SegmentInfo::get_device_total(const DetInfo& child)
{
  const SegmentInfo& seg_info = reinterpret_cast<const SegmentInfo&>(child);
  return seg_info.total();
}

DetInfo::Device SegmentInfo::get_parent_device(const DetInfo& child)
{
  switch (child.device()) {
  case DetInfo::JungfrauSegment:
  case DetInfo::JungfrauSegmentM2:
  case DetInfo::JungfrauSegmentM3:
  case DetInfo::JungfrauSegmentM4:
    return DetInfo::Jungfrau;
  default:
    return INVALID;
  }
}

DetInfo::Device SegmentInfo::get_child_device(const DetInfo& parent, uint32_t number)
{
  switch (parent.device()) {
  case DetInfo::Jungfrau:
    switch (number) {
    case 1:
      return DetInfo::JungfrauSegment;
    case 2:
      return DetInfo::JungfrauSegmentM2;
    case 3:
      return DetInfo::JungfrauSegmentM3;
    case 4:
      return DetInfo::JungfrauSegmentM4;
    default:
      return INVALID;
    }
  default:
    return INVALID;
  }
}

DetInfo SegmentInfo::parent(const DetInfo& child, bool preserve)
{
  return DetInfo(preserve ? child.processId() : 0,
                 child.detector(),
                 child.detId()>>CHILD_BITS,
                 get_parent_device(child),
                 child.devId()>>CHILD_BITS);
}

DetInfo SegmentInfo::child(const DetInfo& parent, uint32_t index, uint32_t number,
                           uint32_t total, bool preserve)
{
  return DetInfo(preserve ? parent.processId() : 0,
                 parent.detector(),
                 (parent.detId()<<CHILD_BITS) | (CHILD_MASK & total),
                 get_child_device(parent, number),
                 (parent.devId()<<CHILD_BITS) | (CHILD_MASK & index));
}
