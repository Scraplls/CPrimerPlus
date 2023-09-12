/* C Primer Plus. Programming Exercise 16.3
 * Polar coordinates describe a vector in terms of magnitude and the counterclockwise angle
 * from the x-axis to the vector. Rectangular coordinates describe the same vector in terms
 * of x and y components. Write a program that reads the magnitude and
 * angle (in degrees) of a vector and then displays the x and y components. The relevant
 * equations are these:
 * x = r cos A  y = r sin A
 * To do the conversion, use a function that takes a structure containing the polar
 * coordinates and returns a structure containing the rectangular coordinates (or use
 * pointers to such structures, if you prefer).
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ex1.h"

#define radian(x) (x / 57.32)

struct polar_vector
{
    double radius;
    double angle;
};

struct vector
{
    double x;
    double y;
};

struct vector* torect(struct polar_vector *polar);

int main(void)
{
    struct polar_vector polar;
    struct vector* rect;

    printf("Enter vector angle (A): ");
    scanf("%lf", &polar.angle);
    CLEARINPUT;
    printf("Enter vector magnitude (r): ");
    scanf("%lf", &polar.radius);
    CLEARINPUT;
    rect = torect(&polar);
    printf("Rectangular vector: {x=%.2lf,y=%.2lf}\n", rect->x, rect->y);

    return 0;
}

struct vector* torect(struct polar_vector *polar)
{
    struct vector *rect = (struct vector*) malloc(sizeof(struct vector));
    rect->x = polar->radius * cos(radian(polar->angle));
    rect->y = polar->radius * sin(radian(polar->angle));

    return rect;
}