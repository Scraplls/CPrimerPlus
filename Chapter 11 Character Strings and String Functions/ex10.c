/* C Primer Plus. Programming Exercise 11.10
 * Write a function that takes a string as an argument and removes the spaces from the
 * string. Test it in a program that uses a loop to read lines until you enter an empty line.
 * The program should apply the function to each input string and display the result.
 */
#include <stdio.h>
#define SIZE 40
char* remspaces(char* dst, char* src);

int main(void)
{
    char src[SIZE];
    char dst[SIZE];

    puts("Enter a string to remove spaces (empty line to quit): ");
    gets(src);
    while (*src != '\0')
    {
        remspaces(dst, src);
        printf("Modified string: %s\n", dst);
        puts("Enter a string to remove spaces (empty line to quit): ");
        gets(src);
    }

    return 0;
}

char* remspaces(char* dst, char* src)
{
    while (*src != '\0')
    {
        if(*src != ' ')
            *dst++ = *src;
        src++;
    }
}