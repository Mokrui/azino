#include "Header.h"

HANDLE mokryi = GetStdHandle(STD_OUTPUT_HANDLE);


void gotoxy(int x, int y) {
COORD p = { x,y };  // STANDART 80/20
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void balance(int bal){
	
	SetConsoleTextAttribute(mokryi, 2);
	gotoxy(80, 2);
	cout << "$ " << bal;
	SetConsoleTextAttribute(mokryi, 7);
	gotoxy(0, 0);
}

void topUp(int *bal){
	system("cls");
	int topup = 0;
	cout << "Your balance: " << *bal<<endl;
	cout << "Enter how much u want to Top Up: ";
	cin >> topup;
	*bal += abs(topup);
	cout << "\nSucessfully added!\n\t Press any key to PLAY...";
	SetConsoleTextAttribute(mokryi, 0);
	system("pause");
	SetConsoleTextAttribute(mokryi, 7);
	play(bal);
}


void play(int* bal) {
	srand(time(0));

	int count = 0;
	int choose = 0;
	int winNum = rand() % 15 + 1;
	
	system("cls");
	balance(*bal);
	cout << "One try costs: 200$\n";
	if (*bal < 200) {
		cout << "Not enough money, press any key to go to Top Up menu\n";
		SetConsoleTextAttribute(mokryi, 0);
		system("pause");
		SetConsoleTextAttribute(mokryi, 7);
		topUp(bal);
	}
	else {
		do {
			system("cls");
			balance(*bal);
			if (count > 0) cout << "Try again!\n";
			cout << "U will win this time!\nChoose num (1-15):";
			cin >> choose;
			count++;
			*bal -= 200;
			if (*bal < 200) {
				balance(*bal);
				cout << "Press any key to Top Up balance and TRY AGAIN";
				SetConsoleTextAttribute(mokryi, 0);
				system("pause");
				SetConsoleTextAttribute(mokryi, 7);
				topUp(bal);
				play(bal);
			}
			if (choose == winNum) {
				system("cls");
				cout << "You win!\n1.One more time \n2.Exit";
				cin >> choose;
				switch (choose) {
				case 1:play(bal);
					break;
				case 2:
					system("pause");
					break;
				}
			}
		} while (count != 5);
		system("cls");
		cout << "\nNext time u will 100% win.\n\t Try and take a revard";
		SetConsoleTextAttribute(mokryi, 0);
		system("pause");
		SetConsoleTextAttribute(mokryi, 7);
		play(bal);
	}
}