#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arreglo[n];
    int arregloinvertido[n];

    for (int i = 0; i < n; i++) {
        cin >> arreglo[i];
    }

    for (int i = 0; i < n; i++) {
        arregloinvertido[i] = arreglo[n - 1 - i];
    }

    cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    cout << "Arreglo invertido: ";
    for (int i = 0; i < n; i++) {
        cout << arregloinvertido[i] << " ";
    }
    cout << endl;

    return 0;
}

