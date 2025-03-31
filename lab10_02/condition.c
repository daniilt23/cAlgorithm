#include "condition.h"

int readValue(int* count)
{
    return scanf("%d", count);
}

int checkCountCondition(int count)
{
    return count > 0;
}

int checkFamily(Student* student, int count)
{
    int readValues = 1;
    for (int i = 0; i < count; i++)
        for (unsigned j = 0; j < strlen(student[i].name); j++)
        {
            if (!(isalpha(student[i].name[j])))
            {
                readValues = 0;
                break;
            }
        }

    return readValues;
}
