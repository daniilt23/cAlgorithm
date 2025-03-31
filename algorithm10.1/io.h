#ifndef IO_H
#define IO_H
#include <string.h>
#include "struct.h"
#include "condition.h"

int getStudents(Student* students, int count);
void incorrectInput();
void spaceBetweenGroup();
void printGroups(Student* students, int count);
void printStudent(const Student* students);

#endif // IO_H
