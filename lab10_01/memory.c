#include "memory.h"

Student* allocateMemoryForStructs(int count)
{
    return (Student*)calloc(sizeof(Student), count);
}

void freeMemory(Student* students)
{
    free(students);
}
