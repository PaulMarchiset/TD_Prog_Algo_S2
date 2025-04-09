#include "hash.hpp"

// --------- HASHING FUNCTIONS ---------

// ----- FOLDING HASH -----
size_t folding_string_hash(std::string const& s, size_t max)
{
    size_t hash = 0;

    for (char c : s)
    {
        hash += c;
    }

    return hash % max;
}

// ----- FOLDING ORDERED HASH -----

size_t folding_string_ordered_hash(std::string const& s, size_t max) {
    size_t hash = 0;

    for (size_t i{0}; i < s.size(); i++) {
        hash += s[i] * (i + 1);
    }

    return hash % max;
}

// ----- POLYNOMIAL ROLLING HASH -----

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t max) {
    size_t hash {0};

    for (size_t i{0}; i < s.size(); i++) {
        hash += s[i] * p;
        p *= p;
        std::cout << p << std::endl;
    }

    return hash % max;
}