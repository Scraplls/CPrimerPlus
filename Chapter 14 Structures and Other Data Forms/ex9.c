/* C Primer Plus. Programming Exercise 14.9
 * Colossus Airlines (from exercise 8) acquires a second plane (same capacity) and expands
 * its service to four flights daily (Flights 102, 311, 444, and 519). Expand the program to
 * handle four flights. Have a top-level menu that offers a choice of flights and the option
 * to quit. Selecting a particular flight should then bring up a menu similar to that of
 * exercise 8. However, one new item should be added: confirming a seat assignment. Also,
 * the quit choice should be replaced with the choice of exiting to the top-level menu. Each
 * display should indicate which flight is currently being handled. Also, the seat assignment
 * display should indicate the confirmation status.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>

#define DEFAULT_FILE "flight.bin"
#define MAXNAME 40
#define MAXSEATS 12
#define FLIGHTS 4

struct seat {
    int id;
    bool assigned;
    bool confirmed;
    char fname[MAXNAME];
    char lname[MAXNAME];
};

struct flight {
    int id;
    struct seat seats[MAXSEATS];
};

void showempty(struct seat seats[], int count);
void showemptylist(struct seat seats[], int count);
void showalphabetical(struct seat seats[], int count);
void assign(struct seat seats[], int count);
void deassign(struct seat seats[], int count);
void confirmseat(struct seat seats[], int count);
void printflightmenu(void);
void printseatmenu(void);

int main(int argc, char *argv[])
{
    struct flight flights[FLIGHTS] = {
            {102}, {311}, {444}, {519}
    };
    struct seat *seats;

    char* filename;
    FILE *fp;
    int i, j, choice;
    int id;
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
    read = fread(&flights, sizeof(struct flight), FLIGHTS, fp);
    if(argc < 2 || read != FLIGHTS)
    {
        i = 0;
        while (i < FLIGHTS)
        {
            j = 0;
            while (j < MAXSEATS)
            {
                flights[i].seats[j].id = j + 1;
                flights[i].seats[j].assigned = false;
                flights[i].seats[j].confirmed = false;
                flights[i].seats[j].fname[0] = '\0';
                flights[i].seats[j].lname[0] = '\0';
                j++;
            }
            i++;
        }
    }

    printflightmenu();
    while ((choice = getchar()) != 'q' && choice != EOF)
    {
        while (getchar() != '\n')
            continue;
        if(choice < 'a' || choice > 'd')
        {
            printf("The entered flight was not found! Try again!\n");
            printflightmenu();
            continue;
        }
        seats = flights[choice - 'a'].seats;
        id = flights[choice - 'a'].id;
        printf("Flight [%d]\n", id);
        printseatmenu();
        while ((choice = getchar()) != 'r' && choice != EOF)
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
                case 'f':
                    confirmseat(seats, MAXSEATS);
                    break;
                default:
                    printf("The entered function was not found! Try again!\n");
                    break;
            }
            printf("Flight [%d]\n", id);
            printseatmenu();
        }
        while (getchar() != '\n')
            continue;
        printflightmenu();
    }
    rewind(fp);
    if(fwrite(&flights, sizeof(struct flight), FLIGHTS, fp) != FLIGHTS){
        fprintf(stderr, "Error while writing to file '%s'!\n", filename);
        exit(EXIT_FAILURE);
    }
    printf("Data has writen to file '%s' successfully!\n", filename);
    fclose(fp);
    return 0;
}

void printflightmenu(void)
{
    printf("===The Colossus Airlines fleet===\n");
    printf("To choose a flight, enter its letter label or q to quit:\n"
           "a) Flight 102\n"
           "b) Flight 311\n"
           "c) Flight 444\n"
           "d) Flight 519\n"
           "q) Quit\n");
}

void printseatmenu(void)
{
    printf("To choose a function, enter its letter label:\n"
           "a) Show number of empty seats\n"
           "b) Show ex2_list of empty seats\n"
           "c) Show alphabetical ex2_list of seats\n"
           "d) Assign a customer to a seat assignment\n"
           "e) Delete a seat assignment\n"
           "f) Confirm a seat assignment\n"
           "r) Return to flight menu\n");
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
            printf("Seat No.%d: assigned by %s %s%s\n", sorted[i]->id,
                   sorted[i]->fname, sorted[i]->lname, sorted[i]->confirmed ? ", confirmed" : "");
    }
}

void assign(struct seat seats[], int count)
{
    int seat;
    char fname[MAXNAME];
    char lname[MAXNAME];

    printf("Enter a seat No. to assign: ");
    scanf("%d", &seat);
    while (getchar() != '\n')
        continue;
    if(seat < 1 || seat > count)
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
    if (getchar() == 'n')
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

    printf("Enter a seat No. to de-assign: ");
    scanf("%d", &seat);
    while (getchar() != '\n')
        continue;
    if(seat < 1 || seat > count)
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
    if (getchar() == 'n')
    {
        puts("Seat de-assignment aborted.");
        while (getchar() != '\n')
            continue;
        return;
    }
    while (getchar() != '\n')
        continue;
    seats[seat].assigned = false;
    seats[seat].confirmed = false;
    seats[seat].fname[0] = '\0';
    seats[seat].lname[0] = '\0';
    printf("Seat No.%d de-assigned successfully.\n", seat+1);
}

void confirmseat(struct seat seats[], int count)
{
    int seat;

    printf("Enter a seat No. to confirm: ");
    scanf("%d", &seat);
    while (getchar() != '\n')
        continue;
    if(seat < 1 || seat > count)
    {
        printf("Invalid seat No. Aborting...\n");
        return;
    }
    seat--;
    if(!seats[seat].assigned)
    {
        printf("There is no assignment for this seat to confirm. Aborting...\n");
        return;
    }
    if(seats[seat].confirmed)
    {
        printf("Sorry, but this seat is already confirmed. Aborting...\n");
        return;
    }

    seats[seat].confirmed = true;
    printf("Seat No.%d confirmed successfully.\n", seat+1);
}
