#ifndef APO_MIN_MAX_HPP
#define APO_MIN_MAX_HPP
#include <valarray>
#include <cassert>
/* Fuck this me pongo con grafos

template <typename T>
class Apo_min_max
{
    public:
        explicit Apo_min_max(size_t tamMax);
        void insertar(const T& e);
        void suprimir();
        const T& cima() const;
        bool vacio() const;
        size_t tama() const;
        size_t tamaMax() const;

        Apo_min_max(const Apo_min_max& B);
        Apo_min_max& operator=(const Apo_min_max& B);
        ~Apo_min_max();

    private:
        using nodo = size_t;
        T eltos;
        size_t  maxNodos,
                numNodos;
        nodo padre(const nodo i) const { return (i-1)/2; }
        nodo hIzq(const nodo i) const { return 2*i+1; }
        nodo hDer(const nodo i) const { return 2*i+2; }
        bool esPar(const nodo i) const { return static_cast<int>(std::log(i + 1)) % 2 == 0; }
        void flotar(nodo i);
        void hundir(nodo i);
};

template<typename T>
Apo_min_max<T>::Apo_min_max(const size_t tamMax) : eltos{new T[tamMax]} , maxNodos{tamMax} , numNodos{} {}

template<typename T>
void Apo_min_max<T>::insertar(const T &e)
{
    assert(numNodos < maxNodos);
    eltos[numNodos++] = e;
    if (numNodos > 1) flotar(numNodos-1);
}

template<typename T>
void Apo_min_max<T>::suprimir()
{

}


*/
#endif
