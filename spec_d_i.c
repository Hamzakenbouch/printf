#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
void spec_d_i(int i, int *p)
{
    char *str;
    int slend;
    str = (char*) malloc(sizeof(char) * 12);
    if (str == NULL) {
        return;
    }
    intToChar(i, str);
    slend = strlen(str);
    *p = write(1, str, slend);
    free(str);
}
