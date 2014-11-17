#!/usr/bin/env python

from matplotlib.pyplot import plot, legend, savefig, gcf
from numpy import logspace, sqrt
from control import bode, tf

z   = 0.075
w_n = 1

mr = 1/(2*z*sqrt(1-z**2))

G = tf([0 ,0, 1], [1/w_n**2, 2*z/w_n, 1])
om = logspace(-2, 1, 500)

bode(G, dB=True, omega=om)

f=gcf()
r, mag, fas = f.get_children()
p1, = mag.plot([0, 0.1, 1, 10], [0, 0, 0, -40], '--')
fas.plot([0, 0.1, 1, 10], [0, 0, -90, -180], '--')

mag.set_yticks([20, mr, 0, -20, -40])

fas.set_yticks([0, -90, -180])

mag.legend([p1], ['asintotas'])
mag.set_xticklabels([])
mag.set_yticklabels(['20.00', r'$M_r$', '0.00', '-20.00', '-40.00'])
fas.set_xticklabels(['',r'$\frac{\omega_n}{100}$', r'$\frac{\omega_n}{10}$', r'$\omega_n$', r'$10 \omega_n$'])
#a.set_yticklabels([])

# Se guarda la figura en la misma carpeta
savefig("bodesegundoorden.pdf", bbox_inches='tight', pad_inches=0, transparent="True")
