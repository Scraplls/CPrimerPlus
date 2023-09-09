/* C Primer Plus. Programming Exercise 14.2
 * Write a program that prompts the user to enter the day, month, and year. The month
 * can be a month number, a month name, or a month abbreviation. The program then
 * should return the total number of days in the year up through the given day. (Do take
 * leap years into account.)
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

int total_days(int day, int month, int year);

int main(void)
{
    char m_str[10];
    int day, month, year;
    int total;
    month = day = year = 0;

    printf("Enter a day: \n");
    scanf("%d", &day);
    printf("Enter a month: \n");
    scanf("%s", m_str);
    printf("Enter a year: \n");
    scanf("%d", &year);
    for(int i = 0; i < 12; i++)
    {
        if(strcmp(months[i].name, m_str) == 0 || strcmp(months[i].abbrev, m_str) == 0)
        {
            month = months[i].number;
            break;
        }
    }
    if(month == 0)
        month = atoi(m_str);

    total = total_days(day, month, year);
    if(total == -1)
    {
        fprintf(stderr, "Given input is incorrect!\n");
        exit(EXIT_FAILURE);
    }
    printf("Today is the %d day of %d\n", total, year);
    return 0;
}

int total_days(int day, int month, int year)
{
    int total, leap;
    total = day;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if(month < 1 || month > 12 || year < 1 || day < 1
    || day > ((month == 2 && leap) ? months[month-1].days + 1 : months[month-1].days))
        return -1;

    if(month > 2 && leap)
        total += 1;
    for (int i = 0; i < month - 1; i++)
        total += months[i].days;
    return total;
}