#ifndef simpson_hpp
#define simpson_hpp

#include <cassert>

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

#endif /* simpson_hpp */
