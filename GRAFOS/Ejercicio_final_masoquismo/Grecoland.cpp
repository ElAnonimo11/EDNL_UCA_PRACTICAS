
#include "Grecoland.hpp"

#include <complex>



// Funciones auxiliares
double distancia_euclidea(const Ciudad &A, const Ciudad &B)
{
    return std::sqrt(std::pow(A.x - B.x,2) + std::pow(A.y - B.y,2));
}
