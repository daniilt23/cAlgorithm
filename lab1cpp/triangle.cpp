#include <math.h>
#include "triangle.h"

Triangle::Triangle(std::string name, float rectangleXfirstPoint, float rectangleYfirstPoint,
    float rectangleXsecondPoint, float rectangleYsecondPoint,
        float rectangleXthirdPoint, float rectangleYthirdPoint) : Figure(name)
{
    this->XfirstPoint = rectangleXfirstPoint;
    this->YfirstPoint = rectangleYfirstPoint;
    this->XsecondPoint = rectangleXsecondPoint;
    this->YsecondPoint = rectangleYsecondPoint;
    this->XthirdPoint = rectangleXthirdPoint;
    this->YthirdPoint = rectangleYthirdPoint;
}

void Triangle::display()
{
    std::cout << "Type: " << type() << ", Name: " << name << ", Coordinate of first point: (" << XfirstPoint << ", " << YfirstPoint <<
        "), Coordinate of second point: (" << XsecondPoint << ", " << YsecondPoint <<
             "), Coordinate of third point: (" << XthirdPoint << ", " << YthirdPoint <<
                 ")" << std::endl;
}

void Triangle::displayWithS()
{
    std::cout << "Type: " << type() << ", Square: " << getSquare()
          << std::endl;
}

std::string Triangle::type() const
{
    return "triangle";
}

float Triangle::getSquare()
{
    float a = sqrt(pow((XfirstPoint - XsecondPoint), 2) +
                   pow((YfirstPoint - YsecondPoint), 2));
    float b = sqrt(pow((XsecondPoint - XthirdPoint), 2) +
                   pow((YsecondPoint - YthirdPoint), 2));
    float c = sqrt(pow((XthirdPoint - XfirstPoint), 2) +
                   pow((YthirdPoint - YfirstPoint), 2));

    float p = (a + b + c) / 2;

    float square = sqrt(p * (p - a) * (p - b) * (p - c));

    return square;
}
