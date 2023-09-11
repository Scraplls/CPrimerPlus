/* C Primer Plus. Programming Exercise 15.6
 */
#include <stdio.h>

#define ID_MASK 255
#define SIZE_MASK 127

enum ALIGNMENT {
    LEFT, CENTER, RIGHT
};

struct font
{
    unsigned int font_id: 8;
    unsigned int font_size: 7;
    unsigned int alignment: 2;
    unsigned int bold: 1;
    unsigned int italic: 1;
    unsigned int underline: 1;
};

void printsettings(struct font *settings);
void changefont(struct font *settings);
void changesize(struct font *settings);
void changealignment(struct font *settings);

int main(void)
{
    int ch;
    struct font settings = {1, 12, 0, 0, 0, 0};

    printsettings(&settings);
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
                settings.bold = ~settings.bold;
                break;
            case 'i':
                settings.italic = ~settings.italic;
                break;
            case 'u':
                settings.underline = ~settings.underline;
                break;
            default:
                break;
        }
        printsettings(&settings);
        printf("f)change font   s)change size   a)change alignment\n"
               "b)toggle bold   i)toggle italic u)toggle underline\n"
               "q)quit\n");
    }
    printf("Bye!\n");
    return 0;
}

void changefont(struct font *settings)
{
    unsigned int id;
    printf("Enter font ID (0-255): ");
    scanf("%ud", &id);
    while (getchar() != '\n')
        continue;
    settings->font_id = id & ID_MASK;
}

void changesize(struct font *settings)
{
    unsigned int size;
    printf("Enter font size (0-127): ");
    scanf("%ud", &size);
    while (getchar() != '\n')
        continue;
    settings->font_size = size & SIZE_MASK;
}

void changealignment(struct font *settings)
{
    char ch;
    printf("Select alignment: \n"
           "l)left c)center r)right\n");
    ch = getchar();
    while (getchar() != '\n')
        continue;
    switch (ch) {
        case 'l':
            settings->alignment = LEFT;
            break;
        case 'c':
            settings->alignment = CENTER;
            break;
        case 'r':
            settings->alignment = RIGHT;
            break;
        default:
            printf("Invalid alignment!\n");
            break;
    }
}

void printsettings(struct font *settings)
{
    printf(" ID SIZE ALIGNMENT   B   I   U\n");
    printf("%3d ", settings->font_id);
    printf("%4d ", settings->font_size);
    switch(settings->alignment)
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
    printf("%3s ", settings->bold ? "on" : "off");
    printf("%3s ", settings->italic ? "on" : "off");
    printf("%3s ", settings->underline ? "on" : "off");
    printf("\n");
}