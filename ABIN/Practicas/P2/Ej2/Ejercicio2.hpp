#ifndef _EJERCICIO_2_P2_HPP_
#define _EJERCICIO_2_P2_HPP_

#include "../../../Abin.hpp"

/*
 * Para un árbol binario B, podemos construir el árbol binario reflejado B^R
 * cambiando los subárboles izquierdo y derecho en cada nodo. Implementa un
 * subprograma que devuelva el árbol binario reflejado de uno dado.
 */

template <typename T>
void reflejar_Abin_rec(const Abin<T>& A,typename Abin<T>::nodo nA,const Abin<T>& B,typename Abin<T>::nodo nB)
{
    if (A.hijoIzqdo(nA) != Abin<T>::NODO_NULO) {
        B.insertarHijoDrcho(nB, A.elemento(A.hijoIzqdo(nA)));
        reflejar_Abin_rec(A, A.hijoIzqdo(nA), B, B.hijoDrcho(nB));
    }
    if (A.hijoDrcho(nA) != Abin<T>::NODO_NULO) {
        B.insertarHijoIzqdo(nB, A.elemento(A.hijoDrcho(nA)));
        reflejar_Abin_rec(A, A.hijoDrcho(nA), B, B.hijoIzqdo(nB));
    }
}

template <typename T>
Abin<T> reflejar_Abin(const Abin<T> &A)
{
    Abin<T> B;
    if (!A.vacio()) {
        B.insertarRaiz(A.elemento(A.raiz()));
        reflejar_Abin_rec(A, A.raiz(), B, B.raiz());
    }
    return B;
}

#endif
