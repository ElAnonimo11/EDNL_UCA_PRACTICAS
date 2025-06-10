#include "ABIN/Abin.hpp"
#include "ABIN/abin_E-S.h"
#include "ABIN/Practicas/P1/Ej6/Ejercicio6.hpp"
#include <cstdlib>
#include <iostream>

int main() {
    Abin<char> A;
    rellenarAbin(A,'#');
    imprimirAbin(std::cout,A,'#');
    std::cout << nivel_desequilibrio(A) << " de desequilibrio." << std::endl;
    exit(EXIT_SUCCESS);
}
