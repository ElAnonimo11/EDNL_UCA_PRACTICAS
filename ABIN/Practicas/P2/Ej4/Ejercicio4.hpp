#ifndef _EJERCICIO_4_P2_HPP_
#define _EJERCICIO_4_P2_HPP_

#include <cstddef>
#include <limits>

/*Una posible representación del TAD Árbol Binario consiste en almacenar los
 * elementos del árbol en un vector cuyo tamaño, 𝑁 = 2
 * 𝐻+1 − 1 , depende de la altura
 * máxima 𝐻 que pueda llegar a alcanzar el árbol. Cada nodo del árbol se corresponde con
 * una única posición del vector, la cual viene determinada por el recorrido en inorden del
 * árbol. Es decir, en el vector aparecen primero los nodos del subárbol izquierdo en inorden,
 * luego la raíz y a continuación los nodos del subárbol derecho también en inorden. Por
 * ejemplo, el árbol de la figura se representa como el vector
 */

template <typename T>
class Abin
{
    public:
        using nodo = size_t;
        static const nodo NODO_NULO;

    private:
        size_t prof_max,
               max_nodos;
        T* elems;
};

template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO{std::numeric_limits<nodo>::max()};

#endif
