#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...);
int print_string(va_list list);
int number_to_string(int num, char*str, int depth);
int print_number(va_list list);
int print_byte(va_list list);

#endif /* MAIN_H */
