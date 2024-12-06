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

class Cat : public Animal {
public:
    void Meow() {
        std::cout << "Meowing..." << std::endl;
    }
};

int main() {
    Dog golu;
    std::cout << "---golu---" << std::endl;
    golu.Bark();
    golu.Eat();

    Cat hudson;
    std::cout << "---hudson---" << std::endl;
    hudson.Meow();
    hudson.Eat();

    return 0;
}
