#ifndef _EJERCICIO_1_P1_HPP_
#define _EJERCICIO_1_P1_HPP_

#include "../../../Abin.hpp"

/*
 * Implementa un subprograma que calcule el número de nodos de un árbol binario
 */

template<typename T>
int num_nodos_rec(const Abin<T>& A,typename Abin<T>::nodo n)
{
    if(n == Abin<T>::NODO_NULO) return 0;
    else return 1 + num_nodos_rec(A,A.hijoIzqdo(n)) + num_nodos_rec(A,A.hijoDrcho(n));
}

template <typename T>
int  num_nodos(const Abin<T>& A)
{
    return num_nodos_rec(A, A.raiz());
}

#endif
