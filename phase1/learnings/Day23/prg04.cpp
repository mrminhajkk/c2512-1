#include <iostream>
#include <string>

class Animal {
public:
    void Eat() {
        std::cout << "Eating..." << std::endl;
    }
};

class Pet {
public:
    void Play() {
        std::cout << "Playing..." << std::endl;
    }
};

class Dog : public Animal, public Pet {
public:
    void Bark() {
        std::cout << "Barking..." << std::endl;
    }
};

int main() {
    Dog buddy;

    // Methods from Animal and Pet base classes
    buddy.Eat();
    buddy.Play();

    // Method from Dog class
    buddy.Bark();

    return 0;
}
