% Create some example data. Students: copy/paste your data into the array
% below to replace the dummy data given here. Be sure that the first and
% last data rows that are copied are well formed. Sometimes the copy/paste
% process corrupts these specific lines of data.
data = [
5, 0​
10, 0​
25, 0​
30, 1​
35, 1​
40, 1​
121, 1​
126, 1​
131, 1​
136, 0​
141, 0​
176, 0​
181, 1
];
 
h_fig = figure(23945); % Open up specific fig number and save the handle to h_fig
clf; % Clear the figure, which removes any exisiting fig info from earlier
set(h_fig,'Name','Lab1 Data'); % Set the name of the plot, useful when many plots are open
width=640; height=450; right=100; bottom=400; % Set variables for plot size
set(gcf,'position',[right,bottom,width,height]) % Force plot into specific size, location
 
% Plot the data column 1 (x) versus column 2 (y), in red lines with data
% dots ('r.-'). Set the markersize to 10, which is much bigger than default
% plot(data(:,1),data(:,2),'r.-','MarkerSize',10)
stairs(data(:,1),data(:,2),'r.-','MarkerSize',10)
 
grid on; grid minor; % Turn on grids, turn on minor grids
ylim([-0.5 1.5]); % Set the y-axis limits so that the plot isn't too tight
xlabel('Time [ms]') % Add x-axis labels
ylabel('Measured Logic [unitless]') % Add y-axis labels
box on % Turn on the box outline for the whole plot, makes it "pretty"
