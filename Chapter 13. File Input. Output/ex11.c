/* C Primer Plus. Programming Exercise 13.11
 * Write a program that takes two command-line arguments. The first is a string; the
 * second is the name of a file. The program should then search the file, printing all lines
 * containing the string. Because this task is line oriented rather than character oriented,
 * use fgets() instead of getc(). Use the standard C library function strstr() (briefly
 * described in exercise 7 of Chapter 11) to search each line for the string. Assume no lines
 * are longer than 255 characters.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 255

int main(int argc, char* argv[])
{
    FILE *fp;
    char* str;
    char line[LINE_SIZE];

    if(argc < 3)
    {
        printf("Usage: %s string file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    str = argv[1];
    if((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr,"Can't open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    printf("Lines with %s: \n", argv[1]);
    while ((fgets(line, LINE_SIZE, fp) != NULL))
        if(strstr(line, str))
            printf("%s", line);

    return 0;
}