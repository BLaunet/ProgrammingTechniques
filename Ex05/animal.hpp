/* Programming Techniques for Scientific Simulations, HS 2016
 * Exercise 4.3
 */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "genome.hpp"

namespace Penna
{

/**
 * Animal having a genome and age.
 */
class Animal
{
public:
    static const age_type maximum_age = Genome::number_of_genes;

    static void set_bad_threshold( age_type );
    static void set_maturity_age( age_type );
    static void set_probability_to_get_pregnant ( double );

    /// Default constructor: Uses all good genome.
    Animal();
    /// Constructor using a given genome.
    Animal( const Genome& gen );

    bool is_dead() const;
    bool is_pregnant() const;
    age_type age() const;
    
    /// Make the animal grow older by one year.
    void grow();
    /// Create a baby animal inheriting its genome from this except for some random mutations.
    Animal give_birth() const;

private:
    /// Number of bad genes an animal can tolerate. Parameter T in Penna's paper.
    static age_type bad_threshold_;
    /// Maturity age. Parameter R in Penna's paper.
    static age_type maturity_age_;
    /// Probability to be pregnant
    static double probability_to_get_pregnant_;

    const Genome gen_;
    age_type age_;
    bool pregnant_;
};

} // end namespace Penna

#endif // !defined ANIMAL_HPP
