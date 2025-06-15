#ifndef EJERCICIO_1_P5_HPP
#define EJERCICIO_1_P5_HPP

#include "../../../apo.hpp"

/*
 * Dado un árbol binario de enteros donde el valor de cada nodo es menor que el de sus
 * hijos, implementa un subprograma para eliminar un valor del mismo preservando la
 * propiedad de orden establecida. Explica razonadamente la elección de la estructura de
 * datos.
 */

/*Lo que haremos sera usar un apo para guardar los hijos y volver a insertarlos en el lugar del padre*/

void eliminar_elem(Apo<int>& A,int elem);

#endif
