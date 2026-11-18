#include "main.h"
#include <unistd.h>
#include <limits.h>

/**
 * _print_number - stores a signed integer in the output buffer
 * @n: integer to print
 * @buffer: character buffer
 * @buffer_index: current buffer position
 * @plus: whether to print a plus sign
 * @space: whether to print a leading space
 *
 * Return: number of characters stored, or -1 on failure
 */

int _print_number(int n, int plus, int space, char *buffer, int *buffer_index)
{
	unsigned int num;
	int count = 0;
	int result;

	if (n < 0)
	{
		result = _buffer_char('-', buffer, buffer_index);
		if (result == -1)
			return (-1);

		count++;
		num = -(unsigned int)n;
	}
	else
	{
		if (plus || space)
		{
			result = _buffer_char(plus ? '+' : ' ',
					buffer, buffer_index);
			if (result == -1)
				return (-1);
			count++;
		}

		num = (unsigned int)n;
	}

	if (num / 10)
	{
		result = _print_number_unsigned(num / 10,
				buffer, buffer_index);
		if (result == -1)
			return (-1);

		count += result;
	}

	result = _buffer_char((num % 10) + '0', buffer, buffer_index);
	if (result == -1)
		return (-1);

	count++;

	return (count);
}

/**
 * _print_number_unsigned - stores an unsigned integer in the buffer
 * @n: unsigned integer to print
 * @buffer: character buffer
 * @buffer_index: current buffer position
 *
 * Return: number of characters stored, or -1 on failure
 */
int _print_number_unsigned(unsigned int n, char *buffer,
		int *buffer_index)
{
	int count = 0;
	int result;

	if (n / 10)
	{
		result = _print_number_unsigned(n / 10, buffer,
				buffer_index);
		if (result == -1)
			return (-1);

		count += result;
	}

	result = _buffer_char((n % 10) + '0', buffer, buffer_index);
	if (result == -1)
		return (-1);

	count++;

	return (count);
}

/**
 * _print_base - stores an unsigned integer in a given base
 * @n: unsigned integer to print
 * @base: number system to use
 * @letter_case: 0 for lowercase, 1 for uppercase
 * @buffer: character buffer
 * @buffer_index: current buffer position
 * @alternate: whether to use an alternate representation
 *
 * Return: number of characters stored, or -1 on failure
 */

int _print_base(unsigned int n, unsigned int base, int letter_case, int alternate, char *buffer, int *buffer_index)
{
	int count = 0;
	int result;
	unsigned int remainder;
	char digit;

	if (base < 2 || base > 16)
		return (0);

	if (alternate && n != 0)
	{
		if (base == 8)
		{
			result = _buffer_char('0', buffer, buffer_index);
			if (result == -1)
				return (-1);
			count++;
		}
		else if (base == 16)
		{
			result = _buffer_char('0', buffer, buffer_index);
			if (result == -1)
				return (-1);
			count++;

			result = _buffer_char(letter_case ? 'X' : 'x', buffer, buffer_index);
			if (result == -1)
				return (-1);
			count++;
		}
	}

	if (n / base)
	{
		result = _print_base(n / base, base, letter_case, 0, buffer, buffer_index);
		if (result == -1)
			return (-1);

		count += result;
	}

	remainder = n % base;

	if (remainder < 10)
		digit = remainder + '0';
	else if (letter_case)
		digit = remainder - 10 + 'A';
	else
		digit = remainder - 10 + 'a';

	result = _buffer_char(digit, buffer, buffer_index);
	if (result == -1)
		return (-1);

	count++;

	return (count);
}

/**
 * _print_pointer - stores a pointer address in hexadecimal
 * @ptr: pointer whose address is to be printed
 * @buffer: character buffer
 * @buffer_index: current buffer position
 *
 * Return: number of characters stored, or -1 on failure
 */
int _print_pointer(void *ptr, char *buffer, int *buffer_index)
{
	unsigned long address;
	char digits[sizeof(unsigned long) * 2];
	char hex[] = "0123456789abcdef";
	int i = 0;
	int count = 0;
	int result;

	if (ptr == (void *)0)
	{
		char null_text[] = "(nil)";

		while (null_text[i] != '\0')
		{
			result = _buffer_char(null_text[i], buffer, buffer_index);
			if (result == -1)
				return (-1);
			count++;
			i++;
		}

		return (count);
	}

	address = (unsigned long)ptr;

	while (address > 0)
	{
		digits[i] = hex[address % 16];
		address /= 16;
		i++;
	}

	result = _buffer_char('0', buffer, buffer_index);
	if (result == -1)
		return (-1);
	count++;

	result = _buffer_char('x', buffer, buffer_index);
	if (result == -1)
		return (-1);
	count++;

	while (i > 0)
	{
		i--;
		result = _buffer_char(digits[i], buffer, buffer_index);
		if (result == -1)
			return (-1);
		count++;
	}

	return (count);
}
