#ifndef _EJERCICIO_2_P1_HPP_
#define _EJERCICIO_2_P1_HPP_

#include "../../../Abin.hpp"
#include <algorithm>

/*
 * Implementa un subprograma que calcule la altura de un árbol binario.
 */

template <typename T>
int altura_abin_rec(const Abin<T>& A,typename Abin<T>::nodo n)
{
    if (n == Abin<T>::NODO_NULO) return -1;
    else return 1 + std::max(altura_abin_rec(A, A.hijoIzqdo(n)),altura_abin_rec(A, A.hijoDrcho(n)));
}

template <typename T>
int altura_abin(const Abin<T>& A)
{
    return altura_abin_rec(A, A.raiz());
}

#endif
