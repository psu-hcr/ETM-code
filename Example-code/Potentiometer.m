close all;                              % close all window
clear all;                              % clear all variable
clc;                                    % clear command window

%create an Arduino board object
a = arduino();

time = 200;
while time > 0
    voltage = readVoltage(a, 'A0');     % read voltage at pin A0
    writePWMVoltage(a, 'D11', voltage); % wirte same voltage at pin 11
    time = time - 1;                    % reduce timer
    pause(0.1);                         % keep current pin voltage for 0.1s
end