#include "population.hpp"
#include "animal.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

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
    // mskoenz: use splice // blaunet : done
    pop_.splice(pop_.begin(),children);
}
    
class animal_dies_
{
public:
    animal_dies_(const Population::size_type &N): pop_size(N){}
    bool operator()(const Animal& a)
    {
        return (a.is_dead() || drand48() < (double) pop_size/Population::max_pop_);
    }
    private:
        Population::size_type pop_size;
        
};

void Population::deaths()
{
    pop_.remove_if(animal_dies_(pop_.size())); // mskoenz: not bad ;)

}


std::vector<age_type> Population::get_ages()
{
    std::vector<age_type> ages;
    
    // mskoenz: do it without loop
    //for(pop_type::iterator a=pop_.begin(); a!=pop_.end(); ++a)
    //{
    //    ages.push_back(a->age());
    //}
    //return ages;
    // blaunet : OK
    std::transform(pop_.begin(), pop_.end(), ages.begin(), std::mem_fun_ref(&Animal::age));
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


