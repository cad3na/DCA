%% Ejemplo de asignacion de polos con observacion de estado
%% Se inicializan las variables simbolicas
clear
clc
syms s
%% Se describe el sistema en su representacion de estado
I = eye(3);
v0= zeros(1,3);

A = [0 1 0;
     0 0 1;
     0 0 0];
b = [0;0;1];
c = [-1 0 1];
x0= [1;0;0];
%% Se inicializan las variables con las que se crearan los polos para el controloador y el observador
tc = 1;
to = 10;
%% Se calcula f para la retroalimentacion de estado
f = [-tc^3 -3*tc^2 -3*tc];
Af = A+ b*f;
% Se muestra el polinomio caracteristico con esta retroalimentacion de
% estado
factor(det(s*I - Af))
%% Se calcula k para la inyeccion de salida
%  Primero se calcula la matriz en la forma observador con un cambio de
%  base
Ao = A';
co = b';
bo = c';
%  Se calcula la matriz de observabilidad
Obs = [c;c*A;c*A^2];
Obso = [co;co*Ao;co*Ao^2];
%  Se calcula la matriz de cambio de base para la forma observador
To = Obs \ Obso;
%  Se calcula k y A en la forma observador
ko = [-to^3;-3*to^2;-3*to];
Ako = Ao + ko*co;
%  Se muestra el polinomio caracteristico con la inyeccion de salida
factor(det(s*I - Ako))
%  Se calcula k y A en la forma normal
k = To*ko;
Ak = A + k*c;
%% Se calcula el sistema retroalimentado
%  Se calcula el sistema en lazo cerrado
Al = [A     b*f;
      -k*c  Af+k*c];
bl = [b;b];
cl = [c v0];
%% Se calcula la forma de Jordan del sistema en Lazo Cerrado
[Tj J] = jordan(Al)