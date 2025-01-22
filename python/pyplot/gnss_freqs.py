import matplotlib.pyplot as plt

# Datos de las señales
constellations = ['GPS', 'GPS', 'GPS', 'GLONASS', 'GLONASS', 'GLONASS', 'Galileo', 'Galileo', 'Galileo', 'Galileo']
signals = ['L1', 'L2', 'L5', 'L1', 'L2', 'L3', 'E1', 'E5a', 'E5b', 'E6']
frequencies = [1575.42, 1227.60, 1176.45, 1602, 1246, 1202.025, 1575.42, 1176.45, 1207.14, 1278.75]
bandwidths = [30.69, 20.46, 24.00, 9.00, 6.00, 1.00, 32.00, 24.00, 24.00, 40.00]

# Constelaciones colores
color_map = {
    'GPS': 'blue',
    'GLONASS': 'green',
    'Galileo': 'red'
}

colors = [color_map[constellation] for constellation in constellations]

plt.figure(figsize = (12, 6))
bars = plt.barh(signals, bandwidths, left = [f - b / 2 for f, b in zip(frequencies, bandwidths)], color = colors, edgecolor = 'black')

# Lineas de frecuencia central
for bar, freq in zip(bars, frequencies):
    plt.text(bar.get_x() + bar.get_width() / 2, bar.get_y() + bar.get_height() / 2,
             f'{freq} MHz', ha = 'center', va = 'center', color = 'black', fontsize = 8)

# Leyendas
legend_labels = [plt.Line2D([0], [0], color = color, lw = 10, label = name) for name, color in color_map.items()]
plt.legend(handles = legend_labels, title = 'Constelación', loc = 'upper center', bbox_to_anchor = (0.5, -0.15), ncol = 3)

# Ejes
plt.title('Distribución de Frecuencias y Anchos de Banda de Señales GNSS', fontsize = 14)
plt.xlabel('Frecuencia (MHz)', fontsize = 12)
plt.ylabel('Señal GNSS', fontsize = 12)
plt.grid(axis = 'x', linestyle = '--', alpha = 0.7)
plt.tight_layout()

plt.show()