#pragma once
#include <chrono>

class FrameTimer
{
	std::chrono::steady_clock::time_point timer;

public:
	FrameTimer();
	float Mark();
};