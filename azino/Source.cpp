#include"Header.h"

int main() {
	int bal=0;
	HANDLE mokryi = GetStdHandle(STD_OUTPUT_HANDLE);
	do {
		system("cls");
		balance(bal);
		int choose = 0;
		cout << "1. Top up balance " << endl;
		cout << "2. PLAY " << endl;
		cout << "3. exit " << endl;
		cout << "Choose: ";
		cin >> choose;
		switch (choose) {
		case 1:
			topUp(&bal);
			break;
		case 2:
			play(&bal);
			break;
		case 3:
			system("cls");
			cout << "Bye";
			SetConsoleTextAttribute(mokryi, 0);
			system("pause");
			return 0;
			break;
		}

	} while (true);
}