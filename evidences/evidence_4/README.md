# EuropeCities Graph Traversal and Shortest Path

Este proyecto implementa un programa en C++ para manejar datos de ciudades europeas y sus conexiones por tren y automóvil. El programa puede leer los datos desde un archivo CSV, mostrar la lista de ciudades, mostrar y guardar listas de adyacencia, realizar recorridos BFS y DFS, y encontrar las rutas más cortas entre dos ciudades.

## Estructura del Proyecto

- `main.cpp`: Archivo principal que maneja la interacción con el usuario.
- `src/EuropeCities.cpp`: Implementación de las clases y métodos para manejar las ciudades y las conexiones.
- `include/EuropeCities.h`: Declaración de las clases y métodos.
- `data/EuropeCities.csv`: Archivo CSV que contiene los datos de las ciudades y las conexiones.
- `build/`: Directorio donde se genera el ejecutable.

## Compilación y Ejecución

### Prerrequisitos

- Un compilador C++ (por ejemplo, g++)
- Un sistema compatible con C++11

### Instrucciones

1. Clona el repositorio o descarga los archivos del proyecto.
2. Navega al directorio del proyecto.
3. Compila el código con el siguiente comando:

   ```bash
   g++ -std=c++11 -Iinclude -o build/main main.cpp src/EuropeCities.cpp
   ```

4. Ejecuta el programa:

   ```bash
   ./build/main
   ```

## Uso del Programa

El programa presenta un menú con las siguientes opciones:

1. **Desplegar las ciudades ordenadas por alfabeto**
   - Muestra las ciudades en orden alfabético.
   - Genera un archivo de salida llamado `output-1.out` con los datos ordenados.

2. **Desplegar la lista de adyacencias del grafo**
   - Muestra la lista de adyacencias del grafo.
   - Genera un archivo de salida llamado `output-2.out`.

3. **Desplegar los recorridos del grafo**
   - Solicita al usuario una ciudad de inicio válida.
   - Genera un archivo de salida llamado `output-3.out` con el recorrido BFS.
   - Genera un archivo de salida llamado `output-4.out` con el recorrido DFS.

4. **Solicitar al usuario dos ciudades y desplegar la siguiente información**
   - La ruta más corta entre las dos ciudades por tren, incluyendo el tiempo y la distancia.
   - La ruta más corta entre las dos ciudades por carro, incluyendo el tiempo y la distancia.
   - Si alguna de las dos ciudades no existe en el grafo, despliega un mensaje de error.

5. **Salir**
   - Termina el programa.

## Datos de Entrada

El archivo `EuropeCities.csv` debe tener el siguiente formato:

```csv
City A,City B,Time by train,Distance by train,Time by car,Distance by car
Ankara,Istanbul,5:36,576,4:30,433
Istanbul,Ankara,5:36,576,4:51,434
Athens,Thessaloniki,5:23,502,5:27,502
Thessaloniki,Athens,5:10,502,5:52,501
Athens,Patras,4:40,220,2:21,211
...
```

## Métodos Principales

### `EuropeCities`

- `void readCSV(const std::string& filename)`: Lee los datos del archivo CSV.
- `void identifyCities()`: Identifica las ciudades únicas y las ordena alfabéticamente.
- `void createGraph()`: Crea las listas de adyacencia para las conexiones por tren y por carro.
- `void printCities() const`: Imprime la lista de ciudades ordenadas alfabéticamente.
- `void saveCitiesToFile(const std::string& filename) const`: Guarda la lista de ciudades en un archivo.
- `void printAdjList() const`: Imprime las listas de adyacencia.
- `void saveAdjListToFile(const std::string& filename) const`: Guarda las listas de adyacencia en un archivo.
- `void bfs(const std::string& startCity, const std::string& filename) const`: Realiza un recorrido BFS desde una ciudad inicial y guarda el resultado en un archivo.
- `void dfs(const std::string& startCity, const std::string& filename) const`: Realiza un recorrido DFS desde una ciudad inicial y guarda el resultado en un archivo.
- `void findShortestPath(const std::string& startCity, const std::string& endCity) const`: Encuentra y muestra la ruta más corta entre dos ciudades por tren y por carro.

## Contribuciones

Las contribuciones son bienvenidas. Por favor, abre un "issue" para discutir cualquier cambio importante antes de realizar una "pull request".

## Licencia

Este proyecto está licenciado bajo la Licencia MIT. Ver el archivo `LICENSE` para más detalles.