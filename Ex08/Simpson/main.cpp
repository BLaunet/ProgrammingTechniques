#include <iostream>
#include "simpson.hpp"
#include "benchmark.hpp"
#include "timer.hpp"
#include "function.hpp"
#include <vector>

void print(const std::vector<double> times, Func f)
{
    std::string names[4] = {"Hard-coded", "Function pointer", "Function object", "Virtual function"};
    std::string str;
    str+="Execution times for ";
    switch (f)
    {
        case f1:
            str+= "f1 = 0";
            break;
        case f2:
            str+= "f2 = 1";
            break;
        case f3:
            str+= "f3 = x";
            break;
        case f4:
            str+= "f4 = x^2";
            break;
        case f5:
            str+= "f5 = sin(x)";
            break;
        case f6:
            str+= "f6 = sin(5*x)";
            break;
            
    }
    std::cout << str << std::endl;
    int i = 0;
    for (std::vector<double>::const_iterator p=times.begin(); p!=times.end(); ++p) {
        std::cout << "\t" << names[i] << " : " << *p << std::endl;
        i++;
    }
}

int main() {
    double a = 0;
    double b = 1;
    unsigned bins = 1000;
    size_t loops = 100000;
    Timer t;
    
    //I really tried my best to build a get_object_function(fn) that could give me the right object function corresponding to the enum fn, and so avoid copy/paste... but I give up
    f1_obj f1_o;
    f2_obj f2_o;
    f3_obj f3_o;
    f4_obj f4_o;
    f5_obj f5_o;
    f6_obj f6_o;
    for (int f_int = f1; f_int <= f6; f_int++) {
        
        Func f_n = static_cast<Func>(f_int);
        
        std::vector<double> times;
        
        //hard coded
        std::function<double(double, double, unsigned int)> integ_hard = get_hard_integ(f_n);
        t.start();
        for(size_t k = 0; k < loops; ++k)
            integ_hard(a, b, bins);
        t.stop();
        times.push_back(t.duration()/loops);
        
        //function pointer
        std::function<return_type(argument_type)> f_p =  get_pointer_f(f_n);
        t.start();
        for(size_t k = 0; k < loops; ++k)
            integrate(a, b, bins, f_p);
        t.stop();
        times.push_back(t.duration()/loops);
        
        //function obj
        switch (f_n) {
            case f1:
                t.start();
                for(size_t k = 0; k < loops; ++k)
                    integrate(a, b, bins, f1_o);
                t.stop();
                break;
            case f2:
                t.start();
                for(size_t k = 0; k < loops; ++k)
                    integrate(a, b, bins, f2_o);
                t.stop();
                break;
            case f3:
                t.start();
                for(size_t k = 0; k < loops; ++k)
                    integrate(a, b, bins, f3_o);
                t.stop();
                break;
            case f4:
                t.start();
                for(size_t k = 0; k < loops; ++k)
                    integrate(a, b, bins, f4_o);
                t.stop();
                break;
            case f5:
                t.start();
                for(size_t k = 0; k < loops; ++k)
                    integrate(a, b, bins, f5_o);
                t.stop();
                break;
            case f6:
                t.start();
                for(size_t k = 0; k < loops; ++k)
                    integrate(a, b, bins, f6_o);
                t.stop();
                break;
        }
        times.push_back(t.duration());
        
        //virtual function
        Function* f_v = get_virtual_f(f_n);

        t.start();
        for(size_t k = 0; k < loops; ++k)
            integrate(a, b, bins, *f_v);
        t.stop();
        delete f_v;
        times.push_back(t.duration());
        
        print(times, f_n);
    }
    
    return 0;
}
