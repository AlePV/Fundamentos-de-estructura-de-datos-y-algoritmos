import matplotlib.pyplot as plt
import pandas as pd
import sys

data1 = pd.read_csv("bubblesort.csv", names=['n', 'time[ms]'])

data1 = data1.sort_values(by='n')

x1 = data1['n'].values
y1 = data1['time[ms]'].values

plt.plot(x1, y1)

plt.xlabel('n')
plt.ylabel('time[ms]')

plt.title('Tiempo de ejecución algoritmo Bubblesort')
plt.legend(['Bubblesort'])

plt.savefig('plot_bubblesort.png', dpi=300)

