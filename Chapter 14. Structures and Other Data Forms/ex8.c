/* C Primer Plus. Programming Exercise 14.8
 * The Colossus Airlines fleet consists of one plane with a seating capacity of 12. It makes
 * one flight daily. Write a seating reservation program with the following features:
 *
 *  a. The program uses an array of 12 structures. Each structure should hold a seat
 *  identification number, a marker that indicates whether the seat is assigned, the last
 *  name of the seat holder, and the first name of the seat holder.
 *
 *  b. The program displays the following menu:
 *   To choose a function, enter its letter label:
 *   a) Show number of empty seats
 *   b) Show list of empty seats
 *   c) Show alphabetical list of seats
 *   d) Assign a customer to a seat assignment
 *   e) Delete a seat assignment
 *   f) Quit
 *
 *  c. The program successfully executes the promises of its menu. Choices d) and e)
 *  require additional input, and each should enable the user to abort an entry.
 *
 *  d. After executing a particular function, the program shows the menu again, except
 *  for choice f).
 *
 *  e. Data is saved in a file between runs. When the program is restarted, it first loads in
 *  the data, if any, from the file.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DEFAULT_FILE "flight.bin"
#define MAXNAME 40
#define MAXSEATS 12

struct seat {
    int id;
    bool assigned;
    char fname[MAXNAME];
    char lname[MAXNAME];
};

int main(int argc, char *argv[])
{
    struct seat seats[MAXSEATS];
    char* filename;
    FILE *fp;
    int i, choice;

    if(argc < 2)
    {
        printf("Data file is not specified! File '%s' will be created.", DEFAULT_FILE);
        filename = DEFAULT_FILE;
    } else
        filename = argv[1];
    if((fp = fopen(filename, "r+b")) == NULL)
    {
        printf("Can't open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    i = 0;
    while (i < MAXSEATS && fread(&seats[i], sizeof(struct seat), 1, fp) == 1)
        i++;
    printf("===The Colossus Airlines fleet===\n");
    printf("To choose a function, enter its letter label:\n"
           "a) Show number of empty seats\n"
           "b) Show list of empty seats\n"
           "c) Show alphabetical list of seats\n"
           "d) Assign a customer to a seat assignment\n"
           "e) Delete a seat assignment\n"
           "f) Quit\n");
    while ((choice = getchar()) != 'f' && choice != EOF)
    {
        while (getchar() != '\n')
            continue;
        switch (choice) {
            case 'a':
                break;
            case 'b':
                break;
            case 'c':
                break;
            case 'd':
                break;
            case 'e':
                break;
            default:
                printf("The entered function was not found! Try again!\n");
                break;
        }
        printf("===The Colossus Airlines fleet===\n");
        printf("To choose a function, enter its letter label:\n"
               "a) Show number of empty seats\n"
               "b) Show list of empty seats\n"
               "c) Show alphabetical list of seats\n"
               "d) Assign a customer to a seat assignment\n"
               "e) Delete a seat assignment\n"
               "f) Quit\n");
    }

}