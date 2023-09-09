/* C Primer Plus. Programming Exercise 13.13
 * Do Programming Exercise 12, but use variable-length arrays (VLAs) instead of standard
 * arrays.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int i, j;
    int ch;
    int first_row, lastncols;
    FILE *in, *out;
    int rows, cols;
    char signs[10] = {' ', '.', '\'', ':', '~', '*', '=', '$', '%', '#'};

    if (argc < 3)
    {
        printf("Usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((in = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((out = fopen(argv[2], "w")) == NULL)
    {
        printf("Can't open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    rows = 0;
    first_row = 1;
    while ((ch = getc(in)) != EOF && isdigit(ch))
    {
        cols = 1;
        while ((ch = getc(in)) != EOF && ch != '\n')
            if (isdigit(ch))
                cols++;
        if (first_row)
            first_row = 0;
        else
        {
            if (cols != lastncols)
            {
                fprintf(stderr, "Invalid input: array should have the same number of digits on each line!\n");
                exit(EXIT_FAILURE);
            }
        }
        lastncols = cols;
        rows++;
    }
    if (cols == 0)
    {
        fprintf(stderr, "Invalid input from file.\n");
        exit(EXIT_FAILURE);
    }

    int digits[rows][cols];
    char picture[rows][cols+1];

    i = 0;
    rewind(in);
    while (fscanf(in, "%d", &ch) != EOF)
    {
        digits[i / cols][i % cols] = ch;
        i++;
    }

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            picture[i][j] = signs[digits[i][j]];
        picture[i][j] = '\0';
    }

    for(i = 0; i < rows; i++)
    {
        printf("%s\n", picture[i]);
        fprintf(out, "%s\n", picture[i]);
    }

    fclose(in);
    fclose(out);
    return 0;
}