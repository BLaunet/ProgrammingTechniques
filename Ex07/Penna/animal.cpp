#include "animal.hpp"
#include "genome.hpp"
#include <cassert>
#include <iostream>
namespace Penna
{
    
age_type Animal::bad_threshold_;
age_type Animal::maturity_age_;
double Animal::probability_to_get_pregnant_;

void Animal::set_bad_threshold( age_type bt )
{
    bad_threshold_ = bt;
}
    
void Animal::set_maturity_age( age_type m )
{
    maturity_age_ = m;
}
void Animal::set_probability_to_get_pregnant (double p )
{
    probability_to_get_pregnant_ = p;
}

Animal::Animal()
:   gen_()
,   age_(0)
,   pregnant_(0)
{
}
/// Constructor using a given genome.
Animal::Animal( const Genome& gen )
:   gen_(gen)
,   age_(0)
,   pregnant_(0)
{
}

bool Animal::is_dead() const
{
    return age_ > maximum_age || gen_.count_bad(age_) >= bad_threshold_;
}
    
bool Animal::is_pregnant() const
{
    return pregnant_;
}
    
age_type Animal::age() const
{
    return age_;
    
}
    
Genome Animal::get_gen() const
{
    return gen_;
}

/// Make the animal grow older by one year.
void Animal::grow()
{
    assert(!is_dead());
    age_++;
    if(age_ >= maturity_age_ && !pregnant_)
    {
        pregnant_=(drand48()  < probability_to_get_pregnant_);
    }
    
}

/// Create a baby animal inheriting its genome from this except for some random mutations.
Animal Animal::give_birth()
{
    assert(pregnant_);
    pregnant_=false;
    Genome child_genome = gen_;
    child_genome.mutate();
    return Animal(child_genome);
}

} // end namespace Penna