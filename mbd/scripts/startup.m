clear; clc;
proj = simulinkproject;
Simulink.fileGenControl('set', ...
    'CodeGenFolder', fullfile(proj.RootFolder, 'codegen'), ...)
    'CacheFolder', fullfile(proj.RootFolder, 'cache'), ...
    'CreateDir', true);

ctrl_DD;
motor_DD;