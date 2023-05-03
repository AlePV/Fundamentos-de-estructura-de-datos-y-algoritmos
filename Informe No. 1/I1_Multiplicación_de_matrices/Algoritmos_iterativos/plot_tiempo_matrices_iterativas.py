import matplotlib.pyplot as plt
import pandas as pd
import sys


data1 = pd.read_csv("standard_mm_results.csv")
data2 = pd.read_csv("transpose_mm_results.csv")


x1 = data1['n'].values
y1 = data1['time[ms]'].values

x2 = data2['n'].values
y2 = data2['time[ms]'].values

plt.plot(x1, y1)
plt.plot(x2, y2)

plt.xlabel('n')
plt.ylabel('time[ms]')

plt.title('Multiplicación de matrices con algoritmos iterativos')
plt.legend(['standard_mm_results', 'transpose_mm_results'])

plt.savefig('plot_algoritmos_iterativos.png', dpi=300)
