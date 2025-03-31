#ifndef MYSTRING_H
#define MYSTRING_H

char* getString();
char* allocateMemory();
void freeMemory(char* str);
unsigned strLen(const char* str);
char* strdelMy(char* str, unsigned index);
char* strcpy(char* str1, const char* str2);
void distribute(char* str);
void trim(char* str, unsigned len);
unsigned strChr(const char* str, char ch);
unsigned strPbrk(char* str, const char* sym);
void printStr(const char* str);


#endif // MYSTRING_H
