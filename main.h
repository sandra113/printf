#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...);
int print_string(va_list list);

#endif /* MAIN_H */
