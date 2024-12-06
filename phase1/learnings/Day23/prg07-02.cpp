#include <iostream>
#include <string>

// Base class Bird
class Bird {
public:
    // Constructor of Bird
    Bird() {
        std::cout << "Bird constructor called." << std::endl;
    }

    // Virtual destructor of Bird (important for polymorphic deletion)
    virtual ~Bird() {
        std::cout << "Bird destructor called." << std::endl;
    }

    // Virtual function for Sound
    virtual void Sound() = 0;
};

// Derived class Crow
class Crow : public Bird {
public:
    // Constructor of Crow (calls the constructor of Bird)
    Crow() {
        std::cout << "Crow constructor called." << std::endl;
    }

    // Destructor of Crow (calls the destructor of Bird)
    ~Crow() {
        std::cout << "Crow destructor called." << std::endl;
    }

    // Override Sound function for Crow
    void Sound() override {
        std::cout << "Crow caws..." << std::endl;
    }
};

int main() {
    // Create an object of type Crow
    Bird* crow = new Crow();  // Calls the constructors of both Bird and Crow

    // Call Sound method (dynamic dispatch)
    crow->Sound();  // Calls Crow's Sound method

    // Cleanup (destructors will be called in reverse order)
    delete crow;  // Calls the destructors of Crow and Bird

    return 0;
}

/*
Output:
Bird constructor called.
Crow constructor called.
Crow caws...
Crow destructor called.
Bird destructor called.

*/