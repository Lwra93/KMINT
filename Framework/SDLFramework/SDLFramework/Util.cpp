#include "Util.h"
#include <cstdlib>


Util::Util()
{
}

double Util::randomDouble(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

Util::~Util()
{
}
