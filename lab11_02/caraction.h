#ifndef CARACTION_H
#define CARACTION_H
#include <stdlib.h>
#include <string.h>
#include "other.h"
#include "fileaction.h"
#include "condition.h"
#include "other.h"
#include "menu.h"
#include "io.h"

void addCar(char* filename);
void takeCars(char* filename);
void deleteCarByBrand(char* filename, const char* brand);
void sortCars(char* filename);

#endif // CARACTION_H
