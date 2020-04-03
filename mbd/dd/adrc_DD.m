Ts = 1.0e-4;

h = Ts;
r = 10.0;
h0 = h;
r0 = r;

%% ADRC Control parameters.
ADRC_TrackFil_h0 = Simulink.Parameter;
ADRC_TrackFil_h0.StorageClass = 'Auto';
ADRC_TrackFil_h0.Description = 'h0: Usually matches execution rate of filter.';
ADRC_TrackFil_h0.DataType = 'single';
ADRC_TrackFil_h0.Min = [];
ADRC_TrackFil_h0.Max = [];
ADRC_TrackFil_h0.DocUnits = '';
ADRC_TrackFil_h0.Value = 1e-3;

ADRC_TrackFil_ts = Simulink.Parameter;
ADRC_TrackFil_ts.StorageClass = 'Auto';
ADRC_TrackFil_ts.Description = 'Tracking filter exeuction rate.';
ADRC_TrackFil_ts.DataType = 'single';
ADRC_TrackFil_ts.Min = [];
ADRC_TrackFil_ts.Max = [];
ADRC_TrackFil_ts.DocUnits = '';
ADRC_TrackFil_ts.Value = 1e-3;

ADRC_TrackFil_r0 = Simulink.Parameter;
ADRC_TrackFil_r0.StorageClass = 'Auto';
ADRC_TrackFil_r0.Description = 'Tracking filter agressivenes.';
ADRC_TrackFil_r0.DataType = 'single';
ADRC_TrackFil_r0.Min = [];
ADRC_TrackFil_r0.Max = [];
ADRC_TrackFil_r0.DocUnits = '';
ADRC_TrackFil_r0.Value = 10.e3;

ADRC_DistObsGain = Simulink.Parameter;
ADRC_DistObsGain.StorageClass = 'Auto';
ADRC_DistObsGain.Description = 'Disturbance observer tuning gain.';
ADRC_DistObsGain.DataType = 'single';
ADRC_DistObsGain.Value = 6.;

