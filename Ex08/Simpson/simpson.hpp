#ifndef simpson_hpp
#define simpson_hpp

#include <cassert>
#include "benchmark.hpp"

template <class F>
struct domain_type { typedef typename F::argument_type type; };

template <class R, class T>
struct domain_type<R(*)(T)> { typedef T type; };

template <class R, class T>
struct domain_type<R(T)> { typedef typename domain_type<R(*)(T)>::type type; };

template <class F>
struct result_type { typedef typename F::result_type type; };

template <class R, class T>
struct result_type<R(*)(T)> { typedef R type; };

template <class R, class T>
struct result_type<R(T)> { typedef typename result_type<R(*)(T)>::type type; };

// mskoenz: I would normally tell you, that you are missing a version that takes 
// Function, but since you passed in a *f_v in the main, it's fine 
// (the template instanciates for the baseclass)

template <class F>
typename result_type<F>::type integrate(typename domain_type<F>::type a, typename domain_type<F>::type b, unsigned int bins, const F& func)
{
    typedef typename domain_type<F>::type domain_t;
    const domain_t dr = (b - a) / (2.*bins);
    typename result_type<F>::type I2(0), I4(0);
    domain_t pos = a;
    
    for(unsigned i = 0; i < bins; ++i) {
        pos += dr;
        I4 += func(pos);
        pos += dr;
        I2 += func(pos);
    }
    
    return (func(a) + 2.*I2 + 4.*I4 - func(b)) * (dr/3.);
}

//Hard Coded integrations
double integrate_f1(double a, double b, unsigned int bins)
{
    const double dr = (b - a) / (2.*bins);
    double I2(0), I4(0);
    double pos = a;
    
    for(unsigned i = 0; i < bins; ++i) {
        pos += dr;
        I4 += f1_point(pos);
        pos += dr;
        I2 += f1_point(pos);
    }
    
    return (f1_point(a) + 2.*I2 + 4.*I4 - f1_point(b)) * (dr/3.);
}

double integrate_f2(double a, double b, unsigned int bins)
{
    const double dr = (b - a) / (2.*bins);
    double I2(0), I4(0);
    double pos = a;
    
    for(unsigned i = 0; i < bins; ++i) {
        pos += dr;
        I4 += f2_point(pos);
        pos += dr;
        I2 += f2_point(pos);
    }
    
    return (f2_point(a) + 2.*I2 + 4.*I4 - f2_point(b)) * (dr/3.);
}

double integrate_f3(double a, double b, unsigned int bins)
{
    const double dr = (b - a) / (2.*bins);
    double I2(0), I4(0);
    double pos = a;
    
    for(unsigned i = 0; i < bins; ++i) {
        pos += dr;
        I4 += f3_point(pos);
        pos += dr;
        I2 += f3_point(pos);
    }
    
    return (f3_point(a) + 2.*I2 + 4.*I4 - f3_point(b)) * (dr/3.);
}

double integrate_f4(double a, double b, unsigned int bins)
{
    const double dr = (b - a) / (2.*bins);
    double I2(0), I4(0);
    double pos = a;
    
    for(unsigned i = 0; i < bins; ++i) {
        pos += dr;
        I4 += f4_point(pos);
        pos += dr;
        I2 += f4_point(pos);
    }
    
    return (f4_point(a) + 2.*I2 + 4.*I4 - f4_point(b)) * (dr/3.);
}

double integrate_f5(double a, double b, unsigned int bins)
{
    const double dr = (b - a) / (2.*bins);
    double I2(0), I4(0);
    double pos = a;
    
    for(unsigned i = 0; i < bins; ++i) {
        pos += dr;
        I4 += f5_point(pos);
        pos += dr;
        I2 += f5_point(pos);
    }
    
    return (f5_point(a) + 2.*I2 + 4.*I4 - f5_point(b)) * (dr/3.);
}

double integrate_f6(double a, double b, unsigned int bins)
{
    const double dr = (b - a) / (2.*bins);
    double I2(0), I4(0);
    double pos = a;
    
    for(unsigned i = 0; i < bins; ++i) {
        pos += dr;
        I4 += f6_point(pos);
        pos += dr;
        I2 += f6_point(pos);
    }
    
    return (f6_point(a) + 2.*I2 + 4.*I4 - f6_point(b)) * (dr/3.);
}

std::function<double(double, double, unsigned int)> get_hard_integ(Func fp)
{
    switch (fp) {
        case f1:
            return integrate_f1;
            break;
        case f2:
            return integrate_f2;
            break;
        case f3:
            return integrate_f3;
            break;
        case f4:
            return integrate_f4;
            break;
        case f5:
            return integrate_f5;
            break;
        default:
            return integrate_f6;
    }
}
#endif /* simpson_hpp */
