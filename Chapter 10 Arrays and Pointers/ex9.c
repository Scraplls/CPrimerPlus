/* C Primer Plus. Programming Exercise 10.9
 * Write a program that initializes a two-dimensional 3×5 array-of-double and uses a VLA-
 * based function to copy it to a second two-dimensional array. Also provide a VLA-based
 * function to display the contents of the two arrays. The two functions should be capable,
 * in general, of processing arbitrary N×M arrays. (If you don’t have access to a VLA-capable
 * compiler, use the traditional C approach of functions that can process an N×5 array).
 */
#include <stdio.h>
#define ROWS 3
#define COLS 5
void mtcopy(int rows, int cols, double target[rows][cols], double source[rows][cols]);
void printmt(int rows, int cols, double mt[rows][cols]);

int main(void)
{
    double mt[ROWS][COLS] = {{0.1, 0.2, 0.3, 0.4, 0.5},
                       {1, 2, 3, 4, 5},
                       {10, 20, 30, 40, 50}};
    double copy[ROWS][COLS];
    printf("Original array: \n");
    printmt(ROWS, COLS, mt);
    mtcopy(ROWS, COLS, copy, mt);
    printf("Copied array: \n");
    printmt(ROWS, COLS,copy);
    return 0;
}

void mtcopy(int rows, int cols, double target[rows][cols], double source[rows][cols])
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            target[i][j] = source[i][j];
        }
    }
}

void printmt(int rows, int cols, double mt[rows][cols])
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        printf("[");
        for(j = 0; j < cols; j++)
        {
            printf("%.2lf, ", mt[i][j]);
        }
        printf("\b\b]\n");
    }
}