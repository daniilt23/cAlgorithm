#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"

class Rectangle : public Figure
{
private:
    float XupperLeftCorner;
    float YupperLeftCorner;
    float XlowerRightcorner;
    float YlowerRightcorner;

public:
    Rectangle(std::string rectangleName, float XrectangleUpperLeftCorner, float YrectangleUpperLeftCorner,
              float XrectangleLowerRightcorner, float YrectangleLowerRightcorner);
    void display() override;
    void displayWithS() override;
    float getSquare() override;
    std::string type() const override;
};


#endif // RECTANGLE_H
