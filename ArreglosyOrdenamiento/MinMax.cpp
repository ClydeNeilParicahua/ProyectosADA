#include <iostream>
			using namespace std;
			
			int main() {
				int n;
				cin >> n;
				
				int arreglo[n];
				for (int i = 0; i < n; i++) {
					cin >> arreglo[i];
				}
				
				int maximo = arreglo[0];
				int minimo = arreglo[0];
				
				for (int i = 1; i < n; i++) {
					if (arreglo[i] > maximo) {
						maximo = arreglo[i];
					}
					if (arreglo[i] < minimo) {
						minimo = arreglo[i];
					}
				}
				
	    cout << "El elemento maximo es:" << maximo << endl;
			    cout << "El elemento minimo es:" << minimo << endl;
				
				return 0;
			}
			
