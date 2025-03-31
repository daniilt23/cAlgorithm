#ifndef FILEACTION_H
#define FILEACTION_H
#include "file.h"
#include "printerror.h"

FILE* openFileToRead(const char* filename);
FILE* openFileToWrite(char* filename);
void readTheData(FILE* file, int lineCount, char** text);
void closeFile(FILE* file);


#endif // FILEACTION_H
