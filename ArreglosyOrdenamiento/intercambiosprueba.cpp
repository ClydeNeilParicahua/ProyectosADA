#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &intercambios) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                intercambios++;  // Incrementa el contador en cada intercambio
            }
        }
    }
}

int main() {
    int arr[] = {40, 21, 4, 9, 10, 35};
    int n = sizeof(arr)/sizeof(arr[0]);
    int intercambios = 0;  // Inicializa el contador de intercambios
    bubbleSort(arr, n, intercambios);  // Pasa el contador como referencia
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\nIntercambios: " << intercambios << endl;
    return 0;
}
