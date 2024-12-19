#include <iostream>
using namespace std;

int main() {
    int n, x;
    bool encontrado = false;

    cin >> n;

    int arreglo[n];
    for (int i = 0; i < n; i++) {
        cin >> arreglo[i];
    }

    cout << "Ingresa el número a eliminar: ";
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (arreglo[i] == x) {
            for (int j = i; j < n - 1; j++) {
                arreglo[j] = arreglo[j + 1];
            }
            encontrado = true;
            n--; 
            break;
        }
    }

    if (encontrado) {
        for (int i = 0; i < n; i++) {
            cout << arreglo[i] << " ";
        }
    } else {
        cout << "El numero " << x << " no se encontro ";
    }

    return 0;
}

