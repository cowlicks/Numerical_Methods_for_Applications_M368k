import math as m
import numpy as np

t1abc = np.array([[1., .25, .75],
                  [1., 0., 0.5],
                  [1., 0., 1.],])

t2abc = np.array([[1., 0.25, .75],
                  [1., .5, .5],
                  [1., 0., .5]])
gam = 5./1.625
def u1(x,y):
    return gam*4*x

def u2(x,y):
    return gam*(-2.+4*y)+(1+2*x-2*y)
