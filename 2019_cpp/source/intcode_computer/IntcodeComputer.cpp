#include "intcode_computer/IntcodeComputer.h"

std::vector<int> IntcodeComputer::FAILED_OUTPUT_MEMORY = {};

std::vector<int> IntcodeComputer::Process(const std::vector<int>& inputMemory)
{
	if (inputMemory.size() == 0)
	{
		return FAILED_OUTPUT_MEMORY;
	}

	auto outputMemory = inputMemory;
	int currentIndex = 0;
	const int numberOfElements = outputMemory.size();
	bool reachedStopInstruction = false;
	bool failedInstruction = false;

	do
	{
		const int instruction = outputMemory[currentIndex];

		if (instruction == Instructions::STOP)
		{
			reachedStopInstruction = true;
			break;
		}

		if (currentIndex + 3 >= numberOfElements)
		{
			return FAILED_OUTPUT_MEMORY;  // Not enough input to perform the below instructions
		}

		if (instruction == Instructions::ADD)
		{
			failedInstruction = !Add(outputMemory, currentIndex + 1);
		}
		else if (instruction == Instructions::MULTIPLY)
		{
			failedInstruction = !Multiply(outputMemory, currentIndex + 1);
		}
		else
		{
			return FAILED_OUTPUT_MEMORY;  // Bad instruction
		}

		if (failedInstruction)
		{
			return FAILED_OUTPUT_MEMORY;
		}

		currentIndex += 4;

	} while (currentIndex < numberOfElements);

	if (!reachedStopInstruction)
	{
		return FAILED_OUTPUT_MEMORY;
	}

	return outputMemory;
}

bool IntcodeComputer::Add(std::vector<int>& memory, unsigned int index)
{
	const int inputIndex1 = memory[index];
	const int inputIndex2 = memory[index + 1];
	const int outputIndex = memory[index + 2];
	const int numberOfElements = memory.size();

	if (inputIndex1 >= numberOfElements || inputIndex2 >= numberOfElements || outputIndex >= numberOfElements)
	{
		return false;
	}

	const int input1 = memory[inputIndex1];
	const int input2 = memory[inputIndex2];
	memory[outputIndex] = input1 + input2;

	return true;
}

bool IntcodeComputer::Multiply(std::vector<int>& memory, unsigned int index)
{
	const int inputIndex1 = memory[index];
	const int inputIndex2 = memory[index + 1];
	const int outputIndex = memory[index + 2];
	const int numberOfElements = memory.size();

	if (inputIndex1 >= numberOfElements || inputIndex2 >= numberOfElements || outputIndex >= numberOfElements)
	{
		return false;
	}

	const int input1 = memory[inputIndex1];
	const int input2 = memory[inputIndex2];
	memory[outputIndex] = input1 * input2;

	return true;
}
