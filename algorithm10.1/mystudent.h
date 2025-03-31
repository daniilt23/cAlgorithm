#ifndef MYSTUDENT_H
#define MYSTUDENT_H
#include <stdio.h>
#include <string.h>
#include "const.h"
#include "memory.h"
#include "condition.h"
#include "io.h"
#include "struct.h"

void distribute(Student* students, int count);
int findMinMark(Student* students);
void distributeGroup(Student* students, enum Marks);
void determinateGroup(Student* students, int count);
void sortStudents(Student* students, int count);
void swap(Student* s1, Student* s2);
void findAnswer(Student* students, char* group, int count);
void sortByGroup(Student* students, int count);

#endif // MYSTUDENT_H
