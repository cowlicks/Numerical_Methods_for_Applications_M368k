import numpy as np
import math as m

a = 1.
b = 2.
alpha   = 1./2.
beta    = 1./3.
N = 3.
h = (b - a)/(N + 1)

def J(w):
    w1 = float(w[1])
    w2 = float(w[2])
    w3 = float(w[3])
    j = np.array([[2+h*h*(3*w1*w1 - (w2 - alpha)/(2*h)), -1 - h*w1/2, 0],
                [-1 + h*w2/2, 2 + h*h*(3*w2*w2 -(w3-w1)/(2*h)), -1 - h*w2/2],
                [0          , -1 + h*w3/2   , 2 + h*h*(3*w3*w3 - (beta - w2)/(2*h))]])
    return j

def F(w):
    w1 = float(w[1])
    w2 = float(w[2])
    w3 = float(w[3])
    f = np.array([[2*w1 - w2 + h*h*(w1**3 - w1*(w2-alpha)/(2*h)) - alpha],
                [-w1 + 2*w2 - w3 + h*h*(w2**3 - w2*(w3-w1)/(2*h))],
                [-w2 + 2*w3 + h*h*(w3**3 - w3*(beta-w2)/(2*h)) - beta]])
    return f

def w0():
    L = [alpha + i*h*(beta-alpha)/(b-a) for i in range(int(N+2))]
    w0 = np.zeros((len(L),1))
    for index, val in enumerate(L):
        w0[index] = val
    return w0


def newt():
    w = w0()
    w_new = w
    for i in range(20):
        print i
        w_new[1:-1] = w[1:-1] - np.dot(np.linalg.inv(J(w)), F(w))
        w = w_new
        print w
    return w_new
        
