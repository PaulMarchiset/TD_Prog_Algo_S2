#include "iteratorExercices.hpp"

// ------ Vecteur de nombres aléatoires ------

std::vector<int> generate_random_vector(size_t const size, int const max)
{
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]()
                  { return std::rand() % max; });
    return vec;
}

// ------ Séparation de string ------

// ------ Version 1 qui bug :c ------
// std::vector<std::string> split_string(std::string const &str) {
//     std::vector<std::string> words;
//     std::string oneWord;

//     std::string::const_iterator it;
//     it = std::find_if_not(str.begin(), str.end(), is_space);

//     while (it != str.end()) {
//         if(is_space(*it)) {
//             words.push_back(oneWord);
//             oneWord.clear();
//         } else {
//             oneWord.push_back(*it);
//         }
//         it = std::find_if_not(it, str.end(), is_space);
//         ++it;
//     }

//     return words;
// }

// ------ Version 2 avec des copy :D ------
std::vector<std::string> split_string(std::string const &str)
{
    std::vector<std::string> words;
    auto it = str.begin();

    while (it != str.end())
    {
        // Skip leading spaces
        it = std::find_if_not(it, str.end(), is_space);
        if (it == str.end())
            break;

        // Find the end of the word
        auto word_end = std::find_if(it, str.end(), is_space);

        // Add the word to the vector
        words.emplace_back(it, word_end);

        // Move iterator to the end of the word
        it = word_end;
    }

    return words;
}

// ------ Palindrome ------

bool is_palindrome(std::string const &str)
{
    return std::equal(std::begin(str),
                      std::begin(str) + std::size(str) / 2,
                      std::rbegin(str));
}