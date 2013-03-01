import numpy
import math

A = numpy.array([[4, -1, -1, 0],
                [-1, 4, 0 , -1],
                [-1, 0, 4, -1],
                [0, -1, -1, 4]])

alpha = math.sqrt(2)
r = (.5*alpha**2 - .5*A[0, 1]*alpha)**.5
w = numpy.array([[0],
    [(A[0, 1]-alpha)/(2*r)],
    [A[0, 2]/(2*r)],
    [0]])
P = numpy.identity(4) - 2*numpy.dot(w, w.T)
A2 = numpy.dot(P, numpy.dot(A, P))

alpha2 = -A2[3,1]
r2  = math.sqrt(.5*alpha2**2)
w2  = numpy.array([[0],[0],[-alpha2/(2*r2)], [A2[3,1]/(2*r2)]])
P2  = numpy.identity(4) - 2*numpy.dot(w2, w2.T)
A3  = numpy.dot(P2, numpy.dot(A2, P2))
