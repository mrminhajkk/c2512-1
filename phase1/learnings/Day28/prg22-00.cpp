#include<iostream>
#include<memory>
using namespace std;

int main() 
{
    unique_ptr<string> name(new string {"John"}); 
    unique_ptr<int> age(new int {25});   
    unique_ptr<string[]> hobbies(new string[3] {"Reading", "Writing", "Singing"});

    cout << "Name: " << *name << endl;
    cout << "Age: " << *age << endl;
    cout << "Hobbies: ";
    for(int I = 0; I < 3; I ++) {
        cout << hobbies[I] << " ";
    }
    cout << endl;
    return 0;
}