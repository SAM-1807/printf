#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int _print_string(char *str, int max_length, char *buffer, int *buffer_index);
int _printf(const char *format, ...);
int _print_number_unsigned(unsigned int n, char *buffer,
		int *buffer_index);
int _print_string_non_printable(char *str, char *buffer,
		int *buffer_index);
int _flush_buffer(char *buffer, int *buffer_index);
int _buffer_char(char c, char *buffer, int *buffer_index);
int _print_pointer(void *ptr, char *buffer, int *buffer_index);
int _print_number(int n, int plus, int space, char *buffer, int *buffer_index);
int _print_base(unsigned int n, unsigned int base, int letter_case, int alternate, char *buffer, int *buffer_index);
int _print_long_unsigned(unsigned long n, char *buffer, int *buffer_index);
int _print_long_number(long n, int plus, int space, char *buffer, int *buffer_index);
int _print_long_base(unsigned long n, unsigned int base, int letter_case, int alternate, char *buffer, int *buffer_index);
int _print_padding(int width, int length, char *buffer, int *buffer_index);
int _int_to_string(int n, char *temp);
int _print_padded_buffer(char *temp, int temp_length, int width, char *buffer, int *buffer_index);
int _print_precision_buffer(char *temp, int temp_length, int width, int precision, char *buffer, int *buffer_index);

#endif


