/*
 * Timer.cpp
 *
 *  Created on: 2 nov. 2016
 *      Author: Barth
 */
#include "Timer.hpp"
#include <chrono>

void Timer::start(){
	start_ = std::chrono::high_resolution_clock::now();
}

void Timer::stop(){
	stop_ = std::chrono::high_resolution_clock::now();
}

Timer::return_type const Timer::duration(){
    return static_cast<std::chrono::duration<Timer::return_type> >(stop_-start_).count();
}
