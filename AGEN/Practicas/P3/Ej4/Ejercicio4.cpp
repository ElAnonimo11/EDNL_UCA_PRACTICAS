#include "../../../Agen.hpp"
#include "Ejercicio4.hpp"

void podaAgen(Agen<int>& A,int elem)
{
    return podaAgen_rec(A, A.raiz(), elem);
}

void podaAgen_rec(Agen<int> &A, Agen<int>::nodo n, int elem)
{

}
