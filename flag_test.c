#include "main.h"
#include <stdio.h>

int main(void)
{
	_printf("Plus: [%+d]\n", 25);
	_printf("Space: [% d]\n", 25);
	_printf("Negative: [%+d]\n", -25);
	_printf("Hex: [%#x]\n", 42);
	_printf("HEX: [%#X]\n", 42);
	_printf("Octal: [%#o]\n", 10);
	_printf("Zero hex: [%#x]\n", 0);
	_printf("Combined: [%+#x]\n", 42);
	_printf("Zero padding: [%05d]\n", 42);
	_printf("Negative zero padding: [%06d]\n", -42);
	_printf("Zero hex padding: [%#08x]\n", 42);
	_printf("Combined flags: [%+08d]\n", 42);
	_printf("Zero flag with precision: [%.5d]\n", 42);
	_printf("Zero flag and precision: [%08.5d]\n", 42);
	_printf("Left integer: [%-8d]\n", 42);
	_printf("Left negative: [%-8d]\n", -42);
	_printf("Left string: [%-8s]\n", "Sam");
	_printf("Left character: [%-8c]\n", 'A');
	_printf("Left hexadecimal: [%-8x]\n", 42);
	_printf("Left overrides zero: [%-08d]\n", 42);
	_printf("Left integer precision: [%-8.5d]\n", 42);
	_printf("Left string precision: [%-8.3s]\n", "Samuel");

	return (0);
}
