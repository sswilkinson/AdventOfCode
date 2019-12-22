#include "fuel_counter_upper/FuelCounterUpper.h"

unsigned int FuelCounterUpper::CalculateRequiredFuelForMass(const unsigned int mass)
{
	if (mass < 6)  // Anything less than 6 results in a negative number, which should be treated as 0
	{
		return 0;
	}

	return (mass / 3) - 2;
}

unsigned int FuelCounterUpper::CalculateRequiredFuelForMass(const std::vector<unsigned int>& masses)
{
	unsigned int total = 0;

	for (auto mass : masses)
	{
		total += CalculateRequiredFuelForMass(mass);
	}
	return total;
}

unsigned int FuelCounterUpper::CalculateTotalRequiredFuelForMass(const unsigned int mass)
{
	unsigned int total = 0;
	return total;
}
