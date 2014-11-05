#!/usr/bin/env python

from numpy import exp, abs, linspace, sin, cos, array, meshgrid, pi
from matplotlib.pyplot import Circle, gcf, text, plot, xticks, yticks, gca, axis, grid, savefig, quiver
from mpl_toolkits.mplot3d import Axes3D, art3d

a3d = gca(projection='3d')

o = array([0, 0, 0])
ex = array([10, 0, 0])
ey = array([0, 1, 0])
ez = array([0, 0, 1])

a3d.text(ex[0], ex[1] - 0.1, ex[2] - 0.1, r'$t$', fontsize=20)
a3d.text(ey[0] + 0.05, ey[1], ey[2], r'$x_1(t)$', fontsize=20)
a3d.text(ez[0], ez[1] - 0.05, ez[2] + 0.1, r'$x_2(t)$', fontsize=20)

xs, ys, zs = zip(o, ex)
plot(xs, ys, zs)
xs, ys, zs = zip(o, ey)
plot(xs, ys, zs)
xs, ys, zs = zip(o, ez)
plot(xs, ys, zs)

e = Circle((0, 0), 1, alpha=0.2)
d = Circle((0, 0), 0.333, alpha=0.2)
a3d.add_patch(e)
art3d.pathpatch_2d_to_3d(e, z=ex[0], zdir="x")
a3d.add_patch(d)
art3d.pathpatch_2d_to_3d(d, z=0, zdir="x")

t = linspace(0, 10, 100)

x = 0.125 - 0.025*t + 0.05*t*cos(t)
y = 0.1 + 0.05*t*sin(t)

plot(t, x, y)
a3d.scatter([t[0], t[99]], [x[0], x[99]], [y[0], y[99]])

a3d.quiver(10, cos(pi/4), cos(pi/4), 0, 1, 1, linewidth=3.8, alpha=0.3)
a3d.text(10, cos(pi/4) + 0.05, cos(pi/4) + 0.05, r'$\epsilon$', fontsize=20)
a3d.quiver(0, -cos(pi/4)*0.333, cos(pi/4)*0.333, 0, -1, 1, linewidth=3.8, alpha=0.3, length=0.333)
a3d.text(0, -cos(pi/4)*0.333 - 0.15, cos(pi/4)*0.333 + 0.15, r'$\delta(\epsilon)$', fontsize=20)

grid(False)
a = gca()
xticks([])
yticks([])
a.set_zticks([])
a.set_zlim3d([-0.7, 0.7])
a.set_ylim3d([-0.7, 0.7])
a.set_xlim3d([0, 10])
a.set_xticklabels([])
a.set_yticklabels([])
a.set_zticklabels([])
a.set_axis_off()
# Se guarda la figura en la misma carpeta
savefig("trayectoriaacotada3d.pdf", bbox_inches='tight', pad_inches=0, transparent="True")
