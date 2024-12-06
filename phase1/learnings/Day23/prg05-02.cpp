#include <iostream>
#include <string>

// Base class Animal
class Animal {
protected:
    // Protected fields of Animal class
    std::string name;
    int age;

public:
    // Constructor of Animal
    Animal(const std::string& name, int age)
        : name(name), age(age) {  // Initialize fields in initializer list
        std::cout << "Animal constructor called for " << name << ", Age: " << age << std::endl;
    }

    //  Destructor of Animal
    ~Animal() {
        std::cout << "Animal destructor called for " << name << "." << std::endl;
    }

    // Function to simulate the sound the animal makes
    void Sound() {
        std::cout << name << " makes a sound..." << std::endl;
    }

    // Function to simulate the animal eating
    void Eat() {
        std::cout << name << " is eating..." << std::endl;
    }
};

// Derived class Dog
class Dog : public Animal {
private:
    // Private fields of Dog class
    std::string breed;
    double weight;

public:
    // Constructor of Dog
    Dog(const std::string& name, int age, const std::string& breed, double weight)
        : Animal(name, age), breed(breed), weight(weight) {  // Initialize both base and derived class fields
        std::cout << "Dog constructor called for " << name << ", Breed: " << breed << ", Weight: " << weight << std::endl;
    }

    // Destructor of Dog
    ~Dog() {
        std::cout << "Dog destructor called for " << name << "." << std::endl;
    }

    // Override the Sound method for Dog
    void Sound()  {
        
        std::cout << name << " barks..." << std::endl;
    }

    // Override the Eat method for Dog
    void Eat()  {
        std::cout << name << " is eating dog food..." << std::endl;
    }
};

int main() {
    // Create an object of type Dog    
    Dog dog("Rex", 5, "German Shepherd", 30.5);
    
    // Call the Sound and Eat methods
    dog.Sound();  // Calls Dog's overridden Sound
    dog.Eat();    // Calls Dog's overridden Eat

    //Animal* panimal = &dog;
    //panimal->Sound();
    //panimal->Eat();

    //Animal* panimal = new Dog("Rex", 5, "German Shepherd", 30.5);   
    //delete panimal;
    return 0;
}
