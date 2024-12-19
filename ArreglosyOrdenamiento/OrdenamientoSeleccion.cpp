#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, int &comparaciones) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparaciones++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int users[] = {580, 320, 760, 435, 520};
    int n = sizeof(users) / sizeof(users[0]);
    int comparaciones = 0;  
    selectionSort(users, n, comparaciones);
    for (int i = 0; i < n; i++) {
        cout << users[i] << " ";
    }
    cout << endl;

    cout << "total de comparaciones: " << comparaciones << endl;

    return 0;
}

