#ifndef EJERCICIO2_HPP
#define EJERCICIO2_HPP

// Definiremos el pseudocentro de un grafo conexo como el nodo del mismo que
// minimiza la suma de las distancias mínimas a sus dos nodos más alejados. Definiremos
// el diámetro del grafo como la suma de las distancias mínimas a los dos nodos más
// alejados del pseudocentro del grafo.
//  Dado un grafo conexo representado mediante matriz de costes, implementa un
// subprograma que devuelva la longitud de su diámetro.

#include "../../../Contenido/alg_grafoPMC.h"
#include "../../../Contenido/grafoPMC.h"
#include "../../../Contenido/matriz.h"

template<typename tCoste>
tCoste longitud_diametro_GrafoP(const GrafoP<tCoste> &G)
{
    using vertice = typename GrafoP<tCoste>::vertice;
    matriz<tCoste> matr = Floyd(G,matriz<GrafoP<vertice>()>{});
    tCoste diametro_min = GrafoP<tCoste>::INFINITO;

    for (size_t i = 0; i < G.numVert() ; ++i)
    {
        tCoste  max1 = tCoste(),
                max2 = tCoste();
        for (const tCoste& val : matr[i])
        {
            if (val > max1)
            {
                max1 = val;
            }
            else if (val > max2)
            {
                max2 = val;
            }
        }
        diametro_min = std::min(diametro_min,suma(max1,max2));
    }
    return diametro_min;
}

#endif
