#ifndef TIMER_H
#define TIMER_H

#include <windows.h>

class Timer {
private:
	double PCFreq = 0.0;
	__int64 TimerStart = 0;

public:
	Timer();
	~Timer();

	void startTimer();
	double getTimer();
};

#endif
