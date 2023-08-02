/* C Primer Plus. Programming Exercise 9.4
 * The harmonic mean of two numbers is obtained by taking the inverses of the two
 * numbers, averaging them, and taking the inverse of the result. Write a function that
 * takes two double arguments and returns the harmonic mean of the two numbers.
 */
#include <stdio.h>
double hmean(double a, double b);

int main(void){
    double a, b;
    a = 3;
    b = 11;
    double hm = hmean(a, b);
    printf("Harmonic mean of a=%.2lf and b=%.2lf is %.2lf\n", a, b, hm);
    return 0;
}

double hmean(double a, double b){
    return 2/(1/a + 1/b);
}
