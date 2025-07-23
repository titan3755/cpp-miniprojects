#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include <iomanip>

void addMessage(const std::string& message);
void listMessages();
void deleteMessage(int index);

const std::string journalFileName = "journal.txt";

int main(int argc, char* argv[]) {
	std::ifstream checkFile(journalFileName);
	if (checkFile.is_open()) {
		checkFile.close();
	} else {
		std::ofstream createFile(journalFileName);
		if (!createFile || !createFile.is_open()) {
			std::cerr << "Error creating journal file.\n";
			return 1;
		}
	}

	std::cout << "JLogger - A Command-Line Journal \n:";

	if (argc < 2) {
		std::cout << "Usage: JLogger add <message>\n";
		std::cout << "       JLogger list\n";
		std::cout << "       JLogger delete <index>\n";
		return 0;
	}

	if (std::string(argv[1]) == "add") {
		if (argc < 3) {
			std::cout << "Error: No message provided.\n";
			return 1;
		}
		std::string message = argv[2];
		addMessage(message);
	} else if (std::string(argv[1]) == "list") {
		listMessages();
	} else if (std::string(argv[1]) == "delete") {
		if (argc < 3) {
			std::cout << "Error: No index provided.\n";
			return 1;
		}
		int index = std::stoi(argv[2]);
		deleteMessage(index);
	} else {
		std::cout << "Unknown command: " << argv[1] << "\n";
		return 1;
	}

	return 0;
}

// message adder function
void addMessage(const std::string& message) {
	std::chrono::system_clock::time_point now_sys = std::chrono::system_clock::now();
	const std::chrono::time_zone* current_tz = std::chrono::current_zone();
	std::chrono::zoned_time local_zoned_time = std::chrono::zoned_time(current_tz, now_sys);
	std::ofstream journalFile(journalFileName, std::ios::app);
	if (!journalFile.is_open()) {
		std::cerr << "Error opening journal file for writing.\n";
		return;
	}
	journalFile << std::format("{:%Y-%m-%d %H:%M:%S} - {}\n", local_zoned_time, message);
	journalFile.close();
	std::cout << "Added message at " 
			  << std::format("{:%Y-%m-%d %H:%M:%S}", local_zoned_time) 
		<< ": " << message << "\n";
}

// message lister function
void listMessages() {
	std::cout << "Listing all messages...\n";
	std::ifstream journalFile(journalFileName);
	if (!journalFile.is_open()) {
		std::cerr << "\nError opening journal file for reading.\n";
		return;
	}
	std::string line;
	while (std::getline(journalFile, line)) {
		std::cout << line << "\n";
	}
	if (line.empty()) {
		std::cout << "\nNo messages found in the journal.\n";
	} else {
		std::cout << "\nEnd of messages.\n";
	}
	if (journalFile.eof()) {
		std::cout << "\nReached end of journal file.\n";
	} else if (journalFile.fail()) {
		std::cerr << "\nError reading journal file.\n";
	}
	if (journalFile.bad()) {
		std::cerr << "\nBad state encountered while reading journal file.\n";
	}
	journalFile.clear();
	journalFile.close();
	std::cout << "\nMessages listed successfully.\n";
}

// message deleter function
void deleteMessage(int index) {
	std::cout << "Message at index " << index << " deleted.\n";
	std::ifstream journalFile(journalFileName);
	if (!journalFile.is_open()) {
		std::cerr << "\nError opening journal file for reading.\n";
		return;
	}
	std::vector<std::string> messages;
	std::string line;
	while (std::getline(journalFile, line)) {
		messages.push_back(line);
	}
	journalFile.close();
	if (index < 0 || index >= static_cast<int>(messages.size())) {
		std::cerr << "\nError: Index out of range.\n";
		return;
	}
	messages.erase(messages.begin() + index);
	std::ofstream outFile(journalFileName, std::ios::trunc);
	if (!outFile.is_open()) {
		std::cerr << "\nError opening journal file for writing.\n";
		return;
	}
	for (const auto& msg : messages) {
		outFile << msg << "\n";
	}
	outFile.close();
	std::cout << "\nMessage at index " << index << " deleted successfully.\n";
	std::cout << "\nUpdated journal file after deletion.\n";
	for (const auto& msg : messages) {
		std::cout << msg << "\n";
	}
	if (messages.empty()) {
		std::cout << "\nNo messages left in the journal.\n";
	} else {
		std::cout << "\nEnd of updated messages.\n";
	}
	if (outFile.eof()) {
		std::cout << "\nReached end of updated journal file.\n";
	} else if (outFile.fail()) {
		std::cerr << "\nError writing to updated journal file.\n";
	}
	if (outFile.bad()) {
		std::cerr << "\nBad state encountered while writing to updated journal file.\n";
	}
	outFile.clear();
	outFile.close();
	std::cout << "\nMessages updated successfully after deletion.\n";
}