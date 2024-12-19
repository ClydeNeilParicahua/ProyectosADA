#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Player {
    int id;
    char name[50];
    int score;
    Player* next;
};

Player* createNode(int id, const char* name, int score) {
    Player* newNode = new Player;
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Player*& head, int id, const char* name, int score) {
    Player* newNode = createNode(id, name, score);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Player* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

double calculateAverage(Player* head) {
    if (head == NULL) {
        cout << "La lista está vacía. No se puede calcular el promedio." << endl;
        return 0;
    }
    double sum = 0;
    int count = 0;
    Player* temp = head;
    while (temp != NULL) {
        sum += temp->score;
        count++;
        temp = temp->next;
    }
    return sum / count;
}

Player* findHighestScore(Player* head) {
    if (head == NULL) return NULL;
    Player* highest = head;
    Player* temp = head->next;
    while (temp != NULL) {
        if (temp->score > highest->score) {
            highest = temp;
        }
        temp = temp->next;
    }
    return highest;
}

Player* findLowestScore(Player* head) {
    if (head == NULL) return NULL;
    Player* lowest = head;
    Player* temp = head->next;
    while (temp != NULL) {
        if (temp->score < lowest->score) {
            lowest = temp;
        }
        temp = temp->next;
    }
    return lowest;
}

void removeBelowAverage(Player*& head, double average) {
    while (head != NULL && head->score < average) {
        Player* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    Player* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->score < average) {
            Player* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        } else {
            current = current->next;
        }
    }
}

void freeList(Player*& head) {
    while (head != NULL) {
        Player* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Player* head = NULL;
    const char* fileName = "jugadores.txt";

    ifstream inputFile(fileName);
    if (!inputFile) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return 1;
    }

    char line[100];
    while (inputFile.getline(line, 100)) {
        char* token = strtok(line, "\t");
        if (token == NULL) continue;

        int id = atoi(token);
        token = strtok(NULL, "\t");
        if (token == NULL) continue;

        char name[50];
        strcpy(name, token);
        token = strtok(NULL, "\t");
        if (token == NULL) continue;

        int score = atoi(token);
        appendNode(head, id, name, score);
    }
    inputFile.close();

    double average = calculateAverage(head);
    cout << "Puntuacion Promedio: " << average << endl;

    Player* highest = findHighestScore(head);
    Player* lowest = findLowestScore(head);

    if (highest) {
        cout << "Puntuacion mas Alta: PlayerID=" << highest->id << ", PlayerName=" << highest->name
             << ", Score=" << highest->score << endl;
    }
    if (lowest) {
        cout << "Puntuacion mas Baja: PlayerID=" << lowest->id << ", PlayerName=" << lowest->name
             << ", Score=" << lowest->score << endl;
    }

    removeBelowAverage(head, average);
cout << "Se han eliminado los jugadores por debajo del promedio." << endl;


    return 0;
}

