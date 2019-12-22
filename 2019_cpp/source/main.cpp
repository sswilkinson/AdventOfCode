#include "fuel_counter_upper/FuelCounterUpper.h"

#include "input/Day1.h"

int main()
{
	// Day 1
	if (FCU::CalculateRequiredFuelForMass(12) != 2)                 return 1;
	if (FCU::CalculateRequiredFuelForMass(14) != 2)                 return 1;
	if (FCU::CalculateRequiredFuelForMass(1969) != 654)             return 1;
	if (FCU::CalculateRequiredFuelForMass(100756) != 33583)         return 1;
	if (FCU::CalculateRequiredFuelForMass(Day1::input) != 3332538)  return 1;

	return 0;
}
