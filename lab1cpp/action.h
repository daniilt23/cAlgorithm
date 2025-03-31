#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "figure.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "interface.h"

using namespace std;

enum
{
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8
};

extern vector<Figure*> figures;

void addCircle();
void addRectangle();
void addTriangle();
void takeAllFigures();
void takeAllFiguresWithS();
void sumSquare();
void takeAllFiguresSquare();
int compareBySquare(Figure* figure1, Figure* figure2);
void sortFigureBySquare();
void deleteFigureByNumber();
void deleteFigureBySquare();
void addFigure();

#endif // ACTION_H
