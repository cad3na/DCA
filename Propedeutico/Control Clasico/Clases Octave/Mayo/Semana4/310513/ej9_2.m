% Compensador de atraso de fase
%
%	            k s
% G(s) = ---------------------
%		  s(s + 1)(0.5 s +1)
%
% donde queremos que k = 5

clear
clc

w1 = logspace(-1, 2, 100);
w2 = logspace(0, 1, 100);
w3 = logspace(-1, 0, 100);

k = 5;
num = [0 1];
den = conv(conv([1 0], [1 1]), [0.5 1]);
G = tf(num, den)
kG = tf(k * num, den)

bode(G, w1)
grid on;
fprintf('Diagrama de Bode.\nPresione enter para continuar...\n\n');
pause;
clf;

margin(G)
grid on;
[MG, MF, wMG, wMF] = margin(G)
fprintf('Diagrama de Bode con lineas acotando los margenes de Fase y Magnitud.\nPresione enter para continuar\n\n');
pause;
clf;

bode(G, w2)
grid on;
fprintf('Acercamiento al diagrama de Bode.\nPresione enter para continuar...\n\n');
pause;
clf;

bode(G, w3)
grid on;
fprintf('Acercamiento a otra sección del diagrama de Bode.\nPresione enter para continuar...\n\n');
pause;
clf;

T = 10;
b = 10;
num = [T 1];
den = [b*T 1];
Gc = tf(num, den)
GcG = Gc * G

bode(GcG, w1)
grid on;
fprintf('Diagrama de Bode de la planta con el controlador.\nPresione enter para continuar...\n\n');
pause;
clf;

margin(GcG)
grid on;
[MG, MF, wMG, wMF] = margin(G)
fprintf('Diagrama de Bode con lineas acotando los margenes de Fase y Magnitud de la planta y el controlador.\nPresione enter para continuar\n\n');
pause;
clf;

bode(GcG, w2)
grid on;
fprintf('Acercamiento al diagrama de Bode de la planta y el controlador.\nPresione enter para continuar...\n\n');
pause;
clf;

bode(GcG, w3)
grid on;
fprintf('Acercamiento a otra sección del diagrama de Bode de la planta y el controlador.\nPresione enter para continuar...\n\n');
pause;
clf;

Gf = G / (1 + G)
kGf = kG / (1 + kG)
GcGf = G / (1 + GcG)
step(Gf, kGf, GcGf, tf(1,1))
axis([0 10 0 6]);
grid on;
fprintf('Respuesta al escalon unitario del sistema, el sistema con ganancia proporcional y el sistema con el controlador retroalimentados.\nPresione enter para continuar...\n\n');
pause;
clf;

rampa = tf([0 1], [1 0]);
Gf *= rampa;
kGf *= rampa;
GcGf *= rampa;
step(Gf, kGf, GcGf, rampa)
axis([0 20 0 20]);
grid on;
fprintf('Respuesta a la rampa unitaria del sistema, el sistema con ganancia proporcional y el sistema con el controlador retroalimentados.\nPresione enter para continuar...\n\n');
pause;

axis([0 10 0 10]);
grid on;
fprintf('Acercamiento a la respuesta a la rampa unitaria del sistema, el sistema con ganancia proporcional y el sistema con el controlador retroalimentados.\nPresione enter para continuar...\n\n');
pause;
clf;
close;