#include <iostream>
#include <variant>

void variantExample() {
    std::variant<int, double, std::string> var;

    var = 42.0; // Holds int
    if (std::holds_alternative<int>(var)) {
        std::cout << "Integer: " << std::get<int>(var) << std::endl;
    }
    var = 3.14; // Holds double
    std::cout << "Double: " << std::get<double>(var) << std::endl;

    var = "Hello, Variant!"; // Holds string
    std::cout << "String: " << std::get<std::string>(var) << std::endl;
}

int main() {
    variantExample();
    return 0;
}