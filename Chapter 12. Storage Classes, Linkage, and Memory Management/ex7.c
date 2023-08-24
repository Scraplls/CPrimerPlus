/* C Primer Plus. Programming Exercise 12.7
 * Write a program that behaves like the modification of Listing 12.13, which we discussed
 * after showing the output of Listing 12.13. That is, have the program produce output like
 * the following:
 * Enter the number of sets; enter q to stop: 18
 * How many sides and how many dice? 6 3
 * Here are 18 sets of 3 6-sided throws.
 * 12 10 6 9 8 14 8 15 9 14 12 17 11 7 10
 * 13 8 14
 * How many sets? Enter q to stop: q
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INPSIZE 10

char* getss(char* s, int n);
void roll_dice_sets(int results[], int sets, int dice, int sides);
int roll_n_dice(int dice, int sides);
static int rollem(int sides);

int main(void)
{
    char s[INPSIZE];
    int dice;
    int sets;
    int sides;
    int status;
    srand((unsigned int) time(0));

    printf("Enter the number of sets; enter q to stop: ");
    getss(s, INPSIZE);

    while (s[0] != 'q')
    {
        sets = atoi(s);
        if(sets < 1)
        {
            printf("You should have entered a positive integer.");
            printf(" Let's try again.\n");
            printf("Enter the number of sets; enter q to stop: ");
            getss(s, INPSIZE);
            continue;
        }
        int results[sets];

        printf("How many sides and how many dice?: ");
        if ((status = scanf("%d %d", &sides, &dice)) != 2)
        {
            if (status == EOF)
                break;
            else
            {
                while (getchar() != '\n')
                    continue;
                printf("You should have entered a positive integer.");
                printf(" Let's try again.\n");
                printf("Enter the number of sets; enter q to stop: ");
                getss(s, INPSIZE);
                continue;
            }
        }
        while (getchar() != '\n')
            continue;
        roll_dice_sets(results, sets, dice, sides);
        printf("Here are %d sets of %d %d-sided throws.\n",
               sets, dice, sides);
        for(int i = 0; i < sets; i++)
            printf("%d ", results[i]);
        printf("\nEnter the number of sets; enter q to stop: ");
        getss(s, INPSIZE);
    }
    return 0;
}

static int rollem(int sides)
{
    int roll;
    roll = rand() % sides + 1;
    return roll;
}

int roll_n_dice(int dice, int sides)
{
    int d;
    int total = 0;
    if (sides < 2)
    {
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (dice < 1)
    {
        printf("Need at least 1 die.\n");
        return -1;
    }
    for (d = 0; d < dice; d++)
        total += rollem(sides);
    return total;
}

void roll_dice_sets(int results[], int sets, int dice, int sides)
{
    int i;
    for(i = 0; i < sets; i++)
        results[i] = roll_n_dice(dice, sides);
}

char* getss(char* s, int n)
{
    int i = 0;
    if (fgets(s, n, stdin) != NULL)
    {
        while (s[i] != '\n' && s[i] != '\0')
            i++;
        if (s[i] == '\n')
            s[i] = '\0';
        return s;
    }
    else
        return NULL;
}
