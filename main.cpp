#include "ABIN/Abin.hpp"
#include "ABIN/abin_E-S.h"
#include "ABIN/Practicas/P1/Ej2/Ejercicio2.hpp"
#include <cstdlib>
#include <iostream>

int main() {
    Abin<char> A;
    rellenarAbin(A,'#');
    imprimirAbin(std::cout,A,'#');
    std::cout << altura_abin(A) << " nodos." << std::endl;
    exit(EXIT_SUCCESS);
}
