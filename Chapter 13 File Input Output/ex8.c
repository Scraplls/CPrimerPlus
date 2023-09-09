/* C Primer Plus. Programming Exercise 13.8
 * Write a program that takes as command-line arguments a character and zero or more
 * filenames. If no arguments follow the character, have the program read the standard
 * input. Otherwise, have it open each file in turn and report how many times the character
 * appears in each file. The filename and the character itself should be reported along with
 * the count. Include error-checking to see whether the number of arguments is correct and
 * whether the files can be opened. If a file can’t be opened, have the program report that
 * fact and go on to the next file.
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char ch, target;
    int count;

    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s character [files]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    target = argv[1][0];
    if(argc > 2)
    {
        FILE *fp;
        int i;

        for(i = 2; i < argc; i++)
        {
            count = 0;
            if((fp = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "Can't open %s\n", argv[i]);
                continue;
            }
            while((ch = fgetc(fp)) != EOF)
                if(ch == target)
                    count++;
            printf("#%d %s - '%c' appeared %d times\n", i-1, argv[i], target, count);
            fclose(fp);
        }
    }
    else
    {
        count = 0;
        while ((ch = getchar()) != EOF)
            if(ch == target)
                count++;
        printf("'%c' appeared %d times\n", target, count);
    }

    return 0;
}