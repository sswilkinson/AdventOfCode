#pragma once

#include <vector>

class FuelCounterUpper
{
public:
	static unsigned int CalculateRequiredFuelForMass(const unsigned int mass);
	static unsigned int CalculateRequiredFuelForMass(const std::vector<unsigned int>& masses);
};
