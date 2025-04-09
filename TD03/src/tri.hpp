#pragma once

#include <vector>
#include <algorithm>

// ------ Test de tri ------

bool is_sorted(std::vector<int> const &vec);
bool is_sorted(std::vector<float> const &vec);

// ------ Bubble sort ------

void bubble_sort(std::vector<int> &vec);

// ------ Merge sort ------

void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<float> & vec, size_t const left, size_t const right);
void merge_sort(std::vector<float> & vec);

void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<int> & vec, size_t const left, size_t const right);
void merge_sort(std::vector<int> & vec);

// ------ Compare sorts ------

#include <vector>
#include <cstdlib>
#include <algorithm>

std::vector<int> generate_random_vector(size_t const size, int const max = 100);


// ------ Dichotomie ------

int search(std::vector<int> const & vec, size_t const left, size_t const right, int const value);
int dichotomie(std::vector<int> const & vec, int const value);