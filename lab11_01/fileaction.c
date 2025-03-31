#include "fileaction.h"

FILE* openFileToRead(const char* filename)
{
    return fopen(filename, "r");
}

void readTheData(FILE* file, int lineCount, char** text)
{
    for (int i = 0; i < lineCount; i++)
    {
        if(fgets(text[i], SIZE, file) == NULL)
        {
            printCannotReadRow();
            break;
        }
    }
}

FILE* openFileToWrite(char* filename)
{
    return fopen(filename, "w");
}

void closeFile(FILE* file)
{
    fclose(file);
}
