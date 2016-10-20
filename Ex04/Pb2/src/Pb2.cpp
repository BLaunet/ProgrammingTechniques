#include <iostream>
#include <cmath>
#include "simpson.hpp"
using namespace std;

class exp_lambda {
public:
    typedef double result_type;
    typedef double arg_type;
    // Default constructor
    exp_lambda(const arg_type lambda=1.0): lambda_(lambda){}
    //Operators overload
    inline result_type operator()(arg_type x) const
    			{return exp(lambda_*x);}
private:
    arg_type lambda_;
};
int main() {
	const double a(0);
	const double b(1);
	const int bins(10);
	const double lambda(0);
	const exp_lambda f(lambda);
	cout << integrate(a, b, bins, f) << endl;
	return 0;
}
