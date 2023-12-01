# Proyecto-TC-1031
Proyecto de estructuras de datos y algoritmos fundamentales.

Diego Isaac Fuentes Juvera A01705506.

Correr con mingw: g++ main.cpp EquipoPokemon.h

##Anotaciones

- Al ordenar alfabéticamente las mayúsculas se despliegan primero que las minúsculas por su valor ASCII.
- Tratar de introducir la información con el tipo de dato correcto para el correcto funcionamiento del programa.

##Descripción del programa

El programa está basado en la saga de videojuegos de Pokemon, donde el jugador puede capturar y coleccionar diferentes Pokemon. Este programa ofrece esa misma funcionalidad, donde el usuario puede tener su propio equipo de Pokemon ilimitados, además de agregar y eliminar nuevos pokemon, ordenarlos según sus características, guardar sus nuevos pokemon para la siguiente sesión, etc. todo a través de la consola.

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

## SICT0302 Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Seleccione el algoritmo de Bubble Sort ya que este solo requiere de una función auxiliar para intercambiar elementos, lo que es conveniente ya que, al trabajar con apuntadores, implimentar varias funciones auxiliares puede volverse muy complicado pues es más dificil localizar el error de lógica en el programa. Además una característica del Bubble Sort es que es estable, osea que mantiene el orden relativo previo de los elementos al ordenarlos y encontrarse con similitudes, lo que es conveniente para mi programa ya que permite ordenar por diferentes parámetros, lo que habilita que el usuario decida parámetros primarios, secundarios, terciarios, etc. por los cuales ordenar la estructura.
Otra ventaja es que Bubble Sort no requiere de una estructura auxiliar donde hacer modificaciones, o de copiar la estructura completamente para ordenarla, si no que todas las operaciones se llevan a cabo dentro de la estructura base, ahorrando memoria.

### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.
Elegí una lista doblemente ligada ya que me permite que el usuario tenga una cantidad indefinida de datos a almacenar, y que pueda operar con estos de la misma manera sin importar cuantos sean, lo que vuelve muy intuitivo el uso del programa. Además es una estrcutura con métodos de acceso y modificación fáciles de implementar, pues está dispuesta de manera secuencial y al tener 2 apuntadores fijos para el inicio y el final de la estructura permite que métodos como add() tengan una complejidad de O(1) al no tener que recorrer el arreglo para llevarse a cabo. También permite un ordenamiento directo y sin ambiguedad al estar dispuesta de manera lineal.

## SICT0303 Implementa acciones científicas
### Implementa mecanismos para consultar información de las estructras correctos
Implemete differentes métodos que permiten acceder y desplegar toda la información necesaria sobre la estructura para el funcionamiento del programa, como los métodos toString() e IndexToString() que permiten convertir los datos de estructura en un formato de texto que el usuario puede interpretar. También para el funcionamiento del programa métodos como indexof() permiten determinar la ubicación de un elemento a partir de un dato que el usuario conoce, como lo es su nombre.

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta
A través de la librería Fstream y abriendo el archivo con los datos predeterminados como un objeto de la clase ifstream puedo leer todos sus contenidos y asignarlos de manera consciente a variables específicas que me permiten después crear elementos en mi estructura de datos para poder probar el programa sin la necesidad de ingresar datos de forma manual. Este mismo funcionamineto es aplicado para el archivo de guardado de elementos del usuario para cargarlos si así se desea.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
También haciendo uso de la librería Fstream puedo generar un archivo de guardado al momento en que el usuario decide añadir un nuevo Pokemon a su equipo, mismo archivo que guarda los Pokémon creados en sesiones anteriores y que puede ser borrado en cualquier momento si así lo decide el usuario.


