#include<stdio.h>
#include<stdlib.h>

void output(int sum){
	printf("Sum digit = %d\n", sum);
	system("pause");
}

void sumdg(int num){
	int sum=0;
	while(num>0){
		sum+=(num%10);
		num/=10;
	}
	output(sum);
}
main(){
	int num;
	for (;;){
	printf("Sum Digit Program\nEnter an integer = ");
	scanf("%d", &num);
	if(num<0)
		num=-num;
	sumdg(num);		
	}
}
