#include "population.hpp"
#include "animal.hpp"
#include <iostream>
#include <list>
#include <vector>

namespace Penna{
    

Population::size_type Population::max_pop_;
void Population::set_max_population(size_type N)
{
    Population::max_pop_ = N;
}

Population::Population()
:   pop_(max_pop_)
{
}

Population::Population(size_type N)
:   pop_(N)
{
}

Population::size_type Population::size() const
{
    return pop_.size();
}

void Population::aging()
{
    std::for_each(pop_.begin(), pop_.end(), std::mem_fun_ref(&Animal::grow));
}

void Population::births()
{
    pop_type children;
    for(pop_type::iterator a=pop_.begin(); a!=pop_.end(); ++a)
    {
        if (a->is_pregnant()) {
            children.push_back(a->give_birth());
        }
    }
    // mskoenz: use splice
    std::copy(children.begin(),children.end(), back_inserter(pop_));
}

void Population::deaths()
{
    pop_.remove_if(animal_dies_(pop_.size())); // mskoenz: not bad ;)
}

std::vector<age_type> Population::get_ages()
{
    std::vector<age_type> ages;
    
    // mskoenz: do it without loop
    for(pop_type::iterator a=pop_.begin(); a!=pop_.end(); ++a)
    {
        ages.push_back(a->age());
    }
    return ages;
}
    
std::vector<age_type> Population::get_bad_genomes()
{
    std::vector<age_type> genomes;
    for(pop_type::iterator a=pop_.begin(); a!=pop_.end(); ++a)
    {
        genomes.push_back(a->get_gen().count_bad(a->age()));
    }
    return genomes;
}
    

    
}


