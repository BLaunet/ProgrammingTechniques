#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "genome.hpp"

class Animal {
    typedef unsigned int age_type;
    
public:
    static age_type maxAge = Genome::number_of_genes;
    static age_type age_of_reproduction = 
    
    //Constructor
    Animal(const Genome & gen);
    Animal give_birth();
    bool is_pregnant() const;
    bool is_dead() const;
    void grow();
    
    
private:
    Genome gen_;
    age_type age_;
    
};

#endif