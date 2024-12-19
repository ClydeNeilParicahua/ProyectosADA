#include <iostream>
using namespace std;

int main() {
    int n;
    bool Ordenado = true;

    cin >> n;

    int arreglo[n];
    for (int i = 0; i < n; i++) {
        cin >> arreglo[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (arreglo[i] > arreglo[i + 1]) {
            Ordenado = false;
            break;
        }
    }

    if (Ordenado) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

