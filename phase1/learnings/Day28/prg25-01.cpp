// weak_ptr is a smart pointer 
// that holds a non-owning ("weak") reference to an object 
// that is managed by shared_ptr. 

// It must be converted to shared_ptr in order to access the referenced object.

// weak_ptr is used to break circular references of shared_ptr.
// ie weak_ptr is used to prevent cyclic references 
// that can lead to memory leaks.

#include<iostream>
#include<memory>
using namespace std;

int main() 
{
    shared_ptr<int> p1 = make_shared<int>(10);
    cout << "p1: " << *p1 << endl;
    cout << "p1.use_count(): " << p1.use_count() << endl;

    weak_ptr<int> p2 = p1;
    if(p2.lock()) {
        cout << "p2, the weak_ptr refers the shared_ptr p1" << endl;
        *p2.lock() = 12;
        cout << "p2: " << *p2.lock() << endl;
    } else {
        cout << "p2 is nullptr" << endl;
    }
    cout << "p1.use_count(): " << p1.use_count() << endl;
    
    


    return 0;
}