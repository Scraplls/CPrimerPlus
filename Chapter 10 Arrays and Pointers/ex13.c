/* C Primer Plus. Programming Exercise 10.13
 * Write a program that prompts the user to enter three sets of five double numbers each.
 * (You may assume the user responds correctly and doesn't enter non-numeric data.) The
 * program should accomplish all the following:
 *  a. Store the information in a 3×5 array.
 *  b. Compute the average of each set of five values.
 *  c. Compute the average of all the values.
 *  d. Determine the largest value of the 15 values.
 *  e. Report the results.
 * Each major task should be handled by a separate function using the traditional C
 * approach to handling arrays. Accomplish task "b" by using a function that computes
 * and returns the average of a one-dimensional array; use a loop to call this function three
 * times. The other tasks should take the entire array as an argument, and the functions
 * performing tasks "c" and "d" should return the answer to the calling program.
 */
#include <stdio.h>
#define ROWS 3
#define COLS 5
void fill_mt(double mt[ROWS][COLS]);
double arravg(double arr[], int size);
double mtavg(double mt[ROWS][COLS]);
double mtmax(double mt[ROWS][COLS]);
void results(double mt[ROWS][COLS]);

int main(void)
{
    double mt[ROWS][COLS];
    printf("Fill the 2d-array 3x5 by any double values: \n");
    fill_mt(mt);
    results(mt);
    return 0;
}

void fill_mt(double mt[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        printf("mt[%d][]:", i);
        for(j = 0; j < COLS; j++)
        {
            scanf("%lf", &mt[i][j]);
        }
    }
}

void results(double mt[ROWS][COLS])
{
    int i;

    for(i = 0; i < ROWS; i++)
        printf("mt[%d][] avg: %.2f\n", i, arravg(mt[i], COLS));
    printf("mt avg: %.2f\n", mtavg(mt));
    printf("mt largest: %.2f\n", mtmax(mt));
}

double arravg(double arr[], int size)
{
    int i;
    double s;

    s = 0;
    for(i = 0; i < size; i++)
        s += arr[i];

    return s/size;
}

double mtavg(double mt[ROWS][COLS])
{
    int i, j;
    double s;

    s = 0;
    for(i = 0; i < ROWS; i++)
        for(j = 0; j < COLS; j++)
            s += mt[i][j];

    return s/(ROWS*COLS);
}

double mtmax(double mt[ROWS][COLS])
{
    int i, j;
    double max;

    j = 0;
    max = mt[0][j++];
    for(i = 0; i < ROWS; i++)
    {
        for(; j < COLS; j++)
        {
            if(mt[i][j] > max)
                max = mt[i][j];
        }
        j = 0;
    }

    return max;
}