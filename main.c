#include <stdio.h>
#include <stdbool.h>

struct S
{
    // will usually occupy 8 bytes:
    // 5 bits: value of b1
    // 27 bits: unused
    // 6 bits: value of b2
    // 15 bits: value of b3
    // 11 bits: unused
    bool b1 : 1;
    bool b2 : 1;
    bool b3 : 1;
    bool b4 : 1;
    bool b5 : 1;
    bool b6 : 1;
    bool b7 : 1;
    bool b8 : 1;
};

int main(void)
{
    struct S s = {1, 1, 0, 1, 1, 0, 1, 0};
    s.b2;
    printf("%d\n", s.b2); // usually prints 8
}