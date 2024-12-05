#include <iostream>

using namespace std;

void f(int index)
{
    cout << "index=" << index << endl;
    int id = 100;
    cout << "id=" << id << endl;
    cout << "size of id=" << sizeof(id) << endl;
    cout << "addr of id=" << (&id) << endl;     // 'addr of' op 
    cout << "value of id=" << (*(&id)) << endl; //dereference the addr "deref op"
    cout << "addr of id=" << (&(*(&id))) << endl; 
    cout << "value of id=" << (*(&(*(&id)))) << endl; 
}

int main() {
    f(1); 
    f(2); 
    f(3); 
    return 0;
}