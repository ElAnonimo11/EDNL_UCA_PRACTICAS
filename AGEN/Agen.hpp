#ifndef _AGEN_HPP_
#define _AGEN_HPP_

#include <cassert>
#include <cstddef>
#include <utility>


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
inline void Agen<T>::insertarRaiz(const T& e)
{
    assert(vacio());

    r = new celda{e};
    numNodos = 1;
}

template <typename T>
inline void Agen<T>::insertarHijoIzqdo(nodo n,const T& e)
{
    assert(n != NODO_NULO);

    nodo hizq = n->hizq;
    n->hizq = new celda{e,n,NODO_NULO,hizq};
    ++numNodos;
}

template <typename T>
inline void Agen<T>::insertarHermDrcho(nodo n,const T& e)
{
    assert(n != NODO_NULO);
    assert(n != r);

    nodo hder = n->hder;
    n->hder = new celda{e,n->padre,NODO_NULO,hder};
    ++numNodos;
}

template <typename T>
inline void Agen<T>::eliminarHijoIzqdo(nodo n)
{
    assert(n != NODO_NULO);

    nodo hizq = n->hizq;
    assert(hizq != NODO_NULO);
    assert(hizq->hizq == NODO_NULO);

    n->hizq = hizq->hder;
    delete hizq;
    --numNodos;
}

template <typename T>
inline void Agen<T>::eliminarHermDrcho(nodo n)
{
    assert(n != NODO_NULO);

    nodo hder  = n->hder;
    assert(hder != NODO_NULO);
    assert(hder->hizq == NODO_NULO);

    n->hder = hder->hder;
    delete hder;
    --numNodos;
}

template <typename T>
inline void Agen<T>::eliminarRaiz()
{
    assert(numNodos == 1);
    delete r;
    r = NODO_NULO;
    numNodos = 0;
}

template <typename T>
inline bool Agen<T>::vacio() const
{
    return numNodos == 0;
}

template <typename T>
inline size_t Agen<T>::tama() const
{
    return numNodos;
}

template <typename T>
inline const T& Agen<T>::elemento(nodo n) const
{
    assert(n != NODO_NULO);
    return n->elto;
}

template <typename T>
inline T& Agen<T>::elemento(nodo n)
{
    assert(n != NODO_NULO);
    return n->elto;
}

template <typename T>
inline typename Agen<T>::nodo Agen<T>::raiz() const
{
    return r;
}

template <typename T>
inline typename Agen<T>::nodo Agen<T>::padre(nodo n) const
{
    assert(n != NODO_NULO);
    return n->padre;
}

template <typename T>
inline typename Agen<T>::nodo Agen<T>::hijoIzqdo(nodo n) const
{
    assert(n != NODO_NULO);
    return n->hizq;
}

template <typename T>
inline typename Agen<T>::nodo Agen<T>::hermDrcho(nodo n) const
{
    assert(n != NODO_NULO);
    return n->hder;
}

template <typename T>
Agen<T>::Agen(const Agen& A) : r{copiar(A.r)}, numNodos{A.numNodos} {}

template <typename T>
Agen<T>& Agen<T>::operator=(const Agen& A)
{
    Agen aux(A);
    std::swap(r,aux.r);
    std::swap(numNodos,aux.numNodos);
    return *this;
}

template <typename T>
Agen<T>::~Agen()
{
    destruir(r);
}

template <typename T>
typename Agen<T>::nodo Agen<T>::copiar(nodo n)
{
    nodo m = NODO_NULO;
    if (n != NODO_NULO) {
        Agen A;
        A.r = new celda{n->elto};
        if (n->hizq != NODO_NULO) {
            A.r->hizq = copiar(n->hizq);
            A.r->hizq->padre = A.r;

            nodo hijo = A.r->hizq;
            nodo hder = n->hizq->hder;
            while (hder != NODO_NULO) {
                hijo = hijo->hder = copiar(hder);
                hijo->padre = A.r;
                hder = hder->hder;
            }
        }
        m = A.r ; A.r = NODO_NULO;
    }
    return m;
}

template <typename T>
void Agen<T>::destruir(nodo& n)
{
    if (n != NODO_NULO) {
        while (n->hizq != NODO_NULO) {
            nodo hder = n->hizq->hder;
            destruir(n->hizq);
            n->hizq = hder;
        }
        delete n;
        n = NODO_NULO;
    }
}

#endif
