#ifndef function_hpp
#define function_hpp

class Function {
public:
    typedef double result_type;
    typedef double argument_type;
    virtual result_type operator() (argument_type x) const = 0;
};

#endif /* function_hpp */
