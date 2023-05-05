import matplotlib.pyplot as plt
import pandas as pd
import sys

#Referencia del programa: basado en programa entregado por el ayudante Vicente Lermanda

data1 = pd.read_csv("strassen.csv", names=['n', 'time[ms]'])

data1 = data1.sort_values(by='n')

x1 = data1['n'].values
y1 = data1['time[ms]'].values

plt.plot(x1, y1)

plt.xlabel('n')
plt.ylabel('time[ms]')

plt.title('Multiplicación de matrices con algoritmo de Strassen')
plt.legend(['strassen'])

plt.savefig('plot_strassen.png', dpi=300)
