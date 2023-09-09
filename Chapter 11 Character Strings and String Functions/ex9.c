/* C Primer Plus. Programming Exercise 11.9
 * Write a function that replaces the contents of a string with the string reversed. Test the
 * function in a complete program that uses a loop to provide input values for feeding to
 * the function.
 */
#include <stdio.h>
#include <string.h>
#define SIZE 40
void strr(char* str);

int main(void)
{
    char str[SIZE];

    puts("Enter a string to reverse (empty line to quit): ");
    gets(str);
    while (*str != '\0')
    {
        strr(str);
        printf("Reversed string is %s\n", str);
        puts("Enter a string to reverse (empty line to quit): ");
        gets(str);
    }
    return 0;
}

void strr(char* str)
{
    int i, n;
    char tmp;
    i = 0;
    n = strlen(str);
    while (i < n/2)
    {
        tmp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = tmp;
        i++;
    }
}