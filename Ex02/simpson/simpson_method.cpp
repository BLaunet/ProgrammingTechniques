#include <cassert>
#include "simpson_method.hpp"
double integrate(double a, double b, int bins, double f(double x))
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

