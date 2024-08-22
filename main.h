#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _strlen(const char *s);
int handle_specifier(char specifier, va_list args);
int print_number(int num);

#endif
