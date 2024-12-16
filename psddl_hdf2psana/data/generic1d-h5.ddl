@include "psddldata/generic1d.ddl";
@package Generic1D {

// ------------------ ConfigV0 -------------------
@h5schema ConfigV0
  [[version(0)]]
{
  @dataset config {
    @attribute NChannels;
  }
  @dataset Length;
  @dataset SampleType;
  @dataset Offset;
  @dataset Period;
  @dataset data_offset [[method_domain(data_offset, @psanaobj._NChannels)]];
  @dataset Depth [[method_domain(Depth, @psanaobj._NChannels)]];
}

// ------------------ DataV0 -------------------
@h5schema DataV0
  [[version(0)]]
  [[external("psddl_hdf2psana/generic1d.h")]]
{
}

} //- @package Generic1D
