#! /usr/bin/env python
"""
Tools for constructing the discrete least squares trigonometric
approximation of a function. This is not meant to be fast or optimized,
just a clear implementation of the algorithim.

I made this for problem 8.5.7 in Burden and Faires 9th ed. Numerical 
Analysis book. Overkill I know.
"""
import math

def xj_list(m, low_bound=-math.pi, up_bound=math.pi):
    """
    Return the list of xj's. By default the domain is [-pi, pi].
    """
    return [ low_bound + (float(j)/m)*up_bound for j in range(2*m) ]

def yj_list(f, xj_list):
    """
    Given the function f that is to be approximated and the list of
    xj's, return the list of yj's.
    """
    return [ f(j) for j in xj_list ]

def ak_list(xj_list, yj_list, m, n):
    """
    Generate all the a constants. Given the yj's, the degree n, and the
    number of points m.
    """
    ak_list = []
    for k in range(n + 1):
        summation = 0
        for j in range(2*m):
            summation += yj_list[j] * math.cos(k * xj_list[j])
        ak_list.append(summation / m)
    return ak_list

def bk_list(xj_list, yj_list, m, n):
    """
    Similar to ak_list function but for the b constants.
    """
    bk_list = [0]
    for k in range(1, n):
        summation = 0
        for j in range(2*m):
            summation += yj_list[j] * math.sin(k * xj_list[j])
        bk_list.append(summation / m)
    return bk_list

def s_trig_poly(line, n, ak_list, bk_list):
    """
    Given the a and b constants, construct the least squares trig
    approximation.
    """
    data = []
    for x in line:
        summation = 0
        if n+1 != len(ak_list):
            for k in range(1, n):
                summation += ak_list[k] * math.cos(k*x) + bk_list[k] * math.sin(k*x)
            data.append(.5*ak_list[0] + ak_list[-1]*math.cos(n*x) + summation)
        else:
            for k in range(1, n):
                summation += ak_list[k] * math.cos(k*x) + bk_list[k] * math.sin(k*x)
            data.append(.5*(ak_list[0] + ak_list[-1]*math.cos(n*x))*summation)
    return data

def main(t, f, m, n=None, low=-math.pi, high=math.pi):
    if n is None: 
        n = m
    xl = xj_list(m)
    yl = yj_list(f, xl)
    al = ak_list(xl, yl, m, n)
    bl = bk_list(xl, yl, m, n)
    return s_trig_poly(t, n, al, bl)

if __name__=='__main__':
    pass
