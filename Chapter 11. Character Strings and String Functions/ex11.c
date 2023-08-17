/* C Primer Plus. Programming Exercise 11.11
 * Write a program that reads in up to 10 strings or to EOF, whichever comes first. Have it
 * offered the user a menu with five choices: print the original list of strings, print the strings
 * in ASCII collating sequence, print the strings in order of increasing length, print the
 * strings in order of the length of the first word in the string, and quit. Have the menu
 * recycle until the user enters the quit request. The program, of course, should actually
 * perform the promised tasks.
 */
#include <stdio.h>
#define SIZE 10
#define LEN 40

void printstrs(char strs[SIZE][LEN]);
void printascii(char strs[SIZE][LEN]);

int main(void)
{
    char list[SIZE][LEN];
    int i, choice;
    i = 0;

    puts("Enter a string to work with: ");
    while (gets(list[i]) != NULL && i < SIZE)
    {
        i++;
        puts("Enter a string to work with: ");
    }

    printf("Menu selection: \n"
           "1. Print list of strings\n"
           "2. Print list in ASCII order\n"
           "3. Print list in order of increasing length\n"
           "4. Print list in order of first word\n"
           "5. Quit");
    scanf("%d", &choice);
    while (choice != 5)
    {
        switch (choice)
        {
            case 1:
                printstrs(list);
                break;
            case 2:
                printascii(list);
                break;
            case 3:
                printlen(list);
                break;
            case 4:
                printfirst(list);
                break;
            default:
                break;
        }
        printf("Menu selection: \n"
               "1. Print list of strings\n"
               "2. Print list in ASCII order\n"
               "3. Print list in order of increasing length\n"
               "4. Print list in order of first word\n"
               "5. Quit");
        scanf("%d", &choice);
    }
    puts("Done!");
    return 0;
}

void printstrs(char strs[SIZE][LEN])
{
    int i;
    i = 0;
    while (i < SIZE)
        puts(strs[i++]);
}

void printascii(char strs[SIZE][LEN])
{
    
}