/* C Primer Plus. Programming Exercise 10.14
 * Do Programming Exercise 13, but use variable-length array function parameters.
 */
#include <stdio.h>

void fill_mt(int rows, int cols, double mt[rows][cols]);
double arravg(double arr[], int size);
double mtavg(int rows, int cols, double mt[rows][cols]);
double mtmax(int rows, int cols, double mt[rows][cols]);
void results(int rows, int cols, double mt[rows][cols]);

int main(void)
{
    double mt[3][5];
    printf("Fill the 2d-array 3x5 by any double values: \n");
    fill_mt(3, 5, mt);
    results(3, 5, mt);
    return 0;
}

void fill_mt(int rows, int cols, double mt[rows][cols])
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        printf("mt[%d][]:", i);
        for(j = 0; j < cols; j++)
        {
            scanf("%lf", &mt[i][j]);
        }
    }
}

void results(int rows, int cols, double mt[rows][cols])
{
    int i;

    for(i = 0; i < rows; i++)
        printf("mt[%d][] avg: %.2f\n", i, arravg(mt[i], cols));
    printf("mt avg: %.2f\n", mtavg(rows, cols, mt));
    printf("mt largest: %.2f\n", mtmax(rows, cols, mt));
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

double mtavg(int rows, int cols, double mt[rows][cols])
{
    int i, j;
    double s;

    s = 0;
    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            s += mt[i][j];

    return s/(rows*cols);
}

double mtmax(int rows, int cols, double mt[rows][cols])
{
    int i, j;
    double max;

    j = 0;
    max = mt[0][j++];
    for(i = 0; i < rows; i++)
    {
        for(; j < cols; j++)
        {
            if(mt[i][j] > max)
                max = mt[i][j];
        }
        j = 0;
    }

    return max;
}
