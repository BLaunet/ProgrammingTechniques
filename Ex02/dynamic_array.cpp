#include <iostream>
using namespace std;

int main()
{
    int n;
    double *dynamic_array = new double[n];
    double sum = 0;
    
    cout << "Enter the number of values you want to input" << endl;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cout << "[" << i << "] = ";
        cin >> dynamic_array[i];
        sum += dynamic_array[i];
    }
    
    cout << "[";
    for(int i = n - 1; i >= 0; i--)
    {
        dynamic_array[i] /= sum;
        if(i != 0)
            cout << dynamic_array[i] << ", ";
        else
            cout << dynamic_array[i];
    }
    cout << "]" << endl;
    return 0;
}
