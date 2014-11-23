#!/usr/bin/env python

from matplotlib.pyplot import plot, text, axis, grid, gca, xticks, yticks, savefig, quiver
from numpy import exp, abs, linspace, sin, array, pi, cos, meshgrid

x = linspace(-1, 1, 300)
h = lambda r: (r**2 - 1)**2
y = h(x)

plot(x, y)

v0 = array([0, 1])
eta = array([0.2, h(0.2) - 1])

xs, ys = zip(v0 - eta, v0, v0+eta, v0 + 2*eta)
plot(xs, ys)

xs, ys = zip(v0, v0+eta)
plot(xs, ys, "o")

quiver(v0[0], v0[1], eta[0], eta[1], angles='xy', scale_units='xy', linewidth=2, alpha=0.3, scale=1)
quiver(v0[0], v0[1], eta[0], eta[1], angles='xy', scale_units='xy', linewidth=2, alpha=0.3, scale=4, color="b")
#quiver([v0[0], v0[1], (v0 + eta)[0], (v0 + eta)[1]], angles='xy', scale_units='xy', scale=1)

text(v0[0] + 0.0125, v0[1] + 0.0125, r'$f_1(v_0)$', fontsize=28)
text(v0[0] + eta[0] + 0.0125, v0[1] + eta[1] + 0.0125, r'$f_1(v_0 + \alpha \eta)$', fontsize=28)
text(v0[0] + 0.0125, v0[1] + eta[1] + 0.0125, r'$f_1(v_0 + \alpha \eta) - f_1(v_0)$', fontsize=28)
text(v0[0] + 0.075, v0[1] - 0.0075, r'$\frac{f_1(v_0 + \alpha \eta) - f_1(v_0)}{\alpha}$', fontsize=28)

axis([-0.05, 0.3, 0.9, 1.025])
grid(True)
xticks([0])
yticks([0])
a = gca()
a.set_xticklabels([])
a.set_yticklabels([])

# Se guarda la figura en la misma carpeta
savefig("trayectoriaderivada.pdf", bbox_inches='tight', pad_inches=0, transparent="True")
