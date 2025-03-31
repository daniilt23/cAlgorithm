#include "rectangle.h"

Rectangle::Rectangle(std::string name, float XrectangleUpperLeftCorner, float YrectangleUpperLeftCorner,
    float XrectangleLowerRightcorner, float YrectangleLowerRightcorner): Figure(name)
{
    this->XupperLeftCorner = XrectangleUpperLeftCorner;
    this->YupperLeftCorner = YrectangleUpperLeftCorner;
    this->XlowerRightcorner = XrectangleLowerRightcorner;
    this->YlowerRightcorner = YrectangleLowerRightcorner;
}

void Rectangle::display()
{
    std::cout << "Type: " << type() << ", Name: " << name << ", Coordinate of upper left corner: (" << XupperLeftCorner << ", " <<
         YupperLeftCorner << "), Coordinate of lower right corner: (" << XlowerRightcorner << ", " <<
             YlowerRightcorner << ")" << std::endl;
}

void Rectangle::displayWithS()
{
    std::cout << "Type: " << type() << ", Square: " << getSquare()
        << std::endl;
}

std::string Rectangle::type() const
{
    return "rectangle";
}

float Rectangle::getSquare()
{
    float width = XlowerRightcorner - XupperLeftCorner;
    float height = YupperLeftCorner - YlowerRightcorner;

    return width * height;
}
