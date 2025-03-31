//Пользователь вводит размер массива и значения его элементов с клавиатуры,
//если размер не равен нулю. Память под массив выделяется динамически
//причём ровно один раз. Необходимо сгруппировать и отсортировать исходный
//массив следующим образом:

//2 вар. положительные по убыванию, нули, отрицательные по возрастанию

#include <stdio.h>
#include <stdlib.h>

enum Status
{
    CORRECT,
    ERROR
};

enum
{
    CORRECT_INPUT = 1
};

int calculateProgramStatus();
int readSizeOfArray(int* size);
int checkTheCondition(int size);
int inputMas(int* array, int size);
int* memoryAllocate(int size);
void freeMemory(int* array);
void swap(int* a, int* b);
int calculateFirstNegativeIndex(int* array, int size);
void sort(int* array, int size, int (*compare)(int, int));
int comparePositive(int a, int b);
int compareNegative(int a, int b);
void printResult(int* array, int size);
void printIncorrectInput();

int main()
{
    return calculateProgramStatus();
}

int calculateProgramStatus()
{
    enum Status state = ERROR;
    int size;
    if (readSizeOfArray(&size) && checkTheCondition(size))
    {
        int* array = memoryAllocate(size);
        if (array != NULL && inputMas(array, size))
        {
            state = CORRECT;
            sort(array, size, comparePositive);
            int firstNegativeIndex = calculateFirstNegativeIndex(array, size);
            if (firstNegativeIndex < size)
                sort(array + firstNegativeIndex, size - firstNegativeIndex, compareNegative);
            printResult(array, size);
            freeMemory(array);
        }
        else
            printIncorrectInput();
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
    return size >= 0;
}

int* memoryAllocate(int size)
{
    return (int*) malloc(sizeof(int) * size);
}

void freeMemory(int* array)
{
    free(array);
}

int inputMas(int* array, int size)
{
    int readValues = 0;
    for (int i = 0; i < size; i++)
        readValues += scanf("%d", array + i);

    return readValues == size;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int calculateFirstNegativeIndex(int* array, int size)
{
    int indexOfFirstNegative = size;
    for (int i = 0; i < size; i++)
        if (array[i] < 0)
        {
            indexOfFirstNegative = i;
            break;
        }

    return indexOfFirstNegative;
}

void sort(int* array, int size, int (*compare)(int, int))
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (compare(array[j], array[j + 1]))
                swap(array + j, array + j + 1);
}

int comparePositive(int a, int b)
{
    return a < b;
}

int compareNegative(int a, int b)
{
    return a > b;
}

void printResult(int* array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void printIncorrectInput()
{
    printf("Incorrect input\n");
}


