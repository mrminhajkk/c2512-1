#include <iostream>
#include <regex>
#include <string>
#include <cstdio>
#include <functional>

// ANSI escape codes for cursor control
#define CLEAR_LINE "\033[K"
#define CURSOR_UP "\033[A"

bool isValidEmail(const std::string &email) {
    const std::regex pattern(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");
    return std::regex_match(email, pattern);
}

void clearLine() {
    std::cout << "\r" << CLEAR_LINE; // Move to start of line and clear it
}

void moveCursorUp(int lines = 1) {
    for (int i = 0; i < lines; i++) {
        std::cout << CURSOR_UP << "\r"; // Move cursor up and return to start
    }
}

int main() {
    std::string name, place, email;

    // Validate Name (required)
    while (true) {
        clearLine(); // Clear the line before prompting
        std::cout << "Enter your Name: ";
        std::getline(std::cin, name);

        if (!name.empty()) {
            break; // Exit loop if name is not empty
        } else {
            // Display error message and re-prompt
            std::cout << "Error: Name is required. Please try again.\n";
            moveCursorUp(2); // Move back to the name input line
            clearLine();     // Clear the name input line
        }
    }

    // Validate Place (required)
    while (true) {
        clearLine(); // Clear the line before prompting
        std::cout << "Enter your Place: ";
        std::getline(std::cin, place);

        if (!place.empty()) {
            break; // Exit loop if place is not empty
        } else {
            // Display error message and re-prompt
            std::cout << "Error: Place is required. Please try again.\n";
            moveCursorUp(2); // Move back to the place input line
            clearLine();     // Clear the place input line
        }
    }

    // Validate Email (required and valid email format)
    while (true) {
        clearLine(); // Clear the line before prompting
        std::cout << "Enter your Email: ";
        std::getline(std::cin, email);

        if (!email.empty() && isValidEmail(email)) {
            break; // Exit loop if email is valid
        } else {
            // Display error message and re-prompt
            std::cout << "Error: Invalid or empty email. Please try again.\n";
            moveCursorUp(2); // Move back to the email input line
            clearLine();     // Clear the email input line
        }
    }

    // Display the form submission result
    std::cout << "\nForm Submission Successful!\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Place: " << place << "\n";
    std::cout << "Email: " << email << "\n";

    return 0;
}
