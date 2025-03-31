#include "condition.h"

int readValue(int* choice)
{
    int result = scanf("%d", choice);
    if (result != 1)
        while (getchar() != '\n');
    return result;
}


int checkChoiceCondition(int choice)
{
    return choice < 6 && choice > 0;
}

void loopForFoundationAndClass(Car* newCar)
{
    while(1)
    {
        if (scanf("%d", &newCar->foundation) == 1)
            break;
        else
        {
            printCarFoundationError();
            getchar();
        }
    }
    printf("Enter car class: ");
    while(1)
    {
        if (scanf("%d", &newCar->class) == 1)
            break;
        else
        {
            printCarClassError();
            getchar();
        }
    }
}
