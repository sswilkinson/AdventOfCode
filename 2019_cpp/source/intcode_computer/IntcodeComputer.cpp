#include "intcode_computer/IntcodeComputer.h"

std::vector<int> IntcodeComputer::FAILED_OUTPUT_MEMORY = {};

std::vector<int> IntcodeComputer::Process(const std::vector<int>& inputMemory)
{
	if (inputMemory.size() == 0)
	{
		return FAILED_OUTPUT_MEMORY;
	}

	auto outputMemory = inputMemory;
	int currentAddress = 0;
	const int memorySize = outputMemory.size();
	bool reachedStopInstruction = false;
	bool failedInstruction = false;

	do
	{
		const int opcode = outputMemory[currentAddress];

		if (opcode == Instructions::STOP)
		{
			reachedStopInstruction = true;
			break;
		}

		if (currentAddress + 3 >= memorySize)
		{
			return FAILED_OUTPUT_MEMORY;  // Not enough input to perform the below instructions
		}

		if (opcode == Instructions::ADD)
		{
			failedInstruction = !Add(outputMemory, currentAddress + 1);
		}
		else if (opcode == Instructions::MULTIPLY)
		{
			failedInstruction = !Multiply(outputMemory, currentAddress + 1);
		}
		else
		{
			return FAILED_OUTPUT_MEMORY;  // Bad opcode
		}

		if (failedInstruction)
		{
			return FAILED_OUTPUT_MEMORY;
		}

		currentAddress += 4;

	} while (currentAddress < memorySize);

	if (!reachedStopInstruction)
	{
		return FAILED_OUTPUT_MEMORY;
	}

	return outputMemory;
}

bool IntcodeComputer::Add(std::vector<int>& memory, unsigned int startAddress)
{
	const int inputAddress1 = memory[startAddress];
	const int inputAddress2 = memory[startAddress + 1];
	const int outputAddress = memory[startAddress + 2];
	const int numberOfElements = memory.size();

	if (inputAddress1 >= numberOfElements || inputAddress2 >= numberOfElements || outputAddress >= numberOfElements)
	{
		return false;
	}

	const int input1 = memory[inputAddress1];
	const int input2 = memory[inputAddress2];
	memory[outputAddress] = input1 + input2;

	return true;
}

bool IntcodeComputer::Multiply(std::vector<int>& memory, unsigned int startAddress)
{
	const int inputAddress1 = memory[startAddress];
	const int inputAddress2 = memory[startAddress + 1];
	const int outputAddress = memory[startAddress + 2];
	const int numberOfElements = memory.size();

	if (inputAddress1 >= numberOfElements || inputAddress2 >= numberOfElements || outputAddress >= numberOfElements)
	{
		return false;
	}

	const int input1 = memory[inputAddress1];
	const int input2 = memory[inputAddress2];
	memory[outputAddress] = input1 * input2;

	return true;
}
