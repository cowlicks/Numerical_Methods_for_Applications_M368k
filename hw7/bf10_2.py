import numpy
import math

class two:
    def __init__(self):
        pass
    def j(self, x):
        arr = numpy.array([[2*float(x[0]), 1., 0.,],
                            [1., -2.*float(x[1]), 0.,],
                            [1., 1., 1.,]])
        return arr
    def f(self, x):
        arr     = numpy.array([[float(x[0])**2 + float(x[1]) - 37],
                            [float(x[0]) - float(x[1])**2 - 5],
                            [float(x[0]) + float(x[1]) + float(x[2]) - 3]])
        return arr

    def G(self, x):
        return x - numpy.dot(numpy.linalg.inv(self.j(x)), self.f(x))

    def result(self):
        x = numpy.zeros((3, 1))
        for i in range(3):
            x = self.G(x)
            print x

class seven:
    def __init__(self):
        pass

    def j(self, x):
        arr = numpy.array([
            [float(2*x[0]/math.log(x[0]**2 + x[1]**2) - x[1]*math.cos(x[0]*x[1])),
                float(2*x[1]/math.log(x[0]**2 + x[1]**2) - x[0]*math.cos(x[0]*x[1]))],
            [float(math.exp(x[0]-x[1]) - x[1]*math.sin(x[0]*x[1])),
                float(-math.exp(x[0]-x[1]) - x[0]*math.sin(x[0]*x[1]))]
            ])
        return arr
    def f(self, x):
        arr = numpy.array([
            [float(math.log(x[0]**2 + x[1]**2) - math.sin(x[0]*x[1]) - math.log(2*math.pi))],
            [float(math.exp(x[0] - x[1]) + math.cos(x[0]*x[1]))]])
        return arr
    
    def G(self, x):
        return x - numpy.dot(numpy.linalg.inv(self.j(x)), self.f(x))

    def result(self):
        x = numpy.array([[2.],
                        [2.]])

        for i in range(3):
            x = self.G(x)
            print x
