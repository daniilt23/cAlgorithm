#include <stdio.h>
#include <stdlib.h>

enum
{
    CORRECT_INPUT = 1
};

enum Status
{
    CORRECT,
    ERROR
};

int calculateProgramStatus();
int readSizeOfMatrix(int* size);
int checkTheConditionOfSize(int size);
int** memoryAllocateForMatrix(int size, int column);
void freeMemory(int** mat);
void transform(int** mat, int* vec, int size);
int inputMat(int size, int** matrix);
void swap(int* a, int* b);
void transposeMatrix(int** matrix, int size);
void printResult(int** matrix, int size);
void printIncorrectInput();

int main()
{
    return calculateProgramStatus();
}

int calculateProgramStatus()
{
    enum Status state = ERROR;
    int size = 0;
    if (readSizeOfMatrix(&size) && checkTheConditionOfSize(size))
    {
        int** matrix = memoryAllocateForMatrix(size, size);
        if (matrix != NULL && inputMat(size, matrix))
        {
            state = CORRECT;
            transposeMatrix(matrix, size);
            printResult(matrix, size);
            freeMemory(matrix);
        }
        else
        {
            printIncorrectInput();
            if (matrix != NULL)
                freeMemory(matrix);
        }
    }
    else
        printIncorrectInput();

    return state;
}

int readSizeOfMatrix(int* size)
{
    return scanf("%d", size) == CORRECT_INPUT;
}

int checkTheConditionOfSize(int size)
{
    return size >= 0;
}

int** memoryAllocateForMatrix(int sizeX, int sizeY)
{
    int** mat = (int**) malloc(sizeof(int*) * sizeY);
    int* vec = NULL;
    if(mat != NULL)
    {
        vec = (int*) malloc(sizeof(int) * sizeX * sizeY);
        if (vec == NULL)
        {
            free(mat);
            mat = NULL;
        }
        else
            transform(mat, vec, sizeX);
    }

    return mat;
}

void freeMemory(int** mat)
{
        free(*mat);
        free(mat);
}

void transform(int** mat, int* vec, int size)
{
    for (int i = 0; i < size; i++)
        mat[i] = vec + i * size;
}

int inputMat(int size, int** matrix)
{
    int readValues = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            readValues += scanf("%d", matrix[i] + j);

    return readValues == size * size;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void transposeMatrix(int** matrix, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1; j++)
            swap(matrix[i] + j, matrix[size - 1 - j] + size - 1 - i);
}

void printResult(int** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%d ", *(*(matrix + i) + j));
        printf("\n");
    }
}

void printIncorrectInput()
{
    printf("Incorrect input");
}
