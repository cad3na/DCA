function dydt = f(t, y, Z)
    yret1 = Z(:, 1);
    yret2 = Z(:, 2);
    
    dydt = -3*y + yret1(1) + yret2(1);
end
