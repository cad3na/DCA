#!/usr/bin/env python

from pylab import *
from numpy import exp, abs

beta = 1.5
T = 0.25

cero = -1/T
polo = -1/(beta*T)

plot(polo, 0, "x")
plot(cero, 0, "o")

plt.text(cero - 0.4, -0.2, r'$- \frac{1}{T}$', fontsize=28)
plt.text(polo - 0.4, -0.2, r'$- \frac{1}{\beta T}$', fontsize=28)

axis([-6, 2, -0.6, 0.6])
grid(True)
xticks([0])
yticks([0])
a = gca()
a.set_xticklabels([])
a.set_yticklabels([])

# Se guarda la figura en la misma carpeta
savefig("atrasopoloycero.pdf", bbox_inches='tight', pad_inches=0, transparent="True")
