#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

#ifdef _WIN32
    #define CLEAR_COMMAND "CLS"
#else
    #define CLEAR_COMMAND "clear"
#endif

using namespace std;

class HashTable {
private:
    vector<string> table;
    int size;
    const string DELETED = "__DELETED__";

    int hashFunction(const string &matricula) {
        int hash = 0;
        for (char c : matricula) {
            hash = (hash * 31 + c) % size;
        }
        return hash;
    }

public:
    HashTable(int size) : size(size) {
        table.resize(size, "");
    }

    void insert(const string &matricula) {
        int index = hashFunction(matricula);
        int originalIndex = index;
        while (!table[index].empty() && table[index] != matricula && table[index] != DELETED) {
            index = (index + 1) % size;
            if (index == originalIndex) {
                cout << "Table is full, cannot insert." << endl;
                return;
            }
        }
        table[index] = matricula;
        cout << "Inserted " << matricula << " at index " << index << endl;
    }

    void remove(const string &matricula) {
        int index = hashFunction(matricula);
        int originalIndex = index;
        while (!table[index].empty()) {
            if (table[index] == matricula) {
                table[index] = DELETED;
                cout << "Removed " << matricula << " from index " << index << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == originalIndex) {
                cout << "Matricula not found." << endl;
                return;
            }
        }
        cout << "Matricula not found." << endl;
    }

    int findStudentId(const string &matricula) {
        int index = hashFunction(matricula);
        int originalIndex = index;
        while (!table[index].empty()) {
            if (table[index] == matricula) {
                return index;
            }
            index = (index + 1) % size;
            if (index == originalIndex) {
                return -1;
            }
        }
        return -1;
    }

    void display() {
        cout << "+-------+----------------+" << endl;
        cout << "| Index | Matricula      |" << endl;
        cout << "+-------+----------------+" << endl;
        for (int i = 0; i < size; ++i) {
            if (!table[i].empty() && table[i] != DELETED) {
                cout << "| " << setw(5) << i << " | " << setw(14) << table[i] << " |" << endl;
            }
        }
        cout << "+-------+----------------+" << endl;
    }
};

int countLines(const string &filename) {
    ifstream file(filename);
    int lines = 0;
    string line;
    while (getline(file, line)) {
        ++lines;
    }
    return lines;
}

void loadMatriculas(HashTable &hashTable, const string &filename) {
    ifstream file(filename);
    string matricula;
    while (file >> matricula) {
        hashTable.insert(matricula);
    }
}

void clearScreen() {
    system(CLEAR_COMMAND);
}

int main() {
    string filename = "Matriculas-1.txt";
    int size = countLines(filename); // Size of the hash table based on number of records
    HashTable hashTable(size);

    loadMatriculas(hashTable, filename);

    int choice;
    string matricula;

    do {
        clearScreen();
        cout << "Menu:\n";
        cout << "1. Insertar matrícula\n";
        cout << "2. Eliminar matrícula\n";
        cout << "3. Buscar matrícula\n";
        cout << "4. Mostrar tabla\n";
        cout << "5. Salir\n";
        cout << "Ingrese su opción: ";
        cin >> choice;

        clearScreen();
        switch (choice) {
            case 1:
                cout << "Ingrese la matrícula a insertar: ";
                cin >> matricula;
                hashTable.insert(matricula);
                break;
            case 2:
                cout << "Ingrese la matrícula a eliminar: ";
                cin >> matricula;
                hashTable.remove(matricula);
                break;
            case 3:
                cout << "Ingrese la matrícula a buscar: ";
                cin >> matricula;
                int index;
                index = hashTable.findStudentId(matricula);
                if (index != -1) {
                    cout << "Matrícula encontrada en el índice " << index << endl;
                } else {
                    cout << "Matrícula no encontrada." << endl;
                }
                break;
            case 4:
                hashTable.display();
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
        if (choice != 5) {
            cout << "Presione cualquier tecla para continuar...";
            cin.ignore().get(); // Wait for user to press a key
        }
    } while (choice != 5);

    return 0;
}