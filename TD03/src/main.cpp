#include <iostream>
#include <vector>

#include "tri.hpp"
#include "ScopedTimer.hpp"

int main()
{
    std::vector<int> vec = {40000, 2, 1, 3, 5, 0, 9, 8, 7, 6};

    // ------ Bubble sort ------
    // bubble_sort(vec);

    // ------ Merge sort ------
    // merge_sort(vec);

    // ------ Test de tri ------
    // if (is_sorted(vec))
    // {
    //     for (int i : vec)
    //     {
    //         std::cout << i << " ";
    //     }
    // }
    // else
    // {
    //     std::cout << "Tri de cong";
    // }

    // ------ Compare sorts ------

    // std::vector<int> vec = generate_random_vector(5000, 100);

    // {
    //     ScopedTimer timer("bubble_sort");
    //     bubble_sort(vec);
    // }

    // {
    //     ScopedTimer timer("merge_sort");
    //     merge_sort(vec);
    // }

    // {
    //     ScopedTimer timer("std::sort");
    //     std::sort(vec.begin(), vec.end());
    // }

    std::cout << "entrez un nombre à chercher dans le tableau" << std::endl;
    int value;
    std::cin >> value;
    if (dichotomie(vec, value) == -1)
    {
        std::cout << "le nombre n'est pas dans le tableau" << std::endl;
    }
    else
    {
        std::cout << "le nombre est à l'index " << dichotomie(vec, value) << std::endl;
    }

    return 0;
}