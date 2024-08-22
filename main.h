#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

int handle_specifier(const char *format, va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);

#endif /* MAIN_H */
