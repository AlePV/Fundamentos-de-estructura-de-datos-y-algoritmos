import matplotlib.pyplot as plt
import pandas as pd
import sys

data1 = pd.read_csv("mergesort.csv", names=['n', 'time[ms]'])
data2 = pd.read_csv("quicksort.csv", names=['n', 'time[ms]'])
data3 = pd.read_csv("standarsort.csv", names=['n', 'time[ms]'])

data1 = data1.sort_values(by='n')
data2 = data2.sort_values(by='n')
data3 = data3.sort_values(by='n')

x1 = data1['n'].values
y1 = data1['time[ms]'].values

x2 = data2['n'].values
y2 = data2['time[ms]'].values

x3 = data3['n'].values
y3 = data3['time[ms]'].values

plt.plot(x1, y1)
plt.plot(x2, y2)
plt.plot(x3, y3)

plt.xlabel('n')
plt.ylabel('time[ms]')

plt.title('Tiempo de ejecución algoritmos Mergesort, Quicksort y Estandar')
plt.legend(['Mergesort', 'Quicksort', 'Standarsort'])

plt.savefig('plot_merge-quick-standar_sorts.png', dpi=300)
