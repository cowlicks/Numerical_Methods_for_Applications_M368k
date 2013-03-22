#! /usr/bin/env python
import numpy
A = numpy.array([[1, 1, 0, 0],
                [1, 2, 0, 1],
                [0, 0, 3, 3],
                [0, 1, 3, 2]])
lam = 5.6658
v1  = numpy.array([[0.0621], [0.2897], [1.1254], [1]])
x   = 1/(lam*v1[0]) * A[0]
x   = x.reshape((4, 1))

B   = A - lam* numpy.dot(v1, x.T)
C   = B[1:, 1:]
