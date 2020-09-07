%% Configuration parameters.
Cfg_EnblSpdSns = Simulink.Parameter;
Cfg_EnblSpdSns.StorageClass = 'Auto';
Cfg_EnblSpdSns.Description = 'Configuration has speed sensor';
Cfg_EnblSpdSns.DataType = 'boolean';
Cfg_EnblSpdSns.Min = [];
Cfg_EnblSpdSns.Max = [];
Cfg_EnblSpdSns.DocUnits = '';
Cfg_EnblSpdSns.Value = 0;


%% Parameter definitions.
%% PID-P term.
IfbkCtrl_Kp = Simulink.Parameter;
% PID_Kp.CoderInfo.StorageClass = 'Custom';
% PID_Kp.CoderInfo.Alias = '';
% PID_Kp.CoderInfo.CustomStorageClass =  'Const';
IfbkCtrl_Kp.StorageClass = 'Auto';
IfbkCtrl_Kp.Description = 'PI proportional term for current controller.';
IfbkCtrl_Kp.DataType = 'single';
IfbkCtrl_Kp.Min = [];
IfbkCtrl_Kp.Max = [];
IfbkCtrl_Kp.DocUnits = '';
IfbkCtrl_Kp.Value = 95.8;

%% PID-I term.
IfbkCtrl_Ki = Simulink.Parameter;
% PID_Ki.CoderInfo.StorageClass = 'Custom';
% PID_Ki.CoderInfo.Alias = '';
% PID_Ki.CoderInfo.CustomStorageClass =  'Const';
IfbkCtrl_Ki.StorageClass = 'Auto';
IfbkCtrl_Ki.Description = 'PI integral term for current controller.';
IfbkCtrl_Ki.DataType =  'single';
IfbkCtrl_Ki.Min = [];
IfbkCtrl_Ki.Max = [];
IfbkCtrl_Ki.DocUnits = '';
IfbkCtrl_Ki.Value = 9.4539e4;

%% PID-P term.
SpdCtrl_Kp = Simulink.Parameter;
% SpdCtrl_Kp.CoderInfo.StorageClass = 'Custom';
% SpdCtrl_Kp.CoderInfo.Alias = '';
% SpdCtrl_Kp.CoderInfo.CustomStorageClass =  'Const';
SpdCtrl_Kp.StorageClass = 'Auto';
SpdCtrl_Kp.Description = 'PI proportional term for speed controller.';
SpdCtrl_Kp.DataType = 'single';
SpdCtrl_Kp.Min = [];
SpdCtrl_Kp.Max = [];
SpdCtrl_Kp.DocUnits = '';
SpdCtrl_Kp.Value = CtrlParams.SpdKp;
%SpdCtrl_Kp.Value = 7.688314981375182e-06;


%% PID-I term.
SpdCtrl_Ki = Simulink.Parameter;
% SpdCtrl_Ki.CoderInfo.StorageClass = 'Custom';
% SpdCtrl_Ki.CoderInfo.Alias = '';
% SpdCtrl_Ki.CoderInfo.CustomStorage0.5Class =  'Const';
SpdCtrl_Ki.StorageClass = 'Auto';
SpdCtrl_Ki.Description = 'PI integral term for speed controller.';
SpdCtrl_Ki.DataType =  'single';
SpdCtrl_Ki.Min = [];
SpdCtrl_Ki.Max = [];
SpdCtrl_Ki.DocUnits = '';
SpdCtrl_Ki.Value = CtrlParams.SpdKi;
%SpdCtrl_Ki.Value = 7.688314981375182e-04;


%% PID-P term.
PosCtrl_Kp = Simulink.Parameter;
% PosCtrl_Kp.CoderInfo.StorageClass = 'Custom';
% PosCtrl_Kp.CoderInfo.Alias = '';
% PosCtrl_Kp.CoderInfo.CustomStorageClass =  'Const';
PosCtrl_Kp.StorageClass = 'Auto';
PosCtrl_Kp.Description = 'PI proportional term for position controller.';
PosCtrl_Kp.DataType = 'single';
PosCtrl_Kp.Min = [];
PosCtrl_Kp.Max = [];
PosCtrl_Kp.DocUnits = '';
PosCtrl_Kp.Value = CtrlParams.PosKp;

%% PID-I term.
PosCtrl_Ki = Simulink.Parameter;
% PosCtrl_Ki.CoderInfo.StorageClass = 'Custom';
% PosCtrl_Ki.CoderInfo.Alias = '';
% PosCtrl_Ki.CoderInfo.CustomStorageClass =  'Const';
PosCtrl_Ki.StorageClass = 'Auto';
PosCtrl_Ki.Description = 'PI integral term for position controller.';
PosCtrl_Ki.DataType =  'single';
PosCtrl_Ki.Min = [];
PosCtrl_Ki.Max = [];
PosCtrl_Ki.DocUnits = '';
PosCtrl_Ki.Value = CtrlParams.PosKi;

%% Sliding mode differentiator P-term.
SmDiff_Kp = Simulink.Parameter;
% SmDiff_Kp.CoderInfo.StorageClass = 'Custom';
% SmDiff_Kp.CoderInfo.Alias = '';
% SmDiff_Kp.CoderInfo.CustomStorageClass =  'Const';
SmDiff_Kp.StorageClass = 'Auto';
SmDiff_Kp.Description = 'Proportional gain for motor position sliding mode differentiator.';
SmDiff_Kp.DataType = 'single';
SmDiff_Kp.Min = [];
SmDiff_Kp.Max = [];
SmDiff_Kp.DocUnits = '';
SmDiff_Kp.Value = SmDiffParams.Kp;

%% Sliding mode differentiator I-term.
SmDiff_Ki = Simulink.Parameter;
% Pos_SMDiff_Kp.CoderInfo.StorageClass = 'Custom';
% Pos_SMDiff_Kp.CoderInfo.Alias = '';
% Pos_SMDiff_Kp.CoderInfo.CustomStorageClass =  'Const';
SmDiff_Ki.StorageClass = 'Auto';
SmDiff_Ki.Description = 'Integral gain for motor position sliding mode differentiator.';
SmDiff_Ki.DataType = 'single';
SmDiff_Ki.Min = [];
SmDiff_Ki.Max = [];
SmDiff_Ki.DocUnits = '';
SmDiff_Ki.Value = SmDiffParams.Ki;

%% SM differentiator filter constant. Calculated as: tau / (ts + tau).
SmDiff_FiltCnst = Simulink.Parameter;
% SmDiff_FiltCnst.CoderInfo.StorageClass = 'Custom';
% SmDiff_FiltCnst.CoderInfo.Alias = '';
% SmDiff_FiltCnst.CoderInfo.CustomStorageClass =  'Const';
SmDiff_FiltCnst.StorageClass = 'Auto';
SmDiff_FiltCnst.Description = ' SM differentiator filter constant. Calculated as: tau / (ts + tau).';
SmDiff_FiltCnst.DataType = 'single';
SmDiff_FiltCnst.Min = [];
SmDiff_FiltCnst.Max = [];
SmDiff_FiltCnst.DocUnits = '';
SmDiff_FiltCnst.Value = 0.9615;

%% Encoder definition.
EncCnts = Simulink.Parameter;
EncCnts.StorageClass = 'Auto';
EncCnts.Description = 'Encoder counts';
EncCnts.DataType = 'single';
EncCnts.Min = [];
EncCnts.Max = [];
EncCnts.DocUnits = '';
EncCnts.Value = 400.;

%% Fast sampling time 30khz
TsFast = Simulink.Parameter;
TsFast.StorageClass = 'Auto';
TsFast.Description = 'Fast sampling time (30khz)';
TsFast.DataType = 'single';
TsFast.Min = [];
TsFast.Max = [];
TsFast.DocUnits = '';
TsFast.Value = 1./30e3;

%% Main sampling time (1khz)
TsMain = Simulink.Parameter;
TsMain.StorageClass = 'Auto';
TsMain.Description = 'Main sampling time (1khz)';
TsMain.DataType = 'single';
TsMain.Min = [];
TsMain.Max = [];
TsMain.DocUnits = '';
TsMain.Value = 1e-3;


%% Signal definitions

%% Current feedback Phase-A.
MtrIf_Ifbk = Simulink.Signal;
MtrIf_Ifbk.CoderInfo.Alias = '';
MtrIf_Ifbk.Description = 'Actual motor current from Phase-A';
MtrIf_Ifbk.DataType =  'Ifbk';
MtrIf_Ifbk.Min = [];
MtrIf_Ifbk.Max = [];
MtrIf_Ifbk.DocUnits = 'mA';
MtrIf_Ifbk.Dimensions = 1;
MtrIf_Ifbk.Complexity =  'auto';
MtrIf_Ifbk.SampleTime = -1;
MtrIf_Ifbk.SamplingMode =  'auto';
MtrIf_Ifbk.InitialValue = '';
% Generate GetSet function:
MtrIf_Ifbk.CoderInfo.StorageClass =  'Custom';
MtrIf_Ifbk.CoderInfo.CustomStorageClass =  'GetSet';
MtrIf_Ifbk.CoderInfo.CustomAttributes.HeaderFile = 'app.h';
MtrIf_Ifbk.CoderInfo.CustomAttributes.GetFunction = 'App_GetIfbkPhA';
MtrIf_Ifbk.CoderInfo.CustomAttributes.SetFunction = '';

%% PWM voltage for Phase-A.
MtrIf_Vin = Simulink.Signal;
MtrIf_Vin.CoderInfo.Alias = '';
MtrIf_Vin.Description = 'PWM voltage for Phase-A';
MtrIf_Vin.DataType =  'Volts';
MtrIf_Vin.Min = [];
MtrIf_Vin.Max = [];
MtrIf_Vin.DocUnits = 'mV';
MtrIf_Vin.Dimensions = 1;
MtrIf_Vin.Complexity =  'auto';
MtrIf_Vin.SampleTime = -1;
MtrIf_Vin.SamplingMode =  'auto';
MtrIf_Vin.InitialValue = '';
% Generate GetSet function:
MtrIf_Vin.CoderInfo.StorageClass =  'Custom';
MtrIf_Vin.CoderInfo.CustomStorageClass =  'GetSet';
MtrIf_Vin.CoderInfo.CustomAttributes.HeaderFile = 'app.h';
MtrIf_Vin.CoderInfo.CustomAttributes.SetFunction = 'App_SetPwmVoltChA';
MtrIf_Vin.CoderInfo.CustomAttributes.GetFunction = '';

%% Motor position.
MtrIf_PosAct = Simulink.Signal;
MtrIf_PosAct.CoderInfo.Alias = '';
MtrIf_PosAct.Description = 'Motor position';
MtrIf_PosAct.DataType =  'Degs';
MtrIf_PosAct.Min = [];
MtrIf_PosAct.Max = [];
MtrIf_PosAct.DocUnits = 'deg';
MtrIf_PosAct.Dimensions = 1;
MtrIf_PosAct.Complexity =  'auto';
MtrIf_PosAct.SampleTime = -1;
MtrIf_PosAct.SamplingMode =  'auto';
MtrIf_PosAct.InitialValue = '';
% Generate GetSet function:
MtrIf_PosAct.CoderInfo.StorageClass =  'Custom';
MtrIf_PosAct.CoderInfo.CustomStorageClass =  'GetSet';
MtrIf_PosAct.CoderInfo.CustomAttributes.HeaderFile = 'app.h';
MtrIf_PosAct.CoderInfo.CustomAttributes.GetFunction = 'App_GetMtrPos';
MtrIf_PosAct.CoderInfo.CustomAttributes.SetFunction = '';

%% Motor position target.
MtrIf_PosTgt = Simulink.Signal;
MtrIf_PosTgt.CoderInfo.Alias = '';
MtrIf_PosTgt.Description = 'Motor position target';
MtrIf_PosTgt.DataType =  'Degs';
MtrIf_PosTgt.Min = [];
MtrIf_PosTgt.Max = [];
MtrIf_PosTgt.DocUnits = 'deg';
MtrIf_PosTgt.Dimensions = 1;
MtrIf_PosTgt.Complexity =  'auto';
MtrIf_PosTgt.SampleTime = -1;
MtrIf_PosTgt.SamplingMode =  'auto';
MtrIf_PosTgt.InitialValue = '';
% Generate GetSet function:
MtrIf_PosTgt.CoderInfo.StorageClass =  'Custom';
MtrIf_PosTgt.CoderInfo.CustomStorageClass =  'GetSet';
MtrIf_PosTgt.CoderInfo.CustomAttributes.HeaderFile = 'app.h';
MtrIf_PosTgt.CoderInfo.CustomAttributes.GetFunction = 'App_GetMtrPosTgt';
MtrIf_PosTgt.CoderInfo.CustomAttributes.SetFunction = 'App_SetMtrPosTgt';


%% Motor speed.
MtrIf_SpdAct = Simulink.Signal;
MtrIf_SpdAct.CoderInfo.Alias = '';
MtrIf_SpdAct.Description = 'Motor speed';
MtrIf_SpdAct.DataType =  'Degs_s';
MtrIf_SpdAct.Min = [];
MtrIf_SpdAct.Max = [];
MtrIf_SpdAct.DocUnits = '';
MtrIf_SpdAct.Dimensions = 1;
MtrIf_SpdAct.Complexity =  'auto';
MtrIf_SpdAct.SampleTime = -1;
MtrIf_SpdAct.SamplingMode =  'auto';
MtrIf_SpdAct.InitialValue = '';
% Generate GetSet function:
MtrIf_SpdAct.CoderInfo.StorageClass =  'Custom';
MtrIf_SpdAct.CoderInfo.CustomStorageClass =  'GetSet';
MtrIf_SpdAct.CoderInfo.CustomAttributes.HeaderFile = 'app.h';
MtrIf_SpdAct.CoderInfo.CustomAttributes.SetFunction = 'App_SetMtrSpd';
MtrIf_SpdAct.CoderInfo.CustomAttributes.GetFunction = 'App_GetMtrSpd';

%% Motor speed filtered.
MtrIf_SpdActFil = Simulink.Signal;
MtrIf_SpdActFil.CoderInfo.Alias = '';
MtrIf_SpdActFil.Description = 'Motor speed filtered';
MtrIf_SpdActFil.DataType =  'Degs_s';
MtrIf_SpdActFil.Min = [];
MtrIf_SpdActFil.Max = [];
MtrIf_SpdActFil.DocUnits = '';
MtrIf_SpdActFil.Dimensions = 1;
MtrIf_SpdActFil.Complexity =  'auto';
MtrIf_SpdActFil.SampleTime = -1;
MtrIf_SpdActFil.SamplingMode =  'auto';
MtrIf_SpdActFil.InitialValue = '';
% Generate GetSet function:
MtrIf_SpdActFil.CoderInfo.StorageClass =  'Custom';
MtrIf_SpdActFil.CoderInfo.CustomStorageClass =  'GetSet';
MtrIf_SpdActFil.CoderInfo.CustomAttributes.HeaderFile = 'app.h';
MtrIf_SpdActFil.CoderInfo.CustomAttributes.SetFunction = 'App_SetMtrSpdFil';
MtrIf_SpdActFil.CoderInfo.CustomAttributes.GetFunction = '';
