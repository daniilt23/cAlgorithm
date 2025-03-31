#include "mystring.h"

enum Status
{
    CORRECT,
    ERROR
};

int main()
{
    enum Status state = ERROR;
    int rowCount;
    if (readValue(&rowCount) && checkRowCountCondition(rowCount))
    {
        char** mat = allocateMemoryForMatrix(rowCount);
        if (mat && inputMatrix(mat, rowCount))
        {
            state = CORRECT;
            char* end1 = getString();
            char* end2 = getString();
            replace(mat, rowCount, end1, end2);
            printChangeFio(mat, rowCount);
            freeMemoryForStr(end1);
            freeMemoryForStr(end2);
            freeMemoryForMat(mat, rowCount);
        }
        else
        {
            incorrectInput();
            if (mat)
                freeMemoryForMat(mat, rowCount);
        }
    }
    else
        incorrectInput();

    return state;
}
