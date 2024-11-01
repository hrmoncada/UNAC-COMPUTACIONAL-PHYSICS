% https://gist.github.com/anazareth/16cd5fc36e75fdc01f004e4681b98495
clc; clear

L = 1; % length of needle
num_needles = 1000; % number of needles to drop

a = 0; b = 10; % bounds (same for x and y) of 10 by 10 area
N = 10; % num points with which to plot lines
x = a:1:b; % x values for line plotting
y = repmat(a:1:b,length(x),1); % y values for line plotting
plot(x, y, 'b')
title([num2str(num_needles) ' needles dropped on lined paper'], ...
    'Length of needle = space between lines = 1')

rng(1234) % set seed for reproducible results
angles = pi*rand(1,num_needles);  % generate random angles
xr = 1+(b-2)*rand(1,num_needles);  % generate random x and y coords on page
yr = 1+(b-2)*rand(1,num_needles);  % (width 1 "margin" for nicer plot)

hold on
for i = 1:num_needles
    t = angles(i);
    x1 = xr(i)-(1/2)*L*cos(t); x2 = x1 + L*cos(t);
    y1 = yr(i)-(1/2)*L*sin(t); y2 = y1 + L*sin(t);
    line([x1,x2], [y1,y2], 'Color', 'r', 'LineWidth', 1);
end

yr_repmat = repmat(yr',1,11);
yNN = repmat(y(1,:),num_needles,1); 
needle_dist = min(abs(yNN-yr_repmat),[],2)';
                   
display('Approximation of pi:')
2*num_needles/sum(needle_dist<=0.5*sin(angles))
