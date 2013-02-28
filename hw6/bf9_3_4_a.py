#! /usr/bin/env python
import numpy as np

# Given variables.
q   = 6
x0  = np.array([1, 2, 1])
A   = np.array([[4, 2, 1], [0, -3, 2], [1, 1, -2]])
I   = np.identity(3)
y1  = np.linalg.solve(A-q*I, x0)

