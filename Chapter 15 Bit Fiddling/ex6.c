/* C Primer Plus. Programming Exercise 15.6
 */
#include <stdio.h>

#define ID_MASK 255
#define SIZE_MASK

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
void changefont(struct font settings);
void changesize(struct font settings);
void changealignment(struct font settings);
void togglebold(struct font settings);
void toggleitalic(struct font settings);
void toggleunderline(struct font settings);

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
                changefont(settings);
                break;
            case 's':
                changesize(settings);
                break;
            case 'a':
                changealignment(settings);
                break;
            case 'b':
                togglebold(settings);
                break;
            case 'i':
                toggleitalic(settings);
                break;
            case 'u':
                toggleunderline(settings);
                break;
            default:
                break;
        }
    }

    return 0;
}

void changefont(struct font settings)
{
    int id;
    printf("Enter font ID (0-255): ");
    scanf("%d", &id);

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