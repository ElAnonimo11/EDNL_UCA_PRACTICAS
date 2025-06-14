#ifndef _EJERCICIO_2_P3_HPP_
#define _EJERCICIO_2_P3_HPP_

#include "../../../Agen.hpp"
#include <cassert>

/*
 * Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine
 * la profundidad de éste nodo en el árbol.
*/

template<typename T>
int prof_nodoAgen(const Agen<T>& A,typename Agen<T>::nodo n)
{
    assert(n != Agen<T>::NODO_NULO);
    int profundidad = 0;
    for (typename Agen<T>::nodo padre = A.padre(n); padre != Agen<T>::NODO_NULO ; padre = A.padre(padre))
        ++profundidad;
    return profundidad;
}

#endif
