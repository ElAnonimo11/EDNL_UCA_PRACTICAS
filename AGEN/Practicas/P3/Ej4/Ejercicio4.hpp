#ifndef _EJERCICIO_4_P3_HPP_
#define _EJERCICIO_4_P3_HPP_

#include "../../../Agen.hpp"

/*
 * Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice
 * la poda de A a partir de x. Se asume que no hay elementos repetidos en A.
 */

void podaAgen(Agen<int>& A,int elem);
void podaAgen_rec(Agen<int>& A,Agen<int>::nodo n,int elem);

void podar_Agen(Agen<int>& A,Agen<int>::nodo n);

#endif
