#ifndef MEMORY_H
#define MEMORY_H
#include "struct.h"
#include <stdlib.h>

Student* allocateMemoryForStructs(int count);
void freeMemory(Student* students);

#endif // MEMORY_H
