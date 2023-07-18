/* C Primer Plus. Programming Exercise 6.16
 * Daphne invests $100 at 10% simple interest. (That is, every year, the investment earns
 * an interest equal to 10% of the original investment.) Deirdre invests $100 at 5% interest
 * compounded annually. (That is, interest is 5% of the current balance, including previous
 * addition of interest.) Write a program that finds how many years it takes for the value
 * of Deirdre's investment to exceed the value of Daphne's investment. Also show the two
 * values at that time.
 */
#include <stdio.h>

int main(void){
    double daphne, deidre;
    int year;

    daphne = 100.0;
    deidre = 100.0;
    for (year = 1; daphne >= deidre; year++){
        daphne += 100 * 0.1;
        deidre += deidre * 0.05;
    }

    printf("After %d years Deirdre's investment will exceed the value of Daphne's investment\n", year);
    printf("Daphne investment after %d years is %.2f\n", year, daphne);
    printf("Deirdre's investment after %d years is %.2f\n", year, deidre);

    return 0;
}