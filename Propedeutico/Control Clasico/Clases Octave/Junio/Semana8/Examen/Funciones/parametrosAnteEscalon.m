function [t_retraso, t_subida, t_pico, sobrepaso_max] = parametrosAnteEscalon(num, den)
%PARAMETROSANTEESCALON calcula parametros utiles de la respuesta de un
%sistema ante un escalon unitario
%   Devuelve tiempo de retraso, tiempo de subida, tiempo pico, sobrepaso
%   maximo, y como entradas pide, el numerador y denominador de la funcion
%   de transferencia del sistema.
    sistema = tf(num, den);
    [y,t] = step(sistema);
    maximo = length(t);

    i=1;
    while y(i) < 0.5001
        i = i + 1;
    end
    t_retraso = t(i);
    
    i=1;
    while y(i) < 1.0001
        i = i + 1;
    end
    t_subida = t(i);

    i=1;
    temp = 0;
    while i < maximo
        i = i + 1;
        if y(i) > 1 && temp > y(i)
            break
        end
        temp = y(i);
    end
    t_pico = t(i);
    
    sobrepaso_max = max(y) - 1;
    
    step(sistema)
end

