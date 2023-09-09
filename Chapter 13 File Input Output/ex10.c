/* C Primer Plus. Programming Exercise 13.10
 * Write a program that opens a text file whose name is obtained interactively. Set up a
 * loop that asks the user to enter a file position. The program then should print the part of
 * the file starting at that position and proceed to the next newline character. Let negative
 * or nonnumeric input terminate the user-input loop.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char name[50];
    int ch;
    long pos, last;

    printf("Enter the filename: ");
    gets(name);

    if((fp = fopen(name, "r")) == NULL)
    {
        fprintf(stderr,"Can't open file %s\n", name);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0, SEEK_END);
    last = ftell(fp);
    printf("Enter a file position (-1 to quit): ");
    while (scanf("%lu", &pos) && pos >= 0)
    {
        if(pos > last)
            printf("Given file position is out of bounds!\n");
        else
        {

            fseek(fp, pos, SEEK_SET);
            while ((ch = getc(fp)) != '\n' && ch != EOF)
                putchar(ch);
            putchar('\n');
        }

        printf("Enter a new file position (-1 to quit): ");
    }
    if (fclose(fp) != 0)
        fprintf(stderr,"Error closing file\n");
    printf("Done!\n");
    return 0;
}