/* C Primer Plus. Programming Exercise 7.9
 * Write a program that accepts a positive integer as input and then displays all the prime
 * numbers smaller than or equal to that number.
 */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool prime;
    int n, i, j;

    printf("Enter an integer n (n > 0):\n");
    scanf("%d", &n);

    if(n > 0){
        printf("All prime numbers from 2 to %d:\n", n);
        printf("%d ", 1);
        for (i = 2; i <= n; i++)
        {
            prime = true;
            for (j = 2; (j * j) <= i; j++)
            {
                if (i % j == 0){
                    prime = false;
                    break;
                }
            }
            if (prime)
                printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}