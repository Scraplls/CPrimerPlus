/* C Primer Plus. Programming Exercise 12.3
 * Redesign the program described in Programming Exercise 2 so that it uses only automatic
 * variables. Have the program offer the same user interface—that is, it should prompt the
 * user to enter a mode, and so on. You’ll have to come up with a different set of function
 * calls, however.
 */
#include <stdio.h>
#include "ex3a.h"

int main(void)
{
    int input = 0, mode = 0;
    double distance, fuel;
    printf("Enter 0 for metric input, 1 for US input: ");
    scanf("%d", &input);
    while (input >= 0)
    {
        if(input != EU_MODE && input != US_MODE)
            printf("Invalid input specified. Mode %d(%s) used.\n", input, input == EU_MODE ? "EU" : "US");
        else
            mode = input;
        get_info(&mode, &distance, &fuel);
        show_info(&mode, &distance, &fuel);
        printf("Enter 0 for metric input, 1 for US input");
        printf(" (-1 to quit): ");
        scanf("%d", &input);
    }
    printf("Done.\n");
    return 0;
}

