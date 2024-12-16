@include "psddldata/andor.ddl";
@package Andor  {


//------------------ ConfigV1 ------------------
@h5schema ConfigV1
  [[version(0)]]
{
  @dataset config {
    @attribute width;
    @attribute height;
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
    @attribute numDelayShots;
  }
}

//------------------ ConfigV2 ------------------
@h5schema ConfigV2
  [[version(0)]]
{
  @dataset config {
    @attribute width;
    @attribute height;
    @attribute orgX;
    @attribute orgY;
    @attribute binX;
    @attribute binY;
    @attribute exposureTime;
    @attribute coolingTemp;
    @attribute fanMode;
    @attribute cropMode;
    @attribute baselineClamp;
    @attribute highCapacity;
    @attribute gainIndex;
    @attribute readoutSpeedIndex;
    @attribute exposureEventCode;
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
    @attribute temperature;
  }
  @dataset data;
}
} //- @package Andor
