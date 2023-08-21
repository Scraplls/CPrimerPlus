/* C Primer Plus. Programming Exercise 11.12
 * Write a program that reads input up to EOF and reports the number of words, the
 * number of uppercase letters, the number of lowercase letters, the number of punctuation
 * characters, and the number of digits. Use the ctype.h family of functions.
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int inwrd;
    int words, uppers, lowers, puncts, digits;
    inwrd = words = uppers = lowers = puncts = digits = 0;

    while((ch = getchar()) != EOF && ch != '\n')
    {
        if(isupper(ch))
        {
            inwrd = 1;
            uppers++;
        }
        else if(islower(ch))
        {
            inwrd = 1;
            lowers++;
        }
        else
        {
            if(inwrd)
            {
                words++;
                inwrd = 0;
            }
            if(ispunct(ch))
                puncts++;
            else if(isdigit(ch))
                digits++;
        }
    }

    printf("Words: %d\n", words);
    printf("Uppercase letters: %d\n", uppers);
    printf("Lowercase letters: %d\n", lowers);
    printf("Punctuation characters: %d\n", puncts);
    printf("Digit characters: %d\n", digits);

    return 0;
}