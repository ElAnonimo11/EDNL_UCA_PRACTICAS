#ifndef _ABB_HPP_
#define _ABB_HPP_
#include <cassert>
#include <algorithm>

template <typename T>
class Abb
{
    public:
        Abb();
        const Abb& buscar(const T& e) const;
        void insertar(const T& e);
        void eliminar(const T& e);
        bool vacio() const;
        const T& elemento() const;
        const Abb& izqdo() const;
        const Abb& drcho() const;
        Abb(const Abb& A); // Ctor. de copia
        Abb& operator =(const Abb& A); // Asig. árboles
        ~Abb();
    public:
        struct arbol
        {
            T elto;
            Abb izq,der;
            arbol(const arbol& A) = default;
            ~arbol() = default;
        };
};


#endif
