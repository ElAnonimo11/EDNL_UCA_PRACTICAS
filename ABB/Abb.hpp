#ifndef ABB_HPP_
#define ABB_HPP_
#include <cassert>
#include <cstddef>
#include <utility>
#include <vector>

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
        Abb(const Abb& A);
        Abb& operator=(const Abb& A);
        ~Abb();
        /*Ejercicio 1 practica 4 */
        void podar(const T& e);
        /*************************/

        /*Ejercicio 2 practica 4 */
        void equilibrio();
        void recorrido_inorden(std::vector<T> &v) const;
        /*************************/
    private:
        struct arbol
        {
            T elto;
            Abb izq,der;
            arbol(const arbol& A) = default;
            ~arbol() = default;
        };
        arbol* r;
        /*Ejercicio 2 practica 4 */
        void rellenar_Abb(const std::vector<T>& v,int ini,int fin);
        /*************************/
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
        else {
            arbol* a;
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
                pMin->r = a->der.r;     // Dado que no tiene hijo izquierdo, vale con convertirlo en el derecho
                // Transferir al mínimo los subárboles de la raíz.
                a->izq.r = r->izq.r;
                a->der.r = r->der.r;
                r->izq.r = nullptr;
                r->der.r = nullptr;
            }
            // Destruir la raíz.
            delete r;
            r = a;
        }
    }
}

template <typename T>
const T& Abb<T>::elemento() const
{
    assert(!vacio());
    return r->elto;
}

template <typename T>
const Abb<T>& Abb<T>::izqdo() const
{
    assert(!vacio());
    return r->izq;
}

template <typename T>
const Abb<T>& Abb<T>::drcho() const
{
    assert(!vacio());
    return r->der;
}

template <typename T>
Abb<T>::Abb(const Abb& A) : r{A.r ? new arbol{*A.r} : nullptr} {}   // La sencillez de la implementacion se debe a que e llamaran recursivamente hasta que no queden elementos el contructor de copia de arbol y Abb

template <typename T>
Abb<T>& Abb<T>::operator=(const Abb& A)
{
    Abb aux{A};
    std::swap(aux.r,r);
    return *this;
}

template <typename T>
Abb<T>::~Abb()
{
    delete r;
    r = nullptr;
}

/*Ejercico 1 practica4 */
template <typename T>
void Abb<T>::podar(const T& e)
{
    if(!vacio()) {
        if (e < r->elto) r->izq.podar(e);
        else if (r->elto < e) r->der.podar(e);
        else {
            // Si el elemento es el buscado, eliminamos la raíz
            delete r;
            r = nullptr;
        }
    }
}
/***********************/

/*Ejercicio 2 practica 4 */
template <typename T>
void Abb<T>::equilibrio()
{
    if (!vacio()) {
        // Paso de complicarme, uso vector
        std::vector<T> elems;
        recorrido_inorden(elems);
        size_t tam = elems.size();
        Abb<T> aux;
        aux.rellenar_Abb(elems, 0, tam);
        delete r;
        r = aux.r;
        aux.r = nullptr;
    }
}

template <typename T>
void Abb<T>::recorrido_inorden(std::vector<T>& v) const
{
    if (!vacio()) {
        r->izq.recorrido_inorden(v);
        v.push_back(r->elto);
        r->der.recorrido_inorden(v);
    }
}

template <typename T>
void Abb<T>::rellenar_Abb(const std::vector<T>& v,int ini,int fin)
{
    if (ini <= fin) {
        int mid = (fin + ini) / 2;
        r = new arbol{v[mid]};
        r->izq.rellenar_Abb(v, ini, mid - 1);
        r->der.rellenar_Abb(v, mid + 1, fin);
    }
}
/*************************/


#endif
