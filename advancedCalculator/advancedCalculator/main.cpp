#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
	std::cout << "<-- Advanced Scientific Calculator -->" << std::endl;
	std::cout << "Available operations for use:" << std::endl;
	std::cout << "1. Addition (+)" << std::endl;
	std::cout << "2. Subtraction (-)" << std::endl;
	std::cout << "3. Multiplication (*)" << std::endl;
	std::cout << "4. Division (/)" << std::endl;
	std::cout << "5. Modulus (%)" << std::endl;
	std::cout << "6. Exponentiation (^)" << std::endl;
	std::cout << "7. Square Root (rt)" << std::endl;
	std::cout << "8. Logarithm (log)" << std::endl;
	std::cout << "9. Trigonometric Functions (sin, cos, tan)" << std::endl;
	std::cout << "10. Inverse Trigonometric Functions (asin, acos, atan)" << std::endl;
	std::cout << "11. Factorial (!)" << std::endl;
	std::cout << "12. Absolute Value (abs)" << std::endl;
	std::cout << "13. Rounding Functions (round, ceil, floor)" << std::endl;
	std::cout << "14. Random Number Generation (rand)" << std::endl;
	std::cout << "15. Exit" << std::endl;
	std::cout << "Please enter your choice (1-15): ";

	int choice;
	std::cin >> choice;
	if (choice < 1 || choice > 15) {
		std::cout << "Invalid choice. Please run the program again." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 1;
	}

	double num1, num2;
	while (true) {
		std::cout << "Enter first number: ";
		std::cin >> num1;
		if (std::cin.fail()) {
			std::cout << "Invalid input. Please enter a valid number." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (choice == 8 && num1 <= 0) {
			std::cout << "Logarithm of non-positive number is not defined." << std::endl;
			continue;
		}
		if (choice == 9 && (num1 < -1 || num1 > 1) && (choice == 10)) {
			std::cout << "asin and acos are not defined for this value." << std::endl;
			continue;
		}
		if (choice == 11 && num1 < 0) {
			std::cout << "Factorial of negative number is not defined." << std::endl;
			continue;
		}
		if (choice == 12 && num1 < 0) {
			std::cout << "Absolute value of negative number is not defined." << std::endl;
			continue;
		}
		if (choice == 13 && num1 < 0) {
			std::cout << "Rounding functions are not defined for negative numbers." << std::endl;
			continue;
		}
		
		std::cout << "Enter second number (if applicable, otherwise enter 0): ";
		std::cin >> num2;
		if (std::cin.fail()) {
			std::cout << "Invalid input. Please enter a valid number." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (choice == 7 && num1 < 0) {
			std::cout << "Square root of negative number is not allowed." << std::endl;
			continue;
		}
		if (choice == 11 && num1 < 0) {
			std::cout << "Factorial of negative number is not defined." << std::endl;
			continue;
		}
		if (choice == 4 && num2 == 0) {
			std::cout << "Division by zero is not allowed." << std::endl;
			continue;
		}
		if (choice == 6 && num2 < 0) {
			std::cout << "Exponentiation with negative exponent is not allowed." << std::endl;
			continue;
		}
		break;
	}

	switch (choice) {
		case 1:
			std::cout << "Result: " << (num1 + num2) << std::endl;
			break;
		case 2:
			std::cout << "Result: " << (num1 - num2) << std::endl;
			break;
		case 3:
			std::cout << "Result: " << (num1 * num2) << std::endl;
			break;
		case 4:
			std::cout << "Result: " << (num1 / num2) << std::endl;
			break;
		case 5:
			std::cout << "Result: " << static_cast<int>(num1) % static_cast<int>(num2) << std::endl;
			break;
		case 6:
			std::cout << "Result: " << pow(num1, num2) << std::endl;
			break;
		case 7:
			std::cout << "Result: " << sqrt(num1) << std::endl;
			break;
		case 8:
			if (num1 <= 0) {
				std::cout << "Logarithm of non-positive number is not defined." << std::endl;
			} else {
				std::cout << "Result: " << log(num1) << std::endl;
			}
			break;
		case 9:
			std::cout << "Trigonometric Functions:" << std::endl;
			std::cout << "sin(" << num1 << ") = " << sin(num1) << std::endl;
			std::cout << "cos(" << num1 << ") = " << cos(num1) << std::endl;
			std::cout << "tan(" << num1 << ") = " << tan(num1) << std::endl;
			break;
		case 10:
			std::cout << "Inverse Trigonometric Functions:" << std::endl;
			if (num1 < -1 || num1 > 1) {
				std::cout << "asin, acos are not defined for this value." << std::endl;
			} else {
				std::cout << "asin(" << num1 << ") = " << asin(num1) << std::endl;
				std::cout << "acos(" << num1 << ") = " << acos(num1) << std::endl;
			}
			std::cout << "atan(" << num1 << ") = " << atan(num1) << std::endl;
			break;
		case 11:
			if (num1 != static_cast<int>(num1)) {
				std::cout << "Factorial is only defined for integers." << std::endl;
			} else {
				int n = static_cast<int>(num1);
				long long factorial = 1;
				for (int i = 1; i <= n; ++i) {
					factorial *= i;
				}
				std::cout << "Result: " << factorial << std::endl;
			}
			break;
		case 12:
			std::cout << "Result: " << fabs(num1) << std::endl;
			break;
		case 13:
			std::cout << "Rounding Functions:" << std::endl;
			std::cout << "round(" << num1 << ") = " << round(num1) << std::endl;
			std::cout << "ceil(" << num1 << ") = " << ceil(num1) << std::endl;
			std::cout << "floor(" << num1 << ") = " << floor(num1) << std::endl;
			break;
		case 14:
			std::cout << "Random Number: " << rand() % 100 << std::endl;
			break;
		case 15:
			std::cout << "Exiting the calculator. Goodbye!" << std::endl;
			return 0;
		default:
			std::cout << "Invalid choice. Please run the program again." << std::endl;
			return 1;
	}

	std::cout << "Perform another calculation? (y/n): ";
	char again;
	std::cin >> again;
	if (again == 'y' || again == 'Y') {
		std::cout << "Restarting the calculator..." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// clear console screen
		std::cout << "\033[2J\033[1;1H";
		return main(argc, argv); // reset
	} else {
		std::cout << "Thank you for using the Advanced Scientific Calculator!" << std::endl;
	}

	return 0;
}