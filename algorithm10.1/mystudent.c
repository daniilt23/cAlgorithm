#include "mystudent.h"

int calculateProgramStatus()
{
    enum Status state = ERROR;
    int count;
    if (readValue(&count) && checkSizeCondition(count))
    {
        Student* students = allocateMemoryForStructs(count);
        if (students)
        {
            if (getStudents(students, count))
            {
                state = CORRECT;
                sortStudents(students, count);
                distribute(students, count);
                sortByGroup(students, count);
                printGroups(students, count);
            }
            else
                incorrectInput();
            freeMemory(students);
        }
        else
            incorrectInput();
    }
    else
        incorrectInput();

    return state;
}

void distribute(Student* students, int count)
{
    int mark = FIVE;
    for (int i = 0; i < count; i++)
    {
        mark = findMinMark(students + i);
        distributeGroup(students + i, mark);
    }
}

int findMinMark(Student* students)
{
    int mark = FIVE;
    for (int j = 0; j < COUNT_MARKS; j++)
    {
        if (students->marks[j] < mark)
            mark = students->marks[j];
    }

    return mark;
}

void distributeGroup(Student* students, enum Marks mark)
{
    switch(mark)
    {
        case FOUR:
            strcpy(students->group, "B-students");
            break;
        case THREE:
            strcpy(students->group, "C-students");
            break;
        case TWO:
            strcpy(students->group, "D-students");
            break;
        default:
            strcpy(students->group, "A-students");
            break;
    }
}

void sortByGroup(Student* students, int count)
{
    for (int i = 0; i < count; i++)
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (strcmp(students[j].group, students[j + 1].group) > 0)
                swap(students + j, students + j + 1);
        }
}

void sortStudents(Student* students, int count)
{
    for (int i = 0; i < count; i++)
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (strcmp(students[j].name, students[j + 1].name) > 0)
                swap(students + j, students + j + 1);
        }
}

void swap(Student* s1, Student* s2)
{
    Student s = *s1;
    *s1 = *s2;
    *s2 = s;
}
