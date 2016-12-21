#ifndef RandomGenerator_hpp
#define RandomGenerator_hpp

#include <limits>
#include <random>
#include <math.h>
#include <iostream>

class RNG {
public:
    typedef double result_type;
    typedef double param_type;
    
    //Constructor
    RNG(const param_type& param = 1): _p(param){};
    
    //Functions to fulfill the requirements
    result_type min() const {return -std::numeric_limits<result_type>::infinity(); }
    result_type max() const {return std::numeric_limits<result_type>::infinity(); }
    void reset(){}
    void param(param_type& p) {_p = p;}
    param_type param() const {return _p;}
    inline bool operator==(const RNG& rhs) const { return (rhs.param() == (*this).param()); }
    inline bool operator!=(const RNG& rhs) const { return !(*this == rhs); }
    
    friend std::ostream& operator <<(std::ostream& out, const RNG& g){
        out << g.param();
        return out;
    }
    
    friend std::istream& operator>>(std::istream& in, RNG& g){
        if (in.gcount()>1)
            in.setstate(std::ios::failbit);
        else
        {
            param_type p;
            in >> p;
            g.param(p);
        }
        return in;
    }
    
    template<class UniformRNG>
    result_type operator()(UniformRNG &g)
    {
        std::normal_distribution<> nd = std::normal_distribution<result_type>(0,_p);
        std::uniform_real_distribution<> u = std::uniform_real_distribution<result_type>(0.,1.);
        result_type x;
        result_type f;
        result_type y;
        result_type n;
        do {
            x = nd(g);
            // mskoenz: it would be much cheaper not to calc this and just check ...
            f = (2./(sqrt(2*M_PI)*_p))*pow(cos(x/_p),2)*exp(-pow(x,2)/(2*pow(_p,2)));
            n = (1/(sqrt(2*M_PI)*_p))*exp(-(pow(x,2))/(2*pow(_p,2)));
            y = u(g);
        } while (y>=f/(2*n)); // y>=pow(cos..., 2)
        return x;
    }
    
    template<class UniformRNG>
    result_type operator()(UniformRNG &g, param_type p)
    {
        this->param(p);
        return this->operator()(g);
    }
private:
    param_type _p;
    
};
#endif /* RandomGenerator_hpp */
