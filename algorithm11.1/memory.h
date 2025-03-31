#ifndef MEMORY_H
#define MEMORY_H
#include "file.h"

char** allocateMemoryForText(int lineCount);
void freeMemory(char** text);

#endif // MEMORY_H
