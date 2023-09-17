/* C Primer Plus. Programming Exercise 17.7
 * Write a program that opens and reads a text file and records how many times each word
 * occurs in the file. Use a binary search tree modified to store both a word and the number
 * of times it occurs. After the program has read the file, it should offer a menu with three
 * choices. The first is to list all the words along with the number of occurrences. The
 * second is to let you enter a word, with the program reporting how many times the word
 * occurred in the file. The third choice is to quit.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ex7_tree.h"

void printword(Item * item);

int main(int argc, char * argv[])
{
    Tree wtree;
    FILE * fp;
    char* buffer;
    long fsize;
    char ch;
    int i;

    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s file", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "rb")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    fsize = ftell(fp);
    fclose(fp);
    buffer = (char *) malloc(fsize * sizeof(char));

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Reading words from file...");

    InitializeTree(&wtree);
    ch = 0;
    while (ch != EOF)
    {
        while (!isalnum(ch = fgetc(fp)))
            continue;
        if(ch == EOF)
            break;

        char * word;
        i = 0;
        buffer[i++] = ch;
        while (isalnum(ch = fgetc(fp)) && ch != EOF)
            buffer[i++] = ch;

        word = (char * ) malloc((i + 1) * sizeof(char));
        strncpy(word, buffer, i);
        AddItem(&(Item){word, 1}, &wtree);
        word[i] = '\0';
    }

    printf("Successfully!\n");

    printf("Here's all word occurrences in file: \n");
    Traverse(&wtree, printword);

    DeleteAll(&wtree);
    free(buffer);
    fclose(fp);
    return 0;
}

void printword(Item * item)
{
    printf("%s - %d times\n", item->word, item->count);
}