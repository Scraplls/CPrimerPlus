/* C Primer Plus. Programming Exercise 14.4
 * Write a program that creates a structure template with two members according to the
 * following criteria:
 *  a. The first member is a social security number. The second member is a structure
 *  with three members. Its first member contains a first name, its second member
 *  contains a middle name, and its final member contains a last name. Create and
 *  initialize an array of five such structures. Have the program print the data in this
 *  format:
 *  Dribble, Flossie M. – 302039823
 * Only the initial letter of the middle name is printed, and a period is added. Neither the
 * initial (of course) nor the period should be printed if the middle name member is empty.
 * Write a function to do the printing; pass the structure array to the function.
 *  b. Modify part a. by passing the structure value instead of the address.
 */
#include <stdio.h>
#include <string.h>

#define NAMELEN 40
#define MEMBERS 5

struct name {
    char first[NAMELEN + 1];
    char middle[NAMELEN + 1];
    char last[NAMELEN + 1];
};

struct person {
    unsigned int ssn;
    struct name name;
};

void print_personptr(const struct person* member);
void print_person(struct person member);


int main(void)
{
    int i;
    struct person members[MEMBERS] = {
            {302039823, {"Dribble", "Michael", "Flossie"}},
            {337121841, {"Alex", "", "Flossie"}},
            {401052809, {"Lewis", "Peter", "Kirkman"}},
            {301039824, {"Eric", "", "Shelf"}},
            {307234822, {"Emily", "Rose", "Lynn"}}
    };

    for(i = 0; i < MEMBERS; i++)
        print_personptr(&members[i]);
    printf("\n");
    for(i = 0; i < MEMBERS; i++)
        print_person(members[i]);

    return 0;
}

void print_personptr(const struct person* member)
{
    int i;
    for(i = 0; i < NAMELEN + 1 && member->name.first[i] != '\0'; i++)
        putchar(member->name.first[i]);
    putchar(',');
    putchar(' ');
    for(i = 0; i < NAMELEN + 1 && member->name.last[i] != '\0'; i++)
        putchar(member->name.last[i]);
    putchar(' ');
    if (member->name.middle[0] != '\0')
    {
        putchar(member->name.middle[0]);
        putchar('.');
    }
    printf(" - %d\n", member->ssn);
}

void print_person(const struct person member)
{
    int i;
    for(i = 0; i < NAMELEN + 1 && member.name.first[i] != '\0'; i++)
        putchar(member.name.first[i]);
    putchar(',');
    putchar(' ');
    for(i = 0; i < NAMELEN + 1 && member.name.last[i] != '\0'; i++)
        putchar(member.name.last[i]);
    putchar(' ');
    if (member.name.middle[0] != '\0')
    {
        putchar(member.name.middle[0]);
        putchar('.');
    }
    printf(" - %d\n", member.ssn);
}