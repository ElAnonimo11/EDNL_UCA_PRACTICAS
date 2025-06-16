/*--------------------------------------------------------*/
/* apo.h                                                  */
/*                                                        */
/* clase Apo gen�rica: �rbol parcialmente ordenado con    */
/*    elementos de tipo T en los nodos, cuyo tama�o       */
/*    (par�metro de entrada del constructor) puede ser    */
/*    distinto para cada objeto de la clase Apo.          */
/*    Los elementos se ordenan con el operador < del tipo */
/*    T, de modo que el de cada nodo es menor que el de   */
/*    todos sus descendientes.                            */
/*--------------------------------------------------------*/

#ifndef APO_H
#define APO_H
#include <cassert>

template <typename T> class Apo {
public:
   explicit Apo(size_t maxNodos);       // constructor
   void insertar(const T& e);
   void suprimir();
   const T& cima() const;
   bool vacio() const;
   Apo(const Apo& A);                   // ctor. de copia
   Apo& operator =(const Apo& A);       // asignaci�n de apo
   ~Apo();                              // destructor
private:
   typedef size_t nodo; // �ndice del vector
                        // entre 0 y maxNodos-1
   T* nodos;          // vector de nodos
   size_t maxNodos;   // tama�o del vector
   size_t numNodos;   // n�mero de nodos del �rbol

   nodo padre(nodo i) const { return (i-1)/2; }
   nodo hIzq(nodo i)  const { return 2*i+1; }
   nodo hDer(nodo i)  const { return 2*i+2; }
   void flotar(nodo i);
   void hundir(nodo i);
};

/*--------------------------------------------------------*/
/* clase Apo gen�rica: Vector de posiciones relativas.    */
/*    Un Apo de n nodos se almacena en celdas             */
/*    consecutivas del vector, desde 0 hasta numNodos-1.  */
/*    La ra�z del APO se almacena en la celda 0 del       */
/*    vector. Al hijo izquierdo del nodo i le corresponde */
/*    la celda 2i+1 y al hijo derecho la celda 2i+2.      */
/*                                                        */
/* Implementaci�n de operaciones                          */
/*--------------------------------------------------------*/

template <typename T>
inline Apo<T>::Apo(size_t maxNodos) :
   nodos(new T[maxNodos]),
   maxNodos(maxNodos),
   numNodos(0)   // Apo vac�o
{}

template <typename T>
inline void Apo<T>::insertar(const T& e)
{
   assert(numNodos < maxNodos);   // Apo no lleno
   nodos[numNodos] = e;
   if (++numNodos > 1)
      flotar(numNodos-1);
}

template <typename T>
inline void Apo<T>::suprimir()
{
   assert(numNodos > 0);   // Apo no vac�o
   if (--numNodos > 0) {     // Apo no queda vac�o.
      nodos[0] = nodos[numNodos];
      if (numNodos > 1)     // Quedan dos o m�s elementos.
         hundir(0);         // Reordenar.
   }
}

template <typename T>
inline const T& Apo<T>::cima() const
{
   assert(numNodos > 0);   // Apo no vac�o
   return nodos[0];
}

template <typename T>
inline bool Apo<T>::vacio() const
{
   return (numNodos == 0);
}

template <typename T>
inline Apo<T>::~Apo()
{
   delete[] nodos;
}

template <typename T>
Apo<T>::Apo(const Apo<T>& A) :
   nodos(new T[A.maxNodos]),
   maxNodos(A.maxNodos),
   numNodos(A.numNodos)
{
   // copiar el vector
   for (nodo n = 0; n < numNodos; n++)
      nodos[n] = A.nodos[n];
}

template <typename T>
Apo<T>& Apo<T>::operator =(const Apo<T>& A)
{
   if (this != &A) {   // evitar autoasignaci�n
      // Destruir el vector y crear uno nuevo si es necesario
      if (maxNodos != A.maxNodos) {
         delete[] nodos;
         maxNodos = A.maxNodos;
         nodos = new T[maxNodos];
      }
      numNodos = A.numNodos;
      // Copiar el vector
      for (nodo n = 0; n < numNodos; n++)
         nodos[n] = A.nodos[n];
   }
   return *this;
}

// M�todos privados

template <typename T>
void Apo<T>::flotar(nodo i)
{
   T e = nodos[i];
   while (i > 0 && e < nodos[padre(i)]) {
      nodos[i] = nodos[padre(i)];
      i = padre(i);
   }
   nodos[i] = e;   // colocar e
}

template <typename T>
void Apo<T>::hundir(nodo i)
{
   bool fin = false;
   T e = nodos[i];
   while (hIzq(i) < numNodos && !fin) {   // hundir e
      nodo hMin;   // hijo menor del nodo i
      if (hDer(i) < numNodos && nodos[hDer(i)] < nodos[hIzq(i)])
         hMin = hDer(i);
      else
         hMin = hIzq(i);
      if (nodos[hMin] < e) { // subir el hijo menor
         nodos[i] = nodos[hMin];
         i = hMin;
      }
      else   // e <= hMin
         fin = true;
   }
   nodos[i] = e;   // colocar e
}

#endif // APO_H
