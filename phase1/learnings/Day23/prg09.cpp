#include <iostream>
#include <cstring>

// Base class Bird (abstract class)
class Bird {
public:
    // Virtual destructor to ensure proper cleanup of derived class objects
    virtual ~Bird() {
        std::cout << "Bird destructor called" << std::endl;
    }

    // Declare Sound as a pure virtual function
    virtual void Sound() = 0; // Pure virtual function makes this an abstract class
};

// Derived class Crow
class Crow : public Bird {
private:
    char* name; // Dynamic memory allocation for name

public:
    // Constructor to allocate memory for name and initialize it
    Crow(const char* n) {
        name = new char[strlen(n) + 1];  // Allocate memory for name
        strcpy(name, n);  // Copy the name into the allocated memory
    }

    // Override the Sound method for Crow
    void Sound() override {
        std::cout << name << " the Crow caws..." << std::endl;
    }

    // Destructor to free dynamically allocated memory
    ~Crow() {
        delete[] name;  // Deallocate memory
        std::cout << "Crow destructor called" << std::endl;
    }
};

// Derived class Parrot
class Parrot : public Bird {
private:
    char* name; // Dynamic memory allocation for name

public:
    // Constructor to allocate memory for name and initialize it
    Parrot(const char* n) {
        name = new char[strlen(n) + 1];  // Allocate memory for name
        strcpy(name, n);  // Copy the name into the allocated memory
    }

    // Override the Sound method for Parrot
    void Sound() override {
        std::cout << name << " the Parrot squawks..." << std::endl;
    }

    // Destructor to free dynamically allocated memory
    ~Parrot() {
        delete[] name;  // Deallocate memory
        std::cout << "Parrot destructor called" << std::endl;
    }
};

int main() {
    // Create pointers to the base class and instantiate derived class objects
    Bird* crow = new Crow("Raven");
    Bird* parrot = new Parrot("Polly");

    // Call Sound on each object using dynamic binding
    crow->Sound();    // Calls Crow's Sound
    parrot->Sound();  // Calls Parrot's Sound

    // Cleanup dynamically allocated memory
    delete crow;  // This will call the Crow destructor
    delete parrot; // This will call the Parrot destructor

    return 0;
}
