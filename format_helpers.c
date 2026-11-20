#include "main.h"

/**
 * _print_padding - writes padding characters to the buffer
 * @width: requested field width
 * @length: length of converted output
 * @buffer: output buffer
 * @buffer_index: current buffer position
 *
 * Return: number of padding characters written, or -1
 */
int _print_padding(int width, int length, char *buffer, int *buffer_index)
{
	int padding = width - length;
	int count = 0;

	while (count < padding)
	{
		if (_buffer_char(' ', buffer, buffer_index) == -1)
			return (-1);
		count++;
	}

	return (count);
}

/**
 * _int_to_string - converts an integer into a string
 * @n: integer to convert
 * @temp: temporary character array
 *
 * Return: number of characters converted
 */
int _int_to_string(int n, char *temp)
{
	unsigned int num;
	int count = 0;
	int start, end;
	char digit, sign;

	if (n < 0)
	{
		sign = '-';
		num = -(unsigned int)n;
	}
	else
	{
		sign = '\0';
		num = (unsigned int)n;
	}

	do {
		temp[count++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	if (sign == '-')
		temp[count++] = sign;

	start = 0;
	end = count - 1;

	while (start < end)
	{
		digit = temp[start];
		temp[start] = temp[end];
		temp[end] = digit;
		start++;
		end--;
	}

	temp[count] = '\0';
	return (count);
}

/**
 * _print_padded_buffer - prints a value with field width
 * @temp: temporary buffer containing the formatted value
 * @temp_length: length of the formatted value
 * @width: minimum field width
 * @buffer: main output buffer
 * @buffer_index: current position in main buffer
 *
 * Return: number of characters printed, or -1 on failure
 */
int _print_padded_buffer(char *temp, int temp_length, int width, int zero, int left, char *buffer, int *buffer_index)
{
	int i, count = 0, prefix = 0;
	int padding, result;

	padding = width - temp_length;

	if (padding < 0)
		padding = 0;

	if (left)
		zero = 0;

	if (padding > 0 && zero)
	{
		if (temp[0] == '-' || temp[0] == '+' || temp[0] == ' ')
			prefix = 1;
		else if (temp_length > 1 && temp[0] == '0' &&
				(temp[1] == 'x' || temp[1] == 'X'))
			prefix = 2;

		for (i = 0; i < prefix; i++)
		{
			result = _buffer_char(temp[i], buffer, buffer_index);
			if (result == -1)
				return (-1);
			count++;
		}

		for (i = 0; i < padding; i++)
		{
			result = _buffer_char('0', buffer, buffer_index);
			if (result == -1)
				return (-1);
			count++;
		}
	}
	else if (!left)
	{
		result = _print_padding(width, temp_length, buffer, buffer_index);
		if (result == -1)
			return (-1);
		count += result;
	}

	for (i = prefix; i < temp_length; i++)
	{
		result = _buffer_char(temp[i], buffer, buffer_index);
		if (result == -1)
			return (-1);
		count++;
	}

	if (left)
	{
		result = _print_padding(width, temp_length, buffer, buffer_index);
		if (result == -1)
			return (-1);
		count += result;
	}

	return (count);
}



/**
 * _print_precision_buffer - prints a number with precision and width
 * @temp: formatted number
 * @temp_length: number of characters in temp
 * @width: minimum field width
 * @precision: minimum number of digits
 * @buffer: main output buffer
 * @buffer_index: current buffer position
 *
 * Return: number of characters printed, or -1 on failure
 */
int _print_precision_buffer(char *temp, int temp_length, int width, int precision, int left, char *buffer, int *buffer_index)

{
	int prefix = 0, zeros = 0, spaces, total;
	int i, count = 0, result;

	if (precision == 0 && temp_length == 1 && temp[0] == '0')
		temp_length = 0;

	if (temp_length > 0 &&
			(temp[0] == '-' || temp[0] == '+' || temp[0] == ' '))
		prefix = 1;
	else if (temp_length > 1 && temp[0] == '0' &&
			(temp[1] == 'x' || temp[1] == 'X'))
		prefix = 2;

	if (precision > temp_length - prefix)
		zeros = precision - (temp_length - prefix);

	total = temp_length + zeros;
	spaces = width - total;

	if (spaces < 0)
		spaces = 0;

	if (!left)
	{
		for (i = 0; i < spaces; i++)
		{
			result = _buffer_char(' ', buffer, buffer_index);
			if (result == -1)
				return (-1);
			count++;
		}
	}

	for (i = 0; i < prefix; i++)
	{
		result = _buffer_char(temp[i], buffer, buffer_index);
		if (result == -1)
			return (-1);
		count++;
	}

	for (i = 0; i < zeros; i++)
	{
		result = _buffer_char('0', buffer, buffer_index);
		if (result == -1)
			return (-1);
		count++;
	}

	for (i = prefix; i < temp_length; i++)
	{
		result = _buffer_char(temp[i], buffer, buffer_index);
		if (result == -1)
			return (-1);
		count++;
	}

	if (left)
	{
		for (i = 0; i < spaces; i++)
		{
			result = _buffer_char(' ', buffer, buffer_index);
			if (result == -1)
				return (-1);
			count++;
		}

	}
	return (count);

}
