%Estabilidad Nyquist
%				  k
% GH(s) = -------------------
%		  s(T1 s +1)(T2 s +1)
%
%donde T1 = 1 y T2 = 2

clear
clc
T1 = 1;
T2 = 2;
num = [0 0 1];
den = conv(conv([T1 1],[T2 1]),[1 0]);
GH = tf(num, den)
rlocus(GH)
axis([-1.5 0.5 -1.5 1.5]);
fprintf('Programa pausado. Presione enter para continuar\n');
pause;

k = (T1 + T2)/(T1 * T2);
kp = k / 2;
kg = 2 * k;
nump = kp * num;
numg = kg * num;
w = logspace(-2, 3, 100);
GHp = tf(nump, den)
bode(GHp, w)
fprintf('Programa pausado. Presione enter para continuar\n');
pause;

nyquist(GHp)
axis([-1.5 0.5 -1.5 1.5]);
fprintf('Programa pausado. Presione enter para continuar\n');
pause;

GHg = tf(numg,den)
bode(GHg, w)
fprintf('Programa pausado. Presione enter para continuar\n');
pause;

nyquist(GHg)
axis([-1.5 0.5 -1.5 1.5]);
fprintf('Programa pausado. Presione enter para continuar\n');
pause;