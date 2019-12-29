Acc_Max = 1e4;

Ts = 0.001;
PID_Ki = 4 * R / Ts;
PID_Kp = 4 * L / Ts;

Ts_spd = 0.01;
Spd_Ki = 4 * Kf / Ts;
Spd_Kp = 4 * J / Ts;
SPD_SLEW_RATE = 100;
SPD_SM_K2 = 1.1 * Acc_Max;
SPD_SM_K1 = sqrt(Acc_Max);

SPD_LIN_KP = 2 * 2e1;
SPD_LIN_KI = SPD_LIN_KP ^ 2 / 4;

Ts_pos = 0.1;
Pos_Kp = 4 / Ts_pos;