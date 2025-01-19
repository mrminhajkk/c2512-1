#include <iostream>
#include <regex>
#include <string>
#include <cstdio>

// ANSI escape codes for cursor control
#define CLEAR_LINE "\033[K"
#define CURSOR_UP "\033[A"

bool isValidEmail(const std::string &email) {
    const std::regex pattern(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");
    return std::regex_match(email, pattern);
}

void clearLine() {
    std::cout << CLEAR_LINE; // Clear the current line
}

void moveCursorUp(int lines = 1) {
    for (int i = 0; i < lines; i++) {
        std::cout << CURSOR_UP << "\r"; // Move cursor up
    }
}

int main() {
    std::string name, place, email;

    std::cout << "Enter your Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter your Place: ";
    std::getline(std::cin, place);

    while (true) {
        std::cout << "Enter your Email: ";
        std::getline(std::cin, email);

        if (isValidEmail(email)) {
            break; // Exit loop if email is valid
        } else {
            // Display error message and move cursor up
            std::cout << "Error: Invalid email. Please try again.\n";
            moveCursorUp(2); // Move back to the email input line
            clearLine();     // Clear the email input line
        }
    }

    std::cout << "\nForm Submission Successful!\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Place: " << place << "\n";
    std::cout << "Email: " << email << "\n";

    return 0;
}
