clc, clear all;
m= 1.177;
M= 0.192;
l= 0.05;
I= 0.0029;
g= 9.81;
r= 0.04;
%% 
A1= (M+m)*m*g*l/((M+m)*I+M*m*l^2);
B1= m*l/((M+m)*I+M*m*l^2);
A2= m^2*l^2*g/((M+m)*I+M*m*l^2);
B2= (I+ m*l^2)/ ((M+m)*I+M*m*l^2);


A= [0 1 0 0; A1 0 0 0; 0 0 0 1; -A2 0 0 0];
B= [0 -B1 0 B2]';
C= [1 0 0 0; 0 0 1 0];
%% Commande LQR 
Q= [200 0 0 0; 0 1 0 0; 0 0 150 0; 0 0 0 1];
R= 1;

K= lqr(A, B, Q, R)

%% Commande discret
Ad= eye(4)+ A*8*10^(-3);
Bd= B*8*10^(-3);

Kd= lqr(Ad, Bd, Q, R)