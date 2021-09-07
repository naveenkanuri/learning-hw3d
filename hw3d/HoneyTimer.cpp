#include "HoneyTimer.h"

using namespace std::chrono;
HoneyTimer::HoneyTimer()
{
	last = steady_clock::now();
}

float HoneyTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float HoneyTimer::Peek() const
{
	return duration<float>( steady_clock::now() - last ).count();
}
