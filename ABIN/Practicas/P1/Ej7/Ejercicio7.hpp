#ifndef _EJERCICIO_7_P1_HPP_
#define _EJERCICIO_7_P1_HPP_

#include "../../../Abin.hpp"
#include <cstdlib>

/*
 * Implementa un subprograma que determine si un árbol binario es o no pseudocompleto.
 * En este problema entenderemos que un árbol es pseudocompleto, si en el penúltimo nivel
 * del mismo cada uno de los nodos tiene dos hijos o ninguno.
 */

template <typename T>
bool pseudo_Abin_rec(const Abin<T>& A,typename Abin<T>::nodo n,int alt_act)
{
    if (n == Abin<T>::NODO_NULO) return true;
    else if (alt_act == 1) return (A.hijoIzqdo(n) == Abin<T>::NODO_NULO) == (A.hijoDrcho(n) == Abin<T>::NODO_NULO);    // xnor en el penultimo nivel si hay dos
    else return pseudo_Abin_rec(A, A.hijoIzqdo(n), alt_act - 1) && pseudo_Abin_rec(A, A.hijoDrcho(n), alt_act - 1);
}

template <typename T>
bool pseudo_Abin(const Abin<T>& A)
{
    return pseudo_Abin_rec(A, A.raiz(),A.altura_nodo(A.raiz()));
}

#endif
