#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include "evaluation.hpp"

int main()
{
    // ----- NPI evaluation -----
    std::string userCalculusNPI{};
    std::getline(std::cin, userCalculusNPI);
    std::cout << userCalculusNPI << std::endl;

    std::vector<std::string> tokens = split_string(userCalculusNPI);

    // std::cout << npi_evaluate(tokens) << std::endl;

    // ----- NPI evaluation with struct and enum -----
    
    std::vector<Token> tokens2 = tokenize(tokens);

    std::cout << npi_evaluate(tokens2) << std::endl;

    return 0;
}