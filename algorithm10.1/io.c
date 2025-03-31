#include "io.h"

int getStudents(Student* students, int count)
{
    int readValues = CORRECT_INPUT;
    for (int i = 0; i < count; i++)
    {
        if (scanf("%s", students[i].name) != 1 || !checkFamily(students + i))
            readValues = INCORRECT_INPUT;
        for (int j = 0; j < COUNT_MARKS; j++)
        {
            if (!scanf("%d", students[i].marks + j) || students[i].marks[j] < 2 || students[i].marks[j] > 5)
                readValues = INCORRECT_INPUT;
        }
    }

    return readValues;
}

void incorrectInput()
{
    printf("Incorrect input\n");
}

void spaceBetweenGroup()
{
    printf("\n");
}

void printStudent(const Student* students)
{
    printf("%s\n", students->name);
    for (int j = 0; j < COUNT_MARKS; j++)
        printf("%d ", students->marks[j]);
    printf("\n");
}

void printGroups(Student* students, int count)
{
    printf("%s:\n", students->group);
    printStudent(students);
    for (int i = 1; i < count; i++)
    {
        if (strcmp(students[i].group, students[i - 1].group) > 0)
        {
            spaceBetweenGroup();
            printf("%s:\n", students[i].group);
        }
        printStudent(students + i);
    }
}
