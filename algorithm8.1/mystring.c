#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

#define SIGNS ",.?!;:()-"

enum
{
    SIGNS_COUNT = 9,
    SIZE = 100
};

char* getString()
{
    int len = 0;
    char* str = allocateMemory();
    char c = getchar();
    while(c != '\n')
    {
        str[len] = c;
        len++;
        c = getchar();
    }
    str[len] = '\0';

    return str;
}

char* allocateMemory()
{
    return (char*)malloc(sizeof(char) * SIZE);
}

unsigned strLen(const char* str)
{
    unsigned i = 0;
    for (i = 0; str[i]; i++);

    return i;
}

char* strdelMy(char* str, unsigned index)
{
    if (index >= strLen(str))
        *str = 0;
    else
        strcpy(str + index, str + index + 1);

    return str;
}

char* strcpy(char* str1, const char* str2)
{
    for (int i = 0; (str1[i] = str2[i]); i++);

    return str1;
}

void distribute(char* str)
{
    unsigned len = strLen(str);
    for (unsigned i = 0; i < len; i++)
    {
        if (strChr(str + i, ' '))
        {
            if (strChr(str + i + 1, ' ') || strPbrk(str + i + 1, SIGNS))
            {
                strdelMy(str, i);
                i--;
                len--;
            }
        }
    }
    trim(str, len);
}

void trim(char* str, unsigned len)
{
    if (strChr(str + len - 1, ' '))
        strdelMy(str, len - 1);
    if (strChr(str, ' '))
        strdelMy(str, 0);
}

unsigned strPbrk(char* str, const char* sym)
{
    unsigned isFound = 0;
    for (unsigned i = 0; i < SIGNS_COUNT; i++)
        if (*str == sym[i])
            isFound = 1;

    return isFound;
}

unsigned strChr(const char* str, char ch)
{
    return *str == ch;
}

void freeMemory(char* str)
{
    free(str);
}

void printStr(const char* str)
{
    printf("|%s|\n", str);
}

