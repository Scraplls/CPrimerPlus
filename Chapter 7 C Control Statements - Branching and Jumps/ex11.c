/* C Primer Plus. Programming Exercise 7.11
 * The ABC Mail Order Grocery sells artichokes for $2.05 per pound, beets for $1.15 per
 * pound, and carrots for $1.09 per pound. It gives a 5% discount for orders of $100 or
 * more prior to adding shipping costs. It charges $6.50 shipping and handling for any
 * order of 5 pounds or under, $14.00 shipping and handling for orders over 5 pounds
 * and under 20 pounds, and $14.00 plus $0.50 per pound for shipments of 20 pounds or
 * more. Write a program that uses a switch statement in a loop such that a response of a
 * lets the user enter the pounds of artichokes desired, b the pounds of beets, c the pounds
 * of carrots, and q allows the user to exit the ordering process. The program should keep
 * track of cumulative totals. That is, if the user enters 4 pounds of beets and later enters
 * 5 pounds of beets, the program should use report 9 pounds of beets. The program then
 * should compute the total charges, the discount, if any, the shipping charges, and the
 * grand total. The program then should display all the purchase information: the cost per
 * pound, the pounds ordered, and the cost for that order for each vegetable, the total cost
 * of the order, the discount (if there is one), the shipping charge, and the grand total of all
 * the charges.
 */
#include <stdio.h>
#include <stdbool.h>

#define ARTICHOKES_PRICE 2.05
#define BEETS_PRICE 1.15
#define CARROTS_PRICE 1.09
#define DISCOUNT 0.05

int main(void){
    char choice;
    float pounds;
    float a_pounds, b_pounds, c_pounds;
    float a_cost, b_cost, c_cost;
    float cost, discount, shipping, total;

    pounds = 0;
    a_pounds = b_pounds = c_pounds = 0;
    cost = discount = shipping = total = 0;

    printf("==========================\n");
    printf("The ABC Mail Order Grocery\n");
    printf("==========================\n");
    printf("Order menu: \n");
    printf("a) artichokes\n");
    printf("b) beets\n");
    printf("c) carrots\n");
    printf("q) (quit)\n");

    while ((choice = getchar()) != 'q'){
        if (choice == '\n')
            continue;
        while (getchar() != '\n')
            continue;
        switch (choice) {
            case 'a':
                printf("Enter weight of artichokes in pounds: ");
                if(!scanf("%f", &pounds) || pounds < 1e-3)
                    break;
                a_pounds += pounds;
                break;
            case 'b':
                printf("Enter weight of artichokes in pounds: ");
                if(!scanf("%f", &pounds) || pounds < 1e-3)
                    break;
                b_pounds += pounds;
                break;
            case 'c':
                printf("Enter weight of artichokes in pounds: ");
                if(!scanf("%f", &pounds) || pounds < 1e-3)
                    break;
                c_pounds += pounds;
                break;
            default:
                break;
        }

        printf("Order menu: \n");
        printf("a) artichokes\n");
        printf("b) beets\n");
        printf("c) carrots\n");
        printf("q) (quit)\n");
    }

    pounds = a_pounds + b_pounds + c_pounds;
    if(pounds > 1e-3){
        a_cost = a_pounds * ARTICHOKES_PRICE;
        b_cost = b_pounds * BEETS_PRICE;
        c_cost = c_pounds * CARROTS_PRICE;
        cost = a_cost + b_cost + c_cost;
        discount = cost * DISCOUNT;
        if(pounds < 5)
            shipping = 6.50;
        else if(pounds >= 5 && pounds < 20)
            shipping = 14.00;
        else
            shipping = 14.00 + 0.50f * (pounds - 20);
        total = cost - discount + shipping;
        printf("[Receipt]\n");
        printf("Artichokes\t\t\t%-6.2fp. x %.2f$ = %.2f$\n", a_pounds, ARTICHOKES_PRICE, a_cost);
        printf("Beets\t\t\t\t%-6.2fp. x %.2f$ = %.2f$\n", b_pounds, BEETS_PRICE, b_cost);
        printf("Carrots\t\t\t\t%-6.2fp. x %.2f$ = %.2f$\n", c_pounds, CARROTS_PRICE, c_cost);
        printf("----------------------------------------------------------\n");
        printf("Cost\t\t\t\t%-6.2f$\n", cost);
        printf("Discount\t\t\t%-6.2f$\n", discount);
        printf("Shipping\t\t\t%-6.2f$\n", shipping);
        printf("----------------------------------------------------------\n");
        printf("Total\t\t\t\t%-6.2f$\n", total);
    } else{
        printf("Your order is empty.\n");
    }
    return 0;
}