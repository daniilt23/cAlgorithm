#ifndef IO_H
#define IO_H
#include <stdio.h>
#include <other.h>
#include "struct.h"

void showMenu();
void enterNumberPlease();
void printCannotOpenFile();
void printCarClassError();
void printCarFoundationError();
void printNoCars();
void feedback();
void readBrand(char* brand);
void writeToFile(FILE* file, Car newCar);

#endif // IO_H
