/* C Primer Plus. Programming Exercise 9.9
 * Redo Programming Exercise 8, but this time use a recursive function.
 */
#include <stdio.h>
double power(double base, int p);

int main(void){
    double x, xpow;
    int exp;
    printf("Enter a number and the integer power\n");
    printf(" to which the number will be raised.\n");
    printf("Enter q to quit.\n");
    while (scanf("%lf%d", &x, &exp) == 2)
    {
        xpow = power(x,exp);
        printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");
    return 0;
}

double power(double n, int p){
    if (p == 0){
        if(n != 0)
            return 1;
        printf("Error! 0 to the 0 is undefined!.\n");
        printf("Calculating 1 to the 0...\n");
        n = 1;
    } else if (p < 0){
        n = 1/n;
        p = -p;
    }
    if(p == 1)
        return n;
    else
        return n * power(n, p - 1);
}