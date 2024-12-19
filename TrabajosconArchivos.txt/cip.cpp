#include <iostream>
#include <fstream>

using namespace std;

 void write();
 
int main() {
	write();
	 
	return 0;
}

void write (){
	ofstream archivo;
	string nombrearchivo,contenido;
	
	cout<<"escriba nombre del archivo";
	getline (cin,nombrearchivo);
	archivo.open(nombrearchivo.c_str(),ios::out); // abriendo archivo
	
	if (archivo.fail()){
		cout << "No se puede abrir archivo";
		exit (1);
	}
	
	cout<<"digite texto que va contener";
	getline (cin,contenido);
	archivo << contenido<< endl;
	archivo << " Se trata del sistema de chat que utiliza inteligencia artificial, y que a finales del 2022 supuso una auténtica revolución en el mundo digital. Ahora, estamos inmersos en una era de la IA, per ChatGPT sigue siendo uno de sus principales protagonistas, junto a su hermano de pago ChatGPT Plus" ;
	;
	
	
	archivo.close();
	}	


