#include "iteratorExercices.hpp"

int main()
{

    // ------ Vecteur de nombres aléatoires ------
    std::vector<int> vec = generate_random_vector(5, 100);
    // std::vector<int> vec = {0, 0, 0, 0, 0};


    // ------ Affichage du vecteur avec itérateurs ------    
    // for (std::vector<int>::iterator it { vec.begin() }; it != vec.end(); ++it) {
    //     std::cout << *it << std::endl;
    // }


    // ------ std::find ------

    // int userNumber { 0 };
    // std::cout << "Entre un nombre OwO : ";
    // std::cin >> userNumber;

    // auto it { std::find(vec.begin(), vec.end(), userNumber) };

    // if (it != vec.end())
    // {
    //     std::cout << "Le nombre " << *it << " est bien dans le tableau GG !" << std::endl;
    // }
    // else
    // {
    //     std::cout << "Dommage le nombre n'est pas dans le tableau :/" << std::endl;
    // }


    // ------ std::count ------
    // int userNumber { 0 };
    // std::cout << "Entre un nombre OwO : ";
    // std::cin >> userNumber;

    // auto it { std::count(vec.begin(), vec.end(), userNumber) };

    // if (it != 0)
    // {
    //     std::cout << "Le nombre " << userNumber << " est présent " << it << " fois dans le tableau GG !" << std::endl;
    // }
    // else
    // {
    //     std::cout << "Dommage le nombre n'est pas dans le tableau :/" << std::endl;
    // }


    // ------ std::sort ------
    // std::sort(vec.begin(), vec.end());
    // for (std::vector<int>::iterator it { vec.begin() }; it != vec.end(); ++it) {
    //     std::cout << *it << std::endl;
    // }


    // ------ std::accumulate ------
    
    // int sum { std::accumulate(vec.begin(), vec.end(), 0) };
    // std::cout << "La somme des éléments du tableau est : " << sum << std::endl;


    // ------ std::find_if ------
    std::string str {"Hi IMAC"};

    std::string::iterator it { std::find_if(str.begin(), str.end(), is_space) };
    std::cout << "First word is " << std::distance(str.begin(), it) << " letters long" << std::endl;
    
    for (auto word: split_string(str)) {
        std::cout << word << std::endl;
    }


    // ------ Palindrome ------
    // std::string str {"saippuakivikauppias"};
    // std::cout << "Is the word " << str << " a palindrome ? " << std::boolalpha << is_palindrome(str) << std::endl;



    return 0;
}