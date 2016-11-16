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
    std::vector< std::vector<double> > times;
    
    f1_obj f1_o;
    f2_obj f2_o;
    f3_obj f3_o;
    f4_obj f4_o;
    f5_obj f5_o;
    f6_obj f6_o;
    
    f1_virtual f1_v;
    f2_virtual f2_v;
    f3_virtual f3_v;
    f4_virtual f4_v;
    f5_virtual f5_v;
    f6_virtual f6_v;
    
    //F1 = 0
    std::vector<double> times_f1;
    //hard coded
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate_f1(a, b, bins);
    t.stop();
    times_f1.push_back(t.duration()/loops);
    
    //function pointer
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f1_point);
    t.stop();
    times_f1.push_back(t.duration()/loops);
    
    //function obj
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f1_o);
    t.stop();
    times_f1.push_back(t.duration());
    
    //virtual function
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f1_v);
    t.stop();
    times_f1.push_back(t.duration());
    
    print(times_f1, f1);
    times.push_back(times_f1);
    
    //f2 = 0
    std::vector<double> times_f2;
    //hard coded
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate_f2(a, b, bins);
    t.stop();
    times_f2.push_back(t.duration()/loops);
    
    //function pointer
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f2_point);
    t.stop();
    times_f2.push_back(t.duration()/loops);
    
    //function obj
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f2_o);
    t.stop();
    times_f2.push_back(t.duration());
    
    //virtual function
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f2_v);
    t.stop();
    times_f2.push_back(t.duration());
    
    print(times_f2, f2);
    times.push_back(times_f2);
    
    //f3 = 0
    std::vector<double> times_f3;
    //hard coded
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate_f3(a, b, bins);
    t.stop();
    times_f3.push_back(t.duration()/loops);
    
    //function pointer
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f3_point);
    t.stop();
    times_f3.push_back(t.duration()/loops);
    
    //function obj
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f3_o);
    t.stop();
    times_f3.push_back(t.duration());
    
    //virtual function
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f3_v);
    t.stop();
    times_f3.push_back(t.duration());
    
    print(times_f3, f3);
    times.push_back(times_f3);
    
    //f4 = 0
    std::vector<double> times_f4;
    //hard coded
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate_f4(a, b, bins);
    t.stop();
    times_f4.push_back(t.duration()/loops);
    
    //function pointer
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f4_point);
    t.stop();
    times_f4.push_back(t.duration()/loops);
    
    //function obj
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f4_o);
    t.stop();
    times_f4.push_back(t.duration());
    
    //virtual function
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f4_v);
    t.stop();
    times_f4.push_back(t.duration());
    
    print(times_f4, f4);
    times.push_back(times_f4);
    
    //f5 = 0
    std::vector<double> times_f5;
    //hard coded
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate_f5(a, b, bins);
    t.stop();
    times_f5.push_back(t.duration()/loops);
    
    //function pointer
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f5_point);
    t.stop();
    times_f5.push_back(t.duration()/loops);
    
    //function obj
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f5_o);
    t.stop();
    times_f5.push_back(t.duration());
    
    //virtual function
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f5_v);
    t.stop();
    times_f5.push_back(t.duration());
    
    print(times_f5, f5);
    times.push_back(times_f5);
    
    //f6 = 0
    std::vector<double> times_f6;
    //hard coded
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate_f6(a, b, bins);
    t.stop();
    times_f6.push_back(t.duration()/loops);
    
    //function pointer
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f6_point);
    t.stop();
    times_f6.push_back(t.duration()/loops);
    
    //function obj
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f6_o);
    t.stop();
    times_f6.push_back(t.duration());
    
    //virtual function
    t.start();
    for(size_t k = 0; k < loops; ++k)
        integrate(a, b, bins, f6_v);
    t.stop();
    times_f6.push_back(t.duration());
    
    print(times_f6, f6);
    times.push_back(times_f6);

    return 0;
}
