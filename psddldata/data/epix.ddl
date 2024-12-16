@include "psddldata/genericpgp.ddl";

@package Epix  {


//------------------ AsicConfigV1 ------------------
@type AsicConfigV1
  [[pack(4)]]
{
  uint32_t _reg1 {
    uint8_t _monostPulser:3 -> monostPulser;
    uint32_t _z:29;
  }
  uint32_t _reg2 {
    uint8_t _dummyTest:1 -> dummyTest;
    uint8_t _dummyMask:1 -> dummyMask;
    uint32_t _z:30;
  }
  uint32_t _reg3 {
    uint16_t _pulser:10 -> pulser;
    uint8_t _pbit:1 -> pbit;
    uint8_t _atest:1 -> atest;
    uint8_t _test:1 -> test;
    uint8_t _sabTest:1 -> sabTest;
    uint8_t _hrTest:1 -> hrTest;
    uint32_t _z:17;
  }
  uint32_t _reg4 {
    uint8_t _digMon1:4 -> digMon1;
    uint8_t _digMon2:4 -> digMon2;
    uint32_t _z:24;
  }
  uint32_t _reg5 {
    uint8_t _pulserDac:3 -> pulserDac;
    uint32_t _z:29;
  }
  uint32_t _reg6 {
    uint8_t _Dm1En:1 -> Dm1En;
    uint8_t _Dm2En:1 -> Dm2En;
    uint8_t _z1:2;
    uint8_t _slvdSBit:1 -> slvdSBit;
    uint32_t _z2:27;
  }
  uint32_t _reg7 {
    uint8_t _VRefDac:6 -> VRefDac;
    uint32_t _z:26;
  }
  uint32_t _reg8 {
    uint8_t _TpsTComp:1 -> TpsTComp;
    uint8_t _TpsMux:4 -> TpsMux;
    uint8_t _RoMonost:3 -> RoMonost;
    uint32_t _z:24;
  }
  uint32_t _reg9 {
    uint8_t _TpsGr:4 -> TpsGr;
    uint8_t _S2dGr:4 -> S2dGr;
    uint32_t _z:24;
  }
  uint32_t _reg10 {
    uint8_t _PpOcbS2d:1 -> PpOcbS2d;
    uint8_t _Ocb:3 -> Ocb;
    uint8_t _Monost:3 -> Monost;
    uint8_t _FastppEnable:1 -> FastppEnable;
    uint32_t _z:24;
  }
  uint32_t _reg11 {
    uint8_t _Preamp:3 -> Preamp;
    uint8_t _z1:1;
    uint8_t _PixelCb:3 -> PixelCb;
    uint32_t _z2:25;
  }
  uint32_t _reg12 {
    uint8_t _S2dTComp:1 -> S2dTComp;
    uint8_t _FilterDac:6 -> FilterDac;
    uint32_t _z:25;
  }
  uint32_t _reg13 {
    uint8_t _TC:2 -> TC;
    uint8_t _S2d:3 -> S2d;
    uint8_t _S2dDacBias:3 -> S2dDacBias;
    uint32_t _z:24;
  }
  uint32_t _reg14 {
    uint8_t _TpsTcDac:2 -> TpsTcDac;
    uint8_t _TpsDac:6 -> TpsDac;
    uint32_t _z:24;
  }
  uint32_t _reg15 {
    uint8_t _S2dTcDac:2 -> S2dTcDac;
    uint8_t _S2dDac:6 -> S2dDac;
    uint32_t _z:24;
  }
  uint32_t _reg16 {
    uint8_t _TestBe:1 -> TestBe;
    uint8_t _IsEn:1 -> IsEn;
    uint8_t _DelExec:1 -> DelExec;
    uint8_t _DelCckReg:1 -> DelCckReg;
    uint32_t _z:28;
  }
  uint32_t _reg17 {
    uint16_t _RowStartAddr:9 -> RowStartAddr;
    uint32_t _z:23;
  }
  uint32_t _reg18 {
    uint16_t _RowStopAddr:9 -> RowStopAddr;
    uint32_t _z:23;
  }
  uint32_t _reg19 {
    uint8_t _ColStartAddr:7 -> ColStartAddr;
    uint32_t _z:25;
  }
  uint32_t _reg20 {
    uint8_t _ColStopAddr:7 -> ColStopAddr;
    uint32_t _z:25;
  }
  uint32_t _reg21 {
    uint16_t _chipID:16 -> chipID;
    uint16_t _z:16;
  }

  /* Constructor with value for each attribute */
  @init()  [[auto]];

}


//------------------ ConfigV1 ------------------
@type ConfigV1
  [[type_id(Id_EpixConfig, 1)]]
  [[config_type]]
  [[pack(4)]]
{
  uint32_t _version -> version;
  uint32_t _runTrigDelay -> runTrigDelay;
  uint32_t _daqTrigDelay -> daqTrigDelay;
  uint32_t _dacSetting -> dacSetting;
  uint32_t _asicPins {
    uint8_t _asicGR:1 -> asicGR;
    uint8_t _asicAcq:1 -> asicAcq;
    uint8_t _asicR0:1 -> asicR0;
    uint8_t _asicPpmat:1 -> asicPpmat;
    uint8_t _asicPpbe:1 -> asicPpbe;
    uint8_t _asicRoClk:1 -> asicRoClk;
    uint32_t _z:26;
  }
  uint32_t _asicControls {
    uint8_t _asicGRControl:1 -> asicGRControl;
    uint8_t _asicAcqControl:1 -> asicAcqControl;
    uint8_t _asicR0Control:1 -> asicR0Control;
    uint8_t _asicPpmatControl:1 -> asicPpmatControl;
    uint8_t _asicPpbeControl:1 -> asicPpbeControl;
    uint8_t _asicR0ClkControl:1 -> asicR0ClkControl;
    uint8_t _prepulseR0En:1 -> prepulseR0En;
    uint32_t _adcStreamMode:1 -> adcStreamMode;
    uint8_t _testPatternEnable:1 -> testPatternEnable;
    uint8_t _z1:23;
  }
  uint32_t _acqToAsicR0Delay -> acqToAsicR0Delay;
  uint32_t _asicR0ToAsicAcq -> asicR0ToAsicAcq;
  uint32_t _asicAcqWidth -> asicAcqWidth;
  uint32_t _asicAcqLToPPmatL -> asicAcqLToPPmatL;
  uint32_t _asicRoClkHalfT -> asicRoClkHalfT;
  uint32_t _adcReadsPerPixel -> adcReadsPerPixel;
  uint32_t _adcClkHalfT -> adcClkHalfT;
  uint32_t _asicR0Width -> asicR0Width;
  uint32_t _adcPipelineDelay -> adcPipelineDelay;
  uint32_t _prepulseR0Width -> prepulseR0Width;
  uint32_t _prepulseR0Delay -> prepulseR0Delay;
  uint32_t _digitalCardId0 -> digitalCardId0;
  uint32_t _digitalCardId1 -> digitalCardId1;
  uint32_t _analogCardId0 -> analogCardId0;
  uint32_t _analogCardId1 -> analogCardId1;
  uint32_t _lastRowExclusions -> lastRowExclusions;
  uint32_t _numberOfAsicsPerRow -> numberOfAsicsPerRow;
  uint32_t _numberOfAsicsPerColumn -> numberOfAsicsPerColumn;
  // generally 2 x 2
  uint32_t _numberOfRowsPerAsic -> numberOfRowsPerAsic;
  // for epix100  352
  uint32_t _numberOfPixelsPerAsicRow -> numberOfPixelsPerAsicRow;
  // for epix100 96*4
  uint32_t _baseClockFrequency -> baseClockFrequency;
  uint32_t _asicMask -> asicMask;
  AsicConfigV1 _asics[@self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn()] -> asics;
  uint32_t _asicPixelTestArray[@self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn()][ @self.numberOfRowsPerAsic()][ (@self.numberOfPixelsPerAsicRow()+31)/32] -> asicPixelTestArray;
  uint32_t _asicPixelMaskArray[@self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn()][ @self.numberOfRowsPerAsic()][ (@self.numberOfPixelsPerAsicRow()+31)/32] -> asicPixelMaskArray;

  /* Number of rows in a readout unit */
  uint32_t numberOfRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.numberOfRowsPerAsic() - @self.lastRowExclusions(); @}

  /* Number of columns in a readout unit */
  uint32_t numberOfColumns()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfPixelsPerAsicRow(); @}

  /* Number of columns in a readout unit */
  uint32_t numberOfAsics()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];

  /* Constructor which takes values necessary for size calculations */
  @init(numberOfAsicsPerRow -> _numberOfAsicsPerRow, numberOfAsicsPerColumn -> _numberOfAsicsPerColumn, 
      numberOfRowsPerAsic -> _numberOfRowsPerAsic, numberOfPixelsPerAsicRow -> _numberOfPixelsPerAsicRow)  [[inline]];

}

//------------------ Asic10kConfigV1 ------------------
@type Asic10kConfigV1
  [[pack(4)]]
{
  uint32_t _reg1 {
    uint8_t _CompTH_DAC:6 -> CompTH_DAC;
    uint8_t _CompEn_0:1 -> CompEn_0;
    uint8_t _PulserSync:1 -> PulserSync;
    uint32_t _z:24;
  }
  uint32_t _reg2 {
    uint8_t _dummyTest:1 -> dummyTest;
    uint8_t _dummyMask:1 -> dummyMask;
    uint8_t _dummyG:1 -> dummyG;
    uint8_t _dummyGA:1 -> dummyGA;
    uint16_t _dummyUpper12bits:12 -> dummyUpper12bits;
    uint32_t _z:16;
  }
  uint32_t _reg3 {
    uint16_t _pulser:10 -> pulser;
    uint8_t _pbit:1 -> pbit;
    uint8_t _atest:1 -> atest;
    uint8_t _test:1 -> test;
    uint8_t _sabTest:1 -> sabTest;
    uint8_t _hrTest:1 -> hrTest;
    uint8_t _PulserR:1 -> pulserR;
    uint32_t _z:16;
  }
  uint32_t _reg4 {
    uint8_t _digMon1:4 -> digMon1;
    uint8_t _digMon2:4 -> digMon2;
    uint32_t _z:24;
  }
  uint32_t _reg5 {
    uint8_t _pulserDac:3 -> pulserDac;
    uint8_t _monostPulser:3 -> monostPulser;
    uint8_t _CompEn_1:1 -> CompEn_1;
    uint8_t _CompEn_2:1 -> CompEn_2;
    uint32_t _z:24;
  }
  uint32_t _reg6 {
    uint8_t _Dm1En:1 -> Dm1En;
    uint8_t _Dm2En:1 -> Dm2En;
    uint8_t _emph_bd:3 -> emph_bd;
    uint8_t _emph_bc:3 -> emph_bc;
    uint32_t _z:24;
  }
  uint32_t _reg7 {
    uint8_t _VRefDac:6 -> VRefDac;
    uint8_t _VrefLow:2 -> vrefLow;
    uint32_t _z:24;
  }
  uint32_t _reg8 {
    uint8_t _TpsTComp:1 -> TpsTComp;
    uint8_t _TpsMux:4 -> TpsMux;
    uint8_t _RoMonost:3 -> RoMonost;
    uint32_t _z:24;
  }
  uint32_t _reg9 {
    uint8_t _TpsGr:4 -> TpsGr;
    uint8_t _S2dGr:4 -> S2dGr;
    uint32_t _z:24;
  }
  uint32_t _reg10 {
    uint8_t _PpOcbS2d:1 -> PpOcbS2d;
    uint8_t _Ocb:3 -> Ocb;
    uint8_t _Monost:3 -> Monost;
    uint8_t _FastppEnable:1 -> FastppEnable;
    uint32_t _z:24;
  }
  uint32_t _reg11 {
    uint8_t _Preamp:3 -> Preamp;
    uint8_t _PixelCb:3 -> PixelCb;
    uint8_t _Vld1_b:2 -> Vld1_b;
    uint32_t _z:24;
  }
  uint32_t _reg12 {
    uint8_t _S2dTComp:1 -> S2dTComp;
    uint8_t _FilterDac:6 -> FilterDac;
    uint8_t _testVDTransmitter:1 -> testVDTransmitter;
    uint32_t _z:24;
  }
  uint32_t _reg13 {
    uint8_t _TC:2 -> TC;
    uint8_t _S2d:3 -> S2d;
    uint8_t _S2dDacBias:3 -> S2dDacBias;
    uint32_t _z:24;
  }
  uint32_t _reg14 {
    uint8_t _TpsTcDac:2 -> TpsTcDac;
    uint8_t _TpsDac:6 -> TpsDac;
    uint32_t _z:24;
  }
  uint32_t _reg15 {
    uint8_t _S2dTcDac:2 -> S2dTcDac;
    uint8_t _S2dDac:6 -> S2dDac;
    uint32_t _z:24;
  }
  uint32_t _reg16 {
    uint8_t _TestBe:1 -> TestBe;
    uint8_t _IsEn:1 -> IsEn;
    uint8_t _DelExec:1 -> DelExec;
    uint8_t _DelCckReg:1 -> DelCckReg;
    uint8_t _RO_rst_en:1 -> RO_rst_en;
    uint8_t _slvdSBit:1 -> slvdSBit;
    uint8_t _FELmode:1 -> FELmode;
    uint8_t _CompEnOn:1 -> CompEnOn;
    uint32_t _z:24;
  }
  uint32_t _reg17 {
    uint16_t _RowStartAddr:9 -> RowStartAddr;
    uint32_t _z:23;
  }
  uint32_t _reg18 {
    uint16_t _RowStopAddr:9 -> RowStopAddr;
    uint32_t _z:23;
  }
  uint32_t _reg19 {
    uint8_t _ColStartAddr:7 -> ColStartAddr;
    uint32_t _z:25;
  }
  uint32_t _reg20 {
    uint8_t _ColStopAddr:7 -> ColStopAddr;
    uint32_t _z:25;
  }
  uint32_t _reg21 {
    uint16_t _chipID:16 -> chipID;
    uint16_t _z:16;
  }

  /* Constructor with value for each attribute */
  @init()  [[auto]];

}


//------------------ Config10KV1 ------------------
@type Config10KV1
  [[type_id(Id_Epix10kConfig, 1)]]
  [[config_type]]
  [[pack(4)]]
{
  uint32_t _version -> version;
  uint32_t _runTrigDelay -> runTrigDelay;
  uint32_t _daqTrigDelay -> daqTrigDelay;
  uint32_t _dacSetting -> dacSetting;
  uint32_t _asicPins {
    uint8_t _asicGR:1 -> asicGR;
    uint8_t _asicAcq:1 -> asicAcq;
    uint8_t _asicR0:1 -> asicR0;
    uint8_t _asicPpmat:1 -> asicPpmat;
    uint8_t _asicPpbe:1 -> asicPpbe;
    uint8_t _asicRoClk:1 -> asicRoClk;
    uint32_t _z:26;
  }
  uint32_t _asicControls {
    uint8_t _asicGRControl:1 -> asicGRControl;
    uint8_t _asicAcqControl:1 -> asicAcqControl;
    uint8_t _asicR0Control:1 -> asicR0Control;
    uint8_t _asicPpmatControl:1 -> asicPpmatControl;
    uint8_t _asicPpbeControl:1 -> asicPpbeControl;
    uint8_t _asicR0ClkControl:1 -> asicR0ClkControl;
    uint8_t _prepulseR0En:1 -> prepulseR0En;
    uint32_t _adcStreamMode:1 -> adcStreamMode;
    uint8_t _testPatternEnable:1 -> testPatternEnable;
    uint8_t _SyncMode:2 -> SyncMode;  // new
    uint8_t _R0Mode:1 -> R0Mode;  // new
    uint8_t _z1:20;
  }
  uint32_t _DoutPipelineDelay -> DoutPipelineDelay;  // new
  uint32_t _acqToAsicR0Delay -> acqToAsicR0Delay;
  uint32_t _asicR0ToAsicAcq -> asicR0ToAsicAcq;
  uint32_t _asicAcqWidth -> asicAcqWidth;
  uint32_t _asicAcqLToPPmatL -> asicAcqLToPPmatL;
  uint32_t _asicRoClkHalfT -> asicRoClkHalfT;
  uint32_t _adcReadsPerPixel -> adcReadsPerPixel;
  uint32_t _adcClkHalfT -> adcClkHalfT;
  uint32_t _asicR0Width -> asicR0Width;
  uint32_t _adcPipelineDelay -> adcPipelineDelay;
  uint32_t _Sync {  // new
    uint16_t _SyncWidth:16 -> SyncWidth;  // new
    uint16_t _SyncDelay:16 -> SyncDelay;  // new
  }  // new
  uint32_t _prepulseR0Width -> prepulseR0Width;
  uint32_t _prepulseR0Delay -> prepulseR0Delay;
  uint32_t _digitalCardId0 -> digitalCardId0;
  uint32_t _digitalCardId1 -> digitalCardId1;
  uint32_t _analogCardId0 -> analogCardId0;
  uint32_t _analogCardId1 -> analogCardId1;
  uint32_t _lastRowExclusions -> lastRowExclusions;
  uint32_t _numberOfAsicsPerRow -> numberOfAsicsPerRow;
  uint32_t _numberOfAsicsPerColumn -> numberOfAsicsPerColumn;
  uint32_t _numberOfRowsPerAsic -> numberOfRowsPerAsic;
  // for epix10k  176
  uint32_t _numberOfPixelsPerAsicRow -> numberOfPixelsPerAsicRow;
  // for epix10k 48*4
  uint32_t _baseClockFrequency -> baseClockFrequency;
  uint32_t _asicMask -> asicMask;
  uint32_t _Scope {
    uint8_t _scopeEnable:1 -> scopeEnable;
    uint8_t _scopeTrigEdge:1 -> scopeTrigEdge;
    uint8_t _scopeTrigChan:4 -> scopeTrigChan;
    uint8_t _scopeArmMode:2 -> scopeArmMode;
    uint8_t _z:8;
    uint16_t _scopeADCThreshold:16 -> scopeADCThreshold;
  }
  uint32_t _ScopeTriggerParms_1 {
    uint16_t _scopeTrigHoldoff:13 -> scopeTrigHoldoff;
    uint16_t _scopeTrigOffset:13 -> scopeTrigOffset;
  }
  uint32_t _ScopeTriggerParms_2 {
    uint16_t _scopeTraceLength:13 -> scopeTraceLength;
    uint16_t _scopeADCsameplesToSkip:13 -> scopeADCsameplesToSkip;
  }
  uint32_t _ScopeWaveformSelects {
    uint8_t _scopeChanAwaveformSelect:5 -> scopeChanAwaveformSelect;
    uint8_t _scopeChanBwaveformSelect:5 -> scopeChanBwaveformSelect;
    uint32_t _z:22;
  }
  Asic10kConfigV1 _asics[@self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn()] -> asics;
  uint16_t _asicPixelConfigArray[@self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn()][ @self.numberOfRowsPerAsic()][ (@self.numberOfPixelsPerAsicRow())] -> asicPixelConfigArray;

  /* Number of rows in a readout unit */
  uint32_t numberOfRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.numberOfRowsPerAsic() - @self.lastRowExclusions(); @}

  /* Number of columns in a readout unit */
  uint32_t numberOfColumns()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfPixelsPerAsicRow(); @}

  /* Number of columns in a readout unit */
  uint32_t numberOfAsics()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];

  /* Constructor which takes values necessary for size calculations */
  @init(numberOfAsicsPerRow -> _numberOfAsicsPerRow, numberOfAsicsPerColumn -> _numberOfAsicsPerColumn, 
      numberOfRowsPerAsic -> _numberOfRowsPerAsic, numberOfPixelsPerAsicRow -> _numberOfPixelsPerAsicRow,
      lastRowExclusions -> _lastRowExclusions)  [[inline]];

}

//------------------ Asic100aConfigV1 ------------------
@type Asic100aConfigV1
  [[pack(4)]]
{
  uint32_t _reg1 {
    uint8_t _pulserVsPixelOnDelay:3 -> pulserVsPixelOnDelay;
    uint8_t _z1:4;
    uint8_t _pulserSync:1 -> pulserSync;
    uint32_t _z2:24;
  }
  uint32_t _reg2 {
    uint8_t _dummyTest:1 -> dummyTest;
    uint8_t _dummyMask:1 -> dummyMask;
    uint32_t _z:30;
  }
  uint32_t _reg3 {
    uint16_t _testPulserLevel:10 -> testPulserLevel;
    uint8_t _pulserCounterDirection:1     -> pulserCounterDirection;
    uint8_t _automaticTestModeEnable:1    -> automaticTestModeEnable;
    uint8_t _testMode:1     -> testMode;
    uint8_t _testModeWithDarkFrame:1  -> testModeWithDarkFrame;
    uint8_t _highResolutionModeTest:1   -> highResolutionModeTest;
    uint8_t _pulserReset:1  -> pulserReset;
    uint16_t _z:16;
  }
  uint32_t _reg4 {
    uint8_t _digitalMonitorMux1:4 -> digitalMonitorMux1;
    uint8_t _digitalMonitorMux2:4 -> digitalMonitorMux2;
    uint32_t _z:24;
  }
  uint32_t _reg5 {
    uint8_t _testPulserCurrent:3 -> testPulserCurrent;
    uint8_t _z1:1;
    uint8_t _testPointSystemOutputDynamicRange:4 -> testPointSystemOutputDynamicRange;
    uint32_t _z2:24;
  }
  uint32_t _reg6 {
    uint8_t _digitalMonitor1Enable:1 -> digitalMonitor1Enable;
    uint8_t _digitalMonitor2Enable:1 -> digitalMonitor2Enable;
    uint8_t _z1:2;
    uint8_t _LVDS_ImpedenceMatchingEnable:1 -> LVDS_ImpedenceMatchingEnable;
    uint32_t _z2:27;
  }
  uint32_t _reg7 {
    uint8_t _VRefBaseLineDac:6 -> VRefBaselineDac;
    uint8_t _extraRowsLowReferenceValue:2 -> extraRowsLowReferenceValue;
    uint32_t _z:24;
  }
  uint32_t _reg8 {
    uint8_t _testPointSystemTemperatureCompensationEnable:1 -> testPointSystemTemperatureCompensationEnable;
    uint8_t _testPointSytemInputSelect:4 -> testPointSytemInputSelect;
    uint8_t _programmableReadoutDelay:3 -> programmableReadoutDelay;
    uint32_t _z:24;
  }
  uint32_t _reg9 {
    uint8_t _outputDriverOutputDynamicRange0:4 -> outputDriverOutputDynamicRange0;
    uint8_t _outputDriverOutputDynamicRange1:4 -> outputDriverOutputDynamicRange1;
    uint32_t _z:24;
  }
  uint32_t _reg10 {
    uint8_t _balconyEnable:1 -> balconyEnable;
    uint8_t _balconyDriverCurrent:3 -> balconyDriverCurrent;
    uint8_t _fastPowerPulsingSpeed:3 -> fastPowerPulsingSpeed;
    uint8_t _fastPowerPulsingEnable:1 -> fastPowerPulsingEnable;
    uint32_t _z:24;
  }
  uint32_t _reg11 {
    uint8_t _preamplifierCurrent:3 -> preamplifierCurrent;
    uint8_t _pixelOutputBufferCurrent:3 -> pixelOutputBufferCurrent;
    uint8_t _pixelBufferAndPreamplifierDrivingCapabilities:2 -> pixelBufferAndPreamplifierDrivingCapabilities;
    uint32_t _z2:24;
  }
  uint32_t _reg12 {
    uint8_t _outputDriverTemperatureCompensationEnable:1 -> outputDriverTemperatureCompensationEnable;
    uint8_t _pixelFilterLevel:6 -> pixelFilterLevel;
    uint32_t _z:25;
  }
  uint32_t _reg13 {
    uint8_t _bandGapReferenceTemperatureCompensationBits:2 -> bandGapReferenceTemperatureCompensationBits;
    uint8_t _outputDriverDrivingCapabilitiesAndStability:3 -> outputDriverDrivingCapabilitiesAndStability;
    uint8_t _outputDriverDacReferenceBias:3 -> outputDriverDacReferenceBias;
    uint32_t _z:24;
  }
  uint32_t _reg14 {
    uint8_t _testPointSystemTemperatureCompensationGain:2 -> testPointSystemTemperatureCompensationGain;
    uint8_t _testPointSystemInputCommonMode:6 -> testPointSystemInputCommonMode;
    uint32_t _z:24;
  }
  uint32_t _reg15 {
    uint8_t _outputDriverTemperatureCompensationGain0:2 -> outputDriverTemperatureCompensationGain0;
    uint8_t _outputDriverInputCommonMode0:6 -> outputDriverInputCommonMode0;
    uint32_t _z:24;
  }
  uint32_t _reg16 {
    uint8_t _testBackEnd:1 -> testBackEnd;
    uint8_t _interleavedReadOutEnable:1 -> interleavedReadOutEnable;
    uint8_t EXEC_DelayEnable:1 -> EXEC_DelayEnable;
    uint8_t _CCK_RegDelayEnable:1 -> CCK_RegDelayEnable;
    uint8_t _syncPinEnable:1 -> syncPinEnable;
    uint32_t _z:28;
  }
  uint32_t _reg17 {
    uint16_t _RowStartAddr:9 -> RowStartAddr;
    uint32_t _z:23;
  }
  uint32_t _reg18 {
    uint16_t _RowStopAddr:9 -> RowStopAddr;
    uint32_t _z:23;
  }
  uint32_t _reg19 {
    uint8_t _ColumnStartAddr:7 -> ColumnStartAddr;
    uint32_t _z:25;
  }
  uint32_t _reg20 {
    uint8_t _ColumnStopAddr:7 -> ColumnStopAddr;
    uint32_t _z:25;
  }
  uint32_t _reg21 {
    uint16_t _chipID:16 -> chipID;
    uint16_t _z:16;
  }
  uint32_t _reg22 {
    uint8_t _outputDriverOutputDynamicRange2:4 -> outputDriverOutputDynamicRange2;
    uint8_t _outputDriverOutputDynamicRange3:4 -> outputDriverOutputDynamicRange3;
    uint32_t _z:24;
  }
  uint32_t _reg23 {
    uint8_t _outputDriverTemperatureCompensationGain1:2 -> outputDriverTemperatureCompensationGain1;
    uint8_t _outputDriverInputCommonMode1:6 -> outputDriverInputCommonMode1;
    uint32_t _z:24;
  }
  uint32_t _reg24 {
    uint8_t _outputDriverTemperatureCompensationGain2:2 -> outputDriverTemperatureCompensationGain2;
    uint8_t _outputDriverInputCommonMode2:6 -> outputDriverInputCommonMode2;
    uint32_t _z:24;
  }
  uint32_t _reg25 {
    uint8_t _outputDriverTemperatureCompensationGain3:2 -> outputDriverTemperatureCompensationGain3;
    uint8_t _outputDriverInputCommonMode3:6 -> outputDriverInputCommonMode3;
    uint32_t _z:24;
  }
  

  /* Constructor with value for each attribute */
  @init()  [[auto]];

}

//------------------ Config100aV1 ------------------
@type Config100aV1
  [[type_id(Id_Epix100aConfig, 1)]]
  [[config_type]]
  [[pack(4)]]
{
  uint32_t _version -> version;
  uint32_t _runTrigDelay -> runTrigDelay;
  uint32_t _daqTrigDelay -> daqTrigDelay;
  uint32_t _dacSetting -> dacSetting;
  uint32_t _asicPins {
    uint8_t _asicGR:1 -> asicGR;
    uint8_t _asicAcq:1 -> asicAcq;
    uint8_t _asicR0:1 -> asicR0;
    uint8_t _asicPpmat:1 -> asicPpmat;
    uint8_t _asicPpbe:1 -> asicPpbe;
    uint8_t _asicRoClk:1 -> asicRoClk;
    uint32_t _z:26;
  }
  uint32_t _asicControls {
    uint8_t _asicGRControl:1 -> asicGRControl;
    uint8_t _asicAcqControl:1 -> asicAcqControl;
    uint8_t _asicR0Control:1 -> asicR0Control;
    uint8_t _asicPpmatControl:1 -> asicPpmatControl;
    uint8_t _asicPpbeControl:1 -> asicPpbeControl;
    uint8_t _asicR0ClkControl:1 -> asicR0ClkControl;
    uint8_t _prepulseR0En:1 -> prepulseR0En;
    uint32_t _adcStreamMode:1 -> adcStreamMode;
    uint8_t _testPatternEnable:1 -> testPatternEnable;
    uint8_t _SyncMode:2 -> SyncMode;
    uint8_t _R0Mode:1 -> R0Mode;
    uint8_t _z1:20;
  }
  uint32_t _acqToAsicR0Delay -> acqToAsicR0Delay;
  uint32_t _asicR0ToAsicAcq -> asicR0ToAsicAcq;
  uint32_t _asicAcqWidth -> asicAcqWidth;
  uint32_t _asicAcqLToPPmatL -> asicAcqLToPPmatL;
  uint32_t _asicPPmatToReadout -> asicPPmatToReadout;
  uint32_t _asicRoClkHalfT -> asicRoClkHalfT;
  uint32_t _adcReadsPerPixel -> adcReadsPerPixel;
  uint32_t _adcClkHalfT -> adcClkHalfT;
  uint32_t _asicR0Width -> asicR0Width;
  uint32_t _adcPipelineDelay -> adcPipelineDelay;
  uint32_t _Sync {  // new
    uint16_t _SyncWidth:16 -> SyncWidth;
    uint16_t _SyncDelay:16 -> SyncDelay;
  }  // new
  uint32_t _prepulseR0Width -> prepulseR0Width;
  uint32_t _prepulseR0Delay -> prepulseR0Delay;
  uint32_t _digitalCardId0 -> digitalCardId0;
  uint32_t _digitalCardId1 -> digitalCardId1;
  uint32_t _analogCardId0 -> analogCardId0;
  uint32_t _analogCardId1 -> analogCardId1;
  uint32_t _numberOfAsicsPerRow -> numberOfAsicsPerRow;
  uint32_t _numberOfAsicsPerColumn -> numberOfAsicsPerColumn;
  uint32_t _numberOfRowsPerAsic -> numberOfRowsPerAsic;
  uint32_t _numberOfReadableRowsPerAsic -> numberOfReadableRowsPerAsic;
  // for epix100a  352
  uint32_t _numberOfPixelsPerAsicRow -> numberOfPixelsPerAsicRow;
  // for epix100a 96*4 = 384
  uint32_t _calibrationRowCountPerASIC -> calibrationRowCountPerASIC;
  uint32_t _environmentalRowCountPerASIC -> environmentalRowCountPerASIC;
  uint32_t _baseClockFrequency -> baseClockFrequency;
  uint32_t _asicMask -> asicMask;
  uint32_t _Scope {
    uint8_t _scopeEnable:1 -> scopeEnable;
    uint8_t _scopeTrigEdge:1 -> scopeTrigEdge;
    uint8_t _scopeTrigChan:4 -> scopeTrigChan;
    uint8_t _scopeArmMode:2 -> scopeArmMode;
    uint8_t _z:8;
    uint16_t _scopeADCThreshold:16 -> scopeADCThreshold;
  }
  uint32_t _ScopeTriggerParms_1 {
    uint16_t _scopeTrigHoldoff:13 -> scopeTrigHoldoff;
    uint16_t _scopeTrigOffset:13 -> scopeTrigOffset;
  }
  uint32_t _ScopeTriggerParms_2 {
    uint16_t _scopeTraceLength:13 -> scopeTraceLength;
    uint16_t _scopeADCsameplesToSkip:13 -> scopeADCsameplesToSkip;
  }
  uint32_t _ScopeWaveformSelects {
    uint8_t _scopeChanAwaveformSelect:5 -> scopeChanAwaveformSelect;
    uint8_t _scopeChanBwaveformSelect:5 -> scopeChanBwaveformSelect;
    uint32_t _z:22;
  }
  Asic100aConfigV1 _asics[@self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn()] -> asics;
  uint16_t _asicPixelConfigArray[ @self.numberOfRows()][ @self.numberOfColumns()] -> asicPixelConfigArray;
  
  /* Calibration row config map is one row for every two calib rows */
  uint8_t  _calibPixelConfigArray[ @self.numberOfCalibrationRows()  / 2 ][ @self.numberOfPixelsPerAsicRow()*@self.numberOfAsicsPerRow()] -> calibPixelConfigArray;

  /* Number of pixel rows in a readout unit */
  uint32_t numberOfRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.numberOfRowsPerAsic(); @}

  /* Number of readable pixel rows in a readout unit */
  uint32_t numberOfReadableRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.numberOfReadableRowsPerAsic(); @}

  /* Number of pixel columns in a readout unit */
  uint32_t numberOfColumns()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfPixelsPerAsicRow(); @}

  /* Number of calibration rows in a readout unit */
  uint32_t numberOfCalibrationRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.calibrationRowCountPerASIC(); @}

  /* Number of rows in a readout unit */
  uint32_t numberOfEnvironmentalRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.environmentalRowCountPerASIC(); @}

  /* Number of columns in a readout unit */
  uint32_t numberOfAsics()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];

  /* Constructor which takes values necessary for size calculations */
  @init(numberOfAsicsPerRow -> _numberOfAsicsPerRow, numberOfAsicsPerColumn -> _numberOfAsicsPerColumn, 
      numberOfRowsPerAsic -> _numberOfRowsPerAsic, numberOfPixelsPerAsicRow -> _numberOfPixelsPerAsicRow,
      calibrationRowCountPerASIC -> _calibrationRowCountPerASIC)  [[inline]];

}

//------------------ Config100aV2 ------------------
@type Config100aV2
  [[type_id(Id_Epix100aConfig, 2)]]
  [[config_type]]
  [[pack(4)]]
{
  uint32_t _version          -> version;
  uint32_t _usePgpEvr        -> usePgpEvr;
  uint32_t _evrRunCode       -> evrRunCode;
  uint32_t _evrDaqCode       -> evrDaqCode;
  uint32_t _evrRunTrigDelay  -> evrRunTrigDelay;
  uint32_t _epixRunTrigDelay -> epixRunTrigDelay;
  uint32_t _dacSetting       -> dacSetting;
  uint32_t _asicPins {
    uint8_t _asicGR:1    -> asicGR;
    uint8_t _asicAcq:1   -> asicAcq;
    uint8_t _asicR0:1    -> asicR0;
    uint8_t _asicPpmat:1 -> asicPpmat;
    uint8_t _asicPpbe:1  -> asicPpbe;
    uint8_t _asicRoClk:1 -> asicRoClk;
    uint32_t _z:26;
  }
  uint32_t _asicControls {
    uint8_t _asicGRControl:1     -> asicGRControl;
    uint8_t _asicAcqControl:1    -> asicAcqControl;
    uint8_t _asicR0Control:1     -> asicR0Control;
    uint8_t _asicPpmatControl:1  -> asicPpmatControl;
    uint8_t _asicPpbeControl:1   -> asicPpbeControl;
    uint8_t _asicR0ClkControl:1  -> asicR0ClkControl;
    uint8_t _prepulseR0En:1      -> prepulseR0En;
    uint32_t _adcStreamMode:1    -> adcStreamMode;
    uint8_t _testPatternEnable:1 -> testPatternEnable;
    uint8_t _SyncMode:2          -> SyncMode;
    uint8_t _R0Mode:1            -> R0Mode;
    uint8_t _z1:20;
  }
  uint32_t _acqToAsicR0Delay -> acqToAsicR0Delay;
  uint32_t _asicR0ToAsicAcq -> asicR0ToAsicAcq;
  uint32_t _asicAcqWidth -> asicAcqWidth;
  uint32_t _asicAcqLToPPmatL -> asicAcqLToPPmatL;
  uint32_t _asicPPmatToReadout -> asicPPmatToReadout;
  uint32_t _asicRoClkHalfT -> asicRoClkHalfT;
  uint32_t _adcReadsPerPixel -> adcReadsPerPixel;
  uint32_t _adcClkHalfT -> adcClkHalfT;
  uint32_t _asicR0Width -> asicR0Width;
  uint32_t _adcPipelineDelay -> adcPipelineDelay;
  uint32_t _adcPipelineDelay0 -> adcPipelineDelay0;
  uint32_t _adcPipelineDelay1 -> adcPipelineDelay1;
  uint32_t _adcPipelineDelay2 -> adcPipelineDelay2;
  uint32_t _adcPipelineDelay3 -> adcPipelineDelay3;
  uint32_t _Sync {  // new
    uint16_t _SyncWidth:16 -> SyncWidth;
    uint16_t _SyncDelay:16 -> SyncDelay;
  }  // new
  uint32_t _prepulseR0Width -> prepulseR0Width;
  uint32_t _prepulseR0Delay -> prepulseR0Delay;
  uint32_t _digitalCardId0 -> digitalCardId0;
  uint32_t _digitalCardId1 -> digitalCardId1;
  uint32_t _analogCardId0 -> analogCardId0;
  uint32_t _analogCardId1 -> analogCardId1;
  uint32_t _carrierId0 -> carrierId0;
  uint32_t _carrierId1 -> carrierId1;
  uint32_t _numberOfAsicsPerRow -> numberOfAsicsPerRow;
  uint32_t _numberOfAsicsPerColumn -> numberOfAsicsPerColumn;
  uint32_t _numberOfRowsPerAsic -> numberOfRowsPerAsic;
  uint32_t _numberOfReadableRowsPerAsic -> numberOfReadableRowsPerAsic;
  // for epix100a  352
  uint32_t _numberOfPixelsPerAsicRow -> numberOfPixelsPerAsicRow;
  // for epix100a 96*4 = 384
  uint32_t _calibrationRowCountPerASIC -> calibrationRowCountPerASIC;
  uint32_t _environmentalRowCountPerASIC -> environmentalRowCountPerASIC;
  uint32_t _baseClockFrequency -> baseClockFrequency;
  uint32_t _asicMask -> asicMask;
  uint32_t _enableAutomaticRunTrigger -> enableAutomaticRunTrigger;
  uint32_t _numberOf125MhzTicksPerRunTrigger -> numberOf125MhzTicksPerRunTrigger;
  uint32_t _Scope {
    uint8_t _scopeEnable:1 -> scopeEnable;
    uint8_t _scopeTrigEdge:1 -> scopeTrigEdge;
    uint8_t _scopeTrigChan:4 -> scopeTrigChan;
    uint8_t _scopeArmMode:2 -> scopeArmMode;
    uint8_t _z:8;
    uint16_t _scopeADCThreshold:16 -> scopeADCThreshold;
  }
  uint32_t _ScopeTriggerParms_1 {
    uint16_t _scopeTrigHoldoff:13 -> scopeTrigHoldoff;
    uint16_t _scopeTrigOffset:13 -> scopeTrigOffset;
  }
  uint32_t _ScopeTriggerParms_2 {
    uint16_t _scopeTraceLength:13 -> scopeTraceLength;
    uint16_t _scopeADCsameplesToSkip:13 -> scopeADCsameplesToSkip;
  }
  uint32_t _ScopeWaveformSelects {
    uint8_t _scopeChanAwaveformSelect:5 -> scopeChanAwaveformSelect;
    uint8_t _scopeChanBwaveformSelect:5 -> scopeChanBwaveformSelect;
    uint32_t _z:22;
  }
  Asic100aConfigV1 _asics[@self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn()] -> asics;
  uint16_t _asicPixelConfigArray[ @self.numberOfRows()][ @self.numberOfColumns()] -> asicPixelConfigArray;
  
  /* Calibration row config map is one row for every two calib rows */
  uint8_t  _calibPixelConfigArray[ @self.numberOfCalibrationRows()  / 2 ][ @self.numberOfPixelsPerAsicRow()*@self.numberOfAsicsPerRow()] -> calibPixelConfigArray;

  /* Number of pixel rows in a readout unit */
  uint32_t numberOfRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.numberOfRowsPerAsic(); @}

  /* Number of readable pixel rows in a readout unit */
  uint32_t numberOfReadableRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.numberOfReadableRowsPerAsic(); @}

  /* Number of pixel columns in a readout unit */
  uint32_t numberOfColumns()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfPixelsPerAsicRow(); @}

  /* Number of calibration rows in a readout unit */
  uint32_t numberOfCalibrationRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.calibrationRowCountPerASIC(); @}

  /* Number of rows in a readout unit */
  uint32_t numberOfEnvironmentalRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.environmentalRowCountPerASIC(); @}

  /* Number of columns in a readout unit */
  uint32_t numberOfAsics()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];

  /* Constructor which takes values necessary for size calculations */
  @init(numberOfAsicsPerRow -> _numberOfAsicsPerRow, numberOfAsicsPerColumn -> _numberOfAsicsPerColumn, 
      numberOfRowsPerAsic -> _numberOfRowsPerAsic, numberOfPixelsPerAsicRow -> _numberOfPixelsPerAsicRow,
      calibrationRowCountPerASIC -> _calibrationRowCountPerASIC)  [[inline]];

}

//------------------ AsicSConfigV1 ------------------
@type AsicSConfigV1
  [[pack(4)]]
  [[devel]]
{
  uint32_t _reg1 {
    uint8_t _z1:7;
    uint8_t _pulserSync:1 -> pulserSync;
    uint32_t _z2:24;
  }
  uint32_t _reg2 {
    uint8_t _dummyTest:1 -> dummyTest;
    uint8_t _dummyMask:1 -> dummyMask;
    uint32_t _z:30;
  }
  uint32_t _reg3 {
    uint16_t _testPulserLevel:10 -> testPulserLevel;
    uint8_t _pulserCounterDirection:1     -> pulserCounterDirection;
    uint8_t _automaticTestModeEnable:1    -> automaticTestModeEnable;
    uint8_t _testMode:1     -> testMode;
    uint8_t _testModeWithDarkFrame:1  -> testModeWithDarkFrame;
    uint8_t _highResolutionModeTest:1   -> highResolutionModeTest;
    uint8_t _pulserReset:1  -> pulserReset;
    uint16_t _z:16;
  }
  uint32_t _reg4 {
    uint8_t _digitalMonitorMux1:4 -> digitalMonitorMux1;
    uint8_t _digitalMonitorMux2:4 -> digitalMonitorMux2;
    uint32_t _z:24;
  }
  uint32_t _reg5 {
    uint8_t _testPulserCurrent:3 -> testPulserCurrent;
    uint8_t _pulserVsPixelOnDelay:3 -> pulserVsPixelOnDelay;
    uint32_t _z:26;
  }
  uint32_t _reg6 {
    uint8_t _digitalMonitor1Enable:1 -> digitalMonitor1Enable;
    uint8_t _digitalMonitor2Enable:1 -> digitalMonitor2Enable;
    uint8_t _inputLeakageCompensation:2 -> inputLeakageCompensation;
    uint8_t _inputLeakageCompensationEnable:1 -> inputLeakageCompensationEnable;
    uint32_t _z:27;
  }
  uint32_t _reg7 {
    uint8_t _VRefBaseLineDac:6 -> VRefBaselineDac;
    uint8_t _extraRowsLowReferenceValue:2 -> extraRowsLowReferenceValue;
    uint32_t _z:24;
  }
  uint32_t _reg8 {
    uint8_t _testPointSystemTemperatureCompensationEnable:1 -> testPointSystemTemperatureCompensationEnable;
    uint8_t _testPointSytemInputSelect:4 -> testPointSytemInputSelect;
    uint8_t _programmableReadoutDelay:3 -> programmableReadoutDelay;
    uint32_t _z:24;
  }
  uint32_t _reg9 {
    uint8_t _testPointSystemOutputDynamicRange:4 -> testPointSystemOutputDynamicRange;
    uint8_t _outputDriverOutputDynamicRange:4 -> outputDriverOutputDynamicRange;
    uint32_t _z:24;
  }
  uint32_t _reg10 {
    uint8_t _balconyEnable:1 -> balconyEnable;
    uint8_t _balconyDriverCurrent:3 -> balconyDriverCurrent;
    uint8_t _fastPowerPulsingSpeed:3 -> fastPowerPulsingSpeed;
    uint8_t _fastPowerPulsingEnable:1 -> fastPowerPulsingEnable;
    uint32_t _z:24;
  }
  uint32_t _reg11 {
    uint8_t _preamplifierCurrent:3 -> preamplifierCurrent;
    uint8_t _pixelOutputBufferCurrent:3 -> pixelOutputBufferCurrent;
    uint8_t _pixelBufferAndPreamplifierDrivingCapabilities:2 -> pixelBufferAndPreamplifierDrivingCapabilities;
    uint32_t _z2:24;
  }
  uint32_t _reg12 {
    uint8_t _outputDriverTemperatureCompensationEnable:1 -> outputDriverTemperatureCompensationEnable;
    uint8_t _pixelFilterLevel:6 -> pixelFilterLevel;
    uint32_t _z:25;
  }
  uint32_t _reg13 {
    uint8_t _bandGapReferenceTemperatureCompensationBits:2 -> bandGapReferenceTemperatureCompensationBits;
    uint8_t _outputDriverDrivingCapabilitiesAndStability:3 -> outputDriverDrivingCapabilitiesAndStability;
    uint8_t _outputDriverDacReferenceBias:3 -> outputDriverDacReferenceBias;
    uint32_t _z:24;
  }
  uint32_t _reg14 {
    uint8_t _testPointSystemTemperatureCompensationGain:2 -> testPointSystemTemperatureCompensationGain;
    uint8_t _testPointSystemInputCommonMode:6 -> testPointSystemInputCommonMode;
    uint32_t _z:24;
  }
  uint32_t _reg15 {
    uint8_t _outputDriverTemperatureCompensationGain:2 -> outputDriverTemperatureCompensationGain0;
    uint8_t _outputDriverInputCommonMode:6 -> outputDriverInputCommonMode0;
    uint32_t _z:24;
  }
  uint32_t _reg16 {
    uint8_t _testBackEnd:1 -> testBackEnd;
    uint8_t _interleavedReadOutEnable:1 -> interleavedReadOutEnable;
    uint8_t EXEC_DelayEnable:1 -> EXEC_DelayEnable;
    uint8_t _CCK_RegDelayEnable:1 -> CCK_RegDelayEnable;
    uint8_t _syncPinEnable:1 -> syncPinEnable;
    uint8_t _LVDS_ImpedenceMatchingEnable:1 -> LVDS_ImpedenceMatchingEnable;
    uint32_t _z:26;
  }
  uint32_t _reg17 {
    uint16_t _RowStartAddr:9 -> RowStartAddr;
    uint32_t _z:23;
  }
  uint32_t _reg18 {
    uint16_t _RowStopAddr:9 -> RowStopAddr;
    uint32_t _z:23;
  }
  uint32_t _reg19 {
    uint8_t _ColumnStartAddr:7 -> ColumnStartAddr;
    uint32_t _z:25;
  }
  uint32_t _reg20 {
    uint8_t _ColumnStopAddr:7 -> ColumnStopAddr;
    uint32_t _z:25;
  }
  uint32_t _reg21 {
    uint16_t _chipID:16 -> chipID;
    uint16_t _z:16;
  }


  /* Constructor with value for each attribute */
  @init()  [[auto]];

}

//------------------ ConfigSV1 ------------------
@type ConfigSV1
  [[type_id(Id_EpixSConfig, 1)]]
  [[config_type]]
  [[devel]]
  [[pack(4)]]
{
  uint32_t _version -> version;
  uint32_t _runTrigDelay -> runTrigDelay;
  uint32_t _daqTrigDelay -> daqTrigDelay;
  uint32_t _dacSetting -> dacSetting;
  uint32_t _asicPins {
    uint8_t _asicGR:1 -> asicGR;
    uint8_t _asicAcq:1 -> asicAcq;
    uint8_t _asicR0:1 -> asicR0;
    uint8_t _asicPpmat:1 -> asicPpmat;
    uint8_t _asicPpbe:1 -> asicPpbe;
    uint8_t _asicRoClk:1 -> asicRoClk;
    uint32_t _z:26;
  }
  uint32_t _asicControls {
    uint8_t _asicGRControl:1 -> asicGRControl;
    uint8_t _asicAcqControl:1 -> asicAcqControl;
    uint8_t _asicR0Control:1 -> asicR0Control;
    uint8_t _asicPpmatControl:1 -> asicPpmatControl;
    uint8_t _asicPpbeControl:1 -> asicPpbeControl;
    uint8_t _asicR0ClkControl:1 -> asicR0ClkControl;
    uint8_t _prepulseR0En:1 -> prepulseR0En;
    uint32_t _adcStreamMode:1 -> adcStreamMode;
    uint8_t _testPatternEnable:1 -> testPatternEnable;
    uint8_t _SyncMode:2 -> SyncMode;
    uint8_t _R0Mode:1 -> R0Mode;
    uint8_t _z1:20;
  }
  uint32_t _acqToAsicR0Delay -> acqToAsicR0Delay;
  uint32_t _asicR0ToAsicAcq -> asicR0ToAsicAcq;
  uint32_t _asicAcqWidth -> asicAcqWidth;
  uint32_t _asicAcqLToPPmatL -> asicAcqLToPPmatL;
  uint32_t _asicPPmatToReadout -> asicPPmatToReadout;
  uint32_t _asicRoClkHalfT -> asicRoClkHalfT;
  uint32_t _adcReadsPerPixel -> adcReadsPerPixel;
  uint32_t _adcClkHalfT -> adcClkHalfT;
  uint32_t _asicR0Width -> asicR0Width;
  uint32_t _adcPipelineDelay -> adcPipelineDelay;
  uint32_t _Sync {  // new
    uint16_t _SyncWidth:16 -> SyncWidth;
    uint16_t _SyncDelay:16 -> SyncDelay;
  }  // new
  uint32_t _prepulseR0Width -> prepulseR0Width;
  uint32_t _prepulseR0Delay -> prepulseR0Delay;
  uint32_t _digitalCardId0 -> digitalCardId0;
  uint32_t _digitalCardId1 -> digitalCardId1;
  uint32_t _analogCardId0 -> analogCardId0;
  uint32_t _analogCardId1 -> analogCardId1;
  uint32_t _carrierId0 -> carrierId0;
  uint32_t _carrierId1 -> carrierId1;
  uint32_t _numberOfAsicsPerRow -> numberOfAsicsPerRow;
  uint32_t _numberOfAsicsPerColumn -> numberOfAsicsPerColumn;
  uint32_t _numberOfRowsPerAsic -> numberOfRowsPerAsic;
  uint32_t _numberOfReadableRowsPerAsic -> numberOfReadableRowsPerAsic;
  // for epixS  352
  uint32_t _numberOfPixelsPerAsicRow -> numberOfPixelsPerAsicRow;
  // for epixS 96*4 = 384
  uint32_t _calibrationRowCountPerASIC -> calibrationRowCountPerASIC;
  uint32_t _environmentalRowCountPerASIC -> environmentalRowCountPerASIC;
  uint32_t _baseClockFrequency -> baseClockFrequency;
  uint32_t _asicMask -> asicMask;
  uint32_t _Scope {
    uint8_t _scopeEnable:1 -> scopeEnable;
    uint8_t _scopeTrigEdge:1 -> scopeTrigEdge;
    uint8_t _scopeTrigChan:4 -> scopeTrigChan;
    uint8_t _scopeArmMode:2 -> scopeArmMode;
    uint8_t _z:8;
    uint16_t _scopeADCThreshold:16 -> scopeADCThreshold;
  }
  uint32_t _ScopeTriggerParms_1 {
    uint16_t _scopeTrigHoldoff:13 -> scopeTrigHoldoff;
    uint16_t _scopeTrigOffset:13 -> scopeTrigOffset;
  }
  uint32_t _ScopeTriggerParms_2 {
    uint16_t _scopeTraceLength:13 -> scopeTraceLength;
    uint16_t _scopeADCsameplesToSkip:13 -> scopeADCsameplesToSkip;
  }
  uint32_t _ScopeWaveformSelects {
    uint8_t _scopeChanAwaveformSelect:5 -> scopeChanAwaveformSelect;
    uint8_t _scopeChanBwaveformSelect:5 -> scopeChanBwaveformSelect;
    uint32_t _z:22;
  }
  AsicSConfigV1 _asics[@self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn()] -> asics;
  uint16_t _asicPixelConfigArray[ @self.numberOfRows()][ @self.numberOfColumns()] -> asicPixelConfigArray;
  
  /* Calibration row config map is one row for every two calib rows */
  uint8_t  _calibPixelConfigArray[ @self.numberOfCalibrationRows()  / 2 ][ @self.numberOfPixelsPerAsicRow()*@self.numberOfAsicsPerRow()] -> calibPixelConfigArray;

  /* Number of pixel rows in a readout unit */
  uint32_t numberOfRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.numberOfRowsPerAsic(); @}

  /* Number of readable pixel rows in a readout unit */
  uint32_t numberOfReadableRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.numberOfReadableRowsPerAsic(); @}

  /* Number of pixel columns in a readout unit */
  uint32_t numberOfColumns()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfPixelsPerAsicRow(); @}

  /* Number of calibration rows in a readout unit */
  uint32_t numberOfCalibrationRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.calibrationRowCountPerASIC(); @}

  /* Number of rows in a readout unit */
  uint32_t numberOfEnvironmentalRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.environmentalRowCountPerASIC(); @}

  /* Number of columns in a readout unit */
  uint32_t numberOfAsics()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];

  /* Constructor which takes values necessary for size calculations */
  @init(numberOfAsicsPerRow -> _numberOfAsicsPerRow, numberOfAsicsPerColumn -> _numberOfAsicsPerColumn, 
      numberOfRowsPerAsic -> _numberOfRowsPerAsic, numberOfPixelsPerAsicRow -> _numberOfPixelsPerAsicRow,
      calibrationRowCountPerASIC -> _calibrationRowCountPerASIC)  [[inline]];

}


//------------------ Asic10kaConfigV1 ------------------
@type Asic10kaConfigV1
  [[pack(4)]]
{
  uint32_t _reg1 {
    uint8_t _CompTH_DAC:6 -> CompTH_DAC;
    uint8_t _CompEn_lowBit:1 -> CompEn_lowBit;
    uint8_t _PulserSync:1 -> PulserSync;
    uint32_t _z2:24;
  }
  uint32_t _reg2 {
    uint8_t _pixelDummy:8 -> pixelDummy;
    uint32_t _z:24;
  }
  uint32_t _reg3 {
    uint16_t _Pulser:10 -> Pulser;
    uint8_t _Pbit:1     -> Pbit;
    uint8_t _atest:1    -> atest;
    uint8_t _test:1     -> test;
    uint8_t _Sab_test:1  -> Sab_test;
    uint8_t _Hrtest:1   -> Hrtest;
    uint8_t _PulserR:1  -> PulserR;
    uint16_t _z:16;
  }
  uint32_t _reg4 {
    uint8_t _DM1:4 -> DM1;
    uint8_t _DM2:4 -> DM2;
    uint32_t _z:24;
  }
  uint32_t _reg5 {
    uint8_t _Pulser_DAC:3 -> Pulser_DAC;
    uint8_t _Monost_Pulser:3 -> Monost_Pulser;
    uint8_t _CompEn_topTwoBits:2 -> CompEn_topTwoBits;
    uint32_t _z2:24;
  }
  uint32_t _reg6 {
    uint8_t _DM1en:1 -> DM1en;
    uint8_t _DM2en:1 -> DM2en;
    uint8_t _emph_bd:3 -> emph_bd;
    uint8_t _emph_bc:3 -> emph_bc;
    uint32_t _z1:24;
  }
  uint32_t _reg7 {
    uint8_t _VREF_DAC:6 -> VREF_DAC;
    uint8_t _VrefLow:2 -> VrefLow;
    uint32_t _z:24;
  }
  uint32_t _reg8 {
    uint8_t _TPS_tcomp:1 -> TPS_tcomp;
    uint8_t _TPS_MUX:4 -> TPS_MUX;
    uint8_t _RO_Monost:3 -> RO_Monost;
    uint32_t _z:24;
  }
  uint32_t _reg9 {
    uint8_t _TPS_GR:4 -> TPS_GR;
    uint8_t _S2D0_GR:4 -> S2D0_GR;
    uint32_t _z:24;
  }
  uint32_t _reg10 {
    uint8_t _PP_OCB_S2D:1 -> PP_OCB_S2D;
    uint8_t _OCB:3 -> OCB;
    uint8_t _Monost:3 -> Monost;
    uint8_t _fastPP_enable:1 -> fastPP_enable;
    uint32_t _z:24;
  }
  uint32_t _reg11 {
    uint8_t _Preamp:3 -> Preamp;
    uint8_t _Pixel_CB:3 -> PixelCB;
    uint8_t _Vld1_b:2 -> Vld1_b;
    uint32_t _z2:24;
  }
  uint32_t _reg12 {
    uint8_t _S2D_tcomp:1 -> S2D_tcomp;
    uint8_t _Filter_DAC:6 -> Filter_DAC;
    uint8_t _testLVDTransmitter:1 -> testLVDTransmitter;
    uint32_t _z:24;
  }
  uint32_t _reg13 {
    uint8_t _tc:2 -> tc;
    uint8_t _S2D:3 -> S2D;
    uint8_t _S2D_DAC_Bias:3 -> S2D_DAC_Bias;
    uint32_t _z:24;
  }
  uint32_t _reg14 {
    uint8_t _TPS_tcDAC:2 -> TPS_tcDAC;
    uint8_t _TPS_DAC:6 -> TPS_DAC;
    uint32_t _z:24;
  }
  uint32_t _reg15 {
    uint8_t _S2D0_tcDAC:2 -> S2D0_tcDAC;
    uint8_t _S2D0_DAC:6 -> S2D0_DAC;
    uint32_t _z:24;
  }
  uint32_t _reg16 {
    uint8_t _testBE:1 -> testBE;
    uint8_t _is_en:1 -> is_en;
    uint8_t _DelEXEC:1 -> DelEXEC;
    uint8_t _DelCCKreg:1 -> DelCCKreg;
    uint8_t _RO_rst_en:1 -> RO_rst_en;
    uint8_t _SLVDSbit:1 -> SLVDSbit;
    uint8_t _FELmode:1 -> FELmode;
    uint8_t _CompEnOn:1 -> CompEnOn;
    uint32_t _z:24;
  }
  uint32_t _reg17 {
    uint16_t _RowStart:9 -> RowStart;
    uint32_t _z:23;
  }
  uint32_t _reg18 {
    uint16_t _RowStop:9 -> RowStop;
    uint32_t _z:23;
  }
  uint32_t _reg19 {
    uint8_t _ColumnStart:7 -> ColumnStart;
    uint32_t _z:25;
  }
  uint32_t _reg20 {
    uint8_t _ColumnStop:7 -> ColumnStop;
    uint32_t _z:25;
  }
  uint32_t _reg21 {
    uint16_t _chipID:16 -> chipID;
    uint16_t _z:16;
  }
  uint32_t _reg22 {
    uint8_t _S2D1_GR:4 -> S2D1_GR;
    uint8_t _S2D2_GR:4 -> S2D2_GR;
    uint32_t _z:24;
  }
  uint32_t _reg23 {
    uint8_t _S2D3_GR:4 -> S2D3_GR;
    uint8_t _trbit:1 -> trbit;
    uint32_t _z:27;
  }
  uint32_t _reg24 {
    uint8_t _S2D1_tcDAC:2 -> S2D1_tcDAC;
    uint8_t _S2D1_DAC:6 -> S2D1_DAC;
    uint32_t _z:24;
  }
  uint32_t _reg25 {
    uint8_t _S2D2_tcDAC:2 -> S2D2_tcDAC;
    uint8_t _S2D2_DAC:6 -> S2D2_DAC;
    uint32_t _z:24;
  }
  uint32_t _reg26 {
    uint8_t _S2D3_tcDAC:2 -> S2D3_tcDAC;
    uint8_t _S2D3_DAC:6 -> S2D3_DAC;
    uint32_t _z:24;
  }


  /* Constructor with value for each attribute */
  @init()  [[auto]];

}

//------------------ Config10kaV1 ------------------
@type Config10kaV1
  [[type_id(Id_Epix10kaConfig, 1)]]
  [[config_type]]
  [[pack(4)]]
{
  uint32_t _version          -> version;
  uint32_t _usePgpEvr        -> usePgpEvr;
  uint32_t _evrRunCode       -> evrRunCode;
  uint32_t _evrDaqCode       -> evrDaqCode;
  uint32_t _evrRunTrigDelay  -> evrRunTrigDelay;
  uint32_t _epixRunTrigDelay -> epixRunTrigDelay;
  uint32_t _dacSetting       -> dacSetting;
  uint32_t _asicPins {
    uint8_t _asicGR:1    -> asicGR;
    uint8_t _asicAcq:1   -> asicAcq;
    uint8_t _asicR0:1    -> asicR0;
    uint8_t _asicPpmat:1 -> asicPpmat;
    uint8_t _asicPpbe:1  -> asicPpbe;
    uint8_t _asicRoClk:1 -> asicRoClk;
    uint32_t _z:26;
  }
  uint32_t _asicControls {
    uint8_t _asicGRControl:1     -> asicGRControl;
    uint8_t _asicAcqControl:1    -> asicAcqControl;
    uint8_t _asicR0Control:1     -> asicR0Control;
    uint8_t _asicPpmatControl:1  -> asicPpmatControl;
    uint8_t _asicPpbeControl:1   -> asicPpbeControl;
    uint8_t _asicR0ClkControl:1  -> asicR0ClkControl;
    uint8_t _prepulseR0En:1      -> prepulseR0En;
    uint32_t _adcStreamMode:1    -> adcStreamMode;
    uint8_t _testPatternEnable:1 -> testPatternEnable;
    uint8_t _SyncMode:2          -> SyncMode;
    uint8_t _R0Mode:1            -> R0Mode;
    uint8_t _z1:20;
  }
  uint32_t _acqToAsicR0Delay -> acqToAsicR0Delay;
  uint32_t _asicR0ToAsicAcq -> asicR0ToAsicAcq;
  uint32_t _asicAcqWidth -> asicAcqWidth;
  uint32_t _asicAcqLToPPmatL -> asicAcqLToPPmatL;
  uint32_t _asicPPmatToReadout -> asicPPmatToReadout;
  uint32_t _asicRoClkHalfT -> asicRoClkHalfT;
  uint32_t _adcReadsPerPixel -> adcReadsPerPixel;
  uint32_t _adcClkHalfT -> adcClkHalfT;
  uint32_t _asicR0Width -> asicR0Width;
  uint32_t _adcPipelineDelay -> adcPipelineDelay;
  uint32_t _adcPipelineDelay0 -> adcPipelineDelay0;
  uint32_t _adcPipelineDelay1 -> adcPipelineDelay1;
  uint32_t _adcPipelineDelay2 -> adcPipelineDelay2;
  uint32_t _adcPipelineDelay3 -> adcPipelineDelay3;
  uint32_t _Sync {  // new
    uint16_t _SyncWidth:16 -> SyncWidth;
    uint16_t _SyncDelay:16 -> SyncDelay;
  }  // new
  uint32_t _prepulseR0Width -> prepulseR0Width;
  uint32_t _prepulseR0Delay -> prepulseR0Delay;
  uint32_t _digitalCardId0 -> digitalCardId0;
  uint32_t _digitalCardId1 -> digitalCardId1;
  uint32_t _analogCardId0 -> analogCardId0;
  uint32_t _analogCardId1 -> analogCardId1;
  uint32_t _carrierId0 -> carrierId0;
  uint32_t _carrierId1 -> carrierId1;
  uint32_t _numberOfAsicsPerRow -> numberOfAsicsPerRow;
  uint32_t _numberOfAsicsPerColumn -> numberOfAsicsPerColumn;
  uint32_t _numberOfRowsPerAsic -> numberOfRowsPerAsic;
  uint32_t _numberOfReadableRowsPerAsic -> numberOfReadableRowsPerAsic;
  // for epix10ka  176
  uint32_t _numberOfPixelsPerAsicRow -> numberOfPixelsPerAsicRow;
  // for epix10ka 96*4 = 384
  uint32_t _calibrationRowCountPerASIC -> calibrationRowCountPerASIC;
  uint32_t _environmentalRowCountPerASIC -> environmentalRowCountPerASIC;
  uint32_t _baseClockFrequency -> baseClockFrequency;
  uint32_t _asicMask -> asicMask;
  uint32_t _enableAutomaticRunTrigger -> enableAutomaticRunTrigger;
  uint32_t _numberOf125MhzTicksPerRunTrigger -> numberOf125MhzTicksPerRunTrigger;
  uint32_t _Scope {
    uint8_t _scopeEnable:1 -> scopeEnable;
    uint8_t _scopeTrigEdge:1 -> scopeTrigEdge;
    uint8_t _scopeTrigChan:4 -> scopeTrigChan;
    uint8_t _scopeArmMode:2 -> scopeArmMode;
    uint8_t _z:8;
    uint16_t _scopeADCThreshold:16 -> scopeADCThreshold;
  }
  uint32_t _ScopeTriggerParms_1 {
    uint16_t _scopeTrigHoldoff:13 -> scopeTrigHoldoff;
    uint16_t _scopeTrigOffset:13 -> scopeTrigOffset;
  }
  uint32_t _ScopeTriggerParms_2 {
    uint16_t _scopeTraceLength:13 -> scopeTraceLength;
    uint16_t _scopeADCsameplesToSkip:13 -> scopeADCsameplesToSkip;
  }
  uint32_t _ScopeWaveformSelects {
    uint8_t _scopeChanAwaveformSelect:5 -> scopeChanAwaveformSelect;
    uint8_t _scopeChanBwaveformSelect:5 -> scopeChanBwaveformSelect;
    uint32_t _z:22;
  }
  Asic10kaConfigV1 _asics[@self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn()] -> asics;
  uint16_t _asicPixelConfigArray[ @self.numberOfRows()][ @self.numberOfColumns()] -> asicPixelConfigArray;

  /* Calibration row config map is one row for every two calib rows */
  uint8_t  _calibPixelConfigArray[ @self.numberOfCalibrationRows()  / 2 ][ @self.numberOfPixelsPerAsicRow()*@self.numberOfAsicsPerRow()] -> calibPixelConfigArray;

  /* Number of pixel rows in a readout unit */
  uint32_t numberOfRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.numberOfRowsPerAsic(); @}

  /* Number of readable pixel rows in a readout unit */
  uint32_t numberOfReadableRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.numberOfReadableRowsPerAsic(); @}

  /* Number of pixel columns in a readout unit */
  uint32_t numberOfColumns()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfPixelsPerAsicRow(); @}

  /* Number of calibration rows in a readout unit */
  uint32_t numberOfCalibrationRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.calibrationRowCountPerASIC(); @}

  /* Number of rows in a readout unit */
  uint32_t numberOfEnvironmentalRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.environmentalRowCountPerASIC(); @}

  /* Number of columns in a readout unit */
  uint32_t numberOfAsics()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];

  /* Constructor which takes values necessary for size calculations */
  @init(numberOfAsicsPerRow -> _numberOfAsicsPerRow, numberOfAsicsPerColumn -> _numberOfAsicsPerColumn,
      numberOfRowsPerAsic -> _numberOfRowsPerAsic, numberOfPixelsPerAsicRow -> _numberOfPixelsPerAsicRow,
      calibrationRowCountPerASIC -> _calibrationRowCountPerASIC)  [[inline]];

}

//------------------ Config10kaV2 ------------------
@type Config10kaV2
  [[type_id(Id_Epix10kaConfig, 2)]]
  [[config_type]]
  [[pack(4)]]
{
  @const int32_t FirmwareHashMax = 64;
  @const int32_t FirmwareDescMax = 256;

  uint32_t _version          -> version;
  uint32_t _usePgpEvr        -> usePgpEvr;
  uint32_t _evrRunCode       -> evrRunCode;
  uint32_t _evrDaqCode       -> evrDaqCode;
  uint32_t _evrRunTrigDelay  -> evrRunTrigDelay;
  uint32_t _epixRunTrigDelay -> epixRunTrigDelay;
  uint32_t _epixDaqTrigDelay -> epixDaqTrigDelay;
  uint32_t _dacSetting       -> dacSetting;
  uint32_t _asicPins {
    uint8_t _asicGR:1    -> asicGR;
    uint8_t _asicAcq:1   -> asicAcq;
    uint8_t _asicR0:1    -> asicR0;
    uint8_t _asicPpmat:1 -> asicPpmat;
    uint8_t _asicPpbe:1  -> asicPpbe;
    uint8_t _asicRoClk:1 -> asicRoClk;
    uint32_t _z:26;
  }
  uint32_t _asicControls {
    uint8_t _asicGRControl:1     -> asicGRControl;
    uint8_t _asicAcqControl:1    -> asicAcqControl;
    uint8_t _asicR0Control:1     -> asicR0Control;
    uint8_t _asicPpmatControl:1  -> asicPpmatControl;
    uint8_t _asicPpbeControl:1   -> asicPpbeControl;
    uint8_t _asicR0ClkControl:1  -> asicR0ClkControl;
    uint8_t _prepulseR0En:1      -> prepulseR0En;
    uint32_t _adcStreamMode:1    -> adcStreamMode;
    uint8_t _testPatternEnable:1 -> testPatternEnable;
    uint8_t _z1:23;
  }
  uint32_t _acqToAsicR0Delay -> acqToAsicR0Delay;
  uint32_t _asicR0ToAsicAcq -> asicR0ToAsicAcq;
  uint32_t _asicAcqWidth -> asicAcqWidth;
  uint32_t _asicAcqLToPPmatL -> asicAcqLToPPmatL;
  uint32_t _asicPPmatToReadout -> asicPPmatToReadout;
  uint32_t _asicRoClkHalfT -> asicRoClkHalfT;
  uint32_t _adcClkHalfT -> adcClkHalfT;
  uint32_t _asicR0Width -> asicR0Width;
  uint32_t _adcPipelineDelay -> adcPipelineDelay;
  uint32_t _adcPipelineDelay0 -> adcPipelineDelay0;
  uint32_t _adcPipelineDelay1 -> adcPipelineDelay1;
  uint32_t _adcPipelineDelay2 -> adcPipelineDelay2;
  uint32_t _adcPipelineDelay3 -> adcPipelineDelay3;
  uint32_t _Sync {  // new
    uint16_t _SyncWidth:16 -> SyncWidth;
    uint16_t _SyncDelay:16 -> SyncDelay;
  }  // new
  uint32_t _prepulseR0Width -> prepulseR0Width;
  uint32_t _prepulseR0Delay -> prepulseR0Delay;
  uint32_t _digitalCardId0 -> digitalCardId0;
  uint32_t _digitalCardId1 -> digitalCardId1;
  uint32_t _analogCardId0 -> analogCardId0;
  uint32_t _analogCardId1 -> analogCardId1;
  uint32_t _carrierId0 -> carrierId0;
  uint32_t _carrierId1 -> carrierId1;
  uint32_t _numberOfAsicsPerRow -> numberOfAsicsPerRow;
  uint32_t _numberOfAsicsPerColumn -> numberOfAsicsPerColumn;
  uint32_t _numberOfRowsPerAsic -> numberOfRowsPerAsic;
  uint32_t _numberOfReadableRowsPerAsic -> numberOfReadableRowsPerAsic;
  // for epix10ka  176
  uint32_t _numberOfPixelsPerAsicRow -> numberOfPixelsPerAsicRow;
  // for epix10ka 96*4 = 384
  uint32_t _calibrationRowCountPerASIC -> calibrationRowCountPerASIC;
  uint32_t _environmentalRowCountPerASIC -> environmentalRowCountPerASIC;
  uint32_t _baseClockFrequency -> baseClockFrequency;
  uint32_t _asicMask -> asicMask;
  uint32_t _enableAutomaticRunTrigger -> enableAutomaticRunTrigger;
  uint32_t _numberOf125MhzTicksPerRunTrigger -> numberOf125MhzTicksPerRunTrigger;
  uint32_t _ghostCorrEn -> ghostCorrEn;
  uint32_t _oversampleEn -> oversampleEn;
  uint32_t _oversampleSize -> oversampleSize;
  uint32_t _Scope {
    uint8_t _scopeEnable:1 -> scopeEnable;
    uint8_t _scopeTrigEdge:1 -> scopeTrigEdge;
    uint8_t _scopeTrigChan:4 -> scopeTrigChan;
    uint8_t _scopeArmMode:2 -> scopeArmMode;
    uint8_t _z:8;
    uint16_t _scopeADCThreshold:16 -> scopeADCThreshold;
  }
  uint32_t _ScopeTriggerParms_1 {
    uint16_t _scopeTrigHoldoff:13 -> scopeTrigHoldoff;
    uint16_t _scopeTrigOffset:13 -> scopeTrigOffset;
  }
  uint32_t _ScopeTriggerParms_2 {
    uint16_t _scopeTraceLength:13 -> scopeTraceLength;
    uint16_t _scopeADCsameplesToSkip:13 -> scopeADCsameplesToSkip;
  }
  uint32_t _ScopeWaveformSelects {
    uint8_t _scopeChanAwaveformSelect:5 -> scopeChanAwaveformSelect;
    uint8_t _scopeChanBwaveformSelect:5 -> scopeChanBwaveformSelect;
    uint32_t _z:22;
  }
  char _firmwareHash[FirmwareHashMax] -> firmwareHash;
  char _firmwareDesc[FirmwareDescMax] -> firmwareDesc;
  Asic10kaConfigV1 _asics[@self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn()] -> asics;
  uint16_t _asicPixelConfigArray[ @self.numberOfRows()][ @self.numberOfColumns()] -> asicPixelConfigArray;

  /* Calibration row config map is one row for every two calib rows */
  uint8_t  _calibPixelConfigArray[ @self.numberOfCalibrationRows()  / 2 ][ @self.numberOfPixelsPerAsicRow()*@self.numberOfAsicsPerRow()] -> calibPixelConfigArray;

  /* Number of pixel rows in a readout unit */
  uint32_t numberOfRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.numberOfRowsPerAsic(); @}

  /* Number of readable pixel rows in a readout unit */
  uint32_t numberOfReadableRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.numberOfReadableRowsPerAsic(); @}

  /* Number of pixel columns in a readout unit */
  uint32_t numberOfColumns()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfPixelsPerAsicRow(); @}

  /* Number of calibration rows in a readout unit */
  uint32_t numberOfCalibrationRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.calibrationRowCountPerASIC(); @}

  /* Number of rows in a readout unit */
  uint32_t numberOfEnvironmentalRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.environmentalRowCountPerASIC(); @}

  /* Number of columns in a readout unit */
  uint32_t numberOfAsics()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];

  /* Constructor which takes values necessary for size calculations */
  @init(numberOfAsicsPerRow -> _numberOfAsicsPerRow, numberOfAsicsPerColumn -> _numberOfAsicsPerColumn,
      numberOfRowsPerAsic -> _numberOfRowsPerAsic, numberOfPixelsPerAsicRow -> _numberOfPixelsPerAsicRow,
      calibrationRowCountPerASIC -> _calibrationRowCountPerASIC)  [[inline]];

}


//----  Configuration object for offline analysis of an Epix10ka element ----//
@type Elem10kaConfigV1
  [[config_type]]
  [[pack(4)]]
{
  @const uint32_t _numberOfAsicsPerRow          = 2;
  @const uint32_t _numberOfAsicsPerColumn       = 2;
  @const uint32_t _numberOfRowsPerAsic          = 176;
  @const uint32_t _numberOfReadableRowsPerAsic  = 176;
  @const uint32_t _numberOfPixelsPerAsicRow     = 192;
  @const uint32_t _calibrationRowCountPerASIC   = 2;
  @const uint32_t _environmentalRowCountPerASIC = 1;

  //  Mimic previous Epix Config interfaces
  uint32_t numberOfAsicsPerRow() [[language("C++")]] @{ return _numberOfAsicsPerRow; @}
  uint32_t numberOfAsicsPerColumn() [[language("C++")]] @{ return _numberOfAsicsPerColumn; @}
  uint32_t numberOfRowsPerAsic() [[language("C++")]] @{ return _numberOfRowsPerAsic; @}
  uint32_t numberOfReadableRowsPerAsic() [[language("C++")]] @{ return _numberOfReadableRowsPerAsic; @}
  uint32_t numberOfPixelsPerAsicRow() [[language("C++")]] @{ return _numberOfPixelsPerAsicRow; @}
  uint32_t calibrationRowCountPerASIC() [[language("C++")]] @{ return _calibrationRowCountPerASIC; @}
  uint32_t environmentalRowCountPerASIC() [[language("C++")]] @{ return _environmentalRowCountPerASIC; @}


  uint32_t         _carrierId0                     -> carrierId0; // read-only
  uint32_t         _carrierId1                     -> carrierId1; // read-only
  uint32_t         _asicMask                       -> asicMask;
  Asic10kaConfigV1 _asics                      [4] -> asics;
  uint16_t         _asicPixelConfigArray[352][384] -> asicPixelConfigArray;
  uint8_t          _calibPixelConfigArray [2][384] -> calibPixelConfigArray;


       // Interface
  /* Number of pixel rows in a readout unit */
  uint32_t numberOfRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.numberOfRowsPerAsic(); @}

  /* Number of readable pixel rows in a readout unit */
  uint32_t numberOfReadableRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.numberOfReadableRowsPerAsic(); @}

  /* Number of pixel columns in a readout unit */
  uint32_t numberOfColumns()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfPixelsPerAsicRow(); @}

  /* Number of calibration rows in a readout unit */
  uint32_t numberOfCalibrationRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.calibrationRowCountPerASIC(); @}

  /* Number of rows in a readout unit */
  uint32_t numberOfEnvironmentalRows()  [[inline]]
  [[language("C++")]] @{ return @self.numberOfAsicsPerColumn()*@self.environmentalRowCountPerASIC(); @}

  /* Number of columns in a readout unit */
  uint32_t numberOfAsics()  [[inline]]
  [[language("C++")]] @{ return  @self.numberOfAsicsPerRow()*@self.numberOfAsicsPerColumn(); @}

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

@type PgpEvrConfig
  [[pack(4)]]
{
  uint16_t _enable   -> enable;
  uint8_t  _runCode  -> runCode;
  uint8_t  _daqCode  -> daqCode;
  uint32_t _runDelay -> runDelay;

  @init() [[auto]];
}

@type Ad9249Config
  [[pack(4)]]
{
  uint32_t _chipId -> chipId; // read-only
  uint32_t _devIndexMask       -> devIndexMask;
  uint32_t _devIndexMaskDcoFco -> devIndexMaskDcoFco;
  uint32_t ControlBits {
    uint8_t _extPwdnMode  :1 -> extPwdnMode;
    uint8_t _intPwdnMode  :2 -> intPwdnMode;
    uint8_t _chopMode     :1 -> chopMode;
    uint8_t _dutyCycleStab:1 -> dutyCycleStab;
    uint8_t _outputInvert :1 -> outputInvert;
    uint8_t _outputFormat :1 -> outputFormat;
    uint32_t z:25;
  }
  uint32_t _clockDivide        -> clockDivide;
  uint32_t _userTestMode       -> userTestMode;
  uint32_t _outputTestMode     -> outputTestMode;
  uint32_t _offsetAdjust       -> offsetAdjust;
  uint32_t _channelDelay[8]    -> channelDelay;
  uint32_t _frameDelay         -> frameDelay;

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

@type Quad10kaConfigV1
  [[pack(4)]]
{
        // Global
  uint32_t _baseClockFrequency               -> baseClockFrequency;
  uint32_t _enableAutomaticRunTrigger        -> enableAutomaticRunTrigger;
  uint32_t _numberOf125MhzTicksPerRunTrigger -> numberOf125MhzTicksPerRunTrigger;

        // AxiVersion (RO)
  uint32_t _digitalCardId0 -> digitalCardId0;
  uint32_t _digitalCardId1 -> digitalCardId1;
        // SystemRegs
  uint32_t _dcdcEn         -> dcdcEn;
  uint32_t _asicAnaEn      -> asicAnaEn;
  uint32_t _asicDigEn      -> asicDigEn;
  uint32_t _ddrVttEn       -> ddrVttEn;
  uint32_t _trigSrcSel     -> trigSrcSel;
  uint32_t _vguardDac      -> vguardDac;
        // AcqCore
  uint32_t _acqToAsicR0Delay -> acqToAsicR0Delay;
  uint32_t _asicR0Width      -> asicR0Width;
  uint32_t _asicR0ToAsicAcq  -> asicR0ToAsicAcq;
  uint32_t _asicAcqWidth     -> asicAcqWidth;
  uint32_t _asicAcqLToPPmatL -> asicAcqLToPPmatL;
  uint32_t _asicPPmatToReadout -> asicPPmatToReadout;
  uint32_t _asicRoClkHalfT     -> asicRoClkHalfT;

  uint32_t _asicForce {
    uint8_t asicAcqForce    :1    -> asicAcqForce;
    uint8_t asicR0Force     :1    -> asicR0Force;
    uint8_t asicPPmatForce  :1    -> asicPPmatForce;
    uint8_t asicSyncForce   :1    -> asicSyncForce;
    uint8_t asicRoClkForce  :1    -> asicRoClkForce;
    uint32_t _z   :27;
  }
  uint32_t _asicForceValue {
    uint8_t asicAcqValue    :1    -> asicAcqValue;
    uint8_t asicR0Value     :1    -> asicR0Value;
    uint8_t asicPPmatValue  :1    -> asicPPmatValue;
    uint8_t asicSyncValue   :1    -> asicSyncValue;
    uint8_t asicRoClkValue  :1    -> asicRoClkValue;
    uint32_t _z   :27;
  }

        // RdoutCore
  uint32_t _adcPipelineDelay -> adcPipelineDelay;
  uint32_t _testData         -> testData;

        // PseudoScopeCore
  uint32_t _Scope {
    uint8_t _scopeEnable:1 -> scopeEnable;
    uint8_t _scopeTrigEdge:1 -> scopeTrigEdge;
    uint8_t _scopeTrigChan:5 -> scopeTrigChan;
    uint8_t _scopeTrigMode:2 -> scopeTrigMode;
    uint8_t _z:7;
    uint16_t _scopeADCThreshold:16 -> scopeADCThreshold;
  }
  uint32_t _ScopeTriggerParms_1 {
    uint16_t _scopeTrigHoldoff:13 -> scopeTrigHoldoff;
    uint16_t _scopeTrigOffset:13  -> scopeTrigOffset;
  }
  uint32_t _ScopeTriggerParms_2 {
    uint16_t _scopeTraceLength:13 -> scopeTraceLength;
    uint16_t _scopeADCsamplesToSkip:13 -> scopeADCsamplesToSkip;
  }
  uint32_t _ScopeWaveformSelects {
    uint8_t _scopeChanAwaveformSelect:7 -> scopeChanAwaveformSelect;
    uint8_t _scopeChanBwaveformSelect:7 -> scopeChanBwaveformSelect;
    uint32_t _z:18;
  }
  uint32_t _scopeTrigDelay -> scopeTrigDelay;

        // Ad9249ReadoutGroup [10]
        // Ad9249ConfigGroup [10]
  Ad9249Config _adc[10]  -> adc;

        // AdcTester
  uint32_t _testChannel  -> testChannel;
  uint32_t _testDataMask -> testDataMask;
  uint32_t _testPattern  -> testPattern;
  uint32_t _testSamples  -> testSamples;
  uint32_t _testTimeout  -> testTimeout;
  uint32_t _testRequest  -> testRequest;

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

@type Quad10kaConfigV2
  [[pack(4)]]
{
  @const int32_t FirmwareHashMax = 64;
  @const int32_t FirmwareDescMax = 256;
        // Global
  uint32_t _baseClockFrequency               -> baseClockFrequency;
  uint32_t _enableAutomaticRunTrigger        -> enableAutomaticRunTrigger;
  uint32_t _numberOf125MhzTicksPerRunTrigger -> numberOf125MhzTicksPerRunTrigger;

        // AxiVersion (RO)
  uint32_t _firmwareVersion               -> firmwareVersion;
  uint32_t _digitalCardId0                -> digitalCardId0;
  uint32_t _digitalCardId1                -> digitalCardId1;
  char     _firmwareHash[FirmwareHashMax] -> firmwareHash;
  char     _firmwareDesc[FirmwareDescMax] -> firmwareDesc;
        // SystemRegs
  uint32_t _dcdcEn         -> dcdcEn;
  uint32_t _asicAnaEn      -> asicAnaEn;
  uint32_t _asicDigEn      -> asicDigEn;
  uint32_t _ddrVttEn       -> ddrVttEn;
  uint32_t _trigSrcSel     -> trigSrcSel;
  uint32_t _vguardDac      -> vguardDac;
        // AcqCore
  uint32_t _acqToAsicR0Delay -> acqToAsicR0Delay;
  uint32_t _asicR0Width      -> asicR0Width;
  uint32_t _asicR0ToAsicAcq  -> asicR0ToAsicAcq;
  uint32_t _asicAcqWidth     -> asicAcqWidth;
  uint32_t _asicAcqLToPPmatL -> asicAcqLToPPmatL;
  uint32_t _asicPPmatToReadout -> asicPPmatToReadout;
  uint32_t _asicRoClkHalfT     -> asicRoClkHalfT;

  uint32_t _asicForce {
    uint8_t asicAcqForce    :1    -> asicAcqForce;
    uint8_t asicR0Force     :1    -> asicR0Force;
    uint8_t asicPPmatForce  :1    -> asicPPmatForce;
    uint8_t asicSyncForce   :1    -> asicSyncForce;
    uint8_t asicRoClkForce  :1    -> asicRoClkForce;
    uint32_t _z   :27;
  }
  uint32_t _asicForceValue {
    uint8_t asicAcqValue    :1    -> asicAcqValue;
    uint8_t asicR0Value     :1    -> asicR0Value;
    uint8_t asicPPmatValue  :1    -> asicPPmatValue;
    uint8_t asicSyncValue   :1    -> asicSyncValue;
    uint8_t asicRoClkValue  :1    -> asicRoClkValue;
    uint32_t _z   :27;
  }

  uint32_t _dummyAcqEn      -> dummyAcqEn;
  uint32_t _asicSyncInjEn   -> asicSyncInjEn;
  uint32_t _asicSyncInjDly  -> asicSyncInjDly;

        // RdoutCore
  uint32_t _adcPipelineDelay -> adcPipelineDelay;
  uint32_t _testData         -> testData;
  uint32_t _overSampleEn     -> overSampleEn;
  uint32_t _overSampleSize   -> overSampleSize;

        // PseudoScopeCore
  uint32_t _Scope {
    uint8_t _scopeEnable:1 -> scopeEnable;
    uint8_t _scopeTrigEdge:1 -> scopeTrigEdge;
    uint8_t _scopeTrigChan:5 -> scopeTrigChan;
    uint8_t _scopeTrigMode:2 -> scopeTrigMode;
    uint8_t _z:7;
    uint16_t _scopeADCThreshold:16 -> scopeADCThreshold;
  }
  uint32_t _ScopeTriggerParms_1 {
    uint16_t _scopeTrigHoldoff:13 -> scopeTrigHoldoff;
    uint16_t _scopeTrigOffset:13  -> scopeTrigOffset;
  }
  uint32_t _ScopeTriggerParms_2 {
    uint16_t _scopeTraceLength:13 -> scopeTraceLength;
    uint16_t _scopeADCsamplesToSkip:13 -> scopeADCsamplesToSkip;
  }
  uint32_t _ScopeWaveformSelects {
    uint8_t _scopeChanAwaveformSelect:7 -> scopeChanAwaveformSelect;
    uint8_t _scopeChanBwaveformSelect:7 -> scopeChanBwaveformSelect;
    uint32_t _z:18;
  }
  uint32_t _scopeTrigDelay -> scopeTrigDelay;

        // Ad9249ReadoutGroup [10]
        // Ad9249ConfigGroup [10]
  Ad9249Config _adc[10]  -> adc;

        // AdcTester
  uint32_t _testChannel  -> testChannel;
  uint32_t _testDataMask -> testDataMask;
  uint32_t _testPattern  -> testPattern;
  uint32_t _testSamples  -> testSamples;
  uint32_t _testTimeout  -> testTimeout;
  uint32_t _testRequest  -> testRequest;

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

//------------------ Config10kaQuadV1 ------------------
@type Config10kaQuadV1
  [[type_id(Id_Epix10kaQuadConfig, 1)]]
  [[pack(4)]]
  [[config_type]]
{
  @const uint32_t _numberOfElements = 4;

  uint32_t numberOfElements()  [[inline]]
  [[language("C++")]] @{ return @self._numberOfElements; @}
  uint32_t numberOfRows() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerColumn * Elem10kaConfigV1::_numberOfRowsPerAsic; @}
  uint32_t numberOfReadableRows() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerColumn * Elem10kaConfigV1::_numberOfReadableRowsPerAsic; @}
  uint32_t numberOfColumns() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerRow * Elem10kaConfigV1::_numberOfPixelsPerAsicRow; @}
  uint32_t numberOfCalibrationRows() [[language("C++")]] @{ return Elem10kaConfigV1::_calibrationRowCountPerASIC * Elem10kaConfigV1::_numberOfAsicsPerColumn; @}
  uint32_t numberOfEnvironmentalRows() [[language("C++")]] @{ return Elem10kaConfigV1::_environmentalRowCountPerASIC * Elem10kaConfigV1::_numberOfAsicsPerColumn; @}
  uint32_t numberOfAsics() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerRow * Elem10kaConfigV1::_numberOfAsicsPerColumn * @self._numberOfElements; @}

  PgpEvrConfig     _evr     -> evr;
  Quad10kaConfigV1 _quad    -> quad;
  Elem10kaConfigV1 _elem[4] -> elemCfg;

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

//------------------ Config10kaQuadV2 ------------------
@type Config10kaQuadV2
  [[type_id(Id_Epix10kaQuadConfig, 2)]]
  [[pack(4)]]
  [[config_type]]
{
  @const uint32_t _numberOfElements = 4;

  uint32_t numberOfElements()  [[inline]]
  [[language("C++")]] @{ return @self._numberOfElements; @}
  uint32_t numberOfRows() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerColumn * Elem10kaConfigV1::_numberOfRowsPerAsic; @}
  uint32_t numberOfReadableRows() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerColumn * Elem10kaConfigV1::_numberOfReadableRowsPerAsic; @}
  uint32_t numberOfColumns() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerRow * Elem10kaConfigV1::_numberOfPixelsPerAsicRow; @}
  uint32_t numberOfCalibrationRows() [[language("C++")]] @{ return Elem10kaConfigV1::_calibrationRowCountPerASIC * Elem10kaConfigV1::_numberOfAsicsPerColumn; @}
  uint32_t numberOfEnvironmentalRows() [[language("C++")]] @{ return Elem10kaConfigV1::_environmentalRowCountPerASIC * Elem10kaConfigV1::_numberOfAsicsPerColumn; @}
  uint32_t numberOfAsics() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerRow * Elem10kaConfigV1::_numberOfAsicsPerColumn * @self._numberOfElements; @}

  PgpEvrConfig     _evr     -> evr;
  Quad10kaConfigV2 _quad    -> quad;
  Elem10kaConfigV1 _elem[4] -> elemCfg;

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

//------------------ Config10ka2MV1 ------------------
@type Config10ka2MV1
  [[type_id(Id_Epix10ka2MConfig, 1)]]
  [[pack(4)]]
  [[config_type]]
{
  @const uint32_t _numberOfElements = 16;

  uint32_t numberOfElements()  [[inline]]
  [[language("C++")]] @{ return @self._numberOfElements; @}
  uint32_t numberOfRows() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerColumn * Elem10kaConfigV1::_numberOfRowsPerAsic; @}
  uint32_t numberOfReadableRows() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerColumn * Elem10kaConfigV1::_numberOfReadableRowsPerAsic; @}
  uint32_t numberOfColumns() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerRow * Elem10kaConfigV1::_numberOfPixelsPerAsicRow; @}
  uint32_t numberOfCalibrationRows() [[language("C++")]] @{ return Elem10kaConfigV1::_calibrationRowCountPerASIC * Elem10kaConfigV1::_numberOfAsicsPerColumn; @}
  uint32_t numberOfEnvironmentalRows() [[language("C++")]] @{ return Elem10kaConfigV1::_environmentalRowCountPerASIC * Elem10kaConfigV1::_numberOfAsicsPerColumn; @}
  uint32_t numberOfAsics() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerRow * Elem10kaConfigV1::_numberOfAsicsPerColumn * @self._numberOfElements; @}

  PgpEvrConfig     _evr     -> evr;
  Quad10kaConfigV1 _quad [4]-> quad;
  Elem10kaConfigV1 _elem[16]-> elemCfg;

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}

//------------------ Config10ka2MV2 ------------------
@type Config10ka2MV2
  [[type_id(Id_Epix10ka2MConfig, 2)]]
  [[pack(4)]]
  [[config_type]]
{
  @const uint32_t _numberOfElements = 16;

  uint32_t numberOfElements()  [[inline]]
  [[language("C++")]] @{ return @self._numberOfElements; @}
  uint32_t numberOfRows() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerColumn * Elem10kaConfigV1::_numberOfRowsPerAsic; @}
  uint32_t numberOfReadableRows() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerColumn * Elem10kaConfigV1::_numberOfReadableRowsPerAsic; @}
  uint32_t numberOfColumns() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerRow * Elem10kaConfigV1::_numberOfPixelsPerAsicRow; @}
  uint32_t numberOfCalibrationRows() [[language("C++")]] @{ return Elem10kaConfigV1::_calibrationRowCountPerASIC * Elem10kaConfigV1::_numberOfAsicsPerColumn; @}
  uint32_t numberOfEnvironmentalRows() [[language("C++")]] @{ return Elem10kaConfigV1::_environmentalRowCountPerASIC * Elem10kaConfigV1::_numberOfAsicsPerColumn; @}
  uint32_t numberOfAsics() [[language("C++")]] @{ return Elem10kaConfigV1::_numberOfAsicsPerRow * Elem10kaConfigV1::_numberOfAsicsPerColumn * @self._numberOfElements; @}

  PgpEvrConfig     _evr     -> evr;
  Quad10kaConfigV2 _quad [4]-> quad;
  Elem10kaConfigV1 _elem[16]-> elemCfg;

  /* Constructor which takes values for every attribute */
  @init()  [[auto]];
}



//------------------ ElementV1 ------------------
@type ElementV1
  [[type_id(Id_EpixElement, 1)]]
  [[pack(2)]]
  [[config(ConfigV1)]]
  [[config(Config10KV1)]]
  [[config(GenericPgp.ConfigV1)]]
{
  uint32_t _first {
    uint8_t _vc:2 -> vc;
    uint8_t _z:4;
    uint8_t _lane:2 -> lane;
    uint32_t _tid:24;
  }
  uint32_t _second {
    uint16_t _acqCount:16 -> acqCount;
    uint16_t _z:16;
  }
  uint32_t _frameNumber -> frameNumber;
  uint32_t _ticks -> ticks;
  uint32_t _fiducials -> fiducials;
  uint32_t _z0;
  uint32_t _z1;
  uint32_t _z2;
  uint16_t _frame[@config.numberOfRows()][@config.numberOfColumns()] -> frame;
  uint16_t _excludedRows[@config.lastRowExclusions()][@config.numberOfColumns()] -> excludedRows;
  uint16_t _temperatures[@config.numberOfAsics()] -> temperatures;
  uint32_t _lastWord -> lastWord;
}

//------------------ ElementV2 ------------------
@type ElementV2
  [[type_id(Id_EpixElement, 2)]]
  [[pack(2)]]
  [[config(Config100aV1)]]
  [[config(Config100aV2)]]
  [[config(ConfigSV1)]]
{
  uint32_t _first {
    uint8_t _vc:2 -> vc;
    uint8_t _z:4;
    uint8_t _lane:2 -> lane;
    uint32_t _tid:24;
  }
  uint32_t _second {
    uint16_t _acqCount:16 -> acqCount;
    uint16_t _z:16;
  }
  uint32_t _frameNumber -> frameNumber;
  uint32_t _ticks -> ticks;
  uint32_t _fiducials -> fiducials;
  uint32_t _z0;
  uint32_t _z1;
  uint32_t _z2;
  uint16_t _frame[@config.numberOfReadableRows()][@config.numberOfColumns()] -> frame;
  uint16_t _calibrationRows[@config.numberOfCalibrationRows()][@config.numberOfColumns()] -> calibrationRows;
  uint16_t _environmentalRows[@config.numberOfEnvironmentalRows()][@config.numberOfColumns()] -> environmentalRows;
  uint16_t _temperatures[@config.numberOfAsics()] -> temperatures;
  uint32_t _lastWord -> lastWord;
}

//------------------ ElementV3 ------------------
@type ElementV3
  [[type_id(Id_EpixElement, 3)]]
  [[pack(2)]]
  [[config(Config100aV1)]]
  [[config(Config100aV2)]]
  [[config(ConfigSV1)]]
  [[config(Config10kaV1)]]
  [[config(Config10kaV2)]]
{
  uint32_t _first {
    uint8_t _vc:2 -> vc;
    uint8_t _z:4;
    uint8_t _lane:2 -> lane;
    uint32_t _tid:24;
  }
  uint32_t _second {
    uint16_t _acqCount:16 -> acqCount;
    uint16_t _z:16;
  }
  uint32_t _frameNumber -> frameNumber;
  uint32_t _ticks -> ticks;
  uint32_t _fiducials -> fiducials;
  uint32_t _z0;
  uint32_t _z1;
  uint32_t _z2;
  uint16_t _frame[@config.numberOfReadableRows()][@config.numberOfColumns()] -> frame;
  uint16_t _calibrationRows[@config.numberOfCalibrationRows()][@config.numberOfColumns()] -> calibrationRows;
  uint32_t _environmentalRows[@config.numberOfEnvironmentalRows()][@config.numberOfColumns()>>1] -> environmentalRows;
  uint16_t _temperatures[@config.numberOfAsics()] -> temperatures;
  uint32_t _lastWord -> lastWord;
}

//------------------ ArrayV1 ------------------
@type ArrayV1
  [[type_id(Id_Epix10kaArray, 1)]]
  [[pack(4)]]
  [[config(Config10ka2MV1)]]
  [[config(Config10kaQuadV1)]]
  [[config(Config10ka2MV2)]]
  [[config(Config10kaQuadV2)]]
{
  uint32_t _frameNumber -> frameNumber;
  uint16_t _frame             [@config.numberOfElements()][@config.numberOfReadableRows()][@config.numberOfColumns()]         -> frame;
  uint16_t _calibrationRows   [@config.numberOfElements()][@config.numberOfCalibrationRows()][@config.numberOfColumns()]      -> calibrationRows;
  uint32_t _environmentalRows [@config.numberOfElements()][@config.numberOfEnvironmentalRows()][@config.numberOfColumns()>>1] -> environmentalRows;
  uint16_t _temperatures[@config.numberOfAsics()] -> temperatures;
}
} //- @package Epix

