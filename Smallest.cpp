#include <stdio.h>
#include <stdlib.h>
void ext() {
	exit(0);
}
void print(int min, int tt[], int k) {
	printf("The smallest element: %d - Its position: ", min);
	for (int i = 0; i < k; ++i)
		printf("%d ", tt[i]);
	printf("\n");
	system("pause");
	ext();
}

void minimum(int a[], int size) {
	int min = INT_MAX, tt[100], k = 0;
	for (int i = 0; i < size; i++)
		if (a[i] < min) {
			min = a[i];
		}
	for (int i = 0; i < size; ++i)
		if (a[i] == min)
		{
			tt[k] = i;
			k++;
		}
	print(min, tt, k);
}
int main(int argc, char const* argv[])
{
	int size, value[100];
	printf("Enter the size of array: ");
	scanf_s("%d", &size);
		for (int i = 0; i < size; ++i)
		{
			printf("Element[%d] = ", i);
			scanf_s("%d", &value[i]);
		}
	minimum(value, size);
}
