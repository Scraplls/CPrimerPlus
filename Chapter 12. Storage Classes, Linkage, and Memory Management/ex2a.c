#include <stdio.h>
#include "ex2a.h"

static int mode;
static double distance;
static double fuel;

void set_mode(int m)
{
    if(m != EU_MODE && m != US_MODE)
        printf("Invalid mode specified. Mode %d(%s) used.\n", mode, mode == EU_MODE ? "EU" : "US");
    else
        mode = m;
}

void get_info()
{
    if(mode == US_MODE)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel);
    }
    else
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel);
    }
}

void show_info()
{
    double rate;
    if(mode == US_MODE)
    {
        rate = distance / fuel;
        printf("Fuel consumption is %.1lf miles per gallon.\n", rate);
    }
    else
    {
        rate = fuel / (distance / 100);
        printf("Fuel consumption is %.2lf liters per 100 km.\n", rate);
    }
}

