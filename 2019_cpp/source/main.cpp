#include "fuel_counter_upper/FuelCounterUpper.h"

int main()
{
	// Day 1
	if (FCU::CalculateRequiredFuelForMass(12) != 2)          return 1;
	if (FCU::CalculateRequiredFuelForMass(14) != 2)          return 2;
	if (FCU::CalculateRequiredFuelForMass(1969) != 654)      return 3;
	if (FCU::CalculateRequiredFuelForMass(100756) != 33583)  return 4;

    return 0;
}
