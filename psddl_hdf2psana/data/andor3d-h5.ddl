@include "psddldata/andor3d.ddl";
@package Andor3d  {


//------------------ ConfigV1 ------------------
@h5schema ConfigV1
  [[version(0)]]
{
  @dataset config {
    @attribute width;
    @attribute height;
    @attribute numSensors;
    @attribute orgX;
    @attribute orgY;
    @attribute binX;
    @attribute binY;
    @attribute exposureTime;
    @attribute coolingTemp;
    @attribute fanMode;
    @attribute baselineClamp;
    @attribute highCapacity;
    @attribute gainIndex;
    @attribute readoutSpeedIndex;
    @attribute exposureEventCode;
    @attribute exposureStartDelay;
    @attribute numDelayShots;
 }
}


//------------------ FrameV1 ------------------
@h5schema FrameV1
  [[version(0)]]
{
  @dataset frame {
    @attribute shotIdStart;
    @attribute readoutTime;
  }
  @dataset temperature [[zero_dims]];
  @dataset data [[zero_dims]];
}
} //- @package Andor
