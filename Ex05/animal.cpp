/* Programming Techniques for Scientific Simulations, HS 2016
 * Exercise 4.3
 */

#include "animal.hpp"
#include <cassert>
#include <iostream>
namespace Penna
{
    
/// Number of bad genes an animal can tolerate. Parameter T in Penna's paper.
age_type Animal::bad_threshold_;
/// Maturity age. Parameter R in Penna's paper.
age_type Animal::maturity_age_;
/// Probability to be pregnant
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
{
}
/// Constructor using a given genome.
Animal::Animal( const Genome& gen )
:   gen_(gen)
,   age_(0)
{
}

bool Animal::is_dead() const
{
    //std::cout << "Bad Genes = " << gen_.count_bad(age_) << std::endl;
    return age_ > maximum_age || gen_.count_bad(age_) > bad_threshold_;
}
    
bool Animal::is_pregnant() const
{
    if(age_ >= maturity_age_)
        return ((rand() % 100)/100. > probability_to_get_pregnant_);
    else
        return false;
}
    
age_type Animal::age() const
{
    return age_;
}

/// Make the animal grow older by one year.
void Animal::grow()
{
    age_++;
}

/// Create a baby animal inheriting its genome from this except for some random mutations.
Animal Animal::give_birth() const
{
    Genome child_genome = gen_;
    child_genome.mutate();
    return Animal(child_genome);
}

} // end namespace Penna