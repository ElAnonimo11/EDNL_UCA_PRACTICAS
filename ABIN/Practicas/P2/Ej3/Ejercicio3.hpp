#ifndef _EJERCICIO_3_P2_HPP_
#define _EJERCICIO_3_P2_HPP_

#include "../../../Abin.hpp"
#include <iostream>
#include <istream>

/*
 * El TAD árbol binario puede albergar expresiones matemáticas mediante un árbol de
 * expresión. Dentro del árbol binario los nodos hojas contendrán los operandos, y el resto
 * de los nodos los operadores.
 * a) Define el tipo de los elementos del árbol para que los nodos puedan almacenar
 * operadores y operandos.
 * b) Implementa una función que tome un árbol binario de expresión (aritmética) y
 * devuelva el resultado de la misma. Por simplificar el problema se puede asumir que el
 * árbol representa una expresión correcta. Los operadores binarios posibles en la expresión
 * aritmética serán suma, resta, multiplicación y división.
 * Ejemplo: El siguiente árbol binario representa la expresión infija 7 × (15  3,2) / 2
 */

struct Oper
{
    char ope;
    double num;
    bool es_num;

    bool operator=(const Oper& A) {
        if (es_num == A.es_num) {if(es_num) return num == A.num; else return ope == A.ope;}
        return false;
    }
};

inline std::istream& operator>>(std::istream& is,Oper& op)
{

    return is;
}


#endif
