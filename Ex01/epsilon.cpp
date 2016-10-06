#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
int main()
{
    double eps = 1;
    while (eps/2 + 1 != 1)
    {
        eps/=2;
    }
    cout << "Result from our function : " << eps << endl;
    cout << "Result from the limits function : " << std::numeric_limits<double>::epsilon() << endl;
    return 0 ;
}