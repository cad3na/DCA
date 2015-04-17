  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (SlotineAdaptableMotor_P)
    ;%
      section.nData     = 34;
      section.data(34)  = dumData; %prealloc
      
	  ;% SlotineAdaptableMotor_P.Integrator1_IC
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SlotineAdaptableMotor_P.Integrator_IC
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% SlotineAdaptableMotor_P.IntDecod_P1_Size
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% SlotineAdaptableMotor_P.IntDecod_P1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% SlotineAdaptableMotor_P.Gain_Gain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% SlotineAdaptableMotor_P.Gain_Gain_j
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% SlotineAdaptableMotor_P.Integrator_IC_c
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% SlotineAdaptableMotor_P.Integrator_IC_m
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% SlotineAdaptableMotor_P.Filtro_A
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% SlotineAdaptableMotor_P.Filtro_C
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 10;
	
	  ;% SlotineAdaptableMotor_P.Gain1_Gain
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 11;
	
	  ;% SlotineAdaptableMotor_P.g2_Gain
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 12;
	
	  ;% SlotineAdaptableMotor_P.TransferFcn_A
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 13;
	
	  ;% SlotineAdaptableMotor_P.TransferFcn_C
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 14;
	
	  ;% SlotineAdaptableMotor_P.g1_Gain
	  section.data(15).logicalSrcIdx = 18;
	  section.data(15).dtTransOffset = 15;
	
	  ;% SlotineAdaptableMotor_P.Gain_Gain_m
	  section.data(16).logicalSrcIdx = 19;
	  section.data(16).dtTransOffset = 16;
	
	  ;% SlotineAdaptableMotor_P.Gain1_Gain_g
	  section.data(17).logicalSrcIdx = 20;
	  section.data(17).dtTransOffset = 17;
	
	  ;% SlotineAdaptableMotor_P.Gain_Gain_f
	  section.data(18).logicalSrcIdx = 21;
	  section.data(18).dtTransOffset = 18;
	
	  ;% SlotineAdaptableMotor_P.IntAD_P1_Size
	  section.data(19).logicalSrcIdx = 22;
	  section.data(19).dtTransOffset = 20;
	
	  ;% SlotineAdaptableMotor_P.IntAD_P1
	  section.data(20).logicalSrcIdx = 23;
	  section.data(20).dtTransOffset = 22;
	
	  ;% SlotineAdaptableMotor_P.IntAD_P2_Size
	  section.data(21).logicalSrcIdx = 24;
	  section.data(21).dtTransOffset = 23;
	
	  ;% SlotineAdaptableMotor_P.IntAD_P2
	  section.data(22).logicalSrcIdx = 25;
	  section.data(22).dtTransOffset = 25;
	
	  ;% SlotineAdaptableMotor_P.Gain1_Gain_p
	  section.data(23).logicalSrcIdx = 26;
	  section.data(23).dtTransOffset = 26;
	
	  ;% SlotineAdaptableMotor_P.IntAD_P1_Size_a
	  section.data(24).logicalSrcIdx = 27;
	  section.data(24).dtTransOffset = 27;
	
	  ;% SlotineAdaptableMotor_P.IntAD_P1_i
	  section.data(25).logicalSrcIdx = 28;
	  section.data(25).dtTransOffset = 29;
	
	  ;% SlotineAdaptableMotor_P.IntAD_P2_Size_h
	  section.data(26).logicalSrcIdx = 29;
	  section.data(26).dtTransOffset = 30;
	
	  ;% SlotineAdaptableMotor_P.IntAD_P2_o
	  section.data(27).logicalSrcIdx = 30;
	  section.data(27).dtTransOffset = 32;
	
	  ;% SlotineAdaptableMotor_P.IntAD_P3_Size
	  section.data(28).logicalSrcIdx = 31;
	  section.data(28).dtTransOffset = 33;
	
	  ;% SlotineAdaptableMotor_P.IntAD_P3
	  section.data(29).logicalSrcIdx = 32;
	  section.data(29).dtTransOffset = 35;
	
	  ;% SlotineAdaptableMotor_P.SignalGenerator_Amplitude
	  section.data(30).logicalSrcIdx = 33;
	  section.data(30).dtTransOffset = 36;
	
	  ;% SlotineAdaptableMotor_P.SignalGenerator_Frequency
	  section.data(31).logicalSrcIdx = 34;
	  section.data(31).dtTransOffset = 37;
	
	  ;% SlotineAdaptableMotor_P.Step_Time
	  section.data(32).logicalSrcIdx = 35;
	  section.data(32).dtTransOffset = 38;
	
	  ;% SlotineAdaptableMotor_P.Step_Y0
	  section.data(33).logicalSrcIdx = 36;
	  section.data(33).dtTransOffset = 39;
	
	  ;% SlotineAdaptableMotor_P.Step_YFinal
	  section.data(34).logicalSrcIdx = 37;
	  section.data(34).dtTransOffset = 40;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (SlotineAdaptableMotor_B)
    ;%
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% SlotineAdaptableMotor_B.Integrator1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SlotineAdaptableMotor_B.Sign
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% SlotineAdaptableMotor_B.Integrator
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% SlotineAdaptableMotor_B.IntDecod
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% SlotineAdaptableMotor_B.Gain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 11;
	
	  ;% SlotineAdaptableMotor_B.Sum1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 12;
	
	  ;% SlotineAdaptableMotor_B.Sum
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 13;
	
	  ;% SlotineAdaptableMotor_B.Gain_c
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 14;
	
	  ;% SlotineAdaptableMotor_B.Integrator_a
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 15;
	
	  ;% SlotineAdaptableMotor_B.Sum2
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 16;
	
	  ;% SlotineAdaptableMotor_B.Integrator_f
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 17;
	
	  ;% SlotineAdaptableMotor_B.Product1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 19;
	
	  ;% SlotineAdaptableMotor_B.Filtro
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 20;
	
	  ;% SlotineAdaptableMotor_B.Sum1_k
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 21;
	
	  ;% SlotineAdaptableMotor_B.Gain1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 22;
	
	  ;% SlotineAdaptableMotor_B.g2
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 23;
	
	  ;% SlotineAdaptableMotor_B.TransferFcn
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
	  ;% SlotineAdaptableMotor_B.Sum_n
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 25;
	
	  ;% SlotineAdaptableMotor_B.g1
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 26;
	
	  ;% SlotineAdaptableMotor_B.Sum1_e
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 27;
	
	  ;% SlotineAdaptableMotor_B.Sum3
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 28;
	
	  ;% SlotineAdaptableMotor_B.Product2
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 29;
	
	  ;% SlotineAdaptableMotor_B.Sum4
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 30;
	
	  ;% SlotineAdaptableMotor_B.Gain_p
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 31;
	
	  ;% SlotineAdaptableMotor_B.Sum_a
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 32;
	
	  ;% SlotineAdaptableMotor_B.Gain1_c
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 33;
	
	  ;% SlotineAdaptableMotor_B.MathFunction
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 34;
	
	  ;% SlotineAdaptableMotor_B.Product3
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 35;
	
	  ;% SlotineAdaptableMotor_B.Gain_i
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 36;
	
	  ;% SlotineAdaptableMotor_B.Product
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 38;
	
	  ;% SlotineAdaptableMotor_B.MathFunction_o
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 40;
	
	  ;% SlotineAdaptableMotor_B.IntAD
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 41;
	
	  ;% SlotineAdaptableMotor_B.Gain1_e
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 49;
	
	  ;% SlotineAdaptableMotor_B.SignalGenerator
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 50;
	
	  ;% SlotineAdaptableMotor_B.Step
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 51;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (SlotineAdaptableMotor_DWork)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% SlotineAdaptableMotor_DWork.IEC_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SlotineAdaptableMotor_DWork.q_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% SlotineAdaptableMotor_DWork.qqd_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% SlotineAdaptableMotor_DWork.qqd_PWORK_m.LoggedData
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% SlotineAdaptableMotor_DWork.u_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% SlotineAdaptableMotor_DWork.qdmed_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% SlotineAdaptableMotor_DWork.qdpmed_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% SlotineAdaptableMotor_DWork.qdppmed_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% SlotineAdaptableMotor_DWork.a_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% SlotineAdaptableMotor_DWork.b_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% SlotineAdaptableMotor_DWork.IntDecod_IWORK
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% SlotineAdaptableMotor_DWork.IntAD_IWORK
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% SlotineAdaptableMotor_DWork.IntAD_IWORK_n
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 4251550148;
  targMap.checksum1 = 1075484270;
  targMap.checksum2 = 2047355761;
  targMap.checksum3 = 3372331732;

