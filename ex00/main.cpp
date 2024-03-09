#include "utils.hpp"

bool g_print_details = false;

unsigned int adder(unsigned int a, unsigned int b)
{
	if (g_print_details)
		printDetailsBefore(a, b);

	unsigned int cin;
	while (b != 0)
	{
		if (g_print_details)
			printDetailsCalculation(a, b);
		cin = a & b;
		a = a ^ b;
		b = cin << 1;
	}

	if (g_print_details)
		printResult(a);
	return a;
}

int main()
{
	// adder(0, 0);
	// adder(10, 10);
	adder(53, 14);
	// adder(123, 456);
	// adder(57324355, 11444444);
	return 0;
}
