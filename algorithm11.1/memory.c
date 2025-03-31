#include "memory.h"

char** allocateMemoryForText(int lineCount)
{
    char** text = malloc(sizeof(char*) * lineCount);
    if (text != NULL)
    {
        for (int i = 0; i < lineCount; i++)
        {
            text[i] = malloc(sizeof(char) * SIZE);
            if (text[i] == NULL)
            {
                text == NULL;
                break;
            }
        }
    }

    return text;
}

void freeMemory(char** text)
{
    free(*text);
    free(text);
}
