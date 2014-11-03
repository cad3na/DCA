#!/usr/bin/env python

from pylab import *
from numpy import exp, abs, meshgrid, linspace, array, sin, cos, pi
from mpl_toolkits.mplot3d import Axes3D

point0 = array([0, 0, 0])
point1 = array([0.5, 0.5, 0.5])
point2 = array([1, 1, 1])
normal = array([1, 0, 0])

d0 = -point0.dot(normal)
d1 = -point1.dot(normal)
d2 = -point2.dot(normal)

y = linspace(0, 1, 100)
z = linspace(0, 1, 100)
yy, zz = meshgrid(y, z)

x0 = (-normal[1] * yy - normal[2] * zz - d0) * 1. /normal[0]
x1 = (-normal[1] * yy - normal[2] * zz - d1) * 1. /normal[0]
x2 = (-normal[1] * yy - normal[2] * zz - d2) * 1. /normal[0]

a3d = gca(projection='3d')
a3d.plot_surface(x0, yy, zz, alpha=0.15)
a3d.plot_surface(x1, yy, zz, alpha=0.15)
a3d.plot_surface(x2, yy, zz, alpha=0.15)

o = array([0, 0, 0])
ex = array([1, 0, 0])
ey = array([0, 1, 0])
ez = array([0, 0, 1])

a3d.text(ex[0], ex[1] - 0.1, ex[2], r'$t$', fontsize=20)
a3d.text(ey[0] + 0.05, ey[1], ey[2], r'$x_1(t)$', fontsize=20)
a3d.text(ez[0], ez[1] - 0.05, ez[2] + 0.1, r'$x_2(t)$', fontsize=20)

xs, ys, zs = zip(o, ex)
plot(xs, ys, zs)
xs, ys, zs = zip(o, ey)
plot(xs, ys, zs)
xs, ys, zs = zip(o, ez)
plot(xs, ys, zs)

xs = linspace(0, 1, 100)
ys = exp(-4.5*xs)*(1-sin(15*xs)/4)
zs = exp(-4.5*xs)*(1-sin(7*xs)/4)

plot(xs, ys, zs)
a3d.scatter([xs[0], xs[50], xs[99]], [ys[0], ys[50], ys[99]], [zs[0], zs[50], zs[99]])

a3d.text(xs[0], ys[0] + 0.05, zs[0], r'$x_0$', fontsize=20)
a3d.text(xs[99], ys[99] - 0.2, zs[99], r'$t \to \infty$', fontsize=20)
a3d.text(xs[50], ys[50] - 0.2, zs[50], r'$x^*$', fontsize=20)

xs = linspace(0, 1, 100)
ys = exp(-0.4-4*xs)*(1-sin(9*xs)/4)
zs = exp(-0.4-4*xs)*(1-sin(11*xs)/4)

plot(xs, ys, zs)
a3d.scatter([xs[0], xs[50], xs[99]], [ys[0], ys[50], ys[99]], [zs[0], zs[50], zs[99]])

a3d.text(xs[99], ys[99] + 0.1, zs[99], r'$\lambda_{\infty} = 0$', fontsize=20)
a3d.text(xs[50], ys[50] + 0.1, zs[50], r'$\lambda^*$', fontsize=20)

grid(False)
a = gca()
xticks([])
yticks([])
a.set_zticks([])
a.set_zlim3d([0, 1])
a.set_ylim3d([0, 1])
a.set_xlim3d([0, 1])
a.set_xticklabels([])
a.set_yticklabels([])
a.set_zticklabels([])
a.set_axis_off()

# Se guarda la figura en la misma carpeta
savefig("trayectorias3d.pdf", bbox_inches='tight', pad_inches=0, transparent="True")
