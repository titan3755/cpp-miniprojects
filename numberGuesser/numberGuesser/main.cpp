#include <iostream>
#include <random>

int main(int argc, char* argv[]) {
	std::random_device rndv; 
	std::mt19937 mstwr(rndv());

	std::cout << "\nWelcome to the Number Guesser game!" << std::endl;
	std::cout << "\nSelect the difficulty level:" << std::endl;
	std::cout << "1. Easy (1-10)" << std::endl;
	std::cout << "2. Medium (1-50)" << std::endl;
	std::cout << "3. Hard (1-100)" << std::endl;
	int difficulty = 0;

	while (difficulty < 1 || difficulty > 3) {
		std::cout << "\nEnter your choice (1-3): ";
		std::cin >> difficulty;
		if (std::cin.fail() || difficulty < 1 || difficulty > 3) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			difficulty = 0;
			std::cout << "Invalid choice. Please try again." << std::endl;
		}
	}

	int range = 0;
	switch (difficulty) {
		case 1: range = 10; break; // Easy
		case 2: range = 50; break; // Medium
		case 3: range = 100; break; // Hard
		default: std::cout << "Invalid difficulty level." << std::endl; return 1;
	}

	int number = mstwr() % range + 1;
	std::cout << "\nI have selected a number between 1 and " << range << ". Try to guess it!" << std::endl;
	int guess = 0;
	int attempts = 0;

	while (guess != number) {
			std::cout << "Enter your guess: ";
			std::cin >> guess;
			if (std::cin.fail() || guess < 1 || guess > range) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				guess = 0;
				std::cout << "Invalid input. Please enter a number between 1 and " << range << "." << std::endl;
				continue;
			}
			if (guess < number) {
				std::cout << "Too low! Try again." << std::endl;
			} else if (guess > number) {
				std::cout << "Too high! Try again." << std::endl;
			} else {
				std::cout << "\nCongratulations! You've guessed the number: " << number << std::endl;
			}
			attempts++;
	}

	std::cout << "You guessed the number in " << attempts << " attempts." << std::endl;
	switch (difficulty) {
		case 1: std::cout << "You played on Easy mode." << std::endl;
			if (attempts <= 3) {
				std::cout << "Great job! You guessed it quickly!" << std::endl;
			} else if (attempts <= 5) {
				std::cout << "Good effort! You took a few tries." << std::endl;
			} else {
				std::cout << "You took quite a few attempts, but you got it!" << std::endl;
			}
			break;
		case 2: std::cout << "You played on Medium mode." << std::endl;
			if (attempts <= 5) {
				std::cout << "Well done! You guessed it in a reasonable number of attempts!" << std::endl;
			} else if (attempts <= 8) {
				std::cout << "Good job! You took a few tries." << std::endl;
			} else {
				std::cout << "You took some time, but you got there!" << std::endl;
			}
			break;
		case 3: std::cout << "You played on Hard mode." << std::endl;
			if (attempts <= 8) {
				std::cout << "Impressive! You guessed it in a few attempts!" << std::endl;
			} else if (attempts <= 12) {
				std::cout << "Good work! You took a moderate number of tries." << std::endl;
			} else {
				std::cout << "It took you a while, but you finally guessed it!" << std::endl;
			}
			break;
		default: std::cout << "Invalid difficulty level." << std::endl; break;
	}

	std::cout << "\nPlay again? (y/n): ";
	char playAgain;
	std::cin >> playAgain;
	if (playAgain == 'y' || playAgain == 'Y') {
		std::cout << "Restarting the game..." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// clear the console (optional, platform-specific)
		std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear the console
		main(argc, argv);
	} else {
		std::cout << "Thanks for playing! Goodbye!" << std::endl;
	}

	return 0;
}