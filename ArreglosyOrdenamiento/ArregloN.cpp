#include <iostream>
using namespace std;

int main() {
    int n;
   
    cin >> n;

    int arreglo[n];
    int suma = 0;

    for (int i = 0; i < n; i++) {
        cin >> arreglo[i];
        suma += arreglo[i];
    }

    cout << suma << endl;
}
