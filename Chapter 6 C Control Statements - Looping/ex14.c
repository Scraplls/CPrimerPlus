/* C Primer Plus. Programming Exercise 6.14
 * Write a program that creates two eight-element arrays of doubles and uses a loop to let
 * the user enter values for the eight elements of the first array. Have the program set the
 * elements of the second array to the cumulative totals of the elements of the first array.
 * For example, the fourth element of the second array should equal the sum of the first
 * four elements of the first array, and the fifth element of the second array should equal
 * the sum of the first five elements of the first array. (It’s possible to do this with nested
 * loops, but by using the fact that the fifth element of the second array equals the fourth
 * element of the second array plus the fifth element of the first array, you can avoid
 * nesting and just use a single loop for this task.) Finally, use loops to display the contents
 * of the two arrays, with the first array displayed on one line and with each element of the
 * second array displayed below the corresponding element of the first array.
 */
#include <stdio.h>
#define ARRAY_SIZE 8

int main(void){
    int i;
    double input[ARRAY_SIZE];
    double totals[ARRAY_SIZE];

    printf("Enter 8 integers to set an array: ");
    for(i = 0; i < ARRAY_SIZE; i++)
        scanf("%lf", &input[i]);

    totals[0] = input[0];
    for(i = 1; i < ARRAY_SIZE; i++)
        totals[i] = input[i] + totals[i - 1];
    printf("Input array: ");
    for(i = 0; i < ARRAY_SIZE; i++)
        printf("%.2f ", input[i]);
    printf("\nCumulative totals: ");
    for(i = 0; i < ARRAY_SIZE; i++)
        printf("%.2f ", totals[i]);

    return 0;
}