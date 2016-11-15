#ifndef benchmark_hpp
#define benchmark_hpp

#include "function.hpp"
#include <cmath>

typedef double argument_type;
typedef double return_type;

//Functions for hard-coded and pointer
inline return_type f1 (argument_type x)
{
    return 0;
}

inline return_type f2 (argument_type x)
{
    return 1;
}

inline return_type f3 (argument_type x)
{
    return x;
}

inline return_type f4 (argument_type x)
{
    return sin(x);
}

inline return_type f5 (argument_type x)
{
    return sin(5*x);
}

//Function object
struct f1_obj {
    typedef double result_type;
    typedef double argument_type;
    f1_obj(){};
    inline double operator()(double x) const {return x;};
};

//Virtual function
class exp_lambda_x: public Function{
    const double lambda_;
public:
    exp_lambda_x(double l): lambda_(l) {};
    result_type operator()(argument_type x) const { return exp(lambda_*x);};
};

class square: public Function {
public:
    result_type const operator()(argument_type x) { return pow(x, 2);};
};

#endif /* benchmark_hpp */
