#include "ABB/Conjunto.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>


void imprimir_vector_enteros(const std::vector<int>& v)
{
    for (const int& elem : v) std::cout << elem << " ";
}

int main()
{
    const Conjunto<int>     conj1({1,2,3,4,5}),
                            conj2({1,3,5,6,7});
    std::cout << "Elementos primer conjunto: ";
    imprimir_vector_enteros(conj1.elementos());
    std::cout << std::endl;

    std::cout << "Elementos segundo conjunto: ";
    imprimir_vector_enteros(conj2.elementos());
    std::cout << std::endl;

    std::cout << "Elementos union: ";
    imprimir_vector_enteros(conj1.unir(conj2).elementos());
    std::cout << std::endl;

    std::cout << "Elementos interseccion: ";
    imprimir_vector_enteros(conj1.interseccion(conj2).elementos());
    std::cout << std::endl;

    std::cout << "Elementos rombo: ";
    imprimir_vector_enteros(conj1.rombo(conj2).elementos());
    std::cout << std::endl;

    std::unordered_map<int,int> a;
    if (a.contains(1))
    {
        std::cout << '1';
    } else
    {
        std::cout << "asldankdjs";
    }

    exit(EXIT_SUCCESS);
}