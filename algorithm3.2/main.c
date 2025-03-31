#include <stdio.h>
#include <math.h>

enum Status {
    CORRECT,
    ERROR
};

enum
{
    CORRECT_INPUT = 3
};

enum
{
    TWO = 2,
    THREE = 3,
    FOUR = 4
};

int programStatus();
int readValues(float* a, float* b, float* e);
int checkTheCondition(float a, float b, float e);
float calculateIntegral(float a, float b, int n);
float calculateDiffOfIntegrals(float a, float b, float e);
float f(float x);
void printResult(float result);
void printIncorrectInput();

int main()
{
    return programStatus();
}

int programStatus()
{
    float a, b;
    float e;
    enum Status state = ERROR;
    if (readValues(&a, &b, &e) && checkTheCondition(a, b, e))
    {
        state = CORRECT;
        float result = calculateDiffOfIntegrals(a, b, e);
        printResult(result);
    }
    else
      printIncorrectInput();
    return state;
}

int readValues(float* a, float* b, float* e)
{
    return scanf("%f %f %f", a, b, e) == CORRECT_INPUT;
}

int checkTheCondition(float a, float b, float e)
{
    return a > 0 && b > 0 && e > 0 ;
}

float f(float x)
{
  return log(x);
}

float calculateIntegral(float a, float b, int n)
{
    float sum = f(a) + f(b);
    float h = (b - a) / n;
    for (int i = 1; i < n; i++)
    {
        float x = a + i * h;
        if (i % TWO == 0)
            sum += TWO * f(x);
        else
            sum += FOUR * f(x);
    }
    return h / THREE * sum;
}

float calculateDiffOfIntegrals(float a, float b, float e)
{
    int n = 1;
    float previous = 0;
    float current = calculateIntegral(a, b, n);
    do
    {
        previous = current;
        n *= TWO;
        current = calculateIntegral(a, b, n);
    } while (fabs(current - previous) > e);
    return current;
}

void printIncorrectInput()
{
    printf("Incorrect input");
}

void printResult(float result)
{
    printf("%f", result);
}
