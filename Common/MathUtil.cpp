#include "MathUtil.h"
#include "IOUtil.h"

int MathUtil::geneRandomInt(int from, int to) {
    _EARLY_RETURN(from > to, "generate random int error: from > to.", INT_MIN);

	std::random_device RandomGenerator;
	std::uniform_int_distribution<int> UDistribution(from, to);
	return UDistribution(RandomGenerator);
}

float MathUtil::geneRandomReal(float from, float to) {
	_EARLY_RETURN(from > to, "generate random int error: from > to.", INT_MIN);

	std::random_device RandomGenerator;
	std::uniform_real_distribution<float> UDistribution(from, to);
	return UDistribution(RandomGenerator);
}

