#include <cmath>
#include "circle.h"
#include "figureexception.h"

Circle::Circle(std::string name, float circleCenterX, float circleCenterY, float circleRadius): Figure(name)
{
    if (circleRadius <= 0)
        throw InvalidCircleException("Radius must be positive number.");
    this->radius = circleRadius;
    this->centerX = circleCenterX;
    this->centerY = circleCenterY;
}

void Circle::display()
{
    std::cout << "Type: " << type() <<", Name: " << name << ", Coordinate (" << centerX << ", " <<
         centerY << ")" << ", Radius: " << radius << std::endl;
}

void Circle::displayWithS()
{
    std::cout << "Type: " << type() << ", Square: " << getSquare() << std::endl;
}

std::string Circle::type() const
{
    return "circle";
}

float Circle::getSquare()
{
    return M_PI * radius * radius;
}
