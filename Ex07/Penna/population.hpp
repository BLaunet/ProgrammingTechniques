#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <list>
#include <stdlib.h>
#include "animal.hpp"
#include <vector>
#include <iostream>

namespace Penna
{
    
class Population
{
public:
    typedef unsigned int size_type;
    typedef std::list<Penna::Animal> pop_type;
    
    static size_type max_pop_;
    static void set_max_population(size_type);
    
    //Default constructor : Population of max size with all animals having good genome and age 0
    Population();
    //Constructor for a size N population
    Population(size_type);
    
    size_type size() const;
    //Make all the animals of the population grow of a year
    void aging();
    //Generates babies for those who are pregnant
    void births();
    //Kill the animals that are supposed to be dead
    void deaths();
    //Return a vector with the age of each animal in the population
    std::vector<age_type> get_ages();
    //Return a vector with the number of bad genome for each animal in the population
    std::vector<age_type> get_bad_genomes();
    
private:
    pop_type pop_;
};
    
} // end of namespace Penna

#endif