#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>
#include "mergesort.h"
#include "quicksort.h"
#include "bubblesort.h"

using namespace std;
using namespace chrono;

int main(int argc, char *argv[]) {
	
	std::string arreglo_ordenado= "";

if (argc != 2) { // Comprobar si se proporcionó el nombre del archivo como argumento
        cout << "Uso: " << argv[0] << " archivo.txt" << endl;
        return 1; // Salir del programa con código de error 1
    }
    
    string filename = argv[1]; // Obtener el nombre del archivo del primer argumento
    
    ifstream file(filename); // Abrir el archivo
    if (!file.is_open()) { // Comprobar si el archivo se abrió correctamente
        cout << "No se pudo abrir el archivo " << filename << endl;
        return 1; // Salir del programa con código de error 1
    }
    
    int primer_valor;
    vector<int> valores;
    
    string line;
    getline(file, line); // Leer la primera línea del archivo
    istringstream iss(line);
    iss >> primer_valor; // Leer el primer valor como un entero
    
    int valor;
    while (iss >> valor) { // Leer los valores restantes como enteros
        valores.push_back(valor);
    }
    
    file.close(); // Cerrar el archivo
    
    // Mostrar los resultados
    cout << "Primer valor: " << primer_valor << endl;
    cout << "Valores restantes: ";
    for (int i = 0; i < valores.size(); i++) {
        cout << valores[i] << " ";
    }
    cout << endl;
	
	//Arreglo a ordenar
	int* arr = valores.data();
	
	//Tamaño del arreglo
	int n = valores.size();
	
	auto start = high_resolution_clock::now();
	switch (primer_valor) {
		case 1: {
			cout << "mergesort: " << endl;
			
			//Se llama a la función mergesort y se le da como argumento el arreglo, un entero 0 y el tamaño del arreglo original menos el primer valor
			mergeSort(arr, 0, n - 1);
			
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
				arreglo_ordenado += std::to_string(arr[i]) + " ";
			}
			cout << endl;
			
			auto end = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(end - start);
			cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;
			
			std::ofstream archivo("mergesort.csv", std::ios::app);//registro de resultados mergesort
			if (archivo.is_open()) { // asegurarse que el archivo se haya abierto correctamente
				archivo << std::to_string(n) + "," + std::to_string(duration.count()) +"\n";
				archivo.close(); // cerrar el archivo para guardar los cambios
				std::cout << "Tiempo guardado en mergesort.csv." << std::endl;
			} else {
				std::cerr << "No se pudo abrir el archivo." << std::endl;
			}			
		}	
		break;
		case 2: {
			cout << "quicksort: " << endl;
			
			//Se llama a la función quicksort y se le da como argumento el arreglo, un valor 0, y el tamaño del arreglo original menos el primer valor
			quickSort(arr, 0, n - 1);

			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
				arreglo_ordenado += std::to_string(arr[i]) + " ";
			}
			
			cout << endl;
			auto end = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(end - start);
			cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;
			
			std::ofstream archivo("quicksort.csv", std::ios::app);//registro de resultados mergesort
			if (archivo.is_open()) { // asegurarse que el archivo se haya abierto correctamente
				archivo << std::to_string(n) + "," + std::to_string(duration.count()) +"\n";
				archivo.close(); // cerrar el archivo para guardar los cambios
				std::cout << "Tiempo guardado en quicksort.csv." << std::endl;
			} else {
				std::cerr << "No se pudo abrir el archivo." << std::endl;
			}
		}
		break;
		case 3: {
			cout << "bubblesort: " << endl;
			
			//Se llama a la función bubblesort y se le da como argumento el arreglo, el tamaño del arreglo original
			bubbleSort(arr, n);

			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
				arreglo_ordenado += std::to_string(arr[i]) + " ";
			}
			cout << endl;
			
			auto end = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(end - start);
			cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;
			
			std::ofstream archivo("bubblesort.csv", std::ios::app);//registro de resultados mergesort
			if (archivo.is_open()) { // asegurarse que el archivo se haya abierto correctamente
				archivo << std::to_string(n) + "," + std::to_string(duration.count()) +"\n";
				archivo.close(); // cerrar el archivo para guardar los cambios
				std::cout << "Tiempo guardado en bubblesort.csv." << std::endl;
			} else {
				std::cerr << "No se pudo abrir el archivo." << std::endl;
			}
		}
		break;
		case 4:{
			cout << "standard sort" << endl;
			
			//Algoritmo de ordenamiento de la biblioteca algorithm
			sort(arr, arr + n);
			
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
				arreglo_ordenado += std::to_string(arr[i]) + " ";
			}
			cout << endl;
			
			auto end = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(end - start);
			cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;
			
			std::ofstream archivo("standarsort.csv", std::ios::app);//registro de resultados mergesort
			if (archivo.is_open()) { // asegurarse que el archivo se haya abierto correctamente
				archivo << std::to_string(n) + "," + std::to_string(duration.count()) +"\n";
				archivo.close(); // cerrar el archivo para guardar los cambios
				std::cout << "Tiempo guardado en standarsort.csv." << std::endl;
			} else {
				std::cerr << "No se pudo abrir el archivo." << std::endl;
			}
		}
		break;
  }

  
  return 0;
}
