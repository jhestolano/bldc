%% Alias type definitions.
%% Current units.
Ifbk = Simulink.AliasType;
Ifbk.BaseType = 'single';

%% Volt units.
Volts = Simulink.AliasType;
Volts.BaseType = 'single';

%% Degree units.
Degs = Simulink.AliasType;
Degs.BaseType = 'single';

%% Degrees per second units.
Degs_s = Simulink.AliasType;
Degs_s.BaseType = 'single';

%% Parameter definitions.
%% PID-P term.
Ifbk_PI_Kp = Simulink.Parameter;
% PID_Kp.CoderInfo.StorageClass = 'Custom';
% PID_Kp.CoderInfo.Alias = '';
% PID_Kp.CoderInfo.CustomStorageClass =  'Const';
Ifbk_PI_Kp.StorageClass = 'Auto';
Ifbk_PI_Kp.Description = 'PI proportional term for current controller.';
Ifbk_PI_Kp.DataType = 'single';
Ifbk_PI_Kp.Min = [];
Ifbk_PI_Kp.Max = [];
Ifbk_PI_Kp.DocUnits = '';
Ifbk_PI_Kp.Value = 95.8;

%% PID-I term.
Ifbk_PI_Ki = Simulink.Parameter;
% PID_Ki.CoderInfo.StorageClass = 'Custom';
% PID_Ki.CoderInfo.Alias = '';
% PID_Ki.CoderInfo.CustomStorageClass =  'Const';
Ifbk_PI_Ki.StorageClass = 'Auto';
Ifbk_PI_Ki.Description = 'PI integral term for current controller.';
Ifbk_PI_Ki.DataType =  'single';
Ifbk_PI_Ki.Min = [];
Ifbk_PI_Ki.Max = [];
Ifbk_PI_Ki.DocUnits = '';
Ifbk_PI_Ki.Value = 9.4539e4;

%% PID-P term.
Spd_PI_Kp = Simulink.Parameter;
% Spd_PI_Kp.CoderInfo.StorageClass = 'Custom';
% Spd_PI_Kp.CoderInfo.Alias = '';
% Spd_PI_Kp.CoderInfo.CustomStorageClass =  'Const';
Spd_PI_Kp.StorageClass = 'Auto';
Spd_PI_Kp.Description = 'PI proportional term for speed controller.';
Spd_PI_Kp.DataType = 'single';
Spd_PI_Kp.Min = [];
Spd_PI_Kp.Max = [];
Spd_PI_Kp.DocUnits = '';
Spd_PI_Kp.Value = Spd_Kp;
%Spd_PI_Kp.Value = 7.688314981375182e-06;


%% PID-I term.
Spd_PI_Ki = Simulink.Parameter;
% Spd_PI_Ki.CoderInfo.StorageClass = 'Custom';
% Spd_PI_Ki.CoderInfo.Alias = '';
% Spd_PI_Ki.CoderInfo.CustomStorage0.5Class =  'Const';
Spd_PI_Ki.StorageClass = 'Auto';
Spd_PI_Ki.Description = 'PI integral term for speed controller.';
Spd_PI_Ki.DataType =  'single';
Spd_PI_Ki.Min = [];
Spd_PI_Ki.Max = [];
Spd_PI_Ki.DocUnits = '';
Spd_PI_Ki.Value = Spd_Ki;
%Spd_PI_Ki.Value = 7.688314981375182e-04;


%% PID-P term.
Pos_PI_Kp = Simulink.Parameter;
% Pos_PI_Kp.CoderInfo.StorageClass = 'Custom';
% Pos_PI_Kp.CoderInfo.Alias = '';
% Pos_PI_Kp.CoderInfo.CustomStorageClass =  'Const';
Pos_PI_Kp.StorageClass = 'Auto';
Pos_PI_Kp.Description = 'PI proportional term for position controller.';
Pos_PI_Kp.DataType = 'single';
Pos_PI_Kp.Min = [];
Pos_PI_Kp.Max = [];
Pos_PI_Kp.DocUnits = '';
Pos_PI_Kp.Value = Pos_Kp;

%% PID-I term.
Pos_PI_Ki = Simulink.Parameter;
% Pos_PI_Ki.CoderInfo.StorageClass = 'Custom';
% Pos_PI_Ki.CoderInfo.Alias = '';
% Pos_PI_Ki.CoderInfo.CustomStorageClass =  'Const';
Pos_PI_Ki.StorageClass = 'Auto';
Pos_PI_Ki.Description = 'PI integral term for position controller.';
Pos_PI_Ki.DataType =  'single';
Pos_PI_Ki.Min = [];
Pos_PI_Ki.Max = [];
Pos_PI_Ki.DocUnits = '';
Pos_PI_Ki.Value = 0.;

%% Sliding mode differentiator P-term.
Pos_SMDiff_Kp = Simulink.Parameter;
% Pos_SMDiff_Kp.CoderInfo.StorageClass = 'Custom';
% Pos_SMDiff_Kp.CoderInfo.Alias = '';
% Pos_SMDiff_Kp.CoderInfo.CustomStorageClass =  'Const';
Pos_SMDiff_Kp.StorageClass = 'Auto';
Pos_SMDiff_Kp.Description = 'Proportional gain for motor position sliding mode differentiator.';
Pos_SMDiff_Kp.DataType = 'single';
Pos_SMDiff_Kp.Min = [];
Pos_SMDiff_Kp.Max = [];
Pos_SMDiff_Kp.DocUnits = '';
Pos_SMDiff_Kp.Value = 756.9398;

%% Sliding mode differentiator I-term.
Pos_SMDiff_Ki = Simulink.Parameter;
% Pos_SMDiff_Kp.CoderInfo.StorageClass = 'Custom';
% Pos_SMDiff_Kp.CoderInfo.Alias = '';
% Pos_SMDiff_Kp.CoderInfo.CustomStorageClass =  'Const';
Pos_SMDiff_Ki.StorageClass = 'Auto';
Pos_SMDiff_Ki.Description = 'Integral gain for motor position sliding mode differentiator.';
Pos_SMDiff_Ki.DataType = 'single';
Pos_SMDiff_Ki.Min = [];
Pos_SMDiff_Ki.Max = [];
Pos_SMDiff_Ki.DocUnits = '';
Pos_SMDiff_Ki.Value = 6.3025e5;

%% Filter constant for SM diff.
Pos_SMDiff_Filt = Simulink.Parameter;
% Pos_SMDiff_Filt.CoderInfo.StorageClass = 'Custom';
% Pos_SMDiff_Filt.CoderInfo.Alias = '';
% Pos_SMDiff_Filt.CoderInfo.CustomStorageClass =  'Const';
Pos_SMDiff_Filt.StorageClass = 'Auto';
Pos_SMDiff_Filt.Description = 'Filter constant for sliding mode differentiator.';
Pos_SMDiff_Filt.DataType = 'single';
Pos_SMDiff_Filt.Min = [];
Pos_SMDiff_Filt.Max = [];
Pos_SMDiff_Filt.DocUnits = '';
Pos_SMDiff_Filt.Value = 2.5e-3;

%% Time step representing 1e-4s.
Ts_1n4 = Simulink.Parameter;
% Ts_1n4.CoderInfo.StorageClass = 'Custom';
% Ts_1n4.CoderInfo.Alias = '';
% Ts_1n4.CoderInfo.CustomStorageClass =  'Const';
Ts_1n4.StorageClass = 'Auto';
Ts_1n4.Description = 'Time step representing 1e-4s. Useful for discrete time systems that take execution rate.';
Ts_1n4.DataType = 'single';
Ts_1n4.Min = [];
Ts_1n4.Max = [];
Ts_1n4.DocUnits = '';
Ts_1n4.Value = 1e-4;

%% SM differentiator filter constant. Calculated as: tau / (ts + tau).
Spd_SMDiff_Filt_K = Simulink.Parameter;
% Spd_SMDiff_Filt_K.CoderInfo.StorageClass = 'Custom';
% Spd_SMDiff_Filt_K.CoderInfo.Alias = '';
% Spd_SMDiff_Filt_K.CoderInfo.CustomStorageClass =  'Const';
Spd_SMDiff_Filt_K.StorageClass = 'Auto';
Spd_SMDiff_Filt_K.Description = ' SM differentiator filter constant. Calculated as: tau / (ts + tau).';
Spd_SMDiff_Filt_K.DataType = 'single';
Spd_SMDiff_Filt_K.Min = [];
Spd_SMDiff_Filt_K.Max = [];
Spd_SMDiff_Filt_K.DocUnits = '';
Spd_SMDiff_Filt_K.Value = 0.9615;

%% Signal definitions

%% Current feedback Phase-A.
IfbkPhA = Simulink.Signal;
IfbkPhA.CoderInfo.Alias = '';
IfbkPhA.Description = 'Actual motor current from Phase-A';
IfbkPhA.DataType =  'Ifbk';
IfbkPhA.Min = [];
IfbkPhA.Max = [];
IfbkPhA.DocUnits = 'mA';
IfbkPhA.Dimensions = 1;
IfbkPhA.Complexity =  'auto';
IfbkPhA.SampleTime = -1;
IfbkPhA.SamplingMode =  'auto';
IfbkPhA.InitialValue = '';
% Generate GetSet function:
IfbkPhA.CoderInfo.StorageClass =  'Custom';
IfbkPhA.CoderInfo.CustomStorageClass =  'GetSet';
IfbkPhA.CoderInfo.CustomAttributes.HeaderFile = 'app.h';
IfbkPhA.CoderInfo.CustomAttributes.GetFunction = 'App_GetIfbkPhA';
IfbkPhA.CoderInfo.CustomAttributes.SetFunction = '';

%% PWM voltage for Phase-A.
PwmChA = Simulink.Signal;
PwmChA.CoderInfo.Alias = '';
PwmChA.Description = 'PWM voltage for Phase-A';
PwmChA.DataType =  'Volts';
PwmChA.Min = [];
PwmChA.Max = [];
PwmChA.DocUnits = 'mV';
PwmChA.Dimensions = 1;
PwmChA.Complexity =  'auto';
PwmChA.SampleTime = -1;
PwmChA.SamplingMode =  'auto';
PwmChA.InitialValue = '';
% Generate GetSet function:
PwmChA.CoderInfo.StorageClass =  'Custom';
PwmChA.CoderInfo.CustomStorageClass =  'GetSet';
PwmChA.CoderInfo.CustomAttributes.HeaderFile = 'app.h';
PwmChA.CoderInfo.CustomAttributes.SetFunction = 'App_SetPwmVoltChA';
PwmChA.CoderInfo.CustomAttributes.GetFunction = '';

%% Motor position.
MtrPos = Simulink.Signal;
MtrPos.CoderInfo.Alias = '';
MtrPos.Description = 'Motor position';
MtrPos.DataType =  'Degs';
MtrPos.Min = [];
MtrPos.Max = [];
MtrPos.DocUnits = 'deg';
MtrPos.Dimensions = 1;
MtrPos.Complexity =  'auto';
MtrPos.SampleTime = -1;
MtrPos.SamplingMode =  'auto';
MtrPos.InitialValue = '';
% Generate GetSet function:
MtrPos.CoderInfo.StorageClass =  'Custom';
MtrPos.CoderInfo.CustomStorageClass =  'GetSet';
MtrPos.CoderInfo.CustomAttributes.HeaderFile = 'app.h';
MtrPos.CoderInfo.CustomAttributes.GetFunction = 'App_GetMtrPos';
MtrPos.CoderInfo.CustomAttributes.SetFunction = '';

%% Motor position target.
MtrPosTgt = Simulink.Signal;
MtrPosTgt.CoderInfo.Alias = '';
MtrPosTgt.Description = 'Motor position target';
MtrPosTgt.DataType =  'Degs';
MtrPosTgt.Min = [];
MtrPosTgt.Max = [];
MtrPosTgt.DocUnits = 'deg';
MtrPosTgt.Dimensions = 1;
MtrPosTgt.Complexity =  'auto';
MtrPosTgt.SampleTime = -1;
MtrPosTgt.SamplingMode =  'auto';
MtrPosTgt.InitialValue = '';
% Generate GetSet function:
MtrPosTgt.CoderInfo.StorageClass =  'Custom';
MtrPosTgt.CoderInfo.CustomStorageClass =  'GetSet';
MtrPosTgt.CoderInfo.CustomAttributes.HeaderFile = 'app.h';
MtrPosTgt.CoderInfo.CustomAttributes.GetFunction = 'App_GetMtrPosTgt';
MtrPosTgt.CoderInfo.CustomAttributes.SetFunction = 'App_SetMtrPosTgt';


%% Motor speed.
MtrSpd = Simulink.Signal;
MtrSpd.CoderInfo.Alias = '';
MtrSpd.Description = 'Motor speed';
MtrSpd.DataType =  'Degs_s';
MtrSpd.Min = [];
MtrSpd.Max = [];
MtrSpd.DocUnits = '';
MtrSpd.Dimensions = 1;
MtrSpd.Complexity =  'auto';
MtrSpd.SampleTime = -1;
MtrSpd.SamplingMode =  'auto';
MtrSpd.InitialValue = '';
% Generate GetSet function:
MtrSpd.CoderInfo.StorageClass =  'Custom';
MtrSpd.CoderInfo.CustomStorageClass =  'GetSet';
MtrSpd.CoderInfo.CustomAttributes.HeaderFile = 'app.h';
MtrSpd.CoderInfo.CustomAttributes.SetFunction = 'App_SetMtrSpd';
MtrSpd.CoderInfo.CustomAttributes.GetFunction = 'App_GetMtrSpd';

%% Motor speed filtered.
MtrSpdFil = Simulink.Signal;
MtrSpdFil.CoderInfo.Alias = '';
MtrSpdFil.Description = 'Motor speed filtered';
MtrSpdFil.DataType =  'Degs_s';
MtrSpdFil.Min = [];
MtrSpdFil.Max = [];
MtrSpdFil.DocUnits = '';
MtrSpdFil.Dimensions = 1;
MtrSpdFil.Complexity =  'auto';
MtrSpdFil.SampleTime = -1;
MtrSpdFil.SamplingMode =  'auto';
MtrSpdFil.InitialValue = '';
% Generate GetSet function:
MtrSpdFil.CoderInfo.StorageClass =  'Custom';
MtrSpdFil.CoderInfo.CustomStorageClass =  'GetSet';
MtrSpdFil.CoderInfo.CustomAttributes.HeaderFile = 'app.h';
MtrSpdFil.CoderInfo.CustomAttributes.SetFunction = 'App_SetMtrSpdFil';
MtrSpdFil.CoderInfo.CustomAttributes.GetFunction = '';
