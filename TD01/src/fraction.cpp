#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

// --------------- OPERATEURS AFFICHAGE ----------------

void Fraction::display() {
    std::cout << numerator << "/" << denominator;
}

std::ostream& operator<<(std::ostream& os, Fraction const& f) {
     return os << f.numerator << "/" << f.denominator;
    
}

// --------------- OPERATEURS CALCUL ----------------

// --------------- ADDITION ----------------

Fraction& Fraction::operator+=(Fraction const& f) {
    return *this = simplify({
        numerator * f.denominator + f.numerator * denominator,
        denominator * f.denominator
    });
    
}

Fraction operator+(Fraction f1, Fraction const& f2) {
    return simplify({
        f1 += f2
    });
}

Fraction operator+(Fraction f1, int const i) {
    Fraction f2 {static_cast<unsigned int>(i), 1};
    return simplify({
        f1 += f2
    });
}

Fraction operator+(int const i, Fraction f1) {
    return f1 + i;
}

// --------------- SOUSTRACTION ----------------

Fraction& Fraction::operator-=(Fraction const& f) {
    return *this = simplify({
        numerator * f.denominator - f.numerator * denominator,
        denominator * f.denominator
    });
}

Fraction operator-(Fraction f1, Fraction const& f2) {
    return simplify({
        f1 -= f2
    });
}

Fraction operator-(Fraction f1, int const i) {
    Fraction f2 {static_cast<unsigned int>(i), 1};
    return simplify({
        f1 -= f2
    });
}

Fraction operator-(int const i, Fraction f1) {
    return f1 - i;
}

// --------------- MULTIPLICATION ----------------

Fraction& Fraction::operator*=(Fraction const& f) {
    return *this = simplify({
        numerator * f.numerator,
        denominator * f.denominator
    });
}

Fraction operator*(Fraction f1, Fraction const& f2) {
    return simplify({
        f1 *= f2
    });
}

Fraction operator*(Fraction f1, int const i) {
    Fraction f2 {static_cast<unsigned int>(i), 1};
    return simplify({
        f1 *= f2
    });
}

Fraction operator*(int const i, Fraction f1) {
    return f1 * i;
}

// --------------- DIVISION ----------------

Fraction& Fraction::operator/=(Fraction const& f) {
    return *this = simplify({
        numerator * f.denominator,
        denominator * f.numerator
    });
}

Fraction operator/(Fraction f1, Fraction const& f2) {
    return simplify({
        f1 /= f2
    });
}

Fraction operator/(Fraction f1, int const i) {
    Fraction f2 {static_cast<unsigned int>(i), 1};
    return simplify({
        f1 /= f2
    });
}

Fraction operator/(int const i, Fraction f1) {
    return f1 / i;
}



// --------------- ANCIENNE VERSION DES OPERATEURS ----------------


// Fraction operator-(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator*(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator/(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     });
// }



// ---------------- OPERATEURS DE COMPARAISON ----------------

bool operator==(Fraction const& f1, Fraction const& f2) {
    return f1.numerator * f2.denominator == f2.numerator * f1.denominator;
}

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2);
}

bool operator<(Fraction const& f1, Fraction const& f2) {
    return f1.numerator * f2.denominator < f2.numerator * f1.denominator;
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    return f1 < f2 || f1 == f2;
}

bool operator>(Fraction const& f1, Fraction const& f2) {
    return !(f1 < f2);
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    return !(f1 < f2) || f1 == f2;
}