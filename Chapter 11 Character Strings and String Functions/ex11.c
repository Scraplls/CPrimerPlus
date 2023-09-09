/* C Primer Plus. Programming Exercise 11.11
 * Write a program that reads in up to 10 strings or to EOF, whichever comes first. Have it
 * offered the user a menu with five choices: print the original list of strings, print the strings
 * in ASCII collating sequence, print the strings in order of increasing length, print the
 * strings in order of the length of the first word in the string, and quit. Have the menu
 * recycle until the user enters the quit request. The program, of course, should actually
 * perform the promised tasks.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIM 5
#define SIZE 40

char* getss(char* s, int n);
char getchoice(void);
void printstrs(char* s[], int n);
void printascii(char* s[], int n);
void printlen(char* s[], int n);
void printfirstwrd(char* s[], int n);
int firstwrd(char* s);

int main(void)
{
    char str[LIM][SIZE];
    char* sptr[LIM];
    int row = 0;
    char choice;

    printf("Enter up to %d strings to work with:\n", LIM);
    while (row < LIM && getss(str[row], SIZE) != NULL)
    {
        sptr[row] = str[row];
        row++;
    }
    while((choice = getchoice()) != 'q')
    {
        printf("\n");
        switch (choice)
        {
            case 'a': printstrs(sptr, row);
                break;
            case 'b':
                printascii(sptr, row);
                break;
            case 'c':
                printlen(sptr, row);
                break;
            case 'd':
                printfirstwrd(sptr, row);
                break;
            default:
                break;
        }
        printf("\n");
    }
    printf("Done.\n");

    return 0;
}

char getchoice(void)
{
    char ch;

    printf("a) print the sourse strings.        b) print in order of ASCII.\n");
    printf("c) print in order of length.        d) print in order of the first word's length.\n");
    printf("q) quit.\n");
    printf("Enter a character (a, b, c, d or q):");
    ch = getchar();
    while (getchar() != '\n')
        continue;
    while (ch < 'a' || ch > 'd' && ch != 'q')
    {
        printf("Please enter the right option (a, b, c, d or q): ");
        ch = getchar();
        while (getchar() != '\n')
            continue;
    }
    return ch;
}

void printstrs(char* s[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        puts(s[i]);
}

void printascii(char* s[], int n)
{
    int i, j;
    char * temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (strcmp(s[i], s[j]) > 0)
            {
                temp = s[j];
                s[j] = s[i];
                s[i] = temp;
            }
    printstrs(s, n);
}

void printlen(char* s[], int n)
{
    int i, j;
    char * temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (strlen(s[i]) > strlen(s[j]))
            {
                temp = s[j];
                s[j] = s[i];
                s[i] = temp;
            }
    printstrs(s, n);
}

void printfirstwrd(char* s[], int n)
{
    int i, j;
    char * temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (firstwrd(s[i]) > firstwrd(s[j]))
            {
                temp = s[j];
                s[j] = s[i];
                s[i] = temp;
            }
    printstrs(s, n);
}

int firstwrd(char* s)
{
    int i = 0;
    int count = 0;

    while (!isalpha(s[i]))
        i++;
    while (isalpha(s[i]))
    {
        i++;
        count++;
    }

    return count;
}

char* getss(char* s, int n)
{
    int i = 0;
    if (fgets(s, n, stdin) != NULL)
    {
        while (s[i] != '\n' && s[i] != '\0')
            i++;
        if (s[i] == '\n')
            s[i] = '\0';
        return s;
    }
    else
        return NULL;
}