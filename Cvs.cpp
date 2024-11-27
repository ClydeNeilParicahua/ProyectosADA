#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

struct Registro {
    string DNI;
    string COD_REGION;
    string COD_PROVINCIA;
    string COD_DISTRITO;
};

void intercambiar(Registro& a, Registro& b) {
    Registro temp = a;
    a = b;
    b = temp;
}

int particion(Registro registros[], int bajo, int alto) {
    string pivote = registros[alto].DNI;
    int i = bajo - 1;

    for (int j = bajo; j < alto; j++) {
        if (registros[j].DNI <= pivote) {
            i++;
            intercambiar(registros[i], registros[j]);
        }
    }
    intercambiar(registros[i + 1], registros[alto]);
    return i + 1;
}

void quickSort(Registro registros[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = particion(registros, bajo, alto);
        quickSort(registros, bajo, pi - 1);
        quickSort(registros, pi + 1, alto);
    }
}

int busquedaBinaria(Registro registros[], int n, const string& dni, int& contador) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {
        int mitad = inicio + (fin - inicio) / 2;
        contador++;
        if (registros[mitad].DNI == dni) {
            return mitad;
        }
        if (registros[mitad].DNI < dni) {
            inicio = mitad + 1;
        } else {
            fin = mitad - 1;
        }
    }
    return -1;
}

int main() {
    clock_t start = clock();

    ifstream inputFile("realdata.csv");
    if (!inputFile.is_open()) {
        cout << "No se pudo abrir el archivo CSV." << endl;
        return 1;
    }

    const int MAX_REGISTROS = 1000000;
    Registro* registros = new Registro[MAX_REGISTROS];
    int n = 0;

    string linea;
    getline(inputFile, linea); 

    while (getline(inputFile, linea) && n < MAX_REGISTROS) {
        stringstream ss(linea);
        Registro reg;

        string basura; 
        getline(ss, reg.DNI, ';');            
        getline(ss, basura, ';');             
        getline(ss, basura, ';');            
        getline(ss, reg.COD_REGION, ';');     
        getline(ss, basura, ';');            
        getline(ss, reg.COD_PROVINCIA, ';'); 
        getline(ss, basura, ';');            
        getline(ss, reg.COD_DISTRITO, ';');   

        for (int i = 0; i < 12; i++) {
            getline(ss, basura, ';');
        }

        registros[n++] = reg;
    }
    inputFile.close();

    quickSort(registros, 0, n - 1);

    string dni;
    cout << "Ingrese el DNI a buscar: ";
    cin >> dni;

    int contador = 0;
    int resultado = busquedaBinaria(registros, n, dni, contador);

    if (resultado != -1) {
        cout << "DNI encontrado:" << endl;
        cout << "COD_REGION: " << registros[resultado].COD_REGION << endl;
        cout << "COD_PROVINCIA: " << registros[resultado].COD_PROVINCIA << endl;
        cout << "COD_DISTRITO: " << registros[resultado].COD_DISTRITO << endl;
    } else {
        cout << "DNI no encontrado." << endl;
    }
    cout << "Número de comparaciones: " << contador << endl;

    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion: " << elapsed_time << " segundos" << endl;

    delete[] registros;
    return 0;
}

