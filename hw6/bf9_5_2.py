#! /usr/bin/env python
import math
import numpy

A = numpy.array([[3., 1., 0.],
                [1., 4., 2.],
                [0., 2., 3.]])
t1 = math.atan(1./3.)
P1 = numpy.array([[math.cos(t1), math.sin(t1), 0],
                [-math.sin(t1), math.cos(t1), 0],
                [0, 0,  1,]])

A2 = numpy.dot(P1, numpy.dot(A, P1.T))

t2 = math.atan(A2[2,1]/A2[1,1])
P2 = numpy.array([[1., 0, 0],
                [0, math.cos(t2), math.sin(t2)],
                [0, -math.sin(t2), math.cos(t2)]])

A3 = numpy.dot(P2, numpy.dot(A2, P2.T))

t1_2 = math.atan(A3[1,0]/A3[0,0])
P1_2 = numpy.array([[math.cos(t1_2), math.sin(t1_2), 0],
                    [-math.sin(t1_2), math.cos(t1_2),0],
                    [0, 0, 1]])
A2_2 = numpy.dot(P1_2, numpy.dot(A3, P1_2.T))

t2_2 = math.atan(A2_2[2,1]/A2[1,1])
P2_2 =  numpy.array([[1, 0, 0],
                    [0, math.cos(t2_2), math.sin(t2_2)],
                    [0, -math.sin(t2_2), math.cos(t2_2)]])
A3_2 = numpy.dot(P2_2, numpy.dot(A2_2, P2_2))
