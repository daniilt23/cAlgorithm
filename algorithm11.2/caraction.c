#include "caraction.h"

void addCar(char filename[SIZE])
{
    Car newCar;
    FILE* file = openFileToWrite(filename);
    if (file == NULL)
        printCannotOpenFile();
    getchar();
    for (int i = 0; i < 1; i++)
    {
        printf("Enter car company: ");
        fgets(newCar.company, SIZE, stdin);
        printf("Enter car brand: ");
        fgets(newCar.brand, SIZE, stdin);
        printf("Enter car date of foundation: ");
        loopForFoundationAndClass(&newCar);
        getchar();
        writeToFile(file, newCar);
    }
    closeFile(file);
}

void takeCars(char* filename)
{
    FILE* file = openFileToRead(filename);
    if (file == NULL)
        printCannotOpenFile();
    int countOfStruct = countLines(file) / FOUR;
    Car* cars = (Car*)malloc(countOfStruct * sizeof(Car));
    if (countOfStruct == 0)
        printNoCars();
    rewind(file);
    for (int i = 0; i < countOfStruct; i++)
    {
        fgets(cars[i].company, SIZE, file);
        fgets(cars[i].brand, SIZE, file);
        fscanf(file, "%d\n", &cars[i].foundation);
        fscanf(file, "%d\n", &cars[i].class);
    }
    for (int i = 0; i < countOfStruct; i++)
    {
        printf("Car: %d\n", i + 1);
        printf("Company: %s", cars[i].company);
        printf("Brand: %s", cars[i].brand);
        printf("Foundation year: %d\n", cars[i].foundation);
        printf("Class: %d\n\n", cars[i].class);
    }
    closeFile(file);
    free(cars);
}


void deleteCarByBrand(char* filename, const char* brand)
{
    FILE* file = openFileToRead(filename);
    int countOfStruct = countLines(file) / FOUR;
    Car* cars = (Car*)malloc(countOfStruct * sizeof(Car));
    rewind(file);
    for (int i = 0; i < countOfStruct; i++)
    {
        fgets(cars[i].company, SIZE, file);
        fgets(cars[i].brand, SIZE, file);
        fscanf(file, "%d\n", &cars[i].foundation);
        fscanf(file, "%d\n", &cars[i].class);
    }
    fclose(file);
    int newCount = 0;
    for (int i = 0; i < countOfStruct; i++)
    {
        cars[i].brand[strcspn(cars[i].brand, "\n")] = 0;
        if (strcmp(cars[i].brand, brand) != 0)
            cars[newCount++] = cars[i];
    }
    FILE* openFile = openFileToWriteW(filename);
    for (int i = 0; i < newCount; i++)
    {
        fputs(cars[i].company, openFile);
        fputs(cars[i].brand, openFile);
        fprintf(openFile, "\n%d\n", cars[i].foundation);
        fprintf(openFile, "%d\n", cars[i].class);
    }
    closeFile(openFile);
    free(cars);
}

void sortCars(char* filename)
{
    FILE* file = openFileToRead(filename);
    int countOfStruct = countLines(file) / FOUR;
    Car* cars = (Car*)malloc(sizeof(Car) * countOfStruct);
    rewind(file);
    for (int i = 0; i < countOfStruct; i++)
    {
        fgets(cars[i].company, SIZE, file);
        fgets(cars[i].brand, SIZE, file);
        fscanf(file, "%d\n", &cars[i].foundation);
        fscanf(file, "%d\n", &cars[i].class);
    }
    closeFile(file);
    for (int i = 0; i < countOfStruct; i++)
        for (int j = 0; j < countOfStruct - 1 - i; j++)
        {
            if (strcmp(cars[j].company, cars[j + 1].company) > 0)
                swap (cars + j, cars + j + 1);
        }
    FILE* openFile = openFileToWriteW(filename);
    for (int i = 0; i < countOfStruct; i++)
    {
        fputs(cars[i].company, openFile);
        fputs(cars[i].brand, openFile);
        fprintf(openFile, "%d\n", cars[i].foundation);
        fprintf(openFile, "%d\n", cars[i].class);
    }
    closeFile(openFile);
    free(cars);
}
