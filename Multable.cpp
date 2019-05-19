#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void enteroresc() {
    do
    {
        char ch = getch();
        fflush(stdin);
        if (ch == 13) break;
        else if (ch == 27)  exit(0); 
    } while (1);
}
char multable(int c) {
	int n = c - 48;
	char key;
	for (int i = 0; i < 11; ++i)
	{
		printf("%d x %d = %d\n", n, i, n * i);
	}
	printf("------------------------------------------\n");
	printf("Press Enter to continue, Esc to exit.\n");
	return key;
}
int main() {
	char c;
	int n;
	for (;;)
	{
		printf("Please enter a number (1 to 9): ");
		scanf("%c", &c);
		fflush(stdin);
		if (c < 48 || c>57)
		{
			printf("Invalid input!\n");
			printf("------------------------------------------\n");
			printf("Press Enter to continue, Esc to exit.\n");
			enteroresc();
		}
		else
		{
			multable(c);
			enteroresc();
		}
	}
}
