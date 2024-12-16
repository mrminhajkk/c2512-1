// unique_ptr manages the ownership of the managed object.
//      unique_ptr is a smart pointer 
//      that owns and manages another object through a pointer and 
//      disposes of that object when the unique_ptr goes out of scope.
// make_unique is used to create a unique_ptr object.
//      make_unique is a factory function that constructs an object and wraps it in a unique_ptr.
//      make_unique is used to create a unique_ptr object.
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
    // little more detailing on unique_ptr
    int *p_age = age.get();             // returns just the managed object ie raw_ptr
    cout << "Age: " << *p_age << endl;
    
    if(age) {                           // checks if the unique_ptr is managing any object
        cout << "age is not nullptr" << endl;
    } else {
        cout << "age is nullptr" << endl;
    }
    age.release();// age releases the ownership of the managed object. 
                  // [but not the 'delete raw_ptr']. 
                  // returns the managed object ie'raw_ptr'. 
                  // [but that is already held by p_age. So, p_age must be deleted.]
                  // so, age(mgr) is now empty
    age.reset(new int {30});//age deletes the old managed object ie 'delete old_raw_ptr'. 
                            // age manages now new managed object 'ie new int {30}'.
   
    cout << "Age: " << *age << endl;
    delete p_age; p_age = nullptr;

    p_age = age.get();
    cout << "Age: " << *p_age << endl;    
    age = make_unique<int>(35); //age 'delete's the old managed object ie 'delete old_raw_ptr'. 
                                // age manages now new managed object 'ie new int {35}'.
    cout << "Age: " << *age << endl;
    //delete p_age; // :: free(): double free detected in tcache 2
    return 0;
}
