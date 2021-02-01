clear all, close all, clc

m = 1;
M = 5;
L = 2;
g = -10;
d = 1;
b = 1; % pendulum up (b=1)

A = [0 1 0 0;
    0 -d/M b*m*g/M 0;
    0 0 0 1;
    0 -b*d/(M*L) -b*(m+M)*g/(M*L) 0];
B = [0; 1/M; 0; b*1/(M*L)];

%% Design the controller
eigs = [-1 -2 -3 -4];

K = place(A,B,eigs);

%% Simulate closed-loop system
tspan = 0:.001:10;
x0 = [2; 0; pi+1; 0];  % initial condition
wr = [1; 0; pi; 0];      % reference position
u=@(x) -K*(x - wr);       % control law

[t,x] = ode45(@(t,x)pendcart(x,m,M,L,g,d,u(x)),tspan,x0);

for k=1:100:length(t)
    drawpend(x(k,:),m,M,L);
end