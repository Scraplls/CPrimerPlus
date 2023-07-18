/* C Primer Plus. Programming Exercise 6.16
 * Daphne invests $100 at 10% simple interest. (That is, every year, the investment earns
 * an interest equal to 10% of the original investment.) Deirdre invests $100 at 5% interest
 * compounded annually. (That is, interest is 5% of the current balance, including previous
 * addition of interest.) Write a program that finds how many years it takes for the value
 * of Deirdre’s investment to exceed the value of Daphne’s investment. Also show the two
 * values at that time.
 */
#include <stdio.h>

int main(void){
    double invest1, invest2;
    int year;

    invest1 = 100.0;
    invest2 = 100.0;
    for (year = 1; invest1 <= invest2; year++){
        invest1 += 100 * 0.1;
        invest2 += invest2 * 0.05;
    }

    printf("After %d years Deirdre’s investment exceeds the value of Daphne’s investment\n");
    printf("Deirdre’s investment after %d years");
    printf("Deirdre’s investment after %d years");

    return 0;
}