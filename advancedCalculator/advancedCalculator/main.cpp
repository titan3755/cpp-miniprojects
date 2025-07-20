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

	
	return 0;
}