#include "main.h"
#include <stdio.h>

int main(void)
{
	int our_count, expected_count;

	our_count = _printf("[%d]", 42);
	expected_count = printf("[%d]", 42);
	printf("\nCounts: %d / %d\n\n", our_count, expected_count);

	our_count = _printf("[%+8d]", 42);
	expected_count = printf("[%+8d]", 42);
	printf("\nCounts: %d / %d\n\n", our_count, expected_count);

	our_count = _printf("[%#8x]", 255);
	expected_count = printf("[%#8x]", 255);
	printf("\nCounts: %d / %d\n\n", our_count, expected_count);

	our_count = _printf("[% 8d]", 42);
	expected_count = printf("[% 8d]", 42);
	printf("\nCounts: %d / %d\n", our_count, expected_count);

	printf("[% .5d]\n", 42);
	_printf("[% .5d]\n", 42);

	printf("[%.5d]\n", 42);
	_printf("[%.5d]\n", 42);

	printf("[%.3d]\n", 12345);
	_printf("[%.3d]\n", 12345);

	printf("[%.0d]\n", 0);
	_printf("[%.0d]\n", 0);

	printf("[%.3s]\n", "Samuel");
	_printf("[%.3s]\n", "Samuel");

	printf("[%10.3s]\n", "Samuel");
	_printf("[%10.3s]\n", "Samuel");

	printf("[%.8s]\n", "Sam");
	_printf("[%.8s]\n", "Sam");

	return (0);
}
