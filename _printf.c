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
int count = 0;
int i = 0;
va_list args;
va_start(args, format);
for (; format[i] != '\0'; i++)
{
if (format[i] == '%') 
{
i++;
if (format[i] == 'c') 
{
char c = (char)va_arg(args, int);
write(1, &c, 1);
count++;
}
else if (format[i] == 's')
{
char *s = va_arg(args, char*);
int len = strlen(s);
write(1, s, len);
count += len;
}
else if (format[i] == '%')
{
char c = '%';
write(1, &c, 1);
count++;
}
}
else {
write(1, &format[i], 1);
count++;
}
}
va_end(args);
return (count);
}
