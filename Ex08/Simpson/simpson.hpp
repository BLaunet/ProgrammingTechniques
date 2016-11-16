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
        I4 += f1(pos);
        pos += dr;
        I2 += f1(pos);
    }
    
    return (f1(a) + 2.*I2 + 4.*I4 - f1(b)) * (dr/3.);
}

double integrate_f2(double a, double b, unsigned int bins)
{
    const double dr = (b - a) / (2.*bins);
    double I2(0), I4(0);
    double pos = a;
    
    for(unsigned i = 0; i < bins; ++i) {
        pos += dr;
        I4 += f2(pos);
        pos += dr;
        I2 += f2(pos);
    }
    
    return (f2(a) + 2.*I2 + 4.*I4 - f2(b)) * (dr/3.);
}

double integrate_f3(double a, double b, unsigned int bins)
{
    const double dr = (b - a) / (2.*bins);
    double I2(0), I4(0);
    double pos = a;
    
    for(unsigned i = 0; i < bins; ++i) {
        pos += dr;
        I4 += f3(pos);
        pos += dr;
        I2 += f3(pos);
    }
    
    return (f3(a) + 2.*I2 + 4.*I4 - f3(b)) * (dr/3.);
}

double integrate_f4(double a, double b, unsigned int bins)
{
    const double dr = (b - a) / (2.*bins);
    double I2(0), I4(0);
    double pos = a;
    
    for(unsigned i = 0; i < bins; ++i) {
        pos += dr;
        I4 += f4(pos);
        pos += dr;
        I2 += f4(pos);
    }
    
    return (f4(a) + 2.*I2 + 4.*I4 - f4(b)) * (dr/3.);
}

double integrate_f5(double a, double b, unsigned int bins)
{
    const double dr = (b - a) / (2.*bins);
    double I2(0), I4(0);
    double pos = a;
    
    for(unsigned i = 0; i < bins; ++i) {
        pos += dr;
        I4 += f5(pos);
        pos += dr;
        I2 += f5(pos);
    }
    
    return (f5(a) + 2.*I2 + 4.*I4 - f5(b)) * (dr/3.);
}

double integrate_f6(double a, double b, unsigned int bins)
{
    const double dr = (b - a) / (2.*bins);
    double I2(0), I4(0);
    double pos = a;
    
    for(unsigned i = 0; i < bins; ++i) {
        pos += dr;
        I4 += f6(pos);
        pos += dr;
        I2 += f6(pos);
    }
    
    return (f6(a) + 2.*I2 + 4.*I4 - f6(b)) * (dr/3.);
}
#endif /* simpson_hpp */
