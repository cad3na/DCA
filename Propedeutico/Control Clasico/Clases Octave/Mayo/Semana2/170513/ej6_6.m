clear
clc
hold on;

num = [0 0 0 1];
den = conv([1 0], [1 4 5]);
sistema = tf(num, den)
raices = roots(den)
rlocus(sistema);
axis([-3 3 -3 3]);
grid off;
z1 = 0.5;
z2 = 1 / sqrt(2);
w1 = 0.5;
w2 = 1;
w3 = 2;
M1 = exp(-(z1 / sqrt(1 - z1^2)) * pi);
M2 = exp(-(z2 / sqrt(1 - z2^2)) * pi);

t = linspace(0, 2*pi, 100)';
x = 0; y = 0;
circsx = w1 .* cos(t) + x;
circsy = w1 .* sin(t) + y;
plot(circsx, circsy);
circsx = w2 .* cos(t) + x;
circsy = w2 .* sin(t) + y;
plot(circsx, circsy);
circsx = w3 .* cos(t) + x;
circsy = w3 .* sin(t) + y;
plot(circsx, circsy);
hold off;
print('grafica.png')

fprintf('Grafica del lugar geométrico de las raices.\nPresione enter para continuar.\n\n');
pause
close