/* C Primer Plus. Programming Exercise 9.5
 * Write and test a function called larger_of() that replaces the contents of two double
 * variables with the maximum of the two values. For example, larger_of(x,y) would
 * reset both x and y to the larger of the two.
 */
#include <stdio.h>
void larger_of(double* a, double* b);

int main(void){
    double a = 1;
    double b = 2;
    printf("a=%.2lf, b=%.2lf\n", a, b);
    printf("larger_of(a, b)\n");
    larger_of(&a, &b);
    printf("Now: a=%.2lf, b=%.2lf\n", a, b);
    return 0;
}

void larger_of(double* a, double* b){
    *a > *b ? (*b = *a) : (*a = *b);
}
