%Estabilidad Nyquist
%	      k(s + 3)
% GH(s) = --------
%		  s(s - 1)
%

clear
clc
num = [1 3];
den = conv([1 -1],[1 0]);
GH = tf(num, den)
rlocus(GH)
axis([-8 1 -4 4]);
fprintf('Programa pausado. Presione enter para continuar\n');
pause;

k = 1;
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
axis([-3.5 0.5 -1.5 1.5]);
fprintf('Programa pausado. Presione enter para continuar\n');
pause;