#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<sstream>

using namespace std;

// Función de partición para QuickSort
int partition(double arr[], int low, int high) {
    double pivot = arr[high]; 
    int i = low - 1;          

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { 
            i++;
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i + 1], arr[high]); 
    return i + 1;                
}

// Implementación de QuickSort
void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1);        
        quickSort(arr, pi + 1, high);       
    }
}
// Leer archivo

int main() {

ifstream archivo;
string frase;
double numeros[100];
int indice = 0;

archivo.open("desordenados.txt",ios::in);
if(archivo.fail()) {
	cout << "Error al leer el archivo";
	return 1;
}
while (getline(archivo,frase) && indice < 100) {
	stringstream ss(frase);
	ss >> numeros[indice];
	indice++;
}

archivo.close();

cout << "Numeros antes de ordenar :" << endl;
for (int i = 0; i < indice;i++) {
	cout << numeros[i] << " ";
}
cout << endl;

// Ordenando

quickSort(numeros, 0, indice - 1);

cout << "Numeros despues de ordenar" << endl;
for (int i = 0; i < indice; i++) {
	cout << numeros[i] << " ";
}
cout << endl;
}
