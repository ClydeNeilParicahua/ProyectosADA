#include <iostream>
#include <fstream>
using namespace std;

int main () {
	string linea;
	ifstream archivo ("documento.txt");
	while (getline(archivo,linea)) {
		cout<<linea<<endl;
	}
	archivo.close();
	return 0;
}
