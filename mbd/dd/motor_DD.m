SimParams.PwmFrq = 30.0e3;
SimParams.Ts = 1.0e-5;

MotorParams.R = 23.6347; % Resistance.
MotorParams.L = 0.02395e-1; % Inductance.
MotorParams.K = 0.0155; % Torque Constant.
MotorParams.Kf = 7.5434e-7; % Damping.
MotorParams.J = 8.6337e-8; % Inertia.
MotorParams.AccMax = 1e4 * 180 / pi;
MotorParams.PPR = 400; % Encoder pulses / rev.

CtrlParams.TsIfbk = 1e-3;
CtrlParams.IfbkKi = 4 * MotorParams.R / CtrlParams.TsIfbk;
CtrlParams.IfbkKp = 4 * MotorParams.L / CtrlParams.TsIfbk;

CtrlParams.TsSpd = 0.05;
CtrlParams.SpdKi = 4 * MotorParams.Kf / MotorParams.K / CtrlParams.TsSpd;
CtrlParams.SpdKp = 4 * MotorParams.J / MotorParams.K / CtrlParams.TsSpd;

CtrlParams.TsPos = 0.3;
CtrlParams.PosKp = (4 / CtrlParams.TsPos);
CtrlParams.PosKi = 0.0;

SmDiffParams.AccMax = 9e4;
SmDiffParams.Ki = 1.1 * SmDiffParams.AccMax;
SmDiffParams.Kp = sqrt(SmDiffParams.AccMax);

%% Disturbance observer tuning.
damp_fctr = 0.99;
Tsettle = 1e-3; % 2% Rule.

% Observer form:
% e = z1 - y;
% dz1/dt = z1 - k1 * e;
% dz2/dt = z2 + b * u - K2 * e;
% dz3/dt = z3 - k3 * e;

wn = 6 / (damp_fctr * Tsettle);
s1 = -damp_fctr * wn + wn * sqrt(1 - damp_fctr^2) * 1j;
s2 = -damp_fctr * wn - wn * sqrt(1 - damp_fctr^2) * 1j;
s3 = -800 * damp_fctr;

A = [0, 1, 0;
     0, 0, 1;
     0, 0, 0];

C = [1, 0, 0];

K = place(A', C', [s1, s2, s3])';
AdrcParams.K1 = K(1);
AdrcParams.K2 = K(2);
AdrcParams.K3 = K(3);
AdrcParams.Ts = 1/30.e3;

clear damp_fctr, wn, s1, s2, s3, A, C, K;
