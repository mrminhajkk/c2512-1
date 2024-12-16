#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Employee {
    private:
        unique_ptr<string> name;
        unique_ptr<int> age;
        unique_ptr<string[]> hobbies;
        int size;
    public:
        Employee(string p_name, int p_age, string p_hobbies[], int p_size) {//RAII
            if(!this->name) { cout << "name is nullptr" << endl; }
            if(!this->age) { cout << "age is nullptr" << endl; }
            if(!this->hobbies) { cout << "hobbies is nullptr" << endl; }
            this->name = make_unique<string>(p_name);
            this->age = make_unique<int>(p_age);
            this->size = p_size;
            this->hobbies = make_unique<string[]>(size);
            for(int I = 0; I < size; I ++) {
                this->hobbies[I] = p_hobbies[I];
            }
        }
        void display() {
            cout << "Name: " << *name << endl;
            cout << "Age: " << *age << endl;
            cout << "Hobbies: ";
            for(int I = 0; I < size; I ++) {
                cout << hobbies[I] << " ";
            }
            cout << endl;
        }
        ~Employee() {
            //
        }
};

int main() 
{
    string hobbies[] = {"Reading", "Writing", "Singing"};
    Employee emp("John", 25, hobbies, 3);
    emp.display();
    
        
    return 0;
}
