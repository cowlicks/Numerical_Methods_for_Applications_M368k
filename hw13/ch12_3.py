import numpy as np
import math as m

dx = 1./8.
dt = 1./10.

A = (1./(4*m.pi*dx))**2 * np.array([[-2., 1., 0,],
                                    [1., -2., 1.],
                                    [0., 1., -2.]])

u0 = np.array([[0.],[0.],[0.]])
u1 = dt*np.array([[1.],[0.],[-1.]])
def step(u0, u1):
    return 2*u1 - u0 + dt**2 * np.dot(A, u1)

def f(x,t):
    return m.sin(t)*m.sin(4.*m.pi*x)
