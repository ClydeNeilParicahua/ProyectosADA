#include <iostream>
using namespace std;

int main() {
    int n, p, y;

    cin >> n;

    int arreglo[n + 1]; 
    
    for (int i = 0; i < n; i++) {
        cin >> arreglo[i];
    }

    cout << "Ingresa el valor a insertar: ";
    cin >> y;

    cout << "Ingresa la posicion del valor: ";
    cin >> p;
    p=p-1;

    if (p < 0 || p > n) {
        cout << "Error:" << endl;
    } else {
        for (int i = n; i > p; i--) {
            arreglo[i] = arreglo[i - 1];
        }

        arreglo[p] = y;
        n++; 

        cout << "Arreglo despues de la insercion: ";
        for (int i = 0; i < n; i++) {
            cout << arreglo[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

