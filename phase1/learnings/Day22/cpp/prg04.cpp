//single dynamic mem block, alloc's and dealloc's
#include <iostream>
using namespace std;

int main() {
    int* ptrId = new int {100};
    cout << "addr of dyn mem=" << ptrId << endl;
    cout << "dyn mem=" << *ptrId << endl;

    delete ptrId;
    ptrId = nullptr; 

    return 0;
}

/*

#include <iostream>

using namespace std;


int main() {
    //int* ptrId;//WILD PTR
    int* ptrId = nullptr;//WILD behaviour is not there
    //cout << "dyn mem=" << *ptrId << endl;
    ptrId = new int {100};
    cout << "addr of dyn mem=" << ptrId << endl;
    cout << "dyn mem=" << *ptrId << endl;

    //delete ptrId;
    //cout << "dyn mem=" << *ptrId << endl;//Dangling PTR

    delete ptrId;
    ptrId = nullptr; //No dangling 
    //cout << "dyn mem=" << *ptrId << endl;//Dangling PTR access is not possible

    return 0;
}

*/