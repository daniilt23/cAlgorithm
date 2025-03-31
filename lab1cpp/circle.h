#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"

class Circle : public Figure
{
private:
    float centerX;
    float centerY;
    float radius;

public:
    Circle(std::string circleName, float centerX, float centerY, float circleRadius);
    void display() override;
    void displayWithS() override;
    std::string type() const override;
    float getSquare() override;
};

#endif // CIRCLE_H
