#include <iostream>
#include <cmath>
#include <limits>

#include "epsilon.hpp"
using namespace std;

int main()
{
    cout << "Float epsilon : " << epsilon<float>() << endl;
    cout << "Result from the limits function : " << std::numeric_limits<float>::epsilon() << endl;

    cout << "Double epsilon : " << epsilon<double>() << endl;
    cout << "Result from the limits function : " << std::numeric_limits<double>::epsilon() << endl;

}