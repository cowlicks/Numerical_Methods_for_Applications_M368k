import math
import numpy

class one:
    def __init__(self):
        self.h = 0.5
        self.x0 = numpy.array([[0],[0]])
        self.x1 = numpy.array([[0.5], [0.75]])

    def j(self, x):
        x0 = float(x[0])
        x1 = float(x[1])

        f = numpy.array([[2*x0, -2*x1 + 2],
                         [2,    2*x1]])
        return f

    def f(self, x):
        x0 = float(x[0])
        x1 = float(x[1])

        f = numpy.array([[x0**2 - x1**2 + 2*x1],
                        [2*x0 + x1**2 - 6]])
        return f

class two:
    def __init__(self):
        self.h = 1.0
        self.x = numpy.array([[3],[-2]])

    def f(self, h, x):
        x0 = float(x[0])
        x1 = float(x[1])

        j = numpy.array([[2*x0, -2*x1 + 2],
                        [2, 2*x1]])
        f = numpy.array([[x0**2 - x1**2 + 2*x1],
                        [x0**2 - x1 + 2*x1]])
        return -numpy.dot(numpy.linalg.inv(j),f)
