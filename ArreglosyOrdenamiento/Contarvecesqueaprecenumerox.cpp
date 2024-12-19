#include <iostream>
using namespace std;

int main() {
    int n, x, contador = 0;

    cin >> n;

    int arreglo[n];
    for (int i = 0; i < n; i++) {
        cin >> arreglo[i];
    }

    cin >> x;

    for (int i = 0; i < n; i++) {
        if (arreglo[i] == x) {
            contador++;
        }
    }

    cout << "El numero " << x << " aparece " << contador << endl;

    return 0;
}

