/* C Primer Plus. Programming Exercise 13.2
 * Write a file-copy program that takes the original filename and the copy file from the
 * command line. Use standard I/O and the binary mode, if possible.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int c;
    int binary;
    FILE *src, *dest;

    if (argc < 3 || (binary = strcmp(argv[1], "-b") == 0) && argc < 4)
    {
        printf("Usage: %s [-b] source copy\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if(binary)
    {
        if ((src = fopen(argv[2], "rb")) == NULL)
        {
            printf("Can't open file %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
        if ((dest = fopen(argv[3], "wb")) == NULL)
        {
            printf("Can't open file %s\n", argv[3]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        if ((src = fopen(argv[1], "rb")) == NULL)
        {
            printf("Can't open file %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        if ((dest = fopen(argv[2], "wb")) == NULL)
        {
            printf("Can't open file %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
    }

    while ((c = fgetc(src)) != EOF)
        fputc(c, dest);

    fclose(src);
    fclose(dest);
    return 0;
}