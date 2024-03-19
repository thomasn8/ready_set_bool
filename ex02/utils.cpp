#include "utils.hpp"

std::string padNumber(size_t numberToBePadded, size_t len)
{
	size_t diff = len - std::to_string(numberToBePadded).length();
	if (diff <= 0)
		return std::to_string(numberToBePadded);
	return std::string(diff, '0') + std::to_string(numberToBePadded);
}

std::string getOperationBar(size_t length)
{
	return std::string(length, '-');
}

void printBlockMirror(size_t *block, size_t blockLength)
{
	size_t maxLen = std::to_string(decimalToBinary(block[blockLength - 1])).length();
	std::cout << "Mirroring block values in binary:" << std::endl;
	for (size_t i = 0; i < blockLength; i++)
	{
		if (i == blockLength / 2)
			std::cout << getOperationBar(maxLen) << std::endl;
		std::cout << padNumber(decimalToBinary(block[i]), maxLen) << std::endl;
	}
}

void printBlockValues(size_t *block, size_t blockLength)
{
	std::cout << "block values in decimal:" << std::endl;
	for (size_t i = 0; i < blockLength; i++)
		std::cout << block[i] << " ";

	std::cout << std::endl;

	std::cout << "Block values in binary:" << std::endl;
	for (size_t i = 0; i < blockLength; i++)
		std::cout << decimalToBinary(block[i]) << " ";
}

void printSymmetricalAdditionDetails(size_t e, size_t n, size_t indexMirroredNumber, size_t *block)
{
	std::cout << "Index du nombre-miroir pour {" << n << "}: " << indexMirroredNumber << std::endl;
	std::cout << "Nombre correspondant à cet index: " << block[indexMirroredNumber] << " (" << decimalToBinary(block[indexMirroredNumber]) << ")" << std::endl;
	std::cout << "Valeur constante à ajouter: " << myPow(2, e + 1) << " (" << decimalToBinary(myPow(2, e + 1)) << ") " << std::endl;
	std::cout << "Résultat: " << block[indexMirroredNumber] + myPow(2, e + 1) << " (" << decimalToBinary(block[indexMirroredNumber] + myPow(2, e + 1)) << ")" << std::endl
						<< std::endl;
}

size_t myPow(size_t base, size_t exponent)
{
	size_t result = 1;
	for (size_t i = 0; i < exponent; ++i)
		result *= base;
	return result;
}

size_t decimalToBinary(size_t n)
{
	size_t binary = 0, remainder, i = 1;
	while (n != 0)
	{
		remainder = n % 2;
		n /= 2;
		binary += remainder * i;
		i *= 10;
	}
	return binary;
}