#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed, or -1 on failure
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0, result;
	char buffer[1024];
	char temp[32];
	int buffer_index = 0;
	int temp_index;
	int plus = 0, space = 0, alternate = 0;
	int length = 0;
	int width = 0;
	int precision = -1;
	int zero = 0;
	int left = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			result = _buffer_char(format[i], buffer,
					&buffer_index);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count++;
		}
		else
		{
			i++;

			plus = 0;
			space = 0;
			alternate = 0;
			length = 0;
			width = 0;
			precision = -1;
			zero = 0;
			left = 0;

			while (format[i] == '+' || format[i] == ' ' || format[i] == '#' || format[i] == '0' || format[i] == '-')
			{
				if (format[i] == '+')
					plus = 1;
				else if (format[i] == ' ')
					space = 1;
				else if (format[i] == '#')
					alternate = 1;
				else if (format[i] == '0')
					zero = 1;
				else if (format[i] == '-')
					left = 1;
				i++;
			}
			while (format[i] >= '0' && format[i] <= '9')
			{
				width = width * 10 + (format[i] - '0');
				i++;
			}

			if (format[i] == '.')
			{
				i++;
				precision = 0;

				while (format[i] >= '0' && format[i] <= '9')
				{
					precision = precision * 10 + (format[i] - '0');
					i++;
				}
			}

			if (format[i] == 'l')
				length = 1;
			else if (format[i] == 'h')
				length = 2;

			if (length != 0)
				i++;


			if (format[i] == '\0')
			{
				result = _buffer_char('%', buffer,
						&buffer_index);
				if (result == -1)
				{
					va_end(args);
					return (-1);
				}
				count++;
				break;
			}

			else if (format[i] == 'c')
			{
				if (!left)
				{
					result = _print_padding(width, 1, buffer, &buffer_index);
					if (result == -1)
						return (-1);
					count += result;
				}

				result = _buffer_char(va_arg(args, int), buffer, &buffer_index);
				if (result == -1)
					return (-1);
				count++;

				if (left)
				{
					result = _print_padding(width, 1, buffer, &buffer_index);
					if (result == -1)
						return (-1);
					count += result;
				}
			}

			else if (format[i] == 's')
			{
				char *str;
				int str_length = 0;

				str = va_arg(args, char *);

				if (str == NULL)
					str = "(null)";

				while (str[str_length] != '\0')
				{
					if (precision >= 0 && str_length == precision)
						break;
					str_length++;
				}

				if (!left)
				{
					result = _print_padding(width, str_length, buffer, &buffer_index);
					if (result == -1)
						return (-1);
					count += result;
				}

				result = _print_string(str, str_length, buffer, &buffer_index);
				if (result == -1)
					return (-1);
				count += result;

				if (left)
				{
					result = _print_padding(width, str_length, buffer, &buffer_index);
					if (result == -1)
						return (-1);
					count += result;
				}
			}

			else if (format[i] == 'd' || format[i] == 'i')
			{
				temp_index = 0;

				if (length == 1)
					result = _print_long_number(va_arg(args, long), plus, space, temp, &temp_index);
				else if (length == 2)
					result = _print_number((short)va_arg(args, int), plus, space, temp, &temp_index);
				else
					result = _print_number(va_arg(args, int), plus, space, temp, &temp_index);

				if (result == -1)
					return (-1);

				if (precision >= 0)
					result = _print_precision_buffer(temp, temp_index, width, precision, left, buffer, &buffer_index);
				else
					result = _print_padded_buffer(temp, temp_index, width, zero, left, buffer, &buffer_index);
				if (result == -1)
					return (-1);

				count += result;
			}



			else if (format[i] == 'u')
			{
				temp_index = 0;

				if (length == 1)
					result = _print_long_unsigned(va_arg(args, unsigned long), temp, &temp_index);
				else if (length == 2)
					result = _print_number_unsigned((unsigned short)va_arg(args, int), temp, &temp_index);
				else
					result = _print_number_unsigned(
							va_arg(args, unsigned int), temp, &temp_index);

				if (result == -1)
					return (-1);

				if (precision >= 0)
					result = _print_precision_buffer(temp, temp_index, width, precision, left, buffer, &buffer_index);
				else
					result = _print_padded_buffer(temp, temp_index, width, zero, left, buffer, &buffer_index);
				if (result == -1)
					return (-1);

				count += result;
			}


			else if (format[i] == 'o')
			{
				temp_index = 0;

				if (length == 1)
					result = _print_long_base(va_arg(args, unsigned long), 8, 0, alternate, temp, &temp_index);
				else if (length == 2)
					result = _print_base((unsigned short)va_arg(args, int), 8, 0, alternate, temp, &temp_index);
				else
					result = _print_base(va_arg(args, unsigned int), 8, 0, alternate, temp, &temp_index);

				if (result == -1)
					return (-1);

				if (precision >= 0)
					result = _print_precision_buffer(temp, temp_index, width, precision, left, buffer, &buffer_index);
				else
					result = _print_padded_buffer(temp, temp_index, width, zero, left, buffer, &buffer_index);
				if (result == -1)
					return (-1);

				count += result;
			}
			else if (format[i] == 'x' || format[i] == 'X')
			{
				temp_index = 0;

				if (length == 1)
					result = _print_long_base(va_arg(args, unsigned long), 16, format[i] == 'X', alternate, temp, &temp_index);
				else if (length == 2)
					result = _print_base((unsigned short)va_arg(args, int), 16, format[i] == 'X', alternate, temp, &temp_index);
				else
					result = _print_base(va_arg(args, unsigned int), 16, format[i] == 'X', alternate, temp, &temp_index);

				if (result == -1)
					return (-1);


				if (precision >= 0)
					result = _print_precision_buffer(temp, temp_index, width, precision, left, buffer, &buffer_index);
				else
					result = _print_padded_buffer(temp, temp_index, width, zero, left, buffer, &buffer_index);

				if (result == -1)
					return (-1);

				count += result;
			}

			else if (format[i] == 'p')
			{
				temp_index = 0;

				result = _print_pointer(va_arg(args, void *), temp, &temp_index);
				if (result == -1)
					return (-1);

				result = _print_padded_buffer(temp, temp_index, width, zero, 0, buffer, &buffer_index);
				if (result == -1)
					return (-1);

				count += result;
			}

			else
			{
				result = _buffer_char('%', buffer, &buffer_index);
				if (result == -1)
				{
					va_end(args);
					return (-1);
				}
				count++;

				result = _buffer_char(format[i], buffer, &buffer_index);
			}

			if (result == -1)
			{
				va_end(args);
				return (-1);
			}

		}

		if (_flush_buffer(buffer, &buffer_index) == -1)
		{
			va_end(args);
			return (-1);
		}
	}

	va_end(args);

	return (count);
}
