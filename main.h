#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int _putchar(char c);
void intToChar(int num, char* str);
void spec_d_i(int i, int *p);


#endif
