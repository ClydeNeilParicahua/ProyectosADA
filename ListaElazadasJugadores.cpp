#include <iostream>
#include <fstream>
#include <string>
#include <cmath>   // Biblioteca para redondear y manipular números
#include <ctime>   // Biblioteca para medir el tiempo
using namespace std;

struct Player {
    int id;
    string name;
    int score;
    Player* next;
};

// Función para agregar un nodo a la lista enlazada
void addPlayer(Player*& head, int id, const string& name, int score) {
    Player* newPlayer = new Player{id, name, score, NULL};
    if (!head) {
        head = newPlayer;
    } else {
        Player* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newPlayer;
    }
}

// Función para calcular el promedio de puntuaciones
double calculateAverage(Player* head) {
    if (!head) return 0.0;
    double sum = 0.0;
    int count = 0;
    Player* temp = head;
    while (temp) {
        sum += temp->score;
        count++;
        temp = temp->next;
    }
    return sum / count;
}

// Función para redondear un número a dos decimales
double roundToTwoDecimals(double num) {
    return floor(num * 100.0 + 0.5) / 100.0;
}

// Función para encontrar el jugador con la puntuación más alta y más baja
void findHighLow(Player* head, Player*& highest, Player*& lowest) {
    if (!head) return;
    highest = lowest = head;
    Player* temp = head->next;
    while (temp) {
        if (temp->score > highest->score) highest = temp;
        if (temp->score < lowest->score) lowest = temp;
        temp = temp->next;
    }
}

// Función para eliminar jugadores con puntuaciones por debajo del promedio
void removeBelowAverage(Player*& head, double average) {
    Player* temp = head;
    Player* prev = NULL;
    while (temp) {
        if (temp->score < average) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            Player* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

// Función para liberar la memoria de la lista enlazada
void freeList(Player*& head) {
    while (head) {
        Player* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Player* head = NULL;

    // Leer datos desde el archivo
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    int id, score;
    string name;
    while (inputFile >> id >> name >> score) {
        addPlayer(head, id, name, score);
    }
    inputFile.close();

    // Calcular el puntaje promedio
    double average = calculateAverage(head);
    average = roundToTwoDecimals(average); // Redondeo manual
    cout << "Puntaje Promedio: " << average << endl;

    // Encontrar los jugadores con puntuaciones más alta y más baja
    Player *highest = NULL, *lowest = NULL;
    findHighLow(head, highest, lowest);
    if (highest) {
        cout << "Puntuación Más Alta: ID=" << highest->id << ", Nombre=" << highest->name
             << ", Puntaje=" << highest->score << endl;
    }
    if (lowest) {
        cout << "Puntuación Más Baja: ID=" << lowest->id << ", Nombre=" << lowest->name
             << ", Puntaje=" << lowest->score << endl;
    }

    // Eliminar jugadores con puntuaciones por debajo del promedio y medir el tiempo
    time_t start = time(NULL); // Tiempo inicial
    removeBelowAverage(head, average);
    time_t end = time(NULL);   // Tiempo final

    cout << "Tiempo para eliminar jugadores por debajo del promedio: "
         << difftime(end, start) << " segundos" << endl;

    // Liberar memoria
    freeList(head);

    return 0;
}

