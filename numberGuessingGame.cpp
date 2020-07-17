#include "Header.h"

void numberGuessingGame() {
	char playAgainChar{ 'y' };

	do {
		std::mt19937 mtseed{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
		unsigned int numberToGuess{ setRandomNumber(mtseed) };
		unsigned int tries{ setTryCount() };

		//player starts guessing
		unsigned int guess{ 0 };
		while (tries > 0)
		{
			unsigned int guess{ userGuess() };
			if (guess == numberToGuess)
			{
				congratulation();
				break;
			}
			else
			{
				--tries;
				if (tries > 0)
				{
					std::cout << "Try it again, you have " << tries << " tries left.\n";
					if (guess < numberToGuess)
						std::cout << "The secret number is higher than the value you have entered.\n";
					else
						std::cout << "The secret number is lower than the value you have entered.\n";
				}
				else {
					std::cout << "You have no tries left." << "The number was: " << numberToGuess << "\n";
					std::cout << "Game Over!\n";
				}
			}
		}
		playAgainChar = playAgain();
	} while (playAgainChar == 'y');
}
