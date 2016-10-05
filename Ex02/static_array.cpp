#include <iostream>
using namespace std;

int main()
{
    int n;
#ifndef NMAX
    int NMAX = 10;
#endif
    double static_array[NMAX];
    double sum = 0;
    
    cout << "Enter the number of values you want to input" << endl;
    cin >> n;
    // We could do verifications on n (is it a number ? is it less than 10 ?) but I think it's not the purpose here
    
    for(int i = 0; i < n; i++)
    {
        cout << "[" << i << "] = ";
        cin >> static_array[i];
        sum += static_array[i];
    }
    
    cout << "[";
    for(int i = n - 1; i >= 0; i--)
    {
        static_array[i] /= sum;
        if(i != 0)
            cout << static_array[i] << ", ";
        else
            cout << static_array[i];
    }
    cout << "]" << endl;
    return 0;
}

