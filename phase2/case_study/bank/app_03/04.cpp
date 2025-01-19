#include <iostream>
#include <cstdio>
#include <regex>
#include <string>
#include <vector>
#include <functional>

// ANSI escape codes for cursor control
#define CLEAR_LINE "\033[K"
#define CURSOR_UP "\033[A"

bool isValidEmail(const std::string &email) {
    const std::regex pattern(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");
    return std::regex_match(email, pattern);
}

void clearLine() {
    std::cout << "\r" << CLEAR_LINE; // Move to the start of the line and clear it
}

void moveCursorUp(int lines = 1) {
    for (int i = 0; i < lines; i++) {
        std::cout << CURSOR_UP; // Move cursor up
    }
}

using validator_fn_t = std::function<bool(std::string)>;
using validator_t = std::pair<std::string, validator_fn_t>;

void Read(std::string& str, std::string caption, std::vector<validator_t> validators) {
    bool isValid = true;
    do {
        clearLine(); // Clear any existing input line
        std::cout << caption;
        std::getline(std::cin, str);

        isValid = true; // Reset validity for each input
        for (auto& [errorMsg, validator] : validators) {
            if (validator(str)) {
                continue; // Input is valid, move to the next validator
            } else {
                // Print error message
                std::cout << errorMsg;
                moveCursorUp(2); // Move back to re-prompt the input line
                isValid = false;
                break;
            }
        }
    } while (!isValid);
}

int main() {
    std::string name, place, email;

    // Validate Name (required)
    std::vector<validator_t> nameValidators = {
        {"Error: Name is required. Please try again.\n", [](std::string str) -> bool { return !str.empty(); }}
    };
    Read(name, "Enter your Name: ", nameValidators);

    // Validate Place (required)
    std::vector<validator_t> placeValidators = {
        {"Error: Place is required. Please try again.\n", [](std::string str) -> bool { return !str.empty(); }}
    };
    Read(place, "Enter your Place: ", placeValidators);

    // Validate Email (required and valid format)
    std::vector<validator_t> emailValidators = {
        {"Error: Email is required. Please try again.\n", [](std::string str) -> bool { return !str.empty(); }},
        {"Error: Invalid email. Please try again.\n", [](std::string str) -> bool { return isValidEmail(str); }}
    };
    Read(email, "Enter your Email: ", emailValidators);

    // Display the form submission result
    std::cout << "\nForm Submission Successful!\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Place: " << place << "\n";
    std::cout << "Email: " << email << "\n";

    return 0;
}
