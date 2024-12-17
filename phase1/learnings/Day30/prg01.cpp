#include <iostream>
#include <string>
using namespace std;

class Animal {
    protected:
        string *name;
    public: 
        virtual void sound() = 0;
        Animal(string v_vname) {            
            name = new string(v_vname);
            cout << "Animal " << *name << " is created" << endl;
        }
        virtual ~Animal() {
            cout << "Animal " << *name << " is destroyed" << endl;
            delete name;            
        }
};

void Animal::sound() {
    cout << "Animal " << *name << " makes a sound" << endl;
}

class Mammal: virtual public Animal {
    protected:
        int *age;
    public:
        void sound() override{
            cout << "Mammal " << *name << " of age " << *age << " makes a sound" << endl;
        }
        Mammal(string v_vname, int _age)  : Animal(v_vname) {
            age = new int(_age);
            cout << "Mammal " << *name << " of age " << *age << " is created" << endl;
        }
        ~Mammal() {
            cout << "Mammal " << *name << " of age " << *age << " is destroyed" << endl;
            delete age;
        }
};

class Bird: virtual public Animal {
    protected:
        int *age;        
    public:
        void sound() override{
            cout << "Bird " << *name << " of age " << *age << " makes a sound" << endl;
        }
        Bird(string v_vname, int _age) : Animal(v_vname) {
            age = new int(_age);
            cout << "Bird " << *name << " of age " << *age << " is created" << endl;
        }
        ~Bird() {      
            cout << "Bird " << *name << " of age " << *age << " is destroyed" << endl;      
            delete age;
        }
};

class Bat : public Bird, public Mammal {
    private:
        string *houseName;      
    public:
        void sound() override{
            cout << "Bat " << *name << " of age " << *Mammal::age << " at " << *houseName << " makes a sound" << endl;
        }
        Bat(string v_vname, int _age, string v_houseName) : Animal(v_vname), Bird(v_vname, _age), Mammal(v_vname, _age) {
            houseName = new string(v_houseName);
            cout << "Bat " << *name << " of age " << *Mammal::age << " at " << *houseName << " is created" << endl;
        }
        ~Bat() {
            cout << "Bat " << *name << " of age " << *Mammal::age << " at " << *houseName << " is destroyed" << endl;
            delete houseName;
        }
};

int main() {
    Animal *bat1 = new Bat("bat1", 10, "temple1");    
    bat1->sound();
    delete bat1;
    return 0;
}