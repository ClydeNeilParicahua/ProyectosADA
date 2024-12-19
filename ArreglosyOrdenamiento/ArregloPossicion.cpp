#include <iostream>
using namespace std;

int main() {
    int n, i, j;

    cin >> n;

    int arreglo[n];
    for (int k = 0; k < n; k++) {
        cin >> arreglo[k];
    }
cout << "ingrese indice (i)";
    cin >> i;
    cout << "ingrese indice (j)";
    cin >> j;

    if (i < 0 || i >= n || j < 0 || j >= n) {
        cout << "Error" << endl;
    } else {
        int temp = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = temp;
        
        cout << "Arreglo nuevo";
        for (int k = 0; k < n; k++) {
            cout << arreglo[k] << " ";
        }
        cout << endl;
    }

    return 0;
}

