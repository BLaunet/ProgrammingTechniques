#include "population.hpp"
#include "animal.hpp"
#include <iostream>
using namespace Penna;

int main()
{
    srand(42);
    //Setting Penna's parameters
    Population::set_max_population(100000);
    Animal::set_probability_to_get_pregnant(0.9);
    Animal::set_maturity_age(8);
    Genome::set_mutation_rate(20);
    Animal::set_bad_threshold(2);
    
    
    // mskoenz: fish(3) is enough
    Population fish = Population(3);
    std:: cout << "Year Population_size" << std::endl;
    for (unsigned i = 0; i<1000; ++i) {
        fish.aging();
        fish.births();
        fish.deaths();
        std::cout << i+1 << " " << fish.size() << std::endl;
        
    }
    std::vector<age_type> distrib = fish.get_bad_genomes();
    for(std::vector<age_type>::iterator g = distrib.begin(); g!=distrib.end(); ++g)
    {
        std::cout << *g << std::endl;
    }
    
    return 0;
}
