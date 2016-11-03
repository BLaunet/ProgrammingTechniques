/*
 * random.cpp
 *
 *  Created on: 2 nov. 2016
 *      Author: Barth
 */

#include "random.hpp"
#include <cmath>
#include <iostream>

//Instantiation of static variables
Generator::var_type Generator::m_ = pow(2,31);
Generator::var_type Generator::a_ = 1664525;
Generator::var_type Generator::c_ = 1013904223;

Generator::Generator(Generator::var_type x0)
: x_(x0)
{
}

Generator::var_type Generator::generate()
{
	x_ = (a_*x_+c_) % m_;
	return x_ ;
}
