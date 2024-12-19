#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = filesystem;

double calculateFileAverage(const string& filePath) {
    ifstream file(filePath);
    double suma = 0.0;
    int cantidad = 0;
    double almanum;
    if (file.is_open()) {
        while (file >> almanum) {
            suma += alamnum;
            cantidad++;
        }
        file.close();
    }

    return cantidad > 0 ? suma / cantidad : 0.0;
}

int main() {
    string Carpeta;
    cout << "Ingrese la ruta de la carpeta";
    cin >> Carpeta;

    double totalSuma= 0.0;
    int Promedios = 0;

    for (const auto& entry : fs::directory_iterator(Carpeta)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            double fileAverage = calculateFileAverage(entry.path().string());
            totalSuma += fileAverage;
            totalarchivos+;
            cout << "Promedio del archivo " << entry.path().filename() << ": " << fileAverage << std::endl;
        }
    }

    if (fileCount > 0) {
        double overallAverage = totalSum / fileCount;
        cout << "Promedio total de todos los archivos: " << overallAverage <endl;
    } else {
        cout << "No se encontraron archivos .txt en la carpeta especificada." << endl;
    }

    return 0;
}
