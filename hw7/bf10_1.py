import math
class six:
    def __init__(self):
        pass

    def g0(self, x):
        return math.sqrt(1./5.) * x[1]

    def g1(self, x):
        return .25*(math.sin(x[0]) + math.cos(x[1]))

    def G(self, x):
        return self.g0(x), self.g1(x)

    def result(self):
        x0  = (.25, .25)
        x   = x0
        for i in range(10):
            x   = self.G(x)
            print x
        
class ten:
    def __init__(self):
        pass
    
    def g0(self, x):
        return math.sqrt(37. - x[1])
    def g1(self, x):
        return math.sqrt(x[0] - 5)
    def g2(self, x):
        return 3 - x[0] - x[1]

    def G(self, x):
        x[0]    = self.g0(x)
        x[1]    = self.g1(x)
        x[2]    = self.g2(x)
        return x
    def result(self):
        x = [5., 2., 0.]
        for i in range(5):
            x = self.G(x)
            print x

