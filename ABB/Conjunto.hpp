#ifndef CONJUNTO_HPP_
#define CONJUNTO_HPP_

#include <initializer_list>
#include <iostream>
#include <vector>
#include "Abb.hpp"

/*He hecho un conjunto general porque me olvide que tenia que ser de enteros xd*/
template <typename T>
class Conjunto{
    public:
        Conjunto() = default;
        Conjunto(const std::initializer_list<T> &list);
        std::vector<T> elementos() const;
        bool pertenencia(const T& e) const;
        void agregar(const T& e);
        Conjunto unir(const Conjunto& B) const;
        Conjunto interseccion(const Conjunto& B) const;
        Conjunto resta(const Conjunto<T>& B) const;
        Conjunto rombo(const Conjunto& B) const;

        Conjunto(const Conjunto &) = default;
        ~Conjunto() = default;
    private:
        mutable Abb<T> abb;
};

template <typename T>
Conjunto<T>::Conjunto(const std::initializer_list<T>& list) : Conjunto()
{
    for (const T& elem : list) abb.insertar(elem);
    abb.equilibrio();
}

template <typename T>
std::vector<T> Conjunto<T>::elementos() const
{
    std::vector<T> elems;
    abb.recorrido_inorden(elems);
    return elems;
}

template <typename T>
bool Conjunto<T>::pertenencia(const T& e) const
{
    return !abb.buscar(e).vacio();
}

template <typename T>
void Conjunto<T>::agregar(const T& e)
{
    abb.insertar(e);
    abb.equilibrio();
}

template <typename T>
Conjunto<T> Conjunto<T>::unir(const Conjunto<T>& B) const
{
    Conjunto<T> aux;
    for (const T& elem : elementos()) aux.abb.insertar(elem);
    for (const T& elem : B.elementos()) aux.abb.insertar(elem);
    aux.abb.equilibrio();
    return aux;
}

template <typename T>
Conjunto<T> Conjunto<T>::interseccion(const Conjunto<T>& B) const
{
    Conjunto<T> aux;
    for (const T& elem : elementos()) if (!B.abb.buscar(elem).vacio()) aux.abb.insertar(elem);
    return aux;
}

template<typename T>
Conjunto<T> Conjunto<T>::resta(const Conjunto<T> &B) const
{
    Conjunto<T> aux;
    for (const T& elem : elementos()) if (B.abb.buscar(elem).vacio()) aux.abb.insertar(elem);
    return aux;
}

template<typename T>
Conjunto<T> Conjunto<T>::rombo(const Conjunto &B) const
{
    return unir(B).resta(interseccion(B));
}



#endif
