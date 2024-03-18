#include "utils.hpp"

unsigned int adder(unsigned int a, unsigned int b)
{
	unsigned int cin;
	while (b != 0)
	{
		cin = a & b;
		a = a ^ b;
		b = cin << 1;
	}
	return a;
}