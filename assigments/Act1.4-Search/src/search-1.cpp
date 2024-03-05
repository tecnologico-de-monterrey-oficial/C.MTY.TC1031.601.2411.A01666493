#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

bool busquedaSecuencial(const vector<int>& vec, int valor) {
    for (int elem : vec) {
        if (elem == valor) {
            return true;
        }
    }
    return false;
}

bool busquedaBinaria(const vector<int>& vec, int valor) {
    int bajo = 0;
    int alto = vec.size() - 1;
    while (bajo <= alto) {
        int medio = bajo + (alto - bajo) / 2;
        if (vec[medio] == valor) {
            return true;
        } else if (vec[medio] < valor) {
            bajo = medio + 1;
        } else {
            alto = medio - 1;
        }
    }
    return false;
}

int main() {
    srand(time(0)); 
    vector<int> numeros(10000);

    for (int& numero : numeros) {
        numero = 1 + rand() % 1000000;
    }

    sort(numeros.begin(), numeros.end());

    int valor;
    while (true) {
        cout << "Ingrese un número entre 1 y 1,000,000 (0 para salir): ";
        cin >> valor;
        if (valor == 0) {
            break;
        }

        auto start = chrono::high_resolution_clock::now();
        bool encontradoSecuencial = busquedaSecuencial(numeros, valor);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempoSecuencial = end - start;

        start = chrono::high_resolution_clock::now();
        bool encontradoBinario = busquedaBinaria(numeros, valor);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempoBinario = end - start;

        cout << "Resultado búsqueda secuencial: " << (encontradoSecuencial ? "Encontrado" : "No encontrado")
             << ". Tiempo: " << tiempoSecuencial.count() << " ms" << endl;
        cout << "Resultado búsqueda binaria: " << (encontradoBinario ? "Encontrado" : "No encontrado")
             << ". Tiempo: " << tiempoBinario.count() << " ms" << endl;
    }

    return 0;
}
