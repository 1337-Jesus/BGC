#include "Header.h"

using std::cout;
using std::cin;

void sayHello() {
	cout << "Hello and welcome to the game collection!\n";
}

void congratulation() {
	cout << "Congratulations, you have guessed the secret number!\n";
}

unsigned int setRandomNumber(std::mt19937 seed) {
	std::uniform_int_distribution<> randNum{ 1,999 };
	unsigned int randomNumber{  };
	randomNumber = randNum(seed);
	return randomNumber;
}

unsigned int setTryCount() {
	unsigned int tryCount = 6;
	return tryCount;
}

unsigned int userGuess() {
	unsigned int userGuess{};
	cout << "Enter a non negativ number and press return: \n";
	cin >> userGuess;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
	};
	return userGuess;
}
char playAgain() {
	std::cout << "Do you want to play again? press \'y\' for yes or any key for no.\n ";
	char againSwitch{ 'y' };
	cin >> againSwitch;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "That was a not a single key.";
	}
	return againSwitch;
}

enum GAMESMENU {
	DUMMY,
	NUMBERGUESSINGGAME,
	WORDGUESSINGGAME,
	EXIT,
};




int main(void) {
	//Welcome player and init game state
	cout << "Hello and welcome to the boring game collection! The most boring games ever.....\n";
	cout << "\n";

	int choice{};
	GAMESMENU choosengame{ static_cast<GAMESMENU>(choice) };

	do {
		cout << "Choose a game by pressing a number:\n";
		cout << "1		Number guessing Game\n";
		cout << "2		Word guessing Game\n";
		cout << "3		Exit Menu\n";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
		};
		GAMESMENU choosengame{ static_cast<GAMESMENU>(choice) };

		switch (choosengame) {
		case 1:
			numberGuessingGame();
			break;
		case 2:
			wordGuessingGame();
			break;
		case 3:
			cout << "cya soon\n";
			cout << "\n";
			break;
		default:
			cout << "This was not a valid choice!\n";
			cout << "\n";
			break;
		};
	} while (choice != 3);

	cout << "Thanks for playing the boring game collection. See ya soon.....\n";
	return 0;
}
