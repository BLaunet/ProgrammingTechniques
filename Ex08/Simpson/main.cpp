#include <iostream>
#include "simpson.hpp"
#include "benchmark.hpp"

int main() {
    f1_obj f1_obj_func;
    double a = 0;
    double b = 1;
    unsigned bins = 10;
    std::cout << integrate(a, b, bins, f1_obj_func) << std::endl;
    return 0;
}
