#!/usr/bin/env python

from matplotlib.pyplot import plot, legend, savefig, gcf
from numpy import logspace, sqrt, log
from control import bode, tf

k = 3

G = tf([k], [1])
om = logspace(-2, 1, 500)

bode(G, dB=True, omega=om)

f=gcf()
r, mag, fas = f.get_children()
mag.set_yticks([20, 8.75*log(k), 0, -20])

fas.set_yticks([90, 0, -90])

mag.set_xticklabels([])
mag.set_yticklabels(['20.00', r'$k_{dB}$', '0.00', '-20.00'])
fas.set_xticklabels([])
#a.set_yticklabels([])

# Se guarda la figura en la misma carpeta
savefig("bodeordencero.pdf", bbox_inches='tight', pad_inches=0, transparent="True")
