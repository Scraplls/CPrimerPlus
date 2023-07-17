/* C Primer Plus. Programming Exercise 5.4
 * Write a program that asks the user to enter a height in centimeters and then displays the
 * height in centimeters and in feet and inches. Fractional centimeters and inches should
 * be allowed, and the program should allow the user to continue entering heights until a
 * nonpositive value is entered. A sample run should look like this:
 * Enter a height in centimeters: 182
 * 182.0 cm = 5 feet, 11.7 inches
 * Enter a height in centimeters (<=0 to quit): 168.7
 * 168.7 cm = 5 feet, 6.4 inches
 * Enter a height in centimeters (<=0 to quit): 0
 * bye
 */
#include <stdio.h>

int main(void)
{
    const float inch_in_feet = 12.0f;
    const float cm_in_inch = 2.54f;
    float height;

    printf("Enter a height in centimeters: ");
    scanf("%f", &height);
    while (height > 0)
    {
        printf("%.1f cm = %d feet, %.1f inches\n", height, (int) (height / (cm_in_inch * inch_in_feet)),
               height/cm_in_inch - ((int) (height / (cm_in_inch * inch_in_feet)) * inch_in_feet));
        printf("Enter a height in centimeters (<=0 to quit): \n");
        scanf("%f", &height);
    }
    printf("bye\n");

    return 0;
}
