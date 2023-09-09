/* C Primer Plus. Programming Exercise 7.8
 * Modify assumption a. in exercise 7 so that the program presents a menu of pay rates
 * from which to choose. Use a switch to select the pay rate. The beginning of a run
 * should look something like this:
 * *****************************************************************
 * Enter the number corresponding to the desired pay rate or action:
 * 1) $8.75/hr 2) $9.33/hr
 * 3) $10.00/hr 4) $11.20/hr
 * 5) quit
 * *****************************************************************
 * If choices 1 through 4 are selected, the program should request the hours worked. The
 * program should recycle until 5 is entered. If something other than choices 1 through 5
 * is entered, the program should remind the user what the proper choices are and then
 * recycle. Use #defined constants for the various earning rates and tax rates.
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
    int variant;
    float gross, tax, net;
    bool stop;

    tax = 0;
    variant = 0;
    stop = false;
    do {
        printf("*****************************************************************\n"
               "Enter the number corresponding to the desired pay rate or action:\n"
               "1) $8.75/hr 2) $9.33/hr\n"
               "3) $10.00/hr 4) $11.20/hr\n"
               "5) quit\n"
               "*****************************************************************\n");
        scanf("%d", &variant);
        switch (variant){
            case 1:
                pph = PPH_1;
                break;
            case 2:
                pph = PPH_2;
                break;
            case 3:
                pph = PPH_3;
                break;
            case 4:
                pph = PPH_4;
                break;
            case 5:
                stop = true;
                break;
            default:
                continue;
        }
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