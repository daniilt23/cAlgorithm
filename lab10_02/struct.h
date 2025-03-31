#ifndef STRUCT_H
#define STRUCT_H
#include "const.h"

typedef struct
{
    char name[SIZE];
    int marks[MARKS_SIZE];
    char group[SIZE];
    float average;
} Student;

#endif // STRUCT_H
