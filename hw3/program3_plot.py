#! /usr/bin/env python

import pylab
import numpy

t = numpy.arange(0., 1.1, 0.001)
x = [0., 0.07, 0.15, 0.22, 0.31, 0.5, 0.6, 0.75, 0.83, 0.94, 1.00]
y = [0.2817, 1.0845, 1.5160, 2.0952, 2.4731, 2.7769, 2.8647, 2.9361, 2.8972, 2.9753, 3.0817]
pylab.plot(t, 0.308743 + 10.9645*t -15.5472*t*t + 7.35464*t*t*t)
pylab.plot(t, 0.576696 + 6.71764*t -4.45122*t*t)
pylab.plot(t, 1.16786 + 2.25996*t)
pylab.scatter(x, y)
pylab.show()
