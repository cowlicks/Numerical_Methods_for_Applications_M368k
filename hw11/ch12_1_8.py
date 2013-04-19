import numpy as np

q = 1.5
K = 1.04
c = q/K

dx = 2.
dy = 5./3

xf = dx**-2
yf = dy**-2

def ul(y):
    return y*(5.-y)

def ub(x):
    return x*(6.-x)

u = np.zeros((4,4))
w = np.zeros(4)

u[0,:] = [-2*(xf + yf), xf, yf, 0]
w[0] = c- ul(10./3)*xf

u[1,:] = [xf, -2*(xf + yf), 0, yf]
w[1] = c

u[2,:] = [yf, 0, -2*(xf + yf), xf]
w[2] = c -(ul(5./3)*xf + ub(2.)*yf)

u[3,:] = [0, yf, xf, -2*(xf + yf)]
w[3] = c - ub(4.)*yf

soln = np.dot(np.linalg.inv(u),w)
