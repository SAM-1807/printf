#include "main.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("LONG SIGNED: %ld\n", LONG_MAX);
	_printf("LONG SIGNED: %ld\n", LONG_MAX);

	printf("LONG MIN: %ld\n", LONG_MIN);
	_printf("LONG MIN: %ld\n", LONG_MIN);

	printf("LONG UNSIGNED: %lu\n", ULONG_MAX);
	_printf("LONG UNSIGNED: %lu\n", ULONG_MAX);

	printf("SHORT SIGNED: %hd\n", (short)32767);
	_printf("SHORT SIGNED: %hd\n", (short)32767);

	printf("SHORT NEGATIVE: %hd\n", (short)-32768);
	_printf("SHORT NEGATIVE: %hd\n", (short)-32768);

	printf("SHORT UNSIGNED: %hu\n", (unsigned short)65535);
	_printf("SHORT UNSIGNED: %hu\n", (unsigned short)65535);

	printf("LONG OCTAL: %#lo\n", 42UL);
	_printf("LONG OCTAL: %#lo\n", 42UL);

	printf("LONG HEX: %#lx\n", 42UL);
	_printf("LONG HEX: %#lx\n", 42UL);

	printf("LONG HEX UPPER: %#lX\n", 42UL);
	_printf("LONG HEX UPPER: %#lX\n", 42UL);

	printf("SHORT HEX: %#hx\n", (unsigned short)255);
	_printf("SHORT HEX: %#hx\n", (unsigned short)255);

	return (0);
}

