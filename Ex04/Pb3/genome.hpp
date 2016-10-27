#ifndef GENOME_HPP
#define GENOME_HPP
#include <bitset>

class Genome {
public:
    typedef unsigned int age_type;
    
    //Max number of genes
    static const age_type number_of_genes = 64;
    
    //Sets mutation rate and threshold if environment conditions change
    static void set_mutation_rate( age_type );
    static void set_threshold( age_type );
    
    //Counts the number of bad genes until year n
    age_type count_bad_genes(age_type) const;
    
    //Get the threshold
    static age_type get_bad_threshold() const;
    
    //Mutate M genes
    void mutate();
    
private:
    std::bitset<number_of_genes> genes_;
    //Parameter M in Penna's model
    static age_type mutation_rate_;
    //Number of bad genes an animal can have before dying
    static age_type threshold_;

    
};
#endif