/* C Primer Plus. Programming Exercise 7.10
 * The 1988 United States Federal Tax Schedule was the simplest in recent times. It had
 * four categories, and each category had two rates. Here is a summary (dollar amounts are
 * taxable income):
 * Category                 Tax
 * Single                   15% of first $17,850 plus 28% of excess
 * Head of Household        15% of first $23,900 plus 28% of excess
 * Married, Joint           15% of first $29,750 plus 28% of excess
 * Married, Separate        15% of first $14,875 plus 28% of excess
 * For example, a single wage earner with a taxable income of $20,000 owes 0.15 × $17,850
 * + 0.28 × ($20,000−$17,850). Write a program that lets the user specify the tax category
 * and the taxable income and that then calculates the tax. Use a loop so that the user can
 * enter several tax cases.
 */
#include <stdio.h>
#include <stdbool.h>
#define TAX_RATE 0.15
#define TAX_OVERLIMIT_RATE 0.28
#define SINGLE_OVERLIMIT 17850.00
#define HOUSEHOLD_OVERLIMIT 23900.00
#define JOINT_OVERLIMIT 29750.00
#define SEPARATE_OVERLIMIT 14875.00

int main(void){
    int category;
    float income, limit, tax;
    bool valid;

    valid = true;

    category = 0;
    do {
        printf("Tax categories: \n");
        printf("1) Single\n");
        printf("2) Head of Household\n");
        printf("3) Married, Joint\n");
        printf("4) Married, Separate\n");
        printf("Choose your category 1-4 (any other character to quit): \n");
        valid &= scanf("%d", &category);
        if(!valid || category < 1 || category > 4)
            break;
        printf("Enter your taxable income: ");
        valid &= scanf("%f", &income);

        switch (category) {
            case 1:
                limit = SINGLE_OVERLIMIT;
                break;
            case 2:
                limit = HOUSEHOLD_OVERLIMIT;
                break;
            case 3:
                limit = JOINT_OVERLIMIT;
                break;
            case 4:
                limit = SEPARATE_OVERLIMIT;
                break;
            default:
                valid = false;
                break;
        }
        if(valid){
            tax = TAX_RATE * income + ((income > limit) ? TAX_OVERLIMIT_RATE * (income - limit): 0);
            printf("Tax: %.2f\n", tax);
        }
    } while (valid);
    printf("Done\n");

    return 0;
}