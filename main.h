#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...);
int print_string(va_list list);
int print_number(va_list list);
int print_byte(va_list list);
int print_unsigned_int(va_list list);
int print_unsigned_octal(va_list list);
int print_hexadecimal_lower(va_list list);
int print_hexadecimal_upper(va_list list);
int print_pointer(va_list list);

#endif /* MAIN_H */
