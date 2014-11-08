#!/usr/bin/env python

from matplotlib.pyplot import plot, legend, savefig, gcf
from numpy import logspace
from control import bode, tf

T=1

G = tf([T, 1], [0, 1])
om = logspace(-2, 2, 100)

bode(G, dB=True, omega=om)

f=gcf()
r, mag, fas = f.get_children()
p1, = mag.plot([0, 0.1, 1, 10, 100], [0, 0, 0, 20, 40], '--')
fas.plot([0, 0.1, 1, 10, 100], [0, 0, 45, 90, 90], '--')

mag.set_yticks([0, 3, 10, 20, 40])

fas.set_yticks([0, 45, 90])

mag.legend([p1], ['asintotas'])
mag.set_xticklabels([])
fas.set_xticklabels(['',r'$\frac{1}{100 T}$', r'$\frac{1}{10 T}$', r'$\frac{1}{T}$', r'$\frac{10}{T}$', r'$\frac{100}{T}$'])
#a.set_yticklabels([])

# Se guarda la figura en la misma carpeta
savefig("bodeprimerordeninverso.pdf", bbox_inches='tight', pad_inches=0, transparent="True")
