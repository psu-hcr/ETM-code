close all;                          % close all window
clear all;                          % clear all variable
clc;                                % clear command window

%create an Arduino board object
a = arduino();

for i = 1:10                        % loop 10 times
    writeDigitalPin(a, 'D13', 0);   % turn on pin 13 off 
    pause(0.5);                     % wait 0.5s
    writeDigitalPin(a, 'D13', 1);   % turn on pin 13 on 
    pause(0.5);                     % wait 0.5s
end