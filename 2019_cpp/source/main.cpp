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
	if (FuelCounterUpper::CalculateRequiredFuelForMass(Day1::input) != 3332538)       return 1;  // Part 1 solution
	if (FuelCounterUpper::CalculateRequiredFuelForMass(5) != 0)                       return 1;  // Check for negative fuel
	if (FuelCounterUpper::CalculateTotalRequiredFuelForMass(14) != 2)                 return 1;
	if (FuelCounterUpper::CalculateTotalRequiredFuelForMass(1969) != 966)             return 1;
	if (FuelCounterUpper::CalculateTotalRequiredFuelForMass(100756) != 50346)         return 1;
	if (FuelCounterUpper::CalculateTotalRequiredFuelForMass(Day1::input) != 4995942)  return 1;  // Part 2 solution

	// Day 2
	auto vector1 = IntcodeComputer::Process( { 1,9,10,3,2,3,11,0,99,30,40,50 } );
	auto vector2 = std::vector<int>{ 3500,9,10,70,2,3,11,0,99,30,40,50 };
	if (!VectorsAreEqual(vector1, vector2))  return 2;

	vector1 = IntcodeComputer::Process({ 1,0,0,0,99 });
	vector2 = std::vector<int>{ 2,0,0,0,99 };
	if (!VectorsAreEqual(vector1, vector2))  return 2;

	vector1 = IntcodeComputer::Process({ 2,3,0,3,99 });
	vector2 = std::vector<int>{ 2,3,0,6,99 };
	if (!VectorsAreEqual(vector1, vector2))  return 2;

	vector1 = IntcodeComputer::Process({ 2,4,4,5,99,0 });
	vector2 = std::vector<int>{ 2,4,4,5,99,9801 };
	if (!VectorsAreEqual(vector1, vector2))  return 2;

	vector1 = IntcodeComputer::Process({ 1,1,1,4,99,5,6,0,99 });
	vector2 = std::vector<int>{ 30,1,1,4,2,5,6,0,99 };
	if (!VectorsAreEqual(vector1, vector2))  return 2;

	vector1 = Day2::input;
	vector1[1] = 12;  // Changes prompted by the puzzle's instructions
	vector1[2] = 2;
	vector1 = IntcodeComputer::Process(vector1);
	vector2 = std::vector<int>{ 3267740,12,2,2,1,1,2,3,1,3,4,3,1,5,0,3,2,1,10,48,1,19,5,49,1,6,23,51,1,27,5,52,2,
		31,10,208,2,35,6,416,1,39,5,417,2,43,9,1251,1,47,6,1253,1,13,51,1258,2,9,55,3774,
		1,59,13,3779,1,6,63,3781,2,67,10,15124,1,9,71,15127,2,75,6,30254,1,79,5,30255,
		1,83,5,30256,2,9,87,90768,2,9,91,272304,1,95,10,272308,1,9,99,272311,2,103,6,
		544622,2,9,107,1633866,1,111,5,1633867,2,6,115,3267734,1,5,119,3267735,1,123,2,
		3267737,1,127,9,0,99,2,0,14,0
	};  // Part 1 solution (vector2[0])
	if (!VectorsAreEqual(vector1, vector2))  return 2;

	return 0;
}

bool VectorsAreEqual(std::vector<int>& vector1, std::vector<int>& vector2)
{
	return std::equal(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());
}
