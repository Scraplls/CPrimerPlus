/* C Primer Plus. Programming Exercise 8.5
 * Modify the guessing program of Listing 8.4 so that it uses a more intelligent guessing
 * strategy. For example, have the program initially guess 50, and have it ask the user
 * whether the guess is high, low, or correct. If, say, the guess is low, have the next guess
 * be halfway between 50 and 100, that is, 75. If that guess is high, let the next guess be
 * halfway between 75 and 50, and so on. Using this binary search strategy, the program
 * quickly zeros in on the correct answer, at least if the user does not cheat.
 */
#include <stdio.h>

int main(void)
{
    char ch;
    int guess, adjust;

    guess = adjust = 50;
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with an = if my guess is right, with an >\n");
    printf("if your number is higher than guess or < if lower.\n");
    printf("Uh...is your number %d?\n", guess);
    while ((ch = getchar()) != '=' && adjust > 1){
        switch (ch) {
            case '>':
                adjust /= 2;
                guess += adjust;
                break;
            case '<':
                adjust /= 2;
                guess -= adjust;
                break;
            default:
                break;
        }
        while((ch = getchar()) != '\n')
            continue;
        printf("Well...is your number %d?\n", guess);
    }
    if(ch == 'y'){
        printf("I knew I could do it!\n");
    } else {
        switch(ch){
            case '>':
                guess++;
                break;
            case '<':
                guess--;
                break;
            default:
                break;
        }

        printf("Alright! Your number is %d?\n", guess);
        while((ch = getchar()) != '\n')
            continue;
        if(getchar() == 'y')
            printf("I knew I could do it!\n");
        else
            printf("You fooled me! Goodbye.\n");
    }

    return 0;
}