#include <iostream>
#include <fstream>

using namespace std;

void ordenador(int datos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (datos[j] > datos[j + 1]) {
                int temp = datos[j];
                datos[j] = datos[j + 1];
                datos[j + 1] = temp;
            }
        }
    }
}

int busquedaBinaria(int datos[], int n, int elemento) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {
        int mitad = inicio + (fin - inicio) / 2;

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
    ifstream inputFile("desordenados.txt");  
    ofstream outputFile("ordenados.txt");  

    if (!inputFile.is_open()) {
        cout << "No se pudo abrir" << endl;
        return 1;
    }

    int datos[200];  
    int n = 0;
    
    while (inputFile >> datos[n]) {
        n++;
    }
    inputFile.close();

    ordenador(datos, n);

    if (outputFile.is_open()) {
        for (int i = 0; i < n; i++) {
            outputFile << datos[i] << endl;
        }
        outputFile.close();
        cout << "datos ordenados guardados" << endl;
    } else {
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        cout << datos[i] << " ";
    }
    cout << endl;
    
    int elemento;
    cout << "Ingrese el elemento a buscar: ";
    cin >> elemento;

    int resultado = busquedaBinaria(datos, n, elemento);

    if (resultado != -1) {
        cout << "Elemento encontrado en la posicion : " << resultado << endl;
    } else {
        cout << "No encontrado" << endl;
    }

    return 0;
}


