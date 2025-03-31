#include "condition.h"

int isFileExist(const char* filename)
{
    FILE *file = fopen(filename, "r");
    int is_open = (file != NULL);
    if (is_open)
        fclose(file);

    return is_open;
}
