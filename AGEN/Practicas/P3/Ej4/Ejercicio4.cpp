#include "../../../Agen.hpp"
#include "Ejercicio4.hpp"

void podaAgen(Agen<int>& A,int elem)
{
    return podaAgen_rec(A, A.raiz(), elem);
}

void podaAgen_rec(Agen<int> &A, Agen<int>::nodo n, int elem)
{
    if (n != Agen<int>::NODO_NULO) {
        // Si el elemento es el buscado, llamamos al eliminador
        if (A.elemento(n) == elem) {
            podar_Agen(A, n);
        // Si no buscamos recursivamente
        } else {
            auto hij = A.hijoIzqdo(n);
            while (hij != Agen<int>::NODO_NULO) {
                podaAgen_rec(A, hij, elem);
                hij = A.hermDrcho(hij);
            }
        }
    }
}

void podar_Agen(Agen<int>& A, Agen<int>::nodo n)
{
    if (n != Agen<int>::NODO_NULO) {
        // Primero eliminamos a sus hijos, empezando por el hijo izquierdo
        while (A.hijoIzqdo(n) != Agen<int>::NODO_NULO) {
            podar_Agen(A, A.hijoIzqdo(n));
            A.eliminarHijoIzqdo(n);
        }
        // Buscamos a su hermano izquierdo para eliminarse, si es que no es el hijo izquierdo del padre ;; o si es raiz
        auto padr = A.padre(n);
        if (padr == Agen<int> ::NODO_NULO) {
            A.eliminarRaiz();
        } else if (n == A.hijoIzqdo(padr)) {
            A.eliminarHijoIzqdo(padr);
        } else {
            auto hij = A.hijoIzqdo(padr);
            while (A.hermDrcho(hij) != n) hij = A.hermDrcho(hij);
            A.eliminarHermDrcho(hij);
        }
    }
}
