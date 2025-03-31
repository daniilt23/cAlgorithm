#ifndef IO_H
#define IO_H
#include <string.h>
#include "stdio.h"
#include "struct.h"

int getStudents(Student* students, int count);
void printGroups(Student* students, int count);
void printStudent(Student* students);
void spaceBetweenGroup();
void incorrectInput();

#endif // IO_H
