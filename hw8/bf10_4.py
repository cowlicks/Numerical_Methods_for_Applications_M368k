import math
import numpy

class one:
    def __init__(self):
        self.x0 = numpy.array([[1.],[ 1.5]])

    def g(self, x):
        return float((3*x[0]**2 - x[1]**2)**2 + (3*x[0]*x[1]**2 - x[0]**3 - 1)**2)

    def dg(self, x):
        x0 = float(x[0])
        x1 = float(x[1])
        a   = 2*(3*x0**2 - x1**2)*(6*x0) + 2*(3*x0*x1**2 - x0**3 - 1)*(3*x1**2 - 3*x0**2)
        b   = 2*(3*x0**2 - x1**2)*(-2*x1) + 2*(3*x0*x1**2 - x0**3 - 1)*(6*x1)
        return numpy.array([[a], [b]])

    def z0(self, x):
        y = self.dg(x)
        return math.sqrt(y[0]**2 + y[1]**2)

    def z(self, x):
        return self.dg(x)/self.z0(x)
