#include<iostream>
#include<memory>
using namespace std;

void h(shared_ptr<int> p) { 
    *p = 102;
    cout << "p: " << *p << endl;                        //102
    cout << "p.use_count(): " << p.use_count() << endl; //4
}

void g(shared_ptr<int> p) { 
    *p = 101;
    cout << "p: " << *p << endl;                        // 101
    cout << "p.use_count(): " << p.use_count() << endl; // 3
    h(p);
    cout << "p: " << *p << endl;                        //102
    cout << "p.use_count(): " << p.use_count() << endl; // 3
}

void f(shared_ptr<int> p) { 
    *p = 100;
    cout << "p: " << *p << endl;                        // 100
    cout << "p.use_count(): " << p.use_count() << endl; // 2
    g(p);
    cout << "p: " << *p << endl;                        // 102
    cout << "p.use_count(): " << p.use_count() << endl; // 2
}

int main() 
{
    shared_ptr<int> p1 = make_shared<int>(10);
    cout << "p1: " << *p1 << endl;                      //10
    cout << "p1.use_count(): " << p1.use_count() << endl;//1
    f(p1);
    cout << "p1: " << *p1 << endl;                      //102
    cout << "p1.use_count(): " << p1.use_count() << endl;//1
    

    return 0;
}
