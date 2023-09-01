/* C Primer Plus. Programming Exercise 8.8
 * Write a program that shows you a menu offering you the choice of addition, subtraction,
 * multiplication, or division. After getting your choice, the program asks for two numbers,
 * then performs the requested operation. The program should accept only the offered
 * menu choices. It should use type float for the numbers and allow the user to try again
 * if he or she fails to enter a number. In the case of division, the program should prompt
 * the user to enter a new value if 0 is entered as the value for the second number. A typical
 * program run should look like this:
 * Enter the operation of your choice:
 * a. add s. subtract
 * m. multiply d. divide
 * q. quit
 * a
 * Enter first number: 22 .4
 * Enter second number: one
 * one is not an number.
 * Please enter a number, such as 2.5, -1.78E8, or 3: 1
 * 22.4 + 1 = 23.4
 * Enter the operation of your choice:
 * a. add s. subtract
 * m. multiply d. divide
 * q. quit
 * d
 * Enter first number: 18.4
 * Enter second number: 0
 * Enter a number other than 0: 0.2
 * 18.4 / 0.2 = 92
 * Enter the operation of your choice:
 * a. add s. subtract
 * m. multiply d. divide
 * q. quit
 * q
 * Bye.
 */
#include <stdio.h>

float getfl(void);

int main(void){
    char choice, op;
    float a, b, c;

    printf("Enter the operation of your choice:\n"
           "a. add s. subtract\n"
           "m. multiply d. divide\n"
           "q. quit\n");
    while ((choice = getchar()) != 'q'){
        while (getchar() != '\n')
            continue;
        printf("Enter first number: ");
        a = getfl();
        printf("Enter second number: ");
        b = getfl();
        switch (choice) {
            case 'a':
                c = a + b;
                op = '+';
                break;
            case 's':
                c = a - b;
                op = '-';
                break;
            case 'm':
                c = a * b;
                op = '*';
                break;
            case 'd':
                while (b < 1e-6){
                    printf("Enter a number other than 0: ");
                    b = getfl();
                }
                c = a / b;
                op = '/';
                break;
            default:
                printf("Enter the operation of your choice:\n"
                       "a. add s. subtract\n"
                       "m. multiply d. divide\n"
                       "q. quit\n");
                continue;
        }
        printf("%f %c %f = %f\n", a, op, b, c);
        printf("Enter the operation of your choice:\n"
               "a. add s. subtract\n"
               "m. multiply d. divide\n"
               "q. quit\n");
    }
    printf("Bye.");
    return 0;
}

float getfl(void){
    float fl;
    char ch;

    while (scanf("%f", &fl) != 1){
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
    }
    while (getchar() != '\n')
        continue;
    return fl;
}