#include <iostream>
#include <string>

using namespace std;
class Cow
{
    private: 
        string name;
        int age;
    public:
        Cow(string name, int age)
        {
            this->name = name;
            this->age = age;
        }
        void display()
        {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};

int main()
{
    Cow cow1("Bessie", 4);
    Cow cow2 = {"Bessie", 4};
    Cow cow3 {"Bessie", 4};

    cow1.display();
    cow2.display();
    cow3.display();

    return 0;
}