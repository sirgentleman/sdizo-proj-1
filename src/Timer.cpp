#include "Timer.h"
#include <windows.h>
#include <iostream>

Timer::Timer() {

}

Timer::~Timer() {

}

void Timer::startTimer() {
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		std::cout << "Error!";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	TimerStart = li.QuadPart;
}

double Timer::getTimer() {
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - TimerStart) / PCFreq;
}