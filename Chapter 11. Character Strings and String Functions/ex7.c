/* C Primer Plus. Programming Exercise 11.7
 * The strncpy(s1, s2, n) function copies exactly n characters from s2 to s1, truncating
 * s2 or padding it with extra null characters as necessary. The target string may not be
 * null-terminated if the length of s2 is n or more. The function returns s1. Write your own
 * version of this function; call it mystrncpy(). Test the function in a complete program
 * that uses a loop to provide input values for feeding to the function.
 */
#include <stdio.h>
#define SRC_SIZE 101
#define DST_SIZE 100

char* mystrncpy(char* target, const char* source, int n);

int main(void)
{
    char source[SRC_SIZE];
    char target[DST_SIZE];
    int i;
    int n;
    char ch;
    n = 0;

    i = 0;
    printf("Enter string to copy:\n");
    while (i < SRC_SIZE && (ch = getchar()) != EOF && ch != '\n')
    {
        source[i] = ch;
        i++;
    }
    source[i] = '\0';

    while (*source != '\0')
    {
        printf("Enter the number of characters to copy:\n");
        if(!scanf("%d", &n) || n < 1)
            break;
        while (getchar() != '\n')
            break;
        mystrncpy(target, source, n);
        printf("Copied string: ");

        i = 0;
        while (target[i] != '\0' && i < DST_SIZE)
        {
            putchar(target[i]);
            i++;
        }
        putchar('\n');

        i = 0;
        printf("Enter string to copy:\n");
        while (i < SRC_SIZE && (ch = getchar()) != EOF && ch != '\n')
        {
            source[i] = ch;
            i++;
        }
    }
    printf("Done!\n");
    return 0;
}

char* mystrncpy(char* target, const char* source, int n)
{
    int i;
    i = 0;
    while (i < SRC_SIZE && i < DST_SIZE && i < n && source[i] != '\0')
    {
        target[i] = source[i];
        i++;
    }
    while (i < DST_SIZE)
    {
        target[i] = '\0';
        i++;
    }
    return target;
}