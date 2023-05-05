#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	
	int N = 200000;
	int A = 4;
	
	srand(clock()); // semilla para la función rand
	
    for(int a = 1; a <= A; a++) {
		for(int n = 1; n < N; n+=20000) {
			string txt = std::to_string(a) + "_" + std::to_string(n) + ".txt"; 
			cout << endl << txt;     
			int arr[n];
						
			for(int i = 0; i < n; i++) {
				arr[i] = rand() % 201 - 100; // generar un número aleatorio entre 0 y 99
				//cout << arr[i] << " "; // imprimir el número generado
			}
			
			// ordenar la primera mitad del arreglo
			
			sort(arr, arr + n/2);
			
			// escribir los valores en un archivo de texto
					
			ofstream archivo(txt);
			archivo << a << " ";
			
			if (archivo.is_open()) {
				for(int i = 0; i < n; i++) {
					archivo << arr[i] << " ";
				}
				archivo.close();
				cout << endl << "Los valores han sido guardados en el archivo valores.txt" << endl;
			} else {
				cout << endl << "No se pudo abrir el archivo" << endl;
			}
    	}
	}
    return 0;
}
