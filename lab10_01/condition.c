#include "condition.h"

int readValue(int* count)
{
    return scanf("%d", count);
}

int checkSizeCondition(int count)
{
    return count > 0;
}

int checkFamily(Student* student)
{
    int readValues = 1;
    for (unsigned j = 0; j < strlen(student->name); j++)
    {
        if (!(isalpha(*student->name + j)))
        {
            readValues = 0;
            break;
        }
    }

    return readValues;
}

