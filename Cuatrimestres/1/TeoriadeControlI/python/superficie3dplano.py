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

rho = sqrt(eta[0]**2 + eta[1]**2 + eta[2]**2)

point0 = array([1 + rho, 1 - rho, h(rho)])
normal = array([1, -1, 1])

d = -point0.dot(normal)

x = linspace(1.125, 1.375, 100)
y = linspace(0.625, 0.875, 100)

xx, yy = np.meshgrid(x, y)
z = (-normal[0] * xx - normal[1] * yy - d) * 1. /normal[2]

a3d = gca(projection='3d')
a3d.plot_surface(xx, yy, z, alpha=0.25, color="r")
a3d.plot_surface(X, Y, Z, alpha=0.35)
#
o = array([0, 0, 0])
ex = array([1.75, 0, 0]) + o
ey = array([0, 1.75, 0]) + o
ez = array([0, 0, 1.0]) + o

xs, ys, zs = zip(o, ex)
plot(xs, ys, zs)
xs, ys, zs = zip(o, ey)
plot(xs, ys, zs)
xs, ys, zs = zip(o, ez)
plot(xs, ys, zs)

xs, ys, zs = [v0[0] + eta[0]], [v0[1] + eta[1]], [h(sqrt(eta[0]**2 + eta[1]**2+ eta[2]**2))]
a3d.scatter(xs, ys, zs)

xs1, ys1, zs1 = zip([0, v0[1] + eta[1], 0], v0 + eta, [v0[0] + eta[0], 0, 0])
plot(xs1, ys1, zs1, "--")
plot([xs[0], xs1[1]], [ys[0], ys1[1]], [zs[0], zs1[1]], "--")

a3d.quiver(xs[0] + 0.2, ys[0] - 0.2, zs[0] + 0.2, 1, -1, 1, linewidth=2, alpha=1, length=0.35)
a3d.quiver(xs[0] + 0.14, ys[0] - 0.14, zs[0] - 0.14, 1, -1, -1, linewidth=2, alpha=1, length=0.25)

a3d.text(v0[0] + eta[0] - 0.025, v0[1] + eta[1] - 0.1, zs[0], r'$\mathcal{G}(v_0)$', fontsize=20)
a3d.text(v0[0] + eta[0] + 0.05, v0[1] + eta[1] + 0.1, zs[0], r'$\nabla_v \mathcal{G}(v_0)$', fontsize=20)
a3d.text(v0[0] + eta[0] + 0.175, v0[1] + eta[1] - 0.2, zs[0], r'$\frac{d R(t)}{dt}$', fontsize=20)

grid(False)
a = gca()
xticks([])
yticks([])
a.set_zticks([])
a.set_zlim3d([0.5, 1])
a.set_ylim3d([0.75, 1.25])
a.set_xlim3d([0.75, 1.25])
a.set_xticklabels([])
a.set_yticklabels([])
a.set_zticklabels([])
a.set_axis_off()

# Se guarda la figura en la misma carpeta
savefig("superficie3dplano.pdf", bbox_inches='tight', pad_inches=0, transparent="True")
