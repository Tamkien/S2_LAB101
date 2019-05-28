#include <stdio.h>
#include <stdlib.h>
#include<math.h>
void f7(double a[], int sogtri, int avg) {
	double sd, n = 0;
	for (int i = 0; i < sogtri; i++)
		n += 1 / (double)sogtri * pow((a[i] - avg), 2.0);
	sd = sqrt(n);
	printf("The ajusted standard deviation is %0.2lf\n\n", sd);
}
void f6(double a[], int sogtri) {
	double avg = 0;
	for (int i = 0; i < sogtri; ++i)
		avg += (a[i] / sogtri);
	printf("The ajusted mean is %0.2lf\n\n", avg);
	f7(a, sogtri, avg);
}
void f5(double a[], int sogtri, int tt) {
	for (int i = tt; i < sogtri; i++)
		a[i] = a[1 + i];
}
void f4(double a[], int sogtri) {
	double min = 100, tt = 0;
	sogtri--;
	for (int i = 0; i < sogtri; i++)
		if (a[i] < min) {
			min = a[i];
			tt = i;
		}
	printf("The data has been adjusted by removing the minimum %0.2lf\n\n", min);
	f5(a, sogtri, tt);
	sogtri--;
	f6(a, sogtri);
}
void f3(double a[], int sogtri) {
	double max = 0, tt = 0;
	for (int i = 0; i < sogtri; i++)
		if (a[i] > max) {
			max = a[i];
			tt = i;
		}
	printf("The data has been adjusted by removing the maximum %0.2lf\n\n", max);
	f5(a, sogtri, tt);
}
void f2(double value[], int sogtri) {
	int frequency[21] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, k = 0;
	for (int i = 0; i <= 100; i += 5)
		for (int k = 0; k < sogtri; ++k)
			if (value[k] >= i && value[k] <= (i + 4.0))
				frequency[i / 5]++;
	printf("\nHere is a histogram of the data:\n");
	printf(" 0- 4|");
	for (int i = 0; i < frequency[0]; ++i)
		printf("*");
	printf("\n 5- 9|");
	for (int i = 0; i < frequency[1]; ++i)
		printf("*");
	for (int i = 10; i <= 95; i += 5) {
		printf("\n%d-%d|", i, i + 4);
		for (int k = 0; k < frequency[i / 5]; k++)
			printf("*");
	}
	printf("\n  100|");
	for (int i = 0; i < frequency[20]; ++i)
		printf("*");
	printf("\n\n");
}
int main() {
	double value[100];
	int i = 0;
	printf("Please enter the number(s), enter -999 to finish:\n");
	for (i; i < 101; ++i) {
		if (i == 100) {
			printf("You can enter at most 100 values only! The program will analize 100 previous values only!\n");
			i--;
			break;
		}
		printf("a[%d] = ", i);
		scanf_s("%lf", &value[i]);
		if (value[0] == -999 || value[1] == -999) {
			printf("Sorry, you must enter at least 3 values!\n");
			i--;
		}
		if (value[i] == -999) break;
		if ((value[i] < 0 || value[i]>100) && value[i] != -999) {
			printf("Sorry, you must enter a value between 0 and 100!\n");
			i--;
		}
	}
	f2(value, i);//frequency
	f3(value, i);
	f4(value, i);//find out the largest (f3), smallest(f4) and delete (f5)
	system("pause");
}
