#! /usr/bin/env python
"""
Tools for constructing the discrete least squares trigonometric
approximation of a function.
"""

def xj_list(m):
    """
    return the list of xj's for the interval [-pi, pi]
    """
    return [ -math.pi + (float(j)/m)*math.pi for j in range(m) ]

def yj_list(f, m):
    """
    Given the function f that is to be approximated and the list of
    xj's, return the list of yj's.
    """
    return [ f(j) for j in m ]


