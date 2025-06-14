#ifndef _CONJUNTO_HPP_
#define _CONJUNTO_HPP_

#include "Abb.hpp"
#include <vector>

template <typename T>
class Conjunto : private Abb<T> {
    public:
        Conjunto() = default;
        std::vector<T> elementos();
        bool pertenencia(const T& e);
        Conjunto unir(const Conjunto& B) const;
        Conjunto interseccion(const Conjunto& B) const;
        Conjunto rombo(const Conjunto& B) const;

        Conjunto(const Conjunto &) = default;
        ~Conjunto() = default;
    private:
        void recorrido_inorden(std::vector<T>& v);
};

template <typename T>
std::vector<T> Conjunto<T>::elementos()
{
    std::vector<T> elems;
    recorrido_inorden(elems);
    return elems;
}

template <typename T>
bool Conjunto<T>::pertenencia(const T& e)
{
    return !this->buscar(e).vacio();
}

template <typename T>
void Conjunto<T>::recorrido_inorden(std::vector<T>& v)
{
    if (!this->vacio()) {
        this->r->izq.recorrido_inorden(v);
        v.push_back(this->r->elto);
        this->r->der.recorrido_inorden(v);
    }
}

template <typename T>
Conjunto<T> Conjunto<T>::unir(const Conjunto<T>& B) const
{

}

#endif
