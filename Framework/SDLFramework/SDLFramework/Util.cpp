#include "Util.h"
#include <cstdlib>
#include <random>
#include <chrono>


Util::Util()
{
}

double Util::randomDouble(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

int Util::randomInt(int low, int high)
{
	std::default_random_engine generator;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	generator.seed(seed);

	std::uniform_int_distribution<int> distribution(low, high);

	return distribution(generator);
}

Util::~Util()
{
}
