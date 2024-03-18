#include "utils.hpp"

void makeAMaxAndBMin(unsigned int &a, unsigned int &b)
{
	if (a < b)
	{
		unsigned int tmp = a;
		a = b;
		b = tmp;
	}
}

// works basicaly the same as a multiplication in base 10
unsigned int multiplier(unsigned int a, unsigned int b)
{
	makeAMaxAndBMin(a, b); // used to reduce the number of iterations in the loop and therefore the time complexity
	unsigned int response = 0;
	while (b != 0)
	{
		if (b & 1)
			response = adder(response, a);
		a = a << 1;
		b = b >> 1;
	}
	return response;
}

int main()
{
	std::cout << multiplier(0, 0) << std::endl;
	std::cout << multiplier(0, 5) << std::endl;
	std::cout << multiplier(5, 1) << std::endl;
	std::cout << multiplier(3, 5) << std::endl;
	std::cout << multiplier(37, 12) << std::endl;
	std::cout << multiplier(379, 1202) << std::endl;
	return 0;
}
