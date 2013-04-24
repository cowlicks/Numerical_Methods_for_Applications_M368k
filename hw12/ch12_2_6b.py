import math as m
import numpy as np
dx = .25
dt = .1
pii = dt/(dx*m.pi)**2
IC = np.array([[2.**-.5, 1., 2.**-.5]]).T
A = np.array([  [-2., 1., 0.,],
                [1., -2., 1.,],
                [0., 1., -2.,]])

def step(A, pii, u):
    u = u + pii*np.dot(A,u)
    return u

def f(x,t):
    return m.exp(-t)*m.cos(m.pi*(x-.5))
