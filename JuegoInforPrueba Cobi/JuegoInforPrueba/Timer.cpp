#include "glut.h"
#include "Timer.h"
#include <math.h>


Timer::Timer() {
	interval = 0;
	timebase = 0;
	elapsedTime = 0;
	startTime = 0;
	parado = false;
}

bool Timer::isTriger() {
	if (parado) {
		return false;
	}
	time_ = glutGet(GLUT_ELAPSED_TIME);

	elapsedTime = time_ - timebase;

	if (elapsedTime > interval) {
		timebase = time_;
		return true;
	}
	else return false;
}

void Timer::reset() {
	timebase = glutGet(GLUT_ELAPSED_TIME);
}

int Timer::getTimeS() {
	if (parado)
		return (timebase / 1000) % 60;
	return ((glutGet(GLUT_ELAPSED_TIME) - timebase) / 1000) % 60;
}

int Timer::getTimeM() {
	if (parado)
		return (timebase / 1000) / 60;
	return floor(((glutGet(GLUT_ELAPSED_TIME) - timebase) / 1000) / 60);
}

