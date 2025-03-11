#include "utils.hpp"

unsigned int gcd(unsigned int a, unsigned int b)
{
    while (b != 0)
    {
        unsigned int modulo{a % b};
        a = b;
        b = modulo;
    }

    return a;
}
// recursive version
// unsigned int gcd(unsigned int a, unsigned int b) {
//     if (b == 0) {
//         return a;
//     }
//
//     return gcd(b, a % b);
// }
// ternary operator version
// unsigned int gcd(unsigned int a, unsigned int b) {
//     return b == 0 ? a : gcd(b, a % b);
// }

Fraction simplify(Fraction const &f)
{
    unsigned int divisor{gcd(f.numerator, f.denominator)};

    return {
        f.numerator / divisor,
        f.denominator / divisor};
}

// ---------------- OPERATEURS DE CONVERSION ----------------

float toFloat(Fraction const &f)
{
    return static_cast<float>(f.numerator) / static_cast<float>(f.denominator);
}

Fraction::operator float() const
{
    return toFloat(*this);
}

// ---------------- UTILS ----------------

unsigned int abs(Fraction const &f)
{
    return static_cast<unsigned int>(toFloat(f));
}

int ceil(Fraction const &f)
{
    return static_cast<int>(toFloat(f)) + 1;
}

int floor(Fraction const &f)
{
    return static_cast<int>(toFloat(f));
}

float round(Fraction const &f)
{
    if(toFloat(f) - floor(f) < 0.5)
    {
        return floor(f);
    }
    else
    {
        return ceil(f);
    }
}