/* C Primer Plus. Programming Exercise 6.13
 * Write a program that creates an eight-element array of ints and sets the elements to the
 * first eight powers of 2 and then prints the values. Use a for loop to set the values, and,
 * for variety, use a do while loop to display the values.
 */
#include <stdio.h>
#define ARRAY_SIZE 8

int main(void){
    int i;
    int arr[ARRAY_SIZE];

    arr[0] = 1;
    for(i = 1; i < ARRAY_SIZE; i++)
        arr[i] = 2 * arr[i - 1];
    i = 0;
    printf("First eight powers of 2: ");
    do {
        printf("%d, ", arr[i]);
    } while(++i < ARRAY_SIZE);
    printf("\b\b ");

    return 0;
}