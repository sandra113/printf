#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...);
int print_string(va_list list);
int number_to_string(int num, char**str, int depth);
``
#endif /* MAIN_H */
