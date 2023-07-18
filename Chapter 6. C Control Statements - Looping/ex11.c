/* C Primer Plus. Programming Exercise 6.11
 * Write a program that reads eight integers into an array and then prints them in reverse
 * order.
 */
#include <stdio.h>
#define INPUT_SIZE 8

int main(void){
    int arr[INPUT_SIZE];
    int i;

    printf("Enter eight integers to fill an array: \n");
    for(i = 0; i < INPUT_SIZE; i++)
        scanf("%d", &arr[i]);
    printf("Reversed array is [");
    for(i = INPUT_SIZE - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\b]\n");

    return 0;
}