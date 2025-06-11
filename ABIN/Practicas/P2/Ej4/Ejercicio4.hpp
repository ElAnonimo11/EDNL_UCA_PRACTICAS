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

        void insertarRaiz(const T& e);
        void insertarHijoIzqdo(nodo n,const T& e);
        nodo padre(nodo n) const;

        ~Abin() {delete [] elems;}

        size_t num_nodos() const {return numNodos;}
        bool vacio() const {return numNodos == 0;}

    private:
        size_t prof_max,
               max_nodos,
               numNodos;
        T* elems;

        bool valido(nodo n) {return n < max_nodos && elems[n] != NODO_NULO;}

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
Abin<T>::Abin(size_t max_prof) : prof_max{max_prof} , max_nodos{size_t(std::pow(2,max_prof + 1)) + 1}, numNodos{0} , elems{new T[size_t(std::pow(2,max_prof + 1)) + 1]}
{
    for (size_t i = 0; i < max_prof; ++i) elems[i] = NODO_NULO;
}

template <typename T>
inline void Abin<T>::insertarRaiz(const T& e) {
    assert(vacio());
    elems[max_nodos / 2] = e;
    numNodos = 1;
}

template <typename T>
inline void Abin<T>::insertarHijoIzqdo(nodo n,const T& e) {
    assert(valido(n));
    int prof = profundidad(n);
    assert(prof < prof_max);
    nodo pos = n - (size_t)std::pow(2,prof + 1);
    assert(elems[pos] == NODO_NULO);
    elems[pos] = e;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::padre(nodo n) const {
    assert(valido(n));
    if (n == max_nodos / 2) return NODO_NULO;
    else {
        int prof = profundidad(n);
        bool es_hijizq = n % (nodo)std::pow(2,prof + 2) == (nodo)std::pow(2,prof) - 1;
        if (es_hijizq) return n + (nodo)std::pow(2,prof);
        else return n - (nodo)std::pow(2,prof);
    }
}

#endif
