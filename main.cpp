#include "ABIN/Abin.hpp"
#include "ABIN/abin_E-S.h"
#include <cstdlib>
#include <iostream>

int main() {
    Abin<char> A;
    rellenarAbin(A,'#');
    std::ofstream archivo("archivo.txt");
    imprimirAbin(archivo,A,'#');
    Abin<char> B(A);
    imprimirAbin(std::cout,B,'#');
    exit(EXIT_SUCCESS);
}
