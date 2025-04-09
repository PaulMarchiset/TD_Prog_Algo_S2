#pragma once

#include <string>
#include <iostream>
#include <ctime>

// --------- HASHING FUNCTIONS ---------

// ----- FOLDING HASH -----
size_t folding_string_hash(std::string const& s, size_t max);

// ----- FOLDING ORDERED HASH -----
size_t folding_string_ordered_hash(std::string const& s, size_t max);

// ----- POLYNOMIAL ROLLING HASH -----
size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t max);


