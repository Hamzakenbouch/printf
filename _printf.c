#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
/**
 * _printf - prints output according to a format
 * @format: the format string
 * @...: additional arguments
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
va_list narg;
int out = 0;
int outdi_val;
int *outdi = &outdi_val;
va_start(narg, format);


if (format == NULL)
{
return (-1);
}

while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
out += _putchar(va_arg(narg, int));
break;
case 's':
{
char *str = va_arg(narg, char *);
int slen = strlen(str);
out += write(1, str, slen);
break;
}
case 'd':
spec_d_i((va_arg(narg, int)), outdi);
out += *outdi;
break;

case 'i':
spec_d_i((va_arg(narg, int)), outdi);
out += *outdi;
break;

case '%':
_putchar('%');
out++;
break;
