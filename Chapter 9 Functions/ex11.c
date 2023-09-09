/* C Primer Plus. Programming Exercise 9.11
 * Write and test a Fibonacci() function that uses a loop instead of recursion to calculate
 * Fibonacci numbers.
 */
#include <stdio.h>
unsigned long fibonacci(unsigned n);

int main(void){
    unsigned n;

    printf("Enter a positive integer n to calculate the n-th fibonacci number:\n");
    scanf("%u", &n);
    printf("%d fibonacci number is %lu\n", n, fibonacci(n));

    return 0;
}

unsigned long fibonacci(unsigned n){
    unsigned i;
    long number, prev, adj;

    number = 1;
    prev = 0;
    for(i = 2; i <= n; i++){
        adj = prev;
        prev = number;
        number += adj;
    }

    return number;
}