#include <stdio.h>
#include <math.h>
#define ERROR_RATE 0.000001
#define CORRECT_INPUT 2

enum  {
    TEN = 10,
    HUNDREAD = 100
};

enum Status {
    CORRECT,
    ERROR
};

enum Point {
    NOTHING,
    REGION1,
    REGION2,
    REGION3,
    REGION4,
    REGION5,
    REGION6,
    REGION7,
    LINE1 = 11,
    LINE2 = 12,
    LINE3 = 13,
    LINE12 = 112,
    LINE23 = 223,
    LINE13 = 113,
};

int readvalue(float* x, float* y);
void printResult(enum Point position);
enum Point getPosition(float chart);
enum Point distribute(float first, float second, float third);
float firstLine(float x, float y);
float secondLine(float x, float y);
float thirdLine(float x, float y);
int pointOnLine(float first, float second, float third);
int pointRegion(float first, float second, float third);
enum Status findSolution();
void incorrectPrint();

int main() {
    return findSolution();
}

enum Status findSolution()
{
   float x, y;
   enum Point position = NOTHING;
   enum Status state = ERROR;
   if (readvalue(&x, &y))
   {
       state = CORRECT;
       float first = firstLine(x, y);
       float second = secondLine(x, y);
       float third = thirdLine(x, y);
       position = distribute(first, second, third);
   }
   printResult(position);
   return state;
}

int readvalue(float* x, float* y)
{
    return scanf("%f %f", x, y) == CORRECT_INPUT;
}

enum Point distribute(float first, float second, float third)
{
    enum Point position = pointOnLine(first, second, third);
    if (!position)
        position = pointRegion(first, second, third);

    return position;
}

int pointOnLine(float first, float second, float third)
{
    enum Point position = NOTHING;
    if (fabs(first) <= ERROR_RATE && fabs(second) <= ERROR_RATE)
        position = LINE12;
    else if (fabs(first) <= ERROR_RATE && fabs(third) <= ERROR_RATE)
        position = LINE13;
    else if (fabs(second) <= ERROR_RATE && fabs(third) <= ERROR_RATE)
        position = LINE23;
    else if (fabs(first) <= ERROR_RATE)
        position = LINE1;
    else if (fabs(second) <= ERROR_RATE)
        position = LINE2;
    else if (fabs(third) <= ERROR_RATE)
        position = LINE3;
    return position;
}

int pointRegion(float first, float second, float third)
{
    enum Point position = NOTHING;
    if (first > 0 && second < 0 && third < 0)
        position = REGION1;
    else if (first > 0 && second > 0 && third < 0)
        position = REGION2;
    else if (first > 0 && second > 0 && third > 0)
        position = REGION3;
    else if (first < 0 && second > 0 && third > 0)
        position = REGION4;
    else if (first < 0 && second < 0 && third > 0)
        position = REGION5;
    else if (first < 0 && second < 0 && third < 0)
        position = REGION6;
    else
        position = REGION7;
    return position;
}

void printResult(enum Point position)
{
    if (position == NOTHING)
        incorrectPrint();
    else if (position >= LINE1 && position <= LINE3)
        printf("Point is placed on line %d\n", position % TEN);
    else if (position >= LINE12 && position <= LINE23)
        printf("Point is placed on lines %d and %d\n", position / HUNDREAD, position % TEN);
    else if (position >= REGION1 && position <= REGION7)
        printf("Point is placed in region %d\n", position);
}

float firstLine(float x, float y)
{
    return 2 * x + 2 - y;
}

float secondLine(float x, float y)
{
   return 0.5 * x - 1 - y;
}

float thirdLine(float x, float y)
{
   return - x + 2 - y;
}

void incorrectPrint(void)
{
    printf("Result: Incorrect input");
}




