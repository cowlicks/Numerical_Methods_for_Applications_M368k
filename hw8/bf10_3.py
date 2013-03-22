import numpy

class two:
    def __init__(self):
        self.j0 = numpy.array([
                    [10, 1, 0],
                    [1, -1, 0],
                    [1, 1, 1]])
        
        self.x0 = numpy.array([[5],[2], [0]])

    def f(self, x):
        return numpy.array([[float(x[0]**2 + x[1] - 37)],
                            [float(x[0] - x[1] - 5)],
                            [float(x[0] + x[1] + x[2] - 3)]])



    def first_step(self, x, j, f):
        return x - numpy.dot(j,f)
    
    def x1(self):
        return self.first_step(self.x0, numpy.linalg.inv(self.j0), self.f(self.x0))

