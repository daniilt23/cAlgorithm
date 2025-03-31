#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>

class Figure
{
protected:
    std::string name;

public:    
    virtual void display() = 0;
    virtual void displayWithS() = 0;
    virtual float getSquare() = 0;
    virtual std::string type() const = 0;
    virtual ~Figure() = default;
    Figure(std::string name);
};

#endif // FIGURE_H
