#include "io.h"

void showMenu()
{
    printf("1. Add car\n");
    printf("2. Take all cars\n");
    printf("3. Delete car\n");
    printf("4. Sort cars\n");
    printf("5. Exit\n");
    printf("Pick number from 1 to 5: \n");
}

void enterNumberPlease()
{
    printf("Enter number from 1 to 5 please\n");
}

void printCannotOpenFile()
{
    printf("Cannot open file");
}

void printCarClassError()
{
    printf("Car class need to be a number, try again please\n");
}

void printCarFoundationError()
{
    printf("Car foundation year need to be a number, try again please\n");
}

void printNoCars()
{
    printf("Dont have cars yet\n");
}

void readBrand(char* brand)
{
    printf("Input brand to delete: ");
    scanf("%s", brand);
}

void feedback()
{
    int rating;
    char feedback[SIZE];
    while (1)
    {
        printf("Please, rate our app from 1 to 10: ");
        if (scanf("%d", &rating) == 1 && rating > 0 && rating < 11)
            break;
        else
        {
            printf("Invalid input\n");
            getchar();
        }
    }
    if (rating < 10)
    {
        printf("Describe please what you didn't like: ");
        scanf("%s", feedback);
    }

    printf("Thank you for your feedback, we are waiting for you again!\n");
}

void writeToFile(FILE* file, Car newCar)
{
    fprintf(file, "%s", newCar.company);
    fprintf(file, "%s", newCar.brand);
    fprintf(file, "%d\n", newCar.foundation);
    fprintf(file, "%d\n", newCar.class);
    fprintf(file, "\n");
};
