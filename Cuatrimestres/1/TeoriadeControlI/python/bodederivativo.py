#!/usr/bin/env python

from matplotlib.pyplot import plot, legend, savefig, gcf
from numpy import logspace
from control import bode, tf

G = tf([1, 0], [0, 1])
om = logspace(-2, 2, 100)

bode(G, dB=True, omega=om)

f=gcf()
r, mag, fas = f.get_children()

mag.set_yticks([20, 0, -20])

fas.set_yticks([45, 90, 135])

mag.set_xticklabels([])
fas.set_xticklabels(['',r'$\frac{1}{100}$', r'$\frac{1}{10}$', r'$1$', r'$10$', r'$100$'])
#a.set_yticklabels([])

# Se guarda la figura en la misma carpeta
savefig("bodederivativo.pdf", bbox_inches='tight', pad_inches=0, transparent="True")
