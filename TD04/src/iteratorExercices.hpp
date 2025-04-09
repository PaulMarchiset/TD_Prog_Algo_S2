#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

// ------ Vecteur de nombres aléatoires ------

std::vector<int> generate_random_vector(size_t const size, int const max);


// ------ Séparation de string ------

auto const is_space = [](char letter){ return letter == ' '; };
std::vector<std::string> split_string(std::string const& str);

// ------ Palindrome ------

bool is_palindrome(std::string const& str);