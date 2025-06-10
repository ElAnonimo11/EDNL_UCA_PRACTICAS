#include "ABIN/Abin.hpp"
#include "ABIN/abin_E-S.h"
#include "ABIN/Practicas/P1/Ej1/Ejercicio1.hpp"
#include <cstdlib>
#include <iostream>

int main() {
    Abin<char> A;
    rellenarAbin(A,'#');
    imprimirAbin(std::cout,A,'#');
    std::cout << num_nodos(A) << " de nodos." << std::endl;
    exit(EXIT_SUCCESS);
}
