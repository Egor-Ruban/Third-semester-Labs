#include <iostream>
#include "Complex.h"

int main() {
    Complex z1(3,5.4),z2(2,4.4);
    std::cout<<z1.Abs()<<std::endl; // модуль числа z1
    std::cout<<Complex::Add(z1,z2).toString()<<std::endl
    int j = Complex::k;
    return 0;
}