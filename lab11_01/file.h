#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#include "memory.h"
#include "fileaction.h"
#include "printerror.h"
#include "condition.h"

int deleteEmptyLines(char** text, int lineCount);
void numerationRows(char** text, int lineCount);
void fillNewFile(FILE* newFile, char** text, int lineCount);
int countLines(FILE* file);

#endif // FILE_H
