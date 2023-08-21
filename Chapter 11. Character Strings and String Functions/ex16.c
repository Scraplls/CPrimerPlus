/* C Primer Plus. Programming Exercise 11.16
 * Write a program that reads input until end-of-file and echoes it to the display. Have the
 * program recognize and implement the following command-line arguments:
 * -p Print input as is
 * -u Map input to all uppercase
 * -l Map input to all lowercase
 * Also, if there are no command-line arguments, let the program behave as if the –p
 * argument had been used.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
void getstr(char str[]);

int main(int argc, char** argv)
{
    int i;
    char str[SIZE + 1];

    i = 0;
    getstr(str);

    if(argc < 2 || strcmp(argv[1], "-p") == 0)
    {
        while (*(str + i) != '\0')
            putchar(*(str + i++));
    }
    else if(strcmp(argv[1], "-u") == 0)
    {
        while (*(str + i) != '\0')
            putchar(toupper(*(str + i++)));
    }
    else if(strcmp(argv[1], "-l") == 0)
    {
        while (*(str + i) != '\0')
            putchar(tolower(*(str + i++)));
    }

    return 0;
}

void getstr(char str[])
{
    int i;
    char ch;
    i = 0;
    while (i < SIZE && (ch = getchar()) != EOF && ch != '\n')
        str[i++] = ch;
    str[i] = '\0';
}
