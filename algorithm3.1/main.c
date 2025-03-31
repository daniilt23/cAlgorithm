#include <stdio.h>
#include <math.h>

enum Status
{
    CORRECT,
    ERROR
};

enum
{
   CORRECT_INPUT = 1
};

int readValue(float* e);
float countSum(float e);
int calculateProgramStatus();
void printIncorrectInput();
int checkInput(float e);
void printResult(float result);

int main()
{
    return calculateProgramStatus();
}

int calculateProgramStatus()
{
    enum Status state = ERROR;
    float e = 0;
    if (readValue(&e) && checkInput(e))
    {
        state = CORRECT;
        float result = countSum(e);
        printResult(result);
    }
    else
        printIncorrectInput();
    return state;
}

int readValue(float* e)
{
    return scanf("%f", e) == CORRECT_INPUT;
}

int checkInput(float e)
{
    return e > 0;
}

float countSum(float e)
{
    float sum = 1;
    float res = 1;
    int b = 0;
    while(fabs(res) > e)
    {
        b += 1;
        res = res * (-1) / b;
        sum = sum + res;
    }
    return sum;
}

void printResult(float result)
{
    printf("%f\n", result);
}

void printIncorrectInput()
{
    printf("Incorrect input\n");
}


