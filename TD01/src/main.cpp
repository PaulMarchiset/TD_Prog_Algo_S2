#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 2, 5 };
    Fraction f2 { 1, 2 };
    int i { 3 };

    std::cout << f1 << " et " << f2 << std::endl;

    if (f1 == f2) {
        std::cout << "f1 == f2" << std::endl;
    } else {
        std::cout << "f1 != f2" << std::endl;
    }


    std::cout << f1 << " = " << static_cast<float>(f1) << std::endl;

    Fraction f3 = f1 + i;

    std::cout << f1 << " + " << i << " = " << f3 << std::endl;

    // std::cout << f1 << " - " << i << " = " << f1 - i << std::endl;
    // std::cout << " la valeur absolue de " << f1 << " est " << abs(f1) << std::endl;

    return 0;
}