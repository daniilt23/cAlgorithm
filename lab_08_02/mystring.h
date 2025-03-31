#ifndef MYSTRING_H
#define MYSTRING_H

int readValue(int* rowCount);
int checkRowCountCondition(int rowCount);
char** allocateMemoryForMatrix(int rowCount);
int inputMatrix(char** mat, int rowCount);
char* allocateMemoryForStr();
void freeMemoryForStr(char* str);
void freeMemoryForMat(char** mat, int rowCount);
char* getString();
void strCat(char* s1, const char* s2);
int strCmp(const char* s1, const char* s2);
char* strStr(char* s, const char* subs);
char* strPbrk(char* str, const char* sym);
int countWords(char* str, char* spr);
unsigned strLen(const char* str);
unsigned strChr(const char* s, char sym);
void replace(char** str, int rowCount, char* old, char* new);
void printChangeFio(char** mat, int rowCount);
void incorrectInput();

#endif // MYSTRING_H
