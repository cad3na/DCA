clear
clc
num = [0 1 2 3];
den = [1 3 3 1];
[r, p, k] = residue(num, den)
fprintf('El residuo de 2 polinomios.\nPresione enter para continuar.\n\n');
pause

clear
clc
t = [0:0.2:10];
zeta = [0 0.2 0.4 0.6 0.8 1];
num = [0 0 1];
for n = 1:6
    den = [1 2*zeta(n) 1];
    sistema = tf(num, den);
    [y(1:51, n), t, x] = step(sistema, t);
    pause
end

plot(y,t)
plot(t,y)
grid
fprintf('La grafica de respuestas a escalon unitario de sistemas con diferente coeficiente de amortiguamiento.\nPresione enter para continuar.\n\n');
pause
clc

num = [0 0 25];
den = [1 6 25];
sistema = tf(num, den)
t = 0:0.005:5;
[y, t, x] = step(sistema, t);
plot(t, y);
grid
fprintf('Grafica de la respuesta temporal de un sistema de 2o orden.\nPresione enter para continuar.\n\n');
pause
clc

close