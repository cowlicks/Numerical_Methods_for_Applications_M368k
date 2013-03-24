import math
import numpy

class one:
    def __init__(self):
        self.x0 = (1., 1.5)

    def g(self, x):
        return (3*x[0]**2 - x[1]**2)**2 + (3*x[0]*x[1]**2 - x[0]**3 - 1)**2

    def gg(self, x):
        x0 = x[0]
        x1 = x[1]
        a   = 2*(3*x0**2 - x1**2)*(6*x0) + 2*(3*x0*x1**2 - x0**3 - 1)*(3*x1**2 - 3*x0**2)
        b   = 2*(3*x0**2 - x1**2)*(-2*x1) + 2*(3*x0*x1**2 - x0**3 - 1)*(6*x1)
        return a, b

    def z0(self, x):
        a, b = self.gg(x)
        return math.sqrt(a**2 + b**2)
