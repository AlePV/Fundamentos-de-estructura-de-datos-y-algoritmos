#include <iostream>

using namespace std;

//Función que recibe un arreglo y un entero con el largo del arreglo
void bubbleSort(int arr[], int n) {
	//Se recorre el arreglo hasta el ultimo elemento
    for (int i = 0; i < n - 1; i++) {
		//Se recorre el arreglo hasta un indice menor al for anterior
        for (int j = 0; j < n - i - 1; j++) {
			//Si el de la izquierda de indice j es mayor al valor de la derecha de indice i se intercambian los valores
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
