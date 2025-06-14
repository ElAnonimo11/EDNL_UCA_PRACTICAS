#ifndef _EJERCICIO_1_P3_HPP_
#define _EJERCICIO_1_P3_HPP_

#include "../../../Agen.hpp"
#include <algorithm>

/*
 * Implementa un subprograma que dado un árbol general nos calcule su grado.
 */

template <typename T>
int gradoAgen_rec(const Agen<T>& A,typename Agen<T>::nodo n)
{
    using nodo = typename Agen<T>::nodo;
    int max_grado = 0,
        grado_act = 0;
    nodo hij = A.hijoIzqdo(n);
    while (hij != Agen<T>::NODO_NULO) {
        ++grado_act;
        max_grado = std::max(max_grado,gradoAgen_rec(A, hij));
        hij = A.hermDrcho(hij);
    }
    return std::max(grado_act,max_grado);
}

template <typename T>
int gradoAgen(const Agen<T>& A)
{
    if (A.vacio()) return 0;
    else return gradoAgen_rec(A, A.raiz());
}

#endif
