/* C Primer Plus. Programming Exercise 6.12
 * Consider these two infinite series:
 * 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
 * 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
 * Write a program that evaluates running totals of these two series up to some limit of
 * number of terms. Hint: –1 times itself an odd number of times is –1, and –1 times itself
 * an even number of times is 1. Have the user enter the limit interactively; let a zero or
 * negative value terminate input. Look at the running totals after 100 terms, 1000 terms,
 * 10,000 terms. Does either series appear to be converging to some value?
 */
#include <stdio.h>

int main(void){
    int i;
    int n;
    float sum1, sum2;
    int sign = 1;

    printf("Enter the limit (n) of two infinite (harmonic and alternating) series: \n");
    scanf("%d", &n);
    while (n > 0){
        sum1 = sum2 = 0;

        for(i = 1; i <= n; i++){
            sum1 += 1.0f/i;
            sum2 += sign * 1.0f/i;
            sign = -sign;
        }

        printf("Sum of the harmonic series = %.3f\n", sum1); // doesn't converge
        printf("Sum of an alternating series = %.3f\n", sum2); // converge (ln(2))

        printf("Enter another limit (n) of infinite series (n <= 0 to quit): \n");
        scanf("%d", &n);
    }
    printf("Done\n");

    return 0;
}