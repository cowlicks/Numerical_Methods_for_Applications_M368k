import numpy as np
import math as m

h = m.pi/8.
a = 0
b = m.pi/2.
alpha = -0.3
beta  = -0.1

def A(h, alpha, beta, a, b):
    A = np.array([[-2*(1 + h**2) , 1-h/2         , 0],
                [h/2 + 1         , -2*(1 + h**2) , 1 - h/2],
                [0               , h/2 + 1       , -2*(1 + h**2) ]])
    return A

def X(h, alpha, beta, a, b):
    X = np.array([[-alpha*(h/2 + 1) + h**2 * m.cos(a+h)],
                [h**2 * m.cos(a + 2*h)],
                [-(1 - h/2)*beta + h**2 * m.cos(a + 3*h)]])
    return X

def f(x):
    return -.1*(m.sin(x) + 3*m.cos(x))


    


