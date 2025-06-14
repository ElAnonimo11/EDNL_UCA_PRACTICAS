#ifndef _EJERCICIO_3_P3_HPP_
#define _EJERCICIO_3_P3_HPP_

#include "../../../Agen.hpp"
#include <algorithm>
#include <limits>

/*
 * Se define el desequilibrio de un árbol general como la máxima diferencia entre las alturas
 * de los subárboles más bajo y más alto de cada nivel. Implementa un subprograma que calcule
 * el grado de desequilibrio de un árbol general
 */


template <typename T>
int alturaAgen_rec(const Agen<T>& A,typename Agen<T>::nodo n)
{
    if (n == Agen<T>::NODO_NULO) return -1;
    int alt_max_hij = 0;
    for (typename Agen<T>::nodo hij = A.hijoIzqdo(n); hij != Agen<T>::NODO_NULO ; hij = A.hermDrcho(hij)) {
        alt_max_hij = std::max(alt_max_hij,alturaAgen_rec(A, hij));
    }
    return 1 + alt_max_hij;
}

/*Esta de adorno */
template <typename T>
int alturaAgen(const Agen<T>& A)
{
    return alturaAgen_rec(A, A.raiz());
}

template <typename T>
int max_diffAgen_rec(const Agen<T>& A,typename Agen<T>::nodo n)
{
    if(n == Agen<T>::NODO_NULO || A.hijoIzqdo(n) == Agen<T>::NODO_NULO) return 0;
    int alt_max = 0,
        alt_min = std::numeric_limits<int>::max(),
        diff_max = 0;
    for (typename Agen<T>::nodo hij = A.hijoIzqdo(n); hij != Agen<T>::NODO_NULO ; hij = A.hermDrcho(hij)) {
        int alt_hij = alturaAgen_rec(A, hij);
        alt_max = std::max(alt_max, alt_hij);
        alt_min = std::min(alt_min, alt_hij);
        diff_max = std::max(diff_max, max_diffAgen_rec(A, hij));
    }
    return std::max(diff_max, alt_max - alt_min);
}

template <typename T>
int max_diffAgen(const Agen<T>& A)
{
    return max_diffAgen_rec(A, A.raiz());
}

#endif
