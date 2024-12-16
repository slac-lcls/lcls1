#ifndef Pds_SegmentInfo_hh
#define Pds_SegmentInfo_hh

#include "pdsdata/xtc/DetInfo.hh"

namespace Pds {

  class SegmentInfo: public DetInfo {
  public:
    SegmentInfo(const DetInfo& child, bool preserve=true);
    SegmentInfo(const DetInfo& parent, uint32_t index, uint32_t number,
                uint32_t total, bool preserve=true);

    /* Check if this device type can be a  parent of segements. */
    bool isParent() const;
    /* Check if this device type is a segment. */
    bool isChild() const;
    /* Check if the device type is valid. */
    bool isValid() const;

    /* The starting index of the components in the segment. */
    uint32_t index() const;
    /* The number of components in the segment. */
    uint32_t number() const;
    /* The total number of components across all segments of the detector. */
    uint32_t total() const;

    static bool is_valid(const DetInfo& child);
    static uint32_t get_device_index(const DetInfo& child);
    static uint32_t get_device_number(const DetInfo& child);
    static uint32_t get_device_total(const DetInfo& child);
    static DetInfo::Device get_parent_device(const DetInfo& child);
    static DetInfo::Device get_child_device(const DetInfo& parent, uint32_t number=1);
    static DetInfo parent(const DetInfo& child, bool preserve=true);
    static DetInfo child(const DetInfo& parent, uint32_t index, uint32_t number,
                         uint32_t total, bool preserve=true);
  };

}
#endif
