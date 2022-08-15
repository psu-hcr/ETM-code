clear all;

% SUTDENTS: change the following 3 lines of code to put your sensor where
% you want to!
sensorx      = 0;  % Units are cm from midpoint between wheels
sensory      = 0;  % Units are cm from midpoint between wheels
sensor_angle_in_degrees = 0;  % Units are degrees, with 0 degrees pointing straight forward


delta_t = 0.01; %100 Hz sampling rate
t = 0:delta_t:200;
IR_distance_array = zeros(size(t));
IR_distance = 100; % Start off with a long-range reading
plot_every = 5; % This tells the simulation to only plot every N time steps. Set = 1 if you want to see each time step

for i=1:length(t)
    time = t(i); % This is the current time
    
    % STUDENTS: Put your algorithm here to drive the robot toward the wall
    % and trying to stop. You get to change the torque based on previous
    % IR_distance reading, and using this and some smarts, try to get the
    % robot to park as close as you can to the wall at x = 300.
       
    torque_L = .954;
    torque_R = 1;

    % Simulate robot and grab the IR distance
    IR_distance = fcn_simRobot2(torque_L,torque_R,sensorx,sensory,sensor_angle_in_degrees,plot_every);
    
    % Check to see if you slam into a wall: if so, the IR reading becomes
    % not-a-number, e.g. NaN!
    if isnan(IR_distance)
        break;
    end
    
end




