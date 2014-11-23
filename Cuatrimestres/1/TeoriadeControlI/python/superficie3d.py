#!/usr/bin/env python

from pylab import *
from numpy import exp, abs, meshgrid, linspace, array, sin, cos, pi, sqrt
from mpl_toolkits.mplot3d import Axes3D

v0 = array([1, 1, 0])
eta = array([0.2, -0.2, 0])

r = linspace(0, 1, 300)
p = linspace(0, 2*pi, 300)
R, P = meshgrid(r, p)

f = lambda r, p: r*cos(p) + 1
g = lambda r, p: r*sin(p) + 1
h = lambda r: (r**2 - 1)**2

X, Y, Z = f(R, P), g(R, P), h(R)

a3d = gca(projection='3d')
a3d.plot_surface(X, Y, Z, alpha=0.15)

o = array([0, 0, 0])
ex = array([1.75, 0, 0]) + o
ey = array([0, 1.75, 0]) + o
ez = array([0, 0, 1.0]) + o

a3d.text(ex[0] + 0.1, ex[1], ex[2], r'$v_1$', fontsize=20)
a3d.text(ey[0] + 0.05, ey[1], ey[2], r'$v_2$', fontsize=20)
a3d.text(ez[0], ez[1] - 0.05, ez[2] + 0.1, r'$f_1(v)$', fontsize=20)

xs, ys, zs = zip(o, ex)
plot(xs, ys, zs)
xs, ys, zs = zip(o, ey)
plot(xs, ys, zs)
xs, ys, zs = zip(o, ez)
plot(xs, ys, zs)

xs, ys, zs = [v0[0], v0[0] + eta[0]], [v0[1], v0[1] + eta[1]], [v0[2] + 1, h(sqrt(eta[0]**2 + eta[1]**2+ eta[2]**2))]
a3d.scatter(xs, ys, zs)

xs1, ys1, zs1 = zip([0, v0[1], 0], v0, [v0[0], 0, 0])
plot(xs1, ys1, zs1, "--")
plot([xs[0], xs1[1]], [ys[0], ys1[1]], [zs[0], zs1[1]], "--")

xs1, ys1, zs1 = zip([0, v0[1] + eta[1], 0], v0 + eta, [v0[0] + eta[0], 0, 0])
plot(xs1, ys1, zs1, "--")
plot([xs[1], xs1[1]], [ys[1], ys1[1]], [zs[1], zs1[1]], "--")

a3d.quiver( o[0] + eta[0],  o[0] + eta[1],  o[0] + eta[2], 1, -1, 0, linewidth=2, alpha=0.3, length=0.3)
a3d.quiver(v0[0] + eta[0], v0[1] + eta[1], v0[2] + eta[2], 1, -1, 0, linewidth=2, alpha=0.3, length=0.3)

a3d.text( o[0] + eta[0] + 0.05,  o[0] + eta[1],         o[0] + eta[2], r'$\eta$', fontsize=20)
a3d.text(v0[0] + eta[0] + 0.1,  v0[1] + eta[1] - 0.05, v0[2] + eta[2], r'$v_0 + \alpha \eta$', fontsize=20)
a3d.text(v0[0] - 0.05,          v0[1] + 0.1,           v0[2] , r'$v_0$', fontsize=20)
a3d.text(v0[0],                 v0[1] + 0.05,          v0[2] + 1, r'$f_1(v_0)$', fontsize=20)
a3d.text(v0[0] + eta[0],        v0[1] + eta[1] + 0.05, zs[1], r'$f_1(v_0 + \alpha \eta)$', fontsize=20)

grid(False)
a = gca()
xticks([])
yticks([])
a.set_zticks([])
a.set_zlim3d([0, 1])
a.set_ylim3d([0, 2])
a.set_xlim3d([0, 2])
a.set_xticklabels([])
a.set_yticklabels([])
a.set_zticklabels([])
a.set_axis_off()

# Se guarda la figura en la misma carpeta
savefig("superficie3d.pdf", bbox_inches='tight', pad_inches=0, transparent="True")
