/*
 * Generator.cpp
 *
 *  Created on: 2 nov. 2016
 *      Author: Barth
 */

#include "Generator.hpp"
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

Generator::var_type Generator::max() const
{
	return m_;
}

void Generator::set_m(var_type m)
{
	m_=m;
}
void Generator::set_a(var_type a)
{
	a_=a;
}
void Generator::set_c(var_type c)
{
	c_=c;
}
