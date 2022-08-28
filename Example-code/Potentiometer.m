close all;                          % close all window
clear all;                          % clear all variable
clc;                                % clear command window

%create an Arduino board object
a = arduino();

time = 200;
while time > 0
    voltage = readVoltage(a, 'A0');
    writePWMVoltage(a, 'D11', voltage);
    time = time - 1;
    pause(0.1);
end