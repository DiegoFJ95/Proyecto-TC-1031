# Proyecto-TC-1031
Proyecto de estructuras de datos y algoritmos fundamentales.

Correr con mingw: g++ main.cpp EquipoPokemon.h

## SICT0301 Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

El programa implementa un algoritmo de ordenamiento de tipo Bubble Sort en los métodos sort_nombre(), sort_tipo1(), sort_tipo2(), sort_vida(), sort_ataque(), sort_defensa(), y sort_velocidad() para poder ordenar a los elementos (pokemon) de la clase equipo (una lista doblemente ligada) según cada parámetro. Dentro del algoritmo de ordenamiento también se incluye el método swap(), el cuál intercambia los apuntadores de 2 elementos y modifica los apuntadores de sus elementos circundantes para reordenar la lista. Este método tiene una complejidad de O(1) debido a que ya conoce previamente la posición de los elementos, por lo que no debe recorrer la estructura, y solo debe hacer un número fijo de operaciones para intercambiar sus apuntadores, por lo que no añade complejidad a los métodos de ordenamiento. La complejidad de los métodos de ordenamiento es de O(N²) ya que el algoritmo debe verificar la estructura completa una vez en búsqueda de un elemento mayor/menor por cada elemento que contenga.

### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa

*Constructores*
Tanto de la clase Pokemon y Equipo tienen una complejidad de O(1) ya que solo rellenan los atributos predeterminados con valores dados.

*empty()*
O(1) al comprobar si la cabeza y la cola de la lista están vacías.

*addFirst()*
O(1) ya que crea un nuevo elemento y lo pone al inicio de la lista, con posición conocida al estar en head.

*add()*
O(1) ya que funciona igual que addFirst() solo que lo añade al final definiendolo como la nueva tail.

*removeFisrt()*
O(1) ya que elimina head y redefine al siguiente elemento como la nueva head.

*remove()*
O(N) ya que debe recorrer la estructura hasta la posición especificada para llevar a cabo la eliminación del elemento.

*clear()*
O(N) ya que recorre toda la estructura para ir eliminando a cada elemento.

*toString()*
O(N) ya que recorre toda la estructura y va añadiendo los parámetros de cada elemento a un string.

*IndexToString()*
O(N) ya que recorre toda la estructura hasta llegar al elemento deseado para añadir sus parámetros a un string.

*indexOf()*
O(N) ya que recorre toda la estructura hasta encontrar un elemento que coincida con la condición de búsqueda para devolver su posición.

### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.


