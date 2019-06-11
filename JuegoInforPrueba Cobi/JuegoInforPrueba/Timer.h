#pragma once
#include "glut.h"

class Timer
{
private:
	float timebase;//int
	int interval;
	int time_;
	int elapsedTime;
	int startTime;
	bool parado;

public:
	Timer();
	void reset();
	int getTimeS();
	int getTimeM();
	bool isTriger();
	void stop() { parado = true; }
	void start() { parado = false; timebase = glutGet(GLUT_ELAPSED_TIME); }
	void setInterval(int inter) { this->interval = inter; }
	int getElapsedTime() { return elapsedTime; }
};

