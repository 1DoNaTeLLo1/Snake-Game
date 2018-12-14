#include "FrameTimer.h"

FrameTimer::FrameTimer()
{
	timer = std::chrono::steady_clock::now();
}

float FrameTimer::Mark()
{
	std::chrono::steady_clock::time_point old = timer;
	timer = std::chrono::steady_clock::now();
	std::chrono::duration<float> duration = timer - old;
	return duration.count();
}
