#include <stdarg.h>
#include <unistd.h>
#include <string.h>
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
va_start(narg, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
{
char c = (char)va_arg(narg, int);
write(1, &c, 1);
out++;
break;
}
case 's':
{
char *str = va_arg(narg, char *);
int slen = strlen(str);
write(1, str, slen);
out += slen;
break;
}
case '%':
write(1, "%", 1);
out++;
break;
}
}
else
{
write(1, &(*format), 1);
out++;
}
format++;
}
va_end(narg);
return (out);
}
