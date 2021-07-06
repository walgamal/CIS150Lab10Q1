/*

 *Author: Wasim Algamal

 *Creation Date: 11/18/2019

 *Modification Date: 11/20/2019

 *Purpose: Search through an array for a user integer

 ***NOTE: I ADDED AN ANIMATION FUNCTION AFTER TESTING	***
 ***BECAUSE I WAS CURIOUS						***

*/


using namespace std;
#include <iostream>
#include <Windows.h>

const int NUM_ROWS = 6;
const int NUM_COLS = 6;

int getUserInt(string intToString);
int searchArray(int array2D[NUM_ROWS][NUM_COLS], int userValue);
void searchAnimation();

int main() {

	int userVal;

	string intToString;
	int array2D[NUM_ROWS][NUM_COLS] = {
		{-101, -85, -71, -59, -34, -20 }, {-14, -12, -5, 0, 1, 7 }, {8, 20, 25, 35, 38, 40 },
		{44, 57, 60, 64, 66, 69 }, {77, 85, 102, 111, 153, 169 }, {178, 201, 251, 264, 287, 300 }
	};

	cout << "Enter an integer: ";
	cin >> intToString;

	userVal = getUserInt(intToString);

	searchAnimation();

	cout << endl;

	searchArray(array2D, userVal);

	system("pause");
	return 0;
}

int searchArray(int array2D[NUM_ROWS][NUM_COLS], int userValue) {

	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {

			if (array2D[i][j] == userValue) {

				cout << "Target " << userValue << " found at row " << i + 1 << ", column " << j + 1 << "!" << endl;
				return userValue;

			}
			else if (array2D[i][j] > userValue) {

				cout << "Sorry, target " << userValue << " was not found!" << endl;
				return -1;


			}
			else if (array2D[5][5] < userValue) {

				cout << "Sorry, target " << userValue << " was not found!" << endl;
				return -1;


			}

		}
	}
}

int getUserInt(string intToString) {

	bool leave;
	int userInteger = 0;

	do {

		leave = false;
		for (int i = 0; i < intToString.size(); ++i) {

			if (!isdigit(intToString[i]) && intToString[i] != '-') {

				leave = true;

			}

		}

		if (leave == true) {

			cin.clear();
			cin.ignore(1000, '\n');
			cout << "That is not an integer! Try again: ";
			cin >> intToString;

		}

	} while (leave == true);

	userInteger = atoi(intToString.c_str());

	return userInteger;
}


void searchAnimation() {

	cout << "Searching";

	for (int i = 0; i < 4; ++i) {
		for (int i = 0; i < 3; ++i) {
			cout << '.';
			Sleep(185);
		}
		if (i == 3)
			break;
		for (int i = 0; i < 3; ++i) {
			cout << '\b';
			Sleep(185);
		}
		for (int i = 0; i < 3; ++i) {
			cout << " ";
			Sleep(185);
		}
		for (int i = 0; i < 3; ++i) {
			cout << '\b';
			Sleep(185);
		}
	}
}
