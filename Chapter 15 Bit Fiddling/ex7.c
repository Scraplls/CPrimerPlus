/* C Primer Plus. Programming Exercise 15.7
 * Write a program with the same behavior as described in exercise 6, but use an unsigned
 * long variable to hold the font information and use the bitwise operators instead of bit
 * members to manage the information.
 */
#include <stdio.h>

#define ID_MASK 255
#define SIZE_MASK 127
#define ALIGN_MASK 3

#define ID_BITS 8
#define SIZE_BITS 7
#define ALIGN_BITS 2

enum ALIGNMENT {
    LEFT, CENTER, RIGHT
};

void printsettings(unsigned long settings);
void changefont(unsigned long *settings);
void changesize(unsigned long *settings);
void changealignment(unsigned long *settings);

int main(void)
{
    int ch;
    unsigned long settings = 0b00000000110000000001;

    printsettings(settings);
    printf("f)change font   s)change size   a)change alignment\n"
           "b)toggle bold   i)toggle italic u)toggle underline\n"
           "q)quit\n");
    while ((ch = getchar()) != 'q')
    {
        while (getchar() != '\n')
            continue;
        switch (ch) {
            case 'f':
                changefont(&settings);
                break;
            case 's':
                changesize(&settings);
                break;
            case 'a':
                changealignment(&settings);
                break;
            case 'b':
                settings = settings & ~(1 << (ID_BITS + SIZE_BITS + ALIGN_BITS)) |
                        ((~settings >> (ID_BITS + SIZE_BITS + ALIGN_BITS) & 1) << (ID_BITS + SIZE_BITS + ALIGN_BITS));
                break;
            case 'i':
                settings = settings & ~(1 << (ID_BITS + SIZE_BITS + ALIGN_BITS + 1)) |
                           ((~settings >> (ID_BITS + SIZE_BITS + ALIGN_BITS + 1) & 1) << (ID_BITS + SIZE_BITS + ALIGN_BITS + 1));
                break;
            case 'u':
                settings = settings & ~(1 << (ID_BITS + SIZE_BITS + ALIGN_BITS + 2)) |
                           ((~settings >> (ID_BITS + SIZE_BITS + ALIGN_BITS + 2) & 1) << (ID_BITS + SIZE_BITS + ALIGN_BITS + 2));
                break;
            default:
                break;
        }
        printsettings(settings);
        printf("f)change font   s)change size   a)change alignment\n"
               "b)toggle bold   i)toggle italic u)toggle underline\n"
               "q)quit\n");
    }
    printf("Bye!\n");
    return 0;
}

void changefont(unsigned long *settings)
{
    unsigned long id;
    printf("Enter font ID (0-255): ");
    scanf("%lu", &id);
    while (getchar() != '\n')
        continue;
    *settings &= ~ID_MASK;
    *settings |= id & ID_MASK;
}

void changesize(unsigned long *settings)
{
    unsigned long size;
    printf("Enter font size (0-127): ");
    scanf("%lu", &size);
    while (getchar() != '\n')
        continue;
    *settings = *settings & ~(SIZE_MASK << ID_BITS) | (size << ID_BITS);
}

void changealignment(unsigned long *settings)
{
    char ch;
    printf("Select alignment: \n"
           "l)left c)center r)right\n");
    ch = getchar();
    while (getchar() != '\n')
        continue;
    switch (ch) {
        case 'l':
            *settings = *settings & ~(ALIGN_MASK << (ID_BITS + SIZE_BITS)) | (LEFT << (ID_BITS + SIZE_BITS));
            break;
        case 'c':
            *settings = *settings & ~(ALIGN_MASK << (ID_BITS + SIZE_BITS)) | (CENTER << (ID_BITS + SIZE_BITS));
            break;
        case 'r':
            *settings = *settings & ~(ALIGN_MASK << (ID_BITS + SIZE_BITS)) | (RIGHT << (ID_BITS + SIZE_BITS));
            break;
        default:
            printf("Invalid alignment!\n");
            break;
    }
}

void printsettings(unsigned long settings)
{
    printf(" ID SIZE ALIGNMENT   B   I   U\n");
    printf("%3lu ", settings & (ID_MASK));
    printf("%4lu ", (settings >> (ID_BITS)) & SIZE_MASK);
    switch((settings >> (ID_BITS + SIZE_BITS)) & ALIGN_MASK)
    {
        case 0:
            printf("%10s", "left ");
            break;
        case 1:
            printf("%10s", "center ");
            break;
        case 2:
            printf("%10s", "right ");
            break;
        default:
            break;
    }
    printf("%3s ", (settings >> (ID_BITS + SIZE_BITS + ALIGN_BITS) & 1) ? "on" : "off");
    printf("%3s ", (settings >> (ID_BITS + SIZE_BITS + ALIGN_BITS + 1) & 1) ? "on" : "off");
    printf("%3s ", (settings >> (ID_BITS + SIZE_BITS + ALIGN_BITS + 2) & 1) ? "on" : "off");
    printf("\n");
}