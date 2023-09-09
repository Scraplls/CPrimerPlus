/* C Primer Plus. Programming Exercise 11.13
 * Write a program that echoes the command-line arguments in reverse word order. That
 * is, if the command-line arguments are see you later, the program should print later
 * you see.
 */
#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;
    i = argc - 1;
    while (i > 0)
        printf("%s ", argv[i--]);
    printf("\n");

    return 0;
}