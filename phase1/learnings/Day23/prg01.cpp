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

int main() {
    Dog golu;
    golu.Eat();
    golu.Bark();

    return 0;
}
