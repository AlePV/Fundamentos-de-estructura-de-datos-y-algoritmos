#include <iostream>

//programado con ayuda de ChatGPT

using namespace std;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2]; //arreglos izquierda y derecha
	
    for (i = 0; i < n1; i++) { //se copian los elementos en el arreglo de la izquierda
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {//se copian los elementos en el arreglo de la derecha
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) { // // Se compara elemento por elemento de los arreglos y se colocan en orden creciente en el arreglo original.
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }

    int m = l + (r - l) / 2; //se calcula el indice del medio del arreglo
    //Se llama recursivamente la función mergesort con los arreglos de la izquierda y la derecha
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
	
	//Se llama la función merge para unir los arreglos
    merge(arr, l, m, r);
}


