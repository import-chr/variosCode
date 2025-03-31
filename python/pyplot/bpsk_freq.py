import numpy as np
import matplotlib.pyplot as plt

Rb = 1e6
fc = 2e6
N = 1000

f = np.linspace(-3e6, 3e6, N)

S = (np.sinc((f - fc) / Rb)) ** 2 + (np.sinc((f + fc) / Rb)) ** 2

plt.plot(f, S, 'b-', linewidth = 2)
plt.title('Espectro BPSK')
plt.xlabel('Frecuencia (MHz)')
plt.ylabel('Densidad espectral')
plt.grid(True)
plt.axvline(x = fc, color = 'r', linestyle = '--', label = f'Portadora ({fc/1e6} MHz)')
plt.axvline(x = -fc, color = 'r', linestyle = '--')
plt.legend()
plt.show()
