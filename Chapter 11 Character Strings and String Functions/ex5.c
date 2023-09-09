/* C Primer Plus. Programming Exercise 11.5
 * Design and test a function that searches the string specified by the first function
 * parameter for the first occurrence of a character specified by the second function
 * parameter. Have the function return a pointer to the character if successful, and a null
 * if the character is not found in the string. (This duplicates the way that the library
 * strchr() function works.) Test the function in a complete program that uses a loop to
 * provide input values for feeding to the function.
 */
#include <stdio.h>
#define SIZE 100
const char *strchr(const char *str, int ch);

int main(void)
{
    char str[SIZE + 1];
    int i;
    char ch;
    const char *chp;
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
        chp = strchr(str, ch);
        if(chp == NULL)
            printf("Letter '%c' was not found in '%s'\n", ch, str);
        else
            printf("Found '%c' starting at '%s'\n", ch, chp);
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

const char *strchr(const char *str, int ch)
{
    while(*str != ch && *str != '\0')
        str++;
    if(*str == '\0' && ch != '\0')
        return NULL;
    return str;
}