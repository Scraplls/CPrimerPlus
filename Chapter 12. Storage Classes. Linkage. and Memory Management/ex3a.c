#include <stdio.h>
#include "ex3a.h"

void get_info(const int* mode, double* distance, double* fuel)
{
    if(*mode == US_MODE)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", fuel);
    }
    else
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", fuel);
    }
}

void show_info(const int* mode, const double* distance, const double* fuel)
{
    double rate;
    if(*mode == US_MODE)
    {
        rate = *distance / *fuel;
        printf("Fuel consumption is %.1lf miles per gallon.\n", rate);
    }
    else
    {
        rate = *fuel / (*distance / 100);
        printf("Fuel consumption is %.2lf liters per 100 km.\n", rate);
    }
}

