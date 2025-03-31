#ifndef FIGUREEXCEPTION_H
#define FIGUREEXCEPTION_H
#include <iostream>

class FigureException : public std::runtime_error
{
public:
    explicit FigureException(const std::string& message)
        : std::runtime_error(message) {}
};

class InvalidCircleException : public FigureException
{
public:
    explicit InvalidCircleException(const std::string& message)
        : FigureException(message) {}
};

class InvalidRectangleException : public FigureException
{
public:
    explicit InvalidRectangleException(const std::string& message)
        : FigureException(message) {}
};

class InvalidTriangleException : public FigureException
{
public:
    explicit InvalidTriangleException(const std::string& message)
        : FigureException(message) {}
};

#endif // FIGUREEXCEPTION_H
