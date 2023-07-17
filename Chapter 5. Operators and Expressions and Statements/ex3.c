/* C Primer Plus. Programming Exercise 5.3
 * Write a program that asks the user to enter the number of days and then converts that
 * value to weeks and days. For example, it would convert 18 days to 2 weeks, 4 days.
 * Display results in the following format:
 * 18 days are 2 weeks, 4 days.
 * Use a while loop to allow the user to repeatedly enter day values; terminate the loop
 * when the user enters a nonpositive value, such as 0 or -20.
 */
#include <stdio.h>

int main(void)
{
    const int days_in_week = 7;
    int days;

    printf("Enter the number of days to convert: ");
    scanf("%d", &days);
    while (days > 0)
    {
        printf("%d days are %d weeks, %d days.\n\n", days, ((int) days / days_in_week), days % days_in_week);
        printf("Enter another number of days or <= 0 to exit: \n");
        scanf("%d", &days);
    }
    printf("Exiting...\n");

    return 0;
}