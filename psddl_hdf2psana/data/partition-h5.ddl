@include "psddldata/partition.ddl";
@include "psddl_hdf2psana/xtc-h5.ddl" [[headers("psddl_hdf2psana/xtc.h")]];

@package Partition {

@h5schema Source
  [[version(0)]]
  [[default]]
  [[embedded]]
{
}

@h5schema ConfigV2 
  [[version(0)]]
{
  @dataset data {
    @attribute numWords;
    @attribute numSources;
    @attribute numBldMaskBits;
    @attribute bldMaskIsZero;
    @attribute bldMaskIsNotZero;
  }
  @dataset bldMask;
  @dataset sources;
  @dataset bldMaskHasBitSet [[method_domain(bldMaskHasBitSet, @psanaobj.numBldMaskBits)]];
  @dataset bldMaskHasBitClear [[method_domain(bldMaskHasBitClear, @psanaobj.numBldMaskBits)]];
}

} //- @package Partition
