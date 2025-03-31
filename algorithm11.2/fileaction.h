#ifndef FILEACTION_H
#define FILEACTION_H
#include <stdio.h>

FILE* openFileToWrite(char* filename);
FILE* openFileToWriteW(char* filename);
FILE* openFileToRead(char* filename);
void closeFile(FILE* file);

#endif // FILEACTION_H
