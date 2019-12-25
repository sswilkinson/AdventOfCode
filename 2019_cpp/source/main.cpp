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
	auto processedMemory = IntcodeComputer::Process( { 1,9,10,3,2,3,11,0,99,30,40,50 } );
	auto expectedMemory = std::vector<int>{ 3500,9,10,70,2,3,11,0,99,30,40,50 };
	if (!VectorsAreEqual(processedMemory, expectedMemory))  return 2;

	processedMemory = IntcodeComputer::Process({ 1,0,0,0,99 });
	expectedMemory = { 2,0,0,0,99 };
	if (!VectorsAreEqual(processedMemory, expectedMemory))  return 2;

	processedMemory = IntcodeComputer::Process({ 2,3,0,3,99 });
	expectedMemory = { 2,3,0,6,99 };
	if (!VectorsAreEqual(processedMemory, expectedMemory))  return 2;

	processedMemory = IntcodeComputer::Process({ 2,4,4,5,99,0 });
	expectedMemory = { 2,4,4,5,99,9801 };
	if (!VectorsAreEqual(processedMemory, expectedMemory))  return 2;

	processedMemory = IntcodeComputer::Process({ 1,1,1,4,99,5,6,0,99 });
	expectedMemory = { 30,1,1,4,2,5,6,0,99 };
	if (!VectorsAreEqual(processedMemory, expectedMemory))  return 2;

	processedMemory = Day2::input;
	processedMemory[1] = 12;  // Changes prompted by the puzzle's instructions
	processedMemory[2] = 2;
	processedMemory = IntcodeComputer::Process(processedMemory);
	expectedMemory = { 3267740,12,2,2,1,1,2,3,1,3,4,3,1,5,0,3,2,1,10,48,1,19,5,49,1,6,23,51,1,27,5,52,2,
		31,10,208,2,35,6,416,1,39,5,417,2,43,9,1251,1,47,6,1253,1,13,51,1258,2,9,55,3774,
		1,59,13,3779,1,6,63,3781,2,67,10,15124,1,9,71,15127,2,75,6,30254,1,79,5,30255,
		1,83,5,30256,2,9,87,90768,2,9,91,272304,1,95,10,272308,1,9,99,272311,2,103,6,
		544622,2,9,107,1633866,1,111,5,1633867,2,6,115,3267734,1,5,119,3267735,1,123,2,
		3267737,1,127,9,0,99,2,0,14,0
	};  // Part 1 solution (vector2[0])
	if (!VectorsAreEqual(processedMemory, expectedMemory))  return 2;

	//for (auto noun = 0; noun < 100; ++noun)
	//{
	//	for (auto verb = 0; verb < 100; ++verb)
	//	{
	//		processedMemory = Day2::input;
	//		processedMemory[1] = noun;
	//		processedMemory[2] = verb;
	//		processedMemory = IntcodeComputer::Process(processedMemory);

	//		if (processedMemory[0] == 19690720)
	//		{
	//			return 100 * noun + verb;  // Part 2 solution
	//		}
	//	}
	//}

	return 0;
}

bool VectorsAreEqual(std::vector<int>& vector1, std::vector<int>& vector2)
{
	return std::equal(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());
}
