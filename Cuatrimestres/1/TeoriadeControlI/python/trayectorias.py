#!/usr/bin/env python

from matplotlib.pyplot import plot, text, axis, grid, gca, xticks, yticks, savefig, legend
from numpy import exp, abs, linspace, sin, pi

x = linspace(0, 0.8, 200)
par = -x**2 + x + 0.25
fun1 = par + (sin(8*pi*x/0.8)/18)
fun2 = par + (sin(14*pi*x/0.8)/60)
fun3 = par + (sin(10*pi*x/0.8)/10)

p1, = plot(x, par)
p2, = plot(x, fun1)
p3, = plot(x, fun2)
p4, = plot(x, fun3)
p5, = plot([x[0], x[199]], [par[0], par[199]], "o")

legend([p1, p2, p3, p4, p5], [r'$v(t)$', r'$v(\alpha_1, t)$', r'$v(\alpha_2, t)$', r'$v(\alpha_3, t)$', r'$\eta(t_1) = \eta(t_2) = 0$'], fontsize=20)

axis([-0.1, 1.05, -0.1, 1.05])
grid(True)
xticks([0])
yticks([0])
a = gca()
a.set_xticklabels([])
a.set_yticklabels([])

# Se guarda la figura en la misma carpeta
savefig("trayectorias.pdf", bbox_inches='tight', pad_inches=0, transparent="True")
