#include "tri.hpp"

// ------ Test de tri ------

bool is_sorted(std::vector<int> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end());
}

bool is_sorted(std::vector<float> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end());
}

// ------ Bubble sort ------

void bubble_sort(std::vector<int> &vec)
{
    for (size_t i{0}; i < vec.size() - 1; i++)
    {
        for (size_t j{0}; j < vec.size() - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// ------ Merge sort ------

void merge_sort(std::vector<float> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
}

void merge_sort(std::vector<float> &vec, size_t const left, size_t const right)
{
    size_t const middle{(left + right) / 2};

    if (left < right)
    {
        merge_sort(vec, left, middle);
        merge_sort(vec, middle + 1, right);
        merge_sort_merge(vec, left, middle, right);
    }
}

void merge_sort_merge(std::vector<float> &vec, size_t const left, size_t const middle, size_t const right)
{
    std::vector<float> vec_temp1(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<float> vec_temp2(vec.begin() + middle + 1, vec.begin() + right + 1);

    size_t i{0}, j{0}, k{0};

    for (i = left; i <= right; i++)
    {
        if (j == vec_temp1.size())
        {
            vec[i] = vec_temp2[k++];
        }
        else if (k == vec_temp2.size())
        {
            vec[i] = vec_temp1[j++];
        }
        else
        {
            if (vec_temp1[j] < vec_temp2[k]) {
                vec[i] = vec_temp1[j++];
            }
            else {
                vec[i] = vec_temp2[k++];
            }
        }
    }
}


void merge_sort(std::vector<int> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
}

void merge_sort(std::vector<int> &vec, size_t const left, size_t const right)
{
    size_t const middle{(left + right) / 2};

    if (left < right)
    {
        merge_sort(vec, left, middle);
        merge_sort(vec, middle + 1, right);
        merge_sort_merge(vec, left, middle, right);
    }
}

void merge_sort_merge(std::vector<int> &vec, size_t const left, size_t const middle, size_t const right)
{
    std::vector<int> vec_temp1(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<int> vec_temp2(vec.begin() + middle + 1, vec.begin() + right + 1);

    size_t i{0}, j{0}, k{0};

    for (i = left; i <= right; i++)
    {
        if (j == vec_temp1.size())
        {
            vec[i] = vec_temp2[k++];
        }
        else if (k == vec_temp2.size())
        {
            vec[i] = vec_temp1[j++];
        }
        else
        {
            if (vec_temp1[j] < vec_temp2[k]) {
                vec[i] = vec_temp1[j++];
            }
            else {
                vec[i] = vec_temp2[k++];
            }
        }
    }
}


// ------ Compare sorts ------

std::vector<int> generate_random_vector(size_t const size, int const max)
{
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]()
                  { return std::rand() % max; });
    return vec;
}

// ------ Dichotomie ------

int search(std::vector<int> const & vec, size_t const left, size_t const right, int const value) {
    if (left > right) {
        return -1;
    }
    size_t middle{(left + right) / 2};
    if (vec[middle] == value) {
        return middle;
    }
    if (vec[middle] > value) {
        return search(vec, left, middle - 1, value);
    }
    return search(vec, middle + 1, right, value);
}

int dichotomie(std::vector<int> const & vec,int const value) {
    std::sort(vec.begin(), vec.end());
   size_t left{0};
   size_t right {vec.size() - 1};

   int middle{(static_cast<int>(left) + static_cast<int>(right)) / 2};
    if (middle > value) {
        right = middle;
    }
    else {
        left = middle;
    }
    return search(vec, left, right, value);
}
