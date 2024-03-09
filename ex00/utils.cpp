#include "utils.hpp"

std::string padNumber(unsigned int numberToBePadded, int len)
{
	int diff = len - std::to_string(numberToBePadded).length();
	if (diff <= 0)
		return std::to_string(numberToBePadded);
	return std::string(diff, '0') + std::to_string(numberToBePadded);
}

std::string getOperationBar(unsigned int length)
{
	return std::string(length, '-');
}

void printDetailsBefore(unsigned int a, unsigned int b)
{
	std::cout
			<< a << " (" << decimalToBinary(a) << ")"
			<< " + " << b << " (" << decimalToBinary(b) << ")"
			<< std::endl
			<< std::endl;
}

void printResult(unsigned int result)
{
	std::cout
			<< result << " (" << decimalToBinary(result) << ")"
			<< std::endl;
}

void printDetailsCalculation(unsigned int a, unsigned int b)
{
	int aLen = std::to_string(decimalToBinary(a)).length();
	int bLen = std::to_string(decimalToBinary(b)).length();
	int cinLen = std::to_string(decimalToBinary((a & b) << 1)).length();
	int maxLen = std::max(aLen, bLen);
	maxLen = std::max(maxLen, cinLen);

	std::cout
			<< padNumber(decimalToBinary(a), maxLen)
			<< std::endl
			<< padNumber(decimalToBinary(b), maxLen)
			<< std::endl
			<< getOperationBar(maxLen)
			<< std::endl
			<< padNumber(decimalToBinary(a ^ b), maxLen) << " ^ (addition sans la retenue XOR)" << std::endl
			<< padNumber(decimalToBinary(a & b), maxLen) << " & (calcule de la retenue AND)" << std::endl
			<< padNumber(decimalToBinary((a & b) << 1), maxLen) << " << 1 (shift de la retenue)" << std::endl
			<< std::endl;
}

unsigned int decimalToBinary(unsigned int n) {
	unsigned int binary = 0, remainder, i = 1;
	while (n != 0) {
		remainder = n % 2;
		n /= 2;
		binary += remainder * i;
		i *= 10;
	}
	return binary;
}