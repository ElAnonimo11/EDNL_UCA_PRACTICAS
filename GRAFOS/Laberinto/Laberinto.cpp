

#include "Laberinto.hpp"
#include "../Contenido/grafoPMC.h"
#include "../Contenido/alg_grafoPMC.h"

Camino_laberinto laberinto_paredes(size_t N,const Lista<Pared>& Paredes, Casilla entr, Casilla sali)
{
    const size_t num_cas = N*N;
    GrafoP<int> G(num_cas);
    // Matriz de costes de nodos adyacentes
    for (size_t i = 0; i < num_cas ; ++i)
    {
        for (size_t j = 0; j < num_cas ; ++j)
        {
            if (adyacentes(static_cast<int>(i),static_cast<int>(j),N))
            {
                G[i][j] = G[j][i] = 1;
            }
        }
    }
    // Ponemos las paredes
    for (auto l = Paredes.primera(); l != Paredes.fin() ; l = Paredes.siguiente(l))
    {
        auto [ini, fin] = Paredes.elemento(l);
        const int   ini_n = casilla_a_nodo(ini,N),
                    fin_n = casilla_a_nodo(fin,N);
        G[ini_n][fin_n] = G[fin_n][ini_n] = GrafoP<int>::INFINITO;
    }
    vector<GrafoP<int>::vertice> camino_fin;
    const vector<int> vect_cost = Dijkstra(G,casilla_a_nodo(entr,N),camino_fin);
    return {camino<int>(casilla_a_nodo(entr,N),casilla_a_nodo(sali,N),camino_fin),vect_cost[casilla_a_nodo(sali,N)]};
}

// Operaciones auxiliares
int casilla_a_nodo(const Casilla &cas, size_t N)
{
    return cas.i * static_cast<int>(N) + cas.j;
}

Casilla nodo_a_casilla(int nodo, size_t N)
{
    return {nodo / static_cast<int>(N), nodo % static_cast<int>(N)};
}

bool adyacentes(int nodo1, int nodo2,size_t N)
{
    Casilla cas1 = nodo_a_casilla(nodo1,N),
            cas2 = nodo_a_casilla(nodo2,N);
    return std::abs(cas1.i - cas2.i) + std::abs(cas1.j - cas2.j) == 1;
}
