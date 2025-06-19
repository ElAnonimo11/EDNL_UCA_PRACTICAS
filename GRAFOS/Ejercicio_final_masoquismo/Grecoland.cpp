
#include "Grecoland.hpp"

#include <complex>

#include "../Contenido/alg_grafoPMC.h"
#include "../Contenido/grafoPMC.h"

double coste_min_Grecoland(
    const Lista<Ciudad>& Ciu_fobos,
    const Lista<Ciudad>& Ciu_deimos,
    const Lista<int>& ciu_cost_fobos,
    const Lista<int>& ciu_cost_deimos,
    Ciudad orig,
    Ciudad dest
    )
{
    std::vector<Ciudad> fobos,
                        deimo;
    // Para ver que ciudades en cada posicion hay
    for (auto l = Ciu_fobos.primera(); l != Ciu_fobos.fin() ; l = Ciu_fobos.siguiente(l)) fobos.push_back(Ciu_fobos.elemento(l));
    for (auto l = Ciu_deimos.primera(); l != Ciu_deimos.fin() ; l = Ciu_deimos.siguiente(l)) deimo.push_back(Ciu_deimos.elemento(l));
    const size_t    num_fob = fobos.size(),
                    num_dei = deimo.size();
    // Grafos de coste de las ciudades de todas con todas carreteras
    GrafoP<double>  G_fobos(num_fob),
                    G_deimo(num_dei);
    for (size_t i = 0; i < num_fob ; ++i)
        for (size_t j = 0; j < num_fob ; ++j)
        {
            if (i != j)
            {
                G_fobos[i][j] = G_fobos[j][i] = distancia_euclidea(fobos[i],fobos[j]);
            }
        }
    for (size_t i = 0; i < num_dei ; ++i)
        for (size_t j = 0; j < num_dei ; ++j)
        {
            if (i != j)
            {
                G_deimo[i][j] = G_deimo[j][i] = distancia_euclidea(deimo[i],deimo[j]);
            }
        }
    // Arboles de coste mínimo
    G_fobos = Kruskall(G_fobos);
    G_deimo = Kruskall(G_deimo);
    // Creamos el grafo de ambas islas y vemos cual es la carretera maxima
    const size_t tam_greco = num_fob + num_dei;
    GrafoP<double> Grecoland(tam_greco);
    double carr_max{};
    for (size_t i = 0 ; i < tam_greco; ++i)
    {
        for (size_t j = 0; j < tam_greco ; ++j)
        {
            double elem = GrafoP<double>::INFINITO;
            // Fobos
            if (i < num_fob && j < num_fob)
            {
                elem = G_fobos[i][j];
            }
            // Deimos
            else if (i >= num_fob && j >= num_fob)
            {
                elem = G_deimo[i-num_fob][j-num_fob];
            }
            Grecoland[i][j] = elem;
            if (elem != GrafoP<double>::INFINITO)
                carr_max = std::max(carr_max,elem);
        }
    }
    // Para calcular las carreteras, recorremos todas las ciudades costeras y a los puentes les sumamos la maxima carretera a todos los puentes
    for (auto l = ciu_cost_fobos.primera(); l != ciu_cost_fobos.fin() ; l = ciu_cost_fobos.siguiente(l))
    {
        const int i = ciu_cost_fobos.elemento(l);
        for (auto t = ciu_cost_deimos.primera(); t != ciu_cost_deimos.fin() ; t = ciu_cost_deimos.siguiente(l))
        {
            const int ind_fei = ciu_cost_deimos.elemento(t);
            const int j = ind_fei + static_cast<int>(num_fob);
            Ciudad prim = fobos[i];
            Ciudad segu = deimo[ind_fei];
            Grecoland[i][j] = Grecoland[j][i] = distancia_euclidea(prim,segu) + carr_max;
        }
    }
    // Vemos las posiciones en el grafo de las ciudades
    size_t  ind_orig = 0,
            ind_fini = 0;
    for (size_t i = 0; i < num_fob ; ++i)
    {
        Ciudad ciu = fobos[i];
        if (orig == ciu)
        {
            ind_orig = i;
        }
        if (dest == ciu)
        {
            ind_fini = i;
        }
    }
    for (size_t i = 0; i < num_dei ; ++i)
    {
        Ciudad ciu = deimo[i];
        if (orig == ciu)
        {
            ind_orig = i + num_fob;
        }
        if (dest == ciu)
        {
            ind_fini = i + num_fob;
        }
    }
    // Devolvemos el camino de coste minimo entre las ciudades
    return Dijkstra(Grecoland,ind_orig,auto())[ind_fini];
}

// Funciones auxiliares
double distancia_euclidea(const Ciudad &A, const Ciudad &B)
{
    return std::sqrt(std::pow(A.x - B.x,2) + std::pow(A.y - B.y,2));
}
