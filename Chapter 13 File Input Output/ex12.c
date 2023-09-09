/* C Primer Plus. Programming Exercise 13.12
 * Create a text file consisting of 20 rows of 30 integers. The integers should be in the range
 * 0–9 and be separated by spaces. The file is a digital representation of a picture, with
 * the values 0 through 9 representing increasing levels of darkness. Write a program that
 * reads the contents of the file into a 20-by-30 array of ints. In a crude approach toward
 * converting this digital representation to a picture, have the program use the values
 * in this array to initialize a 20-by-31 array of chars, with a 0 value corresponding to a
 * space character, a 1 value to the period character, and so on, with each larger number
 * represented by a character that occupies more space. For example, you might use # to
 * represent 9. The last character (the 31st) in each row should be a null character, making
 * it an array of 20 strings. Have the program display the resulting picture (that is, print the
 * strings) and also store the result in a text file.
 */
#include <stdio.h>
#include <stdlib.h>
#define ROWS 20
#define COLS 30

int main(int argc, char *argv[])
{
    int i, j;
    int ch;
    FILE *in, *out;
    int digits[ROWS][COLS];
    char picture[ROWS][COLS + 1];
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

    i = 0;
    while (fscanf(in, "%d", &ch) != EOF)
    {
        digits[i / COLS][i % COLS] = ch;
        i++;
    }

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
            picture[i][j] = signs[digits[i][j]];
        picture[i][j] = '\0';
    }

    for(i = 0; i < ROWS; i++)
    {
        printf("%s\n", picture[i]);
        fprintf(out, "%s\n", picture[i]);
    }

    fclose(in);
    fclose(out);
    return 0;
}