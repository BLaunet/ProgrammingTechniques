#include <iostream>
#include "simpson.hpp"
#include "benchmark.hpp"
#include "timer.hpp"
#include "function.hpp"
#include <vector>

int main() {
    //Instanciation of oc-bjects
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
    
    double a = 0;
    double b = 1;
    unsigned bins = 100;
    size_t loops = 100000;
    Timer t;
    
    // F1 = 0
    std::vector<double> times_f1;
        //hard coded
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate_f1(a, b, bins);}
    t.stop();
    times_f1.push_back(t.duration()/loops);
        //function pointer
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f1);}
    t.stop();
    times_f1.push_back(t.duration()/loops);
        //function obj
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f1_o);}
    t.stop();
    times_f1.push_back(t.duration());
        //virtual function
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f1_v);}
    t.stop();
    times_f1.push_back(t.duration());
    
    std::cout << "Execution times for f1 = 0" << std::endl;
    for (std::vector<double>::iterator p=times_f1.begin(); p!=times_f1.end(); ++p) {
        std::cout << "\t" << *p << std::endl;
    }
    
    // f2 = 1
    std::vector<double> times_f2;
    //hard coded
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate_f2(a, b, bins);}
    t.stop();
    times_f2.push_back(t.duration()/loops);
    //function pointer
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f2);}
    t.stop();
    times_f2.push_back(t.duration()/loops);
    //function obj
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f2_o);}
    t.stop();
    times_f2.push_back(t.duration());
    //virtual function
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f2_v);}
    t.stop();
    times_f2.push_back(t.duration());
    
    std::cout << "Execution times for f2 = 1" << std::endl;
    for (std::vector<double>::iterator p=times_f2.begin(); p!=times_f2.end(); ++p) {
        std::cout << "\t" << *p << std::endl;
    }
    
    // f3 = x
    std::vector<double> times_f3;
    //hard coded
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate_f3(a, b, bins);}
    t.stop();
    times_f3.push_back(t.duration()/loops);
    //function pointer
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f3);}
    t.stop();
    times_f3.push_back(t.duration()/loops);
    //function obj
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f3_o);}
    t.stop();
    times_f3.push_back(t.duration());
    //virtual function
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f3_v);}
    t.stop();
    times_f3.push_back(t.duration());
    
    std::cout << "Execution times for f3 = x" << std::endl;
    for (std::vector<double>::iterator p=times_f3.begin(); p!=times_f3.end(); ++p) {
        std::cout << "\t" << *p << std::endl;
    }
    
    // f4 = x^2
    std::vector<double> times_f4;
    //hard coded
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate_f4(a, b, bins);}
    t.stop();
    times_f4.push_back(t.duration()/loops);
    //function pointer
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f4);}
    t.stop();
    times_f4.push_back(t.duration()/loops);
    //function obj
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f4_o);}
    t.stop();
    times_f4.push_back(t.duration());
    //virtual function
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f4_v);}
    t.stop();
    times_f4.push_back(t.duration());
    
    std::cout << "Execution times for f4 = x^2" << std::endl;
    for (std::vector<double>::iterator p=times_f4.begin(); p!=times_f4.end(); ++p) {
        std::cout << "\t" << *p << std::endl;
    }
    
    // f5 = sin(x)
    std::vector<double> times_f5;
    //hard coded
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate_f5(a, b, bins);}
    t.stop();
    times_f5.push_back(t.duration()/loops);
    //function pointer
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f5);}
    t.stop();
    times_f5.push_back(t.duration()/loops);
    //function obj
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f5_o);}
    t.stop();
    times_f5.push_back(t.duration());
    //virtual function
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f5_v);}
    t.stop();
    times_f5.push_back(t.duration());
    
    std::cout << "Execution times for f5 = sin(x)" << std::endl;
    for (std::vector<double>::iterator p=times_f5.begin(); p!=times_f5.end(); ++p) {
        std::cout << "\t" << *p << std::endl;
    }
    
    // f6 = sin(5*x)
    std::vector<double> times_f6;
    //hard coded
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate_f6(a, b, bins);}
    t.stop();
    times_f6.push_back(t.duration()/loops);
    //function pointer
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f6);}
    t.stop();
    times_f6.push_back(t.duration()/loops);
    //function obj
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f6_o);}
    t.stop();
    times_f6.push_back(t.duration());
    //virtual function
    t.start();
    for(size_t k = 0; k < loops; ++k)
    {   integrate(a, b, bins, f6_v);}
    t.stop();
    times_f6.push_back(t.duration());
    
    std::cout << "Execution times for f6 = 5*x" << std::endl;
    for (std::vector<double>::iterator p=times_f6.begin(); p!=times_f6.end(); ++p) {
        std::cout << "\t" << *p << std::endl;
    }
    return 0;
}
