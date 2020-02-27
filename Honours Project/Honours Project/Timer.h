/*
Name: Craig McCorrisken
Student ID: b00317267
I declare that the following code was produced by (NAME OF GROUP MEMBERS HERE) as a group assignment for the RTCD module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#pragma once

#include <ctime> //LowResTimer good for test not appropriate in games

class Timer
{
public:
	virtual ~Timer() {};
	virtual void startTimer() = 0;
	virtual double getTime() = 0;
	virtual void resetTimer() = 0;
};

class LowResTimer : public Timer
{
private:
	clock_t timer;
public:
	virtual ~LowResTimer() {}
	LowResTimer();
	void startTimer();
	double getTime();
	void resetTimer();
};