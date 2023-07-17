/* C Primer Plus. Programming Exercise 5.1
 * Write a program that converts time in minutes to time in hours and minutes. Use
 * #define or const to create a symbolic constant for 60. Use a while loop to allow the
 * user to enter values repeatedly and terminate the loop if a value for the time of 0 or less
 * is entered.
 */
#include <stdio.h>
#define MINUTES_IN_HOUR 60
int main(void)
{
    int minutes;

    printf("Enter the time (t) in minutes to convert it \nt: ");
    scanf("%d", &minutes);
    while (minutes > 0)
    {
        printf("t = %dm = %dh %dm\n\n", minutes, ((int) minutes / MINUTES_IN_HOUR), minutes % MINUTES_IN_HOUR);
        printf("Enter one more t or t <= 0 to exit: \nt: ");
        scanf("%d", &minutes);
    }
    printf("Exiting...\n");

    return 0;
}