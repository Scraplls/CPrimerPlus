/* C Primer Plus. Programming Exercise 8.7
 * Modify Programming Exercise 8 from Chapter 7 so that the menu choices are labeled by
 * characters instead of by numbers; use q instead of 5 as the cue to terminate input.
 */
#include <stdio.h>
#include <stdbool.h>
#define PPH_1 8.75
#define PPH_2 9.33
#define PPH_3 10.00
#define PPH_4 11.20
#define OVERTIME_HRS 40
#define OVERTIME_RATE 1.50
#define TAX_RATE_BASE 0.15
#define TAX_RATE_150 0.20
#define TAX_RATE_REST 0.25

int main(void){
    int hrs;
    float pph;
    char variant;
    float gross, tax, net;
    bool stop;

    tax = 0;
    variant = 0;
    stop = false;
    do {
        printf("*****************************************************************\n"
               "Enter the number corresponding to the desired pay rate or action:\n"
               "a) $8.75/hr b) $9.33/hr\n"
               "c) $10.00/hr d) $11.20/hr\n"
               "q) quit\n"
               "*****************************************************************\n>");
        scanf("%c", &variant);
        switch (variant){
            case 'a':
                pph = PPH_1;
                break;
            case 'b':
                pph = PPH_2;
                break;
            case 'c':
                pph = PPH_3;
                break;
            case 'd':
                pph = PPH_4;
                break;
            case 'q':
                stop = true;
                break;
            default:
                continue;
        }
        while (getchar() != '\n')
            continue;
        if(!stop){
            printf("Enter the hours you worked last week: ");
            if (scanf("%d", &hrs)){
                if(hrs > OVERTIME_HRS)
                    hrs = OVERTIME_RATE * hrs;
                gross = hrs * pph;

                if(gross <= 300.0)
                    tax += gross * TAX_RATE_BASE;
                else if(gross <= 450.0)
                    tax += (gross - 300.0) * TAX_RATE_150 + 300 * TAX_RATE_BASE;
                else
                    tax += (gross - 450.0) * TAX_RATE_REST + 150.0 * TAX_RATE_150 + 300 * TAX_RATE_BASE;
                net = gross - tax;

                printf("Gross pay: %.2f\n", gross);
                printf("Taxes: %.2f\n", tax);
                printf("Net pay: %.2f\n\n", net);
            }
        }
    } while(!stop);

    return 0;
}