#!/usr/bin/env python

from numpy import exp, abs, linspace, sin, cos
from matplotlib.pyplot import Circle, gcf, text, plot, xticks, yticks, gca, axis, grid, savefig, quiver

e = Circle((0, 0), 3, alpha=0.2)
d = Circle((0, 0), 1, alpha=0.2)
a = gca()
a.add_artist(e)
a.add_artist(d)

t = linspace(0, 10, 100)

x = 0.15 - 0.075*t + 0.1*t*cos(t)
y = 0.175*t*sin(t)

plot(x, y)
plot([x[0], x[99]], [y[0], y[99]], "o")

text(x[0] - 0.4, y[0] - 0.2, r'$x_0$', fontsize=28)
text(x[99] - 0.4, y[99] - 0.4, r'$x(t)$', fontsize=28)

quiver(0, 0, 1, 1, scale=15.1, linewidth=3.8, alpha=0.3)
quiver(0, 0, -3, 3, scale=15.1, linewidth=3.8, alpha=0.3)

text(-2 - 0.4, 2 + 0.25, r'$\epsilon$', fontsize=28)
text(1 - 0.2, 1 - 0.2, r'$\delta(\epsilon)$', fontsize=28)

axis([-5.5, 5.5, -4, 4])
grid(True)
xticks([0])
yticks([0])
a.set_xticklabels([])
a.set_yticklabels([])

# Se guarda la figura en la misma carpeta
savefig("trayectoriaacotada.pdf", bbox_inches='tight', pad_inches=0, transparent="True")
