#include <iostream>
#include <string>

using namespace std;

class Monkey {
private:
    string name;         // Regular field for name
    int* age;            // Pointer to dynamically allocated memory for age
    float weight;        // Regular field for weight
    string color;        // Regular field for color

public:
    // Constructor to initialize the fields, allocate memory for age
    Monkey(const string& monkeyName, int monkeyAge, float monkeyWeight, const string& monkeyColor)
        : name(monkeyName), weight(monkeyWeight), color(monkeyColor) {
        age = new int(monkeyAge);  // Dynamically allocate memory for age
        cout << "Monkey " << name << " created!" << endl;
    }

    /*
    Monkey(const string& monkeyName, int monkeyAge, float monkeyWeight, const string& monkeyColor)
    : name(monkeyName), weight(monkeyWeight), color(monkeyColor), age(new int(monkeyAge)) {  // Invalid
        cout << "Monkey " << name << " created!" << endl;
    }
     */

    // Destructor to delete dynamically allocated memory for age
    ~Monkey() {
        delete age;  // Deallocate memory for age
        cout << "Monkey " << name << " destroyed!" << endl;
    }

    // Method to display the monkey's details
    void showDetails() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << *age << endl;  // Dereferencing pointer to access value
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Color: " << color << endl;
    }
};

int main() {
    // Create two Monkey objects with dynamic memory for age
    Monkey monkey1("George", 5, 15.2, "Brown");
    Monkey monkey2("Max", 3, 12.8, "Black");

    cout << "\nDetails of Monkey 1:" << endl;
    monkey1.showDetails();
    
    cout << "\nDetails of Monkey 2:" << endl;
    monkey2.showDetails();

    return 0;  // Destructor will be called automatically here
}
