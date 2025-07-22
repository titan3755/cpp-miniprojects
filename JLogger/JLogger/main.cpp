#include <iostream>
#include <string>

void addMessage(const std::string& message);
void listMessages();
void deleteMessage(int index);

int main(int argc, char* argv[]) {
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
		// Here you would add the message to your journal
		addMessage(message);
	} else if (std::string(argv[1]) == "list") {
		// Here you would list all messages in your journal
		listMessages();
	} else if (std::string(argv[1]) == "delete") {
		if (argc < 3) {
			std::cout << "Error: No index provided.\n";
			return 1;
		}
		int index = std::stoi(argv[2]);
		// Here you would delete the message at the given index
		deleteMessage(index);
	} else {
		std::cout << "Unknown command: " << argv[1] << "\n";
		return 1;
	}

	return 0;
}

// message adder function
void addMessage(const std::string& message) {
	// Implementation to add a message to the journal
	std::cout << "Message added: " << message << "\n";
}

// message lister function
void listMessages() {
	// Implementation to list all messages in the journal
	std::cout << "Listing all messages...\n";
}

// message deleter function
void deleteMessage(int index) {
	// Implementation to delete a message at the given index
	std::cout << "Message at index " << index << " deleted.\n";
}