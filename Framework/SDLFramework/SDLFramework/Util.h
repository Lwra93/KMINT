#pragma once
#include <cstdlib>

class Util
{
public:
	Util();
	static double randomDouble(double fMin, double fMax);
	static int randomInt(int low, int high);
	static double RandFloat() { return ((rand()) / (RAND_MAX + 1.0)); }
	static double RandomClamped() { return RandFloat() - RandFloat(); }
	~Util();
};

