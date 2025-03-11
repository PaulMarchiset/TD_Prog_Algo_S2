#pragma once

#include "fraction.hpp"

unsigned int gcd(unsigned int a, unsigned int b);
Fraction simplify(Fraction const& f);

// ---------------- CONVERSION ----------------

float toFloat(Fraction const& f);

// ---------------- UTILS ----------------

// unsigned int abs(Fraction const& f);
int ceil(Fraction const& f);
int floor(Fraction const& f);
float round(Fraction const& f);