/* C Primer Plus. Programming Exercise 11.6
 * Write a function called is_within() that takes a character and a string pointer as its two
 * function parameters. Have the function return a nonzero value (true) if the character is
 * in the string and zero (false) otherwise. Test the function in a complete program that uses
 * a loop to provide input values for feeding to the function.
 */
#include <stdio.h>
#define SIZE 100
#define true 1
#define false 0

int is_within(int ch, const char *str);

int main(void)
{
    char str[SIZE + 1];
    int i;
    char ch;
    int isfound;
    i = 0;

    printf("Enter some characters:\n");
    while (i < SIZE && (ch = getchar()) != EOF && ch != '\n')
    {
        str[i] = ch;
        i++;
    }
    str[i] = '\0';

    while (*str != '\0')
    {
        printf("Enter the character to look for:\n");
        ch = getchar();
        while (getchar() != '\n');
        isfound = is_within(ch, str);
        if(!isfound)
            printf("Letter '%c' was not found in '%s'\n", ch, str);
        else
            printf("Found '%c' in '%s'\n", ch, str);
        printf("Enter some characters (empty line to quit): \n");
        i = 0;
        while (i < SIZE && (ch = getchar()) != EOF && ch != '\n')
        {
            str[i] = ch;
            i++;
        }
        str[i] = '\0';
    }
    printf("Done!\n");
    return 0;
}

int is_within(int ch, const char *str)
{
    while(*str != ch && *str != '\0')
        str++;
    if(*str == '\0' && ch != '\0')
        return false;
    return true;
}