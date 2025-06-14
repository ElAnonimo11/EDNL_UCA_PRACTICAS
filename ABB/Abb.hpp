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
        arbol* r;
};

template <typename T>
Abb<T>::Abb() : r{nullptr} {}

template <typename T>
bool Abb<T>::vacio() const
{
    return r == nullptr;
}

template <typename T>
const Abb<T>& Abb<T>::buscar(const T& e) const
{
    if (vacio()) return *this;
    else if (e < r->elto) return r->izq.buscar(e);
    else if (r->elto < e) return r->der.buscar(e);
    else return *this;
}

template <typename T>
void Abb<T>::insertar(const T& e)
{
    if (vacio()) r = new arbol{e};
    else if (e < r->elto) r->izq.insertar(e);
    else if (r->elto < e) r->der.insertar(e);
}

template <typename T>void Abb<T>::eliminar(const T& e)
{
    if (!vacio()) {
        if (e < r->elto) r->izq.eliminar(e);
        else if (r->elto < e) r->der.eliminar(e);
        else { // Eliminar la raíz.
            arbol* a; // Sustituto de la raíz.
            // arbol hoja
            if (!r->izq.r && !r->der.r)
                a = nullptr;
            // Arbol con hijo izquierdo
            else if (!r->der.r) {
                a = r->izq.r;
                r->izq.r = nullptr;
            }
            // Arbol con hijo derecho
            else if (!r->izq.r) {
                a = r->der.r;
                r->der.r = nullptr;
            }
            // Arbol con dos hijos
            else {
                // Buscar el mínimo del subárbol drcho. de la raíz.
                Abb* pMin = &r->der;
                while (pMin->r->izq.r != nullptr) pMin = &pMin->r->izq;
                // Extraer el mínimo y sustituirlo por su hijo drcho.
                a = pMin->r;
                pMin->r = a->der.r;
                // Transferir al mínimo los subárboles de la raíz.
                a->izq.r = r->izq.r;
                a->der.r = r->der.r;
                r->izq.r = nullptr;
                r->der.r = nullptr;
            }
            // Destruir la raíz.
            delete r;
            r = a;
        } // Eliminar la raíz.
    }
}



#endif
