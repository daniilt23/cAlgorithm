#include <stdio.h>
#include <math.h>
#define ERROR_RATE 0.000001
#define CORRECT_INPUT 2

enum Status {
    CORRECT,
    ERROR
};

enum Point {
    NOTHING,
    ABOVE_LINE,
    UNDER_LINE,
    ON_LINE,
};

enum Status findSolution();
int readValue(float* x, float* y);
float getScore(float x, float y);
enum Point getPosition(float chart);
void printResult(enum Point position);
void incorrectPrint();

int main()
{
    return findSolution();
}

enum Status findSolution()
{
    enum Point position = NOTHING;
    enum Status state = ERROR;
    float x, y;
    if (readValue(&x, &y))
    {
        state = CORRECT;
        float score = getScore(x, y);
        position = getPosition(score);
    }
    printResult(position);
    return state;
}

int readValue(float* x, float* y)
{
    return scanf("%f %f", x, y) == CORRECT_INPUT;
}

void printResult(enum Point position)
{
    switch(position)
    {
    case NOTHING:
        incorrectPrint();
        break;
    case ON_LINE:
        printf("Point is on the line");
        break;
    case ABOVE_LINE:
        printf("Point is above the line");
        break;
    case UNDER_LINE:
        printf("Point is under the line");
        break;
    }
}

float getScore(float x, float y)
{
    return 0.5 * x + 1 - y;
}

enum Point getPosition(float chart)
{
    enum Point position = NOTHING;
    if (fabs(chart) <= ERROR_RATE)
        position = ON_LINE;
    else if (chart > 0)
        position = UNDER_LINE;
    else
        position = ABOVE_LINE;
    return position;
}

void incorrectPrint()
{
    printf("Incorrect input");
}
