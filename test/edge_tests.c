
#include "main.h"
#include <stddef.h>

/**
 * main - tests edge cases for _printf
 *
 * Return: 0 on success
 */
int main(void)
{
	char long_string[1101];
	int i, result;

	/* Test 1: Empty string */
	_printf("TEST 1 - Empty string:\n");
	result = _printf("[%s]", "");
	_printf("\nReturn value: %d\n\n", result);

	/* Test 2: NULL string */
	_printf("TEST 2 - NULL string:\n");
	result = _printf("%s", (char *)NULL);
	_printf("\nReturn value: %d\n\n", result);

	/* Test 3: Zero values */
	_printf("TEST 3 - Zero values:\n");
	_printf("Signed: %d\n", 0);
	_printf("Unsigned: %u\n", 0U);
	_printf("Binary: %b\n", 0U);
	_printf("Octal: %o\n", 0U);
	_printf("Hex lowercase: %x\n", 0U);
	_printf("Hex uppercase: %X\n\n", 0U);

	/* Test 4: String longer than the buffer */
	_printf("TEST 4 - Long string (1100 characters):\n");

	for (i = 0; i < 1100; i++)
		long_string[i] = 'A';

	long_string[1100] = '\0';

	result = _printf("%s", long_string);
	_printf("\nLong string return value: %d\n\n", result);

	/* Test 5: Format string ending with % */
	_printf("TEST 5 - Trailing percent:\n");
	result = _printf("100%% complete%");
	_printf("\nReturn value: %d\n\n", result);

	/* Test 6: Unknown format specifier */
	_printf("TEST 6 - Unknown specifier:\n");
	result = _printf("Unknown: %q");
	_printf("\nReturn value: %d\n\n", result);

	/* Test 7: Ordinary characters only */
	_printf("TEST 7 - Ordinary characters:\n");
	result = _printf("Hello SAM, no format specifiers here.");
	_printf("\nReturn value: %d\n", result);

	return (0);
}

