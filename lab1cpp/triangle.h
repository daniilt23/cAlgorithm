#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"

class Triangle : public Figure
{
private:
    float XfirstPoint;
    float YfirstPoint;
    float XsecondPoint;
    float YsecondPoint;
    float XthirdPoint;
    float YthirdPoint;

public:
    Triangle(std::string triangleName, float rectangleXfirstPoint, float rectangleYfirstPoint,
        float rectangleXsecondPoint, float rectangleYsecondPoint,
            float rectangleXthirdPoint, float rectangleYthirdPoint);
    void display() override;
    void displayWithS() override;
    float getSquare() override;
    std::string type() const override;
};

#endif // TRIANGLE_H
