#ifndef _EJERCICIO_6_P1_HPP_
#define _EJERCICIO_6_P1_HPP_

#include "../../../Abin.hpp"
#include <algorithm>
#include <cstdlib>

/*
 * Implementa un subprograma que determine el nivel de desequilibrio de un árbol binario,
 * definido como el máximo desequilibrio de todos sus nodos. El desequilibrio de un nodo se
 * define como la diferencia entre las alturas de los subárboles del mismo.
 */

template <typename T>
int nivel_desequilibrio_rec(const Abin<T>& A,typename Abin<T>::nodo n)
{
    if(n == Abin<T>::NODO_NULO) return 0;
    else {
        int hi = 0,
            hd = 0;
        if (A.hijoIzqdo(n) != Abin<T>::NODO_NULO) hi = A.altura_nodo(A.hijoIzqdo(n));
        if (A.hijoDrcho(n) != Abin<T>::NODO_NULO) hd = A.altura_nodo(A.hijoDrcho(n));
        return std::max({
            std::abs(hi - hd),
            nivel_desequilibrio_rec(A, A.hijoIzqdo(n)),
            nivel_desequilibrio_rec(A, A.hijoDrcho(n))
        });
    }
}

template <typename T>
int nivel_desequilibrio(const Abin<T>& A)
{
    return nivel_desequilibrio_rec(A,A.raiz());
}

#endif
