#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Clase para representar un vértice
template <typename T>
class Vertice
{
public:
    T dato;
    Vertice(T dato) : dato(dato) {}
};

// Clase para representar un grafo con matriz de adyacencias
template <typename T>
class GrafoMatrizAdyacencia
{
private:
    vector<vector<bool>> matriz;
    vector<Vertice<T>> vertices;

public:
    // Constructor
    GrafoMatrizAdyacencia() {}

    // Agregar vértice
    void agregar_vertice(T dato)
    {
        vertices.push_back(Vertice<T>(dato));
        matriz.resize(vertices.size());
        for (int i = 0; i < vertices.size(); i++)
        {
            matriz[i].resize(vertices.size());
        }
    }

    // Agregar arista
    void agregar_arista(T origen, T destino)
    {
        int i = buscar_vertice(origen);
        int j = buscar_vertice(destino);
        if (i != -1 && j != -1)
        {
            matriz[i][j] = true;
            matriz[j][i] = true; // Grafo no dirigido
        }
    }

    // Eliminar vértice
    void eliminar_vertice(T dato)
    {
        int i = buscar_vertice(dato);
        if (i != -1)
        {
            vertices.erase(vertices.begin() + i);
            matriz.erase(matriz.begin() + i);
            for (vector<bool> &fila : matriz)
            {
                fila.erase(fila.begin() + i);
            }
        }
    }

    // Eliminar arista
    void eliminar_arista(T origen, T destino)
    {
        int i = buscar_vertice(origen);
        int j = buscar_vertice(destino);
        if (i != -1 && j != -1)
        {
            matriz[i][j] = false;
            matriz[j][i] = false; // Grafo no dirigido
        }
    }

    // Imprimir grafo
    void imprimir()
    {
        cout << "Matriz de adyacencias:" << endl;
        for (int i = 0; i < vertices.size(); i++)
        {
            for (int j = 0; j < vertices.size(); j++)
            {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Buscar vértice por dato
    int buscar_vertice(T dato)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i].dato == dato)
            {
                return i;
            }
        }
        return -1;
    }
};

// Clase para representar un grafo con lista de adyacencias
template <typename T>
class GrafoListaAdyacencia
{
private:
    map<T, vector<T>> lista_adyacencia;

public:
    // Constructor
    GrafoListaAdyacencia() {}

    // Agregar vértice
    void agregar_vertice(T dato)
    {
        if (lista_adyacencia.find(dato) == lista_adyacencia.end())
        {
            lista_adyacencia[dato] = vector<T>();
        }
    }

    // Agregar arista
    void agregar_arista(T origen, T destino)
    {
        lista_adyacencia[origen].push_back(destino);
        lista_adyacencia[destino].push_back(origen); // Grafo no dirigido
    }

    // Eliminar vértice
    void eliminar_vertice(T dato)
    {
        if (lista_adyacencia.find(dato) != lista_adyacencia.end())
        {
            // Eliminar aristas que contengan el vértice
            for (T adyacente : lista_adyacencia[dato])
            {
                lista_adyacencia[adyacente].erase(remove(lista_adyacencia[adyacente].begin(), lista_adyacencia[adyacente].end(), dato));
            }
            lista_adyacencia.erase(dato);
        }
    }
};