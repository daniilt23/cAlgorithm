#include "file.h"

int calculateProgramStatus()
{
    enum Status state = ERROR;
    char* filename;
    char newFilename[SIZE];
    if (getFileName(filename) && isFileExist(filename))
    {
        FILE* file = openFileToRead(filename);
        if (file)
        {
            int lineCount = countLines(file);
            if (lineCount)
            {
                state = CORRECT;
                char** text = allocateMemoryForText(lineCount);
                readTheData(file, lineCount, text);
                closeFile(file);
                lineCount = deleteEmptyLines(text, lineCount);
                numerationRows(text, lineCount);
                getNewFilename(newFilename);
                FILE* newFile = openFileToWrite(newFilename);
                if (isFileExist(newFilename))
                    fillNewFile(newFile, text, lineCount);
                else
                    printFileNotFound();
                printText(text, lineCount);
                closeFile(newFile);
                freeMemory(text);
            }
            else
                printEmptyFile();
        }
        else
            printCannotOpenFile();
    }
    else
        printFileNotFound();

    return state;
}

int countLines(FILE* file)
{
    int line_count = 0;
    char c;
    do
    {
        c = getc(file);
        if (c == '\n')
            line_count++;
    }
    while(c != EOF);
    rewind(file);
    c = getc(file);
    if (c != EOF && line_count == 0)
        line_count++;

    return line_count;
}

int deleteEmptyLines(char** text, int lineCount)
{
    int newLineCount = 0;
    for (int i = 0; i < lineCount; i++)
    {
        if (strspn(text[i], " \n\t") != strlen(text[i]))
        {
            strcpy(text[newLineCount], text[i]);
            newLineCount++;
        }
    }

    return newLineCount;
}

void numerationRows(char** text, int lineCount)
{
    char rowWithNumeration[SIZE];
    for (int i = 0; i < lineCount; i++)
    {
        snprintf(rowWithNumeration, SIZE, "%d. %s", i + 1, text[i]);
        strcpy(text[i], rowWithNumeration);
    }
}

void fillNewFile(FILE* newFile, char** text, int lineCount)
{
    for (int i = 0; i < lineCount; i++)
        fprintf(newFile, "%s", text[i]);
}
