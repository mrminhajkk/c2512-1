#include <iostream>

using namespace std;


int main() {
    int id = 100;
    int* ptrId = &id;
    cout << "id=" << id << endl;
    cout << "addr of id=" << &id << endl;
    cout << "addr of id=" << ptrId << endl;
    cout << "id=" << *ptrId << endl;
    return 0;
}