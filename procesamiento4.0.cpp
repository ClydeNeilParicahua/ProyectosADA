#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void intercambiar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int particion(int datos[], int bajo, int alto) {
    int pivote = datos[alto];
    int i = bajo - 1; 

    for (int j = bajo; j < alto; j++) {
        if (datos[j] <= pivote) {
            i++;
            intercambiar(datos[i], datos[j]);
        }
    }
    intercambiar(datos[i + 1], datos[alto]);
    return i + 1;
}

void quickSort(int datos[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = particion(datos, bajo, alto);

        
        quickSort(datos, bajo, pi - 1);
        quickSort(datos, pi + 1, alto);
    }
}

int busquedaBinaria(int datos[], int n, int elemento, int& contador) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {
        int mitad = inicio + (fin - inicio) / 2;
        contador++;
        if (datos[mitad] == elemento) {
            return mitad;
        }
        if (datos[mitad] < elemento) {
            inicio = mitad + 1;
        } else {
            fin = mitad - 1;
        }
    }
    return -1;
}

int main() {
    clock_t start = clock();

    ifstream inputFile("aleatorios.txt");
    ofstream outputFile("ordenados2.txt");

    if (!inputFile.is_open()) {
        cout << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    int* datos = new int[1000000];
    int n = 0;

    while (inputFile >> datos[n]) {
        n++;
    }
    inputFile.close();

    quickSort(datos, 0, n - 1);

    if (outputFile.is_open()) {
        for (int i = 0; i < n; i++) {
            outputFile << datos[i] << endl;
        }
        outputFile.close();
        cout << "Datos ordenados guardados." << endl;
    } else {
        cout << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }


    int elemento;
    cout << "Ingrese el elemento a buscar: ";
    cin >> elemento;
    int contador = 0;
    int resultado = busquedaBinaria(datos, n, elemento, contador);

    if (resultado != -1) {
        cout << "Elemento encontrado en la posicion: " << resultado << endl;
    } else {
        cout << "Elemento no encontrado." << endl;
    }
    cout << "Numero de particiones: " << contador << endl;

    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion: " << elapsed_time << " segundos." << endl;

    delete[] datos;
    return 0;
}

