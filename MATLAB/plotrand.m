% Generate random data from a uniform distribution
% and calculate the mean. Plot the data and mean.

n = 50; % 50 data points
r = rand(n, 1);
plot(r)

% Draw a line from (0, m) to (n, m)
m = mean(r);
hold on
plot([0 n], [m m]) % x = [0 n], y = [m m]
hold off
title('Mean of Random Uniform Data')
legend('r', 'line')