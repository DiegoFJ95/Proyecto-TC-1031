# Proyecto-TC-1031
Proyecto de estructuras de datos y algoritmos fundamentales.
Diego Isaac Fuentes Juvera A01705506

Correr con mingw: g++ main.cpp EquipoPokemon.h

//Al ordenar alfabéticamente las mayúsculas se despliegan primero que las minúsculas por su valor ASCII.



## SICT0301 Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.



El programa implementa un algoritmo de ordenamiento de tipo Bubble Sort en los métodos sort_nombre(), sort_tipo1(), sort_tipo2(), sort_vida(), sort_ataque(), sort_defensa(), y sort_velocidad() para poder ordenar a los elementos (pokemon) de la clase equipo (una lista doblemente ligada) según cada parámetro. Dentro del algoritmo de ordenamiento también se incluye el método swap(), el cuál intercambia los apuntadores de 2 elementos y modifica los apuntadores de sus elementos circundantes para reordenar la lista. Este método tiene una complejidad de O(1) debido a que ya conoce previamente la posición de los elementos, por lo que no debe recorrer la estructura, y solo debe hacer un número fijo de operaciones para intercambiar sus apuntadores, por lo que no añade complejidad a los métodos de ordenamiento. La complejidad de los métodos de ordenamiento es de O(N²) ya que el algoritmo debe verificar la estructura completa una vez en búsqueda de un elemento mayor/menor por cada elemento que contenga.



### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa



***Constructores***  Tanto de la clase Pokemon y Equipo tienen una complejidad de O(1) ya que solo rellenan los atributos predeterminados con valores dados.

***empty()***  O(1) porque solo comprueba si la cabeza y la cola de la lista están vacías.

***addFirst()***  O(1) ya que crea un nuevo elemento y lo pone al inicio de la lista, con posición conocida al estar en head.

***add()***  O(1) debido a que funciona igual que addFirst() solo que lo añade al final definiendolo como la nueva tail.

***removeFisrt()***  O(1) puesto que elimina head y redefine al siguiente elemento como la nueva head.

***remove()***  O(N) dado que debe recorrer la estructura hasta la posición especificada para llevar a cabo la eliminación del elemento.

***clear()***  O(N) ya que recorre toda la estructura para ir eliminando a cada elemento.

***toString()***  O(N) porque recorre toda la estructura y va añadiendo los parámetros de cada elemento a un string.

***IndexToString()***  O(N) pues recorre toda la estructura hasta llegar al elemento deseado para añadir sus parámetros a un string.

***indexOf()***  O(N) ya que recorre toda la estructura hasta encontrar un elemento que coincida con la condición de búsqueda para devolver su posición.



### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.



***Carga de archivos*** O(N) debido a que debe recorrer todo el archivo hasta encontrar el caracter de fin de archivo (^Z) para determinar la cantidad de datos a cargar.

***Lectura de archivos***  O(N) pues depende de la cantidad de elementos que se incluyan, pues debe añadir todos uno por uno a la estructura usando el método add().

***Escritura de archivos*** O(1) porque toma los parámetros dados por el usuario y los añade al final del archivo de guardado.

***Eliminación de archivo*** O(N) ya que recorre el archivo para eliminar los datos previos a la apartura y establece el final del archivo al inicio del mismo.

***Menú*** O(N) siendo N el número de acciones que el usuario decida hacer dentro del menú, ya que es un ciclo infinito hasta que el usuario decide salir.

***Complejidad de todo el programa*** O(N²) siendo N el número de Elementos con los que se opere en la estructura, ya que el proceso más complejo a ejecutar es el ordenamiento. 
