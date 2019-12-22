#pragma once

#include <vector>

class FCU
{
public:
	static unsigned int CalculateRequiredFuelForMass(unsigned int mass);
	static unsigned int CalculateRequiredFuelForMass(const std::vector<unsigned int>& masses);
};
