#ifndef SIMPSON_METHOD
#define SIMPSON_METHOD

double integrate(double a, double b, int bins, double f(double x));
#endif

//integrate calculates the inetgral of the function f with the Simpson's Method between a and b with bins intervals.
//Precondition : bins should be greater than 0
//Postcondition : ?
//Dependencies : none
