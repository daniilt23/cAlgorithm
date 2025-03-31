#include "other.h"

FILE* openFileToWrite(char* filename)
{
    return fopen(filename, "a");
}

FILE* openFileToWriteW(char* filename)
{
    return fopen(filename, "w");
}

FILE* openFileToRead(char* filename)
{
    return fopen(filename, "r");
}

void closeFile(FILE* file)
{
    fclose(file);
}
