#include "Ejercicio3.hpp"
#include <string>

std::ostream& operator<<(std::ostream& os,const Oper& op)
{
    if(op.es_num) os << op.num;
    else os << op.ope;
    return os;
}
std::istream& operator>>(std::istream& is,Oper& op)
{
    std::string str;
    is >> str;
    try {
        op.num = std::stod(str);
        op.es_num = true;
    } catch (...) {
        op.es_num = false;
        op.ope = str[0];
    }
    return is;
}

double operador_Abin(const Abin<Oper>& A)
{
    return operador_Abin_rec(A, A.raiz());
}
double operador_Abin_rec(const Abin<Oper>& A,Abin<Oper>::nodo n)
{
    Oper op = A.elemento(n);
    if(op.es_num) return op.num;
    else {
        switch (op.ope) {
            case '+':
                return operador_Abin_rec(A, A.hijoIzqdo(n)) + operador_Abin_rec(A, A.hijoDrcho(n));
            case '-':
                return operador_Abin_rec(A, A.hijoIzqdo(n)) - operador_Abin_rec(A, A.hijoDrcho(n));
            case '/':
                return operador_Abin_rec(A, A.hijoIzqdo(n)) / operador_Abin_rec(A, A.hijoDrcho(n));
            case '*':
                return operador_Abin_rec(A, A.hijoIzqdo(n)) * operador_Abin_rec(A, A.hijoDrcho(n));
        }
    }
    return 0.0;
}
