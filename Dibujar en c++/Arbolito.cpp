#include <iostream>
		using namespace std;
		
		int main() {
			int altura;
			cout << "Introduce la altura del arbolito: ";
			cin >> altura;
				
			for (int i = 1; i <= altura; i++) {
					
				for (int j = 0; j < altura - i; j++) {
					cout << " ";
				}
					
				for (int k = 0; k < (2 * i - 1); k++) {
					cout << "*";
				}
				cout << endl;
			}
			for (int i = 0; i < altura - 1; i++) {
				cout << " ";
			}
			cout << "|\n";
				
		}
