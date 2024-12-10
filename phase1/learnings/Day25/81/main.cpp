//copy constructor , copy assignment operator
#include<iostream>
#include<cstring>
using namespace std;

class Employee {
    private:
        int *id;//int id;
        char* name;//char name[20];
        int* friendsIds;
        int size;
    public:
        Employee(int id, const char* name, int friendsIds[], int size) {
            this->id = new int(id);
            this->name = new char[20];
            strcpy(this->name, name);

            this->friendsIds = new int[size];
            for(int i = 0; i < size; i++) {
                this->friendsIds[i] = friendsIds[i];
            }
            this->size = size;
        }
        ~Employee() {
            delete id;
            delete[] name;
            delete[] friendsIds;
        }
        Employee(const Employee &emp) {
            this->id = new int(*emp.id);
            this->name = new char[20];
            strcpy(this->name, emp.name);
            this->friendsIds = new int[emp.size];
            for(int i = 0; i < emp.size; i++) {
                this->friendsIds[i] = emp.friendsIds[i];
            }
            this->size = emp.size;
        }
        Employee& operator=(const Employee &emp) {
            if(this == &emp) {
                return *this;
            }
            delete id;
            delete[] name;
            delete[] friendsIds;
            this->id = new int(*emp.id);
            this->name = new char[20];
            strcpy(this->name, emp.name);
           this->friendsIds = new int[emp.size];
            for(int i = 0; i < emp.size; i++) {
                this->friendsIds[i] = emp.friendsIds[i];
            }
            this->size = emp.size;
            return *this;
        }
        friend ostream& operator<<(ostream &out, const Employee &emp) {
            out << "Id: " << *emp.id << ", Name: " << emp.name << ", Friends: ";
            for(int i = 0; i < emp.size; i++) {
                out << emp.friendsIds[i] << " ";
            }
            return out;
        }
};

int main()
{
    int friendsIds[] = {1,2,3};
    Employee emp1(1, "John",  friendsIds, 3);
    Employee emp2(2, "Raj"  , friendsIds, 3);
    Employee emp3(3, "Mike" , friendsIds, 3);
    Employee emp4(emp1); //copy constr
    Employee emp5(0,"",{},0);
    emp5 = emp2; //copy assignment
    cout << "Employee 1: " << emp1 << endl;
    cout << "Employee 2: " << emp2 << endl;
    cout << "Employee 3: " << emp3 << endl;
    cout << "Employee 4: " << emp4 << endl;
    cout << "Employee 5: " << emp5 << endl;    
    return 0;
}
