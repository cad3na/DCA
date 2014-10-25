#!/usr/bin/env python

from pylab import *
from numpy import exp, abs

dt = 0.001
t = arange(0.0, 1.0, dt)
r1 = exp(-t/0.05)
r2 = exp(t/0.05)
r3 = exp((-2+10j)*t/0.05).real
r4 = exp((2+10j)*t/0.05).real
r5 = exp((10j)*t/0.05).real
r6 = [1 for i in t]

# Grafica principal del plano complejo
plot(-4, 0, "x")
plot([-2, -2], [2, -2], "x")
plot(0, 0, "x")
plot([0, 0], [2, -2], "x")
plot([2, 2], [2, -2], "x")
plot(4, 0, "x")

axis([-5.5, 5.5, -4, 4])
grid(True)
xticks([0])
yticks([0])
a = gca()
a.set_xticklabels([])
a.set_yticklabels([])

# Grafica de comportamiento completamente amortiguado
a = axes([0.18, 0.55, 0.1, 0.1])
plot(t, r1)
grid(True)
setp(a, xlim=(-0.02, 0.20), ylim=(-1.25, 1.25),
    xticks=[0], yticks=[0],
    xticklabels=[], yticklabels=[])

# Grafica de comportamiento exponencial
a = axes([0.75, 0.55, 0.1, 0.1])
plot(t, r2)
setp(a, xlim=(-0.01, 0.10), ylim=(-5, 5),
    xticks=[0], yticks=[0],
    xticklabels=[], yticklabels=[])

# Grafica de comportamiento sobreamortiguado
a = axes([0.32, 0.15, 0.1, 0.1])
plot(t, r3)
setp(a, xlim=(-0.01, 0.1), ylim=(-1.25, 1.25),
    xticks=[0], yticks=[0],
    xticklabels=[], yticklabels=[])

# Grafica de comportamiento subamortiguado
a = axes([0.62, 0.15, 0.1, 0.1])
plot(t, r4)
setp(a, xlim=(-0.01, 0.1), ylim=(-15, 15),
    xticks=[0], yticks=[0],
    xticklabels=[], yticklabels=[])

# Grafica de comportamiento subamortiguado
a = axes([0.45, 0.75, 0.1, 0.1])
plot(t, r5)
setp(a, xlim=(-0.01, 0.1), ylim=(-1.25, 1.25),
    xticks=[0], yticks=[0],
    xticklabels=[], yticklabels=[])

# Grafica de comportamiento subamortiguado
a = axes([0.55, 0.45, 0.1, 0.1])
plot(t, r6)
setp(a, xlim=(-0.01, 0.1), ylim=(-1.25, 1.25),
    xticks=[0], yticks=[0],
    xticklabels=[], yticklabels=[])

# Se guarda la figura en la misma carpeta
savefig("planocomplejo.pdf", bbox_inches='tight', pad_inches=0, transparent="True")
