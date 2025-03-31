#include <stdio.h>
#include <stdlib.h>

enum
{
    CORRECT_INPUT = 1
};

enum
{
    TWO = 2
};

 enum Status
 {
     CORRECT,
     ERROR
 };

int calculateProgramStatus();
int readSizeOfArray(int* size);
int inputMas(int* array, int size);
void printIncorrectInput();
int checkTheCondition(int size);
int* memoryAllocation(int size);
void printResult(int result);
int calculateProd(const int* array, int lastIndexOfMin);
int calculateIndexOfMin(int* array, int size);

int main()
{
    return calculateProgramStatus();
}

int calculateProgramStatus()
{
    int size;
    int* array = NULL;
    enum Status state = ERROR;
    if (readSizeOfArray(&size) && checkTheCondition(size))
    {
        array = memoryAllocation(size);
        if (array != NULL && inputMas(array, size))
        {
            state = CORRECT;
            int lastIndexOfMin = (calculateIndexOfMin(array, size));
            int result = calculateProd(array, lastIndexOfMin);
            printResult(result);
        }
        else
            printIncorrectInput();
        free(array);
    }
    else
        printIncorrectInput();
    return state;
}

int readSizeOfArray(int* size)
{
    return scanf("%d", size) == CORRECT_INPUT;
}

int checkTheCondition(int size)
{
    return size > 0;
}

int* memoryAllocation(int size)
{
    return malloc(sizeof(int) * size);
}

int inputMas(int* array, int size)
{
    int readValues = 0;
    for (int i = 0; i < size; i++)
        readValues += scanf("%d", array + i);
    return readValues == size;
}

int calculateIndexOfMin(int* array, int size)
{
    int lastIndex = 0;
    int minValue = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] <= minValue)
        {
            minValue = array[i];
            lastIndex = i;
        }
    }
    return lastIndex;
}

int calculateProd(const int* array, int lastIndexOfMin)
{
    int prod = 0;
    if (array[lastIndexOfMin] >= 0 && lastIndexOfMin != 0)
    {
        prod = 1;
        for (int i = 0; i < lastIndexOfMin; i++)
        {
            if (array[i] < array[lastIndexOfMin] * TWO)
                prod *= array[i];
        }
    }
    return prod;
}

void printResult(int result)
{
    printf("%d", result);
}

void printIncorrectInput()
{
    printf("Incorrect input");
}
