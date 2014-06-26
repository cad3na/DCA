%Compensador de red de adelanto
%
%	      a(Ts + 1)
% Gc(s) = ---------
%		  (aTs + 1)
%

clear
clc
a = 0.1
T = 1
num = a * [T 1];
den = [a*T 1];
Gc = tf(num, den)
w = 0.1:0.1:10000;
nyquist(Gc,w)
axis([0 1 -0.5 0.5]);
fprintf('Programa pausado. Presione enter para continuar\n');
%pause;
clf;

w = logspace(-1,2,100);
bode(Gc,w)
grid on;
fiM = (180 / pi) * asin((1 - a) / (1 + a))
wM = 1 / (T * sqrt(a))
fprintf('Programa pausado. Presione enter para continuar\n');
%pause;
clf;

a = 1/4
T = 1
num = a * [T 1];
den = [a*T 1];
Gc = tf(num, den)
bode(Gc,w)
grid on;
fiM = (180 / pi) * asin((1 - a) / (1 + a))
wM = 1 / (T * sqrt(a))
fprintf('Programa pausado. Presione enter para continuar\n');
%pause;
clf;

a = (sqrt(2) - 1) / (sqrt(2) + 1)
T = 1
num = a * [T 1];
den = [a*T 1];
Gc = tf(num, den)
bode(Gc,w)
grid on;
fiM = (180 / pi) * asin((1 - a) / (1 + a))
wM = 1 / (T * sqrt(a))
fprintf('Programa pausado. Presione enter para continuar\n');
%pause;
clf;