close all;                          % close all window
clear all;                          % clear all variable
clc;                                % clear command window

%create an Arduino board object
a = arduino();

for i = 1:10                        % loop 10 times
    writeDigitalPin(a, 'D13', 0);   % set voltage across pin 13 to 0 
    pause(0.5);                     % wait 0.5s
    writeDigitalPin(a, 'D13', 1);   % set voltage across pin 13 to 1 
    pause(0.5);                     % wait 0.5s
end