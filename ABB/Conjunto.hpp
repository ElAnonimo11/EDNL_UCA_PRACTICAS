#ifndef _CONJUNTO_HPP_
#define _CONJUNTO_HPP_

#include "Abb.hpp"
#include <vector>
#include <initializer_list>

template <typename T>
class Conjunto{
    public:
        Conjunto() = default;
        Conjunto(const std::initializer_list<T>& list);
        std::vector<T> elementos();
        bool pertenencia(const T& e);
        void agregar(const T& e);
        Conjunto unir(const Conjunto& B) const;
        Conjunto interseccion(const Conjunto& B) const;
        Conjunto resta(const Conjunto<T>& B) const;
        Conjunto rombo(const Conjunto& B) const;

        Conjunto(const Conjunto &) = default;
        ~Conjunto() = default;
    private:
        Abb<T> abb;
};

template <typename T>
Conjunto<T>::Conjunto(const std::initializer_list<T>& list) : Conjunto()
{
    for (const T& elem : list) abb.insertar(elem);
    abb.equilibrio();
}

template <typename T>
std::vector<T> Conjunto<T>::elementos()
{
    std::vector<T> elems;
    abb.recorrido_inorden(elems);
    return elems;
}

template <typename T>
bool Conjunto<T>::pertenencia(const T& e)
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
Conjunto<T> Conjunto<T>::interseccion(const Conjunto<T>& B) const
{
    Conjunto<T> res;
    for (const T& elem : elementos()) if (B.pertenencia(elem)) res.agregar(elem);
    return res;
}

#endif
