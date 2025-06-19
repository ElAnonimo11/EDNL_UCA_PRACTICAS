
#ifndef LABERINTO_HPP
#define LABERINTO_HPP

// Se dispone de un laberinto de NxN casillas del que se conocen las casillas de entrada y
// salida del mismo. Si te encuentras en una casilla sólo puedes moverte en las siguientes cuatro direcciones
// (arriba, abajo, derecha, izquierda). Por otra parte, entre algunas de las
// casillas hay una pared que impide moverse entre las dos casillas que separa dicha pared
// (en caso contrario no sería un verdadero laberinto).
// Implementa un subprograma que dados
// • N (dimensión del laberinto),
// • la lista de paredes del laberinto,
// • la casilla de entrada, y
// • la casilla de salida,
// calcule el camino más corto para ir de la entrada a la salida y su longitud.

#include <vector>

#include "../Contenido/grafoPMC.h"
#include "../Contenido/listaenla.h"

struct Casilla
{
    int i,
        j;
};

struct Pared
{
    Casilla ini,
            fin;
};

// Pasos de uno a otros
int casilla_a_nodo(const Casilla& cas,size_t N);
Casilla nodo_a_casilla(int nodo,size_t N);

// Comprobar si dos nodos son adyacentes
bool adyacentes(int nodo1, int nodo2,size_t N);

struct Camino_laberinto
{
    GrafoP<int>::tCamino camino;
    int longitud;
};

Camino_laberinto laberinto_paredes(size_t N,Lista<Pared> Paredes,Casilla entr,Casilla sali);

#endif //LABERINTO_HPP
