#include "main.h"
#include <unistd.h>
#include <limits.h>

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _print_string - stores a string in the output buffer
 * @str: string to print
 * @buffer: character buffer
 * @buffer_index: current buffer position
 *
 * Return: number of characters stored, or -1 on failure
 */
int _print_string(char *str, int max_length, char *buffer, int *buffer_index)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while (str[count] != '\0' && count < max_length)
	{
		if (_buffer_char(str[count], buffer, buffer_index) == -1)
			return (-1);

		count++;
	}

	return (count);
}

/**
 * _print_string_non_printable - prints a string, escaping
 * non-printable characters as hexadecimal
 * @str: string to print
 * @buffer: character buffer
 * @buffer_index: current buffer position
 *
 * Return: number of characters stored, or -1 on failure
 */
int _print_string_non_printable(char *str, char *buffer,
		int *buffer_index)
{
	const char *hex = "0123456789ABCDEF";
	unsigned char c;
	int i = 0;
	int count = 0;
	int result;

	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];

		if (c < 32 || c >= 127)
		{
			result = _buffer_char('\\', buffer, buffer_index);
			if (result == -1)
				return (-1);
			count++;

			result = _buffer_char('x', buffer, buffer_index);
			if (result == -1)
				return (-1);
			count++;

			result = _buffer_char(hex[c / 16], buffer,
					buffer_index);
			if (result == -1)
				return (-1);
			count++;

			result = _buffer_char(hex[c % 16], buffer,
					buffer_index);
			if (result == -1)
				return (-1);
			count++;
		}
		else
		{
			result = _buffer_char(c, buffer, buffer_index);
			if (result == -1)
				return (-1);
			count++;
		}

		i++;
	}

	return (count);
}

/**
 * _flush_buffer - writes buffered characters to standard output
 * @buffer: character buffer
 * @buffer_index: number of characters currently stored
 *
 * Return: number of characters written, or -1 on failure
 */
int _flush_buffer(char *buffer, int *buffer_index)
{
	int written = 0;
	int total = *buffer_index;

	while (written < total)
	{
		int result = write(1, buffer + written, total - written);

		if (result == -1)
			return (-1);

		written += result;
	}

	*buffer_index = 0;

	return (written);
}

/**
 * _buffer_char - stores a character in the buffer
 * @c: character to store
 * @buffer: character buffer
 * @buffer_index: current buffer position
 *
 * Return: 1 on success, -1 on failure
 */
int _buffer_char(char c, char *buffer, int *buffer_index)
{
	buffer[(*buffer_index)++] = c;

	if (*buffer_index == 1024)
	{
		if (_flush_buffer(buffer, buffer_index) == -1)
			return (-1);
	}

	return (1);
}
