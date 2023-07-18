/* C Primer Plus. Programming Exercise 6.17
 * Chuckie Lucky won a million dollars (after taxes), which he places in an account that
 * earns 8% a year. On the last day of each year, Chuckie withdraws $100,000. Write a
 * program that finds out how many years it takes for Chuckie to empty his account.
 */
#include <stdio.h>

int main(void){
    double balance;
    int year;

    balance = 1000000;
    year = 0;
    while (balance > 0.0){
        balance = balance * 1.08 - 100000;
        year++;
    }
    printf("Chuckie Lucky will empty his account after %d years.\n", year);
    return 0;
}