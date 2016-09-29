#include <iostream>
#include <cmath>
using namespace std;
double f(double x)
{
    //return x*(1-x);
    return sin(x);
}

int main()
{
    int N = 10;
    double a = 0;
    double b = M_PI;
    
    double step = (b-a)/N;
    double x = a;
    double integ = 0;
    
    for(int i=0; i < N; i++)
    {
        integ += step/6*(f(x) + 4*f(x + step/2) + f(x + step));
        x += step;
    }
    cout << integ << endl;
    return 0;
}

