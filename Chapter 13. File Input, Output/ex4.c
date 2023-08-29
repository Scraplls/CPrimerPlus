/* C Primer Plus. Programming Exercise 13.4
 * Write a program that sequentially displays onscreen all the files listed in the command
 * line. Use argc to control a loop.
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ch;
    FILE *fp;

    for(int i = 1; i < argc; i++)
    {
        printf("#%d - %s:\n", i, argv[i]);
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            printf("Can't open %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        while ((ch = getc(fp)) != EOF)
        {
            putc(ch,stdout);
        }
        fclose(fp);
        printf("\n");
    }
}