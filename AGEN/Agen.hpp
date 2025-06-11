#ifndef _AGEN_HPP_
#define _AGEN_HPP_

#include <cassert>
#include <cstddef>


template <typename T>
class Agen
{
    struct celda;
    public:
        using nodo = celda*;
        static const nodo NODO_NULO;

        Agen();

        void insertarRaiz(const T& e);
        void insertarHijoIzqdo(nodo n, const T& e);
        void insertarHermDrcho(nodo n, const T& e);
        void eliminarHijoIzqdo(nodo n);
        void eliminarHermDrcho(nodo n);
        void eliminarRaiz();

        bool vacio() const;
        size_t tama() const;
        const T& elemento(nodo n) const; // Lectura en Agen const
        T& elemento(nodo n); // Lectura/escritura en Agen no-const
        nodo raiz() const;
        nodo padre(nodo n) const;
        nodo hijoIzqdo(nodo n) const;
        nodo hermDrcho(nodo n) const;

        Agen(const Agen& A); // Ctor. de copia
        Agen& operator =(const Agen& A); // Asignación de árboles
        ~Agen();

    private:
        struct celda
        {
            T elto;
            nodo padre,hizq,hder;
        };

        nodo r;
        size_t numNodos;
        nodo copiar(nodo n);
        void destruir(nodo& n);
};

template <typename T>
const typename Agen<T>::nodo Agen<T>::NODO_NULO{nullptr};

template <typename T>
Agen<T>::Agen() : r{NODO_NULO} , numNodos{0} {}

template <typename T>
void Agen<T>::insertarRaiz(const T& e)
{
    assert(vacio());

    r = new celda{e};
    numNodos = 1;
}

template <typename T>
void Agen<T>::insertarHijoIzqdo(nodo n,const T& e)
{
    assert(n != NODO_NULO);

    nodo hizq = n->hizq;
    n->hizq = new celda{e,n,NODO_NULO,hizq};
    ++numNodos;
}

template <typename T>
void Agen<T>::insertarHermDrcho(nodo n,const T& e)
{
    assert(n != NODO_NULO);
    assert(n != r);

    nodo hder = n->hder;
    n->hder = new celda{e,n->padre,NODO_NULO,hder};
    ++numNodos;
}

#endif
