import numpy as np
import matplotlib.pyplot as plt

ak = [1, 1, 0, 1, 0, 0]
t = np.arange(0, 1, 0.01)
t2 = np.arange(0, len(ak), 0.01)
fc = 1
sp = np.cos(2 * np.pi * fc * t)
abb = np.array([])
sm = np.array([])

for k in ak:
    if k == 1:
        element = 1
    else:
        element = -1
    
    abb = np.append(abb, element * np.ones(len(t)))
    sm = np.append(sm, element * sp)

fig, ax = plt.subplots(2)
ax[0].plot(t2, abb)
ax[1].plot(t2, sm)

plt.show(block = True)