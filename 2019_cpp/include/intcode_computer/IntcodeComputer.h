#pragma once

#include <vector>

class IntcodeComputer
{
public:

	enum Instructions { ADD = 1, MULTIPLY = 2, STOP = 99 };
	static std::vector<int> FAILED_OUTPUT_MEMORY;

	static std::vector<int> Process(const std::vector<int>& inputMemory);


private:

	static bool Add(std::vector<int>& memory, unsigned int startAddress);
	static bool Multiply(std::vector<int>& memory, unsigned int startAddress);
};
