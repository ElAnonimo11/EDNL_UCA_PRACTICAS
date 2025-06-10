#ifndef _EJERCICIO_3_P1_HPP_
#define _EJERCICIO_3_P1_HPP_

#include "../../../Abin.hpp"

/* Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine
 * la profundidad de este nodo en dicho árbol.  */

template<typename T>
int profundidad_Abin(const Abin<T>& A,typename Abin<T>::nodo n)
{
    int prof = 0;
    while (A.padre(n) != Abin<T>::NODO_NULO) {
        ++prof;
        n = A.padre(n);
    }
    return prof;
}

#endif
