/* C Primer Plus. Programming Exercise 14.1
 * Redo Review Question 5, but make the argument the spelled-out name of the month
 * instead of the month number. (Don’t forget about strcmp().) Test the function in a
 * simple program.
 * Review Question 5:
 * Write a function that, when given the month number, returns the total days in the year
 * up to and including that month. Assume that the structure template of question 3 and
 * an appropriate array of such structures are declared externally.
 * Review Question 3:
 * Devise a structure template that will hold the name of a month, a three-letter
 * abbreviation for the month, the number of days in the month, and the month number.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct month {
    char name[10];
    char abbrev[4];
    int days;
    int number;
};

struct month months[] = {
        {"January", "jan", 31, 1},
        {"February", "feb", 28, 2},
        {"March", "mar", 31, 3},
        {"April", "apr", 30, 4},
        {"May", "may", 31, 5},
        {"June", "jun", 30, 6},
        {"July", "jul", 31, 7},
        {"August", "aug", 31, 8},
        {"September", "sep", 30, 9},
        {"October", "oct", 31, 10},
        {"November", "nov", 30, 11},
        {"December", "dec", 31, 12}
};

int total_days(char* month);
/*
int total_days(int month);
*/

int main(void)
{
    char month[10];
    int total;

    printf("Enter a month to get total days from %s to this month: \n", months[0].name);
    scanf("%s", month);
    total = total_days(month);
    if(total == -1)
    {
        fprintf(stderr, "Given \'%s\' month does not exists!\n", month);
        exit(EXIT_FAILURE);
    }
    printf("Total days from %s to %s: %d\n", months[0].name, month, total);
    return 0;
}

int total_days(char* month)
{
    int total;
    total = 0;

    for (int i = 0; i < 12; i++)
    {
        total += months[i].days;
        if(strcmp(months[i].name, month) == 0)
            return total;
    }
    return -1;
}

/*
int total_days(int month)
{
    int total;

    if(month < 1 || month > 12)
        return -1;

    total = 0;
    for (int i = 0; i < month; i++)
        total += months[i].days;
    return total;
}
*/