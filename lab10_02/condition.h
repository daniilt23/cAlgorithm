#ifndef CONDITION_H
#define CONDITION_H
#include "struct.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int calculateProgramStatus();
int readValue(int* count);
int checkCountCondition(int count);
int checkFamily(Student* student, int count);

#endif // CONDITION_H
