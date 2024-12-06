#include <iostream>
#include <string>

class Animal {
public:
    void Eat() {
        std::cout << "Eating..." << std::endl;
    }
};

class Dog : public Animal {
public:
    void Bark() {
        std::cout << "Barking..." << std::endl;
    }
};

class Puppy : public Dog {
public:
    void Weep() {
        std::cout << "Weeping..." << std::endl;
    }
};

int main() {
    Puppy tiny;
    tiny.Eat();   // Inherited from Animal
    tiny.Bark();  // Inherited from Dog
    tiny.Weep();  // Defined in Puppy

    return 0;
}
