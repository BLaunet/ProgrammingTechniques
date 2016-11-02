/*
 * Generator.hpp
 *
 *  Created on: 2 nov. 2016
 *      Author: Barth
 */

#ifndef GENERATOR_HPP_
#define GENERATOR_HPP_
#include <cmath>

class Generator {
public:
	typedef unsigned int var_type;
	var_type generate();
	var_type max() const;
	Generator(var_type);
	static void set_m(var_type);
	static void set_a(var_type);
	static void set_c(var_type);
private:
	static var_type m_;
	static var_type a_;
	static var_type c_;
	var_type x_;

};

#endif /* GENERATOR_HPP_ */
