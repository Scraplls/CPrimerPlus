/* C Primer Plus. Programming Exercise 13.7
 * Write a program that opens two files. You can obtain the filenames either by using
 * command-line arguments or by soliciting the user to enter them.
 * a. Have the program print line 1 of the first file, line 1 of the second file, line 2 of the
 * first file, line 2 of the second file, and so on, until the last line of the longer file (in
 * terms of lines) is printed.
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char ch1, ch2;

    if(argc < 3)
    {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    do
    {
        while ((ch1 = fgetc(fp1)) != '\n' && ch1 != EOF)
            fputc(ch1, stdout);
        fputc('\n', stdout);

        while ((ch2 = fgetc(fp2)) != '\n' && ch2 != EOF)
            fputc(ch2, stdout);
        fputc('\n', stdout);

    } while(ch1 != EOF || ch2 != EOF);

    fclose(fp1);
    fclose(fp2);
    return 0;
}