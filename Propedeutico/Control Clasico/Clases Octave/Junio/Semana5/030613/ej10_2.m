
clear
clc

num = [0 0 0 1.2];
den = [0.36 1.86 2.5 1];
G = tf(num, den);

t = 0:0.01:8;
for k = 5:-0.2:2
	for a = 1.5:-0.2:0.5
		num = k * [1 2*a a^2];
		den = [0 1 0];
		Gc = tf(num, den);


fprintf('Diagrama de Bode. Presione enter para continuar...\n');
pause;