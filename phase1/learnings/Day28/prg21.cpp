#include<iostream>
#include<string>
using namespace std;

class Employee {
    private:
        string* name;  //unique_ptr<string> name;            
        int* age;               //unique_ptr<int> age;            
        string* hobbies;    //unique_ptr<string[]> hobbies;
        int size;
    public:
        Employee(string v_name, int v_age, string v_hobbies[], int v_size) {
            this->name = new string(v_name);
            this->age = new int(v_age);
            this->size = size;
            this->hobbies = new string[v_size];
            for(int I = 0; I < size; I ++) {
                this->hobbies[I] = v_hobbies[I];
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
            delete name;
            delete age;
            delete[] hobbies;
        }
};

int main() 
{
    string hobbies[] = {"Reading", "Writing", "Singing"};
    Employee emp("John", 25, hobbies, 3);
    emp.display();
    
    int a;
    cout  << "A:"; cin >> a; cout  << "A:" << a  << endl;
    return 0;
}
