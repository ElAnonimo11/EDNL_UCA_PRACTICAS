/*--------------------------------------------------------*/
/* listaenla.h                                            */
/*                                                        */
/* clase Lista gen�rica de capacidad ilimitada.           */
/*    Despu�s de una inserci�n o eliminaci�n en una       */
/*    posici�n p, las variables externas de tipo posici�n */
/*    posteriores a p contin�an representado las          */
/*    posiciones de los mismos elementos.                 */
/*--------------------------------------------------------*/

#ifndef LISTA_ENLA_H
#define LISTA_ENLA_H
#include <cassert>

template <typename T> class Lista {
   struct nodo;   // Declaraci�n adelantada privada
public:
   typedef nodo* posicion;                 // Posici�n de un elemento
   Lista();                                // Constructor, req. ctor. T()
   bool vacia() const;
   size_t tama() const;
   void insertar(const T& x, posicion p);
   void eliminar(posicion p);
   const T& elemento(posicion p) const;    // Lec. elto. en Lista const
   T& elemento(posicion p);                // Lec/Esc elto. en Lista no-const
   posicion siguiente(posicion p) const;
   posicion anterior(posicion p) const;
   posicion primera() const;
   posicion fin() const;                   // Posici�n despu�s del �ltimo
   Lista(const Lista& Lis);                // Ctor. de copia, req. ctor. T()
   Lista& operator =(const Lista& Lis);    // Asig. de listas
   ~Lista();                               // Destructor
   // Usado en algoritmos de grafos
   Lista& operator +=(const Lista& L);     // Concatenaci�n
private:
   struct nodo {
      T elto;
      nodo* sig;
      nodo(const T& e = T(), nodo* p = nullptr): elto(e), sig(p) {}
   };

   nodo* L;   // Lista enlazada circular con cabecera, ptro. al �ltimo
   size_t n;  // Longitud de la lista

   void copiar(const Lista& Lis);
};

/*--------------------------------------------------------*/
/* clase Lista gen�rica mediante estructura enlazada      */
/*    circular con cabecera.                              */
/*    La posici�n de un elemento se representa mediante   */
/*    un puntero al nodo anterior.                        */
/*    La primera posici�n es un puntero al nodo cabecera, */
/*    que es el siguiente al �ltimo.                      */
/*    La posici�n fin es un puntero al �ltimo nodo, o lo  */
/*    que es lo mismo, al anterior a la cabecera.         */
/*                                                        */
/* Implementaci�n de operaciones                          */
/*--------------------------------------------------------*/

template <typename T>
inline Lista<T>::Lista() :
   L(new nodo), // Crear cabecera
   n(0)
{
   L->sig = L; // Estructura circular
}

template <typename T>
inline bool Lista<T>::vacia() const
{
   return n == 0; // Alternativa: return primera() == fin();
}

template <typename T>
inline size_t Lista<T>::tama() const
{
   return n;
}

template <typename T>
inline void Lista<T>::insertar(const T& x, posicion p)
{
   p->sig = new nodo(x, p->sig);
   if (p == fin())
      L = p->sig;   // Nuevo �ltimo
   ++n;
}

template <typename T>
inline void Lista<T>::eliminar(posicion p)
{
   assert(p != fin());
   posicion q = p->sig;
   if (q == fin())
      L = p; // El nuevo �ltimo es el pen�ltimo
   p->sig = q->sig;
   delete q;
   --n;
}

template <typename T>
inline const T& Lista<T>::elemento(posicion p) const
{
   assert(p != fin());
   return p->sig->elto;
}

template <typename T>
inline T& Lista<T>::elemento(posicion p)
{
   assert(p != fin());
   return p->sig->elto;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::siguiente(posicion p) const
{
   assert(p != fin());
   return p->sig;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::anterior(posicion p) const
{
   assert(p != primera());
   posicion q = primera();
   while (q->sig != p) q = q->sig;
   return q;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::primera() const
{ return L->sig; }

template <typename T>
inline typename Lista<T>::posicion Lista<T>::fin() const
{ return L; }

// Constructor de copia
template <typename T>
inline Lista<T>::Lista(const Lista& Lis) : Lista()
{
   copiar(Lis);
}

// Asignaci�n de listas
template <typename T>
Lista<T>& Lista<T>::operator =(const Lista& Lis)
{
   if (this != &Lis) {  // Evitar autoasignaci�n
      while (!vacia()) eliminar(primera());
      copiar(Lis);
   }
   return *this;
}

// Destructor: vac�a la lista y destruye el nodo cabecera
template <typename T> Lista<T>::~Lista()
{
   nodo* p;
   while (L != L->sig) {
      p = L->sig;
      L->sig = p->sig;
      delete p;
   }
   delete L;
}

// Concatenaci�n de listas
template<typename T>
Lista<T>& Lista<T>::operator +=(const Lista& L)
{
   for (posicion i = L.primera(); i != L.fin(); i = L.siguiente(i))
      insertar(L.elemento(i), fin());
   return *this;
}

template<typename T>
Lista<T> operator +(const Lista<T>& L1, const Lista<T>& L2)
{
   return Lista<T>(L1) += L2;
}

// M�todo privado
template <typename T>
void Lista<T>::copiar(const Lista& Lis)
// Pre: *this est� vac�a.
// Post: *this es copia de Lis.
{
   for (nodo* p = Lis.L->sig; p != Lis.L; p = p->sig, ++n)
      L = L->sig = new nodo(p->sig->elto, L->sig);
}

#endif // LISTA_ENLA_H
