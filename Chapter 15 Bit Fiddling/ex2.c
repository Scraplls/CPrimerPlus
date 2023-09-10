/* C Primer Plus. Programming Exercise 15.2
 * Write a program that reads two binary strings as command-line arguments and prints
 * the results of applying the ~ operator to each number and the results of applying the
 * &, |, and ^ operators to the pair. Show the results as binary strings. (If you don’t have a
 * command-line environment available, have the program read the strings interactively.)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        printf("Usage: %s str1 str2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int l1 = strlen(argv[1]);
    int l2 = strlen(argv[2]);
    int i, j;

    printf("~%s = ", argv[1]);
    for(i = 0; argv[1][i] != '\0'; i++)
        printf("%c", (~(argv[1][i] - '0') & 1) + '0');
    printf("\n");

    printf("~%s = ", argv[2]);
    for(i = 0; argv[2][i] != '\0'; i++)
        printf("%c", (~(argv[2][i] - '0') & 1) + '0');
    printf("\n");

    printf("%s & %s = ", argv[1], argv[2]);
    for(i = 0; i < l1 - l2; i++)
        printf("%c", argv[1][i]);
    for(j = 0; j < l2 - l1; j++)
        printf("%c", argv[1][j]);
    for(; argv[1][i] != '\0'; i++, j++)
        printf("%c", ((argv[1][i] - '0') & (argv[2][j] - '0') & 1) + '0');
    printf("\n");

    printf("%s | %s = ", argv[1], argv[2]);
    for(i = 0; i < l1 - l2; i++)
        printf("%c", argv[1][i]);
    for(j = 0; j < l2 - l1; j++)
        printf("%c", argv[1][j]);
    for(; argv[1][i] != '\0'; i++, j++)
        printf("%c", ((argv[1][i] - '0') | (argv[2][j] - '0') & 1) + '0');
    printf("\n");

    printf("%s ^ %s = ", argv[1], argv[2]);
    for(i = 0; i < l1 - l2; i++)
        printf("%c", argv[1][i]);
    for(j = 0; j < l2 - l1; j++)
        printf("%c", argv[1][j]);
    for(; argv[1][i] != '\0'; i++, j++)
        printf("%c", ((argv[1][i] - '0') ^ (argv[2][j] - '0') & 1) + '0');
    printf("\n");

    return 0;
}
