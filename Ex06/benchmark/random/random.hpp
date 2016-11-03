/*
 * Generator.hpp
 *
 *  Created on: 2 nov. 2016
 *      Author: Barth
 */

#ifndef RANDOM_HPP_
#define RANDOM_HPP_
#include <cmath>

class Generator {
public:
	typedef unsigned int var_type;
    
	var_type generate();
    var_type max() const {return m_;};
	Generator(var_type);
private:
	static var_type m_;
	static var_type a_;
	static var_type c_;
	var_type x_;

};

#endif /* RANDOM_HPP_ */
