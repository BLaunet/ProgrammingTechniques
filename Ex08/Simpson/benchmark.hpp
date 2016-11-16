#ifndef benchmark_hpp
#define benchmark_hpp

#include "function.hpp"
#include <cmath>

typedef double argument_type;
typedef double return_type;

//Functions for hard-coded and pointer
inline return_type f1 (argument_type x) {return 0;}
inline return_type f2 (argument_type x) {return 1;}
inline return_type f3 (argument_type x) {return x;}
inline return_type f4 (argument_type x) {return x*x;}
inline return_type f5 (argument_type x) {return sin(x);}
inline return_type f6 (argument_type x) {return sin(5*x);}

//Function object
struct f1_obj {
    typedef double result_type;
    typedef double argument_type;
    inline result_type operator()(argument_type x) const {return 0;};
};
struct f2_obj {
    typedef double result_type;
    typedef double argument_type;
    inline result_type operator()(argument_type x) const {return 1;};
};
struct f3_obj {
    typedef double result_type;
    typedef double argument_type;
    inline result_type operator()(argument_type x) const {return x;};
};
struct f4_obj {
    typedef double result_type;
    typedef double argument_type;
    inline result_type operator()(argument_type x) const {return x*x;};
};
struct f5_obj {
    typedef double result_type;
    typedef double argument_type;
    inline result_type operator()(argument_type x) const {return sin(x);};
};
struct f6_obj {
    typedef double result_type;
    typedef double argument_type;
    inline result_type operator()(argument_type x) const {return sin(5*x);};
};

//Virtual function
class f1_virtual: public Function{
public:
    inline result_type operator()(argument_type x) const { return 0;};
};
class f2_virtual: public Function{
public:
    inline result_type operator()(argument_type x) const { return 1;};
};
class f3_virtual: public Function{
public:
    inline result_type operator()(argument_type x) const { return x;};
};
class f4_virtual: public Function{
public:
    inline result_type operator()(argument_type x) const { return x*x;};
};
class f5_virtual: public Function{
public:
    inline result_type operator()(argument_type x) const { return sin(x);};
};
class f6_virtual: public Function{
public:
    inline result_type operator()(argument_type x) const { return sin(5*x);};
};

#endif /* benchmark_hpp */
