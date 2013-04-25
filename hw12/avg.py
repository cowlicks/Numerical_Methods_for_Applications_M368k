#!/usr/bin/env python
import numpy as np
data = np.genfromtxt('program12.out')
u = data[:,2]
print u.mean()

