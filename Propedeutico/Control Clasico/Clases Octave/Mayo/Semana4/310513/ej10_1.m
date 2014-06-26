%
%

clear
clc

num = [0 0 1];
den = conv(conv([1 1], [1 5]), [1 0]);
G = tf(num, den)
rlocus(G)
axis([-10 10 -15 15]);
fprintf('Funcion de transferencia de la planta a controlar y grafica de su lugar geométrico.\nPresione enter para continuar...\n\n');
pause;
clf;

close;