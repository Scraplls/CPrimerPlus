/* C Primer Plus. Programming Exercise 16.6
 * Modify Listing 16.17 so that it uses an array of struct names elements (as defined after
 * the listing) instead of an array of double. Use fewer elements, and initialize the array
 * explicitly to a suitable selection of names.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTAFF 10

typedef struct {
    char first[40];
    char last[40];
} names;

void showarray(const names ar[], int n);
int mycomp(const void * p1, const void * p2);

int main(void)
{
    names staff[MAXSTAFF] = {
            {"John", "Romero"},
            {"Akira", "Yamaoka"},
            {"Walter", "Sullivan"},
            {"John", "Carmack"},
            {"Charles", "Xavier"},
            {"Todd", "Howard"},
            {"Bob", "Ross"},
            {"Paul", "Allen"},
            {"Tyler", "Durden"},
            {"Mike", "Sully"}
    };

    puts("List of staff:");
    showarray(staff, MAXSTAFF);
    qsort(staff, MAXSTAFF, sizeof(names), mycomp);
    puts("\nSorted ex2_list:");
    showarray(staff, MAXSTAFF);
    return 0;
}

void showarray(const names ar[], int n)
{
    int index;
    for(index = 0; index < n; index++)
        printf("%d. %s %s\n", index + 1, ar[index].first, ar[index].last);
}

int mycomp(const void * p1, const void * p2)
{
    const names * a1 = (const names *) p1;
    const names * a2 = (const names *) p2;
    if (strcmp(a1->first, a2->first) < 0)
        return -1;
    if (strcmp(a1->first, a2->first) > 0)
        return 1;

    if (strcmp(a1->last, a2->last) < 0)
        return -1;
    if (strcmp(a1->last, a2->last) > 0)
        return 1;
    return 0;
}