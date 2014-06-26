function [ Ak, J, Al, bl, cl ] = retroalimentacioneInyecciondeSalida(A,b,c,d,tc,to)
%RETROALIMENTACIONEINYECCIONDESALIDA
%   Regresa valores de matrices asociadas a la representacion de estado
%   retroalimentada, asi como la matriz A del controlador y la forma de
%   Jordan de la matriz retroalimentada.
    I = eye(length(A));
    v0= zeros(1,length(A));
    %% Se calcula f para la retroalimentacion de estado
    f = [-tc^3 -3*tc^2 -3*tc];
    Af = A+ b*f;
    %% Se calcula k para la inyeccion de salida
    %  Primero se calcula la matriz en la forma observador con un cambio de
    %  base
    Ao = A';
    bo = c';
    co = b';
    %  Se calcula la matriz de observabilidad
    Obs = [c;c*A;c*A^2];
    Obso = [co;co*Ao;co*Ao^2];
    %  Se calcula la matriz de cambio de base para la forma observador
    To = Obs \ Obso;
    %  Se calcula k y A en la forma observador
    ko = [-to^3;-3*to^2;-3*to];
    Ako = Ao + ko*co;
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
    [Tj J] = jordan(Al);

end