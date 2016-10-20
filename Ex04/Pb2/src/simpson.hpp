#ifndef SIMPSON_HPP
#define SIMPSON_HPP

#include <cassert>
//Concepts needed :
//	a and b should be CopyConstructible
//	f needs an operator()

template<typename T, class F>
double integrate(const T a, const T b, const unsigned bins,const F &f)
{
    assert(bins > 0);
    double step = (b-a)/bins;
    double x = a;
    double integ = 0;
    
    for(int i=0; i < bins; i++)
    {
        integ += step/6*(f(x) + 4*f(x + step/2) + f(x + step));
        x += step;
    }
    return integ;
}

#endif
