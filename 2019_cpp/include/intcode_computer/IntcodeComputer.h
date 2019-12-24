#pragma once

#include <vector>

class IntcodeComputer
{
public:

	enum Instructions { ADD = 1, MULTIPLY = 2, STOP = 99 };
	static std::vector<int> FAILED_OUTPUT;

	static std::vector<int> Process(const std::vector<int>& input);


private:

	static void Add(std::vector<int>& vector, unsigned int index);
	static void Multiply(std::vector<int>& vector, unsigned int index);
};
