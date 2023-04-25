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
va_list ap;
int written = 0;
char buf[1024] = {0};
int len = 0;
va_start(ap, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
int c = va_arg(ap, int);
buf[len++] = c;
}
else if (*format == 's')
{
char *str = va_arg(ap, char*);
int slen = strlen(str);
strncpy(buf + len, str, slen);
len += slen;
}
else if (*format == '%')
{
buf[len++] = '%';
}
else
{
buf[len++] = '%';
buf[len++] = *format;
}
}
else
{
buf[len++] = *format;
}
format++;
}
va_end(ap);
written = write(1, buf, len);
return (written);
}
