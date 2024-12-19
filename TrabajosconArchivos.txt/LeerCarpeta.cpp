#include <iostream>
#include <dirent.h> 
using namespace std;
int main() {
    string carpeta = "C:\\Datos";

    DIR* dir;
    struct dirent* entry;

    dir = opendir(carpeta.c_str()); 
    if (dir == NULL) {
        std::cerr << "No se pudo abrir la carpeta: " << carpeta << std::endl;
        return 1;
    }

   cout << "Archivos en la carpeta \"" << carpeta << "\":" << std::endl;

    while ((entry = readdir(dir)) != NULL) {
cout << entry->d_name << std::endl; 
    }

    closedir(dir); 
    return 0;
}
