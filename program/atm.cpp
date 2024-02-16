#include <stdio.h>
#include <windows.h>
#include <time.h>


int main(){
	system("color 4f");
	 int pin=2007,option,theenteredPin,count=0,amount=1; // THE ENTERED PIN STORES THE VALU FOR THE PIN ENTERED
	 float balance = 5000;
	 int continueTrans = 1;
	
	time_t now;
	time(&now); //displays current date no matter the day
	printf("\n");
	printf("\t\t\t\t\t\t%s", ctime(&now));
	printf("\n\t\t\t====================""Welcome to ZION ATM====================");
	
	while(pin != theenteredPin){
		printf("\nPlease Enter Your Pin:");
		scanf("%d", &theenteredPin);
		if(theenteredPin != pin){ // this if statement means that if the pin above isnt the same as the one entered, the the atm beeps and shows invaild pin
			Beep(600,500); //the beep attribute whered the fist argument is the frequency and the second is the time in ms b4 it happens
			printf("Invalid Pin!");
		}
		count++;
		if(count == 3 && pin != theenteredPin){
			exit(0); // if the user inputs the wrong pin 3 times, he basicallly gets kicked out
		}
	}
	
		printf("\n\t\t\t====================""Available Transactions====================");
		printf("\n\n\t\t1. Withdraw");
		printf("\n\t\t2. Deposit");
		printf("\n\t\t3. Check My Balance");
		printf("\n\n\tPlease select the option: ");
		scanf("%d",&option);
		switch(option){  //using the switch statement, it'll take the user to the next step depending on the option chosen
			case 1:
				while(amount % 500 != 0){
					printf("\n\t\tEnter the amount: ");
					scanf("%d", &amount);
					if(amount % 500 !=0)
					printf("\n\tThis amount must be a multiple of 500"); // if the user enters an amount that isnt a multiple of 500
				}
				if(balance < amount){
					printf("\n\tSorry, insufficient funds");
					amount =1;
					break;
				}
				else {  //if the user satisfies the stratement and withdraws a value lower than his ac bal, then the amount he withdrew will be displayd and the remaining balance in his acc
					balance -= amount;
					printf("\n\tYou have withdrawn $%d. Your new Balance is %.2f",amount,balance);
					printf("\n\t\t Thank You for Banking with us");
					amount=1;
					break;
				}
				case 2:
					printf("\n\t\t Please enter the amount: ");
					scanf("%d", &amount);
					balance +=amount;
					printf("\n\t\t You have deposited $%d. Your new balance is %.2f",amount,balance); //this statement follows the same pattern as above, which is to show the amount you deposited and show your current balance
					printf("\n\t\t Thank You for Banking with us");
					amount =1;
					break;
					
			case 3:
			      printf("\n\t\t Your Balance is $%.2f",balance);
				  printf("\n\t\t Thank You for Banking with us");
				  break;
				  
				  default:
				  Beep(600,500);
				  printf("\n\t\t Invalid Option, Try Again");	
		}
	
	
	while(continueTrans != 0){
		printf("\n\t\t\t====================""Available Transactions====================");
		printf("\n\n\t\t1. Withdraw");
		printf("\n\t\t2. Deposit");
		printf("\n\t\t3. Check My Balance");
		printf("\n\n\tPlease select the option: ");
		scanf("%d",&option);
		switch(option){  //using the switch statement, itll take th user to the next step depending on the option chosen
			case 1:
				while(amount % 500 != 0){
					printf("\n\t\tEnter the amount: ");
					scanf("%d", &amount);
					if(amount % 500 !=0)
					printf("\n\tThis amount must be a multiple of 500"); // if the user enters an amount that isnt a multiple of 500
				}
				if(balance < amount){
					printf("\n\tSorry, Your Broke");
					amount =1;
					break;
				}
				else {  //if the user satisfies the stratement and withdraws a value lower than his ac bal, then the amount he withdrew will be displayd and the remaining balance in his acc
					balance -= amount;
					printf("\n\tYou have withdrawn $%d. Your new Balance is %.2f",amount,balance);
					printf("\n\t\t Thank You for Banking with us");
					amount=1;
					break;
				}
				case 2:
					printf("\n\t\t Please enter the amount: ");
					scanf("%d", &amount);
					balance +=amount;
					printf("\n\t\t You have deposited $%d. Your new balance is %.2f",amount,balance); //this statement follows the same pattern as above, which is to show the amount you deposited and show your current balance
					printf("\n\t\t Thank You for Banking with us");
					amount =1;
					break;
					
			case 3:
			      printf("\n\t\t Your Balance is $%.2f",balance);
				  printf("\n\t\t Thank You for Banking with us");
				  break;
				  
				  default:
				  Beep(600,500);
				  printf("\n\t\t Invalid Option, Try Again");	
		}
	printf("\n\t\tDo you wish to perform anoter transaction?Press 1[Yes] or 0[No]"); //basiaslly gives u theoption to perform another transaction
	scanf("%d" ,&continueTrans);
	}
	
	
	
	
	
	
	
	 return 0;
}
