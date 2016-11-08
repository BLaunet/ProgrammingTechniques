#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include "timer.hpp"

template <typename C>
double insert_test(C container, int val, unsigned int pos)
{
    Timer t;
    unsigned kMax = 1000000;
    t.start();
    for(unsigned k = 0; k < kMax; ++k)
    {
        typename C::iterator it = container.begin();
        std::advance(it, pos);
        container.insert(it, val);
        container.erase(it);
    }
    t.stop();
    return t.duration()/kMax;
}
template<>
double insert_test<std::set<int>>( std::set<int> container, int val, unsigned int pos)
{
    if(val%2==0)
    {
        val++;
        pos++;
    }
    Timer t;
    unsigned kMax = 1000000;
    t.start();
    for(unsigned k = 0; k < kMax; ++k)
    {
        container.insert(val);
        container.erase(val);
    }
    t.stop();
    return t.duration()/kMax;
}

int main()
{
    srand(42);
    unsigned int N_max = 100000;

    for(unsigned int n = 1; n<N_max+1; n*=10)
    {
        int array[n];
        for(unsigned int i = 0; i<n; ++i)
            array[i] = 2*i;
        
        std::vector<int> v(array, array + n);
        std::set<int> s(array, array + n);
        std::list<int> l(array, array + n);

        int j = rand() % n;
        int pos = j/2;
        if( j%2 != 0)
            pos++;
        
        std::cout.precision(12);
        
        std::cout << "For N = " <<  n << " : " << std::endl;
        std::cout << "\t Vector = " <<  insert_test(v, j, pos) << " s " << std::endl;
        std::cout << "\t List = " <<  insert_test(l,j,pos) << " s " << std::endl;
        std::cout << "\t Set = " <<  insert_test(s,j,pos) << " s " << std::endl;

    }
}
