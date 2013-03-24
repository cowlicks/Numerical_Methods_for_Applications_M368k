import math
import numpy


class two:
    def __init__(self):
        self.j0 = numpy.array([
                    [10, 1, 0],
                    [1, -4, 0],
                    [1, 1, 1]])
        
        self.x0 = numpy.array([[5],[2],[0]])

    def f(self, x):
        return numpy.array([[float(x[0]**2 + x[1] - 37)],
                            [float(x[0] - x[1] - 5)],
                            [float(x[0] + x[1] + x[2] - 3)]])
    def first_step(self, x0, j, F):
        return x0 - numpy.dot(numpy.linalg.inv(j), F(x0))

    def step(self, x, j, f):
        return x - numpy.dot(j,f)
    
    def A(self, A0, x0, x1, F):
        y   = F(x1) - F(x0)
        s   = x1 - x0
        snorm = 0
        for i in s:
            snorm += i**2
        snorm = math.sqrt(snorm)
        return A0 + numpy.dot(y - numpy.dot(A0, s), s.T)/snorm
