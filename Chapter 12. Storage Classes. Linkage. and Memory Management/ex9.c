/* C Primer Plus. Programming Exercise 12.9
 * Write a program with the following behavior. First, it asks you how many words you
 * wish to enter. Then it has you enter the words, and then it displays the words. Use
 * malloc() and the answer to the first question (the number of words) to create a dynamic
 * array of the corresponding number of pointers-to-char. (Note that because each element
 * in the array is a pointer-to-char, the pointer used to store the return value of malloc()
 * should be a pointer-to-a-pointer-to-char.) When reading the string, the program should
 * read the word into a temporary array of char, use malloc() to allocate enough storage
 * to hold the word, and store the address in the array of char pointers. Then it should
 * copy the word from the temporary array into the allocated storage. Thus, you wind up
 * with an array of character pointers, each pointing to an object of the precise size needed
 * to store the particular word. A sample run could look like this:
 * How many words do you wish to enter? 5
 * Enter 5 words now:
 * I enjoyed doing this exerise
 * Here are your words:
 * I
 * enjoyed
 * doing
 * this
 * exercise
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX_LENGTH 100

int main(void)
{
    int n;
    char** words;
    char temp[WORD_MAX_LENGTH];

    printf("How many words do you wish to enter? ");
    if(scanf("%d", &n) == 1 && n > 0)
    {
        words = (char**) malloc(n * sizeof(char*));
        if(words == NULL)
        {
            printf("ERROR! Not enough memory to be allocated!\n");
            return 1;
        }
        printf("Enter %d words now:\n", n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", temp);
            *(words+i) = (char*) malloc(strlen(temp) + 1);
            if(*(words+i) == NULL)
            {
                printf("ERROR! Not enough memory to be allocated!\n");
                return 1;
            }
            strcpy(*(words+i), temp);
        }

        printf("Here are your words:\n");
        for(int i = 0; i < n; i++)
        {
            puts(*(words+i));
            free(*(words+i));
        }
        free(words);
    }

    return 0;
}
