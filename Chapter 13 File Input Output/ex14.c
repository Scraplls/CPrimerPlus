/* C Primer Plus. Programming Exercise 13.14
 * Digital images, particularly those radioed back from spacecraft, may have glitches. Add
 * a de-glitching function to programming exercise 12. It should compare each value to its
 * immediate neighbors to the left and right, above and below. If the value differs by more
 * than 1 from each of its neighbors, replace the value with the average of the neighboring
 * values. You should round the average to the nearest integer value. Note that the points
 * along the boundaries have fewer than four neighbors, so they require special handling.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 20
#define COLS 30

void deglitch(int rows, int cols, int data[rows][cols]);
int avg(int target, int left, int right, int above, int below);

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

    deglitch(ROWS, COLS, digits);

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
    printf("\nDeglitch complete!\n");

    fclose(in);
    fclose(out);
    return 0;
}

void deglitch(int rows, int cols, int data[rows][cols]) {
    int i, j;
    if (rows < 2 || cols < 2)
        return;
    /* corners */
    data[0][0] = avg(data[0][0], 0, data[0][1], 0, data[1][0]);
    data[0][cols - 1] = avg(data[0][cols - 1], data[0][cols - 2], 0, 0, data[1][cols - 1]);
    data[rows - 1][0] = avg(data[rows - 1][0], 0, data[rows - 1][1], data[rows - 2][0], 0);
    data[rows - 1][cols - 1] = avg(data[rows - 1][cols - 1], data[rows - 1][cols - 2], 0, data[rows - 2][cols - 1], 0);
    /* boundaries */
    for (i = 1; i < cols - 1; i++) {
        data[0][i] = avg(data[0][i], data[0][i - 1], data[0][i + 1], 0, data[1][i]);
        data[rows - 1][i] = avg(data[rows - 1][i], data[rows - 1][i - 1], data[rows - 1][i + 1], data[rows - 2][i], 0);
    }
    for (i = 1; i < rows - 1; i++) {
        data[i][0] = avg(data[i][0], 0, data[i][1], data[i - 1][0], data[i + 1][0]);
        data[i][cols - 1] = avg(data[i][cols - 1], data[i][cols - 2], 0, data[i - 1][cols - 1], data[i + 1][cols - 1]);
    }

    for (i = 1; i < rows - 1; i++)
        for (j = 1; j < cols - 1; j++)
            data[i][j] = avg(data[i][j], data[i][j-1], data[i][j+1], data[i-1][j], data[i+1][j]);
}

int avg(int target, int left, int right, int above, int below)
{
    double rem;
    if(abs(target - left) <= 1 || abs(target - right) <= 1 ||
       abs(target - above) <= 1 || abs(target - below) <= 1)
        return target;
    rem = (left + right + above + below) / 4.0 - (left + right + above + below) / 4;
    if(rem - 0.5 > 1e6f)
        return (left + right + above + below) / 4 + 1;
    else
        return (left + right + above + below) / 4;
}