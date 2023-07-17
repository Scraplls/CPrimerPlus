#include <stdio.h>

int main(void)
{
	char code;
	
	printf("Enter an ASCII code value:\n");
	scanf("%d", &code);
	printf("The character having ASCII code %d is %c.\n", code, code);
    return 0;
}