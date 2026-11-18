#include <stdio.h>
#include "main.h"
#include <stddef.h>
#include <unistd.h>

int main(void)
{
	int number = 42;
	int *ptr = &number;
	int *null_ptr = NULL;
	char test[] = {127, '\0'};
	char boundary_test[258];
	int i;
	int count;
	count = _printf("%S", "A\nB");



	printf("NORMAL POINTER TEST\n");

	printf("Standard: ");
	fflush(stdout);
	printf("%p\n", (void *)ptr);
	fflush(stdout);

	printf("Our _printf: ");
	fflush(stdout);
	_printf("%p\n", (void *)ptr);

	printf("\nNULL POINTER TEST\n");

	printf("Standard: ");
	fflush(stdout);
	printf("%p\n", (void *)null_ptr);
	fflush(stdout);

	printf("Our _printf: ");
	fflush(stdout);
	_printf("%p\n", (void *)null_ptr);

	printf("\nRETURN COUNT TEST\n");

	count = _printf("%p", (void *)ptr);
	printf("\nReturn count: %d\n", count);


	for (i = 0; i < 257; i++)
		boundary_test[i] = '\n';

	boundary_test[257] = '\0';

	count = _printf("%S", boundary_test);

	_printf("\nBoundary count: %d\n", count);
	_printf("\nReturn count: %d\n", count);
	_printf("Name: %s\n", "SAM");
	_printf("Initial: %c\n", 'S');
	_printf("Progress: 100%%\n");
	_printf("%d\n", 19);
	_printf("%i\n", -250);
	_printf("%d\n", 0);
	_printf("%d\n", -2147483648);
	_printf("Binary of 5: %b\n", 5U);
	_printf("Binary of 10: %b\n", 10U);
	_printf("Binary of 25: %b\n", 25U);
	_printf("Binary of 0: %b\n", 0U);
	_printf("Unsigned zero: %u\n", 0U);
	_printf("Unsigned number: %u\n", 250U);
	_printf("Large unsigned: %u\n", 4294967295U);
	_printf("Octal of 25: %o\n", 25U);
	_printf("Octal of 64: %o\n", 64U);
	_printf("Octal of 0: %o\n", 0U);
	_printf("Hexadecimal of 10: %x\n", 10U);
	_printf("Hexadecimal of 25: %x\n", 25U);
	_printf("Hexadecimal of 255: %x\n", 255U);
	_printf("Hexadecimal of 0: %x\n", 0U);
	_printf("Hexadecimal uppercase: %X\n", 255U);
	_printf("Another test: %X\n", 4095U);
	_printf("Printable: %S\n", "Hello SAM");
	_printf("Newline: %S\n", "Line1\nLine2");
	_printf("Tab: %S\n", "Hello\tWorld");
	_printf("Control: %S\n", "\a\b");
	_printf("NULL: %S\n", (char *)NULL);
	_printf("DEL: %S\n", test);
	_printf("Custom: [%8d]\n", 42);
	_printf("Custom: [%3d]\n", 12345);
	_printf("Custom: [%8d]\n", -42);

	return (0);
}
