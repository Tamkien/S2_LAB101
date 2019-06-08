#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int roll() {
	int k, size;
	char play, * c;
	c = (char*)malloc(size);
	gets(c);
	if (strlen(c) == 1 && c[0] == 'r') {
		k = 2 + rand() % 11;
		printf("You rolled a %d.\n", k);
		return k;
	}
	else {
		printf("Please enter 'r'!\n");
		roll();
	}
}
int arup(int chip) {
	int again, k, bet, size;
	char* c;
	printf("How may chips would you like to bet?\n");
	c = (char*)malloc(size);
	gets(c);
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < 48 || c[i]>57) {
			printf("Invalid input!!!\n");
			return 0;
		}
	}
	bet = atoi(c);
	if (bet > chip || bet < 1){
		printf("Sorry, that is not allowed. No game played.\n");
		return 0;
	}
	else{
		printf("Press 'r' and hit enter for your first roll.\n");
		do {
			k = roll();
			if (k == 12 || k == 11){
				printf("You win!\n");
				return bet;
			}
			else if (k == 2){
				printf("Sorry, you have lost!\n");
				return -bet;
			}
			else {
				printf("Press 'r' and hit enter for your next roll.\n");
				again = roll();
				if (again > k){
					printf("You win!\n");
					return bet;
				}
				else	{
					printf("Sorry, you have lost!\n");
					return -bet;
				}
			}
		} while (1);
	}
}
int crab(int chip) {
	int again, k, bet, size;
	char* c;
	printf("How may chips would you like to bet?\n");
	c = (char*)malloc(size);
	gets(c);
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < 48 || c[i]>57) {
			printf("Invalid input!!!\n");
			return 0;
		}
	}
	bet = atoi(c);
	if (bet > chip || bet < 1){
		printf("Sorry, that is not allowed. No game played.\n");
		return 0;
	}
	else{
		printf("Press 'r' and hit enter for your first roll.\n");
		k = roll();
		if (k == 7 || k == 11){
			printf("You win!\n");
			return bet;
		}
		else if (k == 2 || k == 3 || k == 12){
			printf("Sorry, you have lost!\n");
			return -bet;
		}
		else {
			printf("Press 'r' and hit enter for your next roll.\n");
			do {
				again = roll();
				if (again == k){
					printf("You win!\n");
					return bet;
				}
				else if (again == 7){
					printf("Sorry, you have lost!\n");
					return -bet;
				}
				else printf("Press 'r' and hit enter for your next roll.\n");
			} while (1);
		}
	}
}
void stat(int tong, int chip) {
	printf("You currently have $%d left and %d chip(s).\n", tong, chip);
}
int sell(int chip) {
	int soluong, size;
	char* c;
	printf("How many chips do you want to sell?\n");
	c = (char*)malloc(size);
	gets(c);
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < 48 || c[i]>57) {
			printf("Invalid input!!!\n");
			return 0;
		}
	}
	soluong = atoi(c);
	if (soluong > chip)
		printf("Sorry, you do not have that many chips. No chips sold.\n");
	else
		return soluong;
	return 0;
}
int buy(int tong) {
	int tieu, chip, size;
	char* c;
	printf("How much cash do you want to spend for chips?\n");
	c = (char*)malloc(size);
	gets(c);
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] < 48 || c[i]>57) {
			printf("Invalid input!!!\n");
			return 0;
		}
	}
	tieu = atoi(c);
	if (tieu > tong)
		printf("Sorry, you do not have that much money. No chips bought.\n");
	else if (tieu < 1) {
		printf("Invalid input!\n");
	}
	else{
		chip = tieu / 11;
		return chip;
	}
	return 0;
}
void quit(int tong, int chip) {
	tong += chip * 10;
	printf("After selling your chips, you have $%d. Thanks for playing!\n", tong);
	system("pause");
	exit(0);
}
int main() {
	srand((int)time(0));
	int tong = 1000, chip = 0, choice, giaodich, size;
	char* choicechar;
	for (;;){
		printf("Welcome to the Casino. Here are your choices:\n1) Buy chips\n2) Sell chips\n3) Play Crabs\n4) Play Arup's Game of Dice\n5) Status Report\n6) Quit\n");
		choicechar = (char*)malloc(size);
		gets(choicechar);
		if (strlen(choicechar) != 1) printf("Invalid input!!\n");
		else {
			choice = atoi(choicechar);
			switch (choice){
			case 1:{
				giaodich = buy(tong);
				chip += giaodich;
				tong -= giaodich * 11;
				break;
			}
			case 2:{
				giaodich = sell(chip);
				chip -= giaodich;
				tong += giaodich * 10;
				break;
			}
			case 3:{
				chip += crab(chip);
				break;
			}
			case 4:{
				chip += arup(chip);
				break;
			}
			case 5:{
				stat(tong, chip);
				break;
			}
			case 6:{
				quit(tong, chip);
				break;
			}
			default:{
				printf("Invalid input!\n");
				break;
			}
			}
		}
	}
}
