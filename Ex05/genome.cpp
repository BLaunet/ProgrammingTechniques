/* Programming Techniques for Scientific Simulations, HS 2016
 * Exercise 4.3
 */
#include "genome.hpp"
#include <bitset>
#include <cassert>
#include <set>
#include <stdlib.h>
namespace Penna
{
    
age_type Genome::mutation_rate_;

void Genome::set_mutation_rate(age_type m)
{
    Genome::mutation_rate_ = m;
}

/// Count number of bad genes in first n years.
age_type Genome::count_bad(age_type n) const
{
    return (genes_<<(number_of_genes - n -1)).count();
}

/// mutate the genome by flipping of M genes
void Genome::mutate()
{
    std::set<age_type> keys;
    while(keys.size() < mutation_rate_)
        keys.insert(rand() % number_of_genes);
    for (std::set<age_type>::iterator k = keys.begin(); k!=keys.end(); ++k)
        genes_.flip(*k);
}


} // end namespace Penna
