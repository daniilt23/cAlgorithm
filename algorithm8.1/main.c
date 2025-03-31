#include "mystring.h"

int main()
{
    char* str = getString();
    printStr(str);
    distribute(str);
    printStr(str);
    freeMemory(str);

    return 0;
}

