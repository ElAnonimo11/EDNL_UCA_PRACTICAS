
#ifndef GRECOLAND_HPP
#define GRECOLAND_HPP

// El archipiélago de Grecoland (Zuelandia) está formado únicamente por dos islas,
// Fobos y Deimos, que tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2
// ciudades son costeras (obviamente C1 ≤ N1 y C2 ≤ N2 ). Se dispone de las coordenadas
// cartesianas (x, y) de todas y cada una de las ciudades del archipiélago. El huracán
// Isadore acaba de devastar el archipiélago, con lo que todas las carreteras y puentes
// construidos en su día han desaparecido. En esta terrible situación se pide ayuda a la
// ONU, que acepta reconstruir el archipiélago (es decir volver a comunicar todas las
// ciudades del archipiélago) siempre que se haga al mínimo coste.
//  De cara a poder comparar costes de posibles reconstrucciones se asume lo
// siguiente:
// 1. El coste de construir cualquier carretera o cualquier puente es proporcional a su
// longitud (distancia euclídea entre las poblaciones de inicio y fin de la carretera o
// del puente).
// 2. Cualquier puente que se construya siempre será más caro que cualquier carretera
// que se construya.
//  De cara a poder calcular los costes de VIAJAR entre cualquier ciudad del
// archipiélago se considerará lo siguiente:
// 1. El coste directo de viajar, es decir de utilización de una carretera o de un puente,
// coincidirá con su longitud (distancia euclídea entre las poblaciones origen y
// destino de la carretera o del puente).
//  En estas condiciones, implementa un subprograma que calcule el coste mínimo
// de viajar entre dos ciudades de Grecoland, origen y destino, después de haberse
// reconstruido el archipiélago, dados los siguientes datos:
// 1. Lista de ciudades de Fobos representadas mediante sus coordenadas cartesianas.
// 2. Lista de ciudades de Deimos representadas mediante sus coordenadas
// cartesianas.
// 3. Lista de ciudades costeras de Fobos.
// 4. Lista de ciudades costeras de Deimos.
// 5. Ciudad origen del viaje.
// 6. Ciudad destino del viaje.

#include "../Contenido/listaenla.h"

// Estructura para guardar las ciudades
struct Ciudad
{
    int x, y;
    bool operator==(const Ciudad & ciu) const
    {
        return x == ciu.x && y == ciu.y;
    }
};

double distancia_euclidea(const Ciudad& A,const Ciudad& B);

double coste_min_Grecoland(
    const Lista<Ciudad>& Ciu_fobos,
    const Lista<Ciudad>& Ciu_deimos,
    const Lista<int>& ciu_cost_fobos,
    const Lista<int>& ciu_cost_deimos,
    Ciudad orig,
    Ciudad dest
    );


#endif //GRECOLAND_HPP
