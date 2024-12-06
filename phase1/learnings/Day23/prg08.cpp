#include <iostream>
#include <string>

// Base class Bird (abstract class)
class Bird {
public:
    // Declare Sound as a pure virtual function
    virtual void Sound() = 0; // Pure virtual function makes this an abstract class
};

// Derived class Crow
class Crow : public Bird {
public:
    // Override the Sound method for Crow
    void Sound() override {
        std::cout << "Crow caws..." << std::endl;
    }
};

// Derived class Parrot
class Parrot : public Bird {
public:
    // Override the Sound method for Parrot
    void Sound() override {
        std::cout << "Parrot squawks..." << std::endl;
    }
};

int main() {
    // Create pointers to the base class and instantiate derived class objects
    Bird* crow = new Crow();
    Bird* parrot = new Parrot();

    // Call Sound on each object using dynamic binding
    crow->Sound();    // Calls Crow's Sound (overridden)
    parrot->Sound();  // Calls Parrot's Sound (overridden)

    // Cleanup dynamically allocated memory
    delete crow;
    delete parrot;

    return 0;
}
