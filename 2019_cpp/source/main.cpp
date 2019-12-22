#include "fuel_counter_upper/FuelCounterUpper.h"

#include "input/Day1.h"

int main()
{
	// Day 1
	if (FuelCounterUpper::CalculateRequiredFuelForMass(12) != 2)                      return 1;
	if (FuelCounterUpper::CalculateRequiredFuelForMass(14) != 2)                      return 1;
	if (FuelCounterUpper::CalculateRequiredFuelForMass(1969) != 654)                  return 1;
	if (FuelCounterUpper::CalculateRequiredFuelForMass(100756) != 33583)              return 1;
	if (FuelCounterUpper::CalculateRequiredFuelForMass(Day1::input) != 3332538)       return 1;  // Part 1 answer
	if (FuelCounterUpper::CalculateRequiredFuelForMass(5) != 0)                       return 1;  // Check for negative fuel
	if (FuelCounterUpper::CalculateTotalRequiredFuelForMass(14) != 2)                 return 1;
	if (FuelCounterUpper::CalculateTotalRequiredFuelForMass(1969) != 966)             return 1;
	if (FuelCounterUpper::CalculateTotalRequiredFuelForMass(100756) != 50346)         return 1;
	if (FuelCounterUpper::CalculateTotalRequiredFuelForMass(Day1::input) != 4995942)  return 1;  // Part 2 answer

	return 0;
}
