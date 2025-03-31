#include "mystudent.h"

int calculateProgramStatus()
{
    enum Status state = ERROR;
    int count;
    if (readValue(&count) && checkCountCondition(count))
    {
        Student* students = allocateMemoryForStructs(count);
        if (students)
        {
            if (getStudents(students, count) && checkFamily(students, count))
            {
                state = CORRECT;
                distributeMarks(students, count);
                sortStudents(students, count);
                findStupidStudents(&students, &count);
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

void distributeMarks(Student* students, int count)
{
    for (int i = 0; i < count; i++)
        calculateAverageValue(students + i);
}

void calculateAverageValue(Student* students)
{
    float sum = 0;
    for (int j = 0; j < MARKS_SIZE; j++)
        sum += students->marks[j];
    float avg = sum / (float)MARKS_SIZE;
    students->average = makeTenth(avg);
}

void sortByAverageValue(Student* students, int count)
{
    for (int i = 0; i < count; i++)
        for (int j = 0; j < count - i - 1; j++)
        {
            if (students[j].average < students[j + 1].average)
                swap (students + j, students + j + 1);
        }
}

void sortStudentsByName(Student* students, int count)
{
    for (int i = 0; i < count; i++)
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (students[j].average == students[j + 1].average && strcmp(students[j].name, students[j + 1].name) > 0)
                swap(students + j, students + j + 1);
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
    sortByAverageValue(students, count);
    sortStudentsByName(students, count);
}

void swap(Student* s1, Student* s2)
{
    Student temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void findStupidStudents(Student** students, int* count)
{
    int index = 0;
    int countTwo = 0;
    for (int i = 0; i < *count; i++)
    {
        countTwo = 0;
        for (int j = 0; j < MARKS_SIZE; j++)
        {
            if ((*students)[i].marks[j] == 2)
                countTwo++;
        }
        if (countTwo > 2)
        {
            index = i;
            deleteStudent(*students, index, count);
            i--;
        }
    }
    *students = realloc(*students, sizeof (Student) * (*count));
}

void deleteStudent(Student* students, int index, int* count)
{
    for (int i = index; i < *count - 1; i++)
        students[i] = students[i + 1];
    (*count)--;
}

void distribute(Student* students, int count)
{
    int mark = FIVE;
    for (int i = 0; i < count; i++)
    {
        mark = findMinMark(students + i);
        takeGroupToStudents(students + i, mark);
    }
}

int findMinMark(Student* students)
{
    int mark = FIVE;
    for (int j = 0; j < MARKS_SIZE; j++)
    {
        if (students->marks[j] < mark)
            mark = students->marks[j];
    }

    return mark;
}

void takeGroupToStudents(Student* students, enum Marks mark)
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
