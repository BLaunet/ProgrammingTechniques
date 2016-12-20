#include <iostream>
#include <random>
#include "RandomGenerator.hpp"
#include <boost/random.hpp>

int main(int argc, const char * argv[]) {
    const double p = 1;
    RNG rng = RNG(p);
    std::random_device r;
    std::mt19937 gen(r());
    int i = 0;
    double sum = 0;
    double sumsquared = 0;
    while (i<1000000) {
        double x = rng(gen);
        sum+= x;
        sumsquared += pow(x,2);
        i++;
    }
    std::cout << "Mean = " << sum/(i+1) << std::endl;
    std::cout << "Std = " << sqrt(sumsquared/(i+1) - pow(sum/(i+1),2)) << std::endl;
    return 0;
}
