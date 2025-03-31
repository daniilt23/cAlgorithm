#include "action.h"
#include "io.h"
#include "figureexception.h"

vector<Figure*> figures;

void addFigure()
{
    int action;
    cout << "\n";
    showMenuForAdd();
    cin >> action;
    if (action == ONE)
        addCircle();
    else if (action == TWO)
        addRectangle();
    else if (action == THREE)
        addTriangle();
}

void addCircle()
{
    std::string name;
    float centerX, centerY, radius;
    inputCircle();
    cout << "Enter circle name:" << endl;
    cin >> name;
    cout << "Enter the X coordinate of the center of the circle:" << endl;
    cin >> centerX;
    cout << "Enter the Y coordinate of the center of the circle:" << endl;
    cin >> centerY;
    cout << "Enter the radius of the circle:" << endl;
    cin >> radius;
    try
    {
        Circle* circle = new Circle(name, centerX, centerY, radius);
        figures.push_back(circle);
    }
    catch (const InvalidCircleException& e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

void addRectangle()
{
    std::string name;
    float XupperLeftCorner, YupperLeftCorner, XlowerRightCorner, YlowerRightCorner;
    inputRectangle();
    cout << "Enter rectangle name:" << endl;
    cin >> name;
    cout << "Enter the X coordinate of upper left corner of the rectangle:" << endl;
    cin >> XupperLeftCorner;
    cout << "Enter the Y coordinate of upper left corner of the rectangle:" << endl;
    cin >> YupperLeftCorner;
    cout << "Enter the X coordinate of lower right corner of the rectangle:" << endl;
    cin >> XlowerRightCorner;
    cout << "Enter the Y coordinate of lower right corner of the rectangle:" << endl;
    cin >> YlowerRightCorner;
    Rectangle* rectangle = new Rectangle(name, XupperLeftCorner, YupperLeftCorner, XlowerRightCorner, YlowerRightCorner);
    figures.push_back(rectangle);
}

void addTriangle()
{
    std::string name;
    float XfirstPoint, YfirstPoint, XsecondPoint, YsecondPoint, XthirdPoint, YthirdPoint;
    void inputTriangle();
    cout << "Enter triangle name:" << endl;
    cin >> name;
    cout << "Enter the X coordinate of the first triangle point:" << endl;
    cin >> XfirstPoint;
    cout << "Enter the Y coordinate of the first triangle point:" << endl;
    cin >> YfirstPoint;
    cout << "Enter the X coordinate of the second triangle point:" << endl;
    cin >> XsecondPoint;
    cout << "Enter the Y coordinate of the second triangle point:" << endl;
    cin >> YsecondPoint;
    cout << "Enter the X coordinate of the third triangle point:" << endl;
    cin >> XthirdPoint;
    cout << "Enter the Y coordinate of the third triangle point:" << endl;
    cin >> YthirdPoint;
    Triangle* triangle = new Triangle(name, XfirstPoint,YfirstPoint, XsecondPoint, YsecondPoint, XthirdPoint, YthirdPoint);
    figures.push_back(triangle);
}

void takeAllFigures()
{
    inputAllFigures();
    int count = 1;
    for (const auto& obj : figures)
    {
        std::cout << count << ") ";
        obj->display();
        count++;
    }
    cout << endl;
}

void takeAllFiguresWithS()
{
    inputAllFiguresWithS();
    int count = ONE;
    for (const auto& obj : figures)
    {
        std::cout << count << ") ";
        obj->displayWithS();
        count++;
    }
    cout << endl;
}

void takeAllFiguresSquare()
{
    inputSumSquare();
    float sum = 0;
    for (const auto& obj : figures)
        sum += obj->getSquare();

    cout << "Sum of the square of all figures: " << sum << endl;
}

int compareBySquare(Figure* figure1, Figure* figure2)
{
    return figure1->getSquare() < figure2->getSquare();
}

void sortFigureBySquare()
{
    std::sort(figures.begin(), figures.end(), compareBySquare);
    cout << "The figures is completely sorted" << endl;
}

void deleteFigureByNumber()
{
    inputDeleteFigureById();
    unsigned int number;
    cout << "Enter the number of figure to delete from 1 to " << figures.size() << endl;
    cin >> number;
    delete figures[number - 1];
    figures.erase(figures.begin() + number - 1);
    cout << "Figure with number " << number << " correctly deleted" << endl;
}

void deleteFigureBySquare()
{
    inputDeleteFigureBySquare();
    float square;
    cout << "Enter the area value starting from which you want to delete: " << endl;
    cin >> square;
    for (auto obj = figures.begin(); obj != figures.end(); )
    {
        if ((*obj)->getSquare() > square)
        {
            delete *obj;
            obj = figures.erase(obj);
        }
        else
            obj++;
    }
}

