/* C Primer Plus. Programming Exercise 12.6
 * Write a program that generates 1,000 random numbers in the range 1–10. Don’t save or
 * print the numbers, but do print how many times each number was produced. Have the
 * program do this for 10 different seed values. Do the numbers appear in equal amounts?
 * You can use the functions from this chapter or the ANSI C rand() and srand()
 * functions, which follow the same format that our functions do. This is one way to
 * examine the randomness of a particular random-number generator.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int counters[10];
    int seed, i, num;

    for(seed = 0; seed < 10; seed++)
    {
        srand(seed);
        for(i = 0; i < 10; i++)
            counters[i] = 0;

        for(i = 0; i < 1000; i++)
        {
            num = rand() % 10;
            counters[num] += 1;
        }

        printf("Numbers generated: \n");
        for(i = 0; i < 10; i++)
            printf("%d - %d times\n", i, counters[i]);
        printf("\n");
    }

    return 0;
}