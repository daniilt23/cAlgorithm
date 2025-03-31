#include "memory.h"

Student* allocateMemoryForStructs(int count)
{
    return (Student*)malloc(sizeof(Student) * count);
}

void freeMemory(Student* students)
{
    free(students);
}
