#include <iostream>
#include <string>

// Base class
class Animal {
public:
    void Eat() {
        std::cout << "Eating..." << std::endl;
    }
};

// First derived class
class Mammal : virtual public Animal {
public:
    void Walk() {
        std::cout << "Walking..." << std::endl;
    }
};

// Second derived class
class Bird : virtual public Animal {
public:
    void Fly() {
        std::cout << "Flying..." << std::endl;
    }
};

// Derived class that inherits from both Mammal and Bird
class Bat : public Mammal, public Bird {
public:
    void HangUpsideDown() {
        std::cout << "Hanging upside down..." << std::endl;
    }
};

int main() {
    Bat b;

    // Methods from Animal, Mammal, and Bird
    b.Eat();             // Inherited from Animal (no ambiguity due to virtual inheritance)
    b.Walk();            // Inherited from Mammal
    b.Fly();             // Inherited from Bird
    b.HangUpsideDown();  // Defined in Bat

    return 0;
}
