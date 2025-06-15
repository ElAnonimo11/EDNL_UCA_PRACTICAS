#ifndef APO_HPP
#define APO_HPP
#include <cassert>
#include <utility>


template <typename T>
class Apo
{
    public:
        explicit Apo(size_t max_Nodos = 0);

        void insertar(const T& e);
        void suprimir();
        const T& cima() const;
        bool vacio() const;
        size_t tama() const;
        size_t tamaMax() const;

        Apo(const Apo& A);
        Apo& operator=(const Apo& A);
        ~Apo();

    private:
        typedef size_t nodo;

        T* nodos; // Vector de elementos
        size_t  maxNodos, // Tamaño del vector
                numNodos; // Tamaño del Apo

        nodo padre(nodo i) const { return (i-1)/2; }
        nodo hIzq(nodo i) const { return 2*i+1; }
        nodo hDer(nodo i) const { return 2*i+2; }
        void flotar(nodo i);
        void hundir(nodo i);
};

template<typename T>
inline Apo<T>::Apo(size_t max_Nodos) : nodos{new T[max_Nodos]} , maxNodos{max_Nodos} , numNodos{0} {}

template<typename T>
void Apo<T>::insertar(const T &e)
{
    assert(numNodos < maxNodos);
    nodos[numNodos++] = e;
    if (numNodos > 1) flotar(numNodos-1);
}

template<typename T>
void Apo<T>::suprimir()
{
    assert(numNodos > 0);
    if (--numNodos > 0)
    {
        nodos[0] = nodos[numNodos];
        if (numNodos > 1) hundir(0);
    }
}

template<typename T>
const T& Apo<T>::cima() const
{
    assert(numNodos > 0);
    return nodos[0];
}

template<typename T>
bool Apo<T>::vacio() const
{
    return numNodos == 0;
}

template<typename T>
size_t Apo<T>::tama() const
{
    return numNodos;
}

template<typename T>
size_t Apo<T>::tamaMax() const
{
    return maxNodos;
}

template<typename T>
Apo<T>::Apo(const Apo &A) : Apo(A.maxNodos)
{
    if (!A.vacio())
    {
        numNodos = A.numNodos;
        for (size_t i = 0; i < numNodos ; ++i) nodos[i] = A.nodos[i];
    }
}

template<typename T>
Apo<T>& Apo<T>::operator=(const Apo &A)
{
    Apo aux(A);
    std::swap(nodos,aux.nodos);
    std::swap(numNodos,aux.numNodos);
    std::swap(maxNodos,aux.maxNodos);
    return *this;
}

template<typename T>
Apo<T>::~Apo()
{
    delete [] nodos;
}

/*Metodos privados de ordenacion*/
template<typename T>
void Apo<T>::flotar(nodo i)
{
    T e = nodos[i];
    while (i > 0 && e < nodos[padre(i)])
    {
        nodos[i] = nodos[padre(i)];
        i = padre(i);
    }
    nodos[i] = e;
}

template<typename T>
void Apo<T>::hundir(nodo i)
{
    bool fin = false;
    T e = nodos[i];
    while (hIzq(i) < numNodos && !fin)
    {
        nodo hMin = hDer(i) < numNodos && nodos[hDer(i)] < nodos[hIzq(i)] ? hDer(i) : hIzq(i);
        if (hMin < e)
        {
            nodos[i] = nodos[hMin];
            i = hMin;
        } else fin = true;
    }
    nodos[i] = e;
}


/*******************************/





#endif
