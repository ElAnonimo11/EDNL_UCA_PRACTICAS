#include "Ejercicio1.hpp"
#include "../../../apo.hpp"

void eliminar_elem(Apo<int> &A, const int elem)
{
    Apo<int> aux(A.tamaMax());
    while (A.tama())
        if (A.cima() != elem)
        {
            aux.insertar(A.cima());
            A.suprimir();
        }
    A = aux;
}
