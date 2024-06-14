# Hash Table para Almacenar Matrículas

## Descripción

Este proyecto implementa una tabla hash en C++ para almacenar matrículas de estudiantes utilizando técnicas de hashing y manejo de colisiones con el método de sondeo lineal. La aplicación permite insertar, eliminar, buscar y mostrar matrículas almacenadas en la tabla hash.

## Funcionalidades

- **Insertar Matrícula**: Inserta una matrícula en la tabla hash.
- **Eliminar Matrícula**: Elimina una matrícula de la tabla hash.
- **Buscar Matrícula**: Busca una matrícula en la tabla hash y devuelve el índice donde se encuentra.
- **Mostrar Tabla**: Muestra el contenido de la tabla hash en formato tabular.

## Archivos

- `main.cpp`: Contiene la implementación de la clase `HashTable` y el menú interactivo.
- `Matriculas-1.txt`: Archivo de texto con las matrículas a cargar inicialmente en la tabla hash.

## Instrucciones de Uso

### Requisitos

- g++ (GNU Compiler Collection)

### Compilación y Ejecución

Para compilar y ejecutar el programa, utiliza el siguiente comando:

```bash
g++ -o build/main main.cpp -std=c++11 && ./build/main
