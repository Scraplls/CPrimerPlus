/* C Primer Plus. Programming Exercise 13.3
 * Write a file copy program that prompts the user to enter the name of a text file to act as
 * the source file and the name of an output file. The program should use the toupper()
 * function from ctype.h to convert all text to uppercase as it’s written to the output file.
 * Use standard I/O and the text mode.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    int ch;
    FILE *in, *out;
    char fname[FILENAME_MAX];
    puts("Enter a input filename: ");
    scanf("%s", fname);
    if ((in = fopen(fname, "r")) == NULL)
    {
        printf("Can't open %s\n", fname);
        exit(EXIT_FAILURE);
    }
    puts("Enter an output filename: ");
    scanf("%s", fname);
    if ((out = fopen(fname, "w")) == NULL)
    {
        printf("Can't open %s\n", fname);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(in)) != EOF)
        putc(toupper(ch), out);
    fclose(in);
    fclose(out);
    printf("File copied successfully.\n");
    return 0;
}