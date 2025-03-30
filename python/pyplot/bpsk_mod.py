import numpy as np
import matplotlib.pyplot as plt

ak = [1, 1, 0, 1]
t = np.arange(0, 1, 0.01)
fc = 1
sp = np.cos(2 * np.pi * fc * t)

plt.plot(sp)
plt.show