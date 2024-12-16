@include "psddldata/jungfrau.ddl";
@package Jungfrau  {


//------------------ ConfigV1 ------------------
@h5schema ConfigV1
  [[version(0)]]
  [[default]]
{
}


//------------------ ElementV1 ------------------
@h5schema ElementV1
  [[version(0)]]
{
  @dataset data {
    @attribute frameNumber;
    @attribute ticks;
    @attribute fiducials;
  }
  @dataset frame;
}
} //- @package Jungfrau
