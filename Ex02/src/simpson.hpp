#ifndef SIMPSON_HPP
#define SIMPSON_HPP

double integrate(double a, double b, int bins, double f(double x));
#endif

/*
PRECONDITION : 
 - a and b convertible to double
 - bins > 0
 
POSTCONDITION :
 - Returns the integration of function f between a and b using the Simpson's method
 
*/
