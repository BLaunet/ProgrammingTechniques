/* Programming Techniques for Scientific Simulations, HS 2016
 * Exercise 4.1
 */

#include <iostream>

enum Z2 { Plus, Minus };

template<class T>
T identity_element() { return T(1); }

template<>
Z2 identity_element<Z2>() { return Plus; }

Z2 operator*(const Z2 a, const Z2 b)
{
    if (a==b)
    	return Plus;
    return Minus;
}

std::ostream& operator<<(std::ostream& os, const Z2 a)
{
    if(a == Plus)
    	os << "Plus";
    else
    	os << "Minus";
    return os;
}

template<class T>
T operator*(const T a, const Z2 b)
{
	if (b == Plus)
		return a;
	return -a;
}

template<class T>
T operator*(const Z2 b, const T a)
{
	if (b == Plus)
		return a;
	return -a;
}

template<class T>
T mypow(T a, const unsigned int n)
{
//	T prod = identity_element(); ==> why this doesn't work ?
	T prod = identity_element<T>();
	for (unsigned int i = 0; i < n; i++) {
		prod = prod*a;
	}
	return prod;

}

int main()
{
    // some testing: feel free to add your own!
    std::cout << Plus*Minus << std::endl;
    std::cout << Plus*-1*Minus << std::endl;
    std::cout << (1.+3.)*mypow(Minus,6) << std::endl;
    for (unsigned i=0; i<7; i++)
        std::cout << "Plus^" << i << " = " << mypow(Plus,i) << std::endl;
    for (unsigned i=0; i<7; i++)
        std::cout << "Minus^" << i << " = " << mypow(Minus,i) << std::endl;
    for (unsigned i=0; i<7; i++)
        std::cout << "2^" << i << " = " << mypow(2.0,i) << std::endl;
    return 0;
}
