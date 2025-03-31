#ifndef MYSTUDENT_H
#define MYSTUDENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "round.h"
#include "memory.h"
#include "io.h"
#include "condition.h"

void calculateAverageValue(Student* students);
void sortByAverageValue(Student* students, int count);
void sortStudentsByName(Student* students, int count);
void sortStudents(Student* students, int count);
void swap(Student* s1, Student* s2);
void findStupidStudents(Student** students, int* count);
void deleteStudent(Student* students, int index, int* count);
void distribute(Student* students, int count);
void takeGroupToStudents(Student* students, enum Marks mark);
void sortByGroup(Student* students, int count);
int findMinMark(Student* students);
void distributeMarks(Student* students, int count);
void distribute(Student* students, int count);

#endif // MYSTUDENT_H
