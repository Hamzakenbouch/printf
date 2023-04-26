#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
void intToChar(int num, char* str)
{
    int divisor = 1;
    int i = 0;
    if (num < 0) {
        str[i++] = '-';
        num = -num;
    }
    while (num / divisor >= 10) {
        divisor *= 10;
    }
    while (divisor > 0) {
        int digit = num / divisor;
        str[i++] = digit + '0';
        num %= divisor;
        divisor /= 10;
    }
    str[i] = '\0';
}
