#!/usr/bin/env python

from pylab import *
from matplotlib import style

style.use("fivethirtyeight")

# create some data to use for the plot
dt = 0.001
t = arange(0.0, 10.0, dt)
r1 = exp(-t[:1000]/0.05)
r2 = exp(t[:1000]/0.05)


# the main axes is subplot(111) by default
plot(-5, 0, "x")
plot([-2.5, -2.5], [2.5, -2.5], "x")
plot(0, 0, "x")
plot([0, 0], [2.5, -2.5], "x")
plot([2.5, 2.5], [2.5, -2.5], "x")
plot(5, 0, "x")
axis([-6, 6, -6, 6 ])
title('Plano complejo')
#grid(False)
xticks([0])
yticks([0])
#xticklabels([])
#yticklabels([])

# this is another inset axes over the main axes
a = axes([0.1, 0.5, 0.1, 0.1])
plot(t[:len(r1)], r1,)
grid(True)
setp(a, xlim=(-0.05, 0.2), ylim=(-0.05, 1),
    xticks=[0], yticks=[0],
    xticklabels=[], yticklabels=[])

# this is another inset axes over the main axes
a = axes([0.8, 0.5, 0.1, 0.1])
plot(t[:len(r2)], r2)
setp(a, xlim=(-0.05, 0.2), ylim=(-0.05, 1),
    xticks=[0], yticks=[0],
    xticklabels=[], yticklabels=[])

show()
