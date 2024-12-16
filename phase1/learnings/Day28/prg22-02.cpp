#include<iostream>
#include<memory>
using namespace std;



int main() 
{
    unique_ptr<string> name = make_unique<string>("John"); //c++ 14, make_unique
    unique_ptr<int> age = make_unique<int>(25);             
    unique_ptr<string[]> hobbies = make_unique<string[]>(3);
    hobbies[0] = "Reading";
    hobbies[1] = "Writing";
    hobbies[2] = "Singing";

    cout << "Name: " << *name << endl;
    cout << "Age: " << *age << endl;
    cout << "Hobbies: ";
    for(int I = 0; I < 3; I ++) {
        cout << hobbies[I] << " ";
    }
        
    
    return 0;
}
