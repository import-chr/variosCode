import matplotlib.pyplot as plt

# Datos de las señales
constellations = ['GPS', 'GPS', 'GPS', 'GLONASS', 'GLONASS', 'GLONASS', 'Galileo', 'Galileo', 'Galileo', 'Galileo']
signals = ['L1', 'L2', 'L5', 'L1', 'L2', 'L3', 'E1', 'E5a', 'E5b', 'E6']
frequencies = [1575.42, 1227.60, 1176.45, 1602, 1246, 1202.025, 1575.42, 1176.45, 1207.14, 1278.75]
bandwidths = [30.69, 20.46, 24.00, 9.00, 6.00, 1.00, 32.00, 24.00, 24.00, 40.00]

# Constelaciones colores
color_map = {
    'GPS': '#FF6F61',
    'GLONASS': '#6B8E23',
    'Galileo': '#4682B4'
}

freq_color = "#000000"

colors = [color_map[constellation] for constellation in constellations]

plt.figure(figsize = (18, 9))
bars = plt.barh(signals, bandwidths, left = [f - b / 2 for f, b in zip(frequencies, bandwidths)], color = colors, edgecolor = 'black')

# Lineas de frecuencia central
for i, (bar, freq) in enumerate(zip(bars, frequencies)):
    if i % 2 == 0 or i == 5:
        y_position = bar.get_y() + bar.get_height() + 0.1
    else:
        y_position = bar.get_y() - 0.15
    
    plt.text(bar.get_x() + bar.get_width() / 2,
             y_position,
             f'{freq} MHz',
             ha = 'center',
             va = 'center',
             color = freq_color,
             fontsize = 10)

# Leyendas
legend_labels = [plt.Line2D([0], [0], color = color, lw = 10, label = name) for name, color in color_map.items()]
plt.legend(handles = legend_labels, title = 'Constelación', loc = 'upper center', bbox_to_anchor = (0.5, -0.15), ncol = 3, fontsize = 10, title_fontsize = 14)

# Ejes
plt.title('Distribución de Frecuencias y Anchos de Banda de Señales GNSS', fontsize = 16)
plt.xlabel('Frecuencia (MHz)', fontsize = 14)
plt.ylabel('Señal GNSS', fontsize = 14)
plt.grid(axis = 'x', linestyle = '--', alpha = 0.7)
plt.tight_layout()

plt.show()
