#include "io.h"
#include "interface.h"
#include "action.h"

using namespace std;

int main()
{
    int action = 0;
    while (action != EIGHT)
    {
        showmenu();
        cin >> action;
        if (action == ONE)
            addFigure();
        else if (action == TWO)
            takeAllFigures();
        else if (action == THREE)
            takeAllFiguresWithS();
        else if (action == FOUR)
            takeAllFiguresSquare();
        else if (action == FIVE)
            sortFigureBySquare();
        else if (action == SIX)
            deleteFigureByNumber();
        else if (action == SEVEN)
            deleteFigureBySquare();
    }

    return 0;
}
