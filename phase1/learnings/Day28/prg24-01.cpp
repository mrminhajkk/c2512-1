#include<iostream>
#include<memory>
using namespace std;

int main() 
{
    //shared_ptr<int> p1(new int(10));
    shared_ptr<int> p1 = make_shared<int>(10);
    cout << "p1: " << *p1 << endl;
    cout << "p1.use_count(): " << p1.use_count() << endl;

    shared_ptr<int> p2 = p1;
    *p2 = 11;
    cout << "p2: " << *p2 << endl;
    cout << "p1: " << *p1 << endl;
    cout << "p1.use_count(): " << p1.use_count() << endl;
    cout << "p2.use_count(): " << p2.use_count() << endl;

   /* 
    //2.1 [OR 2.2]
    p2.reset(new int(12));
    cout << "p2: " << *p2 << endl;
    cout << "p1: " << *p1 << endl;
    cout << "p1.use_count(): " << p1.use_count() << endl;
    cout << "p2.use_count(): " << p2.use_count() << endl;
    */

    //2.2 [OR 2.1]
    p2.reset();
    if(p2) {
        cout << "p2: " << *p2 << endl;
    } else {
        cout << "p2 is nullptr" << endl;
    }
    cout << "p1: " << *p1 << endl;
    cout << "p1.use_count(): " << p1.use_count() << endl;
    cout << "p2.use_count(): " << p2.use_count() << endl;


    return 0;
}
