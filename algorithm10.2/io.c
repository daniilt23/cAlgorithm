#include "io.h"

int getStudents(Student* students, int count)
{
    int readValue = CORRECT_INPUT;
    for (int i = 0; i < count; i++)
    {
        scanf("%s", students[i].name);
        for (int j = 0; j < MARKS_SIZE; j++)
        {
            if(scanf("%d", students[i].marks + j) != 1 || students[i].marks[j] < 2 || students[i].marks[j] > 5)
            {
                readValue = INCORRECT_INPUT;
                break;
            }
        }
    }

    return readValue;
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

void printStudent(Student* students)
{
    printf("%s\n", students->name);
    for (int j = 0; j < MARKS_SIZE; j++)
        printf("%d ", students->marks[j]);
    printf("\n");
    printf("%.2f\n", students->average);
}

void spaceBetweenGroup()
{
    printf("\n");
}

void incorrectInput()
{
    printf("Incorect input");
}
