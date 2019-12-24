#include <algorithm>

#include "fuel_counter_upper/FuelCounterUpper.h"
#include "intcode_computer/IntcodeComputer.h"

#include "input/Day1.h"
#include "input/Day2.h"


// Utility Function
bool VectorsAreEqual(std::vector<int>& vector1, std::vector<int>& vector2);


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

	// Day 2
	auto vector1 = IntcodeComputer::Process( { 1,9,10,3,2,3,11,0,99,30,40,50 } );
	auto vector2 = std::vector<int>{ 3500,9,10,70,2,3,11,0,99,30,40,50 };
	if (!VectorsAreEqual(vector1, vector2))  return 2;

	vector1 = IntcodeComputer::Process({ 1,0,0,0,99 });
	vector2 = std::vector<int>{ 2,0,0,0,99 };
	if (!VectorsAreEqual(vector1, vector2))  return 3;

	vector1 = IntcodeComputer::Process({ 2,3,0,3,99 });
	vector2 = std::vector<int>{ 2,3,0,6,99 };
	if (!VectorsAreEqual(vector1, vector2))  return 4;

	vector1 = IntcodeComputer::Process({ 2,4,4,5,99,0 });
	vector2 = std::vector<int>{ 2,4,4,5,99,9801 };
	if (!VectorsAreEqual(vector1, vector2))  return 5;

	vector1 = IntcodeComputer::Process({ 1,1,1,4,99,5,6,0,99 });
	vector2 = std::vector<int>{ 30,1,1,4,2,5,6,0,99 };
	if (!VectorsAreEqual(vector1, vector2))  return 6;

	return 0;
}

bool VectorsAreEqual(std::vector<int>& vector1, std::vector<int>& vector2)
{
	return std::equal(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());
}
