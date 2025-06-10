#ifndef _EJERCICIO_1_P2_HPP_
#define _EJERCICIO_1_P2_HPP_

#include "../../../Abin.hpp"

/*
 * Dos árboles binarios son similares cuando tienen idéntica estructura de ramificación,
 * es decir, ambos son vacíos, o en caso contrario, tienen subárboles izquierdo y derecho
 * similares. Implementa un subprograma que determine si dos árboles binarios son
 * similares.
 */

template <typename T>
bool es_similar_Abin_rec(const Abin<T>& A,typename Abin<T>::nodo nA,const Abin<T>& B,typename Abin<T>::nodo nB)
{

}

template <typename T>
bool es_similar_Abin(const Abin<T>& A,const Abin<T>& B)
{
    return es_similar_Abin_rec(A, A.raiz(), B, B.raiz());
}

#endif
