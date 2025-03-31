#include "interface.h"

using namespace std;

void showmenu()
{
    cout << "===============================" << endl;
    cout << "          MAIN MENU            " << endl;
    cout << "===============================" << endl;
    cout << "1) Add figure" << endl;
    cout << "2) Take all figures" << endl;
    cout << "3) Take all figures with square" << endl;
    cout << "4) Take sum all square" << endl;
    cout << "5) Sort figures by square ascending order" << endl;
    cout << "6) Delete figure by id" << endl;
    cout << "7) Delete figures by square" << endl;
    cout << "8) Exit" << endl;
}

void showMenuForAdd()
{
    cout << "===============================" << endl;
    cout << "          ADD FIGURE MENU            " << endl;
    cout << "===============================" << endl;
    cout << "Pick figure that you want to add:" << endl;
    cout << "1) Circle" << endl;
    cout << "2) Rectangle" << endl;
    cout << "3) Triangle" << endl;
}

