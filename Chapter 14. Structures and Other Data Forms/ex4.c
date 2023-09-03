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
#define NAMELEN 40
#define MEMBERS 5

struct name {
    char first[NAMELEN];
    char middle[NAMELEN];
    char last[NAMELEN];
};

struct person {
    int ssn;
    struct name name;
};

void print_persons(struct person members);

int main(void)
{
    struct person members[MEMBERS] = {
            {302039823, {"Dribble", "Michael", "Flossie"}},
            {337121841, {"Alex", .last = "Flossie"}},
            {401052809, {"Lewis", "Peter" "Kirkman"}},
            {301039824, {"Eric", .last = "Shelf"}},
            {307234822, {"Emily", "Rose" "Lynn"}}
    };


    return 0;
}

void print_persons(struct person members)
{

}