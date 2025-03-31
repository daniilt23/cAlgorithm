#include "io.h"

void circleInput(std::string &name, float &centerX, float &centerY, float &radius)
{
    cout << "Enter circle name:" << endl;
    cin >> name;
    while (true)
    {
        cout << "Enter the X coordinate of the center of the circle:" << endl;
        cin >> centerX;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input for X coordinate. Please enter a number." << endl;
        }
        else
            break;
    }
    while (true)
    {
        cout << "Enter the Y coordinate of the center of the circle:" << endl;
        cin >> centerY;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input for Y coordinate. Please enter a number." << endl;
        }
        else
            break;
    }
    while (true)
    {
        cout << "Enter the radius of the circle:" << endl;
        cin >> radius;
        if (cin.fail() || radius <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input for radius. Please enter a positive number." << endl;
        }
        else
            break;
    }
}

void rectangleInput(std::string &name, float &XupperLeftCorner, float &YupperLeftCorner, float &XlowerRightCorner, float &YlowerRightCorner)
{
    cout << "Enter rectangle name:" << endl;
    cin >> name;
    while(true)
    {
        cout << "Enter the X coordinate of upper left corner of the rectangle:" << endl;
        cin >> XupperLeftCorner;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input for point. Please enter a number." << endl;
        }
        else
            break;
    }
    while(true)
    {
        cout << "Enter the Y coordinate of upper left corner of the rectangle:" << endl;
        cin >> YupperLeftCorner;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input for point/ Please enter a number." << endl;
        }
        else
            break;
    }
    cin >> YupperLeftCorner;
    cout << "Enter the X coordinate of lower right corner of the rectangle:" << endl;
    cin >> XlowerRightCorner;
    cout << "Enter the Y coordinate of lower right corner of the rectangle:" << endl;
    cin >> YlowerRightCorner;
}

void inputCircle()
{
    cout << "===============================" << endl;
    cout << "          ADD CIRCLE            " << endl;
    cout << "===============================" << endl;
}

void inputRectangle()
{
    cout << "===============================" << endl;
    cout << "          ADD RECTANGLE            " << endl;
    cout << "===============================" << endl;
}

void inputTriangle()
{
    cout << "===============================" << endl;
    cout << "          ADD RIANGLE            " << endl;
    cout << "===============================" << endl;
}

void inputAllFigures()
{
    cout << "===============================" << endl;
    cout << "     TAKE ALL FIGURE MENU            " << endl;
    cout << "===============================" << endl;
}

void inputAllFiguresWithS()
{
    cout << "===============================" << endl;
    cout << "  TAKE ALL FIGURE WITH SQUARE            " << endl;
    cout << "===============================" << endl;
}

void inputSumSquare()
{
    cout << "===============================" << endl;
    cout << "       TAKE SUM SQUARE            " << endl;
    cout << "===============================" << endl;
}

void inputDeleteFigureById()
{
    cout << "===============================" << endl;
    cout << "      DELETE FIGURE BY ID            " << endl;
    cout << "===============================" << endl;
}

void inputDeleteFigureBySquare()
{
    cout << "===============================" << endl;
    cout << "    DELETE FIGURE BY SQUARE            " << endl;
    cout << "===============================" << endl;
}
