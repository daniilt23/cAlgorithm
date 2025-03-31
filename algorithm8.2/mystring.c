#include <stdio.h>
#include <malloc.h>
#include "mystring.h"

enum
{
    INCORRECT_INPUT,
    CORRECT_INPUT
};

enum
{
    WORD_SIZE = 2,
    SIZE = 100
};

int readValue(int* rowCount)
{
    return scanf("%d", rowCount);
}

int checkRowCountCondition(int rowCount)
{
    return rowCount > 0;
}

char** allocateMemoryForMatrix(int rowCount)
{
    return (char**)calloc(rowCount, sizeof(char*));
}

int inputMatrix(char** mat, int rowCount)
{
    int inputState = INCORRECT_INPUT;
    for (int i = 0; i < rowCount; i++)
    {
        mat[i] = getString();
        if (countWords(mat[i], " ") == WORD_SIZE)
            inputState = CORRECT_INPUT;
    }

    return inputState;
}

char* allocateMemoryForStr()
{
    return (char*)malloc(SIZE * sizeof(char));
}

void freeMemoryForStr(char* str)
{
    free(str);
}

void freeMemoryForMat(char** mat, int rowCount)
{
    for (int i = 0; i < rowCount; ++i)
        free(mat[i]);
    free(mat);
}

char* getString()
{
    int len = 0;
    char *s = allocateMemoryForStr();
    char c = getchar();
    while (c == '\n' || c == ' ')
        c = getchar();
    while (c != '\n')
    {
        s[len] = c;
        len++;
        c = getchar();
    }
    s[len] = '\0';

    return s;
}

char* strPbrk(char* str, const char* sym)
{
    int isFound = 0;
    char* p;
    for (p = str; !isFound && *p;)
    {
        unsigned i;
        for (i = 0; sym[i] && *p != sym[i]; i++);
        if (sym[i])
            isFound = 1;
        else
            p++;
    }

    return isFound ? p : 0;
}

unsigned strLen(const char* str)
{
    unsigned i = 0;
    for (; str[i]; i++);

    return i;
}

int countWords(char* str, char* spr)
{
    int counter = 0;
    char* p = str;
    for (char* pSpace; (pSpace = strPbrk(p, spr)); p++)
        if (p != pSpace)
        {
            counter += 1;
            p = pSpace;
        }

    return counter;
}

unsigned strChr(const char* s, char sym)
{
    unsigned index = 0;
    unsigned count = 0;
    for (int i = 0; s[i]; ++i)
    {
        if (s[i] == sym)
        {
            count++;
            if (count == 2)
                index = i + 1;
        }
    }

    return index;
}

void strCat(char *s1, const char *s2)
{
    for (unsigned i = 0; (s1[i] = s2[i]); i++);
}

int strCmp(const char* s1, const char* s2)
{
    int i = 0;
    for(; s1[i] && s1[i] == s2[i]; i++);

    return s1[i] - s2[i];
}

char* strStr(char* s, const char* subs)
{
    int isFound = 0;
    char* p;
    for (p = s; !isFound && *p;)
    {
        unsigned i;
        for (i = 0; subs[i] && p[i] == subs[i]; i++);
        if (!subs[i] && !p[i])
            isFound = 1;
        else
            p++;
    }

    return isFound ? p : 0;
}

void replace(char** str, int rowCount, char* old, char* new)
{
    unsigned surnameIndex;
    for (int i = 0; i < rowCount; ++i)
    {
        surnameIndex = strChr(*str, ' ');
        if (strCmp(str[i] + surnameIndex, old))
        {
            char* sub = strStr(str[i] + surnameIndex, old);
            if (sub != 0)
                strCat(sub, new);
        }
    }
}

void printChangeFio(char** mat, int rowCount)
{
    for (int i = 0; i < rowCount; i++)
        printf("%s\n", mat[i]);
}

void incorrectInput()
{
    printf("Incorrect input");
}

