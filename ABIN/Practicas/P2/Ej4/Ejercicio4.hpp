#ifndef _EJERCICIO_4_P2_HPP_
#define _EJERCICIO_4_P2_HPP_

#include <cassert>
#include <cmath>
#include <cstddef>
#include <limits>

/*
 * Una posible representación del TAD Árbol Binario consiste en almacenar los
 * elementos del árbol en un vector cuyo tamaño, 𝑁 = 2
 * 𝐻+1 − 1 , depende de la altura
 * máxima 𝐻 que pueda llegar a alcanzar el árbol. Cada nodo del árbol se corresponde con
 * una única posición del vector, la cual viene determinada por el recorrido en inorden del
 * árbol. Es decir, en el vector aparecen primero los nodos del subárbol izquierdo en inorden,
 * luego la raíz y a continuación los nodos del subárbol derecho también en inorden. Por
 * ejemplo, el árbol de la figura se representa como el vector
 * Define la clase genérica Abin<T> para esta representación.
 * b) Implementa una función miembro privada que calcule la altura de un nodo de un
 * árbol binario representado de la forma descrita.
 * c) Para esta representación implementa, al menos, el constructor de árboles vacíos y
 * las operaciones insertarRaiz(), insertarHijoIzqdo() y padre(), según la
 * especificación del TAD Árbol Binario vista en clase.
 */

template <typename T>
class Abin
{
    public:
        using nodo = size_t;
        static const nodo NODO_NULO;

        Abin(size_t max_prof);

    private:
        size_t prof_max,
               max_nodos;
        T* elems;

        int profundidad(nodo n) const;
};

/*Metodos privados */
template <typename T>
int Abin<T>::profundidad(nodo n) const
{
    assert(elems[n] != NODO_NULO);
    int left = 0,
        righ = max_nodos - 1;
    int prof = 0;
    // Busqueda binaria
    while (left <= righ) {
        int mid = (righ - left) / 2;
        if (mid == n) {
            return prof;
        } else if (mid < n) {
            left = mid;
        } else {
            righ = mid;
        }
        ++prof;
    }
    return prof;
}

/***************** */

template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO{std::numeric_limits<nodo>::max()};

template <typename T>
Abin<T>::Abin(size_t max_prof) : prof_max{max_prof} , max_nodos{size_t(std::pow(2,max_prof + 1)) + 1} , elems{new T[size_t(std::pow(2,max_prof + 1)) + 1]}
{
    for (size_t i = 0; i < max_prof ; ++i) elems[i] = NODO_NULO;
}



#endif
