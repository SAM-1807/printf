
#include "main.h"

/**
 * _print_long_unsigned - prints an unsigned long integer
 * @n: number to print
 * @buffer: output buffer
 * @buffer_index: current buffer position
 *
 * Return: number of characters printed, or -1 on failure
 */
int _print_long_unsigned(unsigned long n, char *buffer, int *buffer_index)
{
        int count = 0;
        int result;

        if (n / 10)
        {
                result = _print_long_unsigned(n / 10, buffer, buffer_index);
                if (result == -1)
                        return (-1);
                count += result;
        }

        result = _buffer_char((n % 10) + '0', buffer, buffer_index);
        if (result == -1)
                return (-1);

        return (count + 1);
}

/**
 * _print_long_number - prints a signed long integer
 * @n: number to print
 * @plus: whether to print a plus sign
 * @space: whether to print a leading space
 * @buffer: output buffer
 * @buffer_index: current buffer position
 *
 * Return: number of characters printed, or -1 on failure
 */
int _print_long_number(long n, int plus, int space, char *buffer, int *buffer_index)
{
        unsigned long num;
        int count = 0;
        int result;

        if (n < 0)
        {
                result = _buffer_char('-', buffer, buffer_index);
                if (result == -1)
                        return (-1);
                count++;

                num = 0UL - (unsigned long)n;
        }
        else
        {
                if (plus || space)
                {
                        result = _buffer_char(plus ? '+' : ' ', buffer, buffer_index);
                        if (result == -1)
                                return (-1);
                        count++;
                }

                num = (unsigned long)n;
        }

        result = _print_long_unsigned(num, buffer, buffer_index);
        if (result == -1)
                return (-1);

        return (count + result);
}

/**
 * _print_long_base - prints an unsigned long in a given base
 * @n: number to print
 * @base: number system to use
 * @letter_case: 0 for lowercase, 1 for uppercase
 * @alternate: whether to print an alternate prefix
 * @buffer: output buffer
 * @buffer_index: current buffer position
 *
 * Return: number of characters printed, or -1 on failure
 */
int _print_long_base(unsigned long n, unsigned int base,
                int letter_case, int alternate, char *buffer, int *buffer_index)
{
        unsigned long remainder;
        char digit;
        int count = 0;
        int result;

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
                result = _print_long_base(n / base, base, letter_case, 0, buffer, buffer_index);
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

        return (count + 1);
}

