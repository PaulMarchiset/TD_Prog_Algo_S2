// #include "hash.hpp"

// int main()
// {
//     // --------- HASHING FUNCTIONS TESTS ---------

//     std::string str = "hello IMAC";
//     size_t hashMax = 1e9 + 1;
//     size_t p = 31;

//     std::cout << "Hash value: " << polynomial_rolling_hash(str, p, hashMax) << std::endl;

//     // --------- ASSOCIATIVE ARRAY TESTS ---------

//     return 0;
// }

#include <iostream>
#include <numeric>


enum class Insect {
    ClassicBee,
    Ladybug,
    Butterfly,
    Dragonfly,
    Ant,
    Grasshopper,
    Beetle,
    Wasp,
    Caterpillar,
    Spider,
    GuimielBee
};

#include <vector>
const std::vector<Insect> insect_values {
    Insect::ClassicBee,
    Insect::Ladybug,
    Insect::Butterfly,
    Insect::Dragonfly,
    Insect::Ant,
    Insect::Grasshopper,
    Insect::Beetle,
    Insect::Wasp,
    Insect::Caterpillar,
    Insect::Spider,
    Insect::GuimielBee
};

#include <unordered_map>
#include <string>

const std::unordered_map<Insect, std::string> insect_to_string = {
    {Insect::ClassicBee, "ClassicBee"},
    {Insect::Ladybug, "Ladybug"},
    {Insect::Butterfly, "Butterfly"},
    {Insect::Dragonfly, "Dragonfly"},
    {Insect::Ant, "Ant"},
    {Insect::Grasshopper, "Grasshopper"},
    {Insect::Beetle, "Beetle"},
    {Insect::Wasp, "Wasp"},
    {Insect::Caterpillar, "Caterpillar"},
    {Insect::Spider, "Spider"},
    {Insect::GuimielBee, "GuimielBee"}
};

#include <vector>
const std::vector<int> expected_insect_counts {
    75, // ClassicBee
    50, // Ladybug
    100, // Butterfly
    20, // Dragonfly
    400, // Ant
    150, // Grasshopper
    60, // Beetle
    10, // Wasp
    40, // Caterpillar
    90, // Spider 
    5, // GuimielBee
};

#include <functional>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<std::pair<Insect, int>> get_insect_observations(const size_t number_of_observations, std::vector<float> const& insect_probabilities, const unsigned int seed = std::random_device{}()) {
    // Create a random engine with a given seed
    std::default_random_engine random_engine(seed);

    auto randInsectIndex { std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine) };
    
    std::vector<std::pair<Insect, int>> observations {};
    observations.reserve(number_of_observations);

    for(size_t i {0}; i < number_of_observations; ++i) {
        size_t const random_insect_index { randInsectIndex() };
        Insect const random_insect { insect_values[random_insect_index] };
        
        //If we have already seen the same insect, increment the count on the last observation
        auto& previous_observation { observations.back() };
        if(previous_observation.first == random_insect) {
            previous_observation.second++;
            i -= 1;
        } else {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}

std::vector<float> probabilities_from_count(std::vector<int> const& counts) {
    std::vector<float> probabilities;
    size_t const totalCount { static_cast<size_t>(std::accumulate(counts.begin(), counts.end(), 0)) };

    for (float oneCount : counts) {
        oneCount /= totalCount;
        probabilities.push_back(oneCount);
    };
    
    return probabilities;
}

int main() {

    // --------- EXERCICE 2.1 ---------

    std::vector<float> probabilities = probabilities_from_count(expected_insect_counts);
    
    for (float oneProbability : probabilities) {
        std::cout << oneProbability << std::endl;
    }

    // --------- EXERCICE 2.2 ---------


    //use unordered_map to count the number of observations for each insect
    std::unordered_map<Insect, int> insect_counts;
    
    get_insect_observations(1000, probabilities);

    
   

    return 0;
    
}