/* C Primer Plus. Programming Exercise 7.3
 * Write a program that reads integers until 0 is entered. After input terminates, the
 * program should report the total number of even integers (excluding the 0) entered, the
 * average value of the even integers, the total number of odd integers entered, and the
 * average value of the odd integers.
 */
#include <stdio.h>

int main(void){
    int n;
    int evn_cnt, odd_cnt;
    float evn_sum, odd_sum;

    evn_cnt = odd_cnt = 0;
    evn_sum = odd_sum = 0.0f;
    while (scanf("%d", &n) && n != 0){
        if (n % 2 == 0){
            evn_cnt++;
            evn_sum += n;
        } else {
            odd_cnt++;
            odd_sum += n;
        }
    }

    if(evn_cnt > 0){
        printf("Total even numbers: %d\n", evn_cnt);
        printf("Average value of even numbers: %.2f\n", evn_sum/evn_cnt);
    }

    if(odd_cnt > 0){
        printf("Total odd numbers: %d\n", odd_cnt);
        printf("Average value of odd numbers: %.2f\n", odd_sum/odd_cnt);
    }

    return 0;
}
