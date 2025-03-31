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

int calculateProgramStatus();
int readSizeOfMatrix(int* sizeY, int* sizeX);
int checkSizeCondition(int sizeX, int sizeY);
int** memoryAllocateForMatrix(int sizeX, int sizeY);
void freeMemory(int** mat);
void transform(int** mat, int* vec, int sizeX, int sizeY);
int inputMat(int** matrix, int sizeX, int sizeY);
int calculateSumUnderSideDiagonal(int** matrix, int sizeX, int sizeY);
void replacingElements(int** matrix, int sum);
void printResult(int** matrix, int sizeX, int sizeY);
void printIncorrectInput();

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
        if (sizeX == 0 || sizeY == 0)
            state = CORRECT;
        else
        {
            int** matrix = memoryAllocateForMatrix(sizeX, sizeY);
            if (matrix != NULL && inputMat(matrix, sizeX, sizeY))
            {
                state = CORRECT;
                int sum = calculateSumUnderSideDiagonal(matrix, sizeX, sizeY);
                replacingElements(matrix, sum);
                printResult(matrix, sizeX, sizeY);
                freeMemory(matrix);
            }
            else
            {
                printIncorrectInput();
                if (matrix != NULL)
                    freeMemory(matrix);
            }
        }
    }
    else
        printIncorrectInput();

    return state;
}

int readSizeOfMatrix(int* sizeY, int* sizeX)
{
    return scanf("%d %d", sizeY, sizeX) == CORRECT_INPUT;
}

int checkSizeCondition(int sizeX, int sizeY)
{
    return sizeY >= 0 && sizeX >= 0;
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
            transform(mat, vec, sizeX, sizeY);
    }

    return mat;
}

void transform(int** mat, int* vec, int sizeX, int sizeY)
{
    for (int i = 0; i < sizeY; i++)
    mat[i] = vec + i * sizeX;
}

void freeMemory(int** mat)
{
    free(*mat);
    free(mat);
}

int inputMat(int** matrix, int sizeX, int sizeY)
{
    int readValues = 0;
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
            readValues += scanf("%d", *(matrix + i) + j);
    }

    return readValues == sizeX * sizeY;
}

int calculateSumUnderSideDiagonal(int** matrix, int sizeX, int sizeY)
{
    int sum = 0;
    for (int i = 0; i < sizeY; i++)
        for (int j = 0; j < sizeX; j++)
            if (i + j > sizeY - 1)
                sum += *(*(matrix + i) + j);

    return sum;
}

void replacingElements(int** matrix, int sum)
{
    matrix[0][0] = sum;
}

void printResult(int** matrix, int sizeX, int sizeY)
{
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void printIncorrectInput()
{
    printf("Incorrect input\n");
}





