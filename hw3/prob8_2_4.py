import math
import numpy
import pylab

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
nrml = numpy.array([[6,        0,          (2./3.),     math.log(27)-2],
                    [0,        (2./3.),    0.,          2-math.log(3)*(3./2.)],
                    [(2./3.),  0.,         (2./5.),     math.log(27)-(26./9)]])
# reduce a row i with a pivot (j, k) of a matrix mat
def rrdce(mat, i, j, k):
    mat[i,:] = mat[i,:] + mat[j,:]*(-mat[i,k]/mat[j,k])
    return mat
