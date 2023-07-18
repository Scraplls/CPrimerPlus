/* C Primer Plus. Programming Exercise 7.7
 * Write a program that requests the hours worked in a week and then prints the gross pay,
 * the taxes, and the net pay. Assume the following:
 * a. Basic pay rate = $10.00/hr
 * b. Overtime (in excess of 40 hours) = time and a half
 * c. Tax rate: #15% of the first $300
 * 20% of the next $150
 * 25% of the rest
 * Use #define constants, and don’t worry if the example does not conform to current
 * tax law.
 */
#include <stdio.h>
#define PAY_PER_HOUR 10
#define OVERTIME_HRS 40
#define OVERTIME_RATE 1.50
#define TAX_RATE_BASE 0.15
#define TAX_RATE_150 0.20
#define TAX_RATE_REST 0.25

int main(void){
    int hrs;
    float gross, tax, net;

    tax = 0;
    printf("Enter the hours you worked last week: ");
    if (scanf("%d", &hrs)){
        if(hrs > OVERTIME_HRS)
            hrs = OVERTIME_RATE * hrs;
        gross = hrs * PAY_PER_HOUR;

        if(gross <= 300.0)
            tax += gross * TAX_RATE_BASE;
        else if(gross <= 450.0)
            tax += (gross - 300.0) * TAX_RATE_150 + 300 * TAX_RATE_BASE;
        else
            tax += (gross - 450.0) * TAX_RATE_REST + 150.0 * TAX_RATE_150 + 300 * TAX_RATE_BASE;
        net = gross - tax;

        printf("Gross pay: %.2f\n", gross);
        printf("Taxes: %.2f\n", tax);
        printf("Net pay: %.2f\n", net);
    }

    return 0;
}

