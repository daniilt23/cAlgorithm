#include "other.h"

int realizeProgram()
{
    char* filename = "C:\\Users\\User\\Desktop\\cars.txt.txt";
    int choice = 0;
    while (choice != EXIT)
    {
        showMenu();
        if (readValue(&choice) != 1 || checkChoiceCondition(choice) != 1)
            enterNumberPlease();
        else
            makeChoice(choice, filename);
    }
    if (choice == EXIT)
        feedback();

    return 0;
}

void makeChoice(enum Option choice, char* filename)
{
    switch (choice)
    {
        case ADD:
            addCar(filename);
            break;
        case TAKE:
            takeCars(filename);
            break;
        case DELETE:
        {
            deleteLogic(filename);
            break;
        }
         case SORT:
             sortCars(filename);
             break;
         default:
             break;
    }
}

void deleteLogic(char* filename)
{
    char brand[SIZE];
    readBrand(brand);
    deleteCarByBrand(filename, brand);
}

int countLines(FILE* file)
{
    int line_count = 0;
    char c;
    do
    {
        c = getc(file);
        if (c == '\n')
            line_count++;
    }
    while(c != EOF);
    rewind(file);
    c = getc(file);
    if (c != EOF && line_count == 0)
        line_count++;

    return line_count;
}

void swap(Car* car1, Car* car2)
{
    Car temp = *car1;
    *car1 = *car2;
    *car2 = temp;
}
