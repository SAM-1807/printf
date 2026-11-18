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

	return (0);
}
