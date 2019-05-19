#include <stdio.h>
#include <stdlib.h>
int ascending(int a[], int j, int i)
{
	int x;
	for (int k = j + 1; k < i; k++)//vd j=0, thi xet tu k=1 tro di neu ak nho hon aj thi ak thay cho aj. sau do j++ o ham main.
	{
		if (a[k] < a[j])
		{
			x = a[j];
			a[j] = a[k];
			a[k] = x;
		}
	}
	return a[j];
}
int descending(int a[], int j, int i)
{
	int x;
	for (int k = j + 1; k < i; k++)
	{
		if (a[k] > a[j])
		{
			x = a[j];
			a[j] = a[k];
			a[k] = x;
		}
	}
	return a[j];
}
int main()
{
	int a[100], i, size;
	printf("Please enter size of array: ");
	scanf("%d", &size);
	for (i = 0; i < size; i++)
	{
		printf("Enter element[%d]: ", i);
		scanf("%d", &a[i]);
	}
	printf("\nThe array sorted in ascending:\n");
	for (int j = 0; j < i; j++)
		printf("%d\t", ascending(a, j, i));
	printf("\n\nThe array sorted in descending:\n");
	for (int j = 0; j < i; j++)
		printf("%d\t", descending(a, j, i));
	printf("\n");
	system("pause");
}
