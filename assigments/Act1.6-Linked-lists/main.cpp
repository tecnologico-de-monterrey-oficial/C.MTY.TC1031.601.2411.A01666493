#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include "include/LinkedList.h"

int menu() {
    std::cout << "\nMenú:" << std::endl;
    std::cout << "1. Agregar un elemento al principio" << std::endl;
    std::cout << "2. Agregar un elemento al final" << std::endl;
    std::cout << "3. Insertar un elemento después de un índice dado" << std::endl;
    std::cout << "4. Borrar un elemento" << std::endl;
    std::cout << "5. Borrar un elemento en una posición dada" << std::endl;
    std::cout << "6. Obtener un elemento de una posición dada" << std::endl;
    std::cout << "7. Actualizar un elemento dado" << std::endl;
    std::cout << "8. Actualizar un elemento en una posición dada" << std::endl;
    std::cout << "9. Encontrar un elemento" << std::endl;
    std::cout << "10. Mostrar el elemento de una posición" << std::endl;
    std::cout << "11. Asignar un elemento en una posición" << std::endl;
    std::cout << "12. Igualar una lista con otra" << std::endl;
    std::cout << "13. Salir" << std::endl;
    std::cout << "Ingrese su opción: ";
    int option;
    std::cin >> option;
    return option;
}

template<typename T>
void displayList(const LinkedList<T>& list) {
    std::cout << "Lista: ";
    for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    srand(time(nullptr)); 

    LinkedList<int> list;

    int option;
    do {
        option = menu();
        switch (option) {
            case 1: {
                int value;
                std::cout << "Ingrese el valor a agregar al principio: ";
                std::cin >> value;
                list.addFirst(value);
                break;
            }
            case 2: {
                int value;
                std::cout << "Ingrese el valor a agregar al final: ";
                std::cin >> value;
                list.addLast(value);
                break;
            }
            case 3: {
                int index, value;
                std::cout << "Ingrese el índice después del cual desea insertar: ";
                std::cin >> index;
                std::cout << "Ingrese el valor a insertar: ";
                std::cin >> value;
                list.insertAfter(index, value);
                break;
            }
            case 4: {
                int value;
                std::cout << "Ingrese el valor a borrar: ";
                std::cin >> value;
                list.remove(value);
                break;
            }
            case 5: {
                int index;
                std::cout << "Ingrese el índice del elemento a borrar: ";
                std::cin >> index;
                list.removeAt(index);
                break;
            }
            case 6: {
                int index;
                std::cout << "Ingrese el índice del elemento a obtener: ";
                std::cin >> index;
                try {
                    std::cout << "Elemento en la posición " << index << ": " << list.get(index) << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 7: {
                int oldValue, newValue;
                std::cout << "Ingrese el valor a actualizar: ";
                std::cin >> oldValue;
                std::cout << "Ingrese el nuevo valor: ";
                std::cin >> newValue;
                list.update(oldValue, newValue);
                break;
            }
            case 8: {
                int index, newValue;
                std::cout << "Ingrese el índice del elemento a actualizar: ";
                std::cin >> index;
                std::cout << "Ingrese el nuevo valor: ";
                std::cin >> newValue;
                try {
                    list[index] = newValue;
                } catch (const std::out_of_range& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 9: {
                int value;
                std::cout << "Ingrese el valor a buscar: ";
                std::cin >> value;
                std::cout << (list.contains(value) ? "El elemento está en la lista." : "El elemento no está en la lista.") << std::endl;
                break;
            }
            case 10: {
                int index;
                std::cout << "Ingrese el índice del elemento a mostrar: ";
                std::cin >> index;
                try {
                    std::cout << "Elemento en la posición " << index << ": " << list[index] << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 11: {
                int index, value;
                std::cout << "Ingrese el índice del elemento a asignar: ";
                std::cin >> index;
                std::cout << "Ingrese el nuevo valor: ";
                std::cin >> value;
                try {
                    list[index] = value;
                } catch (const std::out_of_range& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 12: {
                LinkedList<int> newList;
                newList = list;
                std::cout << "Lista duplicada." << std::endl;
                break;
            }
            case 13:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
        }
        displayList(list);
    } while (option != 13);

    return 0;
}
