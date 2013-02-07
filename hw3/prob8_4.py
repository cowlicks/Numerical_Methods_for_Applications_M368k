import numpy
import pylab

x = [0, 0.15, 0.31, 0.5, 0.6, 0.75]
y = [1.0, 1.004, 1.031, 1.117, 1.223, 1.422]

def sum(x, deg):
    s = 0
    for i in x:
        s += i**deg
    return s
def lsq(x, y, deg):
    s = 0
    for i in range(len(x)):
        s += y[i]*x[i]**deg
    return s

# The resulting normal equations.
nrml = numpy.array([[6,        2.31,       1.2911,      6.797],
                    [2.31,     1.2911,     0.796041,    2.82901],
                    [1.2911,   0.796041,   0.51824771,  1.6410741]])
# reduce a row i with a pivot (j, k) of a matrix mat
def rrdce(mat, i, j, k):
    mat[i,:] = mat[i,:] + mat[j,:]*(-mat[i,k]/mat[j,k])
    return mat

a0 =  1.01134099
a1 = -0.32569875
a2 =  1.14733030

def f(x):
    return a0 + a1*x + a2*x**2

fx = []
t  = numpy.arange(0., 1., 0.001)
for i in t:
    fx.append(f(i))

# Calculate error.
E = 0
for i in range(len(x)):
    E += abs(y[i] - f(x[i]))**2
print E

pylab.plot(t, fx)
pylab.scatter(x ,y)
pylab.show()
