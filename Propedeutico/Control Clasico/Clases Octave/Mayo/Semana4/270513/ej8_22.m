%
%
%	            20(s + 1)
% GH(s) = ---------------------
%		  s(s + 5)(s^2 + s +10)
%

clear
clc
num = 20 * [1 1];
den = conv(conv([1 0], [1 5]), [1 2 10]);
G = tf(num, den)
w = logspace(-1,2,100);
bode(G,w)
grid on;
[Mg Mf wMg wMf] = margin(G);
MgdB = 20*log10(Mg);
datos = [MgdB wMg Mf wMf]
fprintf('Programa pausado. Presione enter para continuar\n');
pause;

ww = 0.1:0.1:100;
nyquist(G)
axis([-1 0.4 -1.5 1.5]);
fprintf('Programa pausado. Presione enter para continuar\n');
pause;