@include "psddldata/xtc.ddl" [[headers("pdsdata/xtc/Src.hh")]];
@package Partition  {


//------------------ Source ------------------
@type Source
  [[value_type]]
  [[pack(4)]]
{
  Pds.Src  _src   -> src;
  uint32_t _group -> group;

  /* Constructor which takes values for every attribute */
  @init() [[auto]];
}

//------------------ ConfigV1 ------------------
@type ConfigV1
  [[type_id(Id_PartitionConfig, 1)]]
  [[config_type]]
{
  uint64_t _bldMask     -> bldMask;       /* Mask of requested BLD */
  uint32_t _numSources -> numSources;	  /* Number of source definitions */
  Source _sources[@self.numSources()] -> sources  [[shape_method(sources_shape)]];	/* Source configuration objects */

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];

}

//------------------ ConfigV2 ------------------
@type ConfigV2
  [[type_id(Id_PartitionConfig, 2)]]
  [[config_type]]
{
  /* Number of words for the bit mask */
  uint32_t  _numWords -> numWords;

  /* Number of source definitions */
  uint32_t  _numSources -> numSources;

  /* Mask of requested BLD */
  uint32_t  _bldMask[@self.numWords()] -> bldMask   [[shape_method(bldmask_shape)]];

  /* Source configuration objects */
  Source   _sources[@self.numSources()] -> sources  [[shape_method(sources_shape)]];

  /* Returns the total number of bits in the mask */
  uint32_t numBldMaskBits()
  [[language("C++")]] @{ return @self.numWords() * 32; @}

  /* Returns non-zero if all bits in the mask are unset, zero otherwise. */
  uint32_t bldMaskIsZero()
  [[language("C++")]] @{ for (unsigned idx = 0; idx != _numWords; ++ idx) if (@self.bldMask()[idx]) return 0; return 1; @}

  /* Returns non-zero if any bits in the mask are set, zero otherwise. */
  uint32_t bldMaskIsNotZero()
  [[language("C++")]] @{ for (unsigned idx = 0; idx != _numWords; ++ idx) if (@self.bldMask()[idx]) return 1; return 0; @}

  /* Returns non-zero if the bit cooresponding to iBit in the word is set, zero otherwise. */
  uint32_t bldMaskHasBitSet(uint32_t iBit)
  [[language("C++")]] @{ return (@self.bldMask()[iBit >> 5] & (1 << (iBit & 0x1f))); @}

  /* Returns non-zero if the bit cooresponding to iBit in the word is unset, zero otherwise. */
  uint32_t bldMaskHasBitClear(uint32_t iBit)
  [[language("C++")]] @{ return !bldMaskHasBitSet(iBit); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

} //- @package Partition
