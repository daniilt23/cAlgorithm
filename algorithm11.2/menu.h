#ifndef MENU_H
#define MENU_H

enum Option
{
    ADD = 1,
    TAKE,
    DELETE,
    SORT,
    EXIT
};

void makeChoice(enum Option choice, char* filename);

#endif // MENU_H
