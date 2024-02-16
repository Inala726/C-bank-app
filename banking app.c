#include <stdio.h>
#include <string.h>

float balance;
int pin = 1234;

void startBankApp(int expectedPin){
	printf("Enter your four digit personal identification number: ");
	scanf("%d", &expectedPin);
	if(expectedPin == pin){
		printf("Welcome to this ATM \n");
		displayMenu();
		int option;
		scanf("%d", &option);
		switch(option){
			case 1:
				deposit();
			  break;
			case 2:
				withdrawal();
			  break;
			case 3:
				checkBalance();
			  break;
			case 4:
				printf("Thank youfor choosing  ATM");  
			default:
				printf("Invalid choice");
		};
		rerunFunction();
	}else{
		printf("Incorrect pin,\nTry again\n");
		startBankApp(expectedPin);
	}
};



void displayMenu(){
	printf("Kindly select your preferred transaction;\n");
	printf("1:Deposit\n");
	printf("2:Withdrawal\n");
	printf("3:Check Balance\n");
//	printf("4:Change Pin\n");
	printf("4:Exit\n\n");
};


int deposit(){
	int amount;
	printf("Enter the amount to be deposited: ");
	scanf("%d", &amount);
	if(amount > 0){
		balance += amount;
		printf("$%d has been sucessfully deposited into your account", amount);
	}
	else{
		printf("Invalid amount");
	}
};


int withdrawal(){
	int amount;
	printf("Enter the amount to be witdrawn: ");
	scanf("%d", &amount);
	if(amount > 0 && amount < balance){
		balance -= amount;
		printf("$%d has been sucessfully withdrawn from your account", amount);
	}
	else{
		printf("Insufficient fund");
	}	
};


void checkBalance(){
	printf("Your balance is $%.2f\n", balance);
};

//void changePin(char expectedPin[]){
//	char inputedPin[];
//	printf("Enter your current pin: ");
//	scanf("%s", &inputedPin);
//	if(inputedPin == expectedPin){
//		char newPin];
//		printf("Enter your preferred new pin: ");
//		scanf("%s", &newPin);
//		newPin = expectedPin;
//	}
//};

void rerunFunction(){
	int choice;
	printf("\n\nDo you want to perform another transaction??:\n1:Yes\n2:No\n\n");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			startBankApp(1234);
		break;
		case 2:
			printf("Thank you for banking with us.\n");
		break;
		default:
			printf("Invalid choice\n");
			printf("\nPlease re-confirm your choice:\n1:Yes\n2:No\n\n");
			scanf("%d", &choice);
	}
};

int main(){
	startBankApp(1234);
}





