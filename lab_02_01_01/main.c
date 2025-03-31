#include <stdio.h>
#include <math.h>

enum Correct
{
    CORRECT_INPUT = 3
};

enum Status {
    CORRECT,
    ERROR
};

int readvalues(float* a, float* b, int* c);
int findSolution();
float stepCount(float a, float b, int c);
void printFor(float a, float b, float step);
void printWhile(float a, float b, float step);
void printDoWhile(float a, float b, float step);
int checkTheCondition(float a, float b, int c);
void incorrectPrint();
float function(float a);
void printResult(float x);

int main()
{
    return findSolution();
}

int findSolution()
{
    float a, b;
    int c;
    enum Status state = ERROR;
    if (readvalues(&a, &b, &c) && checkTheCondition(a, b, c))
    {
        state = CORRECT;
        float step = stepCount(a, b, c);
        printFor(a, b, step);
        printWhile(a, b, step);
        printDoWhile(a, b, step);
    }
    else
        incorrectPrint();
    return state;
}

int readvalues(float* a, float* b, int* c)
{
    return scanf("%f %f %d", a, b, c) == CORRECT_INPUT;
}

int checkTheCondition(float a, float b, int c)
{
    return a < b && c > 1;
}

float stepCount(float a, float b, int c)
{
    return (b - a) / (c - 1);
}

float function(float a)
{
    return (sin(a) * sin(a)) / a;
}

void printFor(float a, float b, float step)
{
    float i = a;
    printf("\nfor:\n");
    printf("x    ");
    for (; a <= b; a += step)
    {
        printf("|%6.3f ", a);
    }
    printf("|\nf(x) ");
    for (; i <= b; i += step)
    {
      printResult(i);
    }
    printf("|\n");
}

void printWhile(float a, float b, float step)
{
    float i = a;
    printf("\nwhile:\n");
    printf("x    ");
    while (a <= b)
    {
        printf("|%6.3f ", a);
        a += step;
    }
    printf("|\nf(x) ");

    while (i <= b)
    {
        printResult(i);
        i += step;
    }
    printf("|\n");
}

void printDoWhile(float a, float b, float step)
{
    float i = a;
    printf("\ndo while:\n");
    printf("x    ");
    do
    {
        printf("|%6.3f ", a);
        a += step;
    }   while (a <= b);

    printf("|\nf(x) ");
    do
    {
        printResult(i);
        i += step;
    }   while (i <= b);
    printf("|\n");
}

void printResult(float x)
{
    if (!isnan(function(x)))
        printf("|%6.3f ", function(x));
    else
        printf("|  nan  ");
}

void incorrectPrint()
{
    printf("Incorrect input");
}
