import numpy as np
import pylab as plt
data = np.genfromtxt('program10.out')
plt.plot(data[:, 0], data[:, 1])
plt.show()
