Custom Printf

Author: SAM

A custom implementation of the C standard library's "printf()" function, developed in C as part of the WinMingle Software Engineering Program.

The project explores variadic functions, format-string parsing, conversion specifiers, number representation, and formatted output.

Project Overview

The project implements a function with the following prototype:

int _printf(const char *format, ...);

It produces output according to a format string and returns the number of characters printed, excluding the terminating null byte.

Project Scope

Conversion Specifiers

- "%c" — Character
- "%s" — String
- "%%" — Literal percent sign
- "%d" and "%i" — Signed decimal integers
- "%b" — Unsigned binary representation
- "%u" — Unsigned decimal integer
- "%o" — Unsigned octal representation
- "%x" and "%X" — Unsigned hexadecimal representation
- "%S" — String with non-printable characters represented using hexadecimal escape sequences
- "%p" — Memory address

Formatting Features

- "+", space, and "#" flag characters
- "l" and "h" length modifiers
- Field width
- Precision
- "0" flag for zero padding
- "-" flag for left justification

Custom Conversion Specifiers

- "%r" — Reversed string
- "%R" — ROT13-encoded string

Project Structure

printf/
├── _printf.c
├── main.h
├── print_helpers.c
├── number_helpers.c
├── length_helpers.c
├── format_helpers.c
├── README.md
└── test/
├── edge_tests.c
├── flag_test.c
├── length_test.c
├── test_printf.c
└── width_test.c

Compilation

The project uses the following compilation flags:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89

To compile the implementation with a test program:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \
                                         _printf.c print_helpers.c number_helpers.c \
                                         length_helpers.c format_helpers.c \
                                         test/test_printf.c -o test_printf

                                         Usage

                                         Include the project header:

#include "main.h"

                                         Example:

                                         _printf("Hello, %s! You scored %d.\n", "Sam", 95);

                                         Project Requirements

                                         - Written in C.
                                         - Follows Betty coding style.
                                         - No global variables.
                                         - No more than five functions per source file.
                                         - All function prototypes are declared in "main.h".
                                         - Header files use include guards.
                                         - Output is handled using the authorized "write()" system call.
                                         - A local buffer is used to minimize write operations.

                                         ---

                                         Author: SAM
