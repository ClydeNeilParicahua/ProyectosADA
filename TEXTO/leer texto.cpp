#include <iostream>
#include <fstream>

using namespace std;

 void leeer();
 
int main() {
	leeer();
	
	return 0;
	
}

void leeer(){
	ifstream archivo;
	string texto;
	
	archivo.open("tortillaconqueso.txt",ios::in);
	
	if (archivo.fail()){ 
		cout << "No se puede abrir archivo"; 
		exit (1);
	}
	
	while (!archivo.eof()){ 
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close();
	}	
