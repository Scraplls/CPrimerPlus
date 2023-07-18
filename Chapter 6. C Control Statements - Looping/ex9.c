/* C Primer Plus. Programming Exercise 6.9
 * Modify exercise 8 so that it uses a function to return the value of the calculation.
 */
#include <stdio.h>
float calculate(float a, float b);

int main(void){
    float a, b;

    printf("Enter two decimal numbers: ");
    while (scanf("%f%f", &a, &b) == 2){
        printf("(a-b)/a*b = %.2f\n", calculate(a, b));
        printf("Enter another two numbers (non-numeric to quit): ");
    }

    return 0;
}

float calculate(float a, float b){
    return (a - b) / (a * b);
}