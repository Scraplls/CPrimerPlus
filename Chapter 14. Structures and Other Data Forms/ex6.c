/* C Primer Plus. Programming Exercise 14.6
 * A text file holds information about a softball team. Each line has data arranged as
 * follows:
 * 4 Jessie Joybat 5 2 1 1
 * The first item is the player's number, conveniently in the range 0–18. The second item
 * is the player's first name, and the third is the player’s last name. Each name is a single
 * word. The next item is the player's official times at bat, followed by the number of hits,
 * walks, and runs batted in (RBIs). The file may contain data for more than one game,
 * so the same player may have more than one line of data, and there may be data for
 * other players between those lines. Write a program that stores the data into an array of
 * structures. The structure should have members to represent the first and last names, the
 * at bats, hits, walks, and RBIs (runs batted in), and the batting average (to be calculated
 * later). You can use the player number as an array index. The program should read to end-
 * of-file, and it should keep cumulative totals for each player.
 * The world of baseball statistics is an involved one. For example, a walk or reaching base
 * on an error doesn't count as an at-bat but could possibly produce an RBI. But all this
 * program has to do is read and process the data file, as described next, without worrying
 * about how realistic the data is.
 * The simplest way for the program to proceed is to initialize the structure contents to
 * zeros, read the file data into temporary variables, and then add them to the contents of
 * the corresponding structure. After the program has finished reading the file, it should
 * then calculate the batting average for each player and store it in the corresponding
 * structure member. The batting average is calculated by dividing the cumulative number
 * of hits for a player by the cumulative number of at-bats; it should be a floating-point
 * calculation. The program should then display the cumulative data for each player along
 * with a line showing the combined statistics for the entire team.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN 40
#define MAXPLAYERS 19

struct player {
    char fname[NAMELEN];
    char lname[NAMELEN];
    float time;
    float hits;
    float walks;
    float runs;
    float avg;
};

int main(int argc, char* argv[])
{
    FILE *fp;
    int i;
    char fname[NAMELEN];
    char lname[NAMELEN];
    float time, hits, walks, runs;
    int read;

    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Can't open file '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    struct player players[MAXPLAYERS];
    for(i = 0; i < MAXPLAYERS; i++)
    {
        players[i].time = players[i].hits = players[i].walks = players[i].runs = players[i].avg = 0;
        strcpy(players[i].fname, "");
        strcpy(players[i].lname, "");
    }

    i = -1;
    while ((read = fscanf(fp, "%d %s %s %f %f %f %f", &i, fname, lname, &time, &hits, &walks, &runs)) != EOF && read == 7)
    {
        if(i < 0 || i > 18)
            continue;
        if(players[i].fname[0] == '\0' && players[i].lname[0] == '\0')
        {
            strcpy(players[i].fname, fname);
            strcpy(players[i].lname, lname);
        }
        else if(strcmp(players[i].fname, fname) != 0 || strcmp(players[i].lname, lname) != 0)
            continue;
        players[i].time += time;
        players[i].hits += hits;
        players[i].walks += walks;
        players[i].runs += runs;
        i = -1;
    }
    printf("File was read successfully!\n");

    time = hits = walks = runs = 0;
    for(i = 0; i < MAXPLAYERS; i++)
    {
        if(players[i].time > 0)
        {
            players[i].avg = players[i].hits / players[i].time;
            time += players[i].time;
            hits += players[i].hits;
            walks += players[i].walks;
            runs += players[i].runs;
        }
    }

    printf("Player statistics:\n");
    for(i = 0; i < MAXPLAYERS; i++)
    {
        if(players[i].time > 0)
        {
            printf("#%d. %s %s\n", i, players[i].fname, players[i].lname);
            printf("* Time at bats: %.2f\n", players[i].time);
            printf("* Hits: %d\n", (int) players[i].hits);
            printf("* Walks: %d\n", (int) players[i].walks);
            printf("* Runs: %d\n", (int) players[i].runs);
            printf("* Batting average: %.2f\n", players[i].avg);
        }
    }

    printf("Statistics for the team:\n");
    printf("* Time at bats: %.2f\n", time);
    printf("* Hits: %d\n", (int) hits);
    printf("* Walks: %d\n", (int) walks);
    printf("* Runs: %d\n", (int) runs);
    printf("* Batting average: %.2f\n", hits / time);

    return 0;
}