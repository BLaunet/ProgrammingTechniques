/*
 * timer.h
 *
 *  Created on: 2 nov. 2016
 *      Author: Barth
 */

#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <chrono>

class Timer {
public:
	typedef double return_type;
	void start();
	void stop();
	return_type const duration();
private:
	std::chrono::time_point< std::chrono::high_resolution_clock > start_ , stop_;
};
#endif /* TIMER_HPP_ */
