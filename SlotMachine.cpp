#include<stdio.h>
#include<stdlib.h>
#include<time.h>
double checkacc(){
	double n;
	FILE* fp;
	fp = fopen("ketqua.txt", "r+");
	fscanf(fp, "%lf", &n);
	return n;
}

double play(double sum) {
	int a, b, c, bc, abc;
	sum -= 0.25;
	a = rand() % 10;
	b = rand() % 10;
	c = rand() % 10;
	printf("The slot machine shows %d%d%d\n", a,b,c);
	if (a == b && b == c)
	{
		printf("You won 3 of a kind!\n");
		sum += 10;
	}
	else if (a != b && b != c && c != a)
	{
		printf("Sorry you did not win anything.\n");
	}
	else
	{
		printf("You won 2 of a kind!\n");
		sum += 0.5;
	}
	return sum;
}

void save(double sum) {
	FILE* fp;
	fp = fopen("ketqua.txt", "w+");
	fprintf(fp, "%lf", sum);
	printf("You have saved $%lf into your account.\n", sum);
}

int main() {
	srand(time(NULL));
	double sum = checkacc();
	if(sum==0)
	sum=10;
	for (; ;)
	{
		int choice;
		printf("You have $%lf\n", sum);
		printf("Choose one of the following menu options:\n");
		printf("1) Play the slot machine\n");
		printf("2) Save game\n");
		printf("3) Cash out\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			if (sum <= 0)
			{
				FILE* fp;
				fp = fopen("ketqua.txt", "w+");
				fprintf(fp, "%lf", 10);
				printf("Sorry, you have no money left. Good luck next time!\n");
				break;
			}
			else
				sum = play(sum);
		}
		if (choice == 2)
		{
			save(sum);
		}
		if (choice == 3)
		{
			printf("$%lf is now be yours.\n", sum);
			break;
		}
	}
	system("pause");
}

