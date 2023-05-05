#include <iostream>

using namespace std;

// Programado con ayuda de ChatGPT
// en esta version de quicksort se toma como pivote el ultimo elemento y no aleatorio.

int partition(int arr[], int low, int high);

void quickSort(int arr[], int low, int high);

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // se selecciona el ultimo elemento como pivote
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) { //si el elemento es menor o igual al pivote
            i++;
            swap(arr[i], arr[j]); //intercambia el elemento i con el elemento j
        }
    }
    swap(arr[i + 1], arr[high]); // intercambia el pivote con el elemento en la posicion i+1
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
