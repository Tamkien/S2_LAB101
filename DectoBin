#include <stdio.h>
#include <stdlib.h>
int main(){
	int a[100], n, i, k = -1;
	printf("\nDecimal to binary converter\n");
	while (1)
	{
		printf("Enter a positive integer here:\t");
		scanf("%d", &n);
		printf("Your binary is ");
		for (i = 0; n > 0; ++i)
		{
			a[i] = n % 2;
			n /= 2;
			k++;
		}
		for (k; k >= 0; k--)
			printf("%d", a[k]);
		printf("\n");
		system("pause");
	}
}
