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
#include <strings.h>

#define DEFAULT_FILE "flight.bin"
#define MAXNAME 40
#define MAXSEATS 12

struct seat {
    int id;
    bool assigned;
    char fname[MAXNAME];
    char lname[MAXNAME];
};

void showempty(struct seat seats[], int count);
void showemptylist(struct seat seats[], int count);
void showalphabetical(struct seat seats[], int count);
void assign(struct seat seats[], int count);
void deassign(struct seat seats[], int count);

int main(int argc, char *argv[])
{
    struct seat seats[MAXSEATS];
    char* filename;
    FILE *fp;
    int i, choice;
    unsigned long long read;

    if(argc < 2)
    {
        printf("Data file was not specified! File '%s' will be created.\n", DEFAULT_FILE);
        fp = fopen((filename = DEFAULT_FILE), "w+b");
    } else
        fp = fopen((filename = argv[1]), "r+b");
    if(fp == NULL)
    {
        fprintf(stderr, "Can't open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    read = fread(&seats, sizeof(struct seat), MAXSEATS, fp);
    if(argc < 2 || read != MAXSEATS)
    {
        i = 0;
        while (i < MAXSEATS)
        {
            seats[i].id = i + 1;
            seats[i].assigned = false;
            seats[i].fname[0] = '\0';
            seats[i].lname[0] = '\0';
            i++;
        }
    }
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
                showempty(seats, MAXSEATS);
                break;
            case 'b':
                showemptylist(seats, MAXSEATS);
                break;
            case 'c':
                showalphabetical(seats, MAXSEATS);
                break;
            case 'd':
                assign(seats, MAXSEATS);
                break;
            case 'e':
                deassign(seats, MAXSEATS);
                break;
            default:
                printf("The entered function was not found! Try again!\n");
                break;
        }
        printf("To choose a function, enter its letter label:\n"
               "a) Show number of empty seats\n"
               "b) Show list of empty seats\n"
               "c) Show alphabetical list of seats\n"
               "d) Assign a customer to a seat assignment\n"
               "e) Delete a seat assignment\n"
               "f) Quit\n");
    }
    rewind(fp);
    if(fwrite(&seats, sizeof(struct seat), MAXSEATS, fp) != MAXSEATS){
        fprintf(stderr, "Error while writing to file '%s'!\n", filename);
        exit(EXIT_FAILURE);
    }
    printf("Data has writen to file '%s' successfully!\n", filename);
    fclose(fp);
    return 0;
}

void showempty(struct seat seats[], int count)
{
    int empty = 0;
    for(int i = 0; i < count; i++)
        if(!seats[i].assigned)
            empty++;
    printf("Current number of empty seats: %d\n", empty);
}

void showemptylist(struct seat seats[], int count)
{
    int empty = 0;
    struct seat *emptyseats[count];
    for(int i = 0; i < count; i++)
        if(!seats[i].assigned)
            emptyseats[empty++] = &seats[i];
    if(empty == 0)
        printf("Sorry, but all seats are already assigned!\n");
    else
    {
        printf("Current empty seats: \n");
        for(int i = 0; i < empty; i++)
            printf("Seat No.%d\n", emptyseats[i]->id);
    }
}

void showalphabetical(struct seat seats[], int count)
{
    struct seat *sorted[count];
    int i, j;
    for (i = 0; i < count; i++)
        sorted[i] = &seats[i];
    struct seat *temp;

    for (i = 0; i < count - 1; i++)
        for (j = i + 1; j < count; j++)
        {
            if (strcmp(sorted[i]->fname, sorted[j]->fname) > 0 ||
                    strcmp(sorted[i]->fname, sorted[j]->fname) == 0 &&
                    strcmp(sorted[i]->lname, sorted[j]->lname) > 0
            )
            {
                temp = sorted[j];
                sorted[j] = sorted[i];
                sorted[i] = temp;
            }
        }
    printf("Seats sorted by name: \n");
    for (i = 0; i < count; i++)
    {
        if(sorted[i]->assigned)
            printf("Seat No.%d: assigned by %s %s\n", sorted[i]->id,
                   sorted[i]->fname, sorted[i]->lname);
    }
}

void assign(struct seat seats[], int count)
{
    int seat;
    char fname[MAXNAME];
    char lname[MAXNAME];
    char ch;

    printf("Enter a seat No. to assign: ");
    scanf("%d", &seat);
    while (getchar() != '\n')
        continue;
    if(seat < 1 || seat > 12)
    {
        printf("Invalid seat No. Aborting...\n");
        return;
    }
    seat--;
    if(seats[seat].assigned)
    {
        printf("Sorry, but this seat is already assigned. Aborting...\n");
        return;
    }
    printf("Enter the passenger's first name: ");
    scanf("%s", fname);
    printf("Enter the passenger's last name: ");
    scanf("%s", lname);
    while (getchar() != '\n')
        continue;
    printf("Seat No.%d: assigning for %s %s\n", seat, fname, lname);
    puts("Is this correct? Enter [n] to abort or any other key to continue.");
    if ((ch = getchar()) == 'n')
    {
        puts("Seat assignment aborted.");
        while (getchar() != '\n')
            continue;
        return;
    }
    while (getchar() != '\n')
        continue;
    strcpy(seats[seat].fname, fname);
    strcpy(seats[seat].lname, lname);
    seats[seat].assigned = true;
    printf("Successfully assigned seat No.%d for %s %s!\n", seat+1,
           seats[seat].fname, seats[seat].lname);
}

void deassign(struct seat seats[], int count)
{
    int seat;
    char ch;

    printf("Enter a seat No. to de-assign: ");
    scanf("%d", &seat);
    while (getchar() != '\n')
        continue;
    if(seat < 1 || seat > 12)
    {
        printf("Invalid seat No. Aborting...\n");
        return;
    }
    seat--;
    if(!seats[seat].assigned)
    {
        printf("This seat is not assigned. Aborting...\n");
        return;
    }
    printf("Seat No.%d: assigned by %s %s\n", seats[seat].id,
           seats[seat].fname, seats[seat].lname);
    puts("Would you like to delete this assignment? Enter [n] to abort "
         "or any other key to continue.");
    if ((ch = getchar()) == 'n')
    {
        puts("Seat de-assignment aborted.");
        while (getchar() != '\n')
            continue;
        return;
    }
    while (getchar() != '\n')
        continue;
    seats[seat].assigned = false;
    seats[seat].fname[0] = '\0';
    seats[seat].lname[0] = '\0';
    printf("Seat No.%d de-assigned successfully.\n", seat+1);
}