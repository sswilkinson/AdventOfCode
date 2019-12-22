#include "fuel_counter_upper/FuelCounterUpper.h"

unsigned int FuelCounterUpper::CalculateRequiredFuelForMass(const unsigned int mass)
{
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
