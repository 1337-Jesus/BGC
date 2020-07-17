#include "Header.h"

void wordGuessingGame() {
	char secret[]{ "caal" }; // here the secret word is stored

	int letters{ (int)sizeof(secret) };
	char* actual{ new char[letters] {} }; //here input from actual try is stored - first try of dynamic memory allocation - seems to work =)


	int tries{ 10 };

	char userinput{ 0 };

	for (int counter = 0; counter < letters - 1; ++counter) {
		if (counter != letters)
			actual[counter] = '_';
		else
			actual[counter] = '\0';
	}

	for (int counter = letters - 1; counter > 0; --counter)
		std::cout << actual[counter];


	std::cout << "Welcome to the word guessing game!\n";
	std::cout << "The secret word has: " << letters - 1 << "\n";
	std::cout << "Start guessing: \n";

	while (tries > 0 && std::strcmp(actual, secret) != 0) {

		if (strcmp(actual, secret) != 0) {
			std::cout << "Enter a letter: \n";
			std::cin >> userinput;


			for (int counter = 0; counter < letters - 1; ++counter)
				if (userinput == secret[counter])
					actual[counter] = secret[counter];

			for (int counter = 0; counter < letters - 1; ++counter)
				std::cout << actual[counter];

			std::cout << "\n";
			--tries;
		}
		else {
			break;
		}

	}
	delete[] actual;
	std::cout << "You have found the secret word! You have won the Game \n";



}
