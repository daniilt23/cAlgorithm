#include "io.h"

int getFileName(char* filename)
{
    return scanf("%s", filename);
}

void printText(char** text, int lineCount)
{
    for (int i = 0; i < lineCount; i++)
        printf("%s", text[i]);
}

void getNewFilename(char* filename)
{
    scanf("%s", filename);
}
