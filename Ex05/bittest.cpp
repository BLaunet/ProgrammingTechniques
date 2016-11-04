/* Programming Techniques for Scientific Simulations, HS 2016
 * Exercise 4.3
 */
#include <iostream>
using namespace std;

int main(){
    bitset<32> bits;
    bits[0] = true;
    bits[1] = true;
    bits[2] = true;
    bits[3] = true;
    cout << (bits<<(32-4-1)) <<endl;
    cout << bits.count() << endl;
    return 0;
}