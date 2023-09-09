/* C Primer Plus. Programming Exercise 9.1
 * Devise a function called min(x,y) that returns the smaller of two double values. Test
 * the function with a simple driver.
 */
#include <stdio.h>
double min(double x, double y);

int main(void){
    double a, b;
    a = 1.23;
    b = 2.34;
    double smaller = min(a, b);
    printf("Minimal of %.2lf and %.2lf is %.2lf\n", a, b, smaller);

    return 0;
}

double min(double x, double y){
    return x < y ? x : y;
}