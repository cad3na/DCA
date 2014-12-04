#!/usr/bin/env python

from matplotlib.pyplot import plot, text, axis, grid, gca, xticks, yticks, savefig
from numpy import exp, abs, linspace, sin

x = linspace(0, 1.2, 200)
fun = exp(-4.5*x)*(1-sin(13*x))
exp = exp(-3*x) + 0.1

plot(x, fun)
plot(x, exp)

text(0.22, 0.15, r'$\xi(t)$', fontsize=28)
text(0.425, 0.425, r'$k e^{-\alpha t}$', fontsize=28)

axis([-0.2, 1.2, -0.2, 1.2])
grid(True)
xticks([0])
yticks([0])
a = gca()
a.set_xticklabels([])
a.set_yticklabels([])

# Se guarda la figura en la misma carpeta
savefig("trayectoriafiltrada.pdf", bbox_inches='tight', pad_inches=0, transparent="True")
