/* C Primer Plus. Programming Exercise 16.4
 * The ANSI library features a clock() function with this description:
 * #include <time.h>
 * clock_t clock (void);
 * Here, clock_t is a type defined in time.h. The function returns the processor time,
 * which is given in some implementation-dependent units. (If the processor time is
 * unavailable or cannot be represented, the function returns a value of -1.) However,
 * CLOCKS_PER_SEC, also defined in time.h, is the number of processor time units per
 * second. Therefore, dividing the difference between two return values of clock() by
 * CLOCKS_PER_SEC gives you the number of seconds elapsed between the two calls.
 * Typecasting the values to double before division enables you to get fractions of a second.
 * Write a function that takes a double argument representing a desired time delay and
 * then runs a loop until that amount of time has passed. Write a simple program that tests
 * the function.
 */
#include <time.h>
#include <stdio.h>

void wait(double seconds);

int main(void)
{
    double seconds;

    printf("Enter time in seconds to wait: ");
    scanf("%lf", &seconds);
    wait(seconds);
    printf("Bye!\n");

    return 0;
}

void wait(double seconds)
{
    double elapsed;
    clock_t time, now;
    time = clock();
    now = clock();
    elapsed = (now - time) * 1.0 / CLOCKS_PER_SEC;
    while (elapsed < seconds)
    {
        now = clock();
        elapsed = (now - time) * 1.0 / CLOCKS_PER_SEC;
    }
}