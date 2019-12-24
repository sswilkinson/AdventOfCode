#include "intcode_computer/IntcodeComputer.h"

std::vector<int> IntcodeComputer::FAILED_OUTPUT = {};

std::vector<int> IntcodeComputer::Process(const std::vector<int>& input)
{
	if (input.size() == 0)
	{
		return FAILED_OUTPUT;
	}

	auto output = input;
	int currentIndex = 0;
	int numberOfElements = output.size();
	bool reachedStopInstruction = false;
	bool failedInstruction = false;

	do
	{
		const int instruction = output[currentIndex];

		if (instruction == Instructions::STOP)
		{
			reachedStopInstruction = true;
			break;
		}

		if (currentIndex + 3 >= numberOfElements)
		{
			return FAILED_OUTPUT;  // Not enough input to perform the below instructions
		}

		if (instruction == Instructions::ADD)
		{
			failedInstruction = !Add(output, currentIndex + 1);
		}
		else if (instruction == Instructions::MULTIPLY)
		{
			failedInstruction = !Multiply(output, currentIndex + 1);
		}
		else
		{
			return FAILED_OUTPUT;  // Bad instruction
		}

		if (failedInstruction)
		{
			return FAILED_OUTPUT;
		}

		currentIndex += 4;

	} while (currentIndex < numberOfElements);

	if (!reachedStopInstruction)
	{
		return FAILED_OUTPUT;
	}

	return output;
}

bool IntcodeComputer::Add(std::vector<int>& vector, unsigned int index)
{
	return false;
}

bool IntcodeComputer::Multiply(std::vector<int>& vector, unsigned int index)
{
	return false;
}
