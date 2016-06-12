clear all;

file = load('data.dat'); % copied data from terminal arduino
t4 = file(:,1)/4; % because 4*360 steps / rotation
r4 = file(:,2)/4; % because 4*360 steps / rotation
theta = 90-mod(t4,360); 
rho = 90-mod(r4,360);
phi = file(:,3);
rad1=pi/180; % factor to convert degrees to radians
cartesian(:,1) = phi.*sin(rad1*rho).*cos(rad1*theta); % x
cartesian(:,2) = phi.*sin(rad1*rho).*sin(rad1*theta); % y
cartesian(:,3) = phi.*cos(rad1*rho); % z

save cartesian.csv cartesian % the file can be displayed in CloudCompare



