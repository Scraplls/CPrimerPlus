/* C Primer Plus. Programming Exercise 9.6
 * Write and test a function that takes the addresses of three double variables as arguments
 * and that moves the value of the smallest variable into the first variable, the middle value
 * to the second variable, and the largest value into the third variable
 */
#include <stdio.h>
void sortabc(double* a, double* b, double* c);

int main(void){
    double a, b, c;
    a = 2;
    b = 0;
    c = 1;
    printf("a=%.2lf, b=%.2lf, c=%.2lf\n", a, b, c);
    printf("sortabc(a, b, c)\n");
    sortabc(&a, &b, &c);
    printf("Now: a=%.2lf, b=%.2lf, c=%.2lf\n", a, b, c);
    return 0;
}

void sortabc(double* a, double* b, double* c){
    double temp;
    temp = 0;
    if (*a > *c){
        temp = *a;
        *a = *c;
        *c = temp;
    }
    if(*b > *c){
        temp = *b;
        *b = *c;
        *c = temp;
    }
    if(*a > *b){
        temp = *a;
        *a = *b;
        *b = temp;
    }
}
