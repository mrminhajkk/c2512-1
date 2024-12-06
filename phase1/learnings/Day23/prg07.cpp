#include <iostream>
#include <string>

// Base class Bird
class Bird {
public:
    // Declare Sound as a virtual function
    virtual void Sound() {
        std::cout << "Bird makes a sound..." << std::endl;
    }
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
    // Create pointers to the base class
    Bird* bird = new Bird();
    Bird* crow = new Crow();
    Bird* parrot = new Parrot();

    // Call Sound on each object using dynamic binding
    bird->Sound();    // Calls Bird's Sound
    crow->Sound();    // Calls Crow's Sound (overridden)
    parrot->Sound();  // Calls Parrot's Sound (overridden)

    // Cleanup dynamically allocated memory
    delete bird;
    delete crow;
    delete parrot;

    return 0;
}
