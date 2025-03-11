#pragma once
#include <iostream>

// ---------------- STRUCTURE ----------------

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    void display();

    Fraction& operator+=(Fraction const& f);
    Fraction& operator-=(Fraction const& f);
    Fraction& operator*=(Fraction const& f);
    Fraction& operator/=(Fraction const& f);

    operator float() const;
};


// ---------------- AFFICHAGE ----------------

std::ostream& operator<<(std::ostream& os, Fraction const& f);


// ---------------- ADDITION ----------------

Fraction operator+(Fraction f1, Fraction const& f2);
Fraction operator+(Fraction f1, int const i);
Fraction operator+(int const i, Fraction f1);

// ---------------- SOUSTRACTION ----------------

Fraction operator-(Fraction f1, Fraction const& f2);
Fraction operator-(Fraction f1, int const i);
Fraction operator-(int const i, Fraction f1);

// ---------------- MULTIPLICATION ----------------

Fraction operator*(Fraction f1, Fraction const& f2);
Fraction operator*(Fraction f1, int const i);
Fraction operator*(int const i, Fraction f1);

// ---------------- DIVISION ----------------

Fraction operator/(Fraction f1, Fraction const& f2);
Fraction operator/(Fraction f1, int const i);
Fraction operator/(int const i, Fraction f1);


// ---------------- COMPARAISON ----------------

bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);

bool operator<(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);

