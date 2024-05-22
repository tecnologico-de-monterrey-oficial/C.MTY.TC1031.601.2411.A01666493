#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "include/MaxHeap.h"
#include "include/MinHeap.h"

using namespace std;

vector<int> heap_sort_asc(vector<int>& arr) {
    MinHeap min_heap;
    for (int num : arr) {
        min_heap.push(num);
    }
    vector<int> sorted;
    while (!min_heap.empty()) {
        sorted.push_back(min_heap.pop());
    }
    return sorted;
}

vector<int> heap_sort_desc(vector<int>& arr) {
    MaxHeap max_heap;
    for (int num : arr) {
        max_heap.push(num);
    }
    vector<int> sorted;
    while (!max_heap.empty()) {
        sorted.push_back(max_heap.pop());
    }
    return sorted;
}

void menu() {
    MaxHeap max_heap;
    MinHeap min_heap;
    while (true) {
        cout << "Menú de opciones:\n";
        cout << "1. Insertar en MaxHeap\n";
        cout << "2. Extraer de MaxHeap\n";
        cout << "3. Mostrar tope de MaxHeap\n";
        cout << "4. Verificar si MaxHeap está vacío\n";
        cout << "5. Mostrar tamaño de MaxHeap\n";
        cout << "6. Insertar en MinHeap\n";
        cout << "7. Extraer de MinHeap\n";
        cout << "8. Mostrar tope de MinHeap\n";
        cout << "9. Verificar si MinHeap está vacío\n";
        cout << "10. Mostrar tamaño de MinHeap\n";
        cout << "11. Ordenar lista en orden ascendente (Heap sort con MinHeap)\n";
        cout << "12. Ordenar lista en orden descendente (Heap sort con MaxHeap)\n";
        cout << "13. Salir\n";

        int opcion;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            int valor;
            cout << "Ingrese el valor a insertar en MaxHeap: ";
            cin >> valor;
            max_heap.push(valor);
        } else if (opcion == 2) {
            try {
                cout << "Valor extraído de MaxHeap: " << max_heap.pop() << endl;
            } catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
        } else if (opcion == 3) {
            try {
                cout << "Tope de MaxHeap: " << max_heap.top() << endl;
            } catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
        } else if (opcion == 4) {
            cout << "MaxHeap está vacío: " << (max_heap.empty() ? "Sí" : "No") << endl;
        } else if (opcion == 5) {
            cout << "Tamaño de MaxHeap: " << max_heap.size() << endl;
        } else if (opcion == 6) {
            int valor;
            cout << "Ingrese el valor a insertar en MinHeap: ";
            cin >> valor;
            min_heap.push(valor);
        } else if (opcion == 7) {
            try {
                cout << "Valor extraído de MinHeap: " << min_heap.pop() << endl;
            } catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
        } else if (opcion == 8) {
            try {
                cout << "Tope de MinHeap: " << min_heap.top() << endl;
            } catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
        } else if (opcion == 9) {
            cout << "MinHeap está vacío: " << (min_heap.empty() ? "Sí" : "No") << endl;
        } else if (opcion == 10) {
            cout << "Tamaño de MinHeap: " << min_heap.size() << endl;
        } else if (opcion == 11) {
            vector<int> arr;
            int n;
            cout << "Ingrese el tamaño de la lista: ";
            cin >> n;
            cout << "Ingrese la lista de números: ";
            for (int i = 0; i < n; ++i) {
                int num;
                cin >> num;
                arr.push_back(num);
            }
            vector<int> sorted = heap_sort_asc(arr);
            cout << "Lista ordenada en orden ascendente: ";
            for (int num : sorted) {
                cout << num << " ";
            }
            cout << endl;
        } else if (opcion == 12) {
            vector<int> arr;
            int n;
            cout << "Ingrese el tamaño de la lista: ";
            cin >> n;
            cout << "Ingrese la lista de números: ";
            for (int i = 0; i < n; ++i) {
                int num;
                cin >> num;
                arr.push_back(num);
            }
            vector<int> sorted = heap_sort_desc(arr);
            cout << "Lista ordenada en orden descendente: ";
            for (int num : sorted) {
                cout << num << " ";
            }
            cout << endl;
        } else if (opcion == 13) {
            break;
        } else {
            cout << "Opción no válida, por favor seleccione una opción válida." << endl;
        }
    }
}

int main() {
    menu();
    return 0;
}