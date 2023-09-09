/* C Primer Plus. Programming Exercise 6.6
 * Write a program that prints a table with each line giving an integer, its square, and its
 * cube. Ask the user to input the lower and upper limits for the table. Use a for loop.
 */
#include <stdio.h>

int main(void){
    int lower, upper;

    printf("Enter the lower and upper limits for the table: ");
    scanf("%d%d", &lower, &upper);
    while (lower > upper){
        printf("Error! The given limit is incorrect!\n");
        printf("Enter an lower and upper limits for the table: ");
        scanf("%d%d", &lower, &upper);
    }

    printf("    n       n^2       n^3\n");
    for(int n = lower; n <= upper; n++){
        printf("%5d%10d%10d\n", n, n*n, n*n*n);
    }

    return 0;
}