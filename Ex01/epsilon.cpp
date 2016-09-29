#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
int main()
{
    double max = 1;
    double min = 0;
    double mid = 0.5;
    double newMid = mid;
    double limit = 8e-15;
    
    cout.precision(50);
    
    while (true)
    {
        if(mid+1 == 1)
            min = mid;
        else
            max = mid;
        
        newMid = (max+min)/2;
        if(abs(max - min) < limit)
            break;
        mid = newMid;
    }
    cout << max/2 << endl;
    cout << std::numeric_limits<double>::epsilon();
    return 0 ;
}