#include "AGEN/Agen.hpp"
#include "AGEN/agen_E-S.h"
#include "AGEN/Practicas/P3/Ej1/Ejercicio1.hpp"
#include <cstdlib>
#include <iostream>

int main() {
    Agen<char> A;
    rellenarAgen(A,'#');
    std::cout << "El grado del Agen es de " << gradoAgen(A) << "." << std::endl;
    imprimirAgen(A);
    exit(EXIT_SUCCESS);
}
