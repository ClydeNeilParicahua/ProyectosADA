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

    double* tiemposBusqueda = new double[n];
    int contador;
    string dniMasRapido, dniMasLento;
    double menorTiempo = 1e9, mayorTiempo = -1.0;

    for (int i = 0; i < n; i++) {
        clock_t inicio = clock();
        contador = 0;
        int resultado = busquedaBinaria(registros, n, registros[i].DNI, contador);
        clock_t fin = clock();
        double tiempoBusqueda = double(fin - inicio) / CLOCKS_PER_SEC;
        tiemposBusqueda[i] = tiempoBusqueda;

        if (tiempoBusqueda < menorTiempo) {
            menorTiempo = tiempoBusqueda;
            dniMasRapido = registros[i].DNI;
        }
        if (tiempoBusqueda > mayorTiempo) {
            mayorTiempo = tiempoBusqueda;
            dniMasLento = registros[i].DNI;
        }
    }

    cout << "Busqueda completada." << endl;
    cout << "El DNI que se busco mas rapido fue: " << dniMasRapido << endl;
    cout << "Tiempo de bsqueda mas rapido: " << menorTiempo << " segundos." << endl;
    cout << "El DNI que se demoro mas en buscar fue: " << dniMasLento << endl;
    cout << "Tiempo de busqueda mas lento: " << mayorTiempo << " segundos." << endl;

    delete[] registros;
    delete[] tiemposBusqueda;

    return 0;
}

