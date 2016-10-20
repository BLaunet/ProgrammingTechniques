#include <iostream>
#include <cmath>
#include "simpson.hpp"
using namespace std;

int main()
{
    int N = 100;
    double a = 0;
    double b = M_PI;
    cout.precision(15);
    cout << integrate(a, b, N, std::sin) << endl;
    return 0;
}

