/* C Primer Plus. Programming Exercise 14.5
 * Write a program that fits the following recipe:
 *  a. Externally define a name structure template with two members: a string to hold the
 *  first name and a string to hold the second name.
 *  b. Externally define a student structure template with three members: a name
 *  structure, a grade array to hold three floating-point scores, and a variable to hold
 *  the average of those three scores.
 *  c. Have the main() function declare an array of CSIZE (with CSIZE = 4) student
 *  structures and initialize the name portions to names of your choice. Use functions
 *  to perform the tasks described in parts d., e., f., and g.
 *  d. Interactively acquire scores for each student by prompting the user with a student
 *  name and a request for scores. Place the scores in the grade array portion of the
 *  appropriate structure. The required looping can be done in main() or in the
 *  function, as you prefer.
 *  e. Calculate the average score value for each structure and assign it to the proper
 *  member.
 *  f. Print the information in each structure.
 *  g. Print the class average for each of the numeric structure members.
 */
#include <stdio.h>
#include <ctype.h>

#define NAMELEN 40
#define GRADES 3
#define CSIZE 4

struct name {
    char first[NAMELEN];
    char second[NAMELEN];
};

struct student {
    struct name name;
    float scores[GRADES];
    float avg;
};

void acqinfo(struct student* student);
void calcavg(struct student* student);
void printinfo(struct student* student);
void printclassavg(int n, struct student student[n]);

int main(void)
{
    int i;
    struct student students[CSIZE];

    for(i = 0; i < CSIZE; i++)
    {
        acqinfo(&students[i]);
        calcavg(&students[i]);
    }
    printf("Given array of students: \n");
    for(i = 0; i < CSIZE; i++)
    {
        printf("student[%d]: { ", i);
        printinfo(&students[i]);
        printf(" }\n");
    }

    printclassavg(CSIZE, students);

    return 0;
}

void acqinfo(struct student* student)
{
    printf("Enter a student first name:\n");
    scanf("%s", student->name.first);
    printf("Enter a student second name:\n");
    scanf("%s", student->name.second);
    printf("Enter a students scores (e.g. 3.1 4.0 5):\n");
    for(int i = 0; i < GRADES; i++)
    {
        student->scores[i] = 0;
        scanf("%f", &student->scores[i]);
    }
}

void calcavg(struct student* student)
{
    float total;
    total = 0;

    for(int i = 0; i < GRADES; i++)
        total += student->scores[i];
    student->avg = total / GRADES;
}

void printinfo(struct student* student)
{
    printf("%s %s, ", student->name.first, student->name.second);
    printf("scores: ");
    for(int i = 0; i < GRADES; i++)
        printf("%.2f ", student->scores[i]);
    printf("\b");
    printf(", average: %.2f", student->avg);
}

void printclassavg(int n, struct student student[n])
{
    int i;
    float total = 0;

    for(i = 0; i < n; i++)
        total += student[i].avg;

    printf("Class average: %.2f\n", total * 1.0 / n);
}