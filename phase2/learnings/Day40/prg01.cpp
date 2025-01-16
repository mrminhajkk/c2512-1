#include <iostream>

void clearScreen() {
    //std::cout << "\033[2J\033[1;1H"; // Clears screen and moves cursor to home position
    system("clear");
}

void printLine(char ch) {
    for(int I =0; I < 80; I++) {
        std::cout << ch;
    }
    std::cout << std::endl;
}

void printTitle(std::string title) {
    std::cout << title << std::endl;
}

void printTitleBar(std::string title, char lineCh = '-') {
    clearScreen();
    printLine(lineCh);
    printTitle(title);
    printLine(lineCh);
}

void pressAnyKey(bool beforeNumber = false) {
    std::cout << "Press any key to continuee..."; 
    std::cin.get();
    if(beforeNumber) {
        std::cin.get();
    }
}
int main() {
    printTitleBar("Page 1");
    std::cout << "Hello, World!" << std::endl;
    pressAnyKey();

    printTitleBar("Page 1");
    std::cout << "Screen Cleared!" << std::endl;
    pressAnyKey();
    
    return 0;
}