#include <stdio.h>
#include <stdlib.h>

enum Status
{
    CORRECT,
    ERROR
};

enum
{
    CORRECT_INPUT = 2
};

enum Shift
{
    UP,
    LEFT,
    DOWN,
    RIGHT
};

int calculateProgramStatus();
int readSizeOfMatrix(int* sizeY, int* sizeX);
int checkSizeCondition(int sizeX, int sizeY);
int** allocateMemory(int sizeY, int sizeX);
int inputMatrix(int** matrix, int sizeX, int sizeY);
void printMatrix(int** matrix, int sizeX, int sizeY);
void swap(int* pa, int* pb);
void transform(int** matrix, int* vec, int sizeX, int sizeY);
void freeMemory(int** matrix);
void incorrectInput();
void sortMas(int* mas, int size);
void reverseRows(int* mas, int sizeX, int sizeY);
void reverseRow(int* mas, int sizeX);

int main()
{
    return calculateProgramStatus();
}

int calculateProgramStatus()
{
    enum Status state = ERROR;
    int sizeX, sizeY;
    if (readSizeOfMatrix(&sizeY, &sizeX) && checkSizeCondition(sizeX, sizeY))
    {
        int** matrix = allocateMemory(sizeX, sizeY);
        if (matrix && inputMatrix(matrix, sizeX, sizeY))
        {
            state = CORRECT;
            int size = sizeX * sizeY;
            sortMas(*matrix, size);
            reverseRows(*matrix, sizeX, sizeY);
            printMatrix(matrix, sizeX, sizeY);
            freeMemory(matrix);
        }
        else
        {
            incorrectInput();
            if (matrix)
                freeMemory(matrix);
        }
    }
    else
        incorrectInput();

    return state;
}

int readSizeOfMatrix(int* sizeY, int* sizeX)
{
    return scanf("%d %d", sizeY, sizeX) == CORRECT_INPUT;
}

int checkSizeCondition(int sizeX, int sizeY)
{
    return sizeX > 0 && sizeY > 0;
}

int** allocateMemory(int sizeX, int sizeY)
{
    int** matrix = (int**) malloc(sizeof(int*) * sizeY);
    int* vec = NULL;
    if (matrix != NULL)
    {
        vec = (int*) malloc(sizeof(int) * sizeX * sizeY);
        if (vec == NULL)
        {
            free(matrix);
            matrix = NULL;
        }
        else
            transform(matrix, vec, sizeX, sizeY);
    }

    return matrix;
}

int inputMatrix(int** matrix, int sizeX, int sizeY)
{
    int readValues = 0;
    for (int i = 0; i < sizeY; i++)
        for (int j = 0; j < sizeX; j++)
            readValues += scanf("%d", matrix[i] + j);

    return readValues == sizeX * sizeY;
}

void sortMas(int* vec, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
        {
            if (vec[j] < vec[j + 1])
                swap(vec + j, vec + j + 1);
        }
}

void reverseRow(int* mas, int sizeX)
{
    for (int j = 0; j < sizeX / 2; j++)
        swap(mas + j, mas + sizeX - 1 - j);
}

void reverseRows(int* mas, int sizeX, int sizeY)
{
    for (int i = sizeY - 2; i >= 0; i -= 2)
        reverseRow(mas + i * sizeX, sizeX);
}

void printMatrix(int** matrix, int sizeX, int sizeY)
{
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void swap(int* pa, int* pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void transform(int** matrix, int* vec, int sizeX, int sizeY)
{
    for (int i = 0; i < sizeY; i++)
        matrix[i] = vec + i * sizeX;
}

void freeMemory(int** matrix)
{
    free(*matrix);
    free(matrix);
}

void incorrectInput()
{
    printf("Incorrect input\n");
}
